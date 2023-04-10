// RepresentationType.cpp
#include <iostream>
#include "MulchExceptions.h"
#include "PData.h"
#include "DataNMRInfo.h"
#include "DataCrystallographicInfo.h"
#include "DataCryoEMInfo.h"
#include "Utility.h"
using namespace mulch;

PData::PData()
{
	_dataNMRInfo = nullptr;
	_dataCrystallographicDataInfo = nullptr;
	_dataCryoEMInfo = nullptr;

	if (_dataNMRInfo != nullptr || _dataCrystallographicDataInfo != nullptr || _dataCryoEMInfo != nullptr)
	{
		throw  std::runtime_error("Issue in PData: more thatn one type of data.");
	}
	// _dataNMRInfo = new DataNMRInfo();
	// _dataCrystallographicDataInfo = new DataCrystallographicInfo();
	// _dataCryoEMInfo = new DataCryoEMInfo();


}

std::string PData::insertQuery()
{	
	std::string query;
	query = "INSERT INTO Data DEFAULT VALUES";
	// query += "(";
	// query += std::to_string(_dataCrystallographicDataInfo->primaryId());
	// query += ");";

	return query;
}

std::string PData::updateQuery()
{
	std::string query;
	query = "UPDATE Data SET comments = ";
	query += "'";
	query += _comments;
	query += "'";
	query += " WHERE data_ID = ";
	query += std::to_string(primaryId());
	query += ";";

	// query = "UPDATE Data SET comments = ";
	// query += "(";
	// query += std::to_string(primaryId());
	// query += ");";
	// query += "UPDATE Data SET data_nmr_info_id = ";
	// query += "(";
	// query += std::to_string(_dataNMRInfo->primaryId());
	// query += ")";
	// query += " WHERE data_ID = ";
	// query += "(";
	// query += std::to_string(primaryId());
	// query += ");";
	return query;
}

std::string PData::selectPidQuery()
{
	std::string query;
	query = "SELECT * FROM Data WHERE data_ID = ";
	query += std::to_string(primaryId());
	query += ";";

	return query;
}

std::string PData::selectQueryDataByInfo(DataEnum dat)
{
	std::string table, id;
	switch (dat)
	{
		case NMR:
		table = "DataNMRInfo";
		id = "data_nmr_info_id";
		break;

		case Xray:
		table = "DataCrystallographicInfo";
		id = "data_crystallographic_info_id";
		break;

		case Cryo:
		table = "DataCryoEMInfo";
		id = "data_cryoem_info_id";
		break;

		default:
		std::cout << "default\n";
		break;	
	};

	std::string query;
	query = " ";

	Utility::protectsql(query);
	return query;
}

void PData::updateDependenciesBefore(Database *db)
{
	if (_dataNMRInfo != nullptr)
	{
		std::cout << "Updating Data->DataNMRInfo \n" << std::endl;
		_dataNMRInfo->updateDatabase(db);
	}
	else if (_dataCrystallographicDataInfo != nullptr)
	{
		std::cout << "Updating Data->DataCrystallographicDataInfo \n" << std::endl;
		_dataCrystallographicDataInfo->updateDatabase(db);
	}
	else if (_dataCryoEMInfo != nullptr)
	{
		std::cout << "Updating Data->DataCryoEMInfo \n" << std::endl;
		_dataCryoEMInfo->updateDatabase(db);
	}
	else
	{
		throw std::runtime_error("Can't update Data: no data info");
	}
}

void PData::retrieveDependencies(Database *db)
{
	// send that representationType to the database
	_dataNMRInfo->updateDatabase(db);
	_dataCrystallographicDataInfo->updateDatabase(db);
	_dataCryoEMInfo->updateDatabase(db);
	
}

void PData::fillInFromResults(const Result &res) 
{
	std::cout << typeid(res).name() << std::endl;
	// _comments = res["comments"];
	_dataNMRInfo->getPidFromResults(res);
	_dataCrystallographicDataInfo->getPidFromResults(res);
	_dataCryoEMInfo->getPidFromResults(res);

};

void PData::setDataInfo(DataEnum dat)
{	
	MulchExceptions::DataTypeIsNone(_datInfo);
	_datInfo = dat;
	std::cout<< _datInfo <<std::endl;
	if (_datInfo == NMR) 
	{
		_dataNMRInfo = new DataNMRInfo();
	}
	else if (_datInfo == Xray)
	{
		_dataCrystallographicDataInfo = new DataCrystallographicInfo();
	}
	else if (_datInfo == Cryo)
	{
		_dataCryoEMInfo = new DataCryoEMInfo();
	}

};

void PData::setFileName(std::string fileName)
{	
	if (_dataCrystallographicDataInfo!=nullptr)
	{
		_dataCrystallographicDataInfo->setFileName(fileName);
	}
};


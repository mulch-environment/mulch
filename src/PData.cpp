// RepresentationType.cpp
#include <typeinfo>
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
	_dataCrystallographicInfo = nullptr;
	_dataCryoEMInfo = nullptr;

	if (_dataNMRInfo != nullptr || _dataCrystallographicInfo != nullptr || _dataCryoEMInfo != nullptr)
	{
		throw  std::runtime_error("Issue in PData: more thatn one type of data.");
	}
	// _dataNMRInfo = new DataNMRInfo();
	// _dataCrystallographicInfo = new DataCrystallographicInfo();
	// _dataCryoEMInfo = new DataCryoEMInfo();


}

std::string PData::insertQuery()
{	
	std::string query;
	query = "INSERT INTO Data DEFAULT VALUES";
	// query += "(";
	// query += std::to_string(_dataCrystallographicInfo->primaryId());
	// query += ");";
	Utility::protectsql(query);
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
	std::cout<<"Update query in PModel: "<<std::endl;
	std::cout<<query<<std::endl;
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
	}

	// std::string query;
	// query = "SELECT * FROM Data WHERE data_ID = ";
	// query += std::to_string(primaryId());
	// query += ";";
	// Utility::protectsql(query);
	// return query;
}

void PData::updateDependenciesBefore(Database *db)
{
	if (_dataNMRInfo != nullptr)
	{
		std::cout << "Updating Data->DataNMRInfo \n" << std::endl;
		_dataNMRInfo->updateDatabase(db);
	}
	else if (_dataCrystallographicInfo != nullptr)
	{
		std::cout << "Updating Data->DataCrystallographicDataInfo \n" << std::endl;
		_dataCrystallographicInfo->updateDatabase(db);
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


/// ------------------ RETRIEVING STUFF -----------------------
PData* PData::dataByPrimaryId(int id, Database *db)
{
	PData *data = new PData();
	data->retrieveExisting(id, db);
	return data;
}

void PData::retrieveDependencies(Result &res, Database *db)
{
	std::string datNmr_id = DataNMRInfo::staticSqlIDName();
	std::string datCryst_id = DataCrystallographicInfo ::staticSqlIDName();
	std::string datCryo_id = DataCryoEMInfo::staticSqlIDName();

	if (!Utility::isNull(res[datNmr_id]))
	{
		std::cout << "Retrieving from PData->DataNMRInfo \n" << std::endl;
		delete _dataNMRInfo;

		std::string datNmr_id = DataNMRInfo::staticSqlIDName();
		std::cout << "res[datNmr_id] = " + res[datNmr_id] << std::endl;
		_dataNMRInfo = DataNMRInfo::NmrInfoByPrimaryId(std::stoi(res[datNmr_id]), db);
	}
	else if (!Utility::isNull(res[datCryst_id]))
	{
		std::cout << "Retrieving from PData->DataCrystallographicInfo \n" << std::endl;
		delete _dataCrystallographicInfo;

		std::string datCryst_id = DataCrystallographicInfo::staticSqlIDName();
		std::cout << "res[datCryst_id] = " + res[datCryst_id] << std::endl;
		_dataCrystallographicInfo = DataCrystallographicInfo::CrystInfolByPrimaryId(std::stoi(res[datCryst_id]), db);	
	}
	else if (!Utility::isNull(res[datCryo_id]))
	{
		std::cout << "Retrieving from PData->DataCryoEMInfo \n" << std::endl;
		delete _dataCryoEMInfo;

		std::string datCryo_id = DataCryoEMInfo::staticSqlIDName();
		std::cout << "res[datCryo_id] = " + res[datCryo_id] << std::endl;
		// _dataCryoEMInfo = DataCryoEMInfo::atomicModelByPrimaryId(std::stoi(res[datCryo_id]), db);	
	}
	else
	{
		std::cout << res << std::endl;
		throw std::runtime_error("Can't retrieving dependencies for PData: check values");
	}
}

void PData::fillInFromResults(const Result &res) 
{

	std::string datNmr_id = DataNMRInfo::staticSqlIDName();
	std::string datCryst_id = DataCrystallographicInfo ::staticSqlIDName();
	std::string datCryo_id = DataCryoEMInfo::staticSqlIDName();

	if (!Utility::isNull(res.at(datNmr_id)))
	{
		_dataNMRInfo =  new DataNMRInfo;
		_dataNMRInfo->getPidFromResults(res);
	}
	
	if (!Utility::isNull(res.at(datCryst_id)))
	{
		_dataCrystallographicInfo = new DataCrystallographicInfo;
		_dataCrystallographicInfo->getPidFromResults(res);
	} 
	
	if (!Utility::isNull(res.at(datCryo_id)))
	{
		_dataCryoEMInfo = new DataCryoEMInfo;
		_dataCryoEMInfo->getPidFromResults(res);
	}

}

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
		_dataCrystallographicInfo = new DataCrystallographicInfo();
	}
	else if (_datInfo == Cryo)
	{
		_dataCryoEMInfo = new DataCryoEMInfo();
	}

};

void PData::setFileName(std::string fileName)
{	
	if (_dataCrystallographicInfo!=nullptr)
	{
		_dataCrystallographicInfo->setFileName(fileName);
	}
};

std::vector<Result> PData::showRetrievedValues(int pid, Database *db)
{
    PData* data = dataByPrimaryId(pid, db);
    std::cout << "Retrieving values from Database" << std::endl;
    std::cout << "Data_id = " << pid << std::endl;    
    std::vector<Result> retrieved_res = db->results();
    // std::cout << retrieved_res << std::endl;
    for (auto& res : retrieved_res) 
    {
        std::cout << "Results from Data:" << std::endl;
        for (auto& kv : res) 
        {
            if (Utility::isNull(kv.second)) 
            {
                std::string temp = std::string("Not yet assigned");
                kv.second = temp;
            }
            std::cout << "Column: " << kv.first << ", Value: " << kv.second << std::endl;
        }
    }
    return retrieved_res;
}

// std::vector<PModel*> PModel::retrieveByType(RepresentationEnum rep, Database *db)
// {
// 	std::vector<PModel*> models;
// 	std::string query;
// 	query = selectQueryModelsByType(rep);
// 	std::cout << query << std::endl;
// 	std::vector<Result> results = db->results();

// 	for (Result &res: results)
// 	{
// 		PModel *model = new PModel();
// 		model->retrieveFromResult(res, db);
// 		models.push_back(model);
// 	}
// 	return models;
// }

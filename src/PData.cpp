// RepresentationType.cpp
#include <typeinfo>
#include <iostream>
#include "MulchExceptions.h"
#include "PData.h"
#include "DataNMRInfo.h"
#include "DataCrystallographicInfo.h"
#include "DataCryoEMInfo.h"
#include "Utility.h"
#include "DebugLog.h"
using namespace mulch;

PData::PData()
{
	_dataNMRInfo = nullptr;
	_dataCrystallographicInfo = nullptr;
	_dataCryoEMInfo = nullptr;

	if (_dataNMRInfo != nullptr || _dataCrystallographicInfo != nullptr || _dataCryoEMInfo != nullptr)
	{
		throw  std::runtime_error("Issue in PData: more than one type of data.");
	}

}

int PData::returnPrimaryId() const
{
    return primaryId();
}

std::string PData::insertQuery()
{	
	std::string query;
	query = "INSERT INTO Data DEFAULT VALUES";
	// query += "(";
	// query += std::to_string(_dataCrystallographicInfo->primaryId());
	query += ";";
	Utility::protectsql(query);
	return query;
}

// std::string PData::updateQuery()
// {
// 	std::string query;
// 	std::string new_comment = PData::getComments();
// 	Utility::protectParameter(new_comment);
// 	query = "UPDATE Data SET comments = ";
// 	query += "'";
// 	query += _comments;
// 	query += "'";
// 	query += " WHERE data_ID = ";
// 	query += std::to_string(PData::primaryId());
// 	query += ";";
// 	debugLog << "Update query in PData: ";
// 	debugLog << query;
// 	return query;
// }
std::string PData::updateQuery()
{
    std::string query;
    std::string new_comment_data = PData::getComments();
    debugLog << new_comment_data;
    Utility::protectParameter(new_comment_data);

    query = "UPDATE Data SET ";
    bool hasUpdates = false;

    // Check if there is a new data_crystallographic_info_id
    if (_dataCrystallographicInfo != nullptr) 
    {
        query += "data_crystallographic_info_id = ";
        query += std::to_string(_dataCrystallographicInfo->primaryId());
        hasUpdates = true;
    }

    // Check if there is a new data_nmr_info_id
    if (_dataNMRInfo != nullptr) {
        if (hasUpdates) {
            query += ", ";
        }
        query += "data_nmr_info_id = ";
        query += std::to_string(_dataNMRInfo->primaryId());
        hasUpdates = true;
    }

    // Check if there is a new data_cryoem_info_id
    if (_dataCryoEMInfo != nullptr) {
        if (hasUpdates) {
            query += ", ";
        }
        query += "data_cryoem_info_id = ";
        query += std::to_string(_dataCryoEMInfo->primaryId());
        hasUpdates = true;
    }

    // Add comments
    if (!new_comment_data.empty()) {
        if (hasUpdates) {
            query += ", ";
        }
        query += "comments = '";
        query += new_comment_data;
        query += "'";
    }

    if (hasUpdates) {
        query += " WHERE data_ID = (";
        query += std::to_string(PData::primaryId());
        query += ");";
        debugLog << "Update query in PData: " << query;
        return query;
    } else {
        return ""; // No updates to perform
    }
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
		std::cout << "default\n" << std::endl;
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
		debugLog << "Updating PData->DataNMRInfo \n";
		_dataNMRInfo->updateDatabase(db);
	}
	else if (_dataCrystallographicInfo != nullptr)
	{
		debugLog << "Updating PData->DataCrystallographicDataInfo \n";
		_dataCrystallographicInfo->updateDatabase(db);
	}
	else if (_dataCryoEMInfo != nullptr)
	{
		debugLog << "Updating PData->DataCryoEMInfo \n";
		_dataCryoEMInfo->updateDatabase(db);
	}
	// else
	// {
	// 	std::cout << "For data_id = " +  std::to_string(primaryId()) << std::endl;
	// 	throw std::runtime_error("Can't update Data: no dependencies");
	// }
}


/// ------------------ RETRIEVING STUFF -----------------------
PData* PData::dataByPrimaryId(int id, Database *db)
{
	// PData *data = new PData();
	// data->retrieveExisting(id, db);
	// return data;
	PData* pData = Cache<PData>::cacheByPrimaryId(id, db);
    return pData;
}

void PData::retrieveDependencies(Result &res, Database *db)
{
	std::string datNmr_id = DataNMRInfo::staticSqlIDName();
	std::string datCryst_id = DataCrystallographicInfo ::staticSqlIDName();
	std::string datCryo_id = DataCryoEMInfo::staticSqlIDName();

	if (!Utility::isNull(res[datNmr_id]))
	{
		debugLog << "Retrieving from PData->DataNMRInfo \n";
		delete _dataNMRInfo;
		_dataNMRInfo = nullptr;

		std::string datNmr_id = DataNMRInfo::staticSqlIDName();
		debugLog << "res[datNmr_id] = " + res[datNmr_id];
		DataNMRInfo* dataNMR = DataNMRInfo::dataNMRInfoByPrimaryId(std::stoi(res[datNmr_id]), db);
		_dataNMRInfo = dataNMR;
	}
	else if (!Utility::isNull(res[datCryst_id]))
	{
		debugLog << "Retrieving from PData->DataCrystallographicInfo \n";
		delete _dataCrystallographicInfo;
		_dataCrystallographicInfo = nullptr;

		std::string datCryst_id = DataCrystallographicInfo::staticSqlIDName();
		debugLog << "res[datCryst_id] = " + res[datCryst_id];
		DataCrystallographicInfo* dataCryst = DataCrystallographicInfo::dataCrystallographicInfoByPrimaryId(std::stoi(res[datCryst_id]), db);	
		_dataCrystallographicInfo = dataCryst;
	}
	else if (!Utility::isNull(res[datCryo_id]))
	{
		debugLog << "Retrieving from PData->DataCryoEMInfo \n";
		delete _dataCryoEMInfo;
		_dataCryoEMInfo = nullptr;

		std::string datCryo_id = DataCryoEMInfo::staticSqlIDName();
		debugLog << "res[datCryo_id] = " + res[datCryo_id];
		DataCryoEMInfo* dataCryo = DataCryoEMInfo::dataCryoEMInfoByPrimaryId(std::stoi(res[datCryo_id]), db);
		_dataCryoEMInfo = dataCryo;	
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

	std::string commentsColumn = "comments";
    if (res.count(commentsColumn) > 0) {
        _comments = res.at(commentsColumn);
    } else {
        debugLog << "No 'comments' column in the result set";
    }
}

void PData::setDataInfo(DataEnum dat)
{	
	MulchExceptions::DataTypeIsNone(_datInfo);
	_datInfo = dat;
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
	if (_dataCrystallographicInfo == nullptr)
	{
		_dataCrystallographicInfo = new DataCrystallographicInfo;
	}
	_dataCrystallographicInfo->setFileName(fileName);
};

void PData::setComments(std::string comments)
{
	_comments = comments;
	debugLog << "In PData::setComments. Received comments: " << _comments;
};




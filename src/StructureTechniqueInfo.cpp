// StructureTechniqueInfo.cpp
#include "MulchExceptions.h"
#include "StructureTechniqueInfo.h"
#include "CrystallographicInfo.h"
#include "NMRInfo.h"
#include "CryoEMInfo.h"
#include "PCollection.h"
#include "DebugLog.h"

using namespace mulch;


StructureTechniqueInfoEnum StructureTechniqueInfo::strcInfo()
{
	if (_crystallographicInfo != nullptr) {
        return StrcXray;
    } else if (_nmrInfo != nullptr) {
         return StrcNMR;
    } else if (_cryoEMInfo != nullptr) {
        return StrcCryo;
    } else {
        return NoneStructureTechniqueInfo;
    }
}

StructureTechniqueInfo::StructureTechniqueInfo()
{
	_crystallographicInfo = nullptr;
	_nmrInfo = nullptr;
	_cryoEMInfo = nullptr;
}

std::string StructureTechniqueInfo::insertQuery()
{
	std::string query;
	query = "INSERT INTO StructureTechniqueInfo DEFAULT VALUES;";
	Utility::protectsql(query);
	return query;
}

std::string StructureTechniqueInfo::updateStrInfo(std::string strcInfoIddName, int strcInfoValue)
{
	std::string query;
	query = "UPDATE StructureTechniqueInfo SET ";
	query += strcInfoIddName; 
	query += " = ";
	query += std::to_string(strcInfoValue); 
	query += " WHERE structure_technique_id = ";
	query += std::to_string(primaryId());
	query += ";";
	Utility::protectsql(query);
	return query;
}

std::string StructureTechniqueInfo::updateQuery()
{

	std::string query;
    std::string strcInfoIdName;
    int strcInfoIdValue;

    StructureTechniqueInfoEnum currentStrc = strcInfo();

    if (currentStrc == StrcXray)
    {
        strcInfoIdName = "crystallographic_info_id";
        strcInfoIdValue = _crystallographicInfo->primaryId();
        query = updateStrInfo(strcInfoIdName, strcInfoIdValue);
        debugLog << query;
        Utility::protectsql(query);
        return query;
    }
    else if (currentStrc == StrcNMR)
    {
        strcInfoIdName = "nmr_info_id";
        strcInfoIdValue = _nmrInfo->primaryId();
        query = updateStrInfo(strcInfoIdName, strcInfoIdValue);
        debugLog << query;
        Utility::protectsql(query);
        return query;
    }   
    else if (currentStrc == StrcCryo)
    {
        strcInfoIdName = "cryoem_info_id";
        strcInfoIdValue = _cryoEMInfo->primaryId();
        query = updateStrInfo(strcInfoIdName, strcInfoIdValue);
        debugLog << query;
        Utility::protectsql(query);
        return query;
    }
    else
    {
    	return ""; // No updates to perform
        // throw std::runtime_error("Can't update StructureTechniqueInfo: no structure technique info.");
    }

}

std::string StructureTechniqueInfo::selectPidQuery()
{
	std::string query;
	query = "SELECT * FROM StructureTechniqueInfo WHERE structure_technique_ID = ";
	query += std::to_string(primaryId());
	query += ";";
	return query;
}

void StructureTechniqueInfo::updateDependenciesBefore(Database *db)
{

	// _crystallographicInfo->updateDatabase(db);
	// _nmrInfo->updateDatabase(db);
	// _cryoEMInfo->updateDatabase(db);	
	if (_crystallographicInfo != nullptr)
	{
		debugLog << "Updating dependencies for StructureTechniqueInfo->CrystallographicInfo";
		_crystallographicInfo->updateDatabase(db);
	}
	else if (_nmrInfo != nullptr)
	{
		debugLog << "Updating dependencies for StructureTechniqueInfo->NMRInfo";
		_nmrInfo->updateDatabase(db);
	}
	else if (_cryoEMInfo != nullptr)
	{
		debugLog << "Updating dependencies for StructureTechniqueInfo->CryoEMInfo";
		_cryoEMInfo->updateDatabase(db);
	}
	// else
	// {
	// 	throw std::runtime_error("Can't update dependencies for StructureTechniqueInfo: no structureTechniqueInfo");
	// }

}

void StructureTechniqueInfo::setStrc(StructureTechniqueInfoEnum strc)
{
    StructureTechniqueInfoEnum temp = strcInfo(); // Create a local variable

    MulchExceptions::StrcInfoIsNone(temp);

    temp = strc;

    // Initialize the corresponding model info based on the new type
    if (temp == StrcXray)
    {
        _crystallographicInfo = new CrystallographicInfo();
    }
    else if (temp == StrcNMR)
    {
        _nmrInfo = new NMRInfo();
    }
    else if (temp == StrcCryo)
    {
        _cryoEMInfo = new CryoEMInfo();
    }
}



/// ------------------ RETRIEVING STUFF -----------------------
StructureTechniqueInfo* StructureTechniqueInfo::structureTechniqueInfoByPrimaryId(int id, Database *db)
{
    return Cache<StructureTechniqueInfo>::cacheByPrimaryId(id, db); // Use the template function from the cache
}


void StructureTechniqueInfo::retrieveDependencies(Result &res, Database *db)
{
    // delete _crystallographicInfo;
    // _crystallographicInfo = nullptr;
    // delete _nmrInfo;
    // _nmrInfo = nullptr;
    // delete _cryoEMInfo;
    // _cryoEMInfo = nullptr;

    std::string crys_id = CrystallographicInfo::staticSqlIDName();
    std::string nmr_id = NMRInfo::staticSqlIDName();
    std::string cryo_id = CryoEMInfo::staticSqlIDName();
    std::cout << "res[crys_id] = " + res[crys_id] << std::endl;
    std::cout << "res[nmr_id] = " + res[nmr_id] << std::endl;
    std::cout << "res[cryo_id] = " + res[cryo_id] << std::endl;

	if (!Utility::isNull(res[crys_id]))
		{
			debugLog << "Retrieving from StructureTechniqueInfo->DataNMRInfo \n";
			delete _crystallographicInfo;
			_crystallographicInfo = nullptr;

			std::string crys_id = CrystallographicInfo::staticSqlIDName();
			debugLog << "res[crys_id] = " + res[crys_id];
			CrystallographicInfo* cryst = CrystallographicInfo::crystallographicInfoByPrimaryId(std::stoi(res[crys_id]), db);
			_crystallographicInfo = cryst;
		}
		else if (!Utility::isNull(res[nmr_id]))
		{
			debugLog << "Retrieving from StructureTechniqueInfo->NMRInfo \n";
		    delete _nmrInfo;
		    _nmrInfo = nullptr;

			std::string nmr_id = NMRInfo::staticSqlIDName();
			debugLog << "res[nmr_id] = " + res[nmr_id];
            NMRInfo* nmr = NMRInfo::nmrByPrimaryId(std::stoi(res[nmr_id]), db);
            _nmrInfo = nmr;
		}
		else if (!Utility::isNull(res[cryo_id]))
		{
			debugLog << "Retrieving from StructureTechniqueInfo->DataCryoEMInfo \n";
    		delete _cryoEMInfo;
    		_cryoEMInfo = nullptr;

			std::string cryo_id = CryoEMInfo::staticSqlIDName();
			debugLog << "res[cryo_id] = " + res[cryo_id];
			CryoEMInfo* cryo = CryoEMInfo::cryoByPrimaryId(std::stoi(res[cryo_id]), db); 
    		_cryoEMInfo = cryo;
		}


    // bool allNull = Utility::isNull(res[crys_id]) && Utility::isNull(res[nmr_id]) && Utility::isNull(res[cryo_id]);

    // if (allNull)
    // {
    //     throw std::runtime_error("In StructureTechniqueInfo: Unregistered values aftet this point.");
    // }

    // if (!Utility::isNull(res[crys_id]))
    // {
    // 	debugLog << "Retrieving from StructureTechniqueInfo->CrystallographicInfo \n";
    //     try 
    //     {
    //         CrystallographicInfo* cryst = CrystallographicInfo::crystallographicInfoByPrimaryId(std::stoi(res[crys_id]), db);
    //         _crystallographicInfo = cryst;
    //     } 
    //     catch (const std::invalid_argument& e) 
    //     {
    //         std::cout << "Warning: CrystallographicInfo ID doesn't exist" << std::endl;
    //     }
    // }

    // if (!Utility::isNull(res[nmr_id]))
    // {
    //     try 
    //     {
    //         NMRInfo* nmr = NMRInfo::nmrByPrimaryId(std::stoi(res[nmr_id]), db);
    //         _nmrInfo = nmr;
    //     } 
    //     catch (const std::invalid_argument& e) 
    //     {
    //         std::cout << "Warning: NMRInfo ID doesn't exist" << std::endl;
    //     }
    // }

    // if (!Utility::isNull(res[cryo_id]))
    // {
    //     try 
    //     {
    //         CryoEMInfo* cryo = CryoEMInfo::cryoByPrimaryId(std::stoi(res[cryo_id]), db); 
    //         _cryoEMInfo = cryo;
    //     } 
    //     catch (const std::invalid_argument& e) 
    //     {
    //         std::cout << "Warning: CryoEMInfo ID doesn't exist" << std::endl;
    //     }
    // }
}


void StructureTechniqueInfo::fillInFromResults(const Result &res) 
{

	std::string crys_id = CrystallographicInfo::staticSqlIDName();
    std::string nmr_id = NMRInfo::staticSqlIDName();
    std::string cryo_id = CryoEMInfo::staticSqlIDName();

	if (!Utility::isNull(res.at(crys_id)))
	{
		_crystallographicInfo = new CrystallographicInfo();
		_crystallographicInfo->getPidFromResults(res);
	}
	
	if (!Utility::isNull(res.at(nmr_id)))
	{
		_nmrInfo = new NMRInfo();
		_nmrInfo->getPidFromResults(res);
	} 
	
	if (!Utility::isNull(res.at(cryo_id)))
	{
		_cryoEMInfo = new CryoEMInfo();
		_cryoEMInfo->getPidFromResults(res);
	}
}




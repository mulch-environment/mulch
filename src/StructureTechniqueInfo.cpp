// StructureTechniqueInfo.cpp
#include <typeinfo>
#include <string>
#include <iostream>
#include "StructureTechniqueInfo.h"
#include "CrystallographicInfo.h"
#include "NMRInfo.h"
#include "CryoEMInfo.h"
#include "PCollection.h"
#include "DebugLog.h"
using namespace mulch;


StructureTechniqueInfo::StructureTechniqueInfo()
{
	_crystallographicInfo = new CrystallographicInfo();
	_nmrInfo = new NMRInfo();
	_cryoEMInfo = new CryoEMInfo();
}

std::string StructureTechniqueInfo::insertQuery()
{
	std::string query;
	query = "INSERT INTO StructureTechniqueInfo DEFAULT VALUES;";
	Utility::protectsql(query);
	return query;
}

std::string StructureTechniqueInfo::updateStrInfo(std::string crystInfoIdName, std::string nmrInfoIdName, std::string cryoInfoIdName,  int crystInfoIdValue, int nmrInfoIdValue, int cryoInfoId)
{
	std::string query;
	query = "UPDATE StructureTechniqueInfo SET ( ";
	query += crystInfoIdName;
	query += ",";
	query += nmrInfoIdName;
	query += ",";
	query += cryoInfoIdName;
	query += ")";
	query += " = (";
	query += std::to_string(crystInfoIdValue); 
	query += ",";
	query += std::to_string(nmrInfoIdValue); 
	query += ",";
	query += std::to_string(cryoInfoId);
	query += ")";
	query += " WHERE structure_technique_id = ";
	query += std::to_string(primaryId());
	query += ";";
	// Utility::protectsql(query);
	return query;
}

std::string StructureTechniqueInfo::updateQuery()
{
	std::string query;
	std::string crystInfoIdName = "crystallographic_info_id";
	int crystInfoIdValue = _crystallographicInfo->primaryId();
	std::string nmrInfoIdName = "nmr_info_id";
	int nmrInfoIdValue = _nmrInfo->primaryId();
	std::string cryoInfoIdName = "cryoem_info_id";
	int cryoInfoIdValue = _cryoEMInfo->primaryId();
	query = updateStrInfo(crystInfoIdName, nmrInfoIdName, cryoInfoIdName, crystInfoIdValue, nmrInfoIdValue, cryoInfoIdValue);
	debugLog << query;
	// Utility::protectsql(query);
	return query;

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
	_crystallographicInfo->updateDatabase(db);
	_nmrInfo->updateDatabase(db);
	_cryoEMInfo->updateDatabase(db);	
}

/// ------------------ RETRIEVING STUFF -----------------------
StructureTechniqueInfo* StructureTechniqueInfo::structureTechniqueInfoByPrimaryId(int id, Database *db)
{
    return Cache<StructureTechniqueInfo>::cacheByPrimaryId(id, db); // Use the template function from the cache
}


void StructureTechniqueInfo::retrieveDependencies(Result &res, Database *db)
{
    delete _crystallographicInfo;
    _crystallographicInfo = nullptr;
    delete _nmrInfo;
    _nmrInfo = nullptr;
    delete _cryoEMInfo;
    _cryoEMInfo = nullptr;

    std::string crys_id = CrystallographicInfo::staticSqlIDName();
    std::string nmr_id = NMRInfo::staticSqlIDName();
    std::string cryo_id = CryoEMInfo::staticSqlIDName();
    std::cout << "res[crys_id] = " + res[crys_id] << std::endl;
    std::cout << "res[nmr_id] = " + res[nmr_id] << std::endl;
    std::cout << "res[cryo_id] = " + res[cryo_id] << std::endl;

    bool allNull = Utility::isNull(res[crys_id]) && Utility::isNull(res[nmr_id]) && Utility::isNull(res[cryo_id]);

    if (allNull)
    {
        throw std::runtime_error("In StructureTechniqueInfo: Unregistered values aftet this point.");
    }

    if (!Utility::isNull(res[crys_id]))
    {
        try 
        {
            CrystallographicInfo* cryst = CrystallographicInfo::crystallographicInfoByPrimaryId(std::stoi(res[crys_id]), db);
            _crystallographicInfo = cryst;
        } 
        catch (const std::invalid_argument& e) 
        {
            std::cout << "Warning: CrystallographicInfo ID doesn't exist" << std::endl;
        }
    }

    if (!Utility::isNull(res[nmr_id]))
    {
        try 
        {
            NMRInfo* nmr = NMRInfo::nmrByPrimaryId(std::stoi(res[nmr_id]), db);
            _nmrInfo = nmr;
        } 
        catch (const std::invalid_argument& e) 
        {
            std::cout << "Warning: NMRInfo ID doesn't exist" << std::endl;
        }
    }

    if (!Utility::isNull(res[cryo_id]))
    {
        try 
        {
            CryoEMInfo* cryo = CryoEMInfo::cryoByPrimaryId(std::stoi(res[cryo_id]), db); 
            _cryoEMInfo = cryo;
        } 
        catch (const std::invalid_argument& e) 
        {
            std::cout << "Warning: CryoEMInfo ID doesn't exist" << std::endl;
        }
    }
}


void StructureTechniqueInfo::fillInFromResults(const Result &res) 
{
	_crystallographicInfo->getPidFromResults(res);
	_nmrInfo->getPidFromResults(res);
	_cryoEMInfo->getPidFromResults(res);	
};

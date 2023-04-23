// StructureTechniqueInfo.cpp
#include <typeinfo>
#include <string>
#include <iostream>
#include "StructureTechniqueInfo.h"
#include "CrystallographicInfo.h"
#include "NMRInfo.h"
#include "CryoEMInfo.h"
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
	Utility::protectsql(query);
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
	std::cout << query << std::endl;
	return query;


	// query = "UPDATE StructureTechniqueInfo SET cryoem_info_ID = 1 WHERE structure_technique_ID = 3";
	// query += ";";
	// query = "UPDATE RepresentationType SET atomic_model_ID= 1 WHERE representation_type_ID = 4";
	// query += ";";
	// return query;
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
	StructureTechniqueInfo *structureTechnique = new StructureTechniqueInfo();
	structureTechnique->retrieveExisting(id, db);
	return structureTechnique;
}

void StructureTechniqueInfo::retrieveDependencies(Result &res, Database *db)
{
	delete _crystallographicInfo;
	delete _nmrInfo;
	delete _cryoEMInfo;

	std::string crys_id = CrystallographicInfo::staticSqlIDName();
	std::string nmr_id =  NMRInfo::staticSqlIDName();
	std::string cryo_id = CryoEMInfo::staticSqlIDName();
	std::cout << "res[crys_id] = " + res[crys_id] << std::endl;
	std::cout << "res[nmr_id] = " + res[nmr_id] << std::endl;
	std::cout << "res[cryo_id] = " + res[cryo_id] << std::endl;

	if (!Utility::isNull(res[crys_id]))
	{
		try 
		{
		        _crystallographicInfo = CrystallographicInfo::crystallographicInfoByPrimaryId(std::stoi(res[crys_id]), db);
		} 
		catch (const std::invalid_argument& e) 
		{
		    std::cout<<"Warning: CrystallographicInfo ID doens't exist" <<std::endl;
		}
	}

	if (!Utility::isNull(res[nmr_id]))
	{
		try 
		{
		        _crystallographicInfo = CrystallographicInfo::crystallographicInfoByPrimaryId(std::stoi(res[nmr_id]), db);
		} 
		catch (const std::invalid_argument& e) 
		{
			std::cout<<"Warning: NMRInfo ID doens't exist"<<std::endl;
		}
	}

	if (!Utility::isNull(res[cryo_id]))
	{
		try 
		{
		        _crystallographicInfo = CrystallographicInfo::crystallographicInfoByPrimaryId(std::stoi(res[cryo_id]), db);  
		} 
		catch (const std::invalid_argument& e) 
		{
		    std::cout<<"Warning: CryoEMInfo ID doens't exist" <<std::endl;
		}
	}
}



void StructureTechniqueInfo::fillInFromResults(const Result &res) 
{
	_crystallographicInfo->getPidFromResults(res);
	_nmrInfo->getPidFromResults(res);
	_cryoEMInfo->getPidFromResults(res);	
};

// StructureTechniqueInfo.cpp
#include <iostream>
#include "AtomicModelInfo.h"
#include "TLSParametersInfo.h"
#include "MulchExceptions.h"

using namespace mulch;

AtomicModelInfo::AtomicModelInfo()
{
	_tlsParametersInfo = new TLSParametersInfo();

}

std::string AtomicModelInfo::insertQuery()
{
	std::string query;
	query = "INSERT INTO AtomicModelInfo DEFAULT VALUES;";
	return query;
}

std::string AtomicModelInfo::updateQuery()
{
	std::string query;
	query =	"UPDATE AtomicModelInfo SET pdb_code = ";
	query += "'";
	query += AtomicModelInfo::getPDBCode();
	query += "'";
	query += " WHERE atomic_model_id = 40;";				
	return query;
}

std::string AtomicModelInfo::selectPidQuery()
{
	std::string query;
	query = "SELECT atomic_model_id FROM AtomicModelInfo";
	query += ";";

	return query;
}


void AtomicModelInfo::updateDependencies(Database *db)
{
	/* Foreign keys (FK): if a column is assigned a FK, each row of that column 
	MUST contain a value that exists in the foreigh column it references.
	**/
	_tlsParametersInfo->updateDatabase(db);
}


void AtomicModelInfo::setFileName(std::string pdbName)
{
	MulchExceptions::FileNameIsNone(_pdbCode);
	_pdbCode = pdbName;
	std::cout<< _pdbCode<<std::endl;
};




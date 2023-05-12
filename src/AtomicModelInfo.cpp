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
	query += " WHERE atomic_model_id = ";
	query += "(";
	query += std::to_string(primaryId());
	query += ");";				
	return query;
}

std::string AtomicModelInfo::selectPidQuery()
{
	std::string query;
	query = "SELECT * FROM AtomicModelInfo where atomic_model_id = ";
	query += std::to_string(primaryId());
	query += ";";
	Utility::protectsql(query);

	return query;
}


void AtomicModelInfo::updateDependenciesBefore(Database *db)
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

/// ------------------ RETRIEVING STUFF -----------------------
std::pair<AtomicModelInfo*, int> AtomicModelInfo::atomicModelByPrimaryId(int id, Database *db)
{
    return Cache<AtomicModelInfo>::cacheByPrimaryId(id, db); // Use the template function from the cache
}

void AtomicModelInfo::retrieveDependencies(Result &res, Database *db)
{

	delete _tlsParametersInfo;
	std::string tls_id = TLSParametersInfo::staticSqlIDName();
	std::cout << "res[tls_id] = " + res[tls_id] << std::endl;
	std::pair<TLSParametersInfo*, int> tlsPair = TLSParametersInfo::tlsByPrimaryId(std::stoi(res[tls_id]), db);
	_tlsParametersInfo = tlsPair.first;
	
}

void AtomicModelInfo::fillInFromResults(const Result &res) 
{
    // std::cout << typeid(res).name() << std::endl;
    _comments = res.at("comments");
    _tlsParametersInfo->getPidFromResults(res);
}



#include "AtomicModelInfo.h"
#include "TLSParametersInfo.h"
#include "MulchExceptions.h"
#include "DebugLog.h"

using namespace mulch;


AtomicModelInfo::AtomicModelInfo()
{
	// _tlsParametersInfo = new TLSParametersInfo();
	_tlsParametersInfo = nullptr;
}

std::string AtomicModelInfo::insertQuery()
{
	std::string query;
	query = "INSERT INTO AtomicModelInfo DEFAULT VALUES;";
	Utility::protectsql(query);
	return query;
}

std::string AtomicModelInfo::updateQuery()
{
	std::string query;
	std::string PDBname = AtomicModelInfo::getPDBCode();
	query =	"UPDATE AtomicModelInfo SET pdb_code = '";
	query += PDBname;
	query += "' WHERE atomic_model_id = (";
	query += std::to_string(AtomicModelInfo::primaryId());
	query += ");";
	debugLog << query;				
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
	if (_tlsParametersInfo != nullptr)
	{
		debugLog << "Update _tlsParametersInfo from AtomicModelInfo::updateDependenciesBefore";
		_tlsParametersInfo->updateDatabase(db);
	}
}


void AtomicModelInfo::setFileName(std::string pdbName)
{
	MulchExceptions::FileNameIsNone(_pdbCode);
	_pdbCode = pdbName;
};

/// ------------------ RETRIEVING STUFF -----------------------
AtomicModelInfo* AtomicModelInfo::atomicModelByPrimaryId(int id, Database *db)
{
    return Cache<AtomicModelInfo>::cacheByPrimaryId(id, db); // Use the template function from the cache
}

void AtomicModelInfo::retrieveDependencies(Result &res, Database *db)
{

	delete _tlsParametersInfo;
	_tlsParametersInfo = nullptr;
	std::string tls_id = TLSParametersInfo::staticSqlIDName();
	debugLog << "res[tls_id] = " + res[tls_id];
	if (!Utility::isNull(res[tls_id]))
	{
		TLSParametersInfo* tls = TLSParametersInfo::tlsByPrimaryId(std::stoi(res[tls_id]), db);
		_tlsParametersInfo = tls;
	}
	
}

void AtomicModelInfo::fillInFromResults(const Result &res) 
{
	_comments = res.at("comments");

	std::string tls_id = TLSParametersInfo::staticSqlIDName();
    if (!Utility::isNull(res.at(tls_id)))
	{
		_tlsParametersInfo = new TLSParametersInfo;
    	_tlsParametersInfo->getPidFromResults(res);
	}
}



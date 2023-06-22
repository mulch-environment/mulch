// RfactrosInfo.cpp

#include "RfactorsInfo.h"
#include "ModelDataPair.h"
using namespace mulch;

RfactorsInfo::RfactorsInfo()
{
	_modelDataPair = new ModelDataPair();
}

std::string RfactorsInfo::insertQuery()
{
	std::string query;
	query = "INSERT INTO RfactorsInfo (modelDataPair_id) VALUES" ;
	query += "(";
	query += std::to_string(_modelDataPair ->primaryId());
	query += ");";
	Utility::protectsql(query);
	return query;
}

std::string RfactorsInfo::updateQuery()
{
	std::string query;
	query = "UPDATE RfactorsInfo SET rfactors_id =";
	query += _modelDataPair->primaryId();
	query += "WHERE rfactors_id = ";
	query += std::to_string(primaryId());;
	query += ";";
	Utility::protectsql(query);
	return query;
}

// ------------------------------------------------------------------------------------------

std::string RfactorsInfo::updateQueryTest(Database *db)
{

    std::string query = "UPDATE RfactorsInfo SET rfactors_id = ? WHERE rfactors_id = ?;";
    int mdpID = _modelDataPair->primaryId();
    int rFactorId = primaryId();

    std::vector<std::string> parameters;
    parameters.push_back(std::to_string(mdpID));
    parameters.push_back(std::to_string(rFactorId));


    executeUpdateQuery(db, query, parameters);
}

// ------------------------------------------------------------------------------------------


std::string RfactorsInfo::selectPidQuery()
{
	std::string query;
	query = "SELECT * FROM RfactorsInfo WHERE rfactrosinfo_id = ";
	query += std::to_string(primaryId());
	query += ";";
	Utility::protectsql(query);
	return query;
}

void RfactorsInfo::updateDependenciesBefore(Database *db)
{
	/* Foreign keys (FK): if a column is assigned a FK, each row of that column 
	MUST contain a value that exists in the foreigh column it references.
	**/
	_modelDataPair->updateDatabase(db);
}

/// ------------------ RETRIEVING STUFF -----------------------
RfactorsInfo* RfactorsInfo::rfactorsInfoByPrimaryId(int id, Database *db)
{
    return Cache<RfactorsInfo>::cacheByPrimaryId(id, db); // Use the template function from the cache
}
























// StructureTechniqueInfo.cpp
#include <iostream>
#include "CoarseGrainingModelInfo.h"
#include "MulchExceptions.h"
using namespace mulch;

CoarseGrainingModelInfo::CoarseGrainingModelInfo()
{

}

std::string CoarseGrainingModelInfo::insertQuery()
{
	std::string query;
	query = "INSERT INTO CoarseGrainingModelInfo DEFAULT VALUES;";
	Utility::protectsql(query);
	return query;
}

std::string CoarseGrainingModelInfo::updateQuery()
{
	std::string query;
	query =	"UPDATE CoarseGrainingModelInfo SET comments = ";
	query += "'";
	query += _comments;
	query += "'";
	query += "WHERE coarsegraining_model_id = ";
	query += "(";
	query += std::to_string(primaryId());
	query += ");";
	Utility::protectsql(query);	
	return query;
}

// ------------------------------------------------------------------------------------------

std::string CoarseGrainingModelInfo::updateQueryTest(Database *db)
{

    std::string query = "UPDATE CoarseGrainingModelInfo SET comments = ? WHERE coarsegraining_model_id = ?";
    std::string comments = _comments;
    int CGid = primaryId();
    std::vector<std::string> parameters;
    parameters.push_back(comments);
    parameters.push_back(std::to_string(CGid));


    executeUpdateQuery(db, query, parameters);
}

// ------------------------------------------------------------------------------------------


std::string CoarseGrainingModelInfo::selectPidQuery()
{
	std::string query;
	query = "SELECT * FROM CoarseGrainingModelInfo WHERE coarsegraining_model_id =";
	query += "(";
	query += std::to_string(primaryId());
	query += ");";
	Utility::protectsql(query);
	return query;
}

void CoarseGrainingModelInfo::setComments(std::string comments)
{
	MulchExceptions::FileNameIsNone(_comments);
	_comments = comments;
	std::cout<< _comments<<std::endl;
};

/// ------------------ RETRIEVING STUFF -----------------------
CoarseGrainingModelInfo* CoarseGrainingModelInfo::cgModelByPrimaryId(int id, Database *db)
{
    return Cache<CoarseGrainingModelInfo>::cacheByPrimaryId(id, db); // Use the template function from the cache
}



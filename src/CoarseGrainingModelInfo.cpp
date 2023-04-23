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

std::string CoarseGrainingModelInfo::selectPidQuery()
{
	std::string query;
	query = "SELECT * FROM CoarseGrainingModelInfo";
	query += ";";
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
    CoarseGrainingModelInfo *coarseGrainingModelInfo = new CoarseGrainingModelInfo();
    coarseGrainingModelInfo->retrieveExisting(id, db); // use the instance pointer
    return coarseGrainingModelInfo; // return the instance pointer
}



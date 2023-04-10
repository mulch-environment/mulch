// StructureTechniqueInfo.cpp
#include <iostream>
#include "CoarseGrainingModelInfo.h"
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

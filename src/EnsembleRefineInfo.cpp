// StructureTechniqueInfo.cpp

#include "EnsembleRefineInfo.h"
using namespace mulch;

EnsembleRefineInfo::EnsembleRefineInfo()
{

}

std::string EnsembleRefineInfo::insertQuery()
{
	std::string query;
	query = "INSERT INTO EnsembleRefineInfo DEFAULT VALUES;";
	return query;
}

std::string EnsembleRefineInfo::updateQuery()
{
	std::string query;
	query =	"UPDATE EnsembleRefineInfo SET comments = ";
	query += "'";
	query += _comments;
	query += "'";
	query += "WHERE ensemble_refine_id = ";
	query += "(";
	query += std::to_string(primaryId());
	query += ");";	
	return query;
}

std::string EnsembleRefineInfo::selectPidQuery()
{
	std::string query;
	query = "SELECT * FROM EnsembleRefineInfo";
	query += ";";

	return query;
}

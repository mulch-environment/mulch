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
	return "";
}

std::string EnsembleRefineInfo::updateQuery()
{
	return "";
}

std::string EnsembleRefineInfo::selectQuery()
{
	std::string query;
	query = "SELECT ensemble_refine_id FROM EnsembleRefineInfo";
	query += ";";

	return query;
}

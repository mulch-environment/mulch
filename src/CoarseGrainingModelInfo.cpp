// StructureTechniqueInfo.cpp

#include "CoarseGrainingModelInfo.h"
using namespace mulch;

CoarseGrainingModelInfo::CoarseGrainingModelInfo()
{

}

std::string CoarseGrainingModelInfo::insertQuery()
{
	std::string query;
	query = "INSERT INTO CoarseGrainingModelInfo DEFAULT VALUES;";
	return "";
}

std::string CoarseGrainingModelInfo::updateQuery()
{
	return "";
}

std::string CoarseGrainingModelInfo::selectPidQuery()
{
	std::string query;
	query = "SELECT coarsegraining_model_id FROM CoarseGrainingModelInfo";
	query += ";";

	return query;
}

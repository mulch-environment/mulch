// StructureTechniqueInfo.cpp

#include "CrystallographicInfo.h"
using namespace mulch;

CrystallographicInfo::CrystallographicInfo()
{

}

std::string CrystallographicInfo::insertQuery()
{
	std::string query;
	query = "INSERT INTO CrystallographicInfo DEFAULT VALUES;";
	return query;
}

std::string CrystallographicInfo::updateQuery()
{
	return "";
}


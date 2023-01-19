// StructureTechniqueInfo.cpp

#include "StructureTechniqueInfo.h"
using namespace mulch;

StructureTechniqueInfo::StructureTechniqueInfo()
{

}

std::string StructureTechniqueInfo::insertQuery()
{
	std::string query;
	query = "INSERT INTO StructureTechniqueInfo DEFAULT VALUES;";
	return query;
}

std::string StructureTechniqueInfo::updateQuery()
{
	return "";
}


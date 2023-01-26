// StructureTechniqueInfo.cpp

#include "CryoEMInfo.h"
using namespace mulch;

CryoEMInfo::CryoEMInfo()
{

}

std::string CryoEMInfo::insertQuery()
{
	std::string query;
	query = "INSERT INTO CryoEMInfo DEFAULT VALUES;";
	return query;
}

std::string CryoEMInfo::updateQuery()
{
	return "";
}


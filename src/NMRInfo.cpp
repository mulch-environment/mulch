// StructureTechniqueInfo.cpp

#include "NMRInfo.h"
using namespace mulch;

NMRInfo::NMRInfo()
{

}

std::string NMRInfo::insertQuery()
{
	std::string query;
	query = "INSERT INTO NMRInfo DEFAULT VALUES;";
	return query;
}

std::string NMRInfo::updateQuery()
{
	return "";
}


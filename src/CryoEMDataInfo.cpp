// RepresentationType.cpp

#include "CryoEMDataInfo.h"
using namespace mulch;

CryoEMDataInfo::CryoEMDataInfo()
{

}

std::string CryoEMDataInfo::insertQuery()
{
	std::string query;
	query = "INSERT INTO CryoEMDataInfo DEFAULT VALUES;";
	return query;
}

std::string CryoEMDataInfo::updateQuery()
{
	return "";
}


// RepresentationType.cpp

#include "DataNMRInfo.h"
#include "NMRQualityData.h"
using namespace mulch;

DataNMRInfo::DataNMRInfo()
{

}

std::string DataNMRInfo::insertQuery()
{
	std::string query;
	query = "INSERT INTO DataNMRInfo DEFAULT VALUES;";
	return query;
}

std::string DataNMRInfo::updateQuery()
{
	return "";
}


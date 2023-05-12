// RepresentationType.cpp

#include "NMRDataInfo.h"
using namespace mulch;

NMRDataInfo::NMRDataInfo()
{

}

std::string NMRDataInfo::insertQuery()
{
	std::string query;
	query = "INSERT INTO NMRDataInfo DEFAULT VALUES;";
	return query;
}

std::string NMRDataInfo::updateQuery()
{
	return "";
}

/// ------------------ RETRIEVING STUFF -----------------------
std::pair<NMRDataInfo*, int> NMRDataInfo::nmrDataInfoByPrimaryId(int id, Database *db)
{
    return Cache<NMRDataInfo>::cacheByPrimaryId(id, db); // Use the template function from the cache
}








// TLSParametersInfo.cpp

#include "TLSParametersInfo.h"
using namespace mulch;

TLSParametersInfo::TLSParametersInfo()
{

}

std::string TLSParametersInfo::insertQuery()
{
	std::string query;
	query = "INSERT INTO TLSParametersInfo DEFAULT VALUES;";
	return query;
}

std::string TLSParametersInfo::updateQuery()
{
	return "";
}

std::string TLSParametersInfo::selectPidQuery()
{
	std::string query;
	query = "SELECT * FROM TLSParametersInfo";
	query += ";";

	return query;
}

/// ------------------ RETRIEVING STUFF -----------------------
TLSParametersInfo* TLSParametersInfo::TLSByPrimaryId(int id, Database *db)
{
	TLSParametersInfo *tlsParametersInfo = new TLSParametersInfo();
	tlsParametersInfo->retrieveExisting(id, db);
	return tlsParametersInfo;
}

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


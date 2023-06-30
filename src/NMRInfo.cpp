#include <iostream>
#include "NMRInfo.h"
#include "MulchExceptions.h"
#include "DebugLog.h"
using namespace mulch;

NMRInfo::NMRInfo()
{

}

std::string NMRInfo::insertQuery()
{
	std::string query;
	query = "INSERT INTO NMRInfo DEFAULT VALUES;";
	Utility::protectsql(query);
	return query;
}

std::string NMRInfo::updateQuery()
{
	std::string query;
	query =	"UPDATE NMRInfo SET comments = '";
	query += _comments;
	query += "' WHERE nmr_info_id = (";
	query += std::to_string(primaryId());
	query += ");";
	Utility::protectsql(query);	
	return query;
}


std::string NMRInfo::selectPidQuery()
{
	std::string query;
	query = "SELECT * FROM NMRInfo WHERE nmr_info_id =";
	query += "(";
	query += std::to_string(primaryId());
	query += ");";
	Utility::protectsql(query);
	return query;
}

void NMRInfo::setComments(std::string comments)
{
	MulchExceptions::FileNameIsNone(_comments);
	_comments = comments;
	debugLog << _comments;
};

/// ------------------ RETRIEVING STUFF -----------------------
NMRInfo* NMRInfo::nmrByPrimaryId(int id, Database *db)
{
    return Cache<NMRInfo>::cacheByPrimaryId(id, db); // Use the template function from the cache
}















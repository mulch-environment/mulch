// StructureTechniqueInfo.cpp

#include "EnsembleRefineInfo.h"
#include "MulchExceptions.h"
using namespace mulch;

EnsembleRefineInfo::EnsembleRefineInfo()
{

}

std::string EnsembleRefineInfo::insertQuery()
{
	std::string query;
	query = "INSERT INTO EnsembleRefineInfo DEFAULT VALUES;";
	return query;
}

std::string EnsembleRefineInfo::updateQuery()
{
	std::string query;
	query =	"UPDATE EnsembleRefineInfo SET comments = ";
	query += "'";
	query += _comments;
	query += "'";
	query += "WHERE ensemble_refine_id = ";
	query += "(";
	query += std::to_string(primaryId());
	query += ");";	
	return query;
}

std::string EnsembleRefineInfo::selectPidQuery()
{
	std::string query;
	query = "SELECT * FROM EnsembleRefineInfo";
	query += ";";

	return query;
}

void EnsembleRefineInfo::setComments(std::string comments)
{
	MulchExceptions::FileNameIsNone(_comments);
	_comments = comments;
	std::cout<< _comments<<std::endl;
};

/// ------------------ RETRIEVING STUFF -----------------------
std::pair<EnsembleRefineInfo*, int> EnsembleRefineInfo::ensembleByPrimaryId(int id, Database *db)
{
    return Cache<EnsembleRefineInfo>::cacheByPrimaryId(id, db); // Use the template function from the cache
}

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
	Utility::protectsql(query);
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
	Utility::protectsql(query);
	return query;
}

// ------------------------------------------------------------------------------------------

std::string EnsembleRefineInfo::updateQueryTest(Database *db)
{

    std::string query = "UPDATE EnsembleRefineInfo SET comments = ? WHERE ensemble_refine_id = (?);";
    std::string comments = _comments;
    int ensembId = primaryId();
    std::vector<std::string> parameters;
    parameters.push_back(comments);
    parameters.push_back(std::to_string(ensembId));


    executeUpdateQuery(db, query, parameters);
}

// ------------------------------------------------------------------------------------------

std::string EnsembleRefineInfo::selectPidQuery()
{
	std::string query;
	query = "SELECT * FROM EnsembleRefineInfo";
	query += ";";
	Utility::protectsql(query);
	return query;
}

void EnsembleRefineInfo::setComments(std::string comments)
{
	MulchExceptions::FileNameIsNone(_comments);
	_comments = comments;
	std::cout<< _comments<<std::endl;
};

/// ------------------ RETRIEVING STUFF -----------------------
EnsembleRefineInfo* EnsembleRefineInfo::ensembleByPrimaryId(int id, Database *db)
{
    return Cache<EnsembleRefineInfo>::cacheByPrimaryId(id, db); // Use the template function from the cache
}

// GroupHasDataset.cpp


#include "GroupHasDataset.h"
#include "ModelDataPair.h"
// #include "Group.h"
using namespace mulch;

GroupHasDataset::GroupHasDataset()
{
	_modelDataPair = new ModelDataPair();
	// _group = new Group();

}

std::string GroupHasDataset::insertQuery()
{	
	std::string query;
	query = "INSERT INTO GroupHasDataset (modeldatapair_ID) VALUES";
	query += "(";
	query += std::to_string(_modelDataPair->primaryId());
	// query += ",";
	// query += std::to_string(_group->primaryId());
	query += ");";

	return query;
}


std::string GroupHasDataset::updateQuery()
{
	std::string query;
	// query = "UPDATE GroupHasDataset SET modeldatapair_id =  WHERE grouphasdataset_id = 2";
	// query += std::to_string(primaryId());
	query = " ";

	return query;
}

void GroupHasDataset::updateDependencies(Database *db)
{
	// send that representationType to the database
	_modelDataPair->updateDatabase(db);
	// _group->updateDatabase(db);
	
}


// GroupHasDataset GroupHasDataset::groupHasDatasetFromResult(const Result &res)
// {
// 	GroupHasDataset exportedGroupHasDataset;
// 	int pid = atoi(res.at("grouphasdataset_id").c_str());
// 	exportedGroupHasDataset.setPrimaryId(pid);
// 	return exportedGroupHasDataset;
// }

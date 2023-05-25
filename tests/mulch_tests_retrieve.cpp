#define BOOST_TEST_MODULE mulch_tests
#include <boost/test/unit_test.hpp>
#include <src/Database.h>
#include <src/Utility.h>
#include <src/MulchExceptions.h>
#include <iostream>
#include <src/PModel.h>
#include <src/Model.h>
#include <src/PData.h>
#include <src/ModelDataPair.h>
#include <src/StructureTechniqueInfo.h>
#include <src/RepresentationType.h>
#include <src/DataNMRInfo.h>
#include <src/ModelDataPair.h>
#include <src/Collection.h>
#include <src/CollectionHasDataset.h>
#include <src/EnumTables.h>

// Define the current database version
const int CURRENT_VERSION = 1;

BOOST_AUTO_TEST_SUITE(retrieve_suite)

// BOOST_AUTO_TEST_CASE(retrieve_structureTechniqueInfo_exported_from_database)
// {
//     mulch::Database db("mulch.db");
//     db.open();

//     // const std::vector<mulch::Result> retrieved_res = db.results();
//     // std::cout << retrieved_res << std::endl;
//     mulch::StructureTechniqueInfo structureTechniqueInfo;
//     std::cout << "StructureTechniqueInfo has been created" << std::endl;

//     structureTechniqueInfo.updateDatabase(&db);
//     std::cout << "StructureTechniqueInfo has been updated" << std::endl;
    
//     structureTechniqueInfo.retrieveExisting(&db);
//     std::cout << "retrieveExisting() finished running!" << std::endl;
// };

// BOOST_AUTO_TEST_CASE(retrieve_select_models_by_structure_type)
// {
// 	mulch::Database db("mulch.db");
// 	mulch::PModel model;
// 	db.open();

// 	// const std::vector<mulch::Result> retrieved_res = db.results();
// 	// std::cout << retrieved_res << std::endl;
// 	mulch::RepresentationType representationType;
// 	std::cout << "RepresentationType has been created" << std::endl;

// 	representationType.updateDatabase(&db);
// 	std::cout << "RepresentationType has been updated" << std::endl;
	
// 	// representationType.retrieveExisting(&db);
// 	// std::cout << "retrieveExisting() finished running!" << std::endl;

// };

// BOOST_AUTO_TEST_CASE(retrieve_model_exported_from_database)
// {
// 	std::cout << "*** STARTING model_exported_from_database ***" << std::endl;
// 	mulch::Database db("mulch.db");
// 	db.open();

// 	mulch::Collection *collect = new mulch::Collection();
// 	collect->addModelDataPair(Atomic, "xyz", Xray, "myx");
// 	collect->persist();

// 	const std::vector<mulch::Result> &res = db.results();
// 	for (const mulch::Result &r: res)
// 	{
		
// 		for (auto it = r.begin(); it != r.end(); it++)
// 		{
// 			std::cout << it->first << "yo" << it->second <<std::endl;
// 		}
// 	}

// 	std::cout << "*** FINISING model_exported_from_database *** \n" << std::endl;
// };




// BOOST_AUTO_TEST_CASE(retrieve_cascade)
// {
// 	mulch::Database db("mulch.db");
// 	db.open();

// 	// std::vector<mulch::Result> retrieved_res = db.results();
// 	// std::cout << retrieved_res << std::endl;

//     const std::vector<mulch::Result> &res = db.results();
//     std::cout << "Results:" << std::endl;
//     for (const mulch::Result &r: res)
//     {
//         for (auto it = r.begin(); it != r.end(); it++)
//         {
//             std::cout << it->first << ": " << it->second << std::endl;
//         }
//         std::cout << std::endl;
//     }

//     mulch::Collection *collect = new mulch::Collection();

// 	for (const mulch::Result &r: res)
//     {
//         collect->retrieveFromResult(r, &db);
//     }

// }

BOOST_AUTO_TEST_CASE(retrieve_collect)
{
	mulch::Database db("mulch.db");
	db.open();

	int testCollectPid_1 = 5;
	int testCollectPid_2 = 7;
	mulch::Collection*  collect_a = mulch::Collection::collectByPrimaryId(testCollectPid_1, &db);
	mulch::Collection*  collect_b = mulch::Collection::collectByPrimaryId(testCollectPid_2, &db);

	if (collect_a == collect_b)
	{
		std::cout << "--------------------" << std::endl;
		std::cout << "Collections are the same" << std::endl;
		std::cout << "--------------------" << std::endl;
	}
	else
	{
		std::cout << "--------------------" << std::endl;
		std::cout << "Collections are different" << std::endl;
		std::cout << "--------------------" << std::endl;
	}

};

BOOST_AUTO_TEST_CASE(retrieve_cascade)
{
	mulch::Database db("mulch.db");
	db.open();

	int testCollectPid_1 = 5;
	int testCollectPid_2 = 1;

	mulch::Collection *collect;
	collect->getDatasetCascade(5, &db);


};

// BOOST_AUTO_TEST_CASE(retrieve_PModel)
// {
// 	mulch::Database db("mulch.db");
// 	db.open();

// 	int testModelPid_1 = 5;
// 	int testModelPid_2 = 7;
// 	std::pair<mulch::PModel*, int> modelPair_a = mulch::PModel::modelByPrimaryId(testModelPid_1, &db);
// 	mulch::PModel* model_a = modelPair_a.first;
// 	int id_a = modelPair_a.second;
// 	// std::vector<mulch::Result> retrievedRes_a = model_a->showRetrievedValues(id_a, &db);

// 	std::pair<mulch::PModel*, int>  modelPair_b = mulch::PModel::modelByPrimaryId(testModelPid_2, &db);
// 	mulch::PModel* model_b = modelPair_b.first;
// 	int id_b = modelPair_b.second;
// 	// std::vector<mulch::Result> retrievedRes_b = model_b->showRetrievedValues(id_b, &db);


// 	if (model_a == model_b)
// 	{
// 		std::cout << "--------------------" << std::endl;
// 		std::cout << "Models are the same:" << std::endl;
// 		std::cout << id_a << "=" << id_b << std::endl;
// 		std::cout << "--------------------" << std::endl;
// 	}
// 	else
// 	{
// 		std::cout << "--------------------" << std::endl;
// 		std::cout << "Models are different" << std::endl;
// 		std::cout << id_a << "!=" << id_b << std::endl;
// 		std::cout << "--------------------" << std::endl;
// 	}

// };

// BOOST_AUTO_TEST_CASE(retrieve_PData)
// {

// 	mulch::Database db("mulch.db");
// 	db.open();
// 	mulch::PData *data = new mulch::PData();
	
// 	int testDataPid_1= 7;
// 	int testDataPid_2= 7;
// 	// std::vector<mulch::Result> retrievedRes;
// 	// retrievedRes = mulch::PModel::showRetrievedValues(testModelPid, &db);
// 	// std::pair<mulch::PData*, int> dataPair_a = mulch::PData::dataByPrimaryId(testDataPid_1, &db);
// 	std::pair<mulch::PData*, int> dataPair_a = data->objectByPrimaryId(testDataPid_1, &db);
// 	mulch::PData* data_a = dataPair_a.first;
// 	int id_a = dataPair_a.second;

// 	std::pair<Object*, int> dataPair_b = data->objectByPrimaryId(testDataPid_2, &db);
// 	// std::pair<mulch::PData*, int>  dataPair_b = mulch::PData::dataByPrimaryId(testDataPid_2, &db);
// 	mulch::PData* data_b = dataPair_b.first;
// 	int id_b = dataPair_b.second;

// 	if (data_a == data_b)
// 	{
// 		std::cout << "--------------------" << std::endl;
// 		std::cout << "Models are the same:" << std::endl;
// 		std::cout << id_a << "=" << id_b << std::endl;
// 		std::cout << "--------------------" << std::endl;
// 	}
// 	else
// 	{
// 		std::cout << "--------------------" << std::endl;
// 		std::cout << "Models are different" << std::endl;
// 		std::cout << id_a << "!=" << id_b << std::endl;
// 		std::cout << "--------------------" << std::endl;
// 	}
// };



// BOOST_AUTO_TEST_SUITE_END()

// BOOST_AUTO_TEST_CASE(retrieve_cascade)
// {
// 	mulch::Database db("mulch.db");
// 	db.open();

// 	std::cout << "*** STARTING test_COLLECTION***" << std::endl;
// 	mulch::Collection *collect = new mulch::Collection();
// 	collect->addModelDataPair(Atomic, "xyz", Xray, "myx");
// 	collect->addModelDataPair(Atomic, "abc", Xray, "yzx");
// 	collect->persist();

//     // check what is inside Result
// 	std::vector<mulch::Collection*> collects;
// 	collects = collect->retrieveCollection(&db);
// 	// Iterate over the vector and print each element

// 	for (int i = 0; i < collect->numModelDataPairs(); i++) 
// 	{
// 		std::cout << i << std::endl;
// 	    // const ModelDataPair* pair = collection.getModelDataPairFromCollection(i);
// 	    // if (pair != nullptr) 
// 	    // {
// 	    //     std::cout << "Model: " << pair->getModel() << ", Data: " << pair->getData() << std::endl;
// 	    // }
// 	}

// 	// Retrieve dependencies with representation type
//     // collect->retrieveDependenciesBefore(&db, RepresentationEnum::Atomic);

//     // Retrieve dependencies without representation type
//     // collect->retrieveDependenciesBefore(&db);

// 	// res = collect->retrieveDependenciesBefore(&db);

// 	// for (const auto& element : res) 
// 	// {
// 	//     std::cout << element.first << ": " << element.second << std::endl;
// 	// }


// }
BOOST_AUTO_TEST_SUITE_END()



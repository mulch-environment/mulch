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




// BOOST_AUTO_TEST_CASE(retrieve_from_collection)
// {

//     std::cout << "*** STARTING retrieve_from_collection ***" << std::endl;
//     mulch::Database db("mulch.db");	
//     std::vector<mulch::Result> retrieved_res = db.results();

// 	mulch::Collection *collect = new mulch::Collection();

// 	// collect->addModel(Atomic, "ter");
// 	// collect->addData(Xray, "myx");
// 	collect->addModelDataPair(Atomic, "xyz", Xray, "myx");
// 	collect->addModelDataPair(Atomic, "abc", Xray, "yzx");
// 	collect->addModelDataPair(Atomic, "def", Xray, "zxy");
// 	collect->addModelDataPair(Atomic, "ghi", Xray, "yxz");

// 	collect->persist();

// 	// // get the 4th ModelDataPair in the collection...
// 	// const mulch::ModelDataPair* mdp = collect->getModelDataPairFromCollection(3);
// 	// // do something with the ModelDataPair (e.g. print its data...)
// 	// if (mdp)
// 	// {
// 	// 	std::cout << "Yo" << std::endl;
// 	//     // std::cout << "Model: " << mdp->modelType << ", data: " << mdp->dataName << std::endl;
// 	// }
// 	// else
// 	// {
// 	//     std::cout << "ModelDataPair not found." << std::endl;
// 	// }

// 	std::cout << "*** FINISING test_COLLECTION_Interface *** \n" << std::endl;

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

BOOST_AUTO_TEST_CASE(retrieve_PModel)
{
	mulch::Database db("mulch.db");
	db.open();

	int testPid = 48;
	mulch::PModel* model = mulch::PModel::modelByPrimaryId(testPid, &db);
	// std::cout << "Atomic" << std::endl;
	// model.setRepType(Atomic);

	// std::cout << "Coarse-grain" << std::endl;
	// model.modelsByRepType(CG, &db);

	// std::cout << "Ensemble" << std::endl;
	// model.modelsByRepType(Ensemble, &db);

	// model.updateDatabase(&db);
	// std::cout << "RepresentationType has been updated" << std::endl;

	// model.retrieveExisting(&db);
	// std::cout << "retrieveExisting() finished running!" << std::endl;
};

BOOST_AUTO_TEST_SUITE_END()

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
// BOOST_AUTO_TEST_SUITE_END()


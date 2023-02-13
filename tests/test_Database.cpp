#define BOOST_TEST_MODULE mulch_tests
#include <boost/test/unit_test.hpp>
#include <src/Database.h>
#include <src/Utility.h>
#include <src/MulchExceptions.h>
#include <iostream>
#include <src/Model.h>
#include <src/Data.h>
#include <src/ModelDataPair.h>
#include <src/StructureTechniqueInfo.h>
#include <src/RepresentationType.h>
#include <src/DataNMRInfo.h>
#include <src/ModelDataPair.h>
#include <src/Collection.h>
#include <src/CollectionHasDataset.h>

// BOOST_AUTO_TEST_CASE(model_inserted_into_database)
// {
// 	mulch::Database db("mulch.db");
// 	db.open();

// 	mulch::Model model;
// 	// ...

// 	std::cout << "Model has been created" << std::endl;
// 	model.updateDatabase(&db);

// };

// BOOST_AUTO_TEST_CASE(model_starts_with_negative_primary_id)
// {
// 	mulch::Model model; // declared in the code, but not in the databse yet
// 	int id = model.primaryId(); // this checks that the primary ID is -1 (or "unset")
// 	BOOST_TEST(id == -1);
// };

// BOOST_AUTO_TEST_CASE(model_exported_from_database)
// {
// 	mulch::Database db("mulch.db");
// 	db.open();

// 	// const std::vector<mulch::Result> retrieved_res = db.results();
// 	// std::cout << retrieved_res << std::endl;
// 	mulch::Model model;
// 	std::cout << "Model has been created" << std::endl;

// 	model.updateDatabase(&db);
// 	std::cout << "Model has been updated" << std::endl;
	
// 	model.retrieveExisting(&db);
// 	std::cout << "retrieveExisting() finished running!" << std::endl;
	

// };


// BOOST_AUTO_TEST_CASE(structureTechniqueInfo_exported_from_database)
// {
// 	mulch::Database db("mulch.db");
// 	db.open();

// 	// const std::vector<mulch::Result> retrieved_res = db.results();
// 	// std::cout << retrieved_res << std::endl;
// 	mulch::StructureTechniqueInfo structureTechniqueInfo;
// 	std::cout << "StructureTechniqueInfo has been created" << std::endl;

// 	structureTechniqueInfo.updateDatabase(&db);
// 	std::cout << "StructureTechniqueInfo has been updated" << std::endl;
	
// 	structureTechniqueInfo.retrieveExisting(&db);
// 	std::cout << "retrieveExisting() finished running!" << std::endl;
	

// };

// BOOST_AUTO_TEST_CASE(select_models_by_structure_type)
// {
// 	mulch::Database db("mulch.db");
// 	db.open();

// 	// const std::vector<mulch::Result> retrieved_res = db.results();
// 	// std::cout << retrieved_res << std::endl;
// 	mulch::RepresentationType representationType;
// 	std::cout << "RepresentationType has been created" << std::endl;

// 	representationType.updateDatabase(&db);
// 	std::cout << "RepresentationType has been updated" << std::endl;
	
// 	representationType.retrieveExisting(&db);
// 	std::cout << "retrieveExisting() finished running!" << std::endl;

// 	model.retrieveExisting(&db);
// 	std::cout << "retrieveExisting() finished running!" << std::endl;

// };

BOOST_AUTO_TEST_CASE(select_models_from_pair)
{
	mulch::Database db("mulch.db");
	db.open();

	mulch::ModelDataPair pair;
	mulch::Model model;
	std::string model_comment = "First comment in models";
	model.setComments(model_comment);
	model.updateDatabase(&db);

	// model* model();
	// pair.modelCom()->setComments("first RoPe model");
	// pair.updateDatabase(&db);


};

// BOOST_AUTO_TEST_CASE(model_exported_from_database)
// {
// 	mulch::Database db("mulch.db");
// 	db.open();

// 	// db.query("SELECT * FROM Model;");
// 	const std::vector<mulch::Result> &res = db.results();
// 	for (const mulch::Result &r: res)
// 	{
// 		for (auto it = r.begin(); it != r.end(); it++)
// 		{
// 			std::cout << it->first << " " << it->second <<std::endl;
// 		}
// 		std::cout << std::endl;
// 		mulch::Model m = mulch::Model::modelFromResult(r);
// 		std::cout<< m.primaryId()<< std::endl;
// 	}
// };



// BOOST_AUTO_TEST_CASE(testing_Data)
// {
// 	mulch::Database db("mulch.db");
// 	db.open();

// 	mulch::Data Data; // declared in the code, but not in the databse yet
// 	int id = Data.primaryId(); // this checks that the primary ID is -1 (or "unset")
// 	BOOST_TEST(id == -1);

// 	Data.updateDatabase(&db);

// };

// BOOST_AUTO_TEST_CASE(testing_ModelDataPair)
// {
// 	mulch::Database db("mulch.db");
// 	db.open();

// 	mulch::ModelDataPair ModelDataPair; // declared in the code, but not in the databse yet
// 	int id = ModelDataPair.primaryId(); // this checks that the primary ID is -1 (or "unset")
// 	BOOST_TEST(id == -1);

// 	ModelDataPair.updateDatabase(&db);

// };

// BOOST_AUTO_TEST_CASE(testing_CollectionHasDataset)
// {
// 	mulch::Database db("mulch.db");
// 	db.open();

// 	mulch::CollectionHasDataset CollectionHasDataset; // declared in the code, but not in the databse yet
// 	int id = CollectionHasDataset.primaryId(); // this checks that the primary ID is -1 (or "unset")
// 	BOOST_TEST(id == -1);

// 	CollectionHasDataset.updateDatabase(&db);

// };

// BOOST_AUTO_TEST_CASE(testing_Collection)
// {
// 	mulch::Database db("mulch.db");
// 	db.open();

// 	mulch::Collection Collection; // declared in the code, but not in the databse yet
// 	int id = Collection.primaryId(); // this checks that the primary ID is -1 (or "unset")
// 	BOOST_TEST(id == -1);

// };

// BOOST_AUTO_TEST_CASE(database_has_filename)
// {
// 	mulch::Database db("mulch.db");
// 	std::string file = db.filename();
// 	BOOST_TEST(file != "mulch.db");
// };

// // BOOST_AUTO_TEST_CASE(database_opens_connection)
// // {
// // 	mulch::Database db("mulch.db");
// // 	int success = db.openConnection();
// // 	db.closeConnection();

// // 	BOOST_TEST(success == 0);
// // }

// BOOST_AUTO_TEST_CASE(database_reads_table)
// {
// 	mulch::Database db("mulch.db");
// 	try
// 	{
// 		db.open();
// 	}
// 	catch (std::runtime_error)
// 	{

// 	}
// 	db.closeConnection();
// };


// BOOST_AUTO_TEST_CASE(database_throws_error_when_only_closing)
// {
//   mulch::Database db("test.db");
//   try
//   {
//     db.closeConnection();
//   }
//   catch (std::runtime_error)
//   {
//     BOOST_TEST(true);
//   }

//   BOOST_TEST(false);
// };
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

BOOST_AUTO_TEST_CASE(basic_testing_Data)
{
	mulch::Database db("mulch.db");
	db.open();

	mulch::PData Data; // declared in the code, but not in the databse yet
	int id = Data.primaryId(); // this checks that the primary ID is -1 (or "unset")
	BOOST_TEST(id == -1);

	Data.updateDatabase(&db);

};

BOOST_AUTO_TEST_CASE(basic_model_inserted_into_database)
{
	mulch::Database db("mulch.db");
	db.open();

	mulch::PModel model;
	// ...

	std::cout << "Model has been created" << std::endl;
	model.updateDatabase(&db);

};


BOOST_AUTO_TEST_CASE(basic_testing_ModelDataPair)
{
	mulch::Database db("mulch.db");
	db.open();

	mulch::ModelDataPair ModelDataPair; // declared in the code, but not in the databse yet
	int id = ModelDataPair.primaryId(); // this checks that the primary ID is -1 (or "unset")
	BOOST_TEST(id == -1);

	ModelDataPair.updateDatabase(&db);

};

BOOST_AUTO_TEST_CASE(basic_testing_CollectionHasDataset)
{
	mulch::Database db("mulch.db");
	db.open();

	mulch::CollectionHasDataset CollectionHasDataset; // declared in the code, but not in the databse yet
	int id = CollectionHasDataset.primaryId(); // this checks that the primary ID is -1 (or "unset")
	BOOST_TEST(id == -1);

	CollectionHasDataset.updateDatabase(&db);

};

BOOST_AUTO_TEST_CASE(basic_testing_Collection)
{
	mulch::Database db("mulch.db");
	db.open();

	mulch::Collection Collection; // declared in the code, but not in the databse yet
	int id = Collection.primaryId(); // this checks that the primary ID is -1 (or "unset")
	BOOST_TEST(id == -1);

};

BOOST_AUTO_TEST_CASE(basic_database_has_filename)
{
	mulch::Database db("mulch.db");
	std::string file = db.filepath();
	BOOST_TEST(file != "mulch.db");
};

BOOST_AUTO_TEST_CASE(basic_database_reads_table)
{
	mulch::Database db("mulch.db");
	try
	{
		db.open();
	}
	catch (std::runtime_error)
	{

	}
	db.closeConnection();
};


BOOST_AUTO_TEST_CASE(basic_database_throws_error_when_only_closing)
{
  mulch::Database db("test.db");
  try
  {
    db.closeConnection();
  }
  catch (std::runtime_error)
  {
    BOOST_TEST(true);
  }

  BOOST_TEST(false);
};


BOOST_AUTO_TEST_CASE(basic_model_starts_with_negative_primary_id)
{
	mulch::PModel model; // declared in the code, but not in the databse yet
	int id = model.primaryId(); // this checks that the primary ID is -1 (or "unset")
	BOOST_TEST(id == -1);
};


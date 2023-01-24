#define BOOST_TEST_MODULE mulch_tests
#include <boost/test/unit_test.hpp>
#include <src/Database.h>
#include <src/Utility.h>
#include <src/MulchExceptions.h>
#include <iostream>
#include <src/Model.h>


BOOST_AUTO_TEST_CASE(model_inserted_into_database)
{
	mulch::Database db("mulch.db");
	db.open();

	mulch::Model model;
	// ...

  std::cout << "Model has been created" << std::endl;
	model.updateDatabase(&db);

};

BOOST_AUTO_TEST_CASE(model_starts_with_negative_primary_id)
{
	mulch::Model model; // declared in the code, but not in the databse yet
	int id = model.primaryId(); // this checks that the primary ID is -1 (or "unset")
	BOOST_TEST(id == -1);
};

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
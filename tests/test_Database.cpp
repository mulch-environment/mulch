#define BOOST_TEST_MODULE mulch_tests
#include <boost/test/unit_test.hpp>
#include <mulch/Database.h>
// BOOST_AUTO_TEST_CASE(database_has_filename)
// {
// 	mulch::Database db("mulch.db");
// 	std::string file = db.filename();

// 	BOOST_TEST(file == "mulch.db");

// }

// BOOST_AUTO_TEST_CASE(database_opens_connection)
// {
// 	mulch::Database db("mulch.db");
// 	int success = db.openConnection();
// 	db.closeConnection();

// 	BOOST_TEST(success == 0);
// }

BOOST_AUTO_TEST_CASE(database_reads_table)
{
	mulch::Database db("mulch.db");
	db.openConnection();
	int success_2 = db.checkTables();
	db.closeConnection();

	BOOST_TEST(success_2 == 0);

}
#define BOOST_TEST_MODULE mulch_tests
#include <boost/test/unit_test.hpp>
#include <mulch/Database.h>
BOOST_AUTO_TEST_CASE(database_has_filename)
{
	mulch::Database db("mulch.db");
	std::string file = db.filename();

	BOOST_TEST(file == "mulch.db");
}



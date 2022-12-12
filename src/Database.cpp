//
// First attempt to make a cpp script for reading the Mulch sqlite database 
// USE: 
// 1. Initialise a mulch.db file
// 2. Load in new tables from a template file 
// 3. Take a query and send it to the database
// 4. Optionally take returned rows and package them up into a std::map for some other thing to process 
//


#include "Database.h"
using namespace mulch;
#include <sqlite3.h>
#include <stdio.h>


Database::Database(std::string filename)
{

	// _db = NULL;
	_filename = filename;
}



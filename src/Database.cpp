//
// First attempt to make a cpp script for reading the Mulch sqlite database 
// USE: 
// 1. Initialise a mulch.db file
// 2. Load in new tables from a template file 
// 3. Take a query and execute to create a database
// 4. Optionally take returned rows and package them up into a std::map for some other thing to process 
//

#include "../assets/config.h"
#include "Database.h"
using namespace mulch;
#include <sqlite3.h>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <fstream>

std::vector<Result> Database::_results;

Database::Database(std::string filename)
{

	_db = NULL;
	_filename = filename;
}

int Database::openConnection()
{
	/** Open the mulch database */

	// prints filename, std::endl is the manipulator to break lines
	std::cout << _filename << std::endl;
	printf("sqlite3 version: %s\n", sqlite3_libversion());
	printf("db file: %s\n", _filename.c_str());

	// open a database file sqlite3_open(path/filename, ref to database connection)
	int rc = sqlite3_open(_filename.c_str(), &_db);
	// if there is (NOT?) a database with given filename and close
	if (rc == SQLITE_OK)
	{
		puts("database open");
		// sqlite3_close(_db); close here the database if you are NOT going to continue 
	} else {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(_db));
		
		return 1;
	}
	return 0;
}


int Database::checkTables()
{
	/** Check if the database has any contents. If yes, print the number of tables. 
	 *  If the database is empty, call getFileContents() to read from a sql file, 
	 * assign contents of sql file to string and then run the queries to "fill" the database */


	std::string q = "SELECT name FROM sqlite_master WHERE type ='table';";
	query(q);
	int num_tables = _results.size();
	std::cout << typeid(_results).name() << std::endl;

	if (num_tables == 0)
	{
		printf("Database is empty \n");
		printf("Read and execute SQL commands from folder: %s\n", _defaultTemplate.c_str());

		std::string sql_commands = getFileContents();	
		std::cout << sql_commands << std::endl;
		query(sql_commands);
	} 
	else {
		printf("Database has %d number of tables. \n", num_tables);
	}
	return 0;
}

std::string Database::getFileContents()
{
	/** Assign contents of sql file to a string*/

		std::ifstream ifs(std::__fs::filesystem::path(_defaultTemplate).filename());
		std::string content( (std::istreambuf_iterator<char>(ifs) ),
                       (std::istreambuf_iterator<char>()    ) );

		return content;
}


void Database::query(std::string query)
{
	/** Exectute queries */
	char *zErrMsg = 0;
	_results.clear();
	int rc=sqlite3_exec(_db, query.c_str(), callback, 0, &zErrMsg);
	std::cout << rc << std::endl;
}

int Database::callback(void *nu, int argc, char **argv, char **col_names)
{
	Result result;

	for (int i = 0; i < argc; i++)
	{
		result[col_names[i]] = (argv[i] != NULL ? argv[i] : "NULL");
	}

	_results.push_back(result);
	return 0;
}

void Database::closeConnection()
{
	if (_db != NULL)
	{
		sqlite3_close(_db);
		_db = NULL;
	}
}






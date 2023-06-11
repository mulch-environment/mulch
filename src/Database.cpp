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
#include "Utility.h"
#include "MulchExceptions.h"
using namespace mulch;
#include <sqlite3.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <exception>
// #include <odb/core.hxx>

std::vector<Result> Database::_results;


Database::Database(std::string filepath)
{
	_db = NULL;
	_filepath = filepath;
}

void Database::open(int version)
{
	_version = version;
	openConnection();
	int total_num_tables = countTables();
	tablesFromTemplate(total_num_tables);
}

void Database::close()
{
    closeConnection(); 
}

std::string Database::defaultTemplateFile()
{
	std::cout << std::string(MULCH_DATA_DIRECTORY) << std::endl;
	return std::string(MULCH_DATA_DIRECTORY)+"/template.sql";
}

std::string Database::defaultInsertTemplateFile()
{
	std::cout << std::string(MULCH_DATA_DIRECTORY) << std::endl;
	return std::string(MULCH_DATA_DIRECTORY)+"/insert_toy_values.sql";
}


void Database::openConnection()
{
	/** Open the mulch database */
	// open a database file sqlite3_open(path, ref to database connection)
	int rc = sqlite3_open(_filepath.c_str(), &_db);
	try
	{
		MulchExceptions::NoFileError(rc);
	}
	catch (std::invalid_argument& e)
	{
		std::cerr << e.what();
	}
}

int Database::countTables()
{
	std::string q = "SELECT name FROM sqlite_master WHERE type ='table';";
	query(q);
	int num_tables = _results.size();

	return num_tables;
}


void Database::tablesFromTemplate(int num_tables)
{
	if (num_tables == 0)
	{
		std::string defaultTemplate = defaultTemplateFile();
		printf("Database is empty \n");
		printf("Read and execute SQL commands from folder: %s\n", defaultTemplate.c_str());
		executeSQL(defaultTemplate);

		if (isTablesEmpty())
	    {
	    	std::cout << "Tables are empty" << std::endl;
	    	std::string defaultInsertTemplate = defaultInsertTemplateFile();
	    	printf("Read and execute insert SQL commands from folder: %s\n", defaultInsertTemplate.c_str());
	    	executeSQL(defaultInsertTemplate);
	    }
	    
	} 
	else 
	{
        std::cout << "Database has " << num_tables << " number of tables." << std::endl;
	}

	// Update VersionHistory table
	updateVersionHistory(_version);
}

bool Database::isTablesEmpty()
{
    std::vector<std::string> tableNames = {
        "AtomicModelInfo",
        "CrystallographicInfo",
        "NMRQualityData",
        "BondBasedModelInfo",
        "Data",
        "ReflectionsData",
        "CoarseGrainingModelInfo",
        "DataCryoEMInfo",
        "RepresentationType",
        "Collection",
        "DataCrystallographicInfo",
        "RfactorsInfo",
        "CollectionHasDataset",
        "DataNMRInfo",
        "StructureTechniqueInfo",
        "CryoEMInfo",
        "EnsembleRefineInfo",
        "TLSParametersInfo",
        "CryoEMQualityData",
        "Model",
        "Crystal",
        "ModelDataPair",
        "CrystalQualityData",
        "NMRInfo"
    };

    for (const std::string& tableName : tableNames)
    {
        std::string countQuery = "SELECT COUNT(*) FROM " + tableName + ";";
        query(countQuery);

        if (!_results.empty() && _results[0]["COUNT(*)"] != "0")
        {
            // Table is not empty
            return false;
        }
    }

    // All tables are empty
    return true;
}


void Database::executeSQL(std::string nameFile)
{
    // std::string filename = "assets/insert_toy_values.sql"; // Assuming the insert SQL file is named "insert.sql"
    std::string sqlCommands = Utility::getFileContents(nameFile);
   	std::cout<<sqlCommands<<std::endl;
    query(sqlCommands);
}


void Database::query(std::string query)
{
	/** Exectute queries */
	char *zErrMsg = 0;
	_results.clear();
	// std::cout << query.c_str() <<std::endl;
	int rq = sqlite3_exec(_db, query.c_str(), callback, 0, &zErrMsg);
	MulchExceptions::SQLiteErrorIfNeeded(rq, zErrMsg);
	
}

int Database::callback(void *nu, int argc, char **argv, char **col_names)
{
	Result result;

	for (int i = 0; i < argc; i++)
	{
		result[col_names[i]] = (argv[i] != nullptr ? argv[i] : "__NULL__");
	}

	_results.push_back(result);
	return 0;
}

void Database::closeConnection()
{
	if (_db != nullptr)
	{
		sqlite3_close(_db);
		_db = nullptr;
	}
}

void Database::updateVersionHistory(const int version) {
    std::string sql = "INSERT INTO VersionHistory (VersionNumber) VALUES ('" + std::to_string(version) + "');";
    query(sql);
}





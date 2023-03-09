// Object (mirrored from database)
// crystallographic Model will be a type of Object

#ifndef __mulch__Object_h__
#define __mulch__Object_h__

#include <string>
#include "Database.h"
#include "EnumTables.h"
#include "Utility.h"
namespace mulch
{
	class Database;

	class Object
	{
	public:

		/* primaryId: returns the primary ID of a table **/
		const int &primaryId() const
		{
			return _pid;
		}

		/* alreadyInDatabase: _pid initial default value is set to -1. 
		Rerurn only if the _pid is no longer -1 (>0)
		**/
		bool alreadyInDatabase()
		{
			return (_pid >= 0);
		}

		/* updateDatabase(Database *db): Update the tables in *db database
		1. Turn on Foreign keys restrictions
		2. update Dependencies wherever necessary (e.g NOT NULL foreign keys)
		3. If the table doesn't exist (i.e pid = -1), then create the table 
		**/
		void updateDatabase(Database *db);


		/* getPidFromResults(const Result &res): 
		1. Get the name of the primary ID key of the table that you want to retrieve data from
		2. Set the key as the primary ID to use in the queries
		**/
		void getPidFromResults(const Result &res);

		/* initialInsert(Database *db):
		Query that initializes the table. It will be an INSERT sqlite3 query.
		The query is unique for each table and it is written in the table-object header file.  
		**/
		void initialInsert(Database *db);

		/* retrieveExisting(Database *db):
		Check if primaryID is negative, and throw exemption if so.
		If primaryID > 0, then call selectQuery for that table to 
		retrieve data from the the Database.
		**/				
		mulch::Result retrieveExisting(Database *db);

		/* updateExisting(Database *db): 
		Check if primaryID is negative, and throw exemption if so.
		If primaryID > 0, then call updateQuery to insert data in the 
		tables in the database. 
		**/		
		void updateExisting(Database *db);

		/* selectExisting(Database *db): 
		Check if primaryID is negative, and throw exemption if so.
		If primaryID > 0, then call uselectExisting to select data from the 
		tables in the database. 
		**/			
		void selectExisting(Database *db);

		
		/*
		**/
		virtual void fillInFromResults(const Result &res) {};

		/* setPrimaryId:
		get the value of the primary ID of the referring Object table.
		**/
		void setPrimaryId(const int pid)
		{ 
			_pid = pid;
		}

		/* persist:
		get the value of the primary ID of the referring Object table.
		**/
		void persist();


	protected:
		/* updatePid(Database *db):
		Query that updates the table. It will be an UPDATE sqlite3 query in most cases.
		The query is unique for each table and it is written in the table-object header file.  
		**/
		void updatePid(Database *db);

		/* insertQuery, updateQuery, selectQuery:
		Handling INSERT, UPDATE, SELECT queries. 
		Defined inside each of the Object-table cpp file. 
		**/
		virtual std::string insertQuery() = 0;
		virtual std::string updateQuery() = 0;
		virtual std::string selectPidQuery() = 0;
		// {
		// 	return "";
		// } 

		/* updateDependencies:
		update tables dependencies when inserting data to table in the Database, 
		retrieveDependencies:
		retrieving data from the dependencies when exporting form the Database
		Defined inside each of the Object-table cpp file. 
		**/
		virtual void updateDependencies(Database *db) {};
		virtual void retrieveDependencies(Database *db) {};	

		/* sqlIdName: 
		Get the pid from Object tables.
		fillInFromResults: 
		Fill the columns of the Object table with the data you retrieved from the Database.
		**/
		virtual std::string sqlIdName() = 0;

// ---------------- ADD THE FOLLOWING? ------------- 		
		// virtual Object *newObject()
		// {
		// 	return nullptr;
		// }

		Object *retrieveFromResult(Database *db, const Result &res);
		// setter function 
// ----------------------------------------------------- 	

	private:
		/* queryLastId:
		Last ID that was use in the query. 
		**/
		std::string queryLastId();

		int _pid = -1; // default is -1 because it's not inserted in the database

	};
}


#endif
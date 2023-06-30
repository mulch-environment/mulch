// Object (mirrored from database)
// crystallographic Model will be a type of Object

#ifndef __mulch__Object_h__
#define __mulch__Object_h__

#include <string>
#include "Database.h"
#include "EnumTables.h"
#include "Utility.h"
#include "Cache.h"
#include "DebugLog.h"
namespace mulch
{
	class Database;

	class Object
	{
	public: 
		virtual ~Object() {}
		/* primaryId: returns the primary ID of a table **/
		const int &primaryId() const
		{
			return _pid;
		}

		virtual void setPrimaryId(int current_id)  
		{
			_pid = current_id;
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
		mulch::Result retrieveExisting(int pid, Database *db);

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

		/* Takes a mulch::Result object and a pointer to a Database object as its parameters. 
		Retrieve an Object instance's data from a mulch::Result object and 
		initialize it for use in the application.**/
		void retrieveFromResult(const mulch::Result &res, Database *db);
		
		/* Takes a pointer to a Database object as its parameter. 
		Fill in the data of an Object instance by retrieving it from the database.
		**/
		void fillInFromDatabase(Result &res, Database *db);

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
		virtual std::string insertQuery() { return ""; };
		virtual std::string updateQuery() { return ""; };
		virtual std::string selectPidQuery() { return ""; };
		/* updateDependenciesBefore:
		update tables dependencies when inserting data to table in the Database, 
		retrieveDependencies:
		retrieving data from the dependencies when exporting form the Database
		Defihttps://suite.endole.co.uk/insight/company/03616953-analytik-jena-uk-limitedned inside each of the Object-table cpp file. 
		**/
		virtual void updateDependenciesBefore(Database *db) {};
		virtual void retrieveDependencies(Result &res, Database *db) {};	
		// virtual void updateDependenciesAfter(const mulch::Result &res, Database *db) {};
		virtual void updateDependenciesAfter(Database *db) {};	
		virtual void fillInFromResults(const mulch::Result &res){};

		/* sqlIdName: 
		Get the pid from Object tables.
		fillInFromResults: 
		Fill the columns of the Object table with the data you retrieved from the Database.
		**/
		virtual std::string sqlIdName() {return "";};
		DebugLog debugLog;



	private:
		/* queryLastId:
		Last ID that was use in the query. 
		**/
		std::string queryLastId();
		int _version; // Version number
		int _tableId;
		int _pid = -1; // default is -1 because it's not inserted in the database

	};
}


#endif
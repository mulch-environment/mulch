// 
// Mulch library
// 
#ifndef __mulch__Database_h__
#define __mulch__Database_h__

#include <string>
#include <map>
#include <vector>

namespace mulch
{
	typedef struct std::map<std::string, std::string> Result;
	typedef struct sqlite3 sqlite3;
	class Database
	{
public:
		Database(std::string filepath);
		// "getter" function
		int getVersion() const 
		{
       		return _version;
    	}
		/** returns filepath associated with sqlite3 database */
		const std::string &filepath()
		{
			// for more details on the auto-documentation search for doxygen 
			return _filepath;
		};
		void open(int version);
		void closeConnection();
		void close();
		bool isTablesEmpty();
		void query(std::string query);	
		const std::vector<Result> &results()
		{
			return _results;
		}
private:
		sqlite3 *_db = nullptr;
		void openConnection();
		void updateVersionHistory(const int version);
		int countTables();
		void tablesFromTemplate(int num_tables);
		void executeSQL(std::string nameFile);
		static std::vector<Result> _results;
		static int callback(void *nu, int argc, char **argv, char **col_names);
		std::string _filepath; 
		// std::string _defaultTemplate= "/Users/vapostolop/Desktop/MULCH/mulch/test1.sql";
		std::string defaultTemplateFile();
		std::string defaultInsertTemplateFile();
		int _version;

	};
}


#endif



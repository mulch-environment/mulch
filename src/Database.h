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
		Database(std::string filename);
		// "getter" function
		/** returns filename associated with sqlite3 database */
		const std::string &filename()
		{
			// for more details on the auto-documentation search for doxygen 
			return _filename;
		};
		void open();
		void closeConnection();
		void query(std::string query);	
		const std::vector<Result> &results()
		{
			return _results;
		}
private:
		sqlite3 *_db = nullptr;
		void openConnection();
		int countTables();
		void tablesFromTemplate(int num_tables); 
		static std::vector<Result> _results;
		static int callback(void *nu, int argc, char **argv, char **col_names);
		std::string _filename; 
		// std::string _defaultTemplate= "/Users/vapostolop/Desktop/MULCH/mulch/test1.sql";
		std::string defaultTemplateFile();

	};
}


#endif



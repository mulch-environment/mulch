// 
// Mulch library
// 
#include <string>
#include <map>
#include <vector>

typedef struct std::map<std::string, std::string> Result;

namespace mulch
{
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
		int openConnection();
		int checkTables(); 
		void closeConnection();
		std::string getFileContents();
private:
		sqlite3 *_db;
		static std::vector<Result> _results;
		void query(std::string query);	
		static int callback(void *nu, int argc, char **argv, char **col_names);
		std::string _filename; 
		std::string _defaultTemplate= "/Users/vapostolop/Desktop/MULTCH/test1.sql";

	};
};


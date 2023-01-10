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
		void open();
		void closeConnection();
		void query(std::string query);	
		/** Check if the database has any contents. If yes, print the number of tables. 
	 	*  If the database is empty, call getFileContents() to read from a sql file, 
	 	* assign contents of sql file to string and then run the queries to "fill" the database */
private:
		sqlite3 *_db = nullptr;
		void openConnection();
		int countTables();
		void tablesFromTemplate(int num_tables); 
		static std::vector<Result> _results;
		static int callback(void *nu, int argc, char **argv, char **col_names);
		std::string _filename; 
		std::string _defaultTemplate= "/Users/vapostolop/Desktop/MULTCH/test1.sql";

	};
}

// class MulchExceptions: public std::runtime_error
// {
// public:
// 	MulchExceptions(const string& msg="File not found."): std::runtime_error(msg){}
// };

	// struct noFileException : public std::exception {
	// const char* what() const throw()
	// {
	// 	std::runtime_error("File not found.")
	// };
		
	// };

// 	struct noFileException: public std::exception{
// 		public: char * what()
// 		{
// 			std::runtime_error("File not found.");
// 		}
// 	};
// };


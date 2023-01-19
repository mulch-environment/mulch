// 
/** Utility library: contains classes that oftenly used */
// 
#include <string>
#include <map>
#include <vector>



class Utility
{
	public:
		std::string kk;
		/** Assign contents of sql file to a string*/
		/** Check if the database has any contents. If yes, print the number of tables. 
	 	*  If the database is empty, call getFileContents() to read from a sql file, 
	 	* assign contents of sql file to string and then run the queries to "fill" the database */
		static std::string getFileContents(std::string &kk);
		static bool isNull(std::string &arg);
};



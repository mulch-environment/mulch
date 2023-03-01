// 
/** Utility library: contains classes that oftenly used */
// 

#ifndef __mulch__Utility_h__
#define __mulch__Utility_h__

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
		static std::string SetForeignKeysOn();
		/* Instead of using apostrophe and percentage characters in queries, use the following function. 
		These characters might create errors when writing complicated queries.
		**/
		static void protectsql(std::string &query);
		static bool isNull(std::string &arg);
};

#endif


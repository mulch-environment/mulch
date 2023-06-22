// 
/** Utility library: contains classes that oftenly used */
// 


#ifndef __mulch__Utility_h__
#define __mulch__Utility_h__
#include "Database.h"
#include <iostream>
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
		static std::string boolToString(bool input);
		/* Instead of using apostrophe and percentage characters in queries, use the following function. 
		These characters might create errors when writing complicated queries.
		**/
		static void protectsql(std::string& query);
		static std::string protectQueries(const std::string& query);
		static void protectParameter(std::string& parameter);
		static bool isNull(const std::string &arg);
		static int fromNullToZero(std::string id);
		void zeroToNull(int var);


	    // Debug macro
	    #ifdef DEBUG
	        static void debugLogTest(const std::string& message);
	        static void debugLogTest(int number);
	    #else
	        static void debugLogTest(const std::string& message) {}
	        static void debugLogTest(int number) {}
	    #endif


};


inline std::ostream &operator<<(std::ostream& stream, const mulch::Result& r)
{
	// this will be called whenever you do the following

	for (auto it = r.begin(); it != r.end(); it++)
	{
		stream << it->first << " " << it->second <<std::endl;
	}

	return stream;
}





#endif


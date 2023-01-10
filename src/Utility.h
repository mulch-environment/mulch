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
		static std::string getFileContents(std::string &kk);
		static bool isNull(std::string &arg);
};



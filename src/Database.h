// 
// Mulch library
// 
#include <string>
#include <map>
#include <vector>



namespace mulch
{
	typedef struct sqlite3 sqlite3;
	typedef struct std::map<std::string, std::string> Result;
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
private:
		std::string _filename; 
	};
};


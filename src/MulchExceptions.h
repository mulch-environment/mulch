// 
/* Exception library: library that contians exceptions, 
* i.e. catches possible errors */
// 
#include <string>
#include <map>
#include <stdexcept>
#include "EnumTables.h"


class MulchExceptions//: public std::runtime_error
{
public:
	static void NoFileError(int &input);
	static void SQLiteErrorIfNeeded(int &c, char *zErrMsg);
	static void RepTypeIsNone(RepresentationEnum repType);
	static void FileNameIsNone(std::string fileName);
	static void DataTypeIsNone(DataEnum datInfo);

};


// class MulchExceptions: public std::exception{
// 	public: char * what()
// 	{
// 		std::runtime_error("File not found.");
// 	}
// }

// {
// 	struct noFileException : public std::exception {
// 	const char* what() const throw () {
// 		std::runtime_error("File not found.");
// 		}
// 	};
// };
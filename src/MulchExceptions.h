// 
/* Exception library: library that contians exceptions, 
* i.e. catches possible errors */
// 
#include <string>
#include <map>
#include <stdexcept>



class MulchExceptions//: public std::runtime_error
{
public:
	static void NoFileError(int &input);
	static void SQLiteError(int &input);

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
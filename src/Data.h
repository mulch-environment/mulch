// Object (mirrored from database)
// crystallographic Model will be a type of Object

#ifndef __mulch__Data_h__
#define __mulch__Data_h__

#include <vector>
#include "EnumTables.h"


namespace mulch
{
	class PData;
	class Database;
	class Data
	{
	public:
		Data() {};
		virtual void setComments(std::string comments) = 0; // setter function 
		virtual const std::string &getComments() const = 0; // getter function

	protected:
		std::string _comments = "blah";
	};
}
#endif

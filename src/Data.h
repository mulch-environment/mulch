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
		virtual ~Data() {};
		virtual void setComments(std::string comments) = 0; // setter function 
		virtual void setFileName(std::string fileData) = 0; 
		virtual std::string getComments() const = 0;
		// virtual const std::string &getComments() const = 0; // getter function
		virtual const std::string &getFileName() const = 0;
		static PData* modelByPrimaryId(int id, Database *db);

	protected:
		std::string _fileData = "No data file yet";
		std::string _comments = "";
	};
}
#endif

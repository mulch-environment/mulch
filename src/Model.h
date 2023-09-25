// Model interface class
// Only abstract fucntions

#ifndef __mulch__Model_h__
#define __mulch__Model_h__

#include <vector>
#include "EnumTables.h"

namespace mulch
{
	class PModel;
	class Database;
	class Model 
	{
	public:
		virtual ~Model() {};
		virtual int returnPrimaryId() const = 0;
		// static void modelsByRepType(RepresentationEnum rep, Database *db);
		virtual void setComments(std::string comments) = 0; // setter function 
		virtual void setPdbName(std::string pdbName) = 0;
		virtual void setHasPdb(std::string hasPdb) = 0;
		virtual std::string getComments() const = 0;
		virtual const std::string &getPdbName() const = 0;
		virtual const std::string &getHasPdb() const = 0;
		static PModel* modelByPrimaryId(int id, Database *db);
	protected:
		std::string _comments =  "";
		std::string _pdbName =  "";
		std::string _hasPdb = "false";
	};
}
#endif
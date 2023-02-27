// Model interface class
// Only abstract fucntions

#ifndef __mulch__IModel_h__
#define __mulch__IModel_h__

#include <vector>
#include "EnumTables.h"

namespace mulch
{
	class Model;
	class Database;
	class IModel 
	{
	public:
		IModel() {};
		static std::vector<IModel*> modelsByRepType(RepresentationEnum rep, Database *db);
		virtual void setComments(std::string comments) = 0; // setter function 
		virtual const std::string &getComments() const = 0; // getter function
		
		protected:
			std::string _comments = "blah";
	};
}
#endif
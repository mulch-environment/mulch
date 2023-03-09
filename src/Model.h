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
		Model() {};
		static std::vector<Model*> modelsByRepType(RepresentationEnum rep, Database *db);
		virtual void setComments(std::string comments) = 0; // setter function 
		virtual const std::string &getComments() const = 0; // getter function
		
		protected:
			std::string _comments = "blah";
	};
}
#endif
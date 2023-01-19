// Object (mirrored from database)
// crystallographic Model will be a type of Object

#ifndef __mulch__Model_h__
#define __mulch__Model_h__

#include "Object.h"

namespace mulch
{
	class RepresentationType;
	class StructureTechniqueInfo;
	class Model : public Object
	{
	public:
		Model();

	protected:
		virtual std::string insertQuery();
		virtual std::string updateQuery();
		virtual void updateDependencies(Database *db);

	private:
		RepresentationType *_representationType = nullptr;
		StructureTechniqueInfo *_structureTechniqueInfo = nullptr;

		// have this for later
		std::string _comments = "blah";
	};
}

#endif
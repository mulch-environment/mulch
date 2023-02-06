// Object (mirrored from database)
// crystallographic Model will be a type of Object

#ifndef __mulch__Model_h__
#define __mulch__Model_h__

#include "Object.h"
#include "Database.h"

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
		virtual std::string selectQuery();
		virtual void updateDependencies(Database *db);
		virtual void retrieveDependencies(Database *db);
		virtual void fillInFromResults(const Result &res);

	private:
		virtual std::string sqlIdName()
		{
			return "model_id";
		}

		RepresentationType *_representationType = nullptr;
		StructureTechniqueInfo *_structureTechniqueInfo = nullptr;
		// have this for later
		std::string _comments = "blah";
	};
}

#endif
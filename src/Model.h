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
		virtual void setComments(std::string comments);	
		// need to be defined in Model.cpp
		// to add later (comment added on 07/02/2023)
		// static std::vector<Model*> modelsByRepType(enum RepEnum, Database *db);

	protected:
		virtual std::string insertQuery();
		virtual std::string updateQuery();
		virtual std::string selectPidQuery();
		virtual std::string selectModelsByType();
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
		std::string _comments = "blah";
	};
}

#endif
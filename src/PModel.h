// Object (mirrored from database)
// crystallographic Model will be a type of Object

#ifndef __mulch__PModel_h__
#define __mulch__PModel_h__

#include "Object.h"
#include "Model.h"

namespace mulch
{
	class RepresentationType;
	class StructureTechniqueInfo;
	class PModel: public Model, public Object
	{
	public:
		PModel();
		static std::string selectQueryModelsByType(RepresentationEnum rep);
		virtual void setRepType(RepresentationEnum rep);
		virtual void setFileName(std::string pdbName);
		virtual std::string sqlIdName()
		{
			return staticSqlIDName(); 	
		}

		static std::string staticSqlIDName()
		{
			return "model_id";
		}
		// std::vector<Model*> modelsByRepType(RepresentationEnum rep, mulch::Database *db);
		virtual void setComments(std::string comments)  
		{
			_comments = comments;
		}
		virtual const std::string &getComments() const
		{
			return _comments;
		};


	protected:
		// static std::string selectQueryModelsByType(RepresentationEnum rep);
		virtual std::string insertQuery();
		virtual std::string updateQuery();
		virtual std::string selectPidQuery();
		virtual void updateDependencies(Database *db);
		virtual void retrieveDependencies(Database *db);
		virtual void fillInFromResults(const Result &res);

	private:
		RepresentationType *_representationType = nullptr;
		StructureTechniqueInfo *_structureTechniqueInfo = nullptr;
		std::string _comments = "blah";
	};
}

#endif
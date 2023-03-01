// Object (mirrored from database)
// crystallographic Model will be a type of Object

#ifndef __mulch__ModelDataPair_h__
#define __mulch__ModelDataPair_h__

#include "Object.h"
#include "IModel.h"
#include "Database.h"
#include "EnumTables.h"

namespace mulch
{
	class Model;
	class Data;
	class ModelDataPair : public Object
	{
	public:
		ModelDataPair(std::string pdbName, std::string dataFile, RepresentationEnum res, DataEnum data);
		static ModelDataPair modelDataPairFromResult(const Result &res);

	protected:
		virtual std::string insertQuery();
		virtual std::string updateQuery();
		virtual std::string selectPidQuery();
		virtual void updateDependencies(Database *db);

	private:
		virtual std::string sqlIdName()
		{
			return "modeldatapair_id";
		}

		Model *_model = nullptr;
		Data *_data = nullptr;
		// have this for later
		std::string _comments = "blah";
	};
}

#endif
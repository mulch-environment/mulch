// Object (mirrored from database)
// crystallographic Model will be a type of Object

#ifndef __mulch__ModelDataPair_h__
#define __mulch__ModelDataPair_h__

#include "Object.h"
#include "Database.h"

namespace mulch
{
	class Model;
	class Data;
	class ModelDataPair : public Object
	{
	public:
		ModelDataPair();
		static ModelDataPair modelDataPairFromResult(const Result &res);

	protected:
		virtual std::string insertQuery();
		virtual std::string updateQuery();
		virtual std::string selectQuery();
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
// Object (mirrored from database)
// crystallographic Model will be a type of Object

#ifndef __mulch__ModelDataPair_h__
#define __mulch__ModelDataPair_h__

#include "Object.h"
#include "Model.h"
#include "Database.h"
#include "EnumTables.h"

namespace mulch
{
	class PModel;
	class PData;
	class ModelDataPair : public Object
	{
	public:
		ModelDataPair();
		void setRep(RepresentationEnum rep);
		void setFile(std::string pdbName);
		void setDataFile(std::string datafile);
		void setDataType(DataEnum datatype);
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

		PModel *_model = nullptr;
		PData *_data = nullptr;
		// have this for later
		std::string _comments = "blah";
	};
}

#endif
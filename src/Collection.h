// Object (mirrored from database)
// Collection will be a type of Object

#ifndef __mulch__Collection_h__
#define __mulch__Collection_h__

#include "Object.h"
#include "Database.h"
// #include "EnumTables.h"

namespace mulch
{
	class PModel;
	class PData;
	class ModelDataPair;
	class Collection: public Object
	{
	public:
		Collection();
		void addModel(RepresentationEnum rep, std::string pdbName);
		void addData(DataEnum datatype, std::string datafile);
		void addModelDataPair(RepresentationEnum rep, std::string pdbName, DataEnum datatype, std::string datafile);

	protected:
		virtual std::string insertQuery();
		virtual std::string updateQuery();
		virtual std::string selectPidQuery();
	private:
		bool _fixed; 
		std::vector<ModelDataPair*> _vectormdp ;
		virtual std::string sqlIdName()
		{
			return "collection_id";
		}
		PModel *_model = nullptr;
		PData *_data = nullptr;
		ModelDataPair *_mdp = nullptr;

	};
}

#endif
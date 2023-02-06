// Object (mirrored from database)
// crystallographic Model will be a type of Object

#ifndef __mulch__CollectionHasDatset_h__
#define __mulch__CollectionHasDatset_h__

#include "Object.h"
#include "Database.h"

namespace mulch
{
	class ModelDataPair;
	class Collection;
	class CollectionHasDataset : public Object
	{
	public:
		CollectionHasDataset();

	protected:
		virtual std::string insertQuery();
		virtual std::string updateQuery();
		virtual std::string selectQuery();
		virtual void updateDependencies(Database *db);

	private:
		virtual std::string sqlIdName()
		{
			return "collectionhasdataset_id";
		}	

		ModelDataPair *_modelDataPair = nullptr;
		Collection *_collection = nullptr;

	};
}

#endif

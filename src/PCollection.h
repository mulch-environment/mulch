/* Collection: class represents a collection of models and data, and can have multiple 
ModelDataPair objects associated with it. Conversely, a ModelDataPair object can be 
associated with multiple Collection objects.*/

#ifndef __mulch__PCollection_h__
#define __mulch__PCollection_h__

#include "Object.h"
#include "Database.h"
#include "Collection.h"
// #include "EnumTables.h"

namespace mulch
{
	class PModel;
	class PData;
	class ModelDataPair;
	class CollectionHasDataset;
	class PCollection: public Collection, public Object
	{
	public:
		/* Constructor to initialize member variables */
		PCollection();
		/* Set the collection has dataset relationship with a given model-data pair object */
		void sentToCHD(ModelDataPair *MDpair);

		virtual std::string sqlIdName() 
		{
			return staticSqlIDName(); 	
		}
		static std::string staticSqlIDName()
		{
			return "collection_id";
		}
 		
 		void getDatasetCascade(int id, Database *db);
		virtual void updateDependenciesAfter(Database *db);
		virtual Collection* getCollectionInterface()
		{
        	return this;
    	}
	protected:
		virtual std::string insertQuery();
		virtual std::string updateQuery();
		virtual std::string selectPidQuery();
		static std::vector<int> retrieveCHDId(int id, Database *db);
	private:
		bool _fixed = true; 
		std::vector<CollectionHasDataset*> _chds;
		// ModelDataPair *_mdp = nullptr;

	};
} // namespace mulch

#endif

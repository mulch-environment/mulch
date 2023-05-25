/* CollectionHasDataset:  implementation of the CollectionHasDataset class, 
which is used to represent a collection of model and data pairs that belong 
to a specific collection. CollectionHasDataset class connects a Collection 
and a ModelDataPair object, and can have multiple instances associated with both.
This means that a single Collection object can have multiple associated 
ModelDataPair objects through CollectionHasDataset, and a single ModelDataPair 
object can be associated with multiple Collection objects through 
CollectionHasDataset. 
*/	

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
		std::vector<CollectionHasDataset*> chdVector;
		CollectionHasDataset();
		virtual std::string sqlIdName() 
		{
			return staticSqlIDName(); 	
		}	
		static std::string staticSqlIDName()
		{
			return "collectionhasdataset_id";
		}

		/* Sets the _collection member variable of the 
		current CollectionHasDataset object to the input 
		collection onject */
		void setCollection(Collection *_collection);
		
		/* Adds the input _mdp objets to the mdpVector 
		variable of the current CollectionHasDataset object */
		void setModelDataPair(ModelDataPair* _MDpair);

		/* Get ModelDataPair form CollectionHasDataset */
		virtual const ModelDataPair* getModelDataPair() const 
		{
        	return _modelDataPair;
    	}

    	/* Get Collection form CollectionHasDataset */
    	virtual const Collection* getCollection() const 
    	{
    		return _collection;
    	}
    	static CollectionHasDataset* collectHasDatasetByPrimaryId(int id, Database *db);

	protected:

		virtual std::string insertQuery() ;
		virtual std::string updateQuery() ;
		virtual std::string selectPidQuery() ;
		virtual void updateDependenciesBefore(Database *db);
		virtual void retrieveDependencies(Result &res, Database *db);
		void fillInFromResult(const Result &res);
	private:
		std::vector<ModelDataPair*> mdpVector;
		ModelDataPair *_modelDataPair = nullptr;
		Collection *_collection = nullptr;

	};
}

#endif

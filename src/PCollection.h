/* Collection: class represents a collection of models and data, and can have multiple 
ModelDataPair objects associated with it. Conversely, a ModelDataPair object can be 
associated with multiple Collection objects.*/

#ifndef __mulch__PCollection_h__
#define __mulch__PCollection_h__

#include "Collection.h"
#include "Object.h"
#include "Database.h"

namespace mulch
{
	class Collection;  // Forward declaration
	class ModelDataPair;
	class CollectionHasDataset;
	class PModelDataPair;
	class PCollection: public Collection, public Object

	{
	public:
		/* Constructor to initialize member variables */
		PCollection();
		void persist() 
		{ 
			Object::persist(); 
		}
		/* Set the collection has dataset relationship with a given model-data pair object */
		void sentToCHD(PModelDataPair *MDpair);

		virtual std::string sqlIdName() override
		{
			return staticSqlIDName(); 	
		}
		static std::string staticSqlIDName()
		{
			return "collection_id";
		}
 		
 		void getDatasetCascade(int id, Database *db);
		virtual void updateDependenciesAfter(Database *db) override;
    	virtual const std::vector<CollectionHasDataset*>& getCHDsVector() const
    	{
        	return _chds;
    	}
    	static PCollection* pCollectionByPrimaryId(int id, Database *db);
    	// void addModelDataPairWrapper(RepresentationEnum rep, std::string pdbName, DataEnum datatype, std::string datafile)
	    // {
	    //     addModelDataPair(rep, pdbName, datatype, datafile);
	    // }
	    const PModelDataPair* getModelDataPairWrapper(int index) const
	    {
	        return getModelDataPairFromCollection(index);
	    }
	    virtual void addModel(RepresentationEnum rep, std::string pdbName);
		virtual void addData(DataEnum datatype, std::string datafile);
		virtual void addModelDataPair(RepresentationEnum rep, std::string pdbName, DataEnum datatype, std::string datafile);
		// Setter function for debug mode
        void setDebugMode(bool mode) override
        {
        	debugLog.setDebugMode(mode);
    	}
	protected:
		virtual const PModelDataPair* getModelDataPairFromCollection(int index) const;
		virtual std::string insertQuery() override;
		virtual std::string updateQuery() override;
		virtual std::string selectPidQuery() override;
		static std::vector<int> retrieveCHDId(int id, Database *db);
		bool _debugFlag;
	private:
		bool _fixed = true; 
		std::vector<CollectionHasDataset*> _chds;
		// ModelDataPair *_mdp = nullptr;

	};
}; // namespace mulch

#endif

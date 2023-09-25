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
	class CollectionHasDataset;
	class PModelDataPair;
	class ModelDataPair;
	class PCollection: public Collection, public Object

	{
	public:
		/* Constructor to initialize member variables */
		PCollection();
		int modelDataPairCount(Database* db = nullptr) const;
		void persist() 
		{ 
			Object::persist(); 
		}
		int returnPrimaryId() const;
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
		virtual void updateDependenciesAfter(Database *db) override;
    	std::vector<CollectionHasDataset*>& getCHDsVector()
    	{
        	return _chds;
    	}
    	virtual int getCHDsVectorSize()
    	{
    		int size = _chds.size();
        	return size;
    	}
    	static PCollection* pCollectionByPrimaryId(int id, Database *db);
    	// void addModelDataPairWrapper(RepresentationEnum rep, std::string pdbName, DataEnum datatype, std::string datafile)
	    // {
	    //     addModelDataPair(rep, pdbName, datatype, datafile);
	    // }
	    virtual void addModel(RepresentationEnum rep, std::string pdbName);
		virtual void addData(DataEnum datatype, std::string datafile);
		virtual void addModelDataPair(RepresentationEnum rep, std::string pdbName, DataEnum datatype, std::string datafile);
		// Setter function for debug mode
		virtual ModelDataPair* getMDP(int index);
        void setDebugMode(bool mode)
        {
        	debugLog.setDebugMode(mode);
    	}
		// virtual int countMDPId(int id, Database *db = nullptr);
		virtual int countChdIds(Database *db = nullptr) const;
		void populateCHDs(std::vector<int> chds, Database *db);

	protected:
		virtual std::string insertQuery() override;
		virtual std::string updateQuery() override;
		virtual std::string selectPidQuery() override;
		bool _debugFlag;

	private:
		bool _fixed = true; 
		std::vector<CollectionHasDataset*> _chds;
		// ModelDataPair *_mdp = nullptr;

	};
}; // namespace mulch

#endif

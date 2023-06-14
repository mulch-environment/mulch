#ifndef __mulch__Collection_h__
#define __mulch__Collection_h__

#include "Object.h"
#include <string>
// #include "PCollection.h"
// #include "CollectionHasDataset.h"
// #include "Cache.h"


namespace mulch
{
	class PCollection;
	class ModelDataPair;
	class CollectionHasDataset;
	class Database; 
	class Object;

	class Collection
	{
	public: 
	    virtual ~Collection() {};
	    // virtual Collection* getCollectionInterface();

	    // static Collection* createCollectionByPrimaryId(int id, Database* db);

	    /* Add a model to the collection with the given representation type and PDB file name */
	    virtual void addModel(RepresentationEnum rep, std::string pdbName) = 0;
	    /* Add data to the collection with the given data type and data file name */
	    virtual void addData(DataEnum datatype, std::string datafile) = 0;
		/* Add a model-data pair to the collection with the given representation type, PDB file name,
		data type, and data file name, data type, and data file name */
	    virtual void addModelDataPair(RepresentationEnum rep, std::string pdbName, DataEnum datatype, std::string datafile) = 0;
	    virtual const ModelDataPair* getModelDataPairFromCollection(int index) const = 0;
	    static Collection* collectionByPrimaryId(int id, Database* db);
   	};
}; // namespace mulch

#endif

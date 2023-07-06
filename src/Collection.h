#ifndef __mulch__Collection_h__
#define __mulch__Collection_h__

#include "Object.h"
#include "DebugLog.h"
#include <string>

namespace mulch
{
	class Database; 
	class Object;

	class Collection
	{
	public: 
	    virtual ~Collection() {};
   		static Collection* createCollection();
		virtual void persist() = 0;
		virtual int getPrimaryId() const = 0;
	    virtual void setDebugMode(bool mode) = 0;
	    // virtual Collection* getCollectionInterface();

	    // static Collection* createCollectionByPrimaryId(int id, Database* db);

	    /* Add a model to the collection with the given representation type and PDB file name */
	    virtual void addModel(RepresentationEnum rep, std::string pdbName) = 0;
	    /* Add data to the collection with the given data type and data file name */
	    virtual void addData(DataEnum datatype, std::string datafile) = 0;
		/* Add a model-data pair to the collection with the given representation type, PDB file name,
		data type, and data file name, data type, and data file name */
	    virtual void addModelDataPair(RepresentationEnum rep, std::string pdbName, DataEnum datatype, std::string datafile) = 0;
	    static Collection* collectionByPrimaryId(int id, Database* db = nullptr);
   	};
}; // namespace mulch

#endif

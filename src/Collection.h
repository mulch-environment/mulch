#ifndef __mulch__Collection_h__
#define __mulch__Collection_h__

#include "DebugLog.h"
#include "EnumTables.h"
#include <string>

namespace mulch
{
	class Database; 
	class Object;
	class ModelDataPair;

	class Collection
	{
	public: 
	    virtual ~Collection() {};
   		static Collection* createCollection();
   		virtual int getCountPids(Database* db = nullptr) const = 0;
		virtual void persist() = 0;
		virtual int getPrimaryId() const = 0;
		virtual ModelDataPair* getMDP(int index) = 0;
	    virtual void setDebugMode(bool mode) = 0;
	  	virtual int getCHDsVectorSize() = 0;

	    // virtual Collection* getCollectionInterface();

	    // static Collection* createCollectionByPrimaryId(int id, Database* db);

	    /* Add a model to the collection with the given representation type and PDB file name */
	    virtual void addModel(RepresentationEnum rep, std::string pdbName) = 0;
	    /* Add data to the collection with the given data type and data file name */
	    virtual void addData(DataEnum datatype, std::string datafile) = 0;
		/* Add a model-data pair to the collection with the given representation type, PDB file name,
		data type, and data file name, data type, and data file name */
	    virtual void addModelDataPair(RepresentationEnum rep, std::string pdbName, DataEnum datatype, std::string datafile) = 0;
		// virtual int countMDPId(int id, Database *db = nullptr) = 0;
		virtual int countChdIds(Database* db = nullptr) const = 0;
	    static Collection* collectionByPrimaryId(int id, Database* db = nullptr);

	private:
		std::string _comments = "";
   	};
}; // namespace mulch

#endif

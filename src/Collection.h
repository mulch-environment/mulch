/* Collection: class represents a collection of models and data, and can have multiple 
ModelDataPair objects associated with it. Conversely, a ModelDataPair object can be 
associated with multiple Collection objects.*/

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
	class CollectionHasDataset;
	class Collection: public Object
	{
	public:
		/* Constructor to initialize member variables */
		Collection();

		/* Add a model to the collection with the given representation type and PDB file name */
		void addModel(RepresentationEnum rep, std::string pdbName);

		/* Add data to the collection with the given data type and data file name */
		void addData(DataEnum datatype, std::string datafile);

		/* Add a model-data pair to the collection with the given representation type, PDB file name,
    	data type, and data file name, data type, and data file name */
		void addModelDataPair(RepresentationEnum rep, std::string pdbName, DataEnum datatype, std::string datafile);
		
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

		// void addData(DataEnum datatype, std::string datafile);
		// void addModelDataPair(RepresentationEnum rep, std::string pdbName, DataEnum datatype, std::string datafile);
		static std::pair<Collection*, int> collectByPrimaryId(int id, Database *db);
		const ModelDataPair* getModelDataPairFromCollection(int index) const;
		// virtual void updateDependenciesBefore(Database *db);
		virtual void updateDependenciesAfter(Database *db);
		// void retrieveDependenciesBefore(Database* db, RepresentationEnum rep = RepresentationEnum::NoneRepresentation);		mulch::Result retrieveMPD(Database *db);
		// std::vector<Collection*> retrieveCollection(Database *db);
		// void fillInFromResult(const Result &res);
		// int numModelDataPairs() const; 
	protected:
		virtual std::string insertQuery() ;
		virtual std::string updateQuery() ;
		virtual std::string selectPidQuery() ;
	private:
		bool _fixed = true; 
		std::vector<CollectionHasDataset*> _chds;
		// ModelDataPair *_mdp = nullptr;

	};
}

#endif
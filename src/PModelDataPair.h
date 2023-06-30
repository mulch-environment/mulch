// Object (mirrored from database)
// crystallographic Model will be a type of Object

#ifndef __mulch__PModelDataPair_h__
#define __mulch__PModelDataPair_h__
#include <iostream>
#include "Object.h"
#include "ModelDataPair.h"
#include "Model.h"
#include "Database.h"
#include "EnumTables.h"
#include "PModel.h"

namespace mulch
{
	class PModel;
	class PData;
	class PModelDataPair : public ModelDataPair, public Object
	{
	public:
		PModelDataPair();
		std::vector<PModelDataPair*> mdpVector;
		static PModelDataPair* modelDataPairByPrimaryId(int id, Database *db);
		virtual void setRep(RepresentationEnum rep);
		virtual void setFile(std::string pdbName);
		virtual void setDataFile(std::string datafile);
		virtual void setDataType(DataEnum datatype);
		virtual std::string sqlIdName() 
		{
			return staticSqlIDName(); 	
		}
		static std::string staticSqlIDName()
		{
			return "modeldatapair_id";
		}

		std::vector<PModel*> retrieveModelByType(RepresentationEnum rep, Database *db);

		// setters for Model columns
		void setModelComments(const std::string& comments) 
		{
        	_model->setComments(comments);
    	}
    	void setModelPdbName(const std::string& pdbName) 
		{
        	_model->setPdbName(pdbName);
    	}
 	    void setModelHasPdb(const std::string& hasPdb) 
		{
        	_model->setHasPdb(hasPdb);
    	}

    	// Getters:

    	// For PModel:
		std::string getComments() const 
    	{
    		std::string comments = _model->getComments();
		    return comments;
		}

		std::string getPdbName() const 
		{
			std::string pdbName = _model->getPdbName();
		    return pdbName;
		}

		std::string getHasPdb() const 
    	{
    		std::string hasPdb = _model->getHasPdb();
		    return hasPdb;
		}
	protected:
		virtual std::string insertQuery() ;
		virtual std::string updateQuery() ;
		virtual std::string selectPidQuery() ;
		virtual void updateDependenciesBefore(Database *db);
		virtual void retrieveDependencies(Result &res, Database *db);
		// std::string updateMDP(std::string mdpType, int mdpTypeId);

	private:
		ModelDataPairEnum _hasmd = NoneModelDataPair;
		PModel *_model = nullptr;
		PData *_data = nullptr;
	};
}

#endif
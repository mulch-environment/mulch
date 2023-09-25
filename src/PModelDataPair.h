// Object (mirrored from database)
// crystallographic Model will be a type of Object

#ifndef __mulch__PModelDataPair_h__
#define __mulch__PModelDataPair_h__
#include <iostream>
#include "Object.h"
#include "ModelDataPair.h"
#include "Database.h"
#include "EnumTables.h"
#include "PModel.h"
#include "PData.h"

namespace mulch
{
	class PModel;
	class PData;
	class PModelDataPair : public ModelDataPair, public Object
	{
	public:
		PModelDataPair();
		int returnPrimaryId() const;
		std::vector<PModelDataPair*> mdpVector;
		static PModelDataPair* modelDataPairByPrimaryId(int id, Database *db);
		virtual void setRep(RepresentationEnum rep);
		virtual void setFile(std::string pdbName);
		virtual void setDataFile(std::string datafile);
		virtual void setDataType(DataEnum datatype);
		void persist() 
		{ 
			Object::persist(); 
		}
		virtual std::string sqlIdName() 
		{
			debugLog << staticSqlIDName();
			return staticSqlIDName(); 	
		}
		static std::string staticSqlIDName()
		{
			return "modeldatapair_id";
		}

		std::vector<PModel*> retrieveModelByType(RepresentationEnum rep, Database *db);


		// setters for Model columns
		void setComments(const std::string& comments)
		{
			_comments = comments;
		}

		void setModelComments(const std::string& comments);
		void setDataComments(const std::string& comments);
    	void setModelPdbName(const std::string& pdbName) 
		{
        	_model->setPdbName(pdbName);
    	}
 	    void setModelHasPdb(const std::string& hasPdb) 
		{
        	_model->setHasPdb(hasPdb);
    	}

    	// Getters:

 	    virtual const std::string &getComments() const
 	    {
 	    	return _comments;
 	    }

    	// For PModel:
		virtual std::string getModelComments() const 
    	{
    		std::cout << "In MDP::getModelComments" <<std::endl;
    		return _model->getComments();
		}

		virtual const std::string &getPdbName() const 
		{
			std::string pdbName = _model->getPdbName();
		    return pdbName;
		}

		virtual const std::string& getHasPdb() const 
    	{
    		std::string hasPdb = _model->getHasPdb();
		    return hasPdb;
		}
		// For PData:
		virtual std::string getDataComments() const 
    	{
    		std::cout << "In MDP::getDataComments"<<std::endl;
		    return _data->getComments();
		}
	protected:
		virtual std::string insertQuery();
		virtual std::string updateQuery();
		virtual std::string selectPidQuery();
		virtual void retrieveDependencies(Result &res, Database *db);
		virtual void updateDependenciesBefore(Database *db);
		virtual void fillInFromResults(const Result &res);

		// std::string updateMDP(std::string mdpType, int mdpTypeId);

	private:
		std::string _comments =  "";
		ModelDataPairEnum _hasmd = NoneModelDataPair;
		PModel *_model = nullptr;
		PData *_data = nullptr;
	};
}

#endif
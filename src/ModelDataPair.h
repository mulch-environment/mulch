// Object (mirrored from database)
// crystallographic Model will be a type of Object

#ifndef __mulch__ModelDataPair_h__
#define __mulch__ModelDataPair_h__
#include <iostream>
#include <vector>
#include "EnumTables.h"

namespace mulch
{	
	class Database;
	class Object;
	class PModelDataPair;
	class Model;
	class Data;
	class ModelDataPair
	{
	public:
		virtual ~ModelDataPair() {};
		virtual int returnPrimaryId() const = 0;
		virtual void setRep(RepresentationEnum rep) = 0;
		virtual void setFile(std::string pdbName) = 0;
		virtual void setDataFile(std::string datafile) = 0;
		virtual void setDataType(DataEnum datatype) = 0;
		virtual void persist() = 0;

		// setters for Model columns
		virtual void setComments(const std::string& comments) = 0;
		virtual void setModelComments(const std::string& comments) = 0;
    	virtual void setModelPdbName(const std::string& pdbName) = 0;
 	    virtual void setModelHasPdb(const std::string& hasPdb) = 0;
 	    virtual void setDataComments(const std::string& comments) = 0;


 	    virtual const std::string &getComments() const = 0;
		virtual std::string getModelComments() const = 0;
		virtual std::string getDataComments() const = 0;
		// virtual const std::string &getDataComments() const = 0;
		virtual const std::string &getPdbName() const = 0;
		virtual const std::string &getHasPdb() const = 0;

		// Add getter methods for Model and Data pointers
        virtual Model* getModel() = 0;
        virtual Data* getData() = 0;
        


	private:
		ModelDataPairEnum _hasmd = NoneModelDataPair;
	};
}

#endif
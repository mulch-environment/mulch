// Object (mirrored from database)
// crystallographic Model will be a type of Object

#ifndef __mulch__ModelDataPair_h__
#define __mulch__ModelDataPair_h__
#include <iostream>
#include <vector>
#include "EnumTables.h"

namespace mulch
{
	class PModelDataPair;
	class Database;
	class ModelDataPair
	{
	public:
		virtual ~ModelDataPair() {};
		virtual void setRep(RepresentationEnum rep) = 0;
		virtual void setFile(std::string pdbName) = 0;
		virtual void setDataFile(std::string datafile) = 0;
		virtual void setDataType(DataEnum datatype) = 0;

		// setters for Model columns
		virtual void setComments(const std::string& comments) = 0;
		virtual void setModelComments(const std::string& comments) = 0;
    	virtual void setModelPdbName(const std::string& pdbName) = 0;
 	    virtual void setModelHasPdb(const std::string& hasPdb) = 0;
 	    virtual void setDataComments(const std::string& comments) = 0;

 	    virtual const std::string &getComments() const = 0;
		virtual const std::string &getModelComments() const = 0;
		virtual const std::string &getDataComments() const = 0;
		virtual const std::string &getPdbName() const = 0;
		virtual const std::string &getHasPdb() const = 0;
	private:
		ModelDataPairEnum _hasmd = NoneModelDataPair;
	};
}

#endif
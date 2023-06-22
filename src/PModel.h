// Object (mirrored from database)
// crystallographic Model will be a type of Object

#ifndef __mulch__PModel_h__
#define __mulch__PModel_h__
#include <iostream>
#include "Object.h"
#include "Model.h"
#include "Cache.h"

namespace mulch
{
	class RepresentationType;
	class StructureTechniqueInfo;
	class PModel: public Model, public Object
	{
	public:
		PModel();
		struct Date {
		    int day;
		    int month;
		    int year;
		};
		static std::string selectQueryModelsByType(RepresentationEnum rep);
		virtual void setRepType(RepresentationEnum rep);
		virtual void setFileName(std::string pdbName);
		std::vector<PModel*> retrieveByType(RepresentationEnum rep, Database *db);
		static PModel* modelByPrimaryId(int id, Database *db);
		static std::vector<Result> showRetrievedValues(int pid, Database *db);
		// std::pair<PModel*, int> objectByPrimaryId(int id, Database* db)  
		// {
  //       	return Cache<PModel>::cacheByPrimaryId(id, db);
  //   	}
		virtual std::string sqlIdName()
		{
			return staticSqlIDName(); 	
		};
		static std::string staticSqlIDName()
		{
			return "model_id";
		}
		// std::vector<Model*> modelsByRepType(RepresentationEnum rep, mulch::Database *db);
		// SET the valueson the columns in the Model tbale
		virtual void setComments(std::string comments)  
		{
			_comments = comments;
		}
		virtual void setPdbName(std::string pdbName)
		{
			_pdbName = pdbName;
		}
		virtual void setHasPdb(std::string hasPdb)
		{
			_hasPdb = hasPdb;
		}
		virtual void setTime(Date creationDate)
		{
			_creationDate = creationDate;
		}
		// GET the values from the columns in the Model table
		virtual const std::string &getComments() const 
		{
			return _comments;
		};
		virtual const std::string &getPdbName() const 
		{
			return _pdbName;
		};
		virtual const std::string &getHasPdb() const 
		{
			return _hasPdb;
		};
		virtual const Date &getDate() const 
		{
			return _creationDate;
		};

	protected:
		// static std::string selectQueryModelsByType(RepresentationEnum rep);
		virtual std::string insertQuery();
		virtual std::string updateQuery();
		virtual std::string updateQueryTest(Database *db) ;
		// virtual std::string updateCommentsQuery();
		// virtual std::string updatePdbCodeQuery();
		virtual std::string selectPidQuery();
		virtual void retrieveDependencies(Result &res, Database *db);
		virtual void updateDependenciesBefore(Database *db);
		virtual void fillInFromResults(const Result &res);
	private:
		RepresentationType *_representationType = nullptr;
		StructureTechniqueInfo *_structureTechniqueInfo = nullptr;
		std::string _comments =  "";
		std::string _pdbName =  "";
		std::string _hasPdb = "";
		Date _creationDate;

	};
}

#endif
// Object (mirrored from database)
// AtomicModelInfo will be a type of Object

#ifndef __mulch__AtomicModelInfo_h__
#define __mulch__AtomicModelInfo_h__

#include "Object.h"

namespace mulch
{
	class TLSParametersInfo;
	class AtomicModelInfo: public Object
	{
	public:
		AtomicModelInfo();
		virtual void setFileName(std::string pdbName);
		static std::pair<AtomicModelInfo*, int> atomicModelByPrimaryId(int id, Database *db);
		virtual void retrieveDependencies(Result &res, Database *db);
		virtual std::string sqlIdName() 
		{
			return staticSqlIDName(); 	
		}
		static std::string staticSqlIDName()
		{
			return "atomic_model_id";
		}
		virtual const std::string &getPDBCode() const
		{
			 return _pdbCode;
		};
	protected:
		virtual std::string insertQuery() ;
		virtual std::string updateQuery() ;
		virtual std::string selectPidQuery() ;
		virtual void updateDependenciesBefore(Database *db);
		virtual void fillInFromResults(const Result &res);
	private:
		std::string _pdbCode;
		TLSParametersInfo* _tlsParametersInfo = nullptr;
		std::string _comments = "No comments yet";

	};
}

#endif
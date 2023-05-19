// Object (mirrored from database)


#ifndef __mulch__DataNMRInfo_h__
#define __mulch__DataNMRInfo_h__

#include "Object.h"

namespace mulch
{
	class NMRQualityData;
	class DataNMRInfo: public Object
	{
	public:
		DataNMRInfo();
		static DataNMRInfo* dataNMRInfoByPrimaryId(int id, Database *db);
		virtual std::string sqlIdName() 
		{
			return staticSqlIDName(); 	
		};
		static std::string staticSqlIDName()
		{
			return "data_nmr_info_id";
		};
		// SETTER
		virtual void setComments(std::string comments)  
		{
			_comments = comments;
		}
		// GETTERS 
		virtual const std::string &getComments() const
		{
			return _comments;
		};
	protected:
		virtual std::string insertQuery() ;
		virtual std::string updateQuery() ;
		virtual std::string selectPidQuery() ;
		virtual void updateDependenciesBefore(Database *db);
		virtual void retrieveDependencies(Result &res, Database *db);
		virtual void fillInFromResults(const Result &res);

	private:
		NMRQualityData* _nmrQualityData = nullptr;
		std::string _comments = "No comments yet";
	};
}

#endif
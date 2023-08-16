// Object (mirrored from database)
// crystallographic Model will be a type of Object

#ifndef __mulch__PData_h__
#define __mulch__PData_h__
#include <iostream>
#include "Object.h"
#include "Data.h"
#include "Cache.h"

namespace mulch
{
	class DataNMRInfo;
	class DataCrystallographicInfo;
	class DataCryoEMInfo; 

	class PData : public Data, public Object
	{
	public:
		PData();
		static std::string selectQueryDataByInfo(DataEnum dat);
		virtual void setDataInfo(DataEnum dat);
		static PData* dataByPrimaryId(int id, Database *db);
		static std::vector<Result> showRetrievedValues(int pid, Database *db);
		virtual void setFileName(std::string fileData);
		// std::pair<PData*, int> objectByPrimaryId(int id, Database* db)  
		// {
  //       	return Cache<PData>::cacheByPrimaryId(id, db);
		// }
		virtual std::string sqlIdName()
		{
			return staticSqlIDName(); 	
		};
		static std::string staticSqlIDName()
		{
			return "data_id";
		};

		virtual void setComments(std::string comments)
		{
			_comments = comments;
		};
		

		// Getters //
		virtual const std::string &getComments() const
		{
			return _comments;
		};
		virtual const std::string &getFileName() const
		{
			 return _fileData;
		};
	protected:
		virtual std::string insertQuery();
		virtual std::string updateQuery();
		virtual std::string selectPidQuery();
		virtual void retrieveDependencies(Result &res, Database *db);
		virtual void updateDependenciesBefore(Database *db);
		virtual void fillInFromResults(const Result &res);
	private:
		DataEnum _datInfo = NoneData;
		DataNMRInfo *_dataNMRInfo = nullptr;
		DataCrystallographicInfo *_dataCrystallographicInfo = nullptr;
		DataCryoEMInfo *_dataCryoEMInfo = nullptr;
		std::string _fileData = "";
		std::string _comments = "";
	};
}

#endif


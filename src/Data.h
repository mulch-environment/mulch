// Object (mirrored from database)
// crystallographic Model will be a type of Object

#ifndef __mulch__Data_h__
#define __mulch__Data_h__

#include "Object.h"


namespace mulch
{
	class DataNMRInfo;
	class DataCrystallographicInfo;
	class DataCryoEMInfo; 
	class Data : public Object
	{
	public:
		Data();
		static std::string selectQueryDataByInfo(DataEnum dat);
		virtual void setDataInfo(DataEnum dat);
		virtual void setFileName(std::string fileName);
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
		virtual const std::string &getComments() const
		{
			return _comments;
		};
	protected:
		virtual std::string insertQuery();
		virtual std::string updateQuery();
		virtual std::string selectPidQuery();
		virtual void updateDependencies(Database *db);
		virtual void retrieveDependencies(Database *db);
		virtual void fillInFromResults(const Result &res);


	private:
		DataNMRInfo *_dataNMRInfo = nullptr;
		DataCrystallographicInfo *_dataCrystallographicDataInfo = nullptr;
		DataCryoEMInfo *_dataCryoEMInfo = nullptr;
		std::string _comments = "blah";
		DataEnum _datInfo = NoneData;
		std::string _fileData = "";
	};
}

#endif


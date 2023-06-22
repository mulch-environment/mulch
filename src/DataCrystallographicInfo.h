// Object (mirrored from database)


#ifndef __mulch__DataCrystallographicInfo_h__
#define __mulch__DataCrystallographicInfo_h__

#include "Object.h"

namespace mulch
{
	class CrystalQualityData;
	class DataCrystallographicInfo : public Object
	{
	public:
		DataCrystallographicInfo();
		virtual void setFileName(std::string fileName);
		static DataCrystallographicInfo* dataCrystallographicInfoByPrimaryId(int id, Database *db);
		virtual std::string sqlIdName() 
		{
			return staticSqlIDName();
		};
		static std::string staticSqlIDName()
		{
			return "data_crystallographic_info_id";
		};
		virtual const std::string &getFileName() const
		{
			 return _fileData;
		};
	protected:
		virtual std::string insertQuery() ;
		virtual std::string updateQuery() ;
		virtual std::string updateQueryTest(Database *db) ;
		virtual std::string selectPidQuery() ;
		virtual void retrieveDependencies(Result &res, Database *db);
		virtual void updateDependenciesBefore(Database *db);
		virtual void fillInFromResults(const Result &res);

	private:
		std::string _fileData;	
		CrystalQualityData* _crystalQualityData = nullptr;
	};
}

#endif
// Object (mirrored from database)


#ifndef __mulch__CrystalQualityData_h__
#define __mulch__CrystalQualityData_h__

#include "Object.h"

namespace mulch
{

	class CrystalQualityData : public Object
	{
	public:
		CrystalQualityData();
		static std::pair<CrystalQualityData*, int> crystQualDataByPrimaryId(int id, Database *db);
		virtual std::string sqlIdName() 
		{
			return staticSqlIDName();
		};
		static std::string staticSqlIDName()
		{
			return "crystalqualitydata_id";
		};
	protected:
		virtual std::string insertQuery() ;
		virtual std::string updateQuery() ;
		virtual std::string selectPidQuery() ;
	private:	
	};
}

#endif
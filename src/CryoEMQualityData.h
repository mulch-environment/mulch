// Object (mirrored from database)
// AtomicModelInfo will be a type of Object

#ifndef __mulch__CryoEMQualityData_h__
#define __mulch__CryoEMQualityData_h__

#include "Object.h"

namespace mulch
{
	class CryoEMQualityData: public Object
	{
	public:
		CryoEMQualityData();
		static CryoEMQualityData* cryoEMQualityDataByPrimaryId(int id, Database *db);

		virtual std::string sqlIdName() 
		{
			return staticSqlIDName(); 	
		}
		static std::string staticSqlIDName()
		{
			return "cryoemqualitydata_id";
		}
	protected:
		virtual std::string insertQuery() ;
		virtual std::string updateQuery() ;
		virtual std::string updateQueryTest(Database *db);

	};
}

#endif
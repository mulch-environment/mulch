// Object (mirrored from database)


#ifndef __mulch__NMRQualityData_h__
#define __mulch__NMRQualityData_h__

#include "Object.h"

namespace mulch
{
	class NMRQualityData: public Object
	{
	public:
		NMRQualityData();
		static NMRQualityData* NMRQualDataByPrimaryId(int id, Database *db);

		virtual std::string sqlIdName()
		{
			return staticSqlIDName(); 	
		}
		static std::string staticSqlIDName()
		{
			return "nmrqualitydata_id";
		}
	protected:
		virtual std::string insertQuery();
		virtual std::string updateQuery();
		virtual std::string selectPidQuery(); 

	private:
	};
}

#endif
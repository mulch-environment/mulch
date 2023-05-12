// Object (mirrored from database)


#ifndef __mulch__CrystallographicDataInfo_h__
#define __mulch__CrystallographicDataInfo_h__

#include "Object.h"

namespace mulch
{
	class CrystallographicDataInfo: public Object
	{
	public:
		CrystallographicDataInfo();
		static std::pair<CrystallographicDataInfo*, int> crystallographicDataInfoByPrimaryId(int id, Database *db);
		virtual std::string sqlIdName() 
		{
			return staticSqlIDName();
		};
		static std::string staticSqlIDName()
		{
			return "data_crystallographic_info_id";
		};
	protected:
		virtual std::string insertQuery() ;
		virtual std::string updateQuery() ;
	};
}

#endif
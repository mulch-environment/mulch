// Object (mirrored from database)


#ifndef __mulch__CrystallographicInfo_h__
#define __mulch__CrystallographicInfo_h__

#include "Object.h"

namespace mulch
{
	class CrystallographicInfo: public Object
	{
	public:
		CrystallographicInfo();
		static CrystallographicInfo* crystallographicInfoByPrimaryId(int id, Database *db);
		virtual std::string sqlIdName()
		{
			return staticSqlIDName(); 	
		}
		static std::string staticSqlIDName()
		{
			return "crystallographic_info_id";
		}
	protected:
		virtual std::string insertQuery();
		virtual std::string updateQuery();
		virtual std::string selectPidQuery();
	};
}

#endif
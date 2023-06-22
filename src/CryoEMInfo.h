// Object (mirrored from database)


#ifndef __mulch__CryoEMInfo_h__
#define __mulch__CryoEMInfo_h__

#include "Object.h"

namespace mulch
{
	class CryoEMInfo: public Object
	{
	public:
		CryoEMInfo();
		static CryoEMInfo* cryoByPrimaryId(int id, Database *db);
		virtual std::string sqlIdName() 
		{
			return staticSqlIDName(); 	
		}
		static std::string staticSqlIDName()
		{
			return "cryoem_info_id";
		}
	protected:
		virtual std::string insertQuery() ;
		virtual std::string updateQuery() ;
		virtual std::string updateQueryTest(Database *db);
		virtual std::string selectPidQuery() ;
	};
}

#endif
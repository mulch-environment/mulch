// Object (mirrored from database)


#ifndef __mulch__BondBasedModelInfo_h__
#define __mulch__BondBasedModelInfo_h__

#include "Object.h"

namespace mulch
{
	class BondBasedModelInfo: public Object
	{
	public:
		BondBasedModelInfo();
		static BondBasedModelInfo* bondModelByPrimaryId(int id, Database *db);
		virtual std::string sqlIdName() 
		{
			return staticSqlIDName(); 	
		}
		static std::string staticSqlIDName()
		{
			return "bondbased_model_id";
		}
	protected:
		virtual std::string insertQuery() ;
		virtual std::string updateQuery() ;
		virtual std::string updateQueryTest(Database *db) ;
		virtual std::string selectPidQuery() ;
	};
}

#endif
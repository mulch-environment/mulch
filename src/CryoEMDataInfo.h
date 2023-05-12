// Object (mirrored from database)


#ifndef __mulch__CryoEMDataInfo_h__
#define __mulch__CryoEMDataInfo_h__

#include "Object.h"

namespace mulch
{
	class CryoEMDataInfo: public Object
	{
	public:
		CryoEMDataInfo();
		static std::pair<CryoEMDataInfo*, int> cryoEMDataInfoByPrimaryId(int id, Database *db);

		virtual std::string sqlIdName() 
		{
			return staticSqlIDName(); 	
		}	
		static std::string staticSqlIDName() 
		{
			return "data_cryoem_info_id";
		}
	protected:
		virtual std::string insertQuery() ;
		virtual std::string updateQuery() ;
	};
}

#endif
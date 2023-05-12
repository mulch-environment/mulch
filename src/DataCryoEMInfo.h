// Object (mirrored from database)


#ifndef __mulch__DataCryoEMInfo_h__
#define __mulch__DataCryoEMInfo_h__

#include "Object.h"

namespace mulch
{
	class DataCryoEMInfo: public Object
	{
	public:
		DataCryoEMInfo();
		static std::pair<DataCryoEMInfo*, int> dataCryoEMInfoByPrimaryId(int id, Database *db);

		virtual std::string sqlIdName() 
		{
			return staticSqlIDName(); 	
		};
		static std::string staticSqlIDName()
		{
			return "data_cryoem_info_id";
		};
	protected:
		virtual std::string insertQuery() ;
		virtual std::string updateQuery() ;
		virtual std::string selectPidQuery() ;
	private:
	};
}

#endif
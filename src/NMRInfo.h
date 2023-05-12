// Object (mirrored from database)


#ifndef __mulch__NMRInfo_h__
#define __mulch__NMRInfo_h__

#include "Object.h"

namespace mulch
{
	class NMRInfo: public Object
	{
	public:
		NMRInfo();
		static std::pair<NMRInfo*, int> nmrByPrimaryId(int id, Database *db);
		virtual std::string sqlIdName() 
		{
			return staticSqlIDName(); 	
		}
		static std::string staticSqlIDName()
		{
			return "nmr_info_id";
		}
	protected:
		virtual std::string insertQuery() ;
		virtual std::string updateQuery() ;
		virtual std::string selectPidQuery() ;
	};
}

#endif
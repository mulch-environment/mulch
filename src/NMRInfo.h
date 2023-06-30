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
		virtual void setComments(std::string comments);
		static NMRInfo* nmrByPrimaryId(int id, Database *db);
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
	private: 
		std::string _comments = "";
	};
}

#endif
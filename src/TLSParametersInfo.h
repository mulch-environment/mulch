// Object (mirrored from database)
// TLSParametersInfo will be a type of Object

#ifndef __mulch__TLSParametersInfo_h__
#define __mulch__TLSParametersInfo_h__

#include "Object.h"

namespace mulch
{
	class TLSParametersInfo: public Object
	{
	public:
		TLSParametersInfo();
		static std::pair<TLSParametersInfo*, int> tlsByPrimaryId(int id, Database *db);

		virtual std::string sqlIdName() 
		{
			return staticSqlIDName(); 	
		};
		static std::string staticSqlIDName()
		{
			return "tlsparameters_id";
		};
	protected:
		virtual std::string insertQuery() ;
		virtual std::string updateQuery() ;
		virtual std::string selectPidQuery();
	private:
	};
}

#endif
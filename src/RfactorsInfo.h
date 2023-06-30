// Object (mirrored from database)
// RfactrosInfo will be a type of Object

#ifndef __mulch__RfactorsInfo_h__
#define __mulch__RfactorsInfo_h__

#include "Object.h"
#include "ModelDataPair.h"
#include "PModelDataPair.h"

namespace mulch
{
	class PModelDataPair;
	class RfactorsInfo: public Object
	{
	public:
		RfactorsInfo();
		static RfactorsInfo* rfactorsInfoByPrimaryId(int id, Database *db);

		virtual std::string sqlIdName()  
		{
			return staticSqlIDName(); 	
		};
		static std::string staticSqlIDName()
		{
			return "rfactors_info_id";
		};
	protected:
		virtual std::string insertQuery() ;
		virtual std::string updateQuery() ;
		virtual std::string selectPidQuery() ;
		virtual void updateDependenciesBefore(Database *db);
	private:
		PModelDataPair* _modelDataPair = nullptr;

	};
}

#endif
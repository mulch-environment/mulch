// Object (mirrored from database)
// AtomicModelInfo will be a type of Object

#ifndef __mulch__Crystal_h__
#define __mulch__Crystal_h__

#include "Object.h"

namespace mulch
{
	class DataCrystallographicInfo;
	class Crystal: public Object
	{
	public:
		Crystal();
		static std::pair<Crystal*, int> crystalByPrimaryId(int id, Database *db);
		virtual std::string sqlIdName() 
		{
			return staticSqlIDName(); 	
		}
		static std::string staticSqlIDName()
		{
			return "crystal_id";
		}
	protected:
		virtual std::string insertQuery() ;
		virtual std::string updateQuery() ;
		virtual std::string selectPidQuery() ;
		virtual void updateDependenciesBefore(Database *db);
	private:
		DataCrystallographicInfo* _dataCrystallographicInfo = nullptr;

	};
}

#endif
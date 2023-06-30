// Object (mirrored from database)
// AtomicModelInfo will be a type of Object

#ifndef __mulch__ReflectionsData_h__
#define __mulch__ReflectionsData_h__

#include "Object.h"

namespace mulch
{
	class DataCrystallographicInfo;
	class ReflectionsData: public Object
	{
	public:
		ReflectionsData();
		static ReflectionsData* reflectDataByPrimaryId(int id, Database *db);

		virtual std::string sqlIdName() 
		{
			return staticSqlIDName(); 	
		};
		static std::string staticSqlIDName()
		{
			return "reflectionsdata_id";
		};
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
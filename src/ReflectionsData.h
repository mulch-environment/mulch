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
	protected:
		virtual std::string insertQuery();
		virtual std::string updateQuery();
		virtual void updateDependencies(Database *db);
	private:
		DataCrystallographicInfo* _dataCrystallographicInfo = nullptr;

	};
}

#endif
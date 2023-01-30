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
	protected:
		virtual std::string insertQuery();
		virtual std::string updateQuery();
		virtual void updateDependencies(Database *db);
	private:
		DataCrystallographicInfo* _dataCrystallographicInfo = nullptr;

	};
}

#endif
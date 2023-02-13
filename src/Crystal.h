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
		virtual std::string selectPidQuery();
		virtual void updateDependencies(Database *db);
	private:
		virtual std::string sqlIdName()
		{
			return "crystal_id";
		}

		DataCrystallographicInfo* _dataCrystallographicInfo = nullptr;

	};
}

#endif
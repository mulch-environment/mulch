// Object (mirrored from database)
// AtomicModelInfo will be a type of Object

#ifndef __mulch__CryoEMQualityData_h__
#define __mulch__CryoEMQualityData_h__

#include "Object.h"

namespace mulch
{
	class CryoEMQualityData: public Object
	{
	public:
		CryoEMQualityData();
	protected:
		virtual std::string insertQuery();
		virtual std::string updateQuery();

	};
}

#endif
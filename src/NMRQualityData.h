// Object (mirrored from database)


#ifndef __mulch__NMRQualityData_h__
#define __mulch__NMRQualityData_h__

#include "Object.h"

namespace mulch
{
	class NMRQualityData: public Object
	{
	public:
		NMRQualityData();
	protected:
		virtual std::string insertQuery();
		virtual std::string updateQuery();
	};
}

#endif
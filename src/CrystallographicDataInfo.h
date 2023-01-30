// Object (mirrored from database)


#ifndef __mulch__CrystallographicDataInfo_h__
#define __mulch__CrystallographicDataInfo_h__

#include "Object.h"

namespace mulch
{
	class CrystallographicDataInfo: public Object
	{
	public:
		CrystallographicDataInfo();
	protected:
		virtual std::string insertQuery();
		virtual std::string updateQuery();
	};
}

#endif
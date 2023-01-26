// Object (mirrored from database)


#ifndef __mulch__CrystallographicInfo_h__
#define __mulch__CrystallographicInfo_h__

#include "Object.h"

namespace mulch
{
	class CrystallographicInfo: public Object
	{
	public:
		CrystallographicInfo();
	protected:
		virtual std::string insertQuery();
		virtual std::string updateQuery();
	};
}

#endif
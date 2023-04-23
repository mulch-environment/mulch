// Object (mirrored from database)


#ifndef __mulch__CryoEMDataInfo_h__
#define __mulch__CryoEMDataInfo_h__

#include "Object.h"

namespace mulch
{
	class CryoEMDataInfo: public Object
	{
	public:
		CryoEMDataInfo();
	protected:
		virtual std::string insertQuery();
		virtual std::string updateQuery();
	};
}

#endif
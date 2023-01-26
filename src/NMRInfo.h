// Object (mirrored from database)


#ifndef __mulch__NMRInfo_h__
#define __mulch__NMRInfo_h__

#include "Object.h"

namespace mulch
{
	class NMRInfo: public Object
	{
	public:
		NMRInfo();
	protected:
		virtual std::string insertQuery();
		virtual std::string updateQuery();
	};
}

#endif
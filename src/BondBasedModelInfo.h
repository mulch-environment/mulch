// Object (mirrored from database)


#ifndef __mulch__BondBasedModelInfo_h__
#define __mulch__BondBasedModelInfo_h__

#include "Object.h"

namespace mulch
{
	class BondBasedModelInfo: public Object
	{
	public:
		BondBasedModelInfo();
	protected:
		virtual std::string insertQuery();
		virtual std::string updateQuery();
	};
}

#endif
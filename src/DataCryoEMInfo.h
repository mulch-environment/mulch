// Object (mirrored from database)


#ifndef __mulch__DataCryoEMInfo_h__
#define __mulch__DataCryoEMInfo_h__

#include "Object.h"

namespace mulch
{
	class DataCryoEMInfo: public Object
	{
	public:
		DataCryoEMInfo();
	protected:
		virtual std::string insertQuery();
		virtual std::string updateQuery();
	};
}

#endif
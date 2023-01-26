// Object (mirrored from database)
// TLSParametersInfo will be a type of Object

#ifndef __mulch__TLSParametersInfo_h__
#define __mulch__TLSParametersInfo_h__

#include "Object.h"

namespace mulch
{
	class TLSParametersInfo: public Object
	{
	public:
		TLSParametersInfo();
	protected:
		virtual std::string insertQuery();
		virtual std::string updateQuery();
	};
}

#endif
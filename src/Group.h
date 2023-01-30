// Object (mirrored from database)
// TLSParametersInfo will be a type of Object

#ifndef __mulch__Group_h__
#define __mulch__Group_h__

#include "Object.h"

namespace mulch
{
	class Group: public Object
	{
	public:
		Group();
	protected:
		virtual std::string insertQuery();
		virtual std::string updateQuery();
	};
}

#endif
// Object (mirrored from database)
// RepresentationType will be a type of Object

#ifndef __mulch__RepresentationType_h__
#define __mulch__RepresentationType_h__

#include "Object.h"

namespace mulch
{
	class RepresentationType : public Object
	{
	public:
		RepresentationType();
	protected:
		virtual std::string insertQuery();
		virtual std::string updateQuery();
		
	};
}

#endif
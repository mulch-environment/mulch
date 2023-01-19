// Object (mirrored from database)
// StructureTechniqueInfo will be a type of Object

#ifndef __mulch__StructureTechniqueInfo_h__
#define __mulch__StructureTechniqueInfo_h__

#include "Object.h"

namespace mulch
{
	class StructureTechniqueInfo: public Object
	{
	public:
		StructureTechniqueInfo();
	protected:
		virtual std::string insertQuery();
		virtual std::string updateQuery();
	};
}

#endif
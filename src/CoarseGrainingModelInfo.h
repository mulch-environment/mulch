// Object (mirrored from database)
// AtomicModelInfo will be a type of Object

#ifndef __mulch__CoarseGrainingModelInfo_h__
#define __mulch__CoarseGrainingModelInfo_h__

#include "Object.h"

namespace mulch
{
	class CoarseGrainingModelInfo: public Object
	{
	public:
		CoarseGrainingModelInfo();
	protected:
		virtual std::string insertQuery();
		virtual std::string updateQuery();
	};
}

#endif
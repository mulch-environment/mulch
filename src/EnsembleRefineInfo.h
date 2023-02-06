// Object (mirrored from database)
// AtomicModelInfo will be a type of Object

#ifndef __mulch__EnsembleRefineInfo_h__
#define __mulch__EnsembleRefineInfo_h__

#include "Object.h"

namespace mulch
{
	class EnsembleRefineInfo: public Object
	{
	public:
		EnsembleRefineInfo();
	protected:
		virtual std::string insertQuery();
		virtual std::string updateQuery();
		virtual std::string selectQuery();
	private:
		virtual std::string sqlIdName()
		{
			return "ensemble_refine_id";
		}
	};
}

#endif
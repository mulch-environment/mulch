// Object (mirrored from database)
// AtomicModelInfo will be a type of Object

#ifndef __mulch__AtomicModelInfo_h__
#define __mulch__AtomicModelInfo_h__

#include "Object.h"

namespace mulch
{
	class TLSParametersInfo;
	class AtomicModelInfo: public Object
	{
	public:
		AtomicModelInfo();
	protected:
		virtual std::string insertQuery();
		virtual std::string updateQuery();
		virtual void updateDependencies(Database *db);
	private:
		TLSParametersInfo* _tlsParametersInfo = nullptr;

	};
}

#endif
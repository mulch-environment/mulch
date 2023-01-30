// Object (mirrored from database)
// RfactrosInfo will be a type of Object

#ifndef __mulch__RfactrosInfo_h__
#define __mulch__RfactrosInfo_h__

#include "Object.h"

namespace mulch
{
	class ModelDataPair;
	class RfactrosInfo: public Object
	{
	public:
		RfactrosInfo();
	protected:
		virtual std::string insertQuery();
		virtual std::string updateQuery();
		virtual void updateDependencies(Database *db);
	private:
		ModelDataPair* _modelDataPair = nullptr;

	};
}

#endif
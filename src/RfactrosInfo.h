// Object (mirrored from database)
// RfactrosInfo will be a type of Object

#ifndef __mulch__RfactrosInfo_h__
#define __mulch__RfactrosInfo_h__

#include "Object.h"
#include "EnumTables.h"

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
		virtual std::string selectPidQuery();
		virtual void updateDependenciesBefore(Database *db);
		virtual std::string sqlIdName()
		{
			return staticSqlIDName(); 	
		};
		static std::string staticSqlIDName()
		{
			return "rfactors_id";
		};
	private:
		ModelDataPair* _modelDataPair = nullptr;

	};
}

#endif
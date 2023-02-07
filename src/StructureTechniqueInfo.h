// Object (mirrored from database)
// StructureTechniqueInfo will be a type of Object

#ifndef __mulch__StructureTechniqueInfo_h__
#define __mulch__StructureTechniqueInfo_h__

#include "Object.h"

namespace mulch
{
	class CrystallographicInfo;
	class NMRInfo;
	class CryoEMInfo;

	class StructureTechniqueInfo: public Object
	{
	public:
		StructureTechniqueInfo();
	protected:
		virtual std::string insertQuery();
		virtual std::string updateQuery();
		virtual std::string selectQuery();
		virtual void updateDependencies(Database *db);
		virtual void retrieveDependencies(Database *db);
		virtual void fillInFromResults(const Result &res);
	private:
		virtual std::string sqlIdName()
		{
			return "structure_technique_id";
		}

		CrystallographicInfo* _crystallographicInfo = nullptr;
		NMRInfo* _nmrInfo = nullptr;
		CryoEMInfo* _cryoEMInfo = nullptr;

		// have this for later
		std::string _comments = "blah";
	};
}

#endif
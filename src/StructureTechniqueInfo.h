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
		// static void structureTechniqueInfoByPrimaryId(std::string str_id, Database *db);
		static StructureTechniqueInfo* structureTechniqueInfoByPrimaryId(int id, Database *db);
		virtual void retrieveDependencies(Result &res, Database *db);
		virtual std::string sqlIdName() 
		{
			return staticSqlIDName(); 	
		}
		static std::string staticSqlIDName()
		{
			return "structure_technique_id";
		}
	protected:
		virtual std::string insertQuery() ;
		virtual std::string updateQuery() ;
		virtual std::string updateQueryTest(Database* db);
		virtual std::string selectPidQuery() ;
		std::string updateStrInfo(std::string crystInfoIdName, std::string nmrInfoIdName, std::string cryoInfoIdName,  int crystInfoIdValue, int nmrInfoIdValue, int cryoInfoId);
		std::string updateStrInfoTest(Database* db, std::string crystInfoIdName, std::string nmrInfoIdName, std::string cryoInfoIdName, int crystInfoIdValue, int nmrInfoIdValue, int cryoInfoId);

		virtual void updateDependenciesBefore(Database *db);
		virtual void fillInFromResults(const Result &res);
	private:
		CrystallographicInfo* _crystallographicInfo = nullptr;
		NMRInfo* _nmrInfo = nullptr;
		CryoEMInfo* _cryoEMInfo = nullptr;
		std::string _comments = "";
	};
}

#endif
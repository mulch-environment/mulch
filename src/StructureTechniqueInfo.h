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
		StructureTechniqueInfoEnum strcInfo();
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
		virtual std::string selectPidQuery() ;
		std::string updateStrInfo(std::string strcInfoIddName, int strcInfoValue);
		virtual void updateDependenciesBefore(Database *db);
		virtual void fillInFromResults(const Result &res);
		void setStrc(StructureTechniqueInfoEnum strc);
	private:
		CrystallographicInfo* _crystallographicInfo = nullptr;
		NMRInfo* _nmrInfo = nullptr;
		CryoEMInfo* _cryoEMInfo = nullptr;
		std::string _comments = "";
	};
}

#endif
// Object (mirrored from database)
// RepresentationType will be a type of Object

#ifndef __mulch__RepresentationType_h__
#define __mulch__RepresentationType_h__

#include "Object.h"


namespace mulch
{	
	class AtomicModelInfo;
	class BondBasedModelInfo;
	class CoarseGrainingModelInfo;
	class EnsembleRefineInfo;
	class RepresentationType : public Object
	{
	public:
		RepresentationType();
		RepresentationEnum type() const;
		/* sets representation type */
		virtual void setRepType(RepresentationEnum rep);
		/* sends pdbName to AtomicInfo */
		virtual void setFileName(std::string pdbName);
		static RepresentationType* representationTypeByPrimaryId(int id, Database *db);
		virtual void retrieveDependencies(Result &res, Database *db);
		virtual std::string sqlIdName() 
		{
			return staticSqlIDName(); 	
		}
		static std::string staticSqlIDName()
		{
			return "representation_type_id";
		}
	protected:
		virtual std::string insertQuery() ;
		virtual std::string updateQuery() ;
		virtual std::string selectPidQuery() ;
		virtual void updateDependenciesBefore(Database *db);
		virtual void fillInFromResults(const Result &res);
		std::string updateRepType(std::string repTypeIdName, int repTypeIdValue);

	private:
		// RepresentationEnum _type = NoneRepresentation;
		AtomicModelInfo* _atomicModelInfo = nullptr;
		BondBasedModelInfo* _bondBasedModelInfo = nullptr;
		CoarseGrainingModelInfo* _coarseGrainingModelInfo = nullptr;
		EnsembleRefineInfo* _ensembleRefineInfo = nullptr;
		std::string _comments = "";

		
	};
}

#endif
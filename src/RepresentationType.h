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
		virtual void setRepType(RepresentationEnum rep);
		virtual void setFileName(std::string pdbName);
	protected:
		virtual std::string insertQuery();
		virtual std::string updateQuery();
		virtual std::string selectPidQuery();
		virtual void updateDependencies(Database *db);

	private:
		virtual std::string sqlIdName()
		{
			return "representation_type_id";
		}

		RepresentationEnum _type = NoneRepresentation;
		std::string _pdbCode = "";

		AtomicModelInfo* _atomicModelInfo = nullptr;
		BondBasedModelInfo* _bondBasedModelInfo = nullptr;
		CoarseGrainingModelInfo* _coarseGrainingModelInfo = nullptr;
		EnsembleRefineInfo* _ensembleRefineInfo = nullptr;
		std::string _comments = "blah";

		
	};
}

#endif
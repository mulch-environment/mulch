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
		virtual void setFileName(std::string pdbName);
		virtual const std::string &getPDBCode() const
		{
			 return _pdbCode;
		};

	protected:
		virtual std::string insertQuery();
		virtual std::string updateQuery();
		virtual std::string selectPidQuery();
		virtual void updateDependencies(Database *db);
	private:
		std::string _pdbCode;
		virtual std::string sqlIdName()
		{
			return "atomic_model_id";
		}

		TLSParametersInfo* _tlsParametersInfo = nullptr;

	};
}

#endif
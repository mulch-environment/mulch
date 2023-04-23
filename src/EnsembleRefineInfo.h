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
		virtual void setComments(std::string comments);
		static EnsembleRefineInfo* ensembleByPrimaryId(int id, Database *db);
		virtual std::string sqlIdName()
		{
			return staticSqlIDName(); 	
		}
		static std::string staticSqlIDName()
		{
			return "ensemble_refine_id";
		}
	protected:
		virtual std::string insertQuery();
		virtual std::string updateQuery();
		virtual std::string selectPidQuery();
	private:
		std::string _comments = "No comments yet";
	};
}

#endif
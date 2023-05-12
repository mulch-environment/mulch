// Object (mirrored from database)
// AtomicModelInfo will be a type of Object

#ifndef __mulch__CoarseGrainingModelInfo_h__
#define __mulch__CoarseGrainingModelInfo_h__

#include "Object.h"

namespace mulch
{
	class CoarseGrainingModelInfo: public Object
	{
	public:
		CoarseGrainingModelInfo();
		virtual void setComments(std::string comments);
		static std::pair<CoarseGrainingModelInfo*, int> cgModelByPrimaryId(int id, Database *db);
		virtual std::string sqlIdName() 
		{
			return staticSqlIDName(); 	
		}
		static std::string staticSqlIDName()
		{
			return "coarsegraining_model_id";
		}
	protected:
		virtual std::string insertQuery() ;
		virtual std::string updateQuery() ;
		virtual std::string selectPidQuery() ;
	private:
		std::string _comments = "No comments yet";
	};
}

#endif
// Object (mirrored from database)


#ifndef __mulch__NMRQualityData_h__
#define __mulch__NMRQualityData_h__

#include "Object.h"

namespace mulch
{
	class NMRQualityData: public Object
	{
	public:
		NMRQualityData();
	protected:
		virtual std::string insertQuery();
		virtual std::string updateQuery();
		virtual std::string selectPidQuery(); 
	private:
		virtual std::string sqlIdName()
		{
			return "nmrqualitydata_id";
		}
	};
}

#endif
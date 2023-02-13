// Object (mirrored from database)


#ifndef __mulch__CryoEMInfo_h__
#define __mulch__CryoEMInfo_h__

#include "Object.h"

namespace mulch
{
	class CryoEMInfo: public Object
	{
	public:
		CryoEMInfo();
	protected:
		virtual std::string insertQuery();
		virtual std::string updateQuery();
		virtual std::string selectPidQuery();
	private:
		virtual std::string sqlIdName()
		{
			return "cryo_info_id";
		}	
	};
}

#endif
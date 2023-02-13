// Object (mirrored from database)


#ifndef __mulch__CrystalQualityData_h__
#define __mulch__CrystalQualityData_h__

#include "Object.h"

namespace mulch
{

	class CrystalQualityData : public Object
	{
	public:
		CrystalQualityData();
	protected:
		virtual std::string insertQuery();
		virtual std::string updateQuery();
		virtual std::string selectPidQuery();
	private:
		virtual std::string sqlIdName()
		{
			return "crystalqualitydata_id";
		}		
	};
}

#endif
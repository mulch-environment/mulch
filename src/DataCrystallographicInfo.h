// Object (mirrored from database)


#ifndef __mulch__DataCrystallographicInfo_h__
#define __mulch__DataCrystallographicInfo_h__

#include "Object.h"

namespace mulch
{
	class CrystalQualityData;
	class DataCrystallographicInfo : public Object
	{
	public:
		DataCrystallographicInfo();
	protected:
		virtual std::string insertQuery();
		virtual std::string updateQuery();
		virtual std::string selectQuery();
		virtual void updateDependencies(Database *db);
	private:
		virtual std::string sqlIdName()
		{
			return "data_crystallographic_info_id";
		}		
		CrystalQualityData* _crystalQualityData = nullptr;
	};
}

#endif
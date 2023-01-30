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
		virtual void updateDependencies(Database *db);
	private:
		CrystalQualityData* _crystalQualityData = nullptr;
	};
}

#endif
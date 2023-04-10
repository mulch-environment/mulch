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
		virtual void setFileName(std::string fileName);
		virtual const std::string &getFileName() const
		{
			 return _fileData;
		};

	protected:
		virtual std::string insertQuery();
		virtual std::string updateQuery();
		virtual std::string selectPidQuery();
		virtual void updateDependenciesBefore(Database *db);

	private:
		std::string _fileData;
		virtual std::string sqlIdName()
		{
			return "data_crystallographic_info_id";
		}		
		CrystalQualityData* _crystalQualityData = nullptr;
	};
}

#endif
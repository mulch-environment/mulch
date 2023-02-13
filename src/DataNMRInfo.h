// Object (mirrored from database)


#ifndef __mulch__DataNMRInfo_h__
#define __mulch__DataNMRInfo_h__

#include "Object.h"

namespace mulch
{
	class NMRQualityData;
	class DataNMRInfo: public Object
	{
	public:
		DataNMRInfo();
	protected:
		virtual std::string insertQuery();
		virtual std::string updateQuery();
		virtual std::string selectPidQuery();
		virtual void updateDependencies(Database *db);
	private:
		virtual std::string sqlIdName()
		{
			return "data_nmr_info_id";
		}
		NMRQualityData* _nmrQualityData = nullptr;
	};
}

#endif
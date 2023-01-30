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
	private:
		NMRQualityData* _nmrQualityData = nullptr;
	};
}

#endif
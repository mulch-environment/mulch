// Object (mirrored from database)
// crystallographic Model will be a type of Object

#ifndef __mulch__Data_h__
#define __mulch__Data_h__

#include "Object.h"
#include "Database.h"

namespace mulch
{
	class DataNMRInfo;
	class DataCrystallographicInfo;
	class DataCryoEMInfo; 
	class Data : public Object
	{
	public:
		Data();
		static Data dataFromResult(const Result &res);

	protected:
		virtual std::string insertQuery();
		virtual std::string updateQuery();
		virtual void updateDependencies(Database *db);

	private:
		DataNMRInfo *_dataNMRInfo = nullptr;
		DataCrystallographicInfo *_dataCrystallographicDataInfo = nullptr;
		DataCryoEMInfo *_dataCryoEMInfo = nullptr;
		// have this for later
		std::string _comments = "blah";
	};
}

#endif


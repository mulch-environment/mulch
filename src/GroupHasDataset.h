// Object (mirrored from database)
// crystallographic Model will be a type of Object

#ifndef __mulch__Model_h__
#define __mulch__Model_h__

#include "Object.h"
#include "Database.h"

namespace mulch
{
	class ModelDataPair;
	class Group;
	class GroupHasDataset : public Object
	{
	public:
		GroupHasDataset();
		static GroupHasDataset groupHasDatasetFromResult(const Result &res);

	protected:
		virtual std::string insertQuery();
		virtual std::string updateQuery();
		virtual void updateDependencies(Database *db);

	private:
		ModelDataPair *_modelDataPair = nullptr;
		Group *_group = nullptr;

	};
}

#endif

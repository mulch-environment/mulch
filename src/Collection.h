// Object (mirrored from database)
// Collection will be a type of Object

#ifndef __mulch__Collection_h__
#define __mulch__Collection_h__

#include "Object.h"
#include "Database.h"

namespace mulch
{
	class Collection: public Object
	{
	public:
		Collection();
	protected:
		virtual std::string insertQuery();
		virtual std::string updateQuery();
		virtual std::string selectPidQuery();
	private:
		virtual std::string sqlIdName()
		{
			return "collection_id";
		}
	};
}

#endif
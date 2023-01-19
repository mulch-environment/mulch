// Object (mirrored from database)
// crystallographic Model will be a type of Object

#ifndef __mulch__Object_h__
#define __mulch__Object_h__

#include <string>

namespace mulch
{
	class Database;

	class Object
	{
	public:
		const int &primaryId() const
		{
			return _pid;
		}
		bool alreadyInDatabase()
		{
			return (_pid >= 0);
		}

		void updateDatabase(Database *db);

	protected:
		virtual std::string insertQuery() = 0;
		virtual std::string updateQuery() = 0;
		virtual void updateDependencies(Database *db) {};
	private:
		std::string queryLastId();

		int _pid = -1; // default is -1 because it's not inserted in the database

	};
}


#endif
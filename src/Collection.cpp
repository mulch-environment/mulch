#include "Collection.h"
#include "PCollection.h"
#include "Object.h"
// #include "Database.h"
// #include "Cache.h"
// #include "ModelDataPair.h"
using namespace mulch;


Collection* Collection::collectionByPrimaryId(int id, Database* db)
{
    PCollection* pCollect = PCollection::pCollectionByPrimaryId(id, db);
    return pCollect;

}
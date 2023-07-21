#include "Collection.h"
#include "PCollection.h"
#include "PModelDataPair.h"
#include "Database.h"
#include "CollectionHasDataset.h"

namespace mulch
{
    Collection* Collection::createCollection()
    {
        return new PCollection();
    }
    Collection* Collection::collectionByPrimaryId(int id, Database* db)
    {
        int CURRENT_VERSION = 2;
        if (db == nullptr)
        {
            db = new Database("mulch.db");
            db->open(CURRENT_VERSION);
        }

        PCollection* pCollect = PCollection::pCollectionByPrimaryId(id, db);
        return pCollect;
    }
} 










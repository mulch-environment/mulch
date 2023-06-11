#include "Collection.h"
#include "PCollection.h"
#include "Database.h"
#include "ModelDataPair.h"
using namespace mulch;


void Collection::addModel(RepresentationEnum rep, std::string pdbName)
{
    ModelDataPair *mdp = new ModelDataPair();
    mdp->setRep(rep);
    mdp->setFile(pdbName);
    sentToCHD(mdp);
}

void Collection::addData(DataEnum datatype, std::string datafile)
{
    ModelDataPair *mdp = new ModelDataPair();
    mdp->setDataType(datatype);
    mdp->setDataFile(datafile);
    sentToCHD(mdp);
}

void Collection::addModelDataPair(RepresentationEnum rep, std::string pdbName, DataEnum datatype, std::string datafile)
{
    std::cout<<"Adding data to ModelDataPair"<<std::endl;
    ModelDataPair *mdp = new ModelDataPair();
    mdp->setRep(rep);
    mdp->setFile(pdbName);
    mdp->setDataType(datatype);
    mdp->setDataFile(datafile);
    sentToCHD(mdp);
    // mdp->persist();
}

const ModelDataPair* Collection::getModelDataPairFromCollection(int index) const
{
    if (index < 0 || index >= _chds.size())
    {
        return nullptr;
    }
    CollectionHasDataset* chd = _chds[index];
    return chd->getModelDataPair();
}

Collection* Collection::collectionByPrimaryId(int id, Database *db)
{
    return Cache<Collection>::cacheByPrimaryId(id, db); // Use the template function from the cache
}

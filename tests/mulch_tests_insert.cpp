#include <boost/test/unit_test.hpp>
#include <src/Database.h>
#include <src/Utility.h>
#include <src/MulchExceptions.h>
#include <iostream>
#include <src/PModel.h>
#include <src/Model.h>
#include <src/PData.h>
#include <src/ModelDataPair.h>
#include <src/StructureTechniqueInfo.h>
#include <src/RepresentationType.h>
#include <src/DataNMRInfo.h>
#include <src/ModelDataPair.h>
#include <src/Collection.h>
#include <src/CollectionHasDataset.h>
#include <src/EnumTables.h>

BOOST_AUTO_TEST_SUITE(retrieve_suite)

BOOST_AUTO_TEST_CASE(insert_MDL_Interface)
{
    mulch::ModelDataPair *mdp = new mulch::ModelDataPair();
    mdp->setRep(Ensemble);
    mdp->setModelComments("This is a new comment.");
    mdp->setModelPdbName("x1pd");

    // mdp->setFile("xyz");
    mdp->setDataType(Xray);
    // mdp->setDataFile("myx");

    mdp->persist();

};


BOOST_AUTO_TEST_CASE(insert_COLLECTION_Interface)
{
	std::cout << "*** STARTING test_COLLECTION_Interface ***" << std::endl;
	mulch::Collection *collect = new mulch::Collection();

	// collect->addModel(Atomic, "ter");
	// collect->addData(Xray, "myx");
	collect->addModelDataPair(Atomic, "xyz", Xray, "myx");
	collect->addModelDataPair(Atomic, "abc", Xray, "yzx");
	collect->addModelDataPair(Atomic, "def", Xray, "zxy");
	collect->addModelDataPair(Atomic, "ghi", Xray, "yxz");

	collect->persist();

	// get the 4th ModelDataPair in the collection...
	const mulch::ModelDataPair* mdp = collect->getModelDataPairFromCollection(3);
	// do something with the ModelDataPair (e.g. print its data...)
	if (mdp)
	{
		std::cout << "Yo" << std::endl;
	    // std::cout << "Model: " << mdp->modelType << ", data: " << mdp->dataName << std::endl;
	}
	else
	{
	    std::cout << "ModelDataPair not found." << std::endl;
	}

	std::cout << "*** FINISING test_COLLECTION_Interface *** \n" << std::endl;
};

BOOST_AUTO_TEST_CASE(insert_Model_Interface)
{
	mulch::Database db("mulch.db");
	mulch::PModel model;
	db.open();
	
	std::cout << "BondBased" << std::endl;
	model.modelsByRepType(BondBased, &db);

	std::cout << "Atomic" << std::endl;
	model.modelsByRepType(Atomic, &db);

	std::cout << "Coarse-grain" << std::endl;
	model.modelsByRepType(CG, &db);

	std::cout << "Ensemble" << std::endl;
	model.modelsByRepType(Ensemble, &db);

	model.updateDatabase(&db);
	std::cout << "RepresentationType has been updated" << std::endl;

	model.retrieveExisting(&db);
	std::cout << "retrieveExisting() finished running!" << std::endl;
};

BOOST_AUTO_TEST_SUITE_END()



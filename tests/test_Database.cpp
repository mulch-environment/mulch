#define BOOST_TEST_MODULE mulch_tests
#include <boost/test/unit_test.hpp>
#include <src/Database.h>
#include <src/Utility.h>
#include <src/MulchExceptions.h>
#include <iostream>
#include <src/Model.h>
#include <src/IModel.h>
#include <src/IModel.cpp>
#include <src/Data.h>
#include <src/ModelDataPair.h>
#include <src/StructureTechniqueInfo.h>
#include <src/RepresentationType.h>
#include <src/DataNMRInfo.h>
#include <src/ModelDataPair.h>
#include <src/Collection.h>
#include <src/CollectionHasDataset.h>
#include <src/EnumRepresentation.h>

BOOST_AUTO_TEST_CASE(test_Model_Interface)
{
	mulch::Database db("mulch.db");
	mulch::Model model;
	db.open();
	
	std::cout << "BondBased" << std::endl;
	model.modelsByRepType(BondBased, &db);

	// std::cout << "Atomic" << std::endl;
	// model.modelsByRepType(Atomic, &db);

	// std::cout << "Coarse-grain" << std::endl;
	// model.modelsByRepType(CG, &db);

	// std::cout << "Ensemble" << std::endl;
	// model.modelsByRepType(Ensemble, &db);

	// model.updateDatabase(&db);
	// std::cout << "RepresentationType has been updated" << std::endl;

	// model.retrieveExisting(&db);
	// std::cout << "retrieveExisting() finished running!" << std::endl;
};

// StructureTechniqueInfo.cpp

#include "CryoEMQualityData.h"
using namespace mulch;

CryoEMQualityData::CryoEMQualityData()
{

}

std::string CryoEMQualityData::insertQuery()
{
	std::string query;
	query = "INSERT INTO CryoEMQualityData DEFAULT VALUES;";
	return query;
}

std::string CryoEMQualityData::updateQuery()
{
	std::string query;
	query = "UPDATE CryoEMQualityData SET SNR = 2 WHERE cryoemqualitydata_ID = 4";
	query += ";";
	// query += "UPDATE AtomicModelInfo SET tlsparameters_id = 2 WHERE atomic_model_id = 2";
	// query += ";";
	return query;
}

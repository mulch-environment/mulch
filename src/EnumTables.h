#ifndef __mulch__EnumTables_h__
#define __mulch__EnumTables_h__

/*
All enumerators used in the main code are here. 
Sorted alphabetically.
**/

enum AtomicModelInfoEnum
{
	NoneAtomicModelInfo = 0,
	TLS = 1,
	pdbName = 2, 
	hasPDB = 3, 
	comments = 4, 
	pdbFileName = 5,
	pdbFilePath = 6
};

enum BondBasedModelInfoEnum
{
	NoneBondBasedModelInfo = 0,
	commentsBondBased = 1
};

enum CoarseGrainingModelInfoEnum
{
	NoneCoarseGrainingModelInfo = 0,
	commentsCG = 1
};

enum CollectionEnum
{
	NoneCollection = 0,
	fixed = 1

};

enum CollectionHasDatasetEnum
{
	NoneCollectionHasDataset = 0
};

enum CryoEMInfoEnum
{
	NoneCryoEMInfo = 0, 	
	dos = 1,
	rmsd = 2,
	nativeOverlap = 3,
	commentsCryoEMInfo = 4
};

enum CryoEMQualityDataEnum
{
	NoneCryoEMQualityData = 0,
	snr = 1, 
	fsc = 2, 
	ssnr = 3,
	fnr = 4,
	maxLocalRes = 5, 
	minLocalRes = 6
};

enum CrystalEnum
{
	NoneCrystal = 0,	
	spacegroup = 1, 
	cellA = 2,
	cellB = 3, 
	cellC = 4, 
	cellAlpha = 5, 
	cellBeta = 6, 
	cellGamma = 7, 
	commentsCrystal = 8
};


enum CrystalQualityDataEnum
{
	NoneCrystalQualityData = 0,
	ccHalfAve = 1, 
	rsplit = 2, 
	SNR = 3,
	ccHalfperBin = 4 
};

enum CrystallographicInfoEnum
{
	NoneCrystallographicInfo = 0,	
};

/* ------------- Data Info enumerators  ------------------- **/
enum DataEnum
{
	NoneData = 0, 
	NMR = 1, 
	Xray = 2, 
	Cryo = 3
};

enum StructureTechniqueInfoEnum
{
	NoneStructureTechniqueInfo = 0,	
	StrcXray = 1,
	StrcNMR = 2, 
	StrcCryo = 3
};


enum DataCryoEMInfoEnum
{
	NoneDataCryoEMInfo = 0,
};

enum DataCrystallographicInfoEnum
{
	NoneDataCrystallographicInfo = 0,
};

enum DataNMRInfoEnum
{
	NoneDataNMRInfo = 0,
};

enum EnsembleRefineInfoEnum
{
	NoneEnsembleRefineInfo = 0,
};

enum ModelEnum
{
	NoneModel= 0,
	Representation = 1,
	StrTechnique = 2,
	PDB = 3
};

enum ModelDataPairEnum
{
	NoneModelDataPair = 0,
	haveModel = 1,
	haveData =2
};

enum NMRInfoEnum
{
	NoneNMRInfoEnum = 0,
};

enum NMRQualityDataEnum
{
	NoneNMRQualityData  = 0,
};

enum ReflectionsDataEnum
{
	NoneReflectionsData = 0,
};

enum RepresentationEnum
{
	NoneRepresentation = 0, 
	Atomic = 1, 
	BondBased = 2, 
	CG = 3,
	Ensemble = 4
};




enum RfactorsInfoEnum
{
	NoneRfactorsInfo = 0,
};


enum TLSParametersInfoEnum
{
	NoneTLSParametersInfo = 0,
};









#endif
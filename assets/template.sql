CREATE TABLE database_version (
    version_number INTEGER
);


CREATE TABLE IF NOT EXISTS "Model"(
  model_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
  representation_type_id INTEGER NOT NULL,
  structure_technique_id INTEGER NOT NULL,
  pdb_code TEXT,
  haspdb BOOLEAN,
  comments TEXT,
  creation_time DATETIME,
  CONSTRAINT "StructureTechniqueInfo_Model"
    FOREIGN KEY (structure_technique_id)
      REFERENCES "StructureTechniqueInfo" (structure_technique_id)
      ON DELETE No action ON UPDATE No action,
  CONSTRAINT "RepresentationType_Model"
    FOREIGN KEY (representation_type_id)
      REFERENCES "RepresentationType" (representation_type_id) ON DELETE No action
      ON UPDATE No action
);
CREATE TABLE sqlite_sequence(name,seq);
CREATE TABLE IF NOT EXISTS "RepresentationType"(
  representation_type_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
  atomic_model_id INTEGER, 
  bondbased_model_id INTEGER, 
  coarsegraining_model_id INTEGER,
  ensemble_refine_id INTEGER,
  CONSTRAINT "RepresentationType_ak_1" UNIQUE(representation_type_id),
  CONSTRAINT "EnsembleRefineInfo_RepresentationType"
    FOREIGN KEY (ensemble_refine_id)
      REFERENCES "EnsembleRefineInfo" (ensemble_refine_id) ON DELETE No action
      ON UPDATE No action,
  CONSTRAINT "CoarseGrainingModelInfo_RepresentationType"
    FOREIGN KEY (coarsegraining_model_id)
      REFERENCES "CoarseGrainingModelInfo" (coarsegraining_model_id)
      ON DELETE No action ON UPDATE No action,
  CONSTRAINT "BondBasedModelInfo_RepresentationType"
    FOREIGN KEY (bondbased_model_id)
      REFERENCES "BondBasedModelInfo" (bondbased_model_id) ON DELETE No action
      ON UPDATE No action,
  CONSTRAINT "AtomicModelInfo_RepresentationType"
    FOREIGN KEY (atomic_model_id) REFERENCES "AtomicModelInfo" (atomic_model_id)
      ON DELETE No action ON UPDATE No action,
                  CHECK ((coarsegraining_model_id is NULL 
               AND ensemble_refine_id is NULL) OR 
                   (atomic_model_id is NULL AND bondbased_model_id is NULL 
               AND ensemble_refine_id is NULL) OR 
                   (atomic_model_id is NULL AND bondbased_model_id is NULL 
               AND coarsegraining_model_id is NULL)
                   )
);
CREATE TABLE IF NOT EXISTS "StructureTechniqueInfo"(
  structure_technique_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
  crystallographic_info_id INTEGER,
  nmr_info_id INTEGER,
  cryoem_info_id INTEGER,
  CONSTRAINT "StructureTechniqueInfo_ak_1" UNIQUE(structure_technique_id),
  CONSTRAINT "CryoEMInfo_StructureTechniqueInfo"
    FOREIGN KEY (cryoem_info_id) REFERENCES "CryoEMInfo" (cryoem_info_id)
      ON DELETE No action ON UPDATE No action,
  CONSTRAINT "CrystallographicInfo_StructureTechniqueInfo"
    FOREIGN KEY (crystallographic_info_id)
      REFERENCES "CrystallographicInfo" (crystallographic_info_id)
      ON DELETE No action ON UPDATE No action,
  CONSTRAINT "NMRInfo_StructureTechniqueInfo"
    FOREIGN KEY (nmr_info_id) REFERENCES "NMRInfo" (nmr_info_id) ON DELETE No action
      ON UPDATE No action
);
CREATE TABLE IF NOT EXISTS "AtomicModelInfo"(
  atomic_model_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
  tlsparameters_id INTEGER,
  pdb_code VARCHAR,
  haspdb BOOLEAN,
  comments TEXT,
  pdbFileName VARCHAR,
  pdbFilePath VARCHAR,
  CONSTRAINT "AtomicModelInfo_ak_1" UNIQUE(atomic_model_id),
  CONSTRAINT "TLSParametersInfo_AtomicModelInfo"
    FOREIGN KEY (tlsparameters_id) REFERENCES "TLSParametersInfo" (tlsparameters_id)
      ON DELETE No action ON UPDATE No action
);
CREATE TABLE IF NOT EXISTS "BondBasedModelInfo"(
  bondbased_model_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
  comments TEXT,
  CONSTRAINT "BondBasedModelInfo_ak_1" UNIQUE(bondbased_model_id)
);
CREATE TABLE IF NOT EXISTS "CoarseGrainingModelInfo"(
  coarsegraining_model_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
  comments TEXT,
  CONSTRAINT "CoarseGrainingModelInfo_ak_1" UNIQUE(coarsegraining_model_id)
);
CREATE TABLE IF NOT EXISTS "TLSParametersInfo"(
  tlsparameters_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
  comments TEXT,
  CONSTRAINT "TLSParametersInfo_ak_1" UNIQUE(tlsparameters_id)
);
CREATE TABLE IF NOT EXISTS "EnsembleRefineInfo"(
  ensemble_refine_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
  comments TEXT,
  CONSTRAINT "EnsembleRefineInfo_ak_1" UNIQUE(ensemble_refine_id)
);
CREATE TABLE IF NOT EXISTS "CrystallographicInfo"(
  crystallographic_info_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
  serial_id INTEGER,
  neutron_id INTEGER,
  electron_id INTEGER,
  comments TEXT,
  CONSTRAINT "CrystallographicInfo_ak_1" UNIQUE(crystallographic_info_id)
);
CREATE TABLE IF NOT EXISTS "NMRInfo"(
  nmr_info_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
  q_factor REAL,
  rdc REAL,
  rdcobs REAL,
  rdcmodel REAL,
  peak_snr REAL,
  comments TEXT,
  CONSTRAINT "NMRInfo_ak_1" UNIQUE(nmr_info_id)
);
CREATE TABLE IF NOT EXISTS "ModelDataPair"(
  modeldatapair_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
  data_id INTEGER,
  model_id INTEGER,
  CONSTRAINT "DataInfo_Dataset"
    FOREIGN KEY (data_id) REFERENCES "Data" (data_id),
  CONSTRAINT "Model_Dataset" FOREIGN KEY (model_id) REFERENCES "Model" (model_id)
);
CREATE TABLE IF NOT EXISTS "Data"(
  data_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
  data_nmr_info_id INTEGER,
  data_crystallographic_info_id INTEGER,
  data_cryoem_info_id INTEGER,
  comments TEXT,
  CONSTRAINT "CryoEMDataInfo_DataInfo"
    FOREIGN KEY (data_cryoem_info_id)
      REFERENCES "DataCryoEMInfo" (data_cryoem_info_id) ON DELETE No action
      ON UPDATE No action,
  CONSTRAINT "CrystallographicDataInfo_DataInfo"
    FOREIGN KEY (data_crystallographic_info_id)
      REFERENCES "DataCrystallographicInfo" (data_crystallographic_info_id)
      ON DELETE No action ON UPDATE No action,
  CONSTRAINT "NMRDataInfo_DataInfo"
    FOREIGN KEY (data_nmr_info_id) REFERENCES "DataNMRInfo" (data_nmr_info_id)
      ON DELETE No action ON UPDATE No action,
      CHECK ((data_nmr_info_id is NULL AND data_crystallographic_info_id is NULL) OR 
             (data_crystallographic_info_id is NULL AND data_cryoem_info_id is NULL) OR 
             (data_nmr_info_id is NULL AND data_cryoem_info_id is NULL))
);
CREATE TABLE IF NOT EXISTS "DataNMRInfo"(
  data_nmr_info_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
  comments TEXT,
  nmrqualitydata_id INTEGER NOT NULL,
  CONSTRAINT "NMRDataInfo_ak_1" UNIQUE(data_nmr_info_id),
  CONSTRAINT "NMRQualityData_DataNMRInfo"
    FOREIGN KEY ("nmrqualitydata_id")
      REFERENCES "NMRQualityData" (nmrqualitydata_id)
);
CREATE TABLE IF NOT EXISTS "DataCrystallographicInfo"(
  data_crystallographic_info_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
  crystalqualitydata_id INTEGER,
  reflections_no INTEGER,
  wavelength REAL,
  file_name TEXT,
  comments TEXT,
  CONSTRAINT "CrystallographicDataInfo_ak_1" UNIQUE(data_crystallographic_info_id),
  CONSTRAINT "QualityData_DataCrystallographicInfo"
    FOREIGN KEY (crystalqualitydata_id)
      REFERENCES "CrystalQualityData" (crystalqualitydata_id)
);
CREATE TABLE IF NOT EXISTS "CrystalQualityData"(
  crystalqualitydata_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
  CChalf_average REAL,
  CCstar REAL,
  Rsplit REAL,
  SNR REAL,
  "CChalf_per_bin" INTEGER
);
CREATE TABLE IF NOT EXISTS "DataCryoEMInfo"(
  data_cryoem_info_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
  cryoemqualitydata_id INTEGER,
  comments TEXT,
  CONSTRAINT "CryoEMDataInfo_ak_1" UNIQUE(data_cryoem_info_id),
  CONSTRAINT "CryoemQualityData_DataCryoEMInfo"
    FOREIGN KEY (cryoemqualitydata_id)
      REFERENCES "CryoemQualityData" (cryoemqualitydata_id)
);
CREATE TABLE IF NOT EXISTS "Collection"(
  Collection_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, 
  fixed TEXT
  );
CREATE TABLE IF NOT EXISTS "CollectionHasDataset"(
  collectionhasdataset_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
  modeldatapair_id INTEGER NOT NULL,
  collection_id INTEGER NOT NULL,
  CONSTRAINT "Dataset_CollectionHadDataset"
    FOREIGN KEY ("modeldatapair_id") REFERENCES "ModelDataPair" (modeldatapair_id)
  CONSTRAINT "Collection_CollectionHadDataset"
    FOREIGN KEY ("Collection_id") REFERENCES "Collection" (collection_id)
);
CREATE TABLE IF NOT EXISTS "RfactorsInfo"(
  rfactors_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
  modeldatapair_id INTEGER NOT NULL,
  Rfree REAL,
  Rwork REAL,
  Rmethod VARCHAR,
  CONSTRAINT "Dataset_RfactorsInfo"
    FOREIGN KEY (modeldatapair_id) REFERENCES "ModelDataPair" (modeldatapair_id)
);
CREATE TABLE IF NOT EXISTS "NMRQualityData"
  (nmrqualitydata_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL);
CREATE TABLE IF NOT EXISTS "Crystal"(
  crystal_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
  data_crystallographic_info_id INTEGER NOT NULL,
  spacegroup TEXT,
  cell_a REAL,
  cell_b REAL,
  cell_c REAL,
  cell_alpha REAL,
  cell_beta REAL,
  cell_gamma REAL,
  comments TEXT,
  CONSTRAINT "DataCrystallographicInfo_Crystal"
    FOREIGN KEY (data_crystallographic_info_id)
      REFERENCES "DataCrystallographicInfo" (data_crystallographic_info_id)
);
CREATE TABLE IF NOT EXISTS "CryoEMQualityData"(
  cryoemqualitydata_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
  SNR REAL,
  FSC REAL,
  SSNR REAL,
  FNR REAL,
  max_local_resolution REAL,
  min_local_resolution REAL
);
CREATE TABLE IF NOT EXISTS "ReflectionsData"(
  reflectionsdata_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
  data_crystallographic_info_id INTEGER NOT NULL,
  wavelength REAL,
  reflection_no REAL,
  high_cell_resolution REAL,
  low_cell_resolution REAL,
  total_cell_resolution REAL,
  method_resolution REAL,
  CONSTRAINT "DataCrystallographicInfo_ReflectionsData"
    FOREIGN KEY (data_crystallographic_info_id)
      REFERENCES "DataCrystallographicInfo" (data_crystallographic_info_id)
);
CREATE TABLE CryoEMInfo(cryoem_info_id INTEGER PRIMARY KEY, dos REAL, rmsd REAL, native_overlap REAL, comments TEXT);

CREATE TABLE "AtomicModelInfo"(
  atomic_model_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
  tlsparameters_id INTEGER,
  pdb_code VARCHAR,
  haspdb BOOLEAN,
  pdbfilename VARCHAR,
  pdbfilepath VARCHAR,
  comments TEXT,
  CONSTRAINT "AtomicModelInfo_ak_1" UNIQUE(atomic_model_id),
  CONSTRAINT "TLSParametersInfo_AtomicModelInfo"
    FOREIGN KEY (tlsparameters_id) REFERENCES "TLSParametersInfo" (tlsparameters_id)
      ON DELETE No action ON UPDATE No action
);

CREATE TABLE "BondBasedModelInfo"(
bondbased_model_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, comments TEXT,
  CONSTRAINT "BondBasedModelInfo_ak_1" UNIQUE(bondbased_model_id)
);

CREATE TABLE "CoarseGrainingModelInfo"(
coarsegraining_model_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
  comments TEXT,
  CONSTRAINT "CoarseGrainingModelInfo_ak_1" UNIQUE(coarsegraining_model_id)
);

CREATE TABLE "Collection"
  (collection_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, fixed TEXT);

CREATE TABLE "CollectionHasDataset"(
  collectionhasdataset_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
  modeldatapair_id INTEGER NOT NULL,
  collection_id INTEGER NOT NULL,
  CONSTRAINT "Collection_CollectionHasDataset"
    FOREIGN KEY (collection_id) REFERENCES "Collection" (collection_id)
      ON DELETE No action ON UPDATE No action,
  CONSTRAINT "ModelDataPair_CollectionHasDataset"
    FOREIGN KEY (modeldatapair_id) REFERENCES "ModelDataPair" (modeldatapair_id)
      ON DELETE No action ON UPDATE No action
);

CREATE TABLE "CryoEMInfo"(
  cryoem_info_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
  dos REAL,
  rmsd REAL,
  native_overlap REAL,
  comments TEXT,
  CONSTRAINT "CryoEMInfo_ak_1" UNIQUE(cryoem_info_id)
);

CREATE TABLE "CryoEMQualityData"(
  cryoemqualitydata_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
  snr REAL,
  fsc REAL,
  ssnr REAL,
  fnr REAL,
  max_local_resolution REAL,
  min_local_resolution REAL
);


CREATE TABLE "Crystal"(
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
      ON DELETE No action ON UPDATE No action
);


CREATE TABLE "CrystalQualityData"(
  crystalqualitydata_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
  cchalf_average REAL,
  ccstar REAL,
  rsplit REAL,
  snr REAL,
  "CChalf_per_bin" INTEGER
);

CREATE TABLE "CrystallographicInfo"(
  crystallographic_info_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
  serial_id INTEGER,
  neutron_id INTEGER,
  electron_id INTEGER,
  comments TEXT,
  CONSTRAINT "CrystallographicInfo_ak_1" UNIQUE(crystallographic_info_id)
);

CREATE TABLE "Data"(
  data_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
  data_nmr_info_id INTEGER,
  data_crystallographic_info_id INTEGER,
  data_cryoem_info_id INTEGER,
  comments TEXT,
  CONSTRAINT "DataNMRInfo_Data"
    FOREIGN KEY (data_nmr_info_id) REFERENCES "DataNMRInfo" (data_nmr_info_id)
      ON DELETE No action ON UPDATE No action,
  CONSTRAINT "DataCrystallographicInfo_Data"
    FOREIGN KEY (data_crystallographic_info_id)
      REFERENCES "DataCrystallographicInfo" (data_crystallographic_info_id)
      ON DELETE No action ON UPDATE No action,
  CONSTRAINT "DataCryoEMInfo_Data"
    FOREIGN KEY (data_cryoem_info_id)
      REFERENCES "DataCryoEMInfo" (data_cryoem_info_id) ON DELETE No action
      ON UPDATE No action
);

CREATE TABLE "DataCryoEMInfo"(
  data_cryoem_info_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
  cryoemqualitydata_id INTEGER NOT NULL,
  comments TEXT,
  CONSTRAINT "CryoEMQualityData_DataCryoEMInfo"
    FOREIGN KEY (cryoemqualitydata_id)
      REFERENCES "CryoEMQualityData" (cryoemqualitydata_id)
);

CREATE TABLE "DataCrystallographicInfo"(
  data_crystallographic_info_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
  crystalqualitydata_id INTEGER,
  reflections_no INTEGER,
  wavelength REAL,
  file_name TEXT,
  comments TEXT,
  CONSTRAINT "CrystallographicDataInfo_ak_1" UNIQUE(data_crystallographic_info_id),
  CONSTRAINT "CrystalQualityData_DataCrystallographicInfo"
    FOREIGN KEY (crystalqualitydata_id)
      REFERENCES "CrystalQualityData" (crystalqualitydata_id) ON DELETE No action
      ON UPDATE No action
);

CREATE TABLE "DataNMRInfo"(
  data_nmr_info_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
  nmrqualitydata_id INTEGER NOT NULL,
  comments TEXT,
  CONSTRAINT "NMRQualityData_DataNMRInfo"
    FOREIGN KEY (nmrqualitydata_id) REFERENCES "NMRQualityData" (nmrqualitydata_id)
      ON DELETE No action ON UPDATE No action
);

CREATE TABLE "EnsembleRefineInfo"(
ensemble_refine_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, comments TEXT,
  CONSTRAINT "EnsembleRefineInfo_ak_1" UNIQUE(ensemble_refine_id)
);

CREATE TABLE "Model"(
  model_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
  representation_type_id INTEGER NOT NULL,
  structure_technique_id INTEGER NOT NULL,
  pdb_code TEXT,
  haspdb BOOLEAN,
  creation_time DATETIME,
  comments TEXT,
  CONSTRAINT "RepresentationType_Model"
    FOREIGN KEY (representation_type_id)
      REFERENCES "RepresentationType" (representation_type_id) ON DELETE No action
      ON UPDATE No action,
  CONSTRAINT "StructureTechniqueInfo_Model"
    FOREIGN KEY (structure_technique_id)
      REFERENCES "StructureTechniqueInfo" (structure_technique_id)
      ON DELETE No action ON UPDATE No action
);

CREATE TABLE "ModelDataPair"(
  modeldatapair_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
  data_id INTEGER,
  model_id INTEGER,
  CONSTRAINT "Model_ModelDataPair"
    FOREIGN KEY (model_id) REFERENCES "Model" (model_id) ON DELETE No action
      ON UPDATE No action,
  CONSTRAINT "Data_ModelDataPair"
    FOREIGN KEY (data_id) REFERENCES "Data" (data_id) ON DELETE No action
      ON UPDATE No action
);

CREATE TABLE "NMRInfo"(
  nmr_info_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
  q_factor REAL,
  rdc REAL,
  rdcobs REAL,
  rdcmodel REAL,
  peak_snr REAL,
  comments TEXT,
  CONSTRAINT "NMRInfo_ak_1" UNIQUE(nmr_info_id)
);

CREATE TABLE "NMRQualityData"
  (nmrqualitydata_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL);

CREATE TABLE "ReflectionsData"(
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
      ON DELETE No action ON UPDATE No action
);

CREATE TABLE "RepresentationType"(
  representation_type_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
  atomic_model_id INTEGER,
  bondbased_model_id INTEGER,
  coarsegraining_model_id INTEGER,
  ensemble_refine_id INTEGER,
  CONSTRAINT "RepresentationType_ak_1" UNIQUE(representation_type_id),
  CONSTRAINT "AtomicModelInfo_RepresentationType"
    FOREIGN KEY (atomic_model_id) REFERENCES "AtomicModelInfo" (atomic_model_id)
      ON DELETE No action ON UPDATE No action,
  CONSTRAINT "BondBasedModelInfo_RepresentationType"
    FOREIGN KEY (bondbased_model_id)
      REFERENCES "BondBasedModelInfo" (bondbased_model_id) ON DELETE No action
      ON UPDATE No action,
  CONSTRAINT "CoarseGrainingModelInfo_RepresentationType"
    FOREIGN KEY (coarsegraining_model_id)
      REFERENCES "CoarseGrainingModelInfo" (coarsegraining_model_id)
      ON DELETE No action ON UPDATE No action,
  CONSTRAINT "EnsembleRefineInfo_RepresentationType"
    FOREIGN KEY (ensemble_refine_id)
      REFERENCES "EnsembleRefineInfo" (ensemble_refine_id) ON DELETE No action
      ON UPDATE No action
);

CREATE TABLE "RfactorsInfo"(
  rfactors_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
  modeldatapair_id INTEGER NOT NULL,
  rfree REAL,
  rwork REAL,
  rmethod VARCHAR,
  CONSTRAINT "ModelDataPair_RfactorsInfo"
    FOREIGN KEY (modeldatapair_id) REFERENCES "ModelDataPair" (modeldatapair_id)
      ON DELETE No action ON UPDATE No action
);

CREATE TABLE "StructureTechniqueInfo"(
  structure_technique_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
  crystallographic_info_id INTEGER,
  nmr_info_id INTEGER,
  cryoem_info_id INTEGER,
  CONSTRAINT "StructureTechniqueInfo_ak_1" UNIQUE(structure_technique_id),
  CONSTRAINT "NMRInfo_StructureTechniqueInfo"
    FOREIGN KEY (nmr_info_id) REFERENCES "NMRInfo" (nmr_info_id) ON DELETE No action
      ON UPDATE No action,
  CONSTRAINT "CrystallographicInfo_StructureTechniqueInfo"
    FOREIGN KEY (crystallographic_info_id)
      REFERENCES "CrystallographicInfo" (crystallographic_info_id)
      ON DELETE No action ON UPDATE No action,
  CONSTRAINT "CryoEMInfo_StructureTechniqueInfo"
    FOREIGN KEY (cryoem_info_id) REFERENCES "CryoEMInfo" (cryoem_info_id)
      ON DELETE No action ON UPDATE No action
);

CREATE TABLE "TLSParametersInfo"(
tlsparameters_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, comments TEXT,
  CONSTRAINT "TLSParametersInfo_ak_1" UNIQUE(tlsparameters_id)
);

CREATE TABLE "VersionHistory"(
"version_Id" INTEGER NOT NULL, "VersionNumber" INTEGER,
  PRIMARY KEY("version_Id")
);

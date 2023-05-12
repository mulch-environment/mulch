
CREATE TABLE "Model"(
  model_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
  representation_type_id INTEGER NOT NULL,
  structure_technique_id INTEGER NOT NULL,
  pdb_code VARCHAR,
  haspdb BOOLEAN,
  comments VARCHAR,
  creationtime DATETIME,
  CONSTRAINT "StructureTechniqueInfo_Model"
    FOREIGN KEY (structure_technique_id)
      REFERENCES "StructureTechniqueInfo" (structure_technique_id)
      ON DELETE No action ON UPDATE No action,
  CONSTRAINT "RepresentationType_Model"
    FOREIGN KEY (representation_type_id)
      REFERENCES "RepresentationType" (representation_type_id) ON DELETE No action
      ON UPDATE No action
);

CREATE TABLE "RepresentationType"(
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
                  CHECK ((bondbased_model_ID is NULL AND coarsegraining_model_ID is NULL 
               AND ensemble_refine_ID is NULL) OR 
                  (atomic_model_ID is NULL AND coarsegraining_model_ID is NULL 
               AND ensemble_refine_ID is NULL) OR
                   (atomic_model_ID is NULL AND bondbased_model_ID is NULL 
               AND ensemble_refine_ID is NULL) OR 
                   (atomic_model_ID is NULL AND bondbased_model_ID is NULL 
               AND coarsegraining_model_ID is NULL)
                   )
);

CREATE TABLE "StructureTechniqueInfo"(
  structure_technique_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
  crystallographic_info_id INTEGER,
  nmr_info_id INTEGER,
  cryoem_info_id INTEGER,
  CONSTRAINT "StructureTechniqueInfo_ak_1" UNIQUE(structure_technique_id),
  CONSTRAINT "CryoEMInfo_StructureTechniqueInfo"
    FOREIGN KEY (cryoem_info_id) REFERENCES "CryoEMInfo" (cryoem_info_id)
      ON DELETE No action ON UPDATE No action,
  CONSTRAINT "CrystalographicInfo_StructureTechniqueInfo"
    FOREIGN KEY (crystallographic_info_id)
      REFERENCES "CrystallographicInfo" (crystallographic_info_id)
      ON DELETE No action ON UPDATE No action,
  CONSTRAINT "NMRInfo_StructureTechniqueInfo"
    FOREIGN KEY (nmr_info_id) REFERENCES "NMRInfo" (nmr_info_id) ON DELETE No action
      ON UPDATE No action
);

--------------------------------------
CREATE TABLE "AtomicModelInfo"(
  atomic_model_id INTEGER NOT NULL,
  tlsparameters_id INTEGER,
  pdb_code BLOB,
  "hasPDB" BLOB,
  comments VARCHAR,
  "pdbFIlesName" BLOB,
  "pdbFilePath" BLOB,
  PRIMARY KEY(atomic_model_id),
  CONSTRAINT "AtomicModelInfo_ak_1" UNIQUE(atomic_model_id),
  CONSTRAINT "TLSParametersInfo_AtomicModelInfo"
    FOREIGN KEY (tlsparameters_id) REFERENCES "TLSParametersInfo" (tlsparameters_id)
      ON DELETE No action ON UPDATE No action
);


CREATE TABLE "BondBasedModelInfo"(
  bondbased_model_id INTEGER NOT NULL,
  comments VARCHAR,
  PRIMARY KEY(bondbased_model_id),
  CONSTRAINT "BondBasedModelInfo_ak_1" UNIQUE(bondbased_model_id)
);

CREATE TABLE "CoarseGrainingModelInfo"(
  coarsegraining_model_id INTEGER NOT NULL,
  comments VARCHAR,
  PRIMARY KEY(coarsegraining_model_id),
  CONSTRAINT "CoarseGrainingModelInfo_ak_1" UNIQUE(coarsegraining_model_id)
);

CREATE TABLE "TLSParametersInfo"(
  tlsparameters_id INTEGER NOT NULL,
  comments VARCHAR,
  PRIMARY KEY(tlsparameters_id),
  CONSTRAINT "TLSParametersInfo_ak_1" UNIQUE(tlsparameters_id)
);

CREATE TABLE "EnsembleRefineInfo"(
  ensemble_refine_id INTEGER NOT NULL,
  comments VARCHAR,
  PRIMARY KEY(ensemble_refine_id),
  CONSTRAINT "EnsembleRefineInfo_ak_1" UNIQUE(ensemble_refine_id)
);

--------------------------------------
CREATE TABLE "CrystallographicInfo"(
  crystallographic_info_id INTEGER NOT NULL,
  serial_id INTEGER,
  neutron_id INTEGER,
  electron_id INTEGER,
  comments VARCHAR,
  PRIMARY KEY(crystallographic_info_id),
  CONSTRAINT "CrystalographicInfo_ak_1" UNIQUE(crystallographic_info_id)
);

CREATE TABLE "NMRInfo"(
  nmr_info_id INTEGER NOT NULL,
  q_factor REAL,
  rdc REAL,
  rdcobs REAL,
  rdcmodel REAL,
  peak_snr REAL,
  comments VARCHAR,
  PRIMARY KEY(nmr_info_id),
  CONSTRAINT "NMRInfo_ak_1" UNIQUE(nmr_info_id)
);

CREATE TABLE "CryoEMInfo"(
  cryoem_info_id INTEGER NOT NULL,
  dos REAL,
  rmsd REAL,
  native_ovelap REAL,
  comments VARCHAR,
  PRIMARY KEY(cryoem_info_id),
  CONSTRAINT "CryoEMInfo_ak_1" UNIQUE(cryoem_info_id)
);


CREATE TABLE "ModelDataPair"(
  modeldatapair_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
  data_id INTEGER,
  model_id INTEGER,
  CONSTRAINT "DataInfo_Dataset"
    FOREIGN KEY (data_id) REFERENCES "Data" (data_id),
  CONSTRAINT "Model_Dataset" FOREIGN KEY (model_id) REFERENCES "Model" (model_id)
);

CREATE TABLE "Data"(
  data_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
  data_nmr_info_id INTEGER,
  data_crystallographic_info_id INTEGER,
  data_cryoem_info_id INTEGER,
  CONSTRAINT "CryoEMDataInfo_DataInfo"
    FOREIGN KEY (data_cryoem_info_id)
      REFERENCES "DataCryoEMInfo" (data_cryoem_info_id) ON DELETE No action
      ON UPDATE No action,
  CONSTRAINT "CrystallographicDataInfo_DataInfo"
    FOREIGN KEY (data_crystallographic_info_id)
      REFERENCES "DataCrystallographicInfo" (data_crystallographic_info_id)
      ON DELETE No action ON UPDATE No action,
  CONSTRAINT "NMRDataInfo_DataInfo"
    FOREIGN KEY (nmr_data_info_id) REFERENCES "DataNMRInfo" (data_nmr_info_id)
      ON DELETE No action ON UPDATE No action
);

CREATE TABLE "DataNMRInfo"(
  data_nmr_info_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
  comments VARCHAR,
  "nmrqualitydata_id" INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
  CONSTRAINT "NMRDataInfo_ak_1" UNIQUE(data_nmr_info_id),
  CONSTRAINT "NMRQualityData_DataNMRInfo"
    FOREIGN KEY ("nmrqualitydata_id")
      REFERENCES "NMRQualityData" (nmrqualitydata_id)
);


CREATE TABLE "DataCrystallographicInfo"(
  data_crystallographic_info_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
  crystalqualitydata_id INTEGER PRIMARY KEY AUTOINCREMENT,
  reflections_no INTEGER,
  wavelength REAL,
  comments VARCHAR,
  CONSTRAINT "CrystallographicDataInfo_ak_1" UNIQUE(data_crystallographic_info_id),
  CONSTRAINT "QualityData_DataCrystallographicInfo"
    FOREIGN KEY (crystalqualitydata_id)
      REFERENCES "CrystalQualityData" (crystalqualitydata_id)
);

CREATE TABLE "DataCryoEMInfo"(
  data_cryoem_info_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
  cryoemqualitydata_id INTEGER PRIMARY KEY AUTOINCREMENT,
  comments VARCHAR,
  CONSTRAINT "CryoEMDataInfo_ak_1" UNIQUE(data_cryoem_info_id),
  CONSTRAINT "CryoemQualityData_DataCryoEMInfo"
    FOREIGN KEY (cryoemqualitydata_id)
      REFERENCES "CryoemQualityData" (cryoemqualitydata_id)
);

CREATE TABLE "Group"
  (group_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, fixed BLOB);

CREATE TABLE "GroupHasDataset"(
  grouphasdataset_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
  modeldatapair_id INTEGER NOT NULL,
  group_id INTEGER NOT NULL,
  CONSTRAINT "Dataset_GroupHadDataset"
    FOREIGN KEY ("modeldatapair_id") REFERENCES "ModelDataPair" (modeldatapair_id),
  CONSTRAINT "Group_GroupHadDataset"
    FOREIGN KEY (group_id) REFERENCES "Group" (group_id)
);



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






CREATE TABLE Model (
   model_ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
   representation_type_ID INTEGER NOT NULL,
   structure_technique_ID INTEGER NOT NULL,
   refinment_method VARCHAR(512),
   comments VARCHAR(512),
   creationTime DATETIME,
   FOREIGN KEY (representation_type_ID) REFERENCES RepresentationType(representation_type_ID),
   FOREIGN KEY (structure_technique_ID) REFERENCES StructureTechniqueInfo(structure_technique_ID)
   );

CREATE TABLE RepresentationType(
   representation_type_ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
   atomic_model_ID INTEGER,
   bondbased_model_ID INTEGER,
   coarsegraining_model_ID INTEGER,
   ensemble_refine_ID INTEGER,
   FOREIGN KEY (atomic_model_ID) REFERENCES AtomicModelInfo(atomic_model_ID),
   FOREIGN KEY (bondBased_model_ID) REFERENCES BondBasedModelInfo(bondbased_model_ID),
   FOREIGN KEY (coarseGraining_model_ID) REFERENCES CoarseGrainingModelInfo(coarsegraining_model_ID),
   FOREIGN KEY (ensemble_refine_ID) REFERENCES EnsembleRefineInfo(ensemble_refine_ID)
   );


CREATE TABLE StructureTechniqueInfo(
   structure_technique_ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
   nmr_info_ID INTEGER,
   Crystallographic_info_ID INTEGER,
   CryoEM_info_ID INTEGER,
   FOREIGN KEY (nmr_info_ID) REFERENCES NMRInfo(nmr_info_ID),
   FOREIGN KEY (crystallographic_info_ID) REFERENCES CrystallographicInfo(crystallographic_info_ID),
   FOREIGN KEY (cryoEM_info_ID) REFERENCES CryoEMInfo(cryoEM_info_ID)
   );

--------------------------------------
CREATE TABLE AtomicModelInfo(
   atomic_model_ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
   tlsparameters_ID INTEGER,
   pdb_code VARCHAR,
   hasPDB BOOLEAN,
   pdbFileName VARCHAR(255), 
   comments VARCHAR(512),
   pdbFilePath VARCHAR(1024),
   FOREIGN KEY (tlsparameters_ID) REFERENCES TLSParametersInfo(tlsparameters_ID)
   );

CREATE TABLE BondBasedModelInfo(
   bondbased_model_ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
   comments VARCHAR(512)
   );

CREATE TABLE CoarseGrainingModelInfo(
   coarsegraining_model_ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
   comments VARCHAR(512)
   );

CREATE TABLE TLSParametersInfo(
   tlsparameters_ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
   comments VARCHAR(512)
   );

CREATE TABLE EnsembleRefineInfo(
   ensemble_refine_ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
   comments VARCHAR(512)
   );

--------------------------------------
CREATE TABLE CrystallographicInfo(
   crystallographic_info_ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
   serial_id INTEGER,
   neutron_id INTEGER,
   electron_id INTEGER,
   comments VARCHAR(512)
   -- FOREIGN KEY (rfactors_ID) REFERENCES RfactorsInfo(rfactors_ID)
   );

CREATE TABLE RfactorsInfo(
   rfactors_ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
   dataset_id INTEGER,
   -- crystallographic_info_ID INTEGER,
   Rfree REAL, 
   Rwork REAL,
   Rmethod VARCHAR(512),
   -- FOREIGN KEY (crystallographic_info_ID) REFERENCES CrystallographicInfo(crystallographic_info_ID),
   FOREIGN KEY (dataset_id) REFERENCES Dataset(dataset_ID)
   );


CREATE TABLE NMRInfo(
   nmr_info_ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
   Q_factor REAL,
   RDC REAL,
   RDCobs REAL, 
   RDCmodel REAL,
   peak_SNR REAL,
   comments VARCHAR(512)
   );

CREATE TABLE CryoEMInfo(
   cryoEM_info_ID INTEGER PRIMARY KEY,
   DOS REAL,
   RMSD REAL, 
   Native_ovelap REAL,
   comments VARCHAR(512)
   );

-- CREATE TABLE "DataCryoEMInfo"(
-- data_cryoem_info_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, 
-- comments VARCHAR
-- );

-- CREATE TABLE Crystal(
--   crystal_ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
--   data_crystallographic_info_id INTEGER,
--   spacegroup VARCHAR,
--   cell_a REAL,
--   cell_b REAL,
--   cell_c REAL,
--   cell_alpha REAL,
--   cell_beta REAL,
--   cell_gamma REAL,
--   resolution REAL,
--   comments VARCHAR,
--     FOREIGN KEY (data_crystallographic_info_id)
--       REFERENCES DataCrystallographicInfo (data_crystallographic_info_id)
-- );

-- CREATE TABLE DataCrystallographicInfo(
--   data_crystallographic_info_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
--   reflections_no INTEGER,
--   wavelength REAL,
--   comments VARCHAR
-- );

-- CREATE TABLE DataInfo(
--   datainfo_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
--   nmr_data_info_id INTEGER,
--   crystallographic_data_info_id INTEGER,
--   cryoem_data_info_id INTEGER,
--     FOREIGN KEY (cryoem_data_info_id)
--       REFERENCES DataCryoEMInfo(data_cryoem_info_id) ON DELETE No action,
--     FOREIGN KEY (crystallographic_data_info_id)
--       REFERENCES DataCrystallographicInfo(data_crystallographic_info_id),
--     FOREIGN KEY (nmr_data_info_id) REFERENCES DataNMRInfodata_nmr_info_id)
-- );


-- CREATE TABLE "DataNMRInfo"(
--    data_nmr_info_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, 
--    comments VARCHAR
-- );


-- CREATE TABLE Resolution(
--   resolution_ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
--   res_cutoff_stats_id INTEGER,
--   crystal_crystal_ID INTEGER,
--   data_cryoem_info_id INTEGER,
--   data_nmr_info_id INTEGER,
--   dataset_id INTEGER,
--   crystal_res REAL,
--   crystal_res_method REAL,
--   cryoem_res_method REAL,
--   nmr_res_method REAL,
--   cryoem_local_res REAL,
--     FOREIGN KEY ("crystal_crystal_ID") REFERENCES "Crystal" ("crystal_ID"),
--     FOREIGN KEY (data_nmr_info_id) REFERENCES "DataNMRInfo" (data_nmr_info_id),
--     FOREIGN KEY (data_cryoem_info_id) REFERENCES "DataCryoEMInfo" (data_cryoem_info_id),
--     FOREIGN KEY (dataset_id) REFERENCES "Dataset" (dataset_id),
--     FOREIGN KEY (res_cutoff_stats_id) REFERENCES "ResolutionCutoffStats" (res_cutoff_stats_id)
-- );

-- CREATE TABLE "Dataset"(
--   dataset_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
--   datainfo_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
--   model_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
--     FOREIGN KEY (datainfo_id) REFERENCES "DataInfo" (datainfo_id)
-- );

-- CREATE TABLE "ResolutionCutoffStats"(
--   res_cutoff_stats_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
--   "CChalf" REAL,
--   "CCstar" REAL,
--   "Rsplit" REAL,
--   "SNR" REAL,
--   "FSC" REAL,
--   "SSNR" REAL,
--   "FNR" REAL,
--   "Local_resolution" REAL
-- );

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


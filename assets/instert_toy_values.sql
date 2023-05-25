INSERT INTO RepresentationType (representation_type_id, atomic_model_id, 
	bondbased_model_id, coarsegraining_model_id, ensemble_refine_id)
VALUES 
	(1, 1,    1,    NULL, NULL),
	(2, NULL, NULL, NULL, 1   ),
	(3, 2,    2,    NULL, NULL),
	(4, NULL, NULL, 1,    NULL),
	(5, 3,    3,    NULL, NULL),
	(6, 4,    4,    NULL, NULL),
	(7, 5,    6,    NULL, NULL);


INSERT INTO BondBasedModelInfo (bondbased_model_id, comments)
VALUES
	(1, "Rope1"),
	(2, "Rope2"),
	(3, "Rope3"),
	(4, "Rope4"),
	(5, "Rope5");


INSERT INTO Model (model_id, representation_type_id, structure_technique_id, pdb_code, hasPDB, comments) 
VALUES
	(1, 1, 1, "YPB4", TRUE,  "blah1"),
	(2, 2, 2, NULL,   FALSE, "blah2"),
	(3, 3, 3, "PH2r", TRUE,  "blah3"),
	(4, 4, 4, "K8iD", TRUE,  "blah4"),
	(5, 5, 5, "IPLB", TRUE,  "blah5"),
	(6, 6, 6, NULL,   FALSE, "blah6"),
	(7, 7, 7, NULL,   FALSE, "blah7");

INSERT INTO Collection (collection_id)
VALUES
	(1),
	(2),
	(3),
	(4),
	(5),
	(6),
	(7),
	(8),
	(9),
	(10);

INSERT INTO CollectionHasDataset (collectionHasDataset_id, collection_id, modeldatapair_id)
VALUES
	(1, 1, 1),
	(2, 2, 2),
	(3, 3, 3),
	(4, 4, 4),
	(5, 5, 5),
	(6, 3, 6),
	(7, 4, 7),
	(8, 5, 8),
	(9, 6, 10),
	(10, 7, 9);



INSERT INTO ModelDataPair (modeldatapair_id, data_id, model_id)
VALUES
	(1, 1, 1),
	(2, 2, 2),
	(3, NULL, 3),
	(4, NULL, NULL),
	(5, NULL, 4),
	(6, 3, 5),
	(7, 4, 6),
	(8, 5, NULL),
	(9, 6, 7),
	(10, 7, NULL);

INSERT INTO StructureTechniqueInfo (structure_technique_id, nmr_info_id, cryoem_info_id)
VALUES
	(1, 1, NULL),
	(2, 2, NULL),
	(3, NULL, NULL),
	(4, NULL, NULL),
	(5, NULL, 1),
	(6, NULL, 2),
	(7, NULL, 3),
	(8, 3, NULL);


INSERT INTO CrystallographicInfo (crystallographic_info_id, serial_id, neutron_id, electron_id)
VALUES
	(1, 1, NULL, 1),
	(2, 2, NULL, 2),
	(3, NULL, NULL, NULL),
	(4, NULL, NULL, 3),
	(5, NULL, 1,4),
	(6, NULL, 2, NULL),
	(7, NULL, 3, 5),
	(8, 3, NULL, 6);


INSERT INTO AtomicModelInfo (atomic_model_id, tlsparameters_id, pdb_code, haspdb)
VALUES
	(1, 1, "abc", TRUE),
	(2, 2, "dfg", TRUE),
	(3, 3, NULL,  FALSE), 
	(4, 4, "lmn", TRUE),
	(5, 5, "opq", TRUE);



INSERT INTO TLSParametersInfo (tlsparameters_id, comments)
VALUES
	(1, "some comment"),
	(2, "some other comments"),
	(3, NULL), 
	(4, "another one"),
	(5, NULL);


INSERT INTO Data (data_id, data_nmr_info_id, data_crystallographic_info_id, data_cryoem_info_id, comments) 
VALUES
	(1, 1,    NULL, NULL,  "comment_1"),
	(2, 2,    NULL, NULL,  "comment_2"),
	(3, NULL, 1,    NULL,  "comment_3"),
	(4, NULL, NULL, 1,     NULL),
	(5, 3,    NULL, NULL,  "comment_4"),
	(6, 4,    NULL, NULL,  "comment_5"),
	(7, NULL, NULL, 2,     NULL);


-- INSERT INTO datanmrinfo (data_nmr_info_id, comments, nmrqualitydata_id) 
-- VALUES
-- 	(1, 1,    "comment_1"),
-- 	(2, 2,    "comment_2"),
-- 	(3, NULL, "comment_3"),
-- 	(4, NULL, NULL),
-- 	(5, 3,    "comment_4"),
-- 	(6, 4,    "comment_5"),
-- 	(7, NULL, NULL);


INSERT INTO dataCrystallographicinfo (data_crystallographic_info_id, crystalqualitydata_id, reflections_no) 
VALUES
	(1, 1, 10000)
;

INSERT INTO crystalqualitydata (crystalqualitydata_id, SNR) 
VALUES
	(1, 8.0)
;

INSERT INTO CryoEMInfo (cryoem_info_id) 
VALUES
	(1)
;

INSERT INTO CryoEMInfo (cryoem_info_id) 
VALUES
	(2)
;

INSERT INTO CryoEMInfo (cryoem_info_id) 
VALUES
	(3)
;

INSERT INTO CoarseGrainingModelInfo (coarsegraining_model_id) 
VALUES
	(1)
;

INSERT INTO DataNMRInfo (data_nmr_info_id, nmrqualitydata_id) 
VALUES 
	(3,3)
;

INSERT INTO NMRInfo (nmr_info_id) 
VALUES 
	(3)
;

INSERT INTO EnsembleRefineInfo (ensemble_refine_id) 
VALUES 
	(1)
;

INSERT INTO EnsembleRefineInfo (ensemble_refine_id) 
VALUES 
	(2)
;

INSERT INTO RepresentationType (representation_type_id, atomic_model_id, 
        bondbased_model_id, coarsegraining_model_id, ensemble_refine_id)
VALUES 
        (8, NULL,    NULL,    2, NULL)
        ;

INSERT INTO Model (model_id, representation_type_id, structure_technique_id, pdb_code, haspdb, comments)
VALUES 
	(8, 8, 8, 'ABC123', 1, 'Example comment');

 INSERT INTO DataNMRInfo (data_nmr_info_id, nmrqualitydata_id) 
 VALUES 
 	(4,2);

INSERT INTO StructureTechniqueInfo  (nmr_info_id) 
VALUES
	(1);

INSERT INTO DataNMRInfo (data_nmr_info_id, nmrqualitydata_id) 
VALUES 
	(4,2);

INSERT INTO DataNMRInfo (data_nmr_info_id, nmrqualitydata_id) 
VALUES 
	(1,1);


















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
	(1, 1, NULL),
	(2, 2, NULL),
	(3, NULL, NULL),
	(4, NULL, NULL),
	(5, NULL, 1),
	(6, NULL, 2),
	(7, NULL, 3),
	(8, 3, NULL);


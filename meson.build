project('mulch', 'cpp', 'c')


headers = [
    'src/Collection.h',
    'src/Model.h',
    'src/Data.h'
]

install_headers(headers, subdir: 'mulch')
install_data('meson.build', install_dir : '/usr/local')


files = [
    'src/Database.h',
    'src/Object.h',
    'src/PModel.h',
    'src/Utility.h',
    'src/MulchExceptions.h',
    'src/RepresentationType.h',
    'src/StructureTechniqueInfo.h',
    'src/AtomicModelInfo.h',
    'src/BondBasedModelInfo.h',
    'src/CoarseGrainingModelInfo.h',
    'src/EnsembleRefineInfo.h',
    'src/TLSParametersInfo.h',
    'src/CrystallographicInfo.h',
    'src/NMRInfo.h',
    'src/CryoEMInfo.h',
    'src/CollectionHasDataset.h',
    'src/PModelDataPair.h',
    'src/ModelDataPair.h',
    'src/PData.h',
    'src/DataNMRInfo.h',
    'src/DataCrystallographicInfo.h',
    'src/DataCryoEMInfo.h',
    'src/PCollection.h',
    'src/RfactorsInfo.h',
    'src/NMRQualityData.h',
    'src/CrystalQualityData.h',
    'src/Crystal.h',
    'src/CryoEMQualityData.h',
    'src/ReflectionsData.h',
    'src/EnumTables.h',
    'src/Database.cpp',
    'src/Object.cpp',
    'src/PModel.cpp',
    'src/Utility.cpp',
    'src/MulchExceptions.cpp',
    'src/RepresentationType.cpp',
    'src/StructureTechniqueInfo.cpp',
    'src/AtomicModelInfo.cpp',
    'src/BondBasedModelInfo.cpp',
    'src/CoarseGrainingModelInfo.cpp',
    'src/EnsembleRefineInfo.cpp',
    'src/TLSParametersInfo.cpp',
    'src/CrystallographicInfo.cpp',
    'src/NMRInfo.cpp',
    'src/CryoEMInfo.cpp',
    'src/CollectionHasDataset.cpp',
    'src/PModelDataPair.cpp',
    'src/PData.cpp',
    'src/DataNMRInfo.cpp',
    'src/DataCrystallographicInfo.cpp',
    'src/DataCryoEMInfo.cpp',
    'src/Collection.cpp',
    'src/PCollection.cpp',
    'src/RfactorsInfo.cpp',
    'src/NMRQualityData.cpp',
    'src/CrystalQualityData.cpp',
    'src/Crystal.cpp',
    'src/CryoEMQualityData.cpp',
    'src/ReflectionsData.cpp', 
    'src/DebugLog.h',
    'src/DebugLog.cpp'
    ]

subdir('assets')

sqlite_dep = dependency('sqlite3')
mulch_lib = static_library('mulch',
    files,
    cpp_args: ['-std=c++11'],
    dependencies: [sqlite_dep],
    install: true
)


subdir('tests')



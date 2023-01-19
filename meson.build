project('mulch', 'cpp', 'c')
files = ['src/Database.cpp', 
		 'src/Database.h',
		 'src/Object.cpp', 
		 'src/Object.h',
		 'src/Model.h',
		 'src/Model.cpp',
		 'src/Utility.cpp', 
		 'src/Utility.h',
		 'src/MulchExceptions.cpp',
		 'src/MulchExceptions.h', 
		 'src/RepresentationType.h',
		 'src/RepresentationType.cpp',
		 'src/StructureTechniqueInfo.h',
		 'src/StructureTechniqueInfo.cpp'
		 ]

subdir('assets')

sqlite_dep = dependency('sqlite3')
mulch_lib = static_library('mulch',
	files, cpp_args: ['-std=c++11'], 
	dependencies: [sqlite_dep], 
	install : true)

subdir('tests')



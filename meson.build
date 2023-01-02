project('mulch', 'cpp', 'c')
files = ['src/Database.cpp', 
		 'src/Database.h'
		 ]

subdir('assets')

sqlite_dep = dependency('sqlite3')
mulch_lib = static_library('mulch',
	files, cpp_args: ['-std=c++11'], 
	dependencies: [sqlite_dep], 
	install : true)

subdir('tests')



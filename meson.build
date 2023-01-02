project('mulch', 'cpp', 'c')
files = ['src/Database.cpp', 
		 'src/Database.h'
		 ]

# installing data files
data_dir = get_option('datadir') / 'mulch'

install_data(
'assets/template.db',
install_dir : data_dir)

sqlite_dep = dependency('sqlite3')
mulch_lib = static_library('mulch',
	files, cpp_args: ['-std=c++11'], 
	dependencies: [sqlite_dep], 
	install : true)

subdir('tests')



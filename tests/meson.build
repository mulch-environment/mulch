boost_unit_test = dependency('boost', modules:['unit_test_framework'])
files = ['test_Database.cpp']

mulch_tests = executable('mulch_tests',
	files, 
	link_with: [mulch_lib],
	dependencies: [boost_unit_test],
	cpp_args: ['-std=c++11'], 
	include_directories:'../')


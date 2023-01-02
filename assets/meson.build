# installing data files
data_dir = get_option('datadir') / 'mulch'

install_data(
'template.db',
install_dir : data_dir)

conf = configuration_data()
conf.set_quoted('MULCH_DATA_DIRECTORY', get_option('prefix') / data_dir)
configure_file(
  output: 'config.h',
  configuration: conf
)


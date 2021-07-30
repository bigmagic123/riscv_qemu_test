project('virt_test', 'c')

sources = []
inc     = []

subdir( 'application' )
subdir( 'driver' )
subdir( 'src' )

# gd32vf103
#add_project_arguments('-march=rv32imafdcp' ,'-mabi=ilp32d', '-nostartfiles','-mcmodel=medany','-ffunction-sections', '-fdata-sections', '-fno-common', language: 'c')

#linker_script = join_paths(meson.current_source_dir(), 'link.ld')

#add_project_link_arguments('-T', linker_script , '-march=rv32imafdcp' ,'-nostartfiles','-mabi=ilp32d','-mcmodel=medany', language: 'c')


add_project_arguments('-march=rv64imafdcp' ,'-mabi=lp64d', '-nostartfiles','-mcmodel=medany','-ffunction-sections', '-fdata-sections', '-fno-common', language: 'c')

linker_script = join_paths(meson.current_source_dir(), 'link_64.ld')

add_project_link_arguments('-T', linker_script , '-march=rv64imafdcp' ,'-nostartfiles','-mabi=lp64d','-mcmodel=medany', language: 'c')


exe = executable('virt_test.elf', sources, include_directories:[inc])

hex = custom_target('demo.bin',
  build_by_default: true,
  input : exe,
  output : 'demo.bin',
  command : [meson.get_external_property('objcopy'), '-O', 'binary','@INPUT@','@OUTPUT@'],
)

dump = custom_target('demo.dump',
  capture          : true,
  build_by_default: true,
  input : exe,
  output : 'demo.dump',
  command : [meson.get_external_property('objdump'), '-D', '-S', '-t', '@INPUT@'],
)

project('example', 'c')

sources = []
inc     = []

subdir( 'test' )

exe = executable('example', sources, include_directories:[inc])

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
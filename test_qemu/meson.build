project('virt_test', 'c')

sources = []
inc     = []

subdir( 'application' )
subdir( 'driver' )
subdir( 'src' )

add_project_arguments('-march=rv64imafdc' ,'-mabi=lp64d','-fno-omit-frame-pointer', '-nostartfiles', '-MD', '-mcmodel=medany', '-ffreestanding', '-fno-common' ,'-nostdlib', '-mno-relax', language: 'c')

linker_script = join_paths(meson.current_source_dir(), 'link.ld')

add_project_link_arguments('-T', linker_script ,'-nostdlib', '-nostartfiles', language: 'c')

exe = executable('virt_test.elf', sources, include_directories:[inc])

hex = custom_target('demo.bin',
  build_by_default: true,
  input : exe,
  output : 'demo.bin',
  command : [meson.get_external_property('objcopy'), '-O', 'binary','@INPUT@','@OUTPUT@'],
)


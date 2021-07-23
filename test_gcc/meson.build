project('example', 'c')

sources = []
inc     = []

subdir( 'test' )
'''
riscv64-unknown-elf-gcc -print-multi-lib
rv32i/ilp32;@march=rv32i@mabi=ilp32
rv32ic/ilp32;@march=rv32ic@mabi=ilp32
rv32im/ilp32;@march=rv32im@mabi=ilp32
rv32imc/ilp32;@march=rv32imc@mabi=ilp32
rv32iac/ilp32;@march=rv32iac@mabi=ilp32
rv32imac/ilp32;@march=rv32imac@mabi=ilp32
rv32imafc/ilp32f;@march=rv32imafc@mabi=ilp32f
rv32imafdc/ilp32d;@march=rv32imafdc@mabi=ilp32d
rv32e/ilp32e;@march=rv32e@mabi=ilp32e
rv32ec/ilp32e;@march=rv32ec@mabi=ilp32e
rv32emc/ilp32e;@march=rv32emc@mabi=ilp32e
rv32ema/ilp32e;@march=rv32ema@mabi=ilp32e
rv32emac/ilp32e;@march=rv32emac@mabi=ilp32e
rv32eac/ilp32e;@march=rv32eac@mabi=ilp32e
rv64i/lp64;@march=rv64i@mabi=lp64
rv64im/lp64;@march=rv64im@mabi=lp64
rv64imc/lp64;@march=rv64imc@mabi=lp64
rv64imac/lp64;@march=rv64imac@mabi=lp64
rv64imafc/lp64f;@march=rv64imafc@mabi=lp64f
rv64imafdc/lp64d;@march=rv64imafdc@mabi=lp64d
'''
add_project_arguments('-march=rv64imafdc' ,'-mabi=lp64d', language: 'c')
add_project_link_arguments('-march=rv64imafdc' ,'-mabi=lp64d', language: 'c')

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
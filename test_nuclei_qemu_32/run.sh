#!/bin/bash
/home/zhaofujin/RISCV/linux_qemu_bak/bin/qemu-system-riscv32 -M nuclei_n,download=ilm -cpu nuclei-n307fdp -kernel virt_test.elf -nographic -d guest_errors

#/home/zhaofujin/RISCV/linux_qemu/bin/qemu-system-riscv64 -M nuclei_n,download=ilm -cpu nuclei-nx600fdp -nographic -d guest_errors -kernel virt_test.elf

#~/RISCV/spike/bin/spike --isa=rv64imafdcp virt_test.elf


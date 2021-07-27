#!/bin/bash
/home/zhaofujin/RISCV/linux_qemu/bin/qemu-system-riscv32 -M nuclei_n,download=ilm -cpu nuclei-n307fdp -kernel virt_test.elf -nographic -d guest_errors

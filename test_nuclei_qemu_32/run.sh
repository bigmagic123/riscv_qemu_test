#!/bin/bash
#/home/zhaofujin/RISCV/linux_qemu/bin/qemu-system-riscv64 -M virt -bios demo.bin -nographic -d guest_errors
/home/zhaofujin/linux_qemu/linux_qemu/bin/qemu-system-riscv32 -M gd32vf103_rvstar -bios demo.bin -nographic -d guest_errors
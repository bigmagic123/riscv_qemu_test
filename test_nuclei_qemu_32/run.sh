#!/bin/bash
/home/zhaofujin/RISCV/linux_qemu/bin/qemu-system-riscv32 -M gd32vf103v_rvstar -kernel virt_test.elf -nographic -d guest_errors
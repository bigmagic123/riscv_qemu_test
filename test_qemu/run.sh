#!/bin/bash
qemu-system-riscv64 -M virt -bios demo.bin -nographic
echo "退出状态："$?

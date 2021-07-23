#include <stdlib.h>
#include <stdio.h>
#include <riscv_dsp.h>

int main()
{
    int64_t a, b, c;
    //c = __rv__ursub64(a, b);
    c = __rv__dkhm8(a, b);
    printf("hello world!\n");
    return 0;
}

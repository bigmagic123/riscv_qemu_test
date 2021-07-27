#include <stdlib.h>
#include <stdio.h>
#include <riscv_dsp.h>

int main()
{
    int64_t a, b, c;
   // c = __rv__ursub64(a, b);
    c = __rv__dkhm8(a, b);
    c = __rv__dkhm16(a, b);

    c = __rv__dkabs8(a);
    c = __rv__dkabs16(a);
    //c = __rv__dkabs8(a);
    //c = __rv__dkabs16(a);
    c = __rv__kabs16(a);

    c = __rv__dkslra8(a, b);
    c = __rv__dkslra16(a, b);

    c = __rv__dkadd8(a, b);
    c = __rv__dkadd16(a, b);

    c = __rv__dksub8(a, b);
    c = __rv__dksub16(a, b);

    //c = __rv__expd80(a);
    //c = __rv__expd81(a);
    //c = __rv__expd82(a);
    //c = __rv__expd83(a);


    printf("hello world!\n");
    return 0;
}

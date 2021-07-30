#include <dsp.h>
#include <riscv_dsp.h>
#include <printf.h>

// #if __riscv_xlen == 32
// typedef int32_t  intXLEN_t;
// typedef uint32_t uintXLEN_t;
// #else
// typedef int64_t  intXLEN_t;
// typedef uint64_t uintXLEN_t;
// #endif

#if __riscv_xlen == 32
uintXLEN_t a = (1 << 0) | (2 << 8) | (3 << 16) | (4 << 24);
uintXLEN_t b = (4 << 0) | (3 << 8) | (2 << 16) | (1 << 24);
uintXLEN_t c = 0;

uint8x4_t  test_a = {1,2,3,4};
uint8x4_t  test_b = {4,3,2,1};
uint8x4_t  test_c;
#else


uintXLEN_t a   = 0x0807060504030201;
uintXLEN_t b   = 0x0102030405060708;
uintXLEN_t c = 0;

uint8x8_t  test_a = {1,2,3,4,5,6,7,8};
uint8x8_t  test_b = {8,7,6,5,4,3,2,1};
uint8x8_t  test_c;

#endif


static void test_add8(void)
{
#if __riscv_xlen == 32
    c = __rv__radd8(a, b);
    printf("c is %p\n", c);
    test_c = __rv__v_radd8(test_a, test_b);
    printf("%d,%d,%d,%d\n", test_c[0], test_c[1], test_c[2], test_c[3]);
#else
     c = __rv__add8(a, b);
      //c =  a + b;
    // printf("a is %p\n", a);
    // printf("b is %p\n", b);
    // printf("c is %p\n", c);
    test_c = __rv__v_uadd8(test_a, test_b);
    //test_c = test_a + test_b;
    printf("c is %p\n", c);
    printf("test_c is %p\n", test_c);
   // printf("%d,%d,%d,%d,%d,%d,%d,%d,%d\n", test_c[0], test_c[1], test_c[2], test_c[3],test_c[4], test_c[5], test_c[6], test_c[7]);
#endif
}

void test_dsp(void)
{
    test_add8();
}

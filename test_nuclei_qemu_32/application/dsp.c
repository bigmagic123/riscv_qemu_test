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

uint8x4_t  test_a32 = {1,2,3,4};
uint8x4_t  test_b32 = {4,3,2,1};
uint8x4_t  test_c;

uint16x2_t  test_a16 = {1,2};
uint16x2_t  test_b16 = {4,3};
uint16x2_t  test_c16;

int8x4_t  test_ia32 = {1,2,3,4};
int8x4_t  test_ib32 = {4,3,2,1};
int8x4_t  test_ic;

int16x2_t  test_ia16 = {1,2};
int16x2_t  test_ib16 = {4,3};
int16x2_t  test_ic16;

int64_t aa = 0x55;
int64_t bb = 0x11;
int64_t cc = 0;

uint64_t uaa = 0x55;
uint64_t ubb = 0x11;
uint64_t ucc = 0;
#else


uintXLEN_t a   = 0x0807060504030201;
uintXLEN_t b   = 0x0102030405060708;
uintXLEN_t c = 0;

uint8x8_t  test_a = {1,2,3,4,5,6,7,8};
uint8x8_t  test_b = {8,7,6,5,4,3,2,1};
uint8x8_t  test_c;

uint16x4_t  test_a16 = {1,2,3,4};
uint16x4_t  test_b16 = {8,7,6,5};
uint16x4_t  test_c16;


int8x8_t  test_ia = {1,2,3,4,5,6,7,8};
int8x8_t  test_ib = {8,7,6,5,4,3,2,1};
int8x8_t  test_ic;

int16x4_t  test_ia16 = {1,2,3,4};
int16x4_t  test_ib16 = {8,7,6,5};
int16x4_t  test_ic16;


int64_t aa = 0x55;
int64_t bb = 0x11;
int64_t cc = 0;

uint64_t uaa = 0x55;
uint64_t ubb = 0x11;
uint64_t ucc = 0;

#endif


static void test_add8(void)
{
#if __riscv_xlen == 32
    c = __rv__radd8(a, b);
    test_c = __rv__v_uadd8(test_a32, test_b32);
    test_ic = __rv__v_sadd8(test_ia32, test_ib32);
#else
    c = __rv__add8(a, b);
    test_c = __rv__v_uadd8(test_a, test_b);
    test_ic =  __rv__v_sadd8(test_ia, test_ib);
#endif
    printf("c is %p\n", c);
    printf("test_c is %p\n", test_c);
    printf("test_ic is %p\n", test_ic);
}

static void test_add16(void)
{
#if __riscv_xlen == 32
    c = __rv__radd16(a, b);
    test_c16 = __rv__v_uadd16(test_a16, test_b16);
    test_ic16 = __rv__v_sadd16(test_ia16, test_ib16);
#else
    c = __rv__add16(a, b);
    test_c16 = __rv__v_uadd16(test_a16, test_b16);
    test_ic16 =  __rv__v_sadd16(test_ia16, test_ib16);
#endif
    printf("c is %p\n", c);
    printf("test_c16 is %p\n", test_c16);
    printf("test_ic16 is %p\n", test_ic16);
}

static void test_add64(void)
{
    // int64_t __rv__sadd64(int64_t a, int64_t b);
    // uint64_t __rv__uadd64(uint64_t a, uint64_t b);

   cc = __rv__sadd64(aa,bb);
   ucc = __rv__uadd64(uaa,ubb);
   printf("cc is %p\n", cc);
   printf("ucc is %p\n", ucc);
}

static void test_bitrev(void)
{
    c = __rv__bitrev(a, b);
    printf("bitrev is %p\n", c);
}

void test_dsp(void)
{
    
    test_add8();
    test_add16();
    test_add64();
    test_bitrev();
}

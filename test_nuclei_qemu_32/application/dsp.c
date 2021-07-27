#include <dsp.h>
#include <riscv_dsp.h>
#include <printf.h>

#if __riscv_xlen == 32
typedef int32_t  intXLEN_t;
typedef uint32_t uintXLEN_t;
#else
typedef int64_t  intXLEN_t;
typedef uint64_t uintXLEN_t;
#endif

static void test_add8(void)
{
#if __riscv_xlen == 32
#if 1
    uintXLEN_t a = (1 << 0) | (2 << 8) | (3 << 16) | (4 << 24);
    uintXLEN_t b = (4 << 0) | (3 << 8) | (2 << 16) | (1 << 24);
    uintXLEN_t c = 0;

    c = __rv__add8(a, b);
    printf("c is %p\n", c);
    printf("%d:%d:%d:%d\n", (c & 0x000000ff) , (c & 0x0000ff00) >> 8, (c & 0x00ff0000) >> 16,  (c & 0xff000000) >> 24);
    printf("test add8 ok!\n");
#endif
    uint8x4_t  test_a = {1,2,3,4};
    uint8x4_t  test_b = {4,3,2,1};
    uint8x4_t  test_c;

    test_c = __rv__v_uadd8(test_a, test_b);
    printf("%d,%d,%d,%d\n", test_c[0], test_c[1], test_c[2], test_c[3]);
#else

#endif
}

void test_dsp(void)
{
    test_add8();
}

#include <stdint.h>
__attribute__((noinline)) int Engine_SignedDivide12_002850C0(uint32_t unused, int value) {
    int64_t product = value * (int64_t)0x2AAAAAABLL;
    int high = (int)(product >> 32);
    (void)unused;
    return (high >> 1) - (high >> 31);
}

#include <stdint.h>
__attribute__((noinline)) void Md5State_Initialize_008D1A88(uint32_t *object)
{
    uint32_t *state = object + 1;
    const uint32_t a = 0x67452301u;
    const uint32_t b = 0xefcdab89u;
    state[0] = a;
    state[1] = b;
    state[2] = ~a;
    state[3] = ~b;
    state[4] = 0;
}

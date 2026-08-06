#include <stdint.h>
extern "C" __attribute__((noinline)) void
RenderCommand_Copy12Words_001131B8(
    uint32_t* destination, const uint32_t* source,
    uint32_t header) {
    const uint32_t w0 = source[0];
    const uint32_t w1 = source[1];
    const uint32_t w2 = source[2];
    const uint32_t w3 = source[3];
    const uint32_t w4 = source[4];
    const uint32_t w5 = source[5];
    const uint32_t w6 = source[6];
    const uint32_t w7 = source[7];
    const uint32_t w8 = source[8];
    const uint32_t w9 = source[9];
    const uint32_t w10 = source[10];
    const uint32_t w11 = source[11];
    destination[1] = header;
    destination[4] = w0;
    destination[3] = w1;
    destination[2] = w2;
    destination[0] = w3;
    destination[8] = w4;
    destination[7] = w5;
    destination[6] = w6;
    destination[5] = w7;
    destination[12] = w8;
    destination[11] = w9;
    destination[10] = w10;
    destination[9] = w11;
}

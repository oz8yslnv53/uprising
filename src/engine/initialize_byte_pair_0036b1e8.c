#include <stdint.h>
__attribute__((noinline)) uint32_t Engine_InitializeBytePair_0036B1E8(uint8_t *record, uint8_t value) {
    record[1] = value;
    record[0] = 0;
    return 1;
}

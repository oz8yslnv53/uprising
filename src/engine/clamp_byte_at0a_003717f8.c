#include <stdint.h>
__attribute__((noinline)) uint8_t Engine_ClampByteAt0A_003717F8(const uint8_t *record) {
    uint8_t value = record[0x0a];
    if (value != 0 && value != 1)
        value = 2;
    return value;
}

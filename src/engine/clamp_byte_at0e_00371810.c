#include <stdint.h>
__attribute__((noinline)) uint8_t Engine_ClampByteAt0E_00371810(const uint8_t *record) {
    uint8_t value = record[0x0e];
    if (value != 0 && value != 1)
        value = 2;
    return value;
}

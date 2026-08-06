#include <stdint.h>
__attribute__((noinline)) uint8_t Engine_LookupNibbleTable_00409664(uint32_t value) {
    const uint8_t *table = (const uint8_t *)0x00CA81CCu;
    return table[(value << 24) >> 28];
}

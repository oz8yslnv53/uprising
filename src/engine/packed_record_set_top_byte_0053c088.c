#include <stdint.h>
__attribute__((noinline)) void PackedRecord_SetTopByte_0053C088(void *record, uint32_t value) {
    volatile uint32_t *word = (volatile uint32_t *)((uint8_t *)record + 4);
    *word = (*word & 0x00ffffffu) | (value << 24);
}

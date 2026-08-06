#include <stdint.h>
__attribute__((noinline)) uint8_t *Engine_RecordArrayEntryAt3C_004C3830(uint8_t *object,
                                                                         uint32_t index)
{
    uint8_t *base = *(uint8_t **)(object + 0x3c);
    return base + index * 0xc;
}

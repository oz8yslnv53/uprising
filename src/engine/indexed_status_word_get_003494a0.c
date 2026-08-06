#include <stdint.h>
__attribute__((noinline)) uint32_t FUN_003494A0(void *base, uint32_t index)
{
    uint32_t result = 0xffffffffu;
    uint8_t *record;
    if (index < 0x10u) {
        record = (uint8_t *)base + index * 0x488u;
        if (record != (uint8_t *)0)
            result = *(uint32_t *)(record + 0x468u);
    }
    return result;
}

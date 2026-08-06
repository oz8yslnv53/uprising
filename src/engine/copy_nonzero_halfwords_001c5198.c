#include <stdint.h>
__attribute__((noinline)) void Engine_CopyNonzeroHalfwords_001C5198(uint8_t *object,
                                          const uint16_t *source)
{
    uint8_t *destination = (uint8_t *)*(uint16_t **)(object + 0x74) + 0x70;
    uint32_t index = 0;
    uint16_t value;
    for (;;) {
        if ((int)index >= 0x40)
            return;
        value = source[index];
        if (value == 0)
            return;
        *(uint16_t *)(destination + index * 2 + 0x2900 + 0xb4) = value;
        index++;
    }
}

#include <stdint.h>
__attribute__((noinline)) void Engine_UpdateNestedStateWords_003A495C(uint8_t *object,
                                            uint32_t first,
                                            uint32_t second)
{
    uint8_t *state = *(uint8_t **)(object + 8);
    if (state != 0 && *(int32_t *)(state + 0x50) > 0) {
        uint8_t *destination = *(uint8_t **)(state + 0x40);
        if (destination != 0) {
            *(uint32_t *)(destination + 0x90) = first;
            *(uint32_t *)(destination + 0x94) = second;
        }
    }
}

#include <stdint.h>
__attribute__((noinline)) void Engine_SetField94IfBelow4_00A1FE50(uint8_t *object, uint32_t value) {
    if (value < 4u)
        *(uint32_t *)(object + 0x94) = value;
}

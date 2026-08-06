#include <stdint.h>
__attribute__((noinline)) void Object_NestedFloat44SetIfPresent_005AA670(uint8_t *object, float value)
{
    uint8_t *nested = *(uint8_t **)(object + 0x9C);
    if (nested != 0)
        *(float *)(nested + 0x44) = value;
}

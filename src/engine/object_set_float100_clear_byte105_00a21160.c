#include <stdint.h>
__attribute__((noinline)) void Object_SetFloat100ClearByte105_00A21160(uint8_t *object, float value)
{
    *(float *)(object + 0x100) = value;
    object[0x105] = 0;
}

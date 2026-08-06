#include <stdint.h>
__attribute__((noinline)) void Record_SetByte2CAndFlag8_009082EC(void *object, uint32_t value)
{
    uint8_t *bytes = (uint8_t *)object;
    if (bytes[0x2cu] != value) {
        bytes[0x2cu] = (uint8_t)value;
        *(uint16_t *)(bytes + 0x20u) |= 8u;
    }
}

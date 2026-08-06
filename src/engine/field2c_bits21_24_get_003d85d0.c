#include <stdint.h>
__attribute__((noinline)) uint32_t Engine_Field2CBits21_24Get_003D85D0(const void *object)
{
    const uint8_t *bytes = (const uint8_t *)object;
    return (*(const uint32_t *)(bytes + 0x2c) & 0x01e00000u) >> 21;
}

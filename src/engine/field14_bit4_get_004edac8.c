#include <stdint.h>
__attribute__((noinline)) uint32_t Engine_Field14Bit4Get_004EDAC8(uint8_t *object)
{
    return (*(uint32_t *)(object + 0x14) & 0x10U) >> 4;
}

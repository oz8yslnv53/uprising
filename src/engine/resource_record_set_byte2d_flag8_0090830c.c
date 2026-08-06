#include <stdint.h>
__attribute__((noinline)) void ResourceRecord_SetByte2DAndFlag8_0090830C(
    uint8_t *record, uint32_t value)
{
    if (*(uint8_t *)(record + 0x2dU) != value) {
        uint16_t flags = *(uint16_t *)(record + 0x20U);
        *(uint8_t *)(record + 0x2dU) = (uint8_t)value;
        *(uint16_t *)(record + 0x20U) = (uint16_t)(flags | 8U);
    }
}

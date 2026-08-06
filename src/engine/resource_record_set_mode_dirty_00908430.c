#include <stdint.h>
__attribute__((noinline)) void ResourceRecord_SetModeAndDirty_00908430(
    uint8_t *record, int32_t mode)
{
    if (*(int8_t *)(record + 0x17U) != mode) {
        uint16_t flags = *(uint16_t *)(record + 0x20U);
        *(uint8_t *)(record + 0x17U) = (uint8_t)mode;
        *(uint16_t *)(record + 0x20U) = (uint16_t)(flags | 2U);
    }
}

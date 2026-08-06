#include <stdint.h>
__attribute__((noinline)) uint32_t Registry_IndexedField2C_00AEDBC8(
    const uint8_t *object, uint32_t index)
{
    uint32_t count = *(const uint32_t *)(object + 0x40);
    const uint8_t *records = *(const uint8_t * const *)(object + 0x4c);
    if ((index < count) && (records != 0))
        return *(const uint32_t *)(records + index * 0x34 + 0x2c);
    return 0;
}

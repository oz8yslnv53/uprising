#include <stdint.h>
__attribute__((noinline)) uint8_t *Engine_OptionalField2CGet_00476B1C(
    const uint8_t *object)
{
    uint8_t *record = *(uint8_t **)(object + 4);
    if (record != 0)
        record += 0x2c;
    return record;
}

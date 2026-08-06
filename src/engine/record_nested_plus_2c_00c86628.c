#include <stdint.h>
__attribute__((noinline)) uint8_t *Record_NestedPlus2C_00C86628(const uint8_t *object)
{
    uint8_t *record = *(uint8_t **)(object + 4);
    if (record != 0)
        record += 0x2c;
    return record;
}

#include <stdint.h>
__attribute__((noinline)) int Engine_NestedFloat14ToInt_00C86B18(const uint8_t *object)
{
    const uint8_t *record = *(const uint8_t * const *)(object + 4);
    const uint8_t *value_owner = *(const uint8_t * const *)record;
    return (int)*(const float *)(value_owner + 0x14);
}

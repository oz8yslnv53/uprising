#include <stdint.h>
__attribute__((noinline)) void *NestedState38_GetIfOne_00421984(void *object)
{
    uint8_t *nested = *(uint8_t **)((uint8_t *)object + 0x80);
    if (nested != 0 && nested[0x38] == 1)
        return nested;
    return 0;
}

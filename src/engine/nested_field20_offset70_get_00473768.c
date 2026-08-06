#include <stdint.h>
__attribute__((noinline)) void *Engine_NestedField20Offset70Get_00473768(void *object)
{
    uint8_t *record = (uint8_t *)object;
    uint8_t *nested = *(uint8_t **)(record + 0x20);
    return nested + 0x70;
}

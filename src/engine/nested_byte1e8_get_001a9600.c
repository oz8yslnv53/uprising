#include <stdint.h>
__attribute__((noinline)) int Engine_NestedByte1E8Get_001A9600(void *object)
{
    uint8_t *bytes = (uint8_t *)object;
    uint8_t *nested = *(uint8_t **)(bytes + 0x24u);
    if (nested != 0)
        return (int)*(int8_t *)(nested + 0x1e8u);
    return 0;
}

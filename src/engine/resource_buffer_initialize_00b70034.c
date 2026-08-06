#include <stdint.h>
extern void FUN_00461594(void *object);
__attribute__((noinline)) void *ResourceBuffer_Initialize_00B70034(void *object)
{
    uint8_t *bytes = (uint8_t *)object;
    bytes[0] = 0u;
    FUN_00461594(bytes + 4u);
    return object;
}

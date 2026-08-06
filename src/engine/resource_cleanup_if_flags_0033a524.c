#include <stdint.h>
extern void *ResourceTable_Lookup(void *handle);
extern void FUN_003634D4(void *object);
__attribute__((noinline)) int FUN_0033A524(void *object)
{
    uint8_t *bytes = (uint8_t *)object;
    if ((bytes[0x38u] & 1u) != 0 &&
        ResourceTable_Lookup(bytes + 0x34u) != (void *)0 &&
        (bytes[0x38u] & 2u) == 0)
        FUN_003634D4(object);
    return 0;
}

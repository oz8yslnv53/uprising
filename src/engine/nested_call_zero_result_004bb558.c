#include <stdint.h>
extern void FUN_004EADCC(void *nested, uint32_t value);
__attribute__((noinline)) int Engine_NestedCallZeroResult_004BB558(void *object)
{
    FUN_004EADCC(*(void **)((uint8_t *)object + 0x30), 0U);
    return 0;
}

#include <stdint.h>
extern void *FUN_003B70CC(void *component);
__attribute__((noinline)) uint8_t FUN_002A1224(void *object)
{
    void *component = FUN_003B70CC(*(void **)((uint8_t *)object + 0x168u));
    if (component != (void *)0)
        return (uint8_t)(*(uint8_t *)((uint8_t *)component + 4u) & 1u);
    return 0;
}

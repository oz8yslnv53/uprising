#include <stdint.h>
extern void *ResourceTree_ResolveCurrentEntry_002A6268(void *owner);
__attribute__((noinline)) void FUN_00274F20(
    void *unused, void *owner, uint8_t value)
{
    void *entry = ResourceTree_ResolveCurrentEntry_002A6268(owner);
    uint8_t *record = *(uint8_t **)((uint8_t *)entry + 0x20u);
    (void)unused;
    record[0x65cu] = value;
}

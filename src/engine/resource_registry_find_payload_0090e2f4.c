#include <stdint.h>
extern void *ResourceRegistry_Get_003D9540(void);
extern void *ResourceRegistry_FindByKeys_00915F50(
    void *registry, uint32_t type, uint32_t key, uint32_t selector);
__attribute__((noinline)) uint32_t ResourceRegistry_FindPayload_0090E2F4(
    uint32_t key, uint32_t selector)
{
    void **registry_slot = (void **)0x00D637E4U;
    void *registry = *registry_slot;
    void *entry;
    if (registry == 0) {
        registry = ResourceRegistry_Get_003D9540();
        *registry_slot = registry;
    }
    entry = ResourceRegistry_FindByKeys_00915F50(
        registry, 0x4334574EU, key, selector);
    if (entry == 0)
        return 0;
    return *(const uint32_t *)((const uint8_t *)entry + 0x50U);
}

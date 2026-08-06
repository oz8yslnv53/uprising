#include <stdint.h>
extern void *ResourceTree_ResolveCurrentEntry_002A6268(void *owner);
extern void ResourceTree_SetEntryActive_0025EE3C(void *entry,
                                                  uint8_t active);
extern void EngineResource_ActivatePendingStates_0025E9D8(void *resource);
int FUN_00178DA4(void *object)
{
    uint8_t *bytes = (uint8_t *)object;
    void *entry = ResourceTree_ResolveCurrentEntry_002A6268(
        *(void **)(bytes + 0x30));
    ResourceTree_SetEntryActive_0025EE3C(
        (uint8_t *)(*(void **)((uint8_t *)entry + 0x20)) + 0x08, 1);
    EngineResource_ActivatePendingStates_0025E9D8(
        *(void **)((uint8_t *)entry + 0x20));
    return 0;
}

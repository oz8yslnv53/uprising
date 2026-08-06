#include <stdint.h>
extern void *ResourceTree_ResolveCurrentEntry_002A6268(void *owner);
extern void ResourceTree_SetEntryActive_0025EE3C(void *entry,
                                                  uint8_t active);
extern uint32_t ResourceTree_CheckEntry_0022CF04(void *object, void *entry);
extern void EngineResource_ActivatePendingStates_0025E9D8(void *resource);
uint32_t FUN_001A70B8(void *object)
{
    void *entry = ResourceTree_ResolveCurrentEntry_002A6268(
        *(void **)((uint8_t *)object + 0x30u));
    void *state = *(void **)((uint8_t *)entry + 0x20u);
    ResourceTree_SetEntryActive_0025EE3C((uint8_t *)state + 8, 1);
    if (ResourceTree_CheckEntry_0022CF04((uint8_t *)object + 0x34u,
                                         (uint8_t *)object + 0x44u) != 0)
        EngineResource_ActivatePendingStates_0025E9D8(
            *(void **)((uint8_t *)entry + 0x20u));
    return 0;
}

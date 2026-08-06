#include <stdint.h>
extern void *ResourceTree_ResolveCurrentEntry_002A6268(void *owner);
extern void ResourceTree_SetEntryActive_0025EE3C(void *entry,
                                                  uint8_t active);
extern uint32_t ResourceTree_CheckEntry_0022CF04(void *object, void *entry);
extern void EngineResource_ActivatePendingStates_0025E9D8(void *state);
uint32_t FUN_001602DC(void *object) {
    void *resolved_entry;
    uint8_t *state;
    resolved_entry = ResourceTree_ResolveCurrentEntry_002A6268(
        *(void **)((uint8_t *)object + 0x30));
    state = *(uint8_t **)((uint8_t *)resolved_entry + 0x20);
    ResourceTree_SetEntryActive_0025EE3C(state + 0x08, 1u);
    if (ResourceTree_CheckEntry_0022CF04(
            (uint8_t *)object + 0x34, (uint8_t *)object + 0x44) != 0u)
        EngineResource_ActivatePendingStates_0025E9D8(
            *(void **)((uint8_t *)resolved_entry + 0x20));
    return 0u;
}

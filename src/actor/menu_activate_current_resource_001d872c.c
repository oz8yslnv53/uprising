#include <stdint.h>
extern void *ResourceTree_ResolveCurrentEntry_002A6268(void *owner);
extern void ResourceTree_SetEntryActive_0025EE3C(void *entry,
                                                  uint8_t active);
extern uint32_t ResourceTree_CheckEntry_0022CF04(void *tree,
                                                 void *entry);
extern void EngineResource_ActivatePendingStates_0025E9D8(void *state);
int Menu_ActivateCurrentResource_001D872C(uint8_t *object)
{
    uint8_t *current = (uint8_t *)ResourceTree_ResolveCurrentEntry_002A6268(
        *(void **)(object + 0x30));
    ResourceTree_SetEntryActive_0025EE3C(
        *(void **)(current + 0x20) + 8, 1);
    if (ResourceTree_CheckEntry_0022CF04(object + 0x38, object + 0x48) != 0)
        EngineResource_ActivatePendingStates_0025E9D8(
            *(void **)(current + 0x20));
    return 0;
}

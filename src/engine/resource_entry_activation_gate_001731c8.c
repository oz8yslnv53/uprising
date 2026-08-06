#include <stdint.h>
extern void *ResourceTree_ResolveCurrentEntry_002A6268(void *owner);
extern void ResourceTree_SetEntryActive_0025EE3C(void *entry, uint8_t active);
extern unsigned int ResourceTree_CheckEntry_0022CF04(void *object, void *entry);
extern void EngineResource_ActivatePendingStates_0025E9D8(void *resource);
int FUN_001731C8(void *object)
{
    void *resource = ResourceTree_ResolveCurrentEntry_002A6268(
        *(void **)((uint8_t *)object + 0x30));
    ResourceTree_SetEntryActive_0025EE3C(
        (uint8_t *)(*(void **)((uint8_t *)resource + 0x20)) + 0x08, 1);
    if (ResourceTree_CheckEntry_0022CF04(
            (uint8_t *)object + 0x34, (uint8_t *)object + 0x44) != 0 &&
        *(uint8_t *)((uint8_t *)object + 0xf9) == 5) {
        EngineResource_ActivatePendingStates_0025E9D8(
            *(void **)((uint8_t *)resource + 0x20));
    }
    return 0;
}

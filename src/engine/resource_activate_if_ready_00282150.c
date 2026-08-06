#include <stdint.h>
extern void *ResourceTree_ResolveCurrentEntry_002A6268(void *owner);
extern void ResourceTree_SetEntryActive_0025EE3C(void *entry,
                                                  uint8_t active);
extern uint32_t ResourceTree_CheckEntry_0022CF04(void *object, void *entry);
extern void EngineResource_ActivatePendingStates_0025E9D8(void *resource);
__attribute__((noinline)) uint32_t
ResourceTree_ActivateIfReady_00282150(void *object) {
    void *current = ResourceTree_ResolveCurrentEntry_002A6268(
        *(void **)((char *)object + 0x30));
    void *resource = *(void **)((char *)current + 0x20);
    ResourceTree_SetEntryActive_0025EE3C((char *)resource + 8, 1);
    if (ResourceTree_CheckEntry_0022CF04(
            (char *)object + 0x48, (char *)object + 0x58) != 0) {
        current = ResourceTree_ResolveCurrentEntry_002A6268(
            *(void **)((char *)object + 0x30));
        EngineResource_ActivatePendingStates_0025E9D8(
            *(void **)((char *)current + 0x20));
    }
    return 0;
}

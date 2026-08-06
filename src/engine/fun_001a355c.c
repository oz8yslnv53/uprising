#include <stdint.h>
extern uint32_t ResourceTree_CheckEntry_0022CF04(void *object, void *entry);
extern void EngineResource_ActivatePendingStates_0025E9D8(void *resource);
uint32_t FUN_001A355C(void *object)
{
    uint8_t *bytes = (uint8_t *)object;
    void *resource = *(void **)(bytes + 0x3e0u);
    if (ResourceTree_CheckEntry_0022CF04(bytes + 0x60u,
                                         (uint8_t *)resource + 0x70u) != 0) {
        void *owner_resource = *(void **)(bytes + 0x440u);
        EngineResource_ActivatePendingStates_0025E9D8(
            *(void **)((uint8_t *)owner_resource + 0x20u));
    }
    return 0;
}

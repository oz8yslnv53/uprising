#include <stdint.h>
extern void *ResourceTree_ResolveCurrentEntry_002A6268(void *owner);
extern void ResourceTree_SetTransitionMode_0025F13C(void *resource,
                                                     uint32_t mode);
uint32_t FUN_001A75E0(void *object)
{
    void *entry = ResourceTree_ResolveCurrentEntry_002A6268(
        *(void **)((uint8_t *)object + 0x30u));
    ResourceTree_SetTransitionMode_0025F13C(
        (uint8_t *)(*(void **)((uint8_t *)entry + 0x20u)) + 8, 2);
    return 0;
}

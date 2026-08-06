#include <stdint.h>
extern void *ResourceTree_ResolveCurrentEntry_002A6268(void *owner);
extern void ResourceTree_SetTransitionMode_0025F13C(void *resource,
                                                     uint32_t mode);
__attribute__((noinline)) int FUN_002830E4(void *object)
{
    void *entry = ResourceTree_ResolveCurrentEntry_002A6268(
        *(void **)((uint8_t *)object + 0x30u));
    void *resource = *(void **)((uint8_t *)entry + 0x20u);
    ResourceTree_SetTransitionMode_0025F13C((uint8_t *)resource + 8u, 2u);
    return 0;
}
__attribute__((noinline)) int ResourceTree_ApplyTransitionMode2_00182784(
    void *object)
{
    uint8_t *nested = *(uint8_t **)((uint8_t *)object + 0x2acu);
    if (nested != 0) {
        ResourceTree_SetTransitionMode_0025F13C(
            *(void **)(nested + 0x4u) + 0x8u, 2u);
    }
    return 0;
}

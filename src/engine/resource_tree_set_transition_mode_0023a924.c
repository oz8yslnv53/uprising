#include <stdint.h>
extern void *ResourceTree_ResolveCurrentEntry_002A6268(void *owner);
extern void ResourceTree_SetTransitionMode_0025F13C(void *resource,
                                                     uint32_t mode);
__attribute__((noinline)) int
ResourceTree_ResolveCurrentAndSetMode_0023A924(void *object)
{
    void *entry = ResourceTree_ResolveCurrentEntry_002A6268(
        *(void **)((uint8_t *)object + 0x30u));
    void *resource = *(void **)((uint8_t *)entry + 0x20u);
    ResourceTree_SetTransitionMode_0025F13C(
        (uint8_t *)resource + 8u, 2u);
    return 0;
}
__attribute__((noinline)) int
ResourceTree_ResolveCurrentAndSetMode_00270970(void *object)
{
    void *entry = ResourceTree_ResolveCurrentEntry_002A6268(
        *(void **)((uint8_t *)object + 0x30u));
    void *resource = *(void **)((uint8_t *)entry + 0x20u);
    ResourceTree_SetTransitionMode_0025F13C(
        (uint8_t *)resource + 8u, 2u);
    return 0;
}

#include <stdint.h>
extern void *ResourceTree_ResolveCurrentEntry_002A6268(void *owner);
extern void ResourceTree_SetTransitionMode_0025F13C(void *resource,
                                                     uint32_t mode);
__attribute__((noinline)) uint32_t ResourceTree_ApplyTransitionMode2_0022B9B0(void *object) {
    void *entry = ResourceTree_ResolveCurrentEntry_002A6268(
        *(void **)((char *)object + 0x30));
    void *resource = *(void **)((char *)entry + 0x20);
    ResourceTree_SetTransitionMode_0025F13C((char *)resource + 8, 2);
    return 0;
}
__attribute__((noinline)) uint32_t
ResourceTree_ApplyTransitionMode2FromNested_00176740(void *object)
{
    void *owner = *(void **)((char *)object + 0x244);
    void *resource = *(void **)((char *)owner + 0x20);
    ResourceTree_SetTransitionMode_0025F13C((char *)resource + 8, 2);
    return 0;
}
__attribute__((noinline)) uint32_t
ResourceTree_ApplyTransitionMode2_001A6DB4(void *object)
{
    void *entry = ResourceTree_ResolveCurrentEntry_002A6268(
        *(void **)((char *)object + 0x30));
    void *resource = *(void **)((char *)entry + 0x20);
    ResourceTree_SetTransitionMode_0025F13C((char *)resource + 8, 2);
    return 0;
}

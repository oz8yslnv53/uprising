#include <stdint.h>
extern void *ResourceTree_ResolveCurrentEntry_002A6268(void *owner);
extern void ResourceTree_SetTransitionMode_0025F13C(
    void *resource, uint32_t mode);
int FUN_001AD5DC(void *object)
{
    void *entry = ResourceTree_ResolveCurrentEntry_002A6268(
        *(void **)((uint8_t *)object + 0x30));
    void *resource = *(void **)((uint8_t *)entry + 0x20);
    ResourceTree_SetTransitionMode_0025F13C(
        (uint8_t *)resource + 8, 2);
    return 0;
}

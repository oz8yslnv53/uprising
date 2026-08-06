#include <stdint.h>
extern void *ResourceTree_ResolveCurrentEntry_002A6268(void *owner);
extern void ResourceTree_SetTransitionMode_0025F13C(void *resource,
                                                     uint32_t mode);
int ResourceTransition_SetMode3_00206594(void *record)
    __attribute__((noinline));
__attribute__((noinline)) int ResourceTransition_SetMode3_00206594(void *record)
{
    void *entry = ResourceTree_ResolveCurrentEntry_002A6268(
        *(void **)((uint8_t *)record + 0x30));
    void *resource = *(void **)((uint8_t *)entry + 0x20);
    ResourceTree_SetTransitionMode_0025F13C((uint8_t *)resource + 0x08, 3);
    return 0;
}

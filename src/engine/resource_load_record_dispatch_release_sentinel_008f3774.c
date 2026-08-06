#include <stdint.h>
typedef void (*ResourceSentinelFn)(void);
extern ResourceSentinelFn ResourceLoadReleaseCallbacks_008F37A4[2];
void ResourceLoadRecord_DispatchReleaseSentinel_008F3774(uint32_t **value)
{
    uint32_t *payload = (uint32_t *)(uintptr_t)*value;
    if (*payload == 0x80000000U)
        ResourceLoadReleaseCallbacks_008F37A4[0]();
    else if (*payload == 0x40000000U)
        ResourceLoadReleaseCallbacks_008F37A4[1]();
}

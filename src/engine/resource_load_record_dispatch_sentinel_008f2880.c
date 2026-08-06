#include <stdint.h>
typedef void (*ResourceSentinelFn)(void);
extern ResourceSentinelFn ResourceLoadSentinelCallbacks_008F28B0[2];
void ResourceLoadRecord_DispatchSentinel_008F2880(uint32_t **value)
{
    uint32_t *payload = (uint32_t *)(uintptr_t)*value;
    if (*payload == 0x80000000U)
        ResourceLoadSentinelCallbacks_008F28B0[0]();
    else if (*payload == 0x40000000U)
        ResourceLoadSentinelCallbacks_008F28B0[1]();
}

#include <stdint.h>
__attribute__((noinline)) void Engine_ClearDescriptorHeader_0048A544(void *record)
{
    uint8_t *bytes = (uint8_t *)record;
    *(uint32_t *)bytes = 0u;
    bytes[4] = 0u;
    bytes[5] = 0u;
    bytes[6] = 0u;
}

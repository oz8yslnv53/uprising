#include <stdint.h>
extern void *Engine_ResourceHandleLookup_00B5E45C(void *handle);
__attribute__((noinline)) void ResourceHandle_LookupIfPending_00809588(void *handle)
{
    if (*(uint8_t *)((uint8_t *)handle + 0x54) != 0) {
        Engine_ResourceHandleLookup_00B5E45C(handle);
        ((uint8_t *)handle)[0x54] = 0;
    }
}

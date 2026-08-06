#include <stdint.h>
extern void ResourceFactory_SubresourceInitialize_0070EA88(void *factory);
__attribute__((noinline)) void *ResourceFactory_GetSubobject340_0070B4A4(void *factory)
{
    ResourceFactory_SubresourceInitialize_0070EA88(factory);
    return (uint8_t *)factory + 0x340;
}

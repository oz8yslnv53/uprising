#include <stdint.h>
extern void *ResourceHandle_GetSingleton_00A2ECD8(void);
__attribute__((noinline)) void ResourceHandle_DefaultConstruct_00B5E464(
    void **handle)
{
    *handle = ResourceHandle_GetSingleton_00A2ECD8();
}

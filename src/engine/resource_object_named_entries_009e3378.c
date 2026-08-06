// 009E3378: resolve the nineteen named entries for a resource wrapper once.
#include <stdint.h>
extern const char * const DAT_00D49DC0[];
extern void *ResourceWrapper_FindNamed_00425F64(
    void *wrapper, const char *name);
void ResourceObject_InitializeNamedEntries_009E3378(
    void *object, void *wrapper)
{
    uint32_t index;
    if (wrapper == 0)
        return;
    if (*(volatile void **)((uint8_t *)object + 0x3C) != 0)
        return;
    for (index = 0; index < 0x13u; ++index) {
        *(volatile void **)((uint8_t *)object + 0x40 + index * 4) =
            ResourceWrapper_FindNamed_00425F64(
                wrapper, DAT_00D49DC0[index]);
    }
    *(volatile void **)((uint8_t *)object + 0x3C) = wrapper;
}

#include <stdint.h>
extern void *Engine_ForEachStrideCallback_00421EA4(
    void *base, void (*callback)(void *), uint32_t stride, uint32_t count);
extern void ResourceRecord_Initialize_001515EC(void *record);
void *ResourceTree_Initialize_0012FF0C(void *object)
{
    uint8_t *sentinel = (uint8_t *)object + 0x0c;
    void *records;
    *(void **)object = object;
    *(void **)((uint8_t *)object + 4) = object;
    *(void **)((uint8_t *)object + 8) = object;
    *(void **)((uint8_t *)object + 0x0c) = sentinel;
    *(void **)((uint8_t *)object + 0x10) = sentinel;
    *(void **)((uint8_t *)object + 0x14) = sentinel;
    records = Engine_ForEachStrideCallback_00421EA4(
        (uint8_t *)object + 0x18, ResourceRecord_Initialize_001515EC,
        0x88, 0x20);
    return (uint8_t *)records - 0x18;
}

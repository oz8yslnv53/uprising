#include <stdint.h>
extern void *ResourceTable_Lookup(void *handle);
extern uint32_t ComponentDescriptor_FieldGet_00579660(uint8_t *object,
                                                       uint32_t offset,
                                                       uint32_t fallback);
__attribute__((noinline)) uint32_t ResourceTable_GetModeBits_00A5AD1C(void *object)
{
    uint8_t *descriptor = (uint8_t *)ResourceTable_Lookup(
        (uint8_t *)object + 0x0Cu);
    if (descriptor == 0) {
        return 0u;
    }
    return ComponentDescriptor_FieldGet_00579660(descriptor, 0x20u, 0u) >> 28;
}

#include <stdint.h>
extern void ResourceEffect_UpdatePrefix_0021F94C(void *record);
__attribute__((noinline)) void DeviceContext_ClearResourceSlots_001878A4(void *context) {
    uint8_t *bytes = (uint8_t *)context;
    int index;
    for (index = 0; index < 0x18; ++index) {
        uint8_t *slot = *(uint8_t **)(bytes + 0x15dc + index * 4);
        ResourceEffect_UpdatePrefix_0021F94C(slot + 0x68);
    }
}

#include <stdint.h>
extern void RecordVariant_Initialize_0045FD88(void *record);
__attribute__((noinline)) uint32_t RecordGroup_InitializeSix_00437090(void *base) {
    uint32_t index = 0;
    do {
        RecordVariant_Initialize_0045FD88(
            (uint8_t *)base + (index * 0x173u << 3));
        index++;
    } while (index < 6);
    *(uint32_t *)((uint8_t *)base + 0x4590) = 0;
    return 0;
}

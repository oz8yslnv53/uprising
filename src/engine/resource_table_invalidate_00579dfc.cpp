#include <cstdint>
#include <stdint.h>
extern void ResourceEntry_Invalidate_005AAE7C(uint8_t *entry);
__attribute__((noinline)) void ResourceTable_Invalidate_00579DFC(uint8_t *table, int32_t index) {
    if (index >= 0) {
        ResourceEntry_Invalidate_005AAE7C(table + index * 0x288 + 0x281c);
        return;
    }
    for (int32_t i = 0; i < 3; ++i) {
        ResourceEntry_Invalidate_005AAE7C(table + i * 0x288 + 0x281c);
    }
}

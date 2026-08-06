#include <stdint.h>
extern "C" uint32_t FUN_0014DAE8(void);
extern "C" uint32_t FUN_0051EAD0(uint32_t);
extern "C" __attribute__((noinline)) uint32_t RenderConfig_GetRangeLimit_00152BFC(uint32_t size) {
    if (size == 0x20000u) {
        if (FUN_0014DAE8() != 0)
            return 0x180000u;
    } else if (size == 0x30000u) {
        if (FUN_0014DAE8() != 0)
            return 0x280000u;
    } else {
        return 0;
    }
    return 0x300000u;
}
extern "C" __attribute__((noinline)) uint32_t RenderConfig_InitializeRangeGroups_0012DCA0(
    uint32_t first_offset, uint32_t second_offset) {
    static const uint32_t sizes[2] = {0x20000u, 0x30000u};
    uint32_t *groups = (uint32_t *)0x00DF0718u;
    const uint32_t offsets[2] = {first_offset, second_offset};
    uint32_t index;
    for (index = 0; index != 2; ++index) {
        uint32_t size = sizes[index];
        uint32_t memory_base = FUN_0051EAD0(size);
        uint32_t limit = RenderConfig_GetRangeLimit_00152BFC(size);
        groups[index * 3] = offsets[index] + memory_base;
        groups[index * 3 + 1] = limit - offsets[index];
        groups[index * 3 + 2] = 0;
    }
    return 1;
}

#include <stdint.h>
extern uint32_t Engine_CountUnits_00B42634(uint32_t count);
__attribute__((noinline)) uint32_t Engine_AlignedStrideFromCount_00B409EC(void *unused,
                                                uint32_t count) {
    uint32_t size = Engine_CountUnits_00B42634(count) * 4u + 4u;
    (void)unused;
    return (size + 3u) & ~3u;
}

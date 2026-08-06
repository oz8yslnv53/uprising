#include <stdint.h>
__attribute__((noinline)) void Engine_RecordValueBelow3Set_00365D6C(uint32_t *slot, uint32_t value) {
    if (value < 3) {
        *slot = value;
    }
}

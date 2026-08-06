// 0012A9BC: set byte +2 in the shared global record at 00D4D498.
#include <stdint.h>
#include "engine_common_views.h"
__attribute__((noinline)) void Engine_GlobalByte2Set_0012A9BC(uint8_t value) {
    volatile struct EngineGlobalStateRecordView *state =
        (volatile struct EngineGlobalStateRecordView *)(uintptr_t)0x00D4D498u;
    state->first_word.bytes_000[2] = value;
}

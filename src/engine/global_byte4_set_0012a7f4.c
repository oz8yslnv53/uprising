// 0012A7F4: set byte +4 in the shared global record at 00D4D498.
#include <stdint.h>
#include "engine_common_views.h"
__attribute__((noinline)) void Engine_GlobalByte4Set_0012A7F4(uint8_t value) {
    struct EngineGlobalStateRecordView *state =
        (struct EngineGlobalStateRecordView *)(uintptr_t)0x00D4D498u;
    state->byte_004 = value;
}

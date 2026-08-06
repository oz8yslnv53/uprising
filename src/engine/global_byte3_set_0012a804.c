// 0012A804: set byte +3 in the shared global record at 00D4D498.
#include <stdint.h>
#include "engine_common_views.h"
__attribute__((noinline)) void Engine_GlobalByte3Set_0012A804(uint8_t value) {
    struct EngineGlobalStateRecordView *state =
        (struct EngineGlobalStateRecordView *)(uintptr_t)0x00D4D498u;
    state->first_word.bytes_000[3] = value;
}

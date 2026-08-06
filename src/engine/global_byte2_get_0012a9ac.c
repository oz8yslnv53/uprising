// 0012A9AC: read byte +2 from the shared global record at 00D4D498.
#include <stdint.h>
#include "engine_common_views.h"
__attribute__((noinline)) uint8_t Engine_GlobalByte2Get_0012A9AC(void) {
    volatile struct EngineGlobalStateRecordView *state =
        (volatile struct EngineGlobalStateRecordView *)(uintptr_t)0x00D4D498u;
    return state->first_word.bytes_000[2];
}

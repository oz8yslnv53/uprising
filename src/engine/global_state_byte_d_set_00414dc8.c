#include <stdint.h>
#include "engine_common_views.h"
__attribute__((noinline)) void Engine_GlobalStateByteDSet_00414DC8(uint8_t value) {
    struct EngineGlobalStateRecordView *state =
        (struct EngineGlobalStateRecordView *)(uintptr_t)0x00D4D498u;
    state->signed_byte_00d = (int8_t)value;
}

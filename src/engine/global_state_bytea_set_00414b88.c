#include <stdint.h>
#include "engine_common_views.h"
__attribute__((noinline)) void Engine_GlobalStateByteASet_00414B88(uint8_t value)
{
    struct EngineGlobalStateRecordView *state =
        (struct EngineGlobalStateRecordView *)(uintptr_t)0x00D4D498u;
    state->byte_00a = value;
}

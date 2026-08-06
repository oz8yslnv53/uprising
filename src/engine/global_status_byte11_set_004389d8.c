#include <stdint.h>
#include "engine_common_views.h"
__attribute__((noinline)) void Engine_GlobalStatusByte11Set_004389D8(uint8_t value)
{
    volatile struct EngineGlobalStateRecordView *state =
        (volatile struct EngineGlobalStateRecordView *)(uintptr_t)0x00D4D498u;
    state->byte_00b = value;
}

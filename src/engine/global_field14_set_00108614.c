// 00108614: store the value in the shared global record's field at +0x14.
#include <stdint.h>
#include "engine_common_views.h"
__attribute__((noinline)) void Engine_GlobalField14Set_00108614(uint32_t value)
{
    volatile struct EngineGlobalStateRecordView *state =
        (volatile struct EngineGlobalStateRecordView *)(uintptr_t)0x00D4D498u;
    state->field_014 = value;
}

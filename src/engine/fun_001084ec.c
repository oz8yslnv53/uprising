#include <stdint.h>
#include "engine_common_views.h"
__attribute__((noinline)) void FUN_001084EC(uint32_t value)
{
    struct EngineGlobalStateRecordView *state =
        (struct EngineGlobalStateRecordView *)(uintptr_t)0x00D4D498u;
    state->mode_flags_018 = value;
}

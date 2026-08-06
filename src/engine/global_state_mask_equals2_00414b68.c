#include <stdint.h>
#include "engine_common_views.h"
__attribute__((noinline)) int Engine_GlobalStateMaskEquals2_00414B68(void)
{
    const struct EngineGlobalStateRecordView *state =
        (const struct EngineGlobalStateRecordView *)(uintptr_t)0x00D4D498u;
    return ((state->mode_flags_018 & 7u) == 2u) ? 1 : 0;
}

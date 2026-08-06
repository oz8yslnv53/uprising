#include <stdint.h>
#include "engine_common_views.h"
__attribute__((noinline)) uint32_t Engine_GlobalStateModeGet_00414B54(void)
{
    const struct EngineGlobalStateRecordView *state =
        (const struct EngineGlobalStateRecordView *)(uintptr_t)0x00D4D498u;
    return state->mode_flags_018 & 7u;
}

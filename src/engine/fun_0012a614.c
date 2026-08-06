#include <stdint.h>
#include "engine_common_views.h"
__attribute__((noinline)) int FUN_0012A614(void)
{
    const struct EngineGlobalStateRecordView *state =
        (const struct EngineGlobalStateRecordView *)(uintptr_t)0x00D4D498u;
    return (int8_t)state->byte_008;
}

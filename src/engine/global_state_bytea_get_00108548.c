#include <stdint.h>
#include "engine_common_views.h"
__attribute__((noinline)) uint8_t Engine_GlobalStateByteAGet_00108548(void)
{
    const struct EngineGlobalStateRecordView *state =
        (const struct EngineGlobalStateRecordView *)(uintptr_t)0x00D4D498u;
    return state->byte_00a;
}

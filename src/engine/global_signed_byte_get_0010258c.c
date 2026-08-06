#include <stdint.h>
#include "engine_common_views.h"
__attribute__((noinline)) int Engine_GlobalSignedByteGet_0010258C(void)
{
    const struct EngineGlobalStateRecordView *state =
        (const struct EngineGlobalStateRecordView *)(uintptr_t)0x00D4D498u;
    return (int8_t)state->first_word.bytes_000[0];
}

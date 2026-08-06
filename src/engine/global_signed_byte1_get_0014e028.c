// 0014E028: return signed byte +1 from the shared global record at D4D498.
#include <stdint.h>
#include "engine_common_views.h"
__attribute__((noinline)) int Engine_GlobalSignedByte1Get_0014E028(void)
{
    volatile struct EngineGlobalStateRecordView *state =
        (volatile struct EngineGlobalStateRecordView *)(uintptr_t)0x00D4D498u;
    return (int8_t)state->first_word.bytes_000[1];
}

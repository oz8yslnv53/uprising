// 0012A660: return signed byte +7 from the shared global record at 00D4D498.
#include <stdint.h>
#include "engine_common_views.h"
__attribute__((noinline)) int Engine_GlobalSignedByte7Get_0012A660(void)
{
    volatile struct EngineGlobalStateRecordView *state =
        (volatile struct EngineGlobalStateRecordView *)(uintptr_t)0x00D4D498u;
    return (int8_t)state->byte_007;
}

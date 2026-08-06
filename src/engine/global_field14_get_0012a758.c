// 0012A758: return field +0x14 from the shared global record at 00D4D498.
#include <stdint.h>
#include "engine_common_views.h"
__attribute__((noinline)) uint32_t Engine_GlobalField14Get_0012A758(void) {
    volatile struct EngineGlobalStateRecordView *state =
        (volatile struct EngineGlobalStateRecordView *)(uintptr_t)0x00D4D498u;
    return state->field_014;
}

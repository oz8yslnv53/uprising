#include <stdint.h>
#include "engine_common_views.h"
__attribute__((noinline)) void Engine_GlobalRecordFields20_60Set_00102564(uint32_t first, uint32_t second)
{
    struct EngineGlobalRecordD4D4C8View *record =
        (struct EngineGlobalRecordD4D4C8View *)(uintptr_t)0x00D4D4C8u;
    record->field_020 = first;
    record->field_060 = second;
}

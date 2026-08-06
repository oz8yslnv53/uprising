#include <stdint.h>
#include "engine_common_views.h"
__attribute__((noinline)) void FUN_00102578(uint32_t value1, uint32_t value2)
{
    struct EngineGlobalRecordD4D4C8View *record =
        (struct EngineGlobalRecordD4D4C8View *)(uintptr_t)0x00D4D4C8u;
    record->field_024 = value1;
    record->callback_040 = (void *)(uintptr_t)value2;
}

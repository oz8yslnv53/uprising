#include <stdint.h>
#include "engine_common_views.h"
__attribute__((noinline)) void Engine_GlobalRecordFieldsSet_00102504(uint32_t first, uint32_t second) {
    struct EngineGlobalRecordD4D4C8View *record =
        (struct EngineGlobalRecordD4D4C8View *)(uintptr_t)0x00D4D4C8u;
    record->field_02c = first;
    record->field_06c = second;
}

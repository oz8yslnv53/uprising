#include <stdint.h>
#include "engine_common_views.h"
__attribute__((noinline)) int Engine_GlobalSignedByteGet_004389B8(void)
{
    const struct EngineGlobalRecordD4D4C8View *record =
        (const struct EngineGlobalRecordD4D4C8View *)(uintptr_t)0x00D4D4C8u;
    return (int8_t)record->byte_000;
}

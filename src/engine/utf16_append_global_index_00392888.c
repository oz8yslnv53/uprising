#include <stdint.h>
extern uint32_t Utf16_FormatWide_003B8894(
    uint16_t *destination, uint32_t capacity, const uint16_t *format,
    const uint16_t *text, uint32_t index);
void Utf16_AppendGlobalIndex_00392888(
    uint16_t *destination, uint32_t capacity, const uint16_t *record,
    uint32_t unused)
{
    uint32_t index = (uint32_t)record[1] + 1u;
    (void)unused;
    Utf16_FormatWide_003B8894(
        destination, capacity, (const uint16_t *)(uintptr_t)0x00CB3818u,
        *(const uint16_t **)(uintptr_t)0x00D5DD3Cu, index);
}

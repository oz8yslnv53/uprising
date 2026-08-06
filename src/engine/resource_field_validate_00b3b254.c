// 00B3B254: validate the low 22 bits of a resource field and report zero.
#include <stdint.h>
extern void Engine_ReportResourceError_005D3984(
    void *context, uint32_t code, void *value, uint32_t auxiliary);
uint32_t ResourceField_Validate_00B3B254(void *record)
{
    uint32_t value = *(volatile uint32_t *)
        ((uint8_t *)record + 0x58);
    uint32_t low_bits = (value << 10) >> 10;
    if (low_bits != 0)
        return value;
    Engine_ReportResourceError_005D3984(
        (void *)(uintptr_t)0x00CAD484u,
        0xBBu,
        (void *)(uintptr_t)0xA000001Du,
        0u);
    return 0;
}

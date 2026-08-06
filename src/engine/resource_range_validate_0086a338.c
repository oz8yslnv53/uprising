// 0086A338: validate and store an ordered positive range.
#include <stdint.h>
extern void Engine_ReportResourceError_005D3984(
    void *context, uint32_t code, void *value, uint32_t auxiliary);
struct ResourceRangeFields {
    uint8_t padding[0x0C];
    int32_t high;
    int32_t low;
};
uint32_t ResourceRange_SetValidatedBounds_0086A338(
    void *record, int32_t low, int32_t high)
{
    if (low < 0 || high <= 0 || low > high) {
        Engine_ReportResourceError_005D3984(
            (void *)(uintptr_t)0x00CAC640u,
            0x2Eu,
            (void *)(uintptr_t)0xE0000012u,
            0u);
        return 0;
    }
    {
        volatile struct ResourceRangeFields *fields =
            (volatile struct ResourceRangeFields *)record;
        fields->high = high;
        fields->low = low;
    }
    return 1u;
}

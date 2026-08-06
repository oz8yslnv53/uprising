// KIU JP Rev1 reconstruction: 0x00836110
#include <stdint.h>
extern int Runtime_ResourceResolve_00369F88(
    uint32_t *state, int32_t *total, int32_t offset,
    uint32_t size, uint32_t flags);
void ResourceResolve_ForwardOffset8_00836110(
    uint8_t *object, int32_t *total, int32_t offset,
    uint32_t size, uint32_t flags)
{
    (void)Runtime_ResourceResolve_00369F88(
        (uint32_t *)(object + 8u), total, offset, size, flags);
}

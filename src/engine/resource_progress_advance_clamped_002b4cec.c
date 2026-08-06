#include <stdint.h>
void ResourceProgress_AdvanceClamped_002B4CEC(void *progress,
                                               uint32_t delta)
{
    uint8_t *record = (uint8_t *)progress;
    uint32_t limit = 0x0098967FU;
    uint32_t value;
    value = *(uint32_t *)(record + 0x1E8) + delta;
    if ((int32_t)value < 0)
        value = 0;
    if ((int32_t)value < (int32_t)delta ||
        (int32_t)limit < (int32_t)value)
        value = limit;
    *(uint32_t *)(record + 0x1E8) = value;
    if ((int32_t)delta > 0) {
        value = *(uint32_t *)(record + 0x101C4) + delta;
        if (value < delta || limit < value)
            value = limit;
        *(uint32_t *)(record + 0x101C4) = value;
    }
}

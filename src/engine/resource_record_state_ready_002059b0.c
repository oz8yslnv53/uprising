#include <stdint.h>
int Resource_QueryState_0025E884(uint32_t field, uint8_t mode,
                                uint32_t value);
__attribute__((noinline)) uint32_t Resource_RecordStateReady_002059B0(uint32_t *record)
{
    uint32_t result = 0;
    if (record[2] == 0) {
        uint32_t *nested = *(uint32_t **)((uint8_t *)record + 0x9c);
        if (Resource_QueryState_0025E884(nested[8],
                                         *((uint8_t *)record + 0x10),
                                         record[0]) != 0)
            result = 1;
    }
    return result;
}

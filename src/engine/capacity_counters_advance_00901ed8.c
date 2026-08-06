#include <stdint.h>
__attribute__((noinline)) void Engine_CapacityCountersAdvance_00901ED8(void *object) {
    int32_t *fields = (int32_t *)object;
    if (fields[0x70 / 4] < fields[0x6C / 4])
        fields[0x70 / 4]++;
    if (fields[0xAC / 4] < fields[0xA8 / 4])
        fields[0xAC / 4]++;
}

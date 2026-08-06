#include <stdint.h>
__attribute__((noinline)) void Engine_RecordIntFloatSet_0023459C(uint8_t *record, uint32_t value,
                                       float amount) {
    *(uint32_t *)(record + 0x10) = value;
    *(float *)(record + 0x14) = amount;
}

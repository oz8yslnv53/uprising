#include <stdint.h>
void Float_QuantizeResidualGuard_005506B4(void *pair, unsigned int count,
                                           float value);
__attribute__((noinline)) void Engine_QuantizeIndexedPair_0047365C(
    uint8_t *object, unsigned int index, float value)
{
    uint32_t pair[2];
    uint8_t *record = object + index * 0x18u;
    pair[0] = *(const uint32_t *)(record + 0x34);
    pair[1] = *(const uint32_t *)(record + 0x40);
    Float_QuantizeResidualGuard_005506B4(pair, 2, value);
}

#include <stdint.h>
__attribute__((noinline)) void Engine_CopyEntryAndSetReady_00495700(
    uint8_t *object, const uint8_t *source)
{
    const uint32_t value = *(const uint32_t *)(source + 0x12c);
    const uint32_t upper = value >> 9;
    const uint32_t low = (value << 23) >> 23;
    *(uint32_t *)(object + 0x1a0) = low | (upper << 9);
    object[0x36] |= 1;
}

#include <stdint.h>
__attribute__((noinline)) void Engine_SetField30Bits12To19_0031F490(
    void *object, unsigned int value)
{
    uint32_t *field = (uint32_t *)((uint8_t *)object + 0x30u);
    *field = (*field & 0xf0000fffu) | (value << 12);
}

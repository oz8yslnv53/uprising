#include <stdint.h>
__attribute__((noinline)) void Engine_CopyTripleToFields_0049819C(
    uint8_t *object, const uint32_t *source)
{
    *(uint32_t *)(object + 0x78) = source[0];
    *(uint32_t *)(object + 0x7c) = source[1];
    *(uint32_t *)(object + 0x80) = source[2];
}

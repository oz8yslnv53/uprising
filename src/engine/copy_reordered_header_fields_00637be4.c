#include <stdint.h>
__attribute__((noinline)) void Engine_CopyReorderedHeaderFields_00637BE4(
    void *destination, const void *source)
{
    uint8_t *out = (uint8_t *)destination;
    const uint8_t *in = (const uint8_t *)source;
    out[1] = in[0];
    out[2] = in[1];
    *(uint32_t *)(out + 4u) = *(const uint32_t *)(in + 8u);
    *(uint32_t *)(out + 8u) = *(const uint32_t *)(in + 4u);
}

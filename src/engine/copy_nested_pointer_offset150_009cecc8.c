#include <stdint.h>
__attribute__((noinline)) void Engine_CopyNestedPointerOffset150_009CECC8(uint32_t *destination,
                                                 const unsigned char *record)
{
    const uint32_t *source = *(const uint32_t **)(record + 0x150);
    *destination = *source;
}

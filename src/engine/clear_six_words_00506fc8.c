#include <stdint.h>
__attribute__((noinline)) void ClearSixWords_00506FC8(void *record)
{
    uint32_t *words = (uint32_t *)record;
    uint32_t zero = 0;
    words[0] = zero;
    words[1] = zero;
    words[2] = zero;
    words[3] = zero;
    words[4] = zero;
    words[5] = zero;
}

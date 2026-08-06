#include <stdint.h>
__attribute__((noinline)) void Record_CopyFourWords_00785EC8(void *record,
                                                              const uint32_t *source)
{
    uint32_t *destination = (uint32_t *)((uint8_t *)record + 0x14);
    destination[0] = source[0];
    destination[1] = source[1];
    destination[2] = source[2];
    destination[3] = source[3];
}

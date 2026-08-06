#include <stdint.h>
__attribute__((noinline)) void Record_CopyThreeWordsClearFlags_00481890(void *object,
                                               const uint32_t *source)
{
    uint32_t *destination = (uint32_t *)((uint8_t *)object + 8);
    destination[0] = source[0];
    destination[1] = source[1];
    destination[2] = source[2];
    *(uint32_t *)((uint8_t *)object + 0x6c) &= ~0x0bu;
}

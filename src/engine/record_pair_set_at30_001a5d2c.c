#include <stdint.h>
__attribute__((noinline)) void Engine_RecordPair_SetAt30_001A5D2C(void *object, uint32_t first,
                                        uint32_t second)
{
    uint8_t *bytes = (uint8_t *)object;
    *(uint32_t *)(bytes + 0x30) = first;
    *(uint32_t *)(bytes + 0x34) = second;
}

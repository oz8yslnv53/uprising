#include <stdint.h>
__attribute__((noinline)) void Engine_RecordStoreField4AndOptional8_004A87E8(void *record,
                                                    uint32_t value)
{
    *(uint32_t *)((unsigned char *)record + 4) = value;
    if (value != 0)
        *(uint32_t *)((unsigned char *)record + 8) = value;
}

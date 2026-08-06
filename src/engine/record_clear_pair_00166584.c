#include <stdint.h>
__attribute__((noinline)) void Record_ClearPair_00166584(void *record)
{
    *(uint32_t *)record = 0u;
    *(uint32_t *)((uint8_t *)record + 4u) = 0u;
}
__attribute__((noinline)) void *
Record_ClearPairAndReturn_00902B24(void *record)
{
    Record_ClearPair_00166584(record);
    return record;
}

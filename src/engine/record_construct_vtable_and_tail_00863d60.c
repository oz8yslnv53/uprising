#include <stdint.h>
extern void *Record_ConstructTail_005DAC54(void *tail);
__attribute__((noinline)) void *Record_ConstructVtableAndTail_00863D60(void *object)
{
    void *tail;
    *(uint32_t *)object = 0x00d1131cu;
    tail = Record_ConstructTail_005DAC54((uint8_t *)object + 0x1c);
    return (uint8_t *)tail - 0x1c;
}

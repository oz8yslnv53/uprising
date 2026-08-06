#include <stdint.h>
__attribute__((noinline)) void Engine_RecordFloatByteSet_00908548(
    void *object,
    float value,
    uint8_t flag)
{
    uint8_t *bytes = (uint8_t *)object;
    *(float *)(bytes + 0xe0) = value;
    bytes[0xcb] = flag;
}

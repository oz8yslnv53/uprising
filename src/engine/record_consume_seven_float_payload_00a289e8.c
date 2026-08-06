#include <stdbool.h>
#include <stdint.h>
struct SevenFloats {
    float values[7];
};
__attribute__((noinline)) bool Record_ConsumeSevenFloatPayload_00A289E8(
    void *record, struct SevenFloats *output)
{
    uint8_t *bytes = (uint8_t *)record;
    if (bytes[0x224] == 0)
        return false;
    bytes[0x224] = 0;
    *output = *(const struct SevenFloats *)(bytes + 0x22c);
    return true;
}

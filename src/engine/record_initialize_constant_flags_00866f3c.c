#include <stdint.h>
void Record_InitializeConstantFlags_00866F3C(uint32_t *record,
                                             unsigned char value)
{
    const uint32_t zero = 0;
    record[0] = 0x00d11554;
    ((unsigned char *)record)[8] = (unsigned char)zero;
    record[1] = zero;
    record[3] = zero;
    ((unsigned char *)record)[0x10] = value;
}

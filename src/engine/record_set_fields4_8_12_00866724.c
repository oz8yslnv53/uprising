#include <stdint.h>
void Record_SetFields4_8_12_00866724(uint32_t *record,
                                     uint32_t value,
                                     const uint32_t *source)
{
    record[1] = value;
    record[2] = source[0];
    ((unsigned char *)record)[0x0c] = 1;
}

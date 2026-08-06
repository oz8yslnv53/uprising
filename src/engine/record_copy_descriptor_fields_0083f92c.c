#include <stdint.h>
unsigned int Record_CopyDescriptorFields_0083F92C(unsigned char *record)
{
    const unsigned int first = record[8];
    unsigned char *destination = record + 0x500;
    unsigned char *source = record + 4;
    unsigned int value;
    record[0x5e2] = first;
    *(uint16_t *)(destination + 0xe4) = record[6];
    value = source[3];
    if (value == 0xff)
        value = ~0;
    *(uint16_t *)(destination + 0xe6) = value;
    *(uint16_t *)(destination + 0xe0) = *(uint16_t *)(source + 6);
    return 1;
}

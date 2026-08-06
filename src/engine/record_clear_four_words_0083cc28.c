#include <stdint.h>
void Record_ClearFourWords_0083CC28(uint32_t *record)
{
    const uint32_t zero = 0;
    record[0] = zero;
    record[1] = zero;
    record[2] = zero;
    ((unsigned char *)record)[0x0c] = (unsigned char)zero;
}

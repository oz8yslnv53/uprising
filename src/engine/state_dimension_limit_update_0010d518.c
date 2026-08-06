#include <stdint.h>
void FUN_0010D518(uint16_t * record, int minimum, int maximum) {
    uint8_t kind = *((uint8_t *)record + 0x0cu);
    if (maximum > 0x91)
        maximum = 0x91;
    if (kind == 0) {
        if (minimum < 0x28)
            minimum = 0x28;
        record[0] = (uint16_t)minimum;
        record[3] = (uint16_t)maximum;
    } else if (kind == 1) {
        if (minimum < 0x24)
            minimum = 0x24;
        record[1] = (uint16_t)minimum;
        record[4] = (uint16_t)maximum;
    } else {
        record[5] = (uint16_t)maximum;
    }
}

#include <stdint.h>
void Record_SubtractField4Clamped_0084A084(uint32_t *record,
                                           uint32_t amount)
{
    if (record[1] > amount)
        record[1] -= amount;
    else
        record[1] = 0;
}

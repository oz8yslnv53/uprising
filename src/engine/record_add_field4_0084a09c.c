#include <stdint.h>
void Record_AddToField4_0084A09C(uint32_t *record, uint32_t amount)
{
    record[1] = amount + record[1];
}

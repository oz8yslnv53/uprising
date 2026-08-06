#include <stdint.h>
extern uint32_t DAT_0084BFFC[];
void Record_SetByte4AndGlobalFieldC_0084BFEC(unsigned char *record,
                                             uint32_t value)
{
    record[4] = (unsigned char)value;
    DAT_0084BFFC[3] = value;
}

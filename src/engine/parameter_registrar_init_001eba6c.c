#include <stdint.h>
void ParameterRegistrar_Init_001EBA6C(uint8_t *record,
                                      uint32_t value,
                                      uint8_t mode)
{
    *(uint32_t *)(record + 0x00) = 0x00d1d7d4u;
    *(uint32_t *)(record + 0x04) = value;
    *(uint32_t *)(record + 0x08) = 0;
    *(uint32_t *)(record + 0x0c) = 0;
    record[0x10] = mode;
}

#include <stdint.h>
extern void StateRecord_Configure_002E83EC(void * context, uint32_t word,
                                           int first, int second, int third,
                                           int fourth, int fifth,
                                           int last);
void FUN_0010D470(void * context, const uint8_t * record) {
    StateRecord_Configure_002E83EC(
        context, *(const uint32_t *)(record + 0u),
        (int)*(const int8_t *)(record + 4u),
        (int)*(const int8_t *)(record + 5u),
        (int)*(const int8_t *)(record + 7u),
        (int)*(const int8_t *)(record + 8u),
        (int)*(const int8_t *)(record + 9u),
        (int)*(const int16_t *)(record + 10u));
}

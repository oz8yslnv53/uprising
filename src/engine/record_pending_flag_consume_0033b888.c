#include <stdint.h>
__attribute__((noinline)) int Engine_RecordPendingFlagConsume_0033B888(uint8_t *record,
                                             uint8_t value) {
    if (record[0x3f3] == 0) {
        return 0;
    }
    record[0x3f4] = value;
    record[0x3f3] = 0;
    return 1;
}

#include <stdint.h>
__attribute__((noinline)) void Engine_RecordModeAtLeast3Set_002C8F94(uint8_t *record, int value) {
    if (value >= 3) {
        record[0x3ed] = 1;
    }
}

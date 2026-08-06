#include <stdint.h>
__attribute__((noinline)) int Engine_RecordLimitAtLeast_002CB430(const uint8_t *record, int value) {
    return *(const int32_t *)(record + 4) >= value;
}

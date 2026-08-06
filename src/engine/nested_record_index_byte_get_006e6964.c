#include <stdint.h>
__attribute__((noinline)) uint8_t Engine_NestedRecordIndexByteGet_006E6964(
    const uint8_t *object, int index) {
    const uint8_t *record = *(const uint8_t * const *)(object + 0xe4);
    return record[index + 0xaf];
}

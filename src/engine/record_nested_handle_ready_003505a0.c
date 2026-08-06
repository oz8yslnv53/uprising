#include <stdint.h>
__attribute__((noinline)) int Engine_RecordNestedHandleReady_003505A0(const uint8_t *record) {
    const uint32_t *nested = *(const uint32_t * const *)(record + 0x14);
    return nested != 0 && nested[1] != 0;
}

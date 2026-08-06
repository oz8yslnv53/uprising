#include <stdint.h>
__attribute__((noinline)) uint32_t Engine_RecordLinkedSentinelTest_00420EE8(const uint8_t *object) {
    return *(const uint8_t *const *)(object + 0x1c) != object + 0x18;
}

#include <stdint.h>
__attribute__((noinline)) uint32_t Engine_RecordFlagBitTest_003B41F8(const uint8_t *object,
                                            uint32_t bit) {
    return (object[0x0f] & (1u << bit)) != 0;
}

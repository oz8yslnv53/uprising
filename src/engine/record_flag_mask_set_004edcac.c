#include <stdint.h>
__attribute__((noinline)) int Engine_RecordFlagMaskSet_004EDCAC(const uint8_t *object, uint32_t mask) {
    return (*(const uint32_t *)(object + 0x44) & mask) != 0;
}

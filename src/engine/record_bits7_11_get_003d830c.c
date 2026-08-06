#include <stdint.h>
__attribute__((noinline)) uint32_t Engine_RecordBits7To11Get_003D830C(const uint8_t *object) {
    return (*(const uint32_t *)(object + 0x30) & 0xf80u) >> 7;
}

#include <stdint.h>
__attribute__((noinline)) uint32_t Engine_RecordEncodedByteGet_00350C48(const uint8_t *record) {
    uint32_t word = *(const uint32_t *)(record + 0x30);
    return (word << 12) >> 24;
}

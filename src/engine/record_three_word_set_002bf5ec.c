#include <stdint.h>
__attribute__((noinline)) void Record_ThreeWordSet_002BF5EC(uint8_t *record,
                                  const uint32_t *source) {
    record[0x0c] = 1;
    *(uint32_t *)(record + 0x04) = source[0];
    *(uint32_t *)(record + 0x08) = source[1];
}

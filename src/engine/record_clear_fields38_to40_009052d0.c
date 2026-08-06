#include <stdint.h>
__attribute__((noinline)) void Record_ClearFields38To40_009052D0(void *record) {
    uint32_t *words = (uint32_t *)((uint8_t *)record + 0x38);
    words[0] = 0;
    words[1] = 0;
    words[2] = 0;
}

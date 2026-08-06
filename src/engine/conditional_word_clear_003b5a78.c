#include <stdint.h>
__attribute__((noinline)) void Engine_ConditionalWordClear_003B5A78(uint32_t *record) {
    uint32_t current = record[1];
    if (current != 0) {
        uint32_t zero = 0;
        record[1] = zero;
    }
}

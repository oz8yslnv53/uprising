#include <stdint.h>
__attribute__((noinline)) void Record_ClearWord4IfSet_005C3C84(void *record) {
    uint32_t *word = (uint32_t *)((uint8_t *)record + 4);
    if (*word != 0)
        *word = 0;
}

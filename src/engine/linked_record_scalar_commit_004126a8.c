#include <stdint.h>
__attribute__((noinline)) void LinkedRecord_ScalarCommit_004126A8(uint32_t *wrapper,
                                        uint32_t unused,
                                        float value) {
    uint32_t *linked = (uint32_t *)(uintptr_t)wrapper[0];
    (void)unused;
    if (linked != 0 && *(uint8_t *)linked != 0 &&
        linked[4] == wrapper[1])
        *(float *)(linked + 0x1c) = value;
}

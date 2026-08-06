#include <stdint.h>
__attribute__((noinline)) void *Engine_SelectResourceStatus_0035F688(void) {
    uint8_t *root = (uint8_t *)0x00D4DDD0u;
    void *active = *(void **)(root + 0x10);
    if (active != 0)
        return *(void **)((uint8_t *)active + 0xcc);
    return *(void **)(root + 8);
}

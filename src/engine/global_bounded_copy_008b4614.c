#include <stdint.h>
extern void *Engine_CopyBytes_0044C108(void *destination, const void *source,
                                       uint32_t count);
__attribute__((noinline)) void Engine_GlobalBoundedCopy_008B4614(
    const void *source, uint32_t length) {
    uint32_t *stored_length = (uint32_t *)(uintptr_t)0x00d4cfb4u;
    if (length == 0) {
        *stored_length = 0;
        source = 0;
    }
    if (source == 0 || length < 8 || length > 0x10)
        return;
    *stored_length = length;
    Engine_CopyBytes_0044C108((void *)(uintptr_t)0x00db99a8u,
                              source, length);
}

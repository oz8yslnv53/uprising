#include <stdint.h>
__attribute__((noinline)) uint32_t RenderCommand_ActiveCursorGet_001ECC28(void) {
    uint8_t *root = *(uint8_t **)(uintptr_t)0x00d4d140u;
    uint8_t *node = *(uint8_t **)(root + 0x08);
    return *(uint32_t *)(node + 0x0c);
}

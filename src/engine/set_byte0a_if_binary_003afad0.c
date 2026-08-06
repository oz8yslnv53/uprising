#include <stdint.h>
__attribute__((noinline)) void Engine_SetByte0AIfBinary_003AFAD0(uint8_t *object, uint8_t value) {
    if (value != 0 && value != 1)
        return;
    object[0x0a] = value;
}

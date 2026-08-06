#include <stdint.h>
void Engine_StateMarkPending_001F61A8(void *state) {
    uint8_t *bytes = (uint8_t *)state;
    if ((bytes[0x80] & 0x80u) == 0)
        bytes[0x80] |= 0x40u;
}

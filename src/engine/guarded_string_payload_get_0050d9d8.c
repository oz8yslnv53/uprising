#include <stdint.h>
__attribute__((noinline)) uint32_t Engine_GuardedStringPayloadGet_0050D9D8(const uint8_t *object) {
    const char *text = *(const char * const *)object;
    if (text != 0 && text[0] != '\0') {
        return *(const uint32_t *)(object + 0x08);
    }
    return 0;
}

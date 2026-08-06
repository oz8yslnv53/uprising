#include <stdint.h>
__attribute__((noinline)) uint32_t Engine_Type5PayloadGet_00B523BC(const uint8_t *object) {
    if (object[8] == 5)
        return *(const uint32_t *)(object + 0x0c);
    return 0;
}

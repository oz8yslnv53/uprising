#include <stdint.h>
__attribute__((noinline)) int ResourceState_GetSignedHalfword_0023B83C(void *object, int index) {
    uint8_t *bytes = (uint8_t *)object;
    if (index < 2)
        return *(int16_t *)(*(uint8_t **)(bytes + 0x3c + index * 4) + 0x10);
    return 0;
}

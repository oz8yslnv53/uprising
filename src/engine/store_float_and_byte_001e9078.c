#include <stdint.h>
__attribute__((noinline)) void Engine_StoreFloatAndByte_001E9078(uint8_t *object, float value,
                                       uint8_t flag) {
    *(float *)(object + 0x28) = value;
    object[0x2c] = flag;
}

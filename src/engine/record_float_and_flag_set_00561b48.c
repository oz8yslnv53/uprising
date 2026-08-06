#include <stdint.h>
__attribute__((noinline)) void Engine_RecordFloatAndFlagSet_00561B48(uint8_t *object, float value) {
    *(float *)(object + 0xf4) = value;
    object[0xe4] = 1;
}

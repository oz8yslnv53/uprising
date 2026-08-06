#include <stdint.h>
typedef struct StateVector7 {
    float value[7];
} StateVector7;
void __attribute__((noinline)) StateVector7_StoreIfPresent_00A31E88(
    void *object, const float *values) {
    uint8_t *bytes = (uint8_t *)object;
    uint8_t *state = *(uint8_t **)(bytes + 0x140);
    if (state != 0) {
        StateVector7 *destination = (StateVector7 *)(state + 0x31e4);
        destination->value[0] = values[0];
        destination->value[1] = values[1];
        destination->value[2] = values[2];
        destination->value[3] = values[3];
        destination->value[4] = values[4];
        destination->value[5] = values[5];
        destination->value[6] = values[6];
    }
}

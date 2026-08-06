#include <stdint.h>
extern const uint32_t *Engine_ConfigResolve_00A9D5A8(void *key);
__attribute__((noinline)) uint32_t ConfigTriple_Copy_00825120(uint32_t *output, void *key) {
    const uint32_t *record = Engine_ConfigResolve_00A9D5A8(key);
    uint32_t value;
    output[0] = record[0x74 / 4];
    output[1] = record[0x78 / 4];
    value = record[0x7c / 4];
    output[2] = value;
    return value;
}

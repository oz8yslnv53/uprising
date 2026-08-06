#include <stdint.h>
__attribute__((noinline)) int Engine_PackedRecordIndex_00234854(const uint32_t *record) {
    uint32_t packed = record[1];
    uint32_t low = (packed << 17) >> 27;
    uint32_t high = (packed << 13) >> 28;
    return (low * 12) + high;
}

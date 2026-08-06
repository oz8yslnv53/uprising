#include <cstdint>
#include <stdint.h>
extern "C" uint32_t SpatialQuery_NormalizeAndDispatch_00564678(
    uint32_t mode, const float *start, const float *end, void *param4,
    void *slot);
__attribute__((noinline)) uint32_t SpatialQuery_QueryWithScratch_0056465C(
    uint32_t mode, const float *start, const float *end, void *param4) {
    uint8_t scratch[60];
    return SpatialQuery_NormalizeAndDispatch_00564678(
        mode, start, end, param4, scratch);
}

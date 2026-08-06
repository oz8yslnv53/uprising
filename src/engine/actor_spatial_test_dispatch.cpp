#include <cstdint>
extern "C" std::uint32_t SpatialQuery_ProjectPoint_00510A24(
    std::uint32_t mode, float* input, float* output, std::uint32_t flags,
    std::uint8_t* scratch);
extern "C" __attribute__((noinline)) std::uint32_t ActorSpatialTestDispatch(
    std::uint32_t mode, float* input, float* output, std::uint32_t flags)
{
    std::uint8_t scratch[60];
    return SpatialQuery_ProjectPoint_00510A24(mode, input, output, flags,
                                               scratch);
}

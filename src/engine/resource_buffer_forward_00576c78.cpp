#include <cstdint>
extern "C" void ResourceBuffer_Apply_00593600(
    std::uint32_t first, std::uint32_t second, std::uint32_t width,
    std::uint32_t third, std::uint32_t fourth);
extern "C" __attribute__((noinline)) void ResourceBuffer_Forward_00576C78(
    std::uint32_t first, std::uint32_t second, std::uint32_t third,
    std::uint32_t fourth) {
    ResourceBuffer_Apply_00593600(second, first, 8, third, fourth);
}

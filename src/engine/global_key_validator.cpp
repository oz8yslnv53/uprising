#include <cstdint>
extern "C" __attribute__((noinline)) int Engine_GlobalKeyValidator_005B0070(void *candidate)
{
    if (candidate == 0)
        return 0;
    const std::uint32_t global_key = *reinterpret_cast<const std::uint32_t *>(
        0x00d4aa90u);
    if (global_key == 0)
        return 0;
    const std::uint32_t key = *reinterpret_cast<const std::uint32_t *>(
        reinterpret_cast<const std::uint8_t *>(candidate) + 0x20);
    return key == global_key
        ? 1
        : 0;
}

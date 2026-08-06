#include <cstdint>
extern "C" __attribute__((noinline)) void Engine_CopySixBytes_0054BF40(std::uint8_t* destination,
                                               const std::uint8_t* source)
{
    *reinterpret_cast<std::uint32_t*>(destination) =
        *reinterpret_cast<const std::uint32_t*>(source);
    *reinterpret_cast<std::uint16_t*>(destination + 4) =
        *reinterpret_cast<const std::uint16_t*>(source + 4);
}

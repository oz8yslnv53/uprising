// Kid Icarus: Uprising JP Rev 1 status-effect runtime field helpers.
#include <cstdint>
extern "C" __attribute__((noinline)) std::uint8_t *StatusEffect_SetRuntimeFlag_00546B4C(
    std::uint8_t *object, std::uint8_t value)
{
    std::uint8_t* runtime = *reinterpret_cast<std::uint8_t**>(object + 0x20);
    if (runtime != 0)
        runtime[0x2c] = value;
    return runtime;
}
extern "C" __attribute__((noinline)) void StatusEffect_SetRuntimeVector_00546B5C(
    std::uint8_t *object, const std::uint32_t values[3])
{
    std::uint8_t* runtime = *reinterpret_cast<std::uint8_t**>(object + 0x20);
    if (runtime == 0)
        return;
    *reinterpret_cast<std::uint32_t *>(runtime + 0x20) = values[0];
    *reinterpret_cast<std::uint32_t *>(runtime + 0x24) = values[1];
    *reinterpret_cast<std::uint32_t *>(runtime + 0x28) = values[2];
}

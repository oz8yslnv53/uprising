#include <cstdint>
extern "C" __attribute__((noinline)) void* InfoTarget_GetColorDescriptor_0071A83C(
    const std::uint8_t* info_target)
{
    const std::uint8_t* const owner = *reinterpret_cast<const std::uint8_t* const *>(
        info_target + 4);
    return *reinterpret_cast<void* const *>(owner + 0x34);
}

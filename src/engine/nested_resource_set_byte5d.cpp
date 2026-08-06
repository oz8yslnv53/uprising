#include <cstdint>
extern "C" __attribute__((noinline)) void NestedResource_SetByte5D_00725DB8(
    void* owner, std::uint8_t value) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(owner);
    std::uint8_t* child = *reinterpret_cast<std::uint8_t**>(bytes + 0x10);
    if (child == 0 ||
        *reinterpret_cast<std::int32_t*>(child + 0x50) <= 0)
        return;
    std::uint8_t* target = *reinterpret_cast<std::uint8_t**>(child + 0x40);
    if (target != 0)
        target[0x5d] = value;
}

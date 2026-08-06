// JP Rev 1: 0x004AEEBC.
#include <cstdint>
extern "C" __attribute__((noinline)) void StateResource_ResetSlots_004AEEBC(void* state) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(state);
    *reinterpret_cast<std::uint32_t*>(bytes + 0xa8) = 0;
    *reinterpret_cast<std::uint32_t*>(bytes + 0xac) = 0;
    *reinterpret_cast<std::uint32_t*>(bytes + 0xb0) = 0;
    *reinterpret_cast<std::uint32_t*>(bytes + 0xb4) = 0;
    *reinterpret_cast<std::uint32_t*>(bytes + 0xc0) = 2;
}

#include <cstdint>
extern "C" __attribute__((noinline)) std::uint32_t
Engine_CandidateHandleSelector_0054AE88(const void* handle) {
    return *reinterpret_cast<const std::uint32_t*>(
               static_cast<const std::uint8_t*>(handle) + 0x514) & 0xFFu;
}

#include <cstdint>
extern "C" __attribute__((noinline)) void StateResource_SetEnabled_0033B7C0(void *state,
                                                   std::uint8_t enabled) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(state);
    if (bytes[0x15] != 0)
        *reinterpret_cast<std::uint8_t *>(*reinterpret_cast<std::uintptr_t *>(bytes) +
                                          0xC2u) = enabled;
}

#include <cstdint>
extern "C" __attribute__((noinline)) void*
ResourceStream_GetBuffer_00A1AB7C(const void* stream) {
    return *reinterpret_cast<void* const*>(
        static_cast<const std::uint8_t*>(stream) + 0x2C);
}

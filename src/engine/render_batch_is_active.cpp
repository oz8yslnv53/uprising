#include <cstdint>
extern "C" __attribute__((noinline)) std::uint32_t
RenderBatch_IsActive_0092F9C8(const void* batch) {
    return *reinterpret_cast<const std::uint32_t*>(
               static_cast<const std::uint8_t*>(batch) + 0x04) & 1u;
}

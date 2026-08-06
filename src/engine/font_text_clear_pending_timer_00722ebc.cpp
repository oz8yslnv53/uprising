#include <cstdint>
extern "C" __attribute__((noinline)) void FontText_ClearPendingTimer_00722EBC(std::uint8_t *text)
{
    *reinterpret_cast<std::uint32_t *>(text + 0x274) = 0u;
}

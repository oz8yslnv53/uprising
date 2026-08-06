#include <cstdint>
extern "C" __attribute__((noinline)) std::uint32_t
Mask_BitForIndex_00611FF8(std::uint32_t index) {
    if (index != 0xFFFFFFFFu && index >= 5)
        return 0;
    return (1u << index) & 0xFFu;
}

#include <cstdint>
extern "C" __attribute__((noinline)) int ByteRange_Equals_00550E34(const void *left,
                                           const void *right,
                                           std::uint32_t size)
{
    const std::int8_t* lhs = static_cast<const std::int8_t*>(left);
    const std::int8_t* rhs = static_cast<const std::int8_t*>(right);
    for (std::uint32_t index = 0; index < size; ++index) {
        if (lhs[index] != rhs[index])
            return 0;
    }
    return 1;
}

// KIU jp_rev1 0x003F40D8.
#include <cstdint>
extern "C" __attribute__((noinline)) std::uint32_t ResourceStream_GetPayload_003F40D8(
    std::uint32_t record) {
    const std::int8_t selector =
        *reinterpret_cast<const std::int8_t*>(record + 0x1a);
    return *reinterpret_cast<const std::uint32_t*>(
        record + 8 + selector * 4);
}

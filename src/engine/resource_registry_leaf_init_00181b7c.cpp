// KIU jp_rev1: 0x00181B7C
#include <cstddef>
#include <cstdint>
extern "C" __attribute__((noinline)) void* ResourceRegistry_LeafInit_00181B7C(void* record) {
    *reinterpret_cast<std::uint32_t*>(
        static_cast<std::uint8_t*>(record) + 0x2acu) = 0x2du;
    return record;
}

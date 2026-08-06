// KIU jp_rev1: copy two three-word records into the split destination layout.
#include <cstdint>
extern "C" __attribute__((noinline)) void MovieRecord_TripleCopy_002B643C(
    std::uint32_t* destination, const std::uint32_t* source_a,
    const std::uint32_t* source_b) {
    destination[3] = source_a[0];
    destination[4] = source_a[1];
    destination[5] = source_a[2];
    destination[0] = source_b[0];
    destination[1] = source_b[1];
    destination[2] = source_b[2];
}

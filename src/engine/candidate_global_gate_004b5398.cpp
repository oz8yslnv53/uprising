#include <cstdint>
extern "C" __attribute__((noinline)) int Engine_CandidateGlobalGate_004B5398(void) {
    std::uint8_t* candidate = *reinterpret_cast<std::uint8_t**>(0x00D4A7E4u);
    if (candidate == 0)
        return 0;
    return (*reinterpret_cast<std::int32_t *>(candidate + 4) > 0 &&
            candidate[0x11] == 2)
               ? 1
               : 0;
}

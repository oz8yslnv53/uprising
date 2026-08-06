#include <cstdint>
extern "C" __attribute__((noinline)) void ThreeWordRecord_Reset_00565198(std::uint32_t record[3]) {
    record[0] = 0;
    record[1] = 0xFFFFFFFFu;
    record[2] = 0;
}
extern "C" __attribute__((noinline)) void ThreeWordRecord_Copy_005651AC(std::uint32_t destination[3],
                                                const std::uint32_t source[3]) {
    destination[0] = 0;
    destination[1] = 0xFFFFFFFFu;
    destination[2] = 0;
    destination[0] = source[0];
    destination[1] = source[1];
    destination[2] = source[2];
}

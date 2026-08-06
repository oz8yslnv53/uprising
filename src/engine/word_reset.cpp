// KIU jp_rev1 generic word reset at 0x0023ED84.
#include <cstdint>
extern "C" __attribute__((noinline)) void Word_Reset_0023ED84(std::uint32_t* word) {
    *word = 0;
}
extern "C" __attribute__((noinline)) void Word_InitOne_0017F85C(std::uint32_t* word) {
    *word = 1;
}
extern "C" __attribute__((noinline)) void WordAndByte_Clear_001F5308(void* record) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(record);
    *reinterpret_cast<std::uint32_t*>(bytes) = 0;
    bytes[4] = 0;
}

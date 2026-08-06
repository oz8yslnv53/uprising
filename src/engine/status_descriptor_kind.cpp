// KIU jp_rev1 status descriptor kind accessor at 0x00549F00.
#include <cstdint>
extern "C" void* StatusDescriptor_Provider_00520480(void);
extern "C" __attribute__((noinline)) int
StatusDescriptor_GetCurrentKindByte_00549F00(void) {
    std::uint8_t* descriptor = static_cast<std::uint8_t*>(
        StatusDescriptor_Provider_00520480());
    if (descriptor == 0)
        return -1;
    return *reinterpret_cast<const std::int8_t*>(descriptor + 0x50);
}

#include <cstdint>
extern "C" __attribute__((noinline)) std::uint32_t
BgmTable_GetEntryId_00260500(int index) {
    if (index >= 0x7a) {
        return 0xffffffffu;
    }
    const std::uint16_t* table = reinterpret_cast<const std::uint16_t*>(0x00D4927Cu);
    return table[index];
}

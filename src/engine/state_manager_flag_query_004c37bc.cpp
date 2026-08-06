// KIU jp_rev1 address reconstructed in this file: 0x004C37BC.
#include <cstdint>
extern "C" __attribute__((noinline)) int FUN_004C37BC(
    const std::uint8_t* manager, std::uint32_t flag_index,
    std::uint32_t slot_index) {
    if (flag_index >= 2 || slot_index >= 2)
        return 0;
    const std::uint8_t* const slot =
        *reinterpret_cast<std::uint8_t* const*>(manager + 0xb8 + slot_index * 4);
    return slot == 0 ? 0 : static_cast<std::int8_t>(slot[0x138dc + flag_index]);
}

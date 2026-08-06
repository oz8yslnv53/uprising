#include <cstdint>
extern "C" __attribute__((noinline)) void*
ResourceTransform_SyncLinkedPositions_002604C0(void* unused_list_owner) {
    (void)unused_list_owner;
    std::uint8_t* current = *reinterpret_cast<std::uint8_t**>(0x00D48E70u);
    while (current != 0) {
        std::uint8_t* source = *reinterpret_cast<std::uint8_t**>(current + 0x54);
        *reinterpret_cast<std::uint32_t*>(current + 0x74) =
            *reinterpret_cast<const std::uint32_t*>(source + 0x2c);
        *reinterpret_cast<std::uint32_t*>(current + 0x78) =
            *reinterpret_cast<const std::uint32_t*>(source + 0x30);
        *reinterpret_cast<std::uint32_t*>(current + 0x7c) =
            *reinterpret_cast<const std::uint32_t*>(source + 0x34);
        current = *reinterpret_cast<std::uint8_t**>(current + 0xcc);
    }
    return current;
}

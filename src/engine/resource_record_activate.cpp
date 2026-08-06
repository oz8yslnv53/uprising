#include <cstdint>
extern "C" __attribute__((noinline)) int ResourceRecord_Activate_002D88E8(void* record_pointer,
                                                 std::int32_t value) {
    std::uint8_t* record = static_cast<std::uint8_t*>(record_pointer);
    if (*reinterpret_cast<std::uint8_t*>(record + 0x4d) != 0 ||
        *reinterpret_cast<std::uint8_t*>(record + 0x4e) == 0)
        return 0;
    const std::int32_t type = *reinterpret_cast<const std::int32_t*>(record + 0x28);
    if (type == 1) {
        *reinterpret_cast<std::int32_t*>(record + 0x38) = value;
    } else if (type == 2 || type == 3) {
        *reinterpret_cast<std::int32_t*>(record + 0x30) = value;
    } else {
        *reinterpret_cast<std::int32_t*>(record + 0x3c) =
            *reinterpret_cast<const std::int32_t*>(record + 0x34);
        *reinterpret_cast<std::int32_t*>(record + 0x28) = 2;
        *reinterpret_cast<std::int32_t*>(record + 0x34) = -1;
        *reinterpret_cast<std::uint8_t*>(record + 0x4f) = 0;
        *reinterpret_cast<std::int32_t*>(record + 0x30) = value;
    }
    *reinterpret_cast<std::uint8_t*>(record + 0x4d) = 1;
    return 1;
}

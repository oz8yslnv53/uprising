#include <cstdint>
extern "C" __attribute__((noinline)) void*
Registry_SelectSetRecord_00AEDC68(void* registry, std::uint32_t index) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(registry);
    std::uint8_t* records = *reinterpret_cast<std::uint8_t**>(bytes + 0x4C);
    if (records != 0 && index < *reinterpret_cast<std::uint32_t*>(bytes + 0x40) &&
        (*reinterpret_cast<std::uint32_t*>(records + index * 0x34) & 1u) != 0) {
        return records + index * 0x34 + 0x0C;
    }
    return reinterpret_cast<void*>(0x00DC2404u);
}

#include <cstdint>
extern "C" __attribute__((noinline)) void ResourceEntry_SetWord10IfChanged_004ED6E4(
    void* base, std::uint32_t index, std::int32_t value) {
    std::uint8_t* entry = static_cast<std::uint8_t*>(base) + index * 4u;
    std::int32_t* field = reinterpret_cast<std::int32_t*>(entry + 0x10);
    if (*field != value)
        *field = value;
}

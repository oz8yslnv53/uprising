#include <cstdint>
typedef std::uint8_t* (*ProviderRecordFn)(void* provider);
extern "C" __attribute__((noinline)) float Owner_ProviderFlaggedFloatAt20_00B40760(void* object)
{
    void* provider = *reinterpret_cast<void**>(
        static_cast<std::uint8_t*>(object) + 0x288);
    const std::uint32_t* vtable =
        *reinterpret_cast<const std::uint32_t* const*>(provider);
    std::uint8_t* record = reinterpret_cast<ProviderRecordFn>(
        vtable[0x14 / 4])(provider);
    if (record != 0 &&
        (*reinterpret_cast<const std::uint32_t*>(record) & 0x80000000u) == 0u)
        record = 0;
    return *reinterpret_cast<const float*>(
        reinterpret_cast<std::uintptr_t>(record) + 0x14u);
}

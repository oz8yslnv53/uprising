#include <cstdint>
typedef std::uint8_t* (*ProviderRecordFn)(void* provider);
extern "C" __attribute__((noinline)) float Owner_ProviderFloatAt8_00B4068C(void* object)
{
    void* provider = *reinterpret_cast<void**>(
        static_cast<std::uint8_t*>(object) + 0x290);
    const std::uint32_t* vtable =
        *reinterpret_cast<const std::uint32_t* const*>(provider);
    std::uint8_t* record = reinterpret_cast<ProviderRecordFn>(
        vtable[0x14 / 4])(provider);
    return *reinterpret_cast<const float*>(record + 8);
}

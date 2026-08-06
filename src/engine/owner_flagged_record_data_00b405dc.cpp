#include <cstdint>
typedef std::uint32_t* (*OwnerRecordFn)(void* owner);
extern "C" __attribute__((noinline)) std::uint32_t* Owner_FlaggedRecordData_00B405DC(
    void* owner)
{
    void* provider = *reinterpret_cast<void**>(
        static_cast<std::uint8_t*>(owner) + 0x288);
    const std::uint32_t* vtable =
        *reinterpret_cast<const std::uint32_t* const*>(provider);
    std::uint32_t* record = reinterpret_cast<OwnerRecordFn>(
        vtable[0x14 / 4])(provider);
    if (record != 0 && (*record & 0x20000000u) == 0u)
        record = 0;
    return record + 2;
}

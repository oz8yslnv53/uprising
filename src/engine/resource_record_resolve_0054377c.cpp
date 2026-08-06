#include <cstdint>
extern "C" std::int32_t ResourceRecord_FindFormatted_00566238(
    std::uint32_t source, const void* name, std::uint32_t size);
extern "C" std::int32_t ResourceRecord_FindNamed_005662DC(
    std::uint32_t source, const char* name, std::uint32_t size,
    std::uint32_t limit);
extern "C" __attribute__((noinline)) void ResourceRecord_Resolve_0054377C(
    std::int32_t record[3], const void* name, std::uint32_t size,
    std::uint32_t source, std::int32_t mode) {
    record[0] = 0;
    record[1] = -1;
    record[2] = 0;
    if (source == 0 || name == 0)
        return;
    const std::int32_t value = mode < 0
        ? ResourceRecord_FindFormatted_00566238(source, name, size)
        : ResourceRecord_FindNamed_005662DC(
              source, static_cast<const char*>(name), size,
              static_cast<std::uint32_t>(mode));
    record[0] = value;
    if (value != 0) {
        record[1] = 0;
        record[2] = static_cast<std::int32_t>(source);
    }
}

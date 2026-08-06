// Kid Icarus: Uprising JP Rev 1 resource/status leaf accessors.
#include <cstdint>
extern "C" __attribute__((noinline)) bool StatusResource_IsKind5Or6_0054ABE0(
    const std::uint8_t *object)
{
    const std::uint8_t kind = object[0x14];
    return kind == 5 || kind == 6;
}
extern "C" __attribute__((noinline)) bool StatusResource_IsKind4_0054ABF8(
    const std::uint8_t *object)
{
    const std::uint8_t kind = object[0x14];
    return kind == 4;
}
extern "C" __attribute__((noinline)) std::uint32_t StatusResource_GetWord10_0054ACD0(
    const std::uint32_t *holder)
{
    const std::uint32_t* resource = reinterpret_cast<const std::uint32_t*>(holder[0]);
    return resource == 0 ? 0 : resource[0x10 / sizeof(std::uint32_t)];
}
extern "C" __attribute__((noinline)) std::uint32_t StatusResource_GetWord8_0054ACE0(
    const std::uint32_t *holder)
{
    const std::uint32_t* resource = reinterpret_cast<const std::uint32_t*>(holder[0]);
    return resource == 0 ? 0 : resource[0x08 / sizeof(std::uint32_t)];
}
extern "C" __attribute__((noinline)) std::uint32_t EffectResource_HasFlag8_0054AE6C(
    const std::uint8_t *object)
{
    const std::uint8_t*resource = *reinterpret_cast<const std::uint8_t *const *>(
        object + 0x14);
    return resource == 0
        ? 0
        : (*reinterpret_cast<const std::uint32_t *>(resource + 0x50) & 8u) >> 3;
}

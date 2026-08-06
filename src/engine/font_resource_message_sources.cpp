#include <cstdint>
extern "C" void* Engine_ResolveTreeNodeOffset_0036028C(
    void*, std::int8_t, std::int32_t);
static void* resolve(void* resource, std::uint32_t offset) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(resource);
    void* node = Engine_ResolveTreeNodeOffset_0036028C(
        resource, *reinterpret_cast<std::int8_t*>(bytes + 0x18),
        *reinterpret_cast<std::int32_t*>(bytes + 0x1c));
    return node == 0 ? 0 : *reinterpret_cast<void**>(
        static_cast<std::uint8_t*>(node) + offset);
}
extern "C" __attribute__((noinline)) void* FontResource_GetMessageSource_0060E4C0(void* resource) {
    return resolve(resource, 0x48);
}
extern "C" __attribute__((noinline)) void* FontResource_GetAlternateMessageSource_0060E4DC(
    void* resource) {
    return resolve(resource, 0x90);
}

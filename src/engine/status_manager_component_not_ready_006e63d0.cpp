#include <cstdint>
extern "C" void* ResourceTable_Lookup_0049C5E4(void* handle);
extern "C" void* ResolveCachedComponent_0051F140(void* resource);
extern "C" __attribute__((noinline)) std::uint32_t StatusManager_ComponentNotReady_006E63D0(
    void* manager) {
    void* resource = ResourceTable_Lookup_0049C5E4(
        static_cast<std::uint8_t*>(manager) + 0xb278);
    if (resource == 0)
        return 0;
    void* component = ResolveCachedComponent_0051F140(resource);
    if (component == 0 ||
        (*reinterpret_cast<const std::uint32_t*>(
             static_cast<std::uint8_t*>(component) + 0x98) & 4u) == 0)
        return 1;
    return 0;
}

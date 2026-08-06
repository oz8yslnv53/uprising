#include <cstdint>
extern "C" void* ResolveCachedComponent_1EC(void* object);
extern "C" __attribute__((noinline)) int
CachedComponent_HasFlag40000(void* object) {
    if (object == 0) {
        return 0;
    }
    const std::uint8_t* component = static_cast<const std::uint8_t*>(
        ResolveCachedComponent_1EC(object));
    return component != 0 &&
           ((*reinterpret_cast<const std::uint32_t*>(component + 0x94) & 0x40000u) != 0);
}

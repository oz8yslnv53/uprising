#include <cstdint>
extern "C" void* Engine_LazyFactoryRegistryGetter_0049BF28(void);
extern "C" void* DAT_00D63560;
extern "C" int ResourceRegistry_HasCategoryKey_0027548C(
    const void* registry, std::uint32_t type, std::uint32_t key);
extern "C" __attribute__((noinline)) int
Resource_QueryLoaded_0025EBCC(void* unused_context, int mode,
                              std::uint32_t key) {
    (void)unused_context;
    if (DAT_00D63560 == 0)
        DAT_00D63560 = Engine_LazyFactoryRegistryGetter_0049BF28();
    const std::uint32_t packed_key =
        key | (static_cast<std::uint32_t>(mode) << 16);
    return ResourceRegistry_HasCategoryKey_0027548C(
               DAT_00D63560, 0x11, packed_key) != 0;
}

#include <cstdint>
extern "C" void* Engine_LazyFactoryRegistryGetter_0049BF28(void);
extern "C" void* DAT_00D63560;
extern "C" int FUN_0022d664(void* resource, std::uint32_t type,
                              std::uint32_t key);
extern "C" __attribute__((noinline)) int
Resource_QueryState_0025E884(void* unused_a, void* unused_b,
                             std::uint32_t key) {
    (void)unused_a;
    (void)unused_b;
    if (DAT_00D63560 == 0)
        DAT_00D63560 = Engine_LazyFactoryRegistryGetter_0049BF28();
    return FUN_0022d664(DAT_00D63560, 0x11, key) != 0;
}

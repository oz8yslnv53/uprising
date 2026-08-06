#include <cstdint>
extern "C" void* Engine_LazyFactoryRegistryGetter_0049BF28(void);
extern "C" void* DAT_00D63560;
extern "C" int FUN_0027537c(void* registry, std::uint32_t type,
                              std::uint32_t key);
extern "C" __attribute__((noinline)) int
Resource_QueryReady_0025E7FC(void* unused_context, int mode,
                             std::uint32_t key) {
    (void)unused_context;
    if (DAT_00D63560 == 0)
        DAT_00D63560 = Engine_LazyFactoryRegistryGetter_0049BF28();
    std::uint32_t type = 0;
    if (mode == 1) {
        type = 1;
    } else if (mode == 2) {
        type = 2;
    }
    return FUN_0027537c(DAT_00D63560, type, key) != 0;
}

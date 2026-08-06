#include <cstdint>
extern "C" void* Engine_LazySingletonGetter_00422CC8(void);
extern "C" __attribute__((noinline)) int
Engine_GlobalModeByteIsZero(void) {
    static void* singleton;
    if (singleton == 0) {
        singleton = Engine_LazySingletonGetter_00422CC8();
    }
    return *reinterpret_cast<const std::uint8_t*>(
               static_cast<const std::uint8_t*>(singleton) + 0x1efd) == 0;
}

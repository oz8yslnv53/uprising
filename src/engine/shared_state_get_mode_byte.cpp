#include <cstdint>
extern "C" void* Engine_LazySingletonGetter_003B6C98(void);
extern "C" void* DAT_00D63588;
extern "C" __attribute__((noinline)) int
SharedState_GetModeByte_00350ECC(void* unused) {
    (void)unused;
    if (DAT_00D63588 == 0)
        DAT_00D63588 = Engine_LazySingletonGetter_003B6C98();
    return *reinterpret_cast<const std::int8_t*>(
        static_cast<const std::uint8_t*>(DAT_00D63588) + 0x3EE);
}

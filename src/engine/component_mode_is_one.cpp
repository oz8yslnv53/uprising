#include <cstdint>
extern "C" void *Engine_LazySingletonGetter_00422CC8(void);
extern "C" __attribute__((noinline)) int Engine_ComponentModeIsOne(void)
{
    void** slot = reinterpret_cast<void**>(0x00d636e0u);
    void*component = *slot;
    if (component == 0) {
        component = Engine_LazySingletonGetter_00422CC8();
        *slot = component;
    }
    return *reinterpret_cast<const std::uint8_t *>(
               static_cast<const std::uint8_t *>(component) + 0x1efd) == 1
        ? 1
        : 0;
}

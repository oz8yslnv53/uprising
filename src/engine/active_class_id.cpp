#include <cstdint>
extern "C" void *FUN_004EE6EC(void);
extern "C" __attribute__((noinline)) int Engine_ActiveClassId_004EAF40(void)
{
    std::uint8_t* active = static_cast<std::uint8_t*>(FUN_004EE6EC());
    return active == 0
        ? 0x1f
        : static_cast<int>(*reinterpret_cast<std::int8_t *>(active + 0x2d));
}

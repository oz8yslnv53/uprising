#include <cstdint>
extern "C" __attribute__((noinline)) std::uint32_t Object_GetAllocatorContext(void* object)
{
    const std::uint8_t* allocator = *reinterpret_cast<const std::uint8_t**>(
        static_cast<std::uint8_t*>(object) + 0x154);
    return *reinterpret_cast<const std::uint32_t*>(allocator + 0x10);
}

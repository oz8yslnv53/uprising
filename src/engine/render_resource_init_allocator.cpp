#include <cstdint>
extern "C" void* RenderResource_GetAllocator_00BA892C(void* record);
extern "C" __attribute__((noinline)) void*
RenderResource_InitAllocator_0090E2E0(void* record) {
    std::uint8_t* allocator = static_cast<std::uint8_t*>(
        RenderResource_GetAllocator_00BA892C(record));
    *reinterpret_cast<std::uint32_t*>(allocator + 0x64) = 0;
    return allocator;
}

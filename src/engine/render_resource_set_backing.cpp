#include <cstdint>
extern "C" std::uint32_t RenderResource_CalculateBackingSize_00909A4C(
    std::uint32_t record_count);
extern "C" void* Engine_AllocateTaggedBlock(
    std::uint32_t element_size, void* type_tag, std::uint32_t allocator);
extern "C" void* RenderResource_InitBackingRecord_00909A3C(
    void* backing, std::uint32_t record_count);
extern "C" __attribute__((noinline)) void RenderResource_SetBacking_0090E2A0(
    void* resource, std::uint32_t allocator, std::uint32_t record_count) {
    const std::uint32_t size =
        RenderResource_CalculateBackingSize_00909A4C(record_count);
    void* backing = Engine_AllocateTaggedBlock(
        size, reinterpret_cast<void*>(0x0090e2dc), allocator);
    void* initialized =
        RenderResource_InitBackingRecord_00909A3C(backing, record_count);
    std::uint8_t* bytes = static_cast<std::uint8_t*>(resource);
    *reinterpret_cast<void**>(bytes + 0x44) = initialized;
    *reinterpret_cast<void**>(bytes + 0x64) = backing;
}

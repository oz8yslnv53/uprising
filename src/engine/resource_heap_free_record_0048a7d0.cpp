#include <cstdint>
extern "C" void ResourceHeap_RecordRelease_0048A818(void* record);
extern "C" __attribute__((noinline)) void ResourceHeap_FreeRecord_0048A7D0(void* record) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(record);
    ResourceHeap_RecordRelease_0048A818(bytes + 0x18);
    --*reinterpret_cast<std::int32_t*>(bytes + 0x54);
}

#include <cstdint>
extern "C" void ResourceBatch_RecordReset_00489640(std::uint32_t *record);
extern "C" __attribute__((noinline)) void ResourceBatch_SlotReset_00461804(void *slot)
{
    std::uint8_t* bytes = static_cast<std::uint8_t*>(slot);
    for (int i = 0; i < 5; ++i)
        ResourceBatch_RecordReset_00489640(
            reinterpret_cast<std::uint32_t *>(bytes + 4 + i * 0x80));
}

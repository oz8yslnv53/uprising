#include <cstdint>
extern "C" void MemoryZeroEnd_003DC5D0(void *destination, unsigned int size);
extern "C" __attribute__((noinline)) void ResourceState_CopyPackedValues_002FB618(
    void *destination, const std::int16_t *values, unsigned int count)
{
    std::uint32_t* counts = static_cast<std::uint32_t*>(destination);
    MemoryZeroEnd_003DC5D0(destination, 0x344);
    unsigned int index = count == 0 ? 0 : count & 1u;
    if (index == 1)
        ++counts[values[0]];
    for (; index < count; index += 2) {
        ++counts[values[index]];
        ++counts[values[index + 1]];
    }
}

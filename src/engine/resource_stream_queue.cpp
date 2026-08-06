#include <cstdint>
extern "C" void StateResource_Notify_003D1B1C(void* resource);
extern "C" void StateResource_NotifyLoaded_003ABB48(void* resource);
extern "C" std::uint32_t ResourceStream_ComputeBaseOffset_005FA32C(
    void* queue, std::uint32_t selected);
extern "C" std::uint32_t ResourceStream_ComputeHalfStrideOffset_005FA340(
    void* queue, std::uint32_t selected);
extern "C" std::uint8_t g_ResourceStreamQueueLock_00DF0730[];
extern "C" __attribute__((noinline)) int ResourceStream_GetCurrentDescriptor_00B8BB1C(
    void* stream, std::uint32_t* output) {
    std::uint8_t* queue = *reinterpret_cast<std::uint8_t**>(
        static_cast<std::uint8_t*>(stream) + 4);
    if (queue == 0)
        return 0;
    StateResource_Notify_003D1B1C(g_ResourceStreamQueueLock_00DF0730);
    if (*reinterpret_cast<std::uint32_t*>(queue + 0x38) == 0) {
        StateResource_NotifyLoaded_003ABB48(
            g_ResourceStreamQueueLock_00DF0730);
        return 0;
    }
    const std::uint32_t index =
        *reinterpret_cast<std::uint32_t*>(queue + 0x34);
    const std::uint32_t selected = (*reinterpret_cast<std::uint32_t**>(
        queue + 0x28))[index];
    output[0] = selected;
    output[1] = ResourceStream_ComputeBaseOffset_005FA32C(queue, selected);
    output[2] =
        ResourceStream_ComputeHalfStrideOffset_005FA340(queue, selected);
    output[3] = *reinterpret_cast<std::uint32_t*>(queue + 0x18);
    output[4] = *reinterpret_cast<std::uint32_t*>(queue + 0x18);
    output[5] = *reinterpret_cast<std::uint32_t*>(queue + 0x18);
    output[6] = *reinterpret_cast<std::uint32_t*>(queue + 0x20);
    output[7] = *reinterpret_cast<std::uint32_t*>(queue + 0x24);
    const std::uint32_t indexed_value = (*reinterpret_cast<std::uint32_t**>(
        queue + 0x2C))[index];
    output[8] = indexed_value;
    output[9] = indexed_value;
    output[10] = 1;
    StateResource_NotifyLoaded_003ABB48(g_ResourceStreamQueueLock_00DF0730);
    return 1;
}
extern "C" __attribute__((noinline)) int ResourceStream_Advance_00B8BC58(void* stream) {
    std::uint8_t* queue = *reinterpret_cast<std::uint8_t**>(
        static_cast<std::uint8_t*>(stream) + 4);
    if (queue == 0)
        return 0;
    StateResource_Notify_003D1B1C(g_ResourceStreamQueueLock_00DF0730);
    std::uint32_t* pending = reinterpret_cast<std::uint32_t*>(queue + 0x38);
    if (*pending == 0) {
        StateResource_NotifyLoaded_003ABB48(
            g_ResourceStreamQueueLock_00DF0730);
        return 0;
    }
    std::uint32_t* index = reinterpret_cast<std::uint32_t*>(queue + 0x34);
    ++*index;
    if (*index == *reinterpret_cast<std::uint32_t*>(queue + 8))
        *index = 0;
    --*pending;
    StateResource_NotifyLoaded_003ABB48(g_ResourceStreamQueueLock_00DF0730);
    return 1;
}
// Retail 0x005FA32C: selected + stride * descriptor word 2.
extern "C" __attribute__((noinline)) std::uint32_t ResourceStream_ComputeBaseOffset_005FA32C(
    void* queue, std::uint32_t selected) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(queue);
    std::uint32_t* descriptor = *reinterpret_cast<std::uint32_t**>(bytes);
    const std::uint32_t stride =
        *reinterpret_cast<std::uint32_t*>(bytes + 0x18);
    return stride * descriptor[2] + selected;
}
// Retail 0x005FA340: the same offset plus half a stride.
extern "C" __attribute__((noinline)) std::uint32_t ResourceStream_ComputeHalfStrideOffset_005FA340(
    void* queue, std::uint32_t selected) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(queue);
    std::uint32_t* descriptor = *reinterpret_cast<std::uint32_t**>(bytes);
    const std::uint32_t stride =
        *reinterpret_cast<std::uint32_t*>(bytes + 0x18);
    return stride * descriptor[2] + selected + (stride >> 1);
}

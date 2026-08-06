#include <cstdint>
extern "C" void StateResource_WorkQueueAppend_0021FC28(
    void* object, void* work_record);
extern "C" __attribute__((noinline)) void StateResource_QueueRecord_00259984(
    void* table, std::uint32_t index, void* work_record,
    std::uint32_t publish) {
    std::uint8_t* entries = static_cast<std::uint8_t*>(table);
    std::uint8_t* record = static_cast<std::uint8_t*>(work_record);
    void* object = *reinterpret_cast<void**>(entries + index * 4u);
    StateResource_WorkQueueAppend_0021FC28(object, record);
    if (publish != 0u)
        *reinterpret_cast<void**>(entries + 0x1Cu) = record;
}

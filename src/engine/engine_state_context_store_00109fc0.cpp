#include <stdint.h>
extern "C" __attribute__((noinline)) void Engine_StateContextStore_00109FC0(
    void* object, uint32_t first, uint32_t second,
    uint32_t third, uint32_t fourth, uint32_t fifth) {
    uint8_t* bytes = static_cast<uint8_t*>(object);
    *reinterpret_cast<uint32_t*>(bytes + 0x1e60) = first;
    *reinterpret_cast<uint32_t*>(bytes + 0x1e64) = second;
    *reinterpret_cast<uint32_t*>(bytes + 0x1e68) = third;
    *reinterpret_cast<uint32_t*>(bytes + 0x1e6c) = fourth;
    *reinterpret_cast<uint32_t*>(bytes + 0x1e74) = fifth;
}

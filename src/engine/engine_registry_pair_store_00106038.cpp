// Retail 0x00106038: store the two registration-context words.
#include <stdint.h>
extern "C" __attribute__((noinline)) void Engine_RegistryPairStore_00106038(
    void* object, uint32_t first, uint32_t second) {
    uint8_t* bytes = static_cast<uint8_t*>(object);
    *reinterpret_cast<uint32_t*>(bytes + 0xc0) = first;
    *reinterpret_cast<uint32_t*>(bytes + 0xc4) = second;
}

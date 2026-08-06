#include <cstdint>
extern "C" void ResourceReference_Release_00474668(void *reference);
extern "C" __attribute__((noinline)) std::uint32_t *StateResource_ReleaseSlot_005788E4(
    std::uint32_t *slot) {
    ResourceReference_Release_00474668(
        reinterpret_cast<void *>(*slot));
    return slot;
}
extern "C" __attribute__((noinline)) void *StateHandle_GetPayloadField_005796E0(void *handle) {
    std::uint8_t* payload = *reinterpret_cast<std::uint8_t**>(
        static_cast<std::uint8_t *>(handle) + 4);
    return payload ? payload + 0x2c : 0;
}

#include <cstdint>
extern "C" bool DeferredResource_IsReady_00B1E6D4(void *resource);
extern "C" __attribute__((noinline)) bool SceneSetting_DeferredResourceGate_IsClear_00A62F9C(void *state)
{
    const std::uint8_t* bytes = static_cast<const std::uint8_t*>(state);
    void*resource = *reinterpret_cast<void *const *>(bytes + 0xbc);
    if (resource != 0 && !DeferredResource_IsReady_00B1E6D4(resource))
        return false;
    void*record = *reinterpret_cast<void *const *>(bytes + 0x1c0);
    return record == 0 ||
           (static_cast<const std::uint8_t *>(record)[0x0a] == 0 &&
            static_cast<const std::uint8_t *>(record)[0x0b] == 0);
}

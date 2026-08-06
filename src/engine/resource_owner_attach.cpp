#include <cstdint>
extern "C" void* Engine_SharedResourceSingleton_00422D20();
extern "C" void* cached_ordered_tree_resolver(void* object);
extern "C" void* FUN_003F552C(void* owner, std::uint32_t slot);
extern "C" __attribute__((noinline)) void* Resource_OwnerAttach_00489A54(
    void*, void* object, std::uint32_t slot) {
    void** shared_slot = reinterpret_cast<void**>(0x00d637ec);
    if (*shared_slot == 0) {
        *shared_slot = Engine_SharedResourceSingleton_00422D20();
    }
    std::uint8_t* record =
        static_cast<std::uint8_t*>(cached_ordered_tree_resolver(object));
    void* resource = *reinterpret_cast<void**>(record + 0x24);
    if (resource == 0) {
        return 0;
    }
    record = static_cast<std::uint8_t*>(
        cached_ordered_tree_resolver(object));
    return FUN_003F552C(
        *reinterpret_cast<void**>(
            *reinterpret_cast<std::uint8_t**>(record + 0x24) + 0xb0),
        slot);
}

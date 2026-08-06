#include <cstddef>
#include <cstdint>
namespace {
struct SceneResourceCollection {
    void* vtable;
    std::uint8_t opaque_04[4];
    void* context;
    std::uint8_t opaque_0c[8];
    void** begin;
    void** end;
};
#if __cplusplus >= 201103L
typedef char kiu_sa_scene_resource_collection_1[(offsetof(SceneResourceCollection, context) == 0x08) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_scene_resource_collection_2[(offsetof(SceneResourceCollection, begin) == 0x14) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_scene_resource_collection_3[(offsetof(SceneResourceCollection, end) == 0x18) ? 1 : -1] __attribute__((unused));
#endif
typedef void (*InvokeEntry)(void*);
typedef std::uint32_t (*QueryEntry)(void*, void*);
}  // namespace
extern "C" __attribute__((noinline)) void SceneResourceCollection_InvokeEntrySlot14_008D9440(
    SceneResourceCollection* collection) {
    std::int32_t index = 0;
    if (index >= collection->end - collection->begin)
        return;
    do {
        void* entry = collection->begin[index];
        if (entry != 0)
            reinterpret_cast<InvokeEntry>(
                (*static_cast<void***>(entry))[5])(entry);
        ++index;
    } while (index < collection->end - collection->begin);
}
extern "C" __attribute__((noinline)) std::uint32_t SceneResourceCollection_SetContext_008D9498(
    SceneResourceCollection* collection, void* context) {
    collection->context = context;
    return 0;
}
extern "C" __attribute__((noinline)) std::uint32_t SceneResourceCollection_AnyEntrySlot1C_00B3BD58(
    SceneResourceCollection* collection, void* argument) {
    std::int32_t index = 0;
    if (index < collection->end - collection->begin) {
      do {
        void* entry = collection->begin[index];
        if (entry != 0) {
            if (reinterpret_cast<QueryEntry>(
                    (*static_cast<void***>(entry))[7])(entry, argument) != 0)
                return 1;
        }
        ++index;
      } while (index < collection->end - collection->begin);
    }
    return 0;
}

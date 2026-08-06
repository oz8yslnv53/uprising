#include <stdint.h>
#include <stddef.h>
extern "C" __attribute__((noinline)) void RenderResourcePool_Clear_003DC5D0(void* destination,
                                                    uint32_t size) {
    uint8_t* bytes = static_cast<uint8_t*>(destination);
    for (uint32_t i = 0; i < size; ++i)
        bytes[i] = 0;
}
typedef void (*RenderResourceFirstMethod)(void*);
typedef void (*RenderResourceCompanionMethod)(void*, void*);
static void RenderResource_ClearObject(void* object) {
    void** vtable = *reinterpret_cast<void***>(object);
    reinterpret_cast<RenderResourceFirstMethod>(vtable[0])(object);
    uint8_t* companion = *reinterpret_cast<uint8_t**>(
        static_cast<uint8_t*>(object) + 4);
    void** companion_vtable = *reinterpret_cast<void***>(companion);
    reinterpret_cast<RenderResourceCompanionMethod>(companion_vtable[3])(
        companion, object);
}
struct RenderResourcePoolOwnerView {
    void* pool;
    uint32_t initialized;
};
typedef char kiu_sa_render_resource_initialize_1[(sizeof(RenderResourcePoolOwnerView) == 8) ? 1 : -1] __attribute__((unused));
struct RenderResourcePoolBaseView {
    uint8_t opaque_0000_to_07ff[0x800];
    void* resource_block;
};
typedef char kiu_sa_render_resource_initialize_2[(offsetof(RenderResourcePoolBaseView, resource_block) == 0x800) ? 1 : -1] __attribute__((unused));
struct RenderResourcePoolBlockOpaque {
    uint8_t bytes[0x278];
};
typedef char kiu_sa_render_resource_initialize_3[(sizeof(RenderResourcePoolBlockOpaque) == 0x278) ? 1 : -1] __attribute__((unused));
extern "C" void* ResourceRegistry_FindForPath_004156B0(void* path,
                                                         void* same_path);
extern "C" void* ResourceRegistry_FindMode_004B2134(void* mode,
                                                     void* path);
extern "C" void* RenderResource_GetIndexedRecord_003AF054(
    void* owner, uint32_t index);
extern "C" void RenderResource_ClearChildren_003AD60C(void* record);
extern "C" int* RenderResource_BuildDefaultChild_0038F6D0(
    void* temporary_record, void* allocator_context);
extern "C" void RenderResource_FinalizeDefaultChild_0038FAB0(
    void* temporary_record);
extern "C" void RenderResource_ClearBindings_003AD3B0(void* record);
extern "C" void RenderResource_ClearSlots_003AD2E0(void* record);
extern "C" void RenderResource_BuildParameters_00416130(
    void* record, void* resource, void* resolved, void* child);
extern "C" void RenderResource_BuildEntries_00415970(
    void* record, void* resource, void* resolved, void* child);
extern "C" void RenderResource_BuildLinks_004156F0(
    void* record, void* resource, void* resolved, void* child);
struct RenderResourceIndexedView {
    uint8_t opaque_0000_to_0143[0x144];
    uint32_t record_mask;
    uint8_t entries[6][0x20];
};
typedef char kiu_sa_render_resource_initialize_4[(offsetof(RenderResourceIndexedView, record_mask) == 0x144) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_render_resource_initialize_5[(offsetof(RenderResourceIndexedView, entries) == 0x148) ? 1 : -1] __attribute__((unused));
extern "C" void RenderResourcePool_Clear_003DC5D0(void* bytes,
                                                    uint32_t size);
extern "C" __attribute__((noinline)) void RenderResource_ClearChildren_003AD60C(void* record) {
    uint8_t* bytes = static_cast<uint8_t*>(record);
    if (*reinterpret_cast<const uint8_t*>(bytes + 0x190) == 0)
        return;
    for (uint32_t index = 0; index != 0x20; ++index) {
        void* child = *reinterpret_cast<void**>(bytes + 8 + index * 4);
        if (child != 0) {
            uint8_t* slot = *reinterpret_cast<uint8_t**>(
                static_cast<uint8_t*>(child) + 0x28);
            if (slot != 0) {
                uint8_t* table = *reinterpret_cast<uint8_t**>(slot + 0x1c);
                void* nested = *reinterpret_cast<void**>(table);
                if (nested != 0)
                    RenderResource_ClearObject(nested);
            }
            RenderResource_ClearObject(child);
        }
        *reinterpret_cast<void**>(bytes + 8 + index * 4) = 0;
    }
    uint8_t temporary[0x24] = {0};
    temporary[0x00] = 1;
    temporary[0x01] = 1;
    temporary[0x0c] = 1;
    temporary[0x14] = 1;
    temporary[0x1c] = 1;
    void* owner = *reinterpret_cast<void**>(bytes + 0x00);
    void* allocator_context = *reinterpret_cast<void**>(
        static_cast<uint8_t*>(owner) + 0x40);
    int* replacement = RenderResource_BuildDefaultChild_0038F6D0(
        temporary, allocator_context);
    *reinterpret_cast<void**>(bytes + 8) = replacement;
    RenderResource_FinalizeDefaultChild_0038FAB0(temporary);
}
extern "C" __attribute__((noinline)) void* RenderResourcePool_CreateBlock_0018C024(void) {
    typedef void*(*Allocate)(uint32_t, uint32_t,
                               uint32_t, uint32_t);
    Allocate* callback_slot = reinterpret_cast<Allocate*>(0x00D4D45Cu);
    uint8_t* block = 0;
    if (*callback_slot != 0) {
        block = static_cast<uint8_t*>((*callback_slot)(
            0x10000u, 0x100u, 0, 0x278u));
        if (block != 0) {
            RenderResourcePool_Clear_003DC5D0(block, 0x278u);
            const uint32_t record_tag = 0x1406u;
            for (uint32_t i = 0; i != 12; ++i) {
                uint8_t* stride18 = block + i * 0x18u;
                *reinterpret_cast<uint32_t*>(stride18 + 0x04) = 4;
                *reinterpret_cast<uint32_t*>(stride18 + 0x08) = record_tag;
                uint8_t* stride10 = block + i * 0x10u;
                *reinterpret_cast<float*>(stride10 + 0x128) = 0.0f;
                *reinterpret_cast<float*>(stride10 + 0x12c) = 0.0f;
                *reinterpret_cast<float*>(stride10 + 0x130) = 0.0f;
                *reinterpret_cast<float*>(stride10 + 0x134) = 1.0f;
                uint8_t* stride0c = block + i * 0x0cu;
                *reinterpret_cast<uint32_t*>(stride0c + 0x1e8) = 0x3f000000u;
                *reinterpret_cast<uint32_t*>(stride0c + 0x1ec) = 0;
                *reinterpret_cast<uint32_t*>(stride0c + 0x1f0) = 0;
            }
        }
    }
    return block;
}
extern "C" __attribute__((noinline)) void* RenderResource_SelectIndexedRecord_00AA0F80(
    void* record, uint32_t index) {
    if (index >= 6)
        return 0;
    RenderResourceIndexedView* view = static_cast<RenderResourceIndexedView*>(record);
    if ((view->record_mask & (1u << index)) == 0)
        return 0;
    return view->entries[index];
}
extern "C" __attribute__((noinline)) int RenderResourcePool_Initialize_001684DC(void* pool) {
    RenderResourcePoolOwnerView* owner = *reinterpret_cast<RenderResourcePoolOwnerView**>(
        0x00168544u);
    owner->pool = pool;
    RenderResourcePool_Clear_003DC5D0(pool, 0x844u);
    void* block = RenderResourcePool_CreateBlock_0018C024();
    static_cast<RenderResourcePoolBaseView*>(pool)->resource_block = block;
    if (block != 0) {
        owner->initialized = 1;
        return 0;
    }
    void (**failure_callback)(uint32_t, uint32_t, uint32_t) =
        reinterpret_cast<void (**)(uint32_t,
                                                          uint32_t,
                                                          uint32_t)>(
        0x0016854Cu);
    if (*failure_callback != 0)
        (*failure_callback)(0x10000u, 0x100u, 0);
    owner->pool = 0;
    return -1;
}
extern "C" __attribute__((noinline)) void RenderResource_InitializeRecord_003AD254(
    void* record_object, void* resource, void* resolved, void* child_pointer) {
    uint8_t* record = static_cast<uint8_t*>(record_object);
    RenderResource_ClearChildren_003AD60C(record);
    RenderResource_ClearBindings_003AD3B0(record);
    RenderResource_ClearSlots_003AD2E0(record);
    *reinterpret_cast<uint8_t*>(record + 0x190) = 0;
    *reinterpret_cast<uint32_t*>(record + 0x184) = 0;
    *reinterpret_cast<uint32_t*>(record + 0x188) = 0;
    *reinterpret_cast<uint32_t*>(record + 0x18c) = 0;
    RenderResource_BuildParameters_00416130(
        record, resource, resolved, child_pointer);
    RenderResource_BuildEntries_00415970(
        record, resource, resolved, child_pointer);
    RenderResource_BuildLinks_004156F0(
        record, resource, resolved, child_pointer);
    *reinterpret_cast<uint8_t*>(record + 0x190) = 1;
}
extern "C" __attribute__((noinline)) void RenderResource_InitializeIndexed_003EE100(
    void** owner, void* mode, void* path, void* resource,
    uint32_t record_index, int32_t child_index) {
    void* resolved = mode == 0
                         ? ResourceRegistry_FindForPath_004156B0(path, path)
                         : ResourceRegistry_FindMode_004B2134(mode, path);
    uint8_t* record = static_cast<uint8_t*>(
        RenderResource_GetIndexedRecord_003AF054(*owner, record_index));
    if (record == 0)
        return;
    const int32_t child = child_index + 1;
    const int32_t count =
        *reinterpret_cast<const int32_t*>(record + 0x5c);
    if (child > count)
        return;
    uint8_t* table = record + 0x60;
    const int32_t table_offset =
        *reinterpret_cast<const int32_t*>(table);
    if (table_offset != 0)
        table += table_offset;
    else
        table = 0;
    if (table == 0)
        return;
    uint8_t* slot = table + child_index * 0x10 + 0x28;
    const int32_t slot_offset =
        *reinterpret_cast<const int32_t*>(slot);
    if (slot_offset == 0)
        return;
    void* child_pointer = slot + slot_offset;
    RenderResource_InitializeRecord_003AD254(
        record, resource, resolved, child_pointer);
}

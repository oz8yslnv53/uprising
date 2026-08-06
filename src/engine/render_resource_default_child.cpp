#include <cstddef>
#include <cstdint>
#include "engine_common_views.h"
typedef void*(*Allocate)(void*, std::uint32_t, std::uint32_t);
struct AllocatorVtableView {
    void* opaque_00;
    void* opaque_04;
    Allocate allocate;
};
struct AllocatorView {
    AllocatorVtableView* vtable;
};
struct OpaqueOwnedPointer {
    void* pointer;
    std::uint8_t owned;
    std::uint8_t opaque_05[3];
};
struct DefaultChildDescriptorView {
    std::uint8_t opaque_00[0x10];
    OpaqueOwnedPointer first;
    OpaqueOwnedPointer second;
};
struct OpaqueDefaultChildSource {
    std::uint32_t signature_000;
    std::uint32_t signature_004;
    std::uint32_t version_008;
    std::uint8_t opaque_00c[0x0c];
    std::uint32_t flags_018;
    std::uint8_t opaque_01c[0x14];
    float opaque_030;
    float opaque_034;
    float opaque_038;
    std::uint8_t opaque_03c[0x18];
    std::uint8_t matrix_054[0x30];
    std::uint8_t matrix_084[0x30];
    std::uint32_t first_mode_0b4;
    std::uint32_t second_mode_0b8;
    std::int32_t relative_first_0bc;
    std::int32_t relative_second_0c0;
    std::uint8_t opaque_0c4[4];
};
struct OpaqueDefaultChildObject {
    std::uint32_t implementation_000;
    std::uint8_t opaque_004[4];
    OpaqueDefaultChildSource* source_008;
    std::uint8_t opaque_00c[0x1c];
    void* publication_028;
    std::uint8_t opaque_02c[0x20];
    std::uint8_t opaque_04c[0xfc];
    std::uint8_t matrix_148[0x30];
    std::uint8_t matrix_178[0x30];
    std::uint8_t matrix_1a8[0x40];
    std::uint8_t matrix_1e8[0x40];
    std::uint8_t matrix_228[0x30];
    std::uint8_t opaque_258[0x30];
    OpaqueOwnedPointer first_288;
    OpaqueOwnedPointer second_290;
    EngineResourceObjectView* resource_object_298;
    OpaqueDefaultChildSource* cloned_source_29c;
    std::uint32_t source_words_030_2a0[9];
    float opaque_2c4;
    std::uint8_t opaque_2c8;
    std::uint8_t opaque_2c9[3];
};
struct OpaquePublicationView {
    std::uint8_t opaque_000[0x0c];
    void** output_00c;
};
typedef char kiu_sa_render_resource_default_child_1[(sizeof(OpaqueOwnedPointer) == 8) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_render_resource_default_child_2[(sizeof(DefaultChildDescriptorView) == 0x20) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_render_resource_default_child_3[(offsetof(OpaqueDefaultChildSource, matrix_054) == 0x54) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_render_resource_default_child_4[(offsetof(OpaqueDefaultChildSource, relative_first_0bc) == 0xbc) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_render_resource_default_child_5[(sizeof(OpaqueDefaultChildSource) == 0xc8) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_render_resource_default_child_6[(offsetof(OpaqueDefaultChildObject, source_008) == 0x08) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_render_resource_default_child_7[(offsetof(OpaqueDefaultChildObject, publication_028) == 0x28) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_render_resource_default_child_8[(offsetof(OpaqueDefaultChildObject, matrix_148) == 0x148) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_render_resource_default_child_9[(offsetof(OpaqueDefaultChildObject, first_288) == 0x288) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_render_resource_default_child_10[(offsetof(OpaqueDefaultChildObject, resource_object_298) == 0x298) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_render_resource_default_child_11[(offsetof(OpaqueDefaultChildObject, cloned_source_29c) == 0x29c) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_render_resource_default_child_12[(offsetof(OpaqueDefaultChildObject, source_words_030_2a0) == 0x2a0) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_render_resource_default_child_13[(sizeof(OpaqueDefaultChildObject) == 0x2cc) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_render_resource_default_child_14[(offsetof(OpaquePublicationView, output_00c) == 0x0c) ? 1 : -1] __attribute__((unused));
extern "C" void* FUN_003D34D4(AllocatorView*);
extern "C" void* FUN_003D35AC(AllocatorView*);
extern "C" void* FUN_004B0660(
    void*, void*, void*, const std::uint32_t*);
extern "C" void* FUN_004388F4();
extern "C" float* Matrix4x4_Identity_004624B8();
extern "C" void Matrix3x4_Copy_0044C0A0(void*, const void*);
extern "C" void Matrix4x4_Copy_003FDA38(void*, const void*);
extern "C" std::uint32_t ResourcePrerequisite_008E0B80(
    void*, void*);
extern "C" void ResourceObject_Initialize_008FD77C(
    void*, void*, void*, void*);
extern "C" std::uint32_t ResourceObject_MaterializeSpans_008FC988(
    void*, bool);
extern "C" void* ResourceObject_Finalize_008FD830(void*);
namespace {
template <typename T>
T& at(void* object, std::size_t offset) {
    return *reinterpret_cast<T*>(
        static_cast<std::uint8_t*>(object) + offset);
}
void release_owned(OpaqueOwnedPointer& owner) {
    if (owner.pointer == 0 || owner.owned == 0)
        return;
    void** vtable = *static_cast<void***>(owner.pointer);
    reinterpret_cast<void (*)(void*)>(vtable[0])(owner.pointer);
    void* allocator = at<void*>(owner.pointer, 4);
    void** allocator_vtable = *static_cast<void***>(allocator);
    reinterpret_cast<void (*)(void*, void*)>(
        allocator_vtable[3])(allocator, owner.pointer);
}
void transfer_owned(
    OpaqueOwnedPointer& destination,
    OpaqueOwnedPointer& source) {
    destination = source;
    source.pointer = 0;
}
template <typename T>
T* resolve_relative(std::int32_t* relative) {
    return *relative == 0
               ? 0
               : reinterpret_cast<T*>(
                     reinterpret_cast<std::uint8_t*>(relative) + *relative);
}
template <typename T>
const T* resolve_relative(const std::int32_t* relative) {
    return *relative == 0
               ? 0
               : reinterpret_cast<const T*>(
                     reinterpret_cast<const std::uint8_t*>(relative) +
                     *relative);
}
void copy_words(void* destination, const void* source, std::uint32_t size) {
    std::uint32_t* output = static_cast<std::uint32_t*>(destination);
    const std::uint32_t* input =
        static_cast<const std::uint32_t*>(source);
    for (std::uint32_t index = 0; index != size >> 2; ++index)
        output[index] = input[index];
}
void* clone_relative_record(
    AllocatorView* allocator, const std::int32_t* relative,
    std::uint32_t size) {
    const void* source = resolve_relative<void>(relative);
    void* clone = allocator->vtable->allocate(allocator, size, 4);
    if (clone != 0)
        copy_words(clone, source, size);
    return clone;
}
}  // namespace
extern "C" __attribute__((noinline)) void* OpaqueComponent_Value0C_008ED548(void* component) {
    return at<void*>(component, 0x0c);
}
extern "C" __attribute__((noinline)) void* OpaqueComponent_Value1C_008EF8C4(void* component) {
    return at<void*>(component, 0x1c);
}
extern "C" __attribute__((noinline)) void*
FUN_00439B08(
    void* storage, void* allocator, void* source,
    const std::uint32_t* configuration,
    OpaqueOwnedPointer* first, OpaqueOwnedPointer* second,
    float value, std::uint8_t enabled) {
    OpaqueDefaultChildObject* object = static_cast<OpaqueDefaultChildObject*>(
        FUN_004B0660(storage, allocator, source, configuration));
    object->implementation_000 = 0x00d14fa4u;
    Matrix3x4_Copy_0044C0A0(object->matrix_148, FUN_004388F4());
    Matrix3x4_Copy_0044C0A0(object->matrix_178, FUN_004388F4());
    Matrix4x4_Copy_003FDA38(
        object->matrix_1a8, Matrix4x4_Identity_004624B8());
    Matrix4x4_Copy_003FDA38(
        object->matrix_1e8, Matrix4x4_Identity_004624B8());
    Matrix3x4_Copy_0044C0A0(object->matrix_228, FUN_004388F4());
    object->first_288 = *first;
    first->pointer = 0;
    object->second_290 = *second;
    second->pointer = 0;
    object->resource_object_298 = 0;
    object->cloned_source_29c = 0;
    object->opaque_2c4 = value;
    object->opaque_2c8 = enabled;
    return object;
}
extern "C" __attribute__((noinline)) std::uint32_t DefaultChildResource_CloneSource_008F8EE0(
    OpaqueDefaultChildObject* object, AllocatorView* allocator) {
    const OpaqueDefaultChildSource* source = object->source_008;
    OpaqueDefaultChildSource* clone =
        static_cast<OpaqueDefaultChildSource*>(
            allocator->vtable->allocate(allocator, 0xc8, 4));
    *clone = *source;
    Matrix3x4_Copy_0044C0A0(clone->matrix_054, source->matrix_054);
    Matrix3x4_Copy_0044C0A0(clone->matrix_084, source->matrix_084);
    clone->relative_first_0bc = 0;
    clone->relative_second_0c0 = 0;
    const std::uint32_t first_mode = source->first_mode_0b4 & 0xffu;
    const std::uint32_t first_size =
        first_mode == 0 ? 0x18u
                        : first_mode == 1 ? 0x20u
                                          : first_mode == 2 ? 0x14u : 0u;
    void* first = first_size == 0
                      ? 0
                      : clone_relative_record(
                            allocator, &source->relative_first_0bc,
                            first_size);
    clone->relative_first_0bc =
        first == 0
            ? 0
            : static_cast<std::int32_t>(
                  static_cast<std::uint8_t*>(first) -
                  reinterpret_cast<std::uint8_t*>(
                      &clone->relative_first_0bc));
    const std::uint32_t second_mode = source->second_mode_0b8 & 0xffu;
    const std::uint32_t second_size =
        second_mode == 0 ? 0x14u
                         : second_mode == 1 || second_mode == 2 ? 0x1cu : 0u;
    void* second = second_size == 0
                       ? 0
                       : clone_relative_record(
                             allocator, &source->relative_second_0c0,
                             second_size);
    clone->relative_second_0c0 =
        second == 0
            ? 0
            : static_cast<std::int32_t>(
                  static_cast<std::uint8_t*>(second) -
                  reinterpret_cast<std::uint8_t*>(
                      &clone->relative_second_0c0));
    object->cloned_source_29c = clone;
    const std::uint32_t* words =
        reinterpret_cast<const std::uint32_t*>(
            reinterpret_cast<const std::uint8_t*>(source) + 0x30);
    for (std::uint32_t index = 0; index != 9; ++index)
        object->source_words_030_2a0[index] = words[index];
    return 0;
}
extern "C" __attribute__((noinline)) std::uint32_t DefaultChildResource_BuildBindings_008F91F0(
    OpaqueDefaultChildObject* object, AllocatorView* allocator) {
    if (object->publication_028 == 0)
        return 0;
    const EngineRelativeResourceSourceView* source =
        reinterpret_cast<const EngineRelativeResourceSourceView*>(
            object->source_008);
    const EngineRelativeResourceIntermediateView* intermediate =
        resolve_relative<EngineRelativeResourceIntermediateView>(
            &source->relative_intermediate_02c);
    const EngineRelativeResourceContextView* context =
        intermediate == 0
            ? 0
            : resolve_relative<EngineRelativeResourceContextView>(
                  &intermediate->relative_context_028);
    EngineResourceObjectView* resource =
        static_cast<EngineResourceObjectView*>(
            allocator->vtable->allocate(allocator, 0x68, 4));
    if (resource == 0)
        return 0x80000000u;
    ResourceObject_Initialize_008FD77C(
        resource, const_cast<EngineRelativeResourceContextView*>(context),
        object, allocator);
    std::uint32_t status =
        ResourceObject_MaterializeSpans_008FC988(resource, true);
    if ((status & 0x80000000u) != 0) {
        ResourceObject_Finalize_008FD830(resource);
        void** vtable = *reinterpret_cast<void***>(allocator);
        reinterpret_cast<void (*)(void*, void*)>(
            vtable[3])(allocator, resource);
        return status;
    }
    object->resource_object_298 = resource;
    for (std::int32_t index = 0;
         context != 0 && index < context->entry_count_010; ++index) {
        const EngineRelativeResourceEntryTableView* table =
            resolve_relative<EngineRelativeResourceEntryTableView>(
                &context->relative_entry_table_014);
        const EngineRelativeResourceEntryView* entry =
            resolve_relative<EngineRelativeResourceEntryView>(
                &table->entries_028[index].relative_entry);
        void* base = 0;
        if (entry->kind_010 == 9)
            base = object;
        else if (entry->kind_010 == 10)
            base = OpaqueComponent_Value0C_008ED548(
                object->first_288.pointer);
        else if (entry->kind_010 == 11)
            base = OpaqueComponent_Value1C_008EF8C4(
                object->second_290.pointer);
        static_cast<void**>(resource->opaque_span_030.begin)[index] = base;
        static_cast<void**>(resource->opaque_span_040.begin)[index] =
            entry->kind_010 == 9 && entry->field_014 == 0
                ? object->opaque_04c
                : reinterpret_cast<void*>(
                      reinterpret_cast<std::uintptr_t>(base) +
                      entry->byte_offset_008);
        static_cast<void**>(resource->opaque_span_020.begin)[index] = 0;
        void* target = 0;
        if (entry->kind_010 == 9 && entry->field_014 == 0) {
            target = object->source_words_030_2a0;
        } else if (entry->kind_010 == 10) {
            target = resolve_relative<void>(
                &object->cloned_source_29c->relative_first_0bc);
        } else if (entry->kind_010 == 11) {
            target = resolve_relative<void>(
                &object->cloned_source_29c->relative_second_0c0);
        }
        static_cast<void**>(resource->opaque_span_050.begin)[index] =
            target == 0
                ? 0
                : reinterpret_cast<void*>(
                      reinterpret_cast<std::uintptr_t>(target) +
                      entry->byte_offset_008);
    }
    OpaquePublicationView* publication =
        static_cast<OpaquePublicationView*>(object->publication_028);
    *publication->output_00c = object->resource_object_298;
    return 0;
}
extern "C" __attribute__((noinline)) std::uint32_t DefaultChildResource_Initialize_008F8E98(
    OpaqueDefaultChildObject* object, AllocatorView* allocator) {
    std::uint32_t status =
        ResourcePrerequisite_008E0B80(object, allocator);
    if ((status & 0x80000000u) == 0) {
        status |= DefaultChildResource_CloneSource_008F8EE0(
            object, allocator);
        status |= DefaultChildResource_BuildBindings_008F91F0(
            object, allocator);
    }
    return status;
}
extern "C" __attribute__((noinline)) void*
RenderResource_BuildDefaultChild_0038F6D0(
    void* descriptor_storage, void* allocator_storage) {
    DefaultChildDescriptorView* descriptor = static_cast<DefaultChildDescriptorView*>(
            descriptor_storage);
    AllocatorView* allocator = static_cast<AllocatorView*>(allocator_storage);
    if (descriptor->first.pointer == 0) {
        OpaqueOwnedPointer replacement = {
            FUN_003D34D4(allocator), 1, {},
        };
        OpaqueOwnedPointer previous = descriptor->first;
        descriptor->first = replacement;
        release_owned(previous);
    }
    if (descriptor->second.pointer == 0) {
        OpaqueOwnedPointer replacement = {
            FUN_003D35AC(allocator), 1, {},
        };
        OpaqueOwnedPointer previous = descriptor->second;
        descriptor->second = replacement;
        release_owned(previous);
    }
    OpaqueDefaultChildSource* source = static_cast<OpaqueDefaultChildSource*>(
        allocator->vtable->allocate(allocator, 0xc8, 4));
    for (std::uint32_t i = 0; i != 0xc8; ++i)
        reinterpret_cast<std::uint8_t*>(source)[i] = 0;
    void* first_value =
        OpaqueComponent_Value0C_008ED548(descriptor->first.pointer);
    void* second_value =
        OpaqueComponent_Value1C_008EF8C4(descriptor->second.pointer);
    source->relative_first_0bc =
        first_value == 0
            ? 0
            : static_cast<std::uint8_t*>(first_value) -
                  reinterpret_cast<std::uint8_t*>(
                      &source->relative_first_0bc);
    source->relative_second_0c0 =
        second_value == 0
            ? 0
            : static_cast<std::uint8_t*>(second_value) -
                  reinterpret_cast<std::uint8_t*>(
                      &source->relative_second_0c0);
    const std::uint32_t first_mode =
        *static_cast<std::uint32_t*>(first_value);
    if (first_mode == 0x80000000u)
        source->first_mode_0b4 = 0;
    else if (first_mode == 0x20000000u)
        source->first_mode_0b4 = 2;
    else if (first_mode == 0x40000000u)
        source->first_mode_0b4 = 1;
    const std::uint32_t second_mode =
        *static_cast<std::uint32_t*>(second_value);
    if (second_mode == 0x80000000u)
        source->second_mode_0b8 = 1;
    else if (second_mode == 0x20000000u)
        source->second_mode_0b8 = 0;
    else if (second_mode == 0x40000000u)
        source->second_mode_0b8 = 2;
    source->signature_000 = 0x4000000au;
    source->signature_004 = 0x4e465443u;
    source->version_008 = 0x07010000u;
    source->opaque_030 = 1.0f;
    source->opaque_034 = 1.0f;
    source->opaque_038 = 1.0f;
    const std::uint8_t* identity = static_cast<const std::uint8_t*>(FUN_004388F4());
    for (std::uint32_t i = 0; i != 0x30; ++i)
        source->matrix_084[i] = identity[i];
    source->flags_018 |= 1;
    void* object =
        allocator->vtable->allocate(allocator, 0x2cc, 4);
    OpaqueOwnedPointer first;
    OpaqueOwnedPointer second;
    transfer_owned(first, descriptor->first);
    transfer_owned(second, descriptor->second);
    object = FUN_00439B08(
        object, allocator, source,
        reinterpret_cast<const std::uint32_t*>(descriptor),
        &first, &second, 0.0f, 1);
    release_owned(first);
    release_owned(second);
    DefaultChildResource_Initialize_008F8E98(
        static_cast<OpaqueDefaultChildObject*>(object), allocator);
    return object;
}
extern "C" __attribute__((noinline)) void
RenderResource_FinalizeDefaultChild_0038FAB0(
    void* descriptor_storage) {
    DefaultChildDescriptorView* descriptor = static_cast<DefaultChildDescriptorView*>(
            descriptor_storage);
    release_owned(descriptor->second);
    release_owned(descriptor->first);
}

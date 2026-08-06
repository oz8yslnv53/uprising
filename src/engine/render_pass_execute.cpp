#include <cstdint>
extern "C" void TemporaryRecord_ZeroInit(
    void* record, const void* tag, std::uint32_t count,
    std::uint32_t element_size);
extern "C" void* Engine_StateSingleton_003B6EDC();
extern "C" void Engine_StateRecord_Read_003B4170(
    int* out, void* state, std::uint32_t entry);
extern "C" void ParameterString_Assign_00416688(
    void* destination, const char* text, std::uint32_t mode);
extern "C" void* Engine_AllocateTaggedBlock(
    std::uint32_t element_size, const void* tag, std::uint32_t count);
extern "C" void PicaCommand_EmitViewport_0012BC44(
    void* state, std::uint32_t x, std::uint32_t y,
    std::int32_t width, std::int32_t height);
extern "C" void RenderPass_SetTargetState_00911484(
    void* target, std::uint32_t value0, std::uint32_t value1,
    std::uint32_t value2);
extern "C" void* RenderResource_GetIndexedRecord_003AF054(
    void* owner, std::uint32_t index);
extern "C" void* Resource_GetIndexedEntry_00464200(void* resource,
                                                     std::uint32_t index);
extern "C" void FontText_Render_007228BC(void* text);
extern "C" void RenderState_Deactivate_00911340(void* target);
extern "C" void RenderState_Activate_00911348(void* target, void* resource);
extern "C" void RenderState_Commit_00911424(void* target,
                                             void* list);
extern "C" void RenderProjectionCommand_Emit_008DEA8C(
    void* target, void* resource, std::uint32_t mode);
extern "C" void RenderResource_InvokeModeCallback_00717F8C(
    void* state, std::uint32_t index);
extern "C" void RenderResource_Rebuild_008DC2E8(void* context, void* entry);
extern "C" void RenderResource_Release_008DE7B4(void* resource);
extern "C" void RenderResource_RecordInitialize_00542598(
    void* destination, void* source);
extern "C" void RenderResource_RecordClearSource_0054258C(void* record);
extern "C" void* Engine_LazySingletonGetter_00BB7940();
extern "C" void RenderCommand_FinalizeTrackedRange_008DD2A0();
extern "C" void RenderPass_RenderTarget_00A33DA0(void* state,
                                                   std::uint32_t mode);
extern "C" void RenderState_SwitchSlot_00916400(void* state,
                                                  std::uint32_t slot);
extern "C" void RenderCommand_FinalizeCurrentPacket_002A4618();
extern "C" void Matrix3x4_Copy_0044C0A0(
    void* destination, const void* source);
extern "C" void RenderState_InvokeSlotB8_0075C84C(void* manager,
                                                    std::uint32_t unused,
                                                    std::uint32_t slot);
extern "C" void RenderState_InvokeSlotA8_0075C770(void* manager,
                                                    std::uint32_t slot);
extern "C" void* Engine_LazyStateManager_00475D18();
extern "C" void* Engine_SharedRegistrySingleton_00593E20();
extern "C" std::uint32_t RenderPass_TopInactivePrepare_00727670(void* pass);
extern "C" void RenderPass_TopInactiveFallback_00727A90(void* pass,
                                                          void* owner,
                                                          std::uint32_t unused);
extern "C" void RenderPass_TopMoviePrepare_00729FB0(void* pass,
                                                      void* owner);
extern "C" void RenderPass_TopOverlayStrips_00725418(void* pass);
extern "C" void RenderRecordRange_PartitionSort_00C912E4(
    const void* begin, const void* end, std::uint32_t count);
extern "C" void RenderRecordRange_FinalInsertionSort_00C936B4(
    const void* begin, const void* end);
struct RenderPassGlobalsView {
    void* state_singleton;
    void* packed_selector_record;
    void** selector_slot;
    void** target_registry_slot;
    void** state_manager_slot;
};
extern RenderPassGlobalsView DAT_007C90B4;
// Shared retail slot at 00D635B8; its concrete owner is not established.
extern void* DAT_00D635B8;
extern void* g_RenderPassRegistry_00D63654;
extern "C" void* g_RenderState_Global_00D637BC;
extern "C" void Engine_VirtualReleaseDispatch_00421DEC(void* object);
extern "C" __attribute__((noinline)) std::uint32_t RenderPass_QueryReady_00B4988C(void* resource) {
    std::uint8_t* state = *reinterpret_cast<std::uint8_t**>(
        static_cast<std::uint8_t*>(resource) + 4);
    return state == 0 ||
           *reinterpret_cast<void**>(state + 0x18) ==
               *reinterpret_cast<void**>(state + 0x1c);
}
struct RenderPassRecordConfig {
    std::uint32_t values[7];
};
struct RenderPassRecord {
    void* vtable;
    RenderPassRecord* previous;
    void* next_link;
    void* next;
    std::uint8_t* state_begin;
    std::uint32_t state_size;
    std::uint8_t state[0x20];
    std::uint8_t enabled;
    std::uint8_t reserved_39[3];
    std::uint32_t index;
    RenderPassRecordConfig config;
    std::uint8_t pending;
    std::uint8_t ready;
    std::uint8_t reserved_5e[2];
    void* text;
};
typedef char kiu_sa_render_pass_execute_1[(sizeof(RenderPassRecord) == 0x64) ? 1 : -1] __attribute__((unused));
struct PreFontPassRecord {
    void* vtable;
    PreFontPassRecord* previous;
    void* next_link;
    void* next;
    std::uint8_t* state_begin;
    std::uint32_t state_size;
    std::uint8_t state[0x20];
    std::uint8_t enabled;
    std::uint8_t reserved_39[3];
    std::uint32_t index;
};
typedef char kiu_sa_render_pass_execute_2[(sizeof(PreFontPassRecord) == 0x40) ? 1 : -1] __attribute__((unused));
extern "C" __attribute__((noinline)) RenderPassRecordConfig*
RenderPass_BuildConfig_007C8CD0(
    RenderPassRecordConfig* config) {
    config->values[0] = 0;
    config->values[1] = 0;
    config->values[2] = 0;
    config->values[3] = 0;
    config->values[4] = 0;
    config->values[5] = 1;
    config->values[6] = 1;
    void* state = g_RenderState_Global_00D637BC;
    if (state == 0) {
        state = Engine_StateSingleton_003B6EDC();
        g_RenderState_Global_00D637BC = state;
    }
    int values[4];
    Engine_StateRecord_Read_003B4170(values, state, 1);
    for (std::uint32_t i = 0; i < 4; ++i)
        config->values[i + 1] = static_cast<std::uint32_t>(values[i]);
    return config;
}
extern "C" __attribute__((noinline)) RenderPassRecord*
RenderPass_RecordConstruct_007C90C8(
    RenderPassRecord* record, std::uint32_t index,
    const RenderPassRecordConfig* config) {
    record->next_link = &record->previous;
    record->previous = record;
    record->next = &record->previous;
    record->state_begin = record->state;
    record->state_size = sizeof(record->state);
    record->state[0] = 0;
    record->enabled = 1;
    record->index = index;
    record->vtable = reinterpret_cast<void*>(0x00cf6c4c);
    record->config = *config;
    record->pending = 0;
    record->ready = 1;
    record->text = 0;
    return record;
}
extern "C" __attribute__((noinline)) std::uint32_t RenderPass_AllocateRecord_007DBA34(
    void*, std::uint32_t count, void* owner) {
    std::uint8_t* owner_bytes = static_cast<std::uint8_t*>(owner);
    owner_bytes[0x18] = 0;
    ParameterString_Assign_00416688(
        owner_bytes + 0x10, "BottomRenderPass", 0);
    RenderPassRecordConfig config;
    RenderPass_BuildConfig_007C8CD0(&config);
    config.values[0] = *reinterpret_cast<std::uint32_t*>(owner_bytes + 0x54);
    RenderPassRecord* record = static_cast<RenderPassRecord*>(Engine_AllocateTaggedBlock(
        sizeof(RenderPassRecord), reinterpret_cast<const void*>(0x007dbab4),
        count));
    if (record != 0)
        record = RenderPass_RecordConstruct_007C90C8(record, 0, &config);
    const std::uintptr_t record_address = reinterpret_cast<std::uintptr_t>(record);
    const std::uint32_t index = *reinterpret_cast<volatile std::uint32_t*>(
        record_address + 0x3c);
    *reinterpret_cast<RenderPassRecord**>(
        owner_bytes + 0x40 + index * sizeof(void*)) = record;
    return 1;
}
extern "C" __attribute__((noinline)) std::uint32_t RenderPass_AllocatePreFont_00814784(
    void*, std::uint32_t count, void* owner) {
    std::uint8_t* owner_bytes = static_cast<std::uint8_t*>(owner);
    owner_bytes[0x18] = 0;
    ParameterString_Assign_00416688(owner_bytes + 0x10, "PreRenderPass", 0);
    PreFontPassRecord* record = static_cast<PreFontPassRecord*>(Engine_AllocateTaggedBlock(
        sizeof(PreFontPassRecord),
        reinterpret_cast<const void*>(0x0081483c), count));
    if (record != 0) {
        record->next_link = &record->previous;
        record->previous = record;
        record->next = &record->previous;
        record->state_begin = record->state;
        record->state_size = sizeof(record->state);
        record->state[0] = 0;
        record->enabled = 1;
        record->index = 1;
        record->vtable = reinterpret_cast<void*>(0x00cfa4fc);
    }
    const std::uintptr_t record_address = reinterpret_cast<std::uintptr_t>(record);
    *reinterpret_cast<volatile std::uint8_t*>(record_address + 0x18) = 0;
    ParameterString_Assign_00416688(
        reinterpret_cast<void*>(record_address + 0x10), "PreFontPass", 0);
    const std::uint32_t index = *reinterpret_cast<volatile std::uint32_t*>(
        record_address + 0x3c);
    *reinterpret_cast<PreFontPassRecord**>(
        owner_bytes + 0x40 + index * sizeof(void*)) = record;
    return 1;
}
extern "C" __attribute__((noinline)) void RenderPassRegistry_Destroy_00BA9DF8(void* registry) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(registry);
    *reinterpret_cast<void**>(bytes) =
        reinterpret_cast<void*>(0x00d15f38);
    const std::int32_t count = *reinterpret_cast<std::int32_t*>(bytes + 0x50);
    for (std::int32_t i = 0; i < count; ++i) {
        void* pass = *reinterpret_cast<void**>(
            bytes + 0x40 + static_cast<std::uint32_t>(i) * sizeof(void*));
        if (pass != 0) {
            void** vtable = *static_cast<void***>(pass);
            reinterpret_cast<void (*)(void*)>(vtable[1])(pass);
        }
    }
    std::uint8_t* previous = *reinterpret_cast<std::uint8_t**>(bytes + 8);
    std::uint8_t* next = *reinterpret_cast<std::uint8_t**>(bytes + 0x0c);
    *reinterpret_cast<void**>(next + 4) = previous;
    *reinterpret_cast<void**>(previous + 8) = next;
    Engine_VirtualReleaseDispatch_00421DEC(registry);
}
extern "C" __attribute__((noinline)) void RenderPass_UnlinkNode_007C912C(void* object) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(object);
    std::uint8_t* previous = *reinterpret_cast<std::uint8_t**>(bytes + 8);
    std::uint8_t* next = *reinterpret_cast<std::uint8_t**>(bytes + 0x0c);
    *reinterpret_cast<void**>(next + 4) = previous;
    *reinterpret_cast<void**>(previous + 8) = next;
    Engine_VirtualReleaseDispatch_00421DEC(object);
}
typedef void (*RenderEntryPrepare)(void* entry, void* target_record);
typedef void (*RenderTargetPrepare)(
    void* controller, void* range, void* source, void* resource_state,
    std::uint32_t first, std::uint32_t second, std::uint32_t third);
typedef void* (*RenderTargetGetState)(void* target);
struct Matrix3x4View_0090E73C {
    float values[12];
};
extern "C" __attribute__((noinline)) void
RenderTarget_SetFourStateFloats_008F91A4(
    void* owner, float value0, float value1, float value2, float value3) {
    void* target = *reinterpret_cast<void**>(
        static_cast<std::uint8_t*>(owner) + 0x290);
    void** vtable = *static_cast<void***>(target);
    std::uint8_t* state = static_cast<std::uint8_t*>(
        reinterpret_cast<RenderTargetGetState>(vtable[4])(target));
    if (state != 0 &&
        ((*reinterpret_cast<std::uint32_t*>(state) & 0x20000000u) == 0))
        state = 0;
    *reinterpret_cast<float*>(state + 0x10) = value0;
    *reinterpret_cast<float*>(state + 0x0C) = value1;
    *reinterpret_cast<float*>(state + 0x04) = value2;
    *reinterpret_cast<float*>(state + 0x08) = value3;
}
extern "C" __attribute__((noinline)) void RenderTarget_QueryFourStateFloats_004C38A4(
    void* owner, float* value0, float* value1,
    float* value2, float* value3) {
    void* target = *reinterpret_cast<void**>(
        static_cast<std::uint8_t*>(owner) + 0x290);
    void** vtable = *static_cast<void***>(target);
    std::uint8_t* state = static_cast<std::uint8_t*>(
        reinterpret_cast<RenderTargetGetState>(vtable[5])(target));
    if (state != 0 &&
        ((*reinterpret_cast<std::uint32_t*>(state) & 0x20000000u) == 0))
        state = 0;
    if (value0 != 0)
        *value0 = *reinterpret_cast<float*>(state + 0x10);
    if (value1 != 0)
        *value1 = *reinterpret_cast<float*>(state + 0x0c);
    if (value2 != 0)
        *value2 = *reinterpret_cast<float*>(state + 0x04);
    if (value3 != 0)
        *value3 = *reinterpret_cast<float*>(state + 0x08);
}
extern "C" __attribute__((noinline)) void RenderTarget_QueryBoundsAndFloats_00B406C4(
    void* owner, float* bounds, float* value0, float* value1) {
    void* target = *reinterpret_cast<void**>(
        static_cast<std::uint8_t*>(owner) + 0x290);
    void** vtable = *static_cast<void***>(target);
    std::uint8_t* state = static_cast<std::uint8_t*>(
        reinterpret_cast<RenderTargetGetState>(vtable[5])(target));
    if (state != 0 &&
        ((*reinterpret_cast<std::uint32_t*>(state) & 0x40000000u) == 0))
        state = 0;
    if (bounds != 0) {
        const float scale = *reinterpret_cast<float*>(state + 0x10);
        const float half_width =
            scale * *reinterpret_cast<float*>(state + 0x0c) * 0.5f;
        const float half_height = scale * 0.5f;
        const float center_x = *reinterpret_cast<float*>(state + 0x14);
        const float center_y = *reinterpret_cast<float*>(state + 0x18);
        bounds[0] = center_x - half_width;
        bounds[1] = center_y - half_height;
        bounds[2] = center_x + half_width;
        bounds[3] = center_y + half_height;
    }
    if (value0 != 0)
        *value0 = *reinterpret_cast<float*>(state + 0x04);
    if (value1 != 0)
        *value1 = *reinterpret_cast<float*>(state + 0x08);
}
extern "C" __attribute__((noinline)) void RenderState_PublishDerivedMatrices_0090E73C(
    void* state, const float* matrix) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(state);
    const std::uint8_t enabled = bytes[0x180];
    std::uint8_t* output = *reinterpret_cast<std::uint8_t**>(bytes + 0x178);
    if (enabled == 0)
        return;
    const float m00 = matrix[0], m01 = matrix[1], m02 = matrix[2];
    const float m03 = matrix[3];
    const float m10 = matrix[4], m11 = matrix[5], m12 = matrix[6];
    const float m13 = matrix[7];
    const float m20 = matrix[8], m21 = matrix[9], m22 = matrix[10];
    const float m23 = matrix[11];
    float translation0 = m00 * m03;
    float translation1 = m01 * m03;
    float translation2 = m02 * m03;
    translation0 += m13 * m10;
    translation1 += m13 * m11;
    translation2 += m13 * m12;
    translation0 += m23 * m20;
    translation1 += m23 * m21;
    translation2 += m23 * m22;
    Matrix3x4View_0090E73C inverse = {{
        m00, m10, m20, -translation0,
        m01, m11, m21, -translation1,
        m02, m12, m22, -translation2,
    }};
    const float inverse_scale =
        1.0f / *reinterpret_cast<float*>(bytes + 0x17c);
    Matrix3x4View_0090E73C projection;
    projection.values[0] = inverse_scale;
    projection.values[1] = 0.0f;
    projection.values[2] = 0.0f;
    projection.values[3] = 0.5f;
    projection.values[4] = 0.0f;
    projection.values[5] = inverse_scale;
    projection.values[6] = 0.0f;
    projection.values[7] = 0.5f;
    projection.values[8] = 0.0f;
    projection.values[9] = 0.0f;
    projection.values[10] = 0.0f;
    projection.values[11] = 1.0f;
    Matrix3x4View_0090E73C remapped = {{
        matrix[8], matrix[9], matrix[10],
        -(matrix[8] * inverse.values[3] +
          matrix[9] * inverse.values[7] +
          matrix[10] * inverse.values[11]),
        matrix[0], matrix[1], matrix[2],
        -(matrix[0] * inverse.values[3] +
          matrix[1] * inverse.values[7] +
          matrix[2] * inverse.values[11]),
        matrix[4], matrix[5], matrix[6],
        -(matrix[4] * inverse.values[3] +
          matrix[5] * inverse.values[7] +
          matrix[6] * inverse.values[11]),
    }};
    const Matrix3x4View_0090E73C* source = reinterpret_cast<const Matrix3x4View_0090E73C*>(matrix);
    *reinterpret_cast<Matrix3x4View_0090E73C*>(output + 0x148) = *source;
    Matrix3x4View_0090E73C copied;
    Matrix3x4_Copy_0044C0A0(&copied, &inverse);
    *reinterpret_cast<Matrix3x4View_0090E73C*>(output + 0x178) = copied;
    Matrix3x4_Copy_0044C0A0(&copied, &inverse);
    *reinterpret_cast<Matrix3x4View_0090E73C*>(output + 0x8c) = copied;
    Matrix3x4_Copy_0044C0A0(&copied, &projection);
    *reinterpret_cast<Matrix3x4View_0090E73C*>(output + 0x228) = copied;
    Matrix3x4_Copy_0044C0A0(&copied, &remapped);
    *reinterpret_cast<Matrix3x4View_0090E73C*>(output + 0x258) = copied;
}
extern "C" __attribute__((noinline)) std::uint32_t
RenderPass_TopUpdate_00729EA0(void* pass) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(pass);
    std::uint32_t temporary = 0;
    TemporaryRecord_ZeroInit(
        &temporary, reinterpret_cast<const void*>(0x00729fa0), 3, 0x10);
    void* owner = *reinterpret_cast<void**>(bytes + 0x40);
    if (bytes[0x364] != 0) {
        RenderPass_TopMoviePrepare_00729FB0(pass, owner);
    } else if (RenderPass_TopInactivePrepare_00727670(pass) == 0) {
        RenderPass_TopInactiveFallback_00727A90(pass, owner, 3);
    }
    void* resource = DAT_00D635B8;
    if (resource == 0) {
        resource = Engine_LazyStateManager_00475D18();
        DAT_00D635B8 = resource;
    }
    RenderState_InvokeSlotA8_0075C770(resource, 0);
    RenderState_InvokeSlotB8_0075C84C(resource, 0, 0);
    void* registry = g_RenderPassRegistry_00D63654;
    if (registry == 0) {
        registry = Engine_SharedRegistrySingleton_00593E20();
        g_RenderPassRegistry_00D63654 = registry;
    }
    RenderPass_RenderTarget_00A33DA0(registry, 0);
    RenderState_InvokeSlotB8_0075C84C(resource, 0, 1);
    void* movie_quad = *reinterpret_cast<void**>(bytes + 0x368);
    if (movie_quad != 0 &&
        ((*reinterpret_cast<std::uint32_t*>(
              static_cast<std::uint8_t*>(movie_quad) + 0x270) & 2) != 0))
        RenderPass_TopOverlayStrips_00725418(movie_quad);
    RenderCommand_FinalizeCurrentPacket_002A4618();
    return 1;
}
extern "C" __attribute__((noinline)) std::uint32_t
RenderPass_Execute_007C8D44(void* pass) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(pass);
    std::uint8_t temporary[0x34] = {};
    TemporaryRecord_ZeroInit(
        temporary + 0x0c, reinterpret_cast<const void*>(0x007c90ac), 3, 0x20);
    std::uint8_t* owner = *reinterpret_cast<std::uint8_t**>(bytes + 0x40);
    std::uint8_t* target = *reinterpret_cast<std::uint8_t**>(owner + 4);
    void* state = DAT_007C90B4.state_singleton;
    if (state == 0) {
        state = Engine_StateSingleton_003B6EDC();
        DAT_007C90B4.state_singleton = state;
    }
    *reinterpret_cast<std::uint32_t*>(owner + 0xF4) =
        *reinterpret_cast<std::uint32_t*>(bytes + 0x54);
    *reinterpret_cast<std::uint32_t*>(owner + 0xF8) =
        *reinterpret_cast<std::uint32_t*>(bytes + 0x58);
    *reinterpret_cast<std::uint32_t*>(target + 0x58) = 0xFFFFFFFFu;
    PicaCommand_EmitViewport_0012BC44(
        state, *reinterpret_cast<std::uint32_t*>(bytes + 0x44),
        *reinterpret_cast<std::uint32_t*>(bytes + 0x48),
        *reinterpret_cast<std::int32_t*>(bytes + 0x4c),
        *reinterpret_cast<std::int32_t*>(bytes + 0x50));
    RenderPass_SetTargetState_00911484(
        target, *reinterpret_cast<std::uint32_t*>(bytes + 0x54),
        *reinterpret_cast<std::uint32_t*>(bytes + 0x58), 0xFFFFFFFFu);
    std::uint8_t* resource =
        static_cast<std::uint8_t*>(RenderResource_GetIndexedRecord_003AF054(
            owner, *reinterpret_cast<std::uint32_t*>(owner + 0xF4)));
    if (bytes[0x5D] != 0) {
        void* entries[4] = {};
        for (std::uint32_t i = 0; i != 4; ++i)
            entries[i] = Resource_GetIndexedEntry_00464200(owner, 0x0F + i);
        const std::uint32_t packed_indices = *reinterpret_cast<std::uint32_t*>(
            static_cast<std::uint8_t*>(DAT_007C90B4.packed_selector_record) + 4);
        void* target_record = *reinterpret_cast<void**>(target + 0x14);
        void* source = *reinterpret_cast<void**>(target + 0x18);
        void* controller = *reinterpret_cast<void**>(target + 0x1C);
        void* rebuild_context = *reinterpret_cast<void**>(target + 0x30);
        std::uint8_t* range = *reinterpret_cast<std::uint8_t**>(target + 0x34);
        for (std::uint32_t i = 0; i != 4; ++i) {
            bool rebuilt = false;
            const std::uint32_t ready = RenderPass_QueryReady_00B4988C(entries[i]);
            if (ready == 0) {
                void* entry = *reinterpret_cast<void**>(
                    static_cast<std::uint8_t*>(entries[i]) + 4);
                RenderResource_RecordInitialize_00542598(target_record, source);
                void** entry_vtable = *static_cast<void***>(entry);
                reinterpret_cast<RenderEntryPrepare>(entry_vtable[4])(
                    entry, target_record);
                RenderResource_RecordClearSource_0054258C(target_record);
                *reinterpret_cast<std::uint32_t*>(range + 0x10) =
                    *reinterpret_cast<std::uint32_t*>(range + 0x0C);
                range[0x28] = 0;
                void** controller_vtable = *static_cast<void***>(controller);
                reinterpret_cast<RenderTargetPrepare>(controller_vtable[7])(
                    controller, range, source,
                    *reinterpret_cast<void**>(resource + 8), 0, 1, 0);
                void* begin = *reinterpret_cast<void**>(range + 0x0C);
                void* end = *reinterpret_cast<void**>(range + 0x10);
                if (begin != end) {
                    RenderRecordRange_PartitionSort_00C912E4(
                        begin, end,
                        (static_cast<std::uint8_t*>(end) -
                         static_cast<std::uint8_t*>(begin)) >> 4);
                    RenderRecordRange_FinalInsertionSort_00C936B4(begin, end);
                }
                RenderProjectionCommand_Emit_008DEA8C(
                    *reinterpret_cast<void**>(target + 0x28),
                    *reinterpret_cast<void**>(resource + 8), 0);
                RenderState_Deactivate_00911340(target);
                RenderState_Activate_00911348(target, resource);
                RenderState_Commit_00911424(target, range);
                rebuilt = true;
            }
            void** selector_slot = DAT_007C90B4.selector_slot;
            if (*selector_slot == 0)
                *selector_slot = Engine_LazySingletonGetter_00BB7940();
            RenderResource_InvokeModeCallback_00717F8C(
                *selector_slot, (packed_indices >> (i * 8)) & 0xFFu);
            if (rebuilt) {
                std::uint8_t* source_bytes =
                    static_cast<std::uint8_t*>(source);
                std::uint8_t* begin =
                    *reinterpret_cast<std::uint8_t**>(source_bytes + 0xDC);
                std::uint8_t* end =
                    *reinterpret_cast<std::uint8_t**>(source_bytes + 0xE0);
                if (begin != end) {
                    RenderProjectionCommand_Emit_008DEA8C(
                        *reinterpret_cast<void**>(target + 0x28),
                        *reinterpret_cast<void**>(resource + 8), 0);
                    RenderState_Deactivate_00911340(target);
                    RenderState_Activate_00911348(target, resource);
                    for (std::uint8_t* p = begin; p != end; p += 4)
                        RenderResource_Rebuild_008DC2E8(
                            rebuild_context, *reinterpret_cast<void**>(p));
                    RenderResource_Release_008DE7B4(
                        *reinterpret_cast<void**>(target + 0x28));
                }
            }
            RenderCommand_FinalizeCurrentPacket_002A4618();
            RenderCommand_FinalizeTrackedRange_008DD2A0();
        }
    }
    RenderPass_RenderTarget_00A33DA0(
        *DAT_007C90B4.target_registry_slot, 1);
    void* state_manager = *DAT_007C90B4.state_manager_slot;
    if (state_manager == 0) {
        state_manager = Engine_LazyStateManager_00475D18();
        *DAT_007C90B4.state_manager_slot = state_manager;
    }
    RenderState_InvokeSlotB8_0075C84C(
        state_manager, 1, 1);
    void* font = *reinterpret_cast<void**>(bytes + 0x60);
    if (font != 0 &&
        ((*reinterpret_cast<std::uint32_t*>(static_cast<std::uint8_t*>(font) +
                                             0x270) & 0x1C) != 0)) {
        FontText_Render_007228BC(font);
    }
    return 1;
}

#include <cstddef>
#include <cstdint>
extern "C" void FUN_00168590(
    std::uint32_t, std::uint32_t, void**);
extern "C" std::uint32_t FUN_001414A0();
extern "C" std::uint32_t FUN_001EDEF0();
extern "C" void* FUN_0035F6A4(std::uint32_t, std::uint32_t);
extern "C" void FUN_0035F668(void*);
extern "C" void FUN_001B4E70(
    std::uint32_t, std::uint32_t, std::uint32_t);
extern "C" void Engine_BulkCopy_00425DF8(
    void*, const void*, std::uint32_t);
extern "C" void FUN_0017C614(
    void*, std::uint32_t, std::uint32_t, std::uint32_t,
    std::uint32_t, std::uint32_t, std::uint32_t, std::uint32_t,
    std::uint32_t, std::uint32_t);
extern "C" void FUN_0015B9C0(
    void*, const void*, void*, std::uint32_t);
extern "C" void FUN_0015E5EC(void*, const void*);
extern "C" void FUN_0015DDF4(void*);
extern "C" void FUN_0018BB84(std::uint32_t, void*);
extern "C" void FUN_0017C7DC(void*);
extern "C" std::uint32_t Platform_MapResourceAddress_003AC86C(
    std::uint32_t);
extern "C" void RenderCommand_FinalizeCurrentPacket_002A4618();
extern "C" void FUN_0018BB6C();
extern "C" void FUN_00168980();
extern "C" void FUN_00168F0C();
extern "C" void FUN_001688F0();
extern "C" void FUN_0017002C(
    void*, std::uint16_t, std::uint16_t, std::uint32_t);
extern "C" void FUN_0017040C(std::uint16_t, std::uint16_t);
extern "C" void FUN_0016F05C(
    std::uint16_t, std::uint16_t, std::uint32_t, std::uint32_t);
extern "C" void FUN_0015542C(
    void*, float*, std::uint16_t, std::uint16_t);
extern "C" void FUN_00192610(void*);
extern "C" void FUN_00155324(void*, const float*, const float*);
extern "C" int Matrix3x4_InvertAffine_003FD91C(float*, const float*);
extern "C" void Matrix3x4_TransposeBasisClearTranslation_001552A4(
    float*, const float*);
extern "C" void FUN_0016F18C(std::uint32_t, std::uint32_t);
extern "C" void FUN_00192130(void*, void*, std::uint32_t);
extern "C" void RenderCommand_SubmitPacket_001689E0(
    std::uint32_t, std::uint32_t, std::uint32_t, std::uint32_t,
    std::uint32_t, std::uint32_t, std::uint32_t);
extern "C" void* FUN_0039FA98();
extern "C" std::uint32_t g_RenderDraw_ColorTable_00CB0CA8[];
extern "C" std::uint32_t g_RenderDraw_TransformMode_00DC2018[];
extern "C" std::uint32_t g_RenderDraw_ReleaseState_00CB0864[];
typedef void (*RenderDrawReleaseCallback)(
    std::uint32_t, std::uint32_t, std::uint32_t, std::uint32_t);
extern "C" void FUN_0018BCC8(
    std::uint32_t, RenderDrawReleaseCallback*);
namespace {
struct DrawWorkspace {
    std::uint32_t target_class;
    std::uint32_t view_mask;
    std::uint32_t flags;
    std::uint32_t padding;
    std::uint8_t data[0xb0];
};
typedef char kiu_sa_render_draw_packet_submit_1[(offsetof(DrawWorkspace, data) == 0x10) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_render_draw_packet_submit_2[(sizeof(DrawWorkspace) == 0xc0) ? 1 : -1] __attribute__((unused));
template <typename T>
T& Field(void* object, std::uint32_t offset) {
    return *reinterpret_cast<T*>(
        static_cast<std::uint8_t*>(object) + offset);
}
std::uint32_t SelectTargetClass(const std::uint16_t* extent) {
    const std::uint16_t width = extent[0];
    const std::uint16_t height = extent[1];
    std::uint32_t target_class;
    if ((width > 0x80 || height > 0x80) && FUN_001414A0() != 0) {
        target_class = 0x100;
    } else {
        target_class = (width > 0x40 || height > 0x40) ? 0x80 : 0x40;
    }
    if (FUN_001EDEF0() != 0) {
        if ((width > 0x200 || height > 0x200) && FUN_001414A0() != 0)
            target_class = 0x400;
        else if (width > 0x100 || height > 0x100)
            target_class = 0x200;
    }
    return target_class;
}
std::uint32_t NormalizeTargetClass(std::uint32_t target_class) {
    switch (target_class) {
    case 0x80:
    case 0xe0:
        return 0x80;
    case 0x100:
    case 0x1e0:
        return 0x100;
    case 0x200:
        return 0x200;
    case 0x400:
        return 0x400;
    default:
        return 0x40;
    }
}
void UpdateMappedView(void* workspace, std::uint32_t view_index) {
    void* const resource =
        Field<void*>(workspace, 0x70 + view_index * 4);
    if (resource == 0 || Field<std::uint32_t>(workspace, 0x60) == view_index)
        return;
    void* const owner = Field<void*>(workspace, 0x6c);
    std::uint32_t* const address_word = Field<std::uint32_t*>(owner, 0x734);
    if (address_word != 0) {
        const std::uint32_t address =
            Field<std::uint32_t>(resource, 0x28);
        *address_word = Platform_MapResourceAddress_003AC86C(address) >> 3;
    }
    Field<std::uint32_t>(workspace, 0x60) = view_index;
}
void SubmitWorkspacePacket(void* workspace, std::uint32_t base_offset) {
    void* const owner = Field<void*>(workspace, 0x6c);
    std::uint8_t output[0x30];
    FUN_00192130(workspace, output, 1);
    RenderCommand_SubmitPacket_001689E0(
        Field<std::uint32_t>(owner, base_offset + 0x00),
        0,
        Field<std::uint32_t>(owner, base_offset + 0x08),
        Field<std::uint32_t>(owner, base_offset + 0x10),
        Field<std::uint32_t>(owner, base_offset + 0x14),
        0,
        Field<std::uint8_t>(owner, base_offset + 0x0c));
    FUN_0018BB6C();
    FUN_0018BB6C();
}
void ReleaseOwnerSlot(
    void* slot, std::uint32_t release_id,
    RenderDrawReleaseCallback* callback) {
    const std::uint32_t handle = Field<std::uint32_t>(slot, 0x00);
    if (handle == 0)
        return;
    if (Field<std::uint32_t>(slot, 0x0c) != 0) {
        FUN_0018BCC8(0, callback);
        (*callback)(
            Field<std::uint32_t>(slot, 0x08), release_id, handle,
            Field<std::uint32_t>(slot, 0x04));
    }
    Field<std::uint32_t>(slot, 0x00) = 0;
    Field<std::uint32_t>(slot, 0x0c) = 0;
}
}  // namespace
extern "C" __attribute__((noinline)) std::uint32_t RenderDraw_CountViewBits_0013BBD4(
    std::uint32_t view_mask) {
    std::uint32_t count = 0;
    for (std::uint32_t bit = 0; bit < 16; ++bit) {
        if ((view_mask & (1u << bit)) != 0)
            ++count;
    }
    return count;
}
extern "C" __attribute__((noinline)) void RenderDraw_InitWorkspace_0013BC08(
    void* workspace,
    const void* packet,
    std::uint32_t packet_limit,
    void* allocation,
    std::uint32_t target_class,
    std::uint32_t view_mask,
    std::uint32_t flags) {
    FUN_001B4E70(0xcb0874, 0x30, 1);
    FUN_001B4E70(0xcb08a4, 0x30, 1);
    Field<std::uint32_t>(workspace, 0x64) = 0;
    Field<std::uint32_t>(workspace, 0x68) = 0x2701;
    Field<void*>(workspace, 0x6c) = allocation;
    Engine_BulkCopy_00425DF8(
        static_cast<std::uint8_t*>(allocation) + 0x55c, packet, 0x120);
    Field<std::uint32_t>(allocation, 0x67c) = packet_limit;
    Field<void*>(allocation, 0x680) = allocation;
    Field<std::uint32_t>(allocation, 0x684) = target_class;
    Field<std::uint32_t>(allocation, 0x688) = view_mask;
    Field<std::uint32_t>(allocation, 0x68c) = flags;
    std::uint8_t* next_view =
        static_cast<std::uint8_t*>(allocation) + 0x780;
    for (std::uint32_t view = 0; view < 16; ++view) {
        if ((view_mask & (1u << view)) == 0) {
            Field<void*>(workspace, 0x70 + view * 4) = 0;
        } else {
            Field<void*>(workspace, 0x70 + view * 4) = next_view;
            next_view += 0x34;
        }
    }
    const std::uint32_t normalized_class =
        NormalizeTargetClass(target_class);
    bool selected_first = false;
    for (std::uint32_t view = 0; view < 16; ++view) {
        if ((view_mask & (1u << view)) == 0)
            continue;
        FUN_0017C614(
            Field<void*>(workspace, 0x70 + view * 4),
            normalized_class, normalized_class, 1, 0, 0, 10, 0,
            0x10000, 0);
        if (!selected_first) {
            selected_first = true;
            Field<std::uint32_t>(workspace, 0x60) = view;
        }
    }
    std::uint8_t scratch[0x100];
    FUN_0015B9C0(scratch, packet, workspace, target_class);
    FUN_0015E5EC(allocation, scratch);
    FUN_0015DDF4(workspace);
}
extern "C" __attribute__((noinline)) std::uint32_t RenderDraw_EmitWorkspace_0013B630(
    void* context,
    void* workspace,
    std::uint32_t view_index,
    const std::uint16_t* target) {
    if (workspace == 0 ||
        Field<void*>(workspace, 0x70 + view_index * 4) == 0)
        return 2;
    if (context == 0)
        FUN_00168590(0x0de1, 0x6790, &context);
    const std::uint16_t width = target[0];
    const std::uint16_t height = target[1];
    const std::uint32_t command =
        *reinterpret_cast<const std::uint32_t*>(target + 2);
    FUN_0017002C(context, width, height, command);
    FUN_0017040C(width, height);
    const std::uint32_t color_mode =
        *reinterpret_cast<const std::uint32_t*>(target + 4);
    if (color_mode != 2) {
        std::uint32_t color;
        if (color_mode == 1) {
            color = *reinterpret_cast<const std::uint32_t*>(target + 6);
        } else {
            void* const owner = Field<void*>(workspace, 0x6c);
            std::int32_t index = Field<std::int32_t>(owner, 0x648);
            if (index > 11)
                index = 11;
            color = g_RenderDraw_ColorTable_00CB0CA8[index];
        }
        FUN_0016F05C(width, height, color & 0x00ffffff, 1);
    }
    std::uint8_t matrix_state[0x40];
    float transform[12];
    FUN_0015542C(matrix_state, transform, width, height);
    FUN_00192610(matrix_state);
    std::uint8_t local_workspace[0xb0];
    Engine_BulkCopy_00425DF8(local_workspace, workspace, 0xb0);
    const std::uint32_t original_view =
        Field<std::uint32_t>(local_workspace, 0x60);
    UpdateMappedView(local_workspace, view_index);
    if (g_RenderDraw_TransformMode_00DC2018[12] ==
        g_RenderDraw_TransformMode_00DC2018[11]) {
        FUN_00155324(local_workspace, transform, transform);
    } else {
        float inverse[12];
        Matrix3x4_InvertAffine_003FD91C(inverse, transform);
        Matrix3x4_TransposeBasisClearTranslation_001552A4(inverse, inverse);
        FUN_00155324(local_workspace, transform, inverse);
    }
    FUN_0016F18C(0xcb0ac4, 1);
    FUN_001B4E70(0xcb0794, 0xa0, 1);
    FUN_001B4E70(target[8] == 0 ? 0xcb0834 : 0xcb0844, 0x10, 1);
    typedef void (*Callback)(std::uint32_t);
    Callback const callback = *reinterpret_cast<Callback const*>(target + 10);
    if (callback != 0)
        callback(*reinterpret_cast<const std::uint32_t*>(target + 12));
    const std::uint8_t skip_first =
        *(reinterpret_cast<const std::uint8_t*>(target) + 0x11);
    if (skip_first == 0)
        SubmitWorkspacePacket(local_workspace, 0x694);
    SubmitWorkspacePacket(local_workspace, 0x6b0);
    typedef void (*CompletionCallback)();
    void* callback_owner = FUN_0039FA98();
    CompletionCallback completion =
        Field<CompletionCallback>(callback_owner, 0xdc);
    if (completion != 0) {
        callback_owner = FUN_0039FA98();
        Field<CompletionCallback>(callback_owner, 0xdc)();
    }
    UpdateMappedView(local_workspace, original_view);
    return 0;
}
extern "C" __attribute__((noinline)) void RenderDraw_DestroyWorkspace_0013B43C(void* workspace) {
    void* const owner = Field<void*>(workspace, 0x6c);
    std::uint32_t release_state[4] = {
        g_RenderDraw_ReleaseState_00CB0864[0],
        g_RenderDraw_ReleaseState_00CB0864[1],
        g_RenderDraw_ReleaseState_00CB0864[2],
        g_RenderDraw_ReleaseState_00CB0864[3],
    };
    FUN_001B4E70(
        reinterpret_cast<std::uint32_t>(release_state), 0x10, 1);
    if (Field<std::uint32_t>(owner, 0x694) != 0) {
        FUN_0018BB84(1, static_cast<std::uint8_t*>(owner) + 0x694);
        Field<std::uint32_t>(owner, 0x694) = 0;
    }
    if (Field<std::uint32_t>(owner, 0x6b0) != 0) {
        FUN_0018BB84(1, static_cast<std::uint8_t*>(owner) + 0x6b0);
        Field<std::uint32_t>(owner, 0x6b0) = 0;
    }
    FUN_0017C7DC(static_cast<std::uint8_t*>(owner) + 0x414);
    FUN_0017C7DC(static_cast<std::uint8_t*>(owner) + 0x4b0);
    FUN_0017C7DC(static_cast<std::uint8_t*>(owner) + 0x47c);
    FUN_0017C7DC(static_cast<std::uint8_t*>(owner) + 0x448);
    RenderDrawReleaseCallback callback = 0;
    for (std::int32_t index = 8; index >= 0; --index) {
        void* const record =
            static_cast<std::uint8_t*>(owner) + index * 0x74;
        if (Field<std::uint32_t>(record, 0x68) == 0)
            continue;
        const std::uint32_t release_id =
            static_cast<std::uint32_t>(index + 0xfa);
        ReleaseOwnerSlot(
            static_cast<std::uint8_t*>(record) + 0x04,
            release_id, &callback);
        ReleaseOwnerSlot(
            static_cast<std::uint8_t*>(record) + 0x54,
            release_id, &callback);
        Field<std::uint32_t>(record, 0x68) = 0;
    }
    for (std::int32_t index = 15; index >= 0; --index) {
        void* const record =
            Field<void*>(workspace, 0x70 + index * 4);
        if (record == 0 || Field<std::uint32_t>(record, 0x00) == 0)
            continue;
        if (Field<std::uint32_t>(record, 0x30) != 0) {
            FUN_0018BCC8(0, &callback);
            callback(
                Field<std::uint32_t>(record, 0x2c),
                static_cast<std::uint32_t>(index + 0xf2),
                Field<std::uint32_t>(record, 0x00),
                Field<std::uint32_t>(record, 0x28));
        }
        Field<std::uint32_t>(record, 0x00) = 0;
        Field<std::uint32_t>(record, 0x04) = 0;
        Field<std::uint32_t>(record, 0x08) = 0;
        Field<std::uint32_t>(record, 0x30) = 0;
    }
}
extern "C" __attribute__((noinline)) void RenderDraw_SubmitPacket_00113294(
    void* context,
    void* packet,
    std::uint32_t view_index,
    const std::uint16_t* target_extent) {
    if (context == 0)
        FUN_00168590(0x0de1, 0x6790, &context);
    const std::uint32_t view_mask = 1u << view_index;
    DrawWorkspace workspace;
    workspace.target_class = SelectTargetClass(target_extent);
    workspace.view_mask = view_mask;
    workspace.flags = 0x10000000;
    const std::uint32_t view_count =
        RenderDraw_CountViewBits_0013BBD4(view_mask);
    const std::uint32_t allocation_size =
        ((view_count * 0x34u + 0x1fu) & ~0x1fu) + 0x780u;
    void* const allocation = FUN_0035F6A4(allocation_size, 0x20);
    RenderDraw_InitWorkspace_0013BC08(
        workspace.data, packet, 0x10000, allocation,
        workspace.target_class, workspace.view_mask, workspace.flags);
    void* const view_resource =
        Field<void*>(workspace.data, 0x70 + view_index * 4);
    if (view_resource != 0 &&
        Field<std::uint32_t>(workspace.data, 0x60) != view_index) {
        void* const owner = Field<void*>(workspace.data, 0x6c);
        std::uint32_t* const address_word = Field<std::uint32_t*>(owner, 0x734);
        if (address_word != 0) {
            const std::uint32_t address =
                Field<std::uint32_t>(view_resource, 0x28);
            *address_word =
                Platform_MapResourceAddress_003AC86C(address) >> 3;
        }
        Field<std::uint32_t>(workspace.data, 0x60) = view_index;
    }
    RenderDraw_EmitWorkspace_0013B630(
        context, workspace.data, view_index, target_extent);
    RenderCommand_FinalizeCurrentPacket_002A4618();
    FUN_0018BB6C();
    FUN_00168980();
    FUN_00168F0C();
    FUN_001688F0();
    FUN_0018BB6C();
    RenderDraw_DestroyWorkspace_0013B43C(workspace.data);
    FUN_0035F668(allocation);
}

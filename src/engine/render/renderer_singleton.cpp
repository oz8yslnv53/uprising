#include <cstddef>
#include <cstdint>
extern "C" int OnceGuard_TestAndSet_003B4FE4(std::uint32_t* guard);
extern "C" void* Engine_ForEachStrideCallback(
    void* base, void* callback, std::uint32_t stride, std::uint32_t count);
struct RenderContextClearSubBlockView {
    std::uint32_t words_000[3];
    std::uint8_t flag_00c;
    std::uint8_t opaque_00d[3];
};
struct RenderStateRecordView {
    std::uint32_t implementation_000;
    std::uint32_t value_004;
    float value_008;
};
struct RenderContextStateBlockView {
    RenderStateRecordView base;
    float value_00c;
};
struct RenderContextCommandBlockView {
    RenderStateRecordView base;
    std::uint32_t value_00c;
    std::uint8_t enabled_010;
    std::uint8_t opaque_011[3];
};
struct RenderContextView {
    std::uint32_t implementation_000;
    RenderContextClearSubBlockView sub_blocks_004[2];
    std::uint8_t flags_024[4];
    std::uint8_t opaque_028[0x630];
    float values_658[4];
    void* links_668[4];
    std::uint32_t values_678[3];
    std::uint8_t flag_684;
    std::uint8_t opaque_685[3];
};
struct RendererSingletonStorageView {
    std::uint8_t initialized_000;
    std::uint8_t opaque_001[3];
    RenderContextView context_004;
    std::uint32_t record_header_68c;
    std::uint8_t records_690[5][0x18];
    std::uint8_t opaque_708[0x14];
    RenderContextStateBlockView state_71c;
    RenderContextCommandBlockView command_72c;
    std::uint32_t state_740;
};
typedef char renderer_layout_1[
    (sizeof(RenderContextClearSubBlockView) == 0x10) ? 1 : -1];
typedef char renderer_layout_2[
    (offsetof(RenderContextView, values_658) == 0x658) ? 1 : -1];
typedef char renderer_layout_3[
    (offsetof(RenderContextView, links_668) == 0x668) ? 1 : -1];
typedef char renderer_layout_4[
    (sizeof(RenderContextView) == 0x688) ? 1 : -1];
typedef char renderer_layout_5[
    (offsetof(RendererSingletonStorageView, record_header_68c) == 0x68c)
        ? 1 : -1];
typedef char renderer_layout_6[
    (offsetof(RendererSingletonStorageView, records_690) == 0x690) ? 1 : -1];
typedef char renderer_layout_7[
    (offsetof(RendererSingletonStorageView, state_71c) == 0x71c) ? 1 : -1];
typedef char renderer_layout_8[
    (offsetof(RendererSingletonStorageView, command_72c) == 0x72c) ? 1 : -1];
typedef char renderer_layout_9[
    (offsetof(RendererSingletonStorageView, state_740) == 0x740) ? 1 : -1];
typedef char renderer_layout_10[
    (sizeof(RendererSingletonStorageView) == 0x744) ? 1 : -1];
extern "C" __attribute__((noinline)) void* RenderContext_ClearSubBlock_005D2488(void* block) {
    RenderContextClearSubBlockView* view =
        static_cast<RenderContextClearSubBlockView*>(block);
    view->words_000[0] = 0;
    view->words_000[1] = 0;
    view->words_000[2] = 0;
    view->flag_00c = 0;
    return block;
}
extern "C" __attribute__((noinline)) void* RenderStateRecord_Init_005D2618(void* record) {
    RenderStateRecordView* view = static_cast<RenderStateRecordView*>(record);
    view->implementation_000 = 0x00d16194;
    view->value_004 = 0;
    view->value_008 = 3.4028234663852886e+38f;
    return record;
}
extern "C" __attribute__((noinline)) void* RenderContext_Init_005CD768(void* context) {
    RenderContextView* view = static_cast<RenderContextView*>(context);
    std::uint8_t* bytes = static_cast<std::uint8_t*>(context);
    view->implementation_000 = 0x00d15754;
    RenderContext_ClearSubBlock_005D2488(&view->sub_blocks_004[0]);
    RenderContext_ClearSubBlock_005D2488(&view->sub_blocks_004[1]);
    view->flags_024[0] = 0;
    view->flags_024[1] = 0;
    view->flags_024[2] = 0;
    view->flags_024[3] = 0;
    view->values_658[0] = 0.0f;
    view->values_658[1] = 0.0f;
    view->values_658[2] = 0.0f;
    view->values_658[3] = 0.0f;
    view->links_668[0] = bytes + 0x94;
    view->links_668[1] = bytes + 0x244;
    view->links_668[2] = bytes + 0x454;
    view->links_668[3] = bytes + 0x284;
    view->values_678[0] = 0;
    view->values_678[1] = 0;
    view->values_678[2] = 0;
    view->flag_684 = 0;
    return context;
}
extern "C" __attribute__((noinline)) void* RenderContext_InitStateBlock_005CD9F4(void* state) {
    RenderContextStateBlockView* view =
        static_cast<RenderContextStateBlockView*>(
            RenderStateRecord_Init_005D2618(state));
    view->value_00c = 0.6f;
    view->base.implementation_000 = 0x00d16124;
    return view;
}
extern "C" __attribute__((noinline)) void* RenderContext_InitCommandBlock_005CDA18(void* state) {
    RenderContextCommandBlockView* view =
        static_cast<RenderContextCommandBlockView*>(
            RenderStateRecord_Init_005D2618(state));
    view->value_00c = 0;
    view->enabled_010 = 1;
    view->base.implementation_000 = 0x00d161ac;
    return view;
}
extern "C" __attribute__((noinline)) void* RenderContext_ClearState_005CDA80(void* state) {
    *static_cast<std::uint32_t*>(state) = 0;
    return state;
}
extern "C" __attribute__((noinline)) void* Engine_RendererSingleton_Init_005C80EC(void* renderer) {
    std::uint8_t* cursor = static_cast<std::uint8_t*>(renderer);
    reinterpret_cast<RendererSingletonStorageView*>(
        cursor)->initialized_000 = 0;
    cursor = static_cast<std::uint8_t*>(RenderContext_Init_005CD768(
        cursor + offsetof(RendererSingletonStorageView, context_004))) -
        offsetof(RendererSingletonStorageView, context_004);
    *reinterpret_cast<std::uint32_t*>(
        cursor + offsetof(RendererSingletonStorageView, record_header_68c)) =
        0;
    cursor = static_cast<std::uint8_t*>(Engine_ForEachStrideCallback(
        cursor + offsetof(RendererSingletonStorageView, records_690),
        reinterpret_cast<void*>(0x005cd928), 0x18, 5));
    cursor = static_cast<std::uint8_t*>(RenderContext_InitStateBlock_005CD9F4(
        cursor + offsetof(RendererSingletonStorageView, state_71c) -
            offsetof(RendererSingletonStorageView, records_690)));
    cursor = static_cast<std::uint8_t*>(
        RenderContext_InitCommandBlock_005CDA18(cursor + 0x10));
    cursor = static_cast<std::uint8_t*>(
        RenderContext_ClearState_005CDA80(cursor + 0x14));
    return cursor - 0x740;
}
extern "C" __attribute__((noinline)) void* Engine_RendererSingleton_Get_005C3CE4() {
    std::uint32_t* guard =
        reinterpret_cast<std::uint32_t*>(0x00d63730);
    void* renderer = reinterpret_cast<void*>(0x00f2dc9c);
    if ((*guard & 1u) == 0 &&
        OnceGuard_TestAndSet_003B4FE4(guard) != 0) {
        Engine_RendererSingleton_Init_005C80EC(renderer);
    }
    return renderer;
}

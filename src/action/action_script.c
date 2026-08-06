#include <stddef.h>
#include <stdint.h>
extern void StateParameterRecord_Init_003B530C(uint32_t *record);
extern void *ActionResource_ChannelWork_Lookup_00BB2DAC(void *tree);
extern void Engine_OrderedDescriptorSelect_00475718(
    uint32_t *output, void *owner, uint32_t mode, uint32_t key);
extern void PslMatClr_DescriptorSelect_004757AC(
    uint32_t *output, void *owner, uint32_t mode, uint32_t key);
extern void PslChr_ChangeAnimation_0054EC10(
    uint32_t *selected, uint32_t *name, int mode);
extern void PslMatClr_ChangeAnimation_00520398(
    uint32_t *selected, uint32_t *name, int mode);
extern void Engine_VirtualResourceCallback_00448728(
    void *resource, float frame);
extern void PslMatClr_ResourceRelease_0049B5D4(
    void *resource, float frame);
extern void FrameEnd_OptionalInitialize_0044A1CC(
    void *optional, void *descriptor);
extern int FrameEnd_OptionalHasValue_0044A1EC(void *optional);
extern int FrameEnd_OptionalIsTagged_00476B2C(void *optional);
extern void FrameEnd_OptionalClear_0044900C(void *optional);
extern float FrameEnd_DescriptorFrame_003FD85C(void *descriptor);
extern int FrameEnd_OptionalTruncate_00396090(void *optional);
extern void FrameEndChr_CompleteLane_00BB3F88(
    void *context, float threshold);
extern float FrameEnd_DescriptorDelta_00C86580(void *descriptor);
extern float FrameEnd_DescriptorPhase_0044A1A8(void *descriptor);
extern float FrameEnd_WrapPhase_00923724(float phase, float period);
extern int FrameEnd_ThresholdInWindow_00923788(
    float threshold, float first, float second);
extern void FrameEndMatClr_OptionalInitialize_004C5CFC(
    void *optional, void *descriptor);
extern int FrameEndMatClr_OptionalHasValue_004C5D2C(void *optional);
extern int FrameEndMatClr_OptionalIsTagged_00C86BC8(void *optional);
extern void FrameEndMatClr_OptionalClear_004C55F8(void *optional);
extern float FrameEndMatClr_DescriptorFrame_00C86698(void *descriptor);
extern int FrameEndMatClr_OptionalTruncate_00C86BB0(void *optional);
extern float FrameEndMatClr_DescriptorDelta_00C86674(void *descriptor);
extern float FrameEndMatClr_DescriptorPhase_00C866B0(void *descriptor);
extern void FrameEndMatClr_CompleteLane_00BB445C(
    void *context, float threshold);
extern void FrameEndShp_DescriptorSelect_004223FC(
    uint32_t *output, void *owner, uint32_t mode, uint32_t key);
extern void FrameEndShp_OptionalInitialize_003B84C8(
    void *optional, void *descriptor);
extern int FrameEndShp_OptionalHasValue_003B84E8(void *optional);
extern int FrameEndShp_OptionalIsTagged_00C86B30(void *optional);
extern void FrameEndShp_OptionalClear_003B5A78(void *optional);
extern float FrameEndShp_DescriptorFrame_00C865C8(void *descriptor);
extern int FrameEndShp_OptionalTruncate_00C86B18(void *optional);
extern float FrameEndShp_DescriptorDelta_00C865A4(void *descriptor);
extern float FrameEndShp_DescriptorPhase_00C865E0(void *descriptor);
extern void FrameEndShp_CompleteLane_00BB4124(
    void *context, float threshold);
extern void AnimeCommand_Channel_SelectLane34_00448D74(
    uint32_t *output, void *owner, uint32_t mode, uint32_t key);
extern void AnimeCommand_Channel_Lane34OptionalInit_004C5CDC(
    void *optional, void *descriptor);
extern int AnimeCommand_Channel_Lane34OptionalHasValue_004C5D1C(
    void *optional);
extern int AnimeCommand_Channel_Lane34OptionalIsTagged_00C86B7C(
    void *optional);
extern void AnimeCommand_Channel_Lane34OptionalClear_004C55E4(
    void *optional);
extern float AnimeCommand_Channel_Lane34DescriptorFrame_00C86638(
    void *descriptor);
extern int AnimeCommand_Channel_Lane34OptionalTruncate_00C86B64(
    void *optional);
extern float AnimeCommand_Channel_Lane34DescriptorDelta_00C86604(
    void *descriptor);
extern float AnimeCommand_Channel_Lane34DescriptorPhase_00C86650(
    void *descriptor);
extern void AnimeCommand_Channel_CompleteCallback_00BB42C0(
    void *context, float threshold);
extern void AnimeCommand_Channel_SelectLane2C_00448E08(
    uint32_t *output, void *owner, uint32_t mode, uint32_t key);
extern void AnimeCommand_Channel_Lane2COptionalInit_005C3D3C(
    void *optional, void *descriptor);
extern int AnimeCommand_Channel_Lane2COptionalHasValue_005C3D5C(
    void *optional);
extern int AnimeCommand_Channel_Lane2COptionalIsTagged_00C86C14(
    void *optional);
extern void AnimeCommand_Channel_Lane2COptionalClear_005C3C84(
    void *optional);
extern float AnimeCommand_Channel_Lane2CDescriptorFrame_00C866F8(
    void *descriptor);
extern int AnimeCommand_Channel_Lane2COptionalTruncate_00C86BFC(
    void *optional);
extern float AnimeCommand_Channel_Lane2CDescriptorDelta_00C866D4(
    void *descriptor);
extern float AnimeCommand_Channel_Lane2CDescriptorPhase_00C86710(
    void *descriptor);
extern void AnimeCommand_Channel_CompleteCallback_00BB45F8(
    void *context, float threshold);
extern void StateSelection_FindLowerBound(
    uint32_t *output, void *owner, uint32_t mode, uint32_t key);
extern void StateHandle_ReleasePayload(void *optional, void *descriptor);
extern int StateHandle_IsLive(void *optional);
extern int AnimeCommand_Channel_Lane30OptionalIsTagged_00C86C44(
    void *optional);
extern void StateHandle_Clear(void *optional);
extern float AnimeCommand_Channel_Lane30DescriptorFrame_00C86768(
    void *descriptor);
extern int AnimeCommand_Channel_Lane30OptionalTruncate_00C86C2C(
    void *optional);
extern float AnimeCommand_Channel_Lane30DescriptorDelta_00C86734(
    void *descriptor);
extern float AnimeCommand_Channel_Lane30DescriptorPhase_00C86780(
    void *descriptor);
extern void AnimeCommand_Channel_CompleteCallback_00BB4794(
    void *context, float threshold);
extern void PslShp_ChangeAnimation_003B5514(
    uint32_t *selected, uint32_t *name, int mode);
extern void PslShp_ResourceApply_003B55FC(
    void *resource, float frame);
extern void AnimeCommand_Channel_Lane34ChangeAnimation_003B56B0(
    uint32_t *selected, uint32_t *name, int mode);
extern void AnimeCommand_Channel_Lane34ResourceApply_004C54D4(
    void *resource, float frame);
extern void AnimeCommand_Channel_Lane2CChangeAnimation_00BB143C(
    uint32_t *selected, uint32_t *name, int mode);
extern void AnimeCommand_Channel_Lane2CResourceApply_005C3C68(
    void *resource, float frame);
extern void AnimeCommand_Channel_Lane30ChangeAnimation_003B5830(
    uint32_t *selected, uint32_t *name, int mode);
extern void StatePayload_Release(void *resource, float frame);
struct DodgeArmParameters {
    uint8_t kind_parameter;
    uint8_t set_component_bit_20;
};
struct ActionCommandAnimationView {
    uint8_t opaque_000[0x10];
    uint32_t name_010[2];
    uint8_t opaque_018[0x24];
    float frame_03c;
    int8_t mode_040;
};
struct ActionExecutionContextView {
    uint8_t state_000;
    uint8_t opaque_001[0x13];
    uint8_t *channel_source_014;
    void *descriptor_owner_018;
};
typedef char kiu_sa_action_script_1[(offsetof(struct ActionCommandAnimationView, name_010) == 0x10) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_action_script_2[(offsetof(struct ActionCommandAnimationView, frame_03c) == 0x3c) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_action_script_3[(offsetof(struct ActionCommandAnimationView, mode_040) == 0x40) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_action_script_4[(offsetof(struct ActionExecutionContextView, channel_source_014) == 0x14) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_action_script_5[(offsetof(struct ActionExecutionContextView, descriptor_owner_018) == 0x18) ? 1 : -1] __attribute__((unused));
static const int8_t dodge_kind_parameter[8] = {
    0, 0, 0, 1, 1, 0, 1, 0
};
__attribute__((noinline)) struct DodgeArmParameters
DodgeArmParametersForEvent(unsigned event_kind)
{
    struct DodgeArmParameters result = { 0, 0 };
    if (event_kind < sizeof(dodge_kind_parameter))
        result.kind_parameter =
            (uint8_t)dodge_kind_parameter[event_kind];
    result.set_component_bit_20 = event_kind == 6;
    return result;
}
__attribute__((noinline)) void PslActorCommand_End_Execute_00B4D560(void *command, void *context)
{
    struct ActionExecutionContextView *context_view =
        (struct ActionExecutionContextView *)context;
    (void)command;
    context_view->channel_source_014[0x24] = 0;
}
__attribute__((noinline)) void PslActorCommand_Endless_Execute_00B4E3A4(void *command, void *context)
{
    (void)command;
    *(uint8_t *)context = 0;
}
__attribute__((noinline)) void PslActorCommand_ChangeAnmChr_Execute_00C8BFEC(
    void *command, void *context)
{
    struct ActionCommandAnimationView *command_view =
        (struct ActionCommandAnimationView *)command;
    struct ActionExecutionContextView *context_view =
        (struct ActionExecutionContextView *)context;
    uint32_t name[2];
    uint32_t selected[3];
    uint32_t key = 0;
    void *work;
    if (context_view->descriptor_owner_018 == 0)
        return;
    StateParameterRecord_Init_003B530C(selected);
    selected[0] = command_view->name_010[0];
    selected[1] = command_view->name_010[1];
    name[0] = selected[0];
    name[1] = selected[1];
    work = ActionResource_ChannelWork_Lookup_00BB2DAC(
        context_view->channel_source_014 + 0x0c);
    if (work != 0)
        key = *(uint32_t *)((uint8_t *)work + 0x24);
    Engine_OrderedDescriptorSelect_00475718(
        selected, context_view->descriptor_owner_018, 0, key);
    PslChr_ChangeAnimation_0054EC10(
        selected, name, command_view->mode_040);
    Engine_VirtualResourceCallback_00448728(
        selected, command_view->frame_03c);
}
__attribute__((noinline)) void PslActorCommand_ChangeAnmMatClr_Execute_00C8CE2C(
    void *command, void *context)
{
    struct ActionCommandAnimationView *command_view =
        (struct ActionCommandAnimationView *)command;
    struct ActionExecutionContextView *context_view =
        (struct ActionExecutionContextView *)context;
    uint32_t name[2];
    uint32_t selected[3];
    uint32_t key = 0;
    void *work;
    if (context_view->descriptor_owner_018 == 0)
        return;
    StateParameterRecord_Init_003B530C(selected);
    selected[0] = command_view->name_010[0];
    selected[1] = command_view->name_010[1];
    name[0] = selected[0];
    name[1] = selected[1];
    work = ActionResource_ChannelWork_Lookup_00BB2DAC(
        context_view->channel_source_014 + 0x0c);
    if (work != 0)
        key = *(uint32_t *)((uint8_t *)work + 0x28);
    PslMatClr_DescriptorSelect_004757AC(
        selected, context_view->descriptor_owner_018, 0, key);
    PslMatClr_ChangeAnimation_00520398(
        selected, name, command_view->mode_040);
    PslMatClr_ResourceRelease_0049B5D4(
        selected, command_view->frame_03c);
}
__attribute__((noinline)) void PslActorCommand_FrameEndChr_Execute_00C8949C(
    void *command, void *context)
{
    struct ActionExecutionContextView *context_view =
        (struct ActionExecutionContextView *)context;
    uint32_t selected[3];
    uint32_t optional[2];
    uint32_t key = 0;
    void *work;
    float threshold;
    (void)command;
    if (context_view->descriptor_owner_018 == 0)
        return;
    work = ActionResource_ChannelWork_Lookup_00BB2DAC(
        context_view->channel_source_014 + 0x0c);
    if (work != 0)
        key = *(uint32_t *)((uint8_t *)work + 0x24);
    Engine_OrderedDescriptorSelect_00475718(
        selected, context_view->descriptor_owner_018, 0, key);
    FrameEnd_OptionalInitialize_0044A1CC(optional, selected);
    if (!FrameEnd_OptionalHasValue_0044A1EC(optional) ||
        FrameEnd_OptionalIsTagged_00476B2C(optional)) {
        FrameEnd_OptionalClear_0044900C(optional);
        return;
    }
    threshold = FrameEnd_DescriptorFrame_003FD85C(selected) >= 0.0f
        ? (float)FrameEnd_OptionalTruncate_00396090(optional)
        : 0.0f;
    FrameEndChr_CompleteLane_00BB3F88(context, threshold);
    FrameEnd_OptionalClear_0044900C(optional);
}
__attribute__((noinline)) void FrameEndChr_CompleteLane_00BB3F88(void *context, float threshold)
{
    struct ActionExecutionContextView *context_view =
        (struct ActionExecutionContextView *)context;
    uint32_t selected[3];
    uint32_t optional[2];
    uint32_t key = 0;
    void *work;
    float offset;
    float delta;
    float phase;
    float window;
    int tagged;
    work = ActionResource_ChannelWork_Lookup_00BB2DAC(
        context_view->channel_source_014 + 0x0c);
    if (work != 0)
        key = *(uint32_t *)((uint8_t *)work + 0x24);
    Engine_OrderedDescriptorSelect_00475718(
        selected, context_view->descriptor_owner_018, 0, key);
    FrameEnd_OptionalInitialize_0044A1CC(optional, selected);
    if (!FrameEnd_OptionalHasValue_0044A1EC(optional)) {
        context_view->state_000 = 1;
        FrameEnd_OptionalClear_0044900C(optional);
        return;
    }
    offset = (float)FrameEnd_OptionalTruncate_00396090(optional);
    delta = FrameEnd_DescriptorDelta_00C86580(selected);
    phase = FrameEnd_WrapPhase_00923724(
        FrameEnd_DescriptorPhase_0044A1A8(selected), 1.0f / 1024.0f);
    window = FrameEnd_WrapPhase_00923724(
        FrameEnd_DescriptorPhase_0044A1A8(selected) - delta,
        1.0f / 1024.0f);
    tagged = FrameEnd_OptionalIsTagged_00476B2C(optional);
    if (!tagged && delta != 0.0f) {
        if ((delta >= 0.0f && window <= threshold) ||
            (delta < 0.0f && threshold <= window)) {
            FrameEnd_OptionalClear_0044900C(optional);
            return;
        }
    }
    context_view->state_000 = (uint8_t)FrameEnd_ThresholdInWindow_00923788(
        threshold, window, phase);
    if (context_view->state_000 == 0 &&
        FrameEnd_OptionalHasValue_0044A1EC(optional) &&
        FrameEnd_OptionalIsTagged_00476B2C(optional)) {
        if (delta < 0.0f)
            offset = -offset;
        context_view->state_000 = (uint8_t)FrameEnd_ThresholdInWindow_00923788(
            threshold, window + offset, phase + offset);
    }
    FrameEnd_OptionalClear_0044900C(optional);
}
__attribute__((noinline)) void PslActorCommand_FrameEndMatClr_Execute_00C89FD0(
    void *command, void *context)
{
    struct ActionExecutionContextView *context_view =
        (struct ActionExecutionContextView *)context;
    uint32_t selected[3];
    uint32_t optional[2];
    uint32_t key = 0;
    void *work;
    float threshold;
    (void)command;
    if (context_view->descriptor_owner_018 == 0)
        return;
    work = ActionResource_ChannelWork_Lookup_00BB2DAC(
        context_view->channel_source_014 + 0x0c);
    if (work != 0)
        key = *(uint32_t *)((uint8_t *)work + 0x28);
    PslMatClr_DescriptorSelect_004757AC(
        selected, context_view->descriptor_owner_018, 0, key);
    FrameEndMatClr_OptionalInitialize_004C5CFC(optional, selected);
    if (!FrameEndMatClr_OptionalHasValue_004C5D2C(optional) ||
        FrameEndMatClr_OptionalIsTagged_00C86BC8(optional)) {
        FrameEndMatClr_OptionalClear_004C55F8(optional);
        return;
    }
    threshold = FrameEndMatClr_DescriptorFrame_00C86698(selected) >= 0.0f
        ? (float)FrameEndMatClr_OptionalTruncate_00C86BB0(optional)
        : 0.0f;
    FrameEndMatClr_CompleteLane_00BB445C(context, threshold);
    FrameEndMatClr_OptionalClear_004C55F8(optional);
}
__attribute__((noinline)) void FrameEndMatClr_CompleteLane_00BB445C(void *context, float threshold)
{
    struct ActionExecutionContextView *context_view =
        (struct ActionExecutionContextView *)context;
    uint32_t selected[3];
    uint32_t optional[2];
    uint32_t key = 0;
    void *work;
    float offset;
    float delta;
    float phase;
    float window;
    int tagged;
    work = ActionResource_ChannelWork_Lookup_00BB2DAC(
        context_view->channel_source_014 + 0x0c);
    if (work != 0)
        key = *(uint32_t *)((uint8_t *)work + 0x28);
    PslMatClr_DescriptorSelect_004757AC(
        selected, context_view->descriptor_owner_018, 0, key);
    FrameEndMatClr_OptionalInitialize_004C5CFC(optional, selected);
    if (!FrameEndMatClr_OptionalHasValue_004C5D2C(optional)) {
        context_view->state_000 = 1;
        FrameEndMatClr_OptionalClear_004C55F8(optional);
        return;
    }
    offset = (float)FrameEndMatClr_OptionalTruncate_00C86BB0(optional);
    delta = FrameEndMatClr_DescriptorDelta_00C86674(selected);
    phase = FrameEnd_WrapPhase_00923724(
        FrameEndMatClr_DescriptorPhase_00C866B0(selected),
        1.0f / 1024.0f);
    window = FrameEnd_WrapPhase_00923724(
        FrameEndMatClr_DescriptorPhase_00C866B0(selected) - delta,
        1.0f / 1024.0f);
    tagged = FrameEndMatClr_OptionalIsTagged_00C86BC8(optional);
    if (!tagged && delta != 0.0f) {
        if ((delta >= 0.0f && window <= threshold) ||
            (delta < 0.0f && threshold <= window)) {
            FrameEndMatClr_OptionalClear_004C55F8(optional);
            return;
        }
    }
    context_view->state_000 = (uint8_t)FrameEnd_ThresholdInWindow_00923788(
        threshold, window, phase);
    if (context_view->state_000 == 0 &&
        FrameEndMatClr_OptionalHasValue_004C5D2C(optional) &&
        FrameEndMatClr_OptionalIsTagged_00C86BC8(optional)) {
        if (delta < 0.0f)
            offset = -offset;
        context_view->state_000 = (uint8_t)FrameEnd_ThresholdInWindow_00923788(
            threshold, window + offset, phase + offset);
    }
    FrameEndMatClr_OptionalClear_004C55F8(optional);
}
__attribute__((noinline)) void PslActorCommand_FrameEndShp_Execute_00C89858(
    void *command, void *context)
{
    struct ActionExecutionContextView *context_view =
        (struct ActionExecutionContextView *)context;
    uint32_t selected[3];
    uint32_t optional[2];
    uint32_t key = 0;
    void *work;
    float threshold;
    (void)command;
    if (context_view->descriptor_owner_018 == 0)
        return;
    work = ActionResource_ChannelWork_Lookup_00BB2DAC(
        context_view->channel_source_014 + 0x0c);
    if (work != 0)
        key = *(uint32_t *)((uint8_t *)work + 0x38);
    FrameEndShp_DescriptorSelect_004223FC(
        selected, context_view->descriptor_owner_018, 0, key);
    FrameEndShp_OptionalInitialize_003B84C8(optional, selected);
    if (!FrameEndShp_OptionalHasValue_003B84E8(optional) ||
        FrameEndShp_OptionalIsTagged_00C86B30(optional)) {
        FrameEndShp_OptionalClear_003B5A78(optional);
        return;
    }
    threshold = FrameEndShp_DescriptorFrame_00C865C8(selected) >= 0.0f
        ? (float)FrameEndShp_OptionalTruncate_00C86B18(optional)
        : 0.0f;
    FrameEndShp_CompleteLane_00BB4124(context, threshold);
    FrameEndShp_OptionalClear_003B5A78(optional);
}
__attribute__((noinline)) void FrameEndShp_CompleteLane_00BB4124(void *context, float threshold)
{
    struct ActionExecutionContextView *context_view =
        (struct ActionExecutionContextView *)context;
    uint32_t selected[3];
    uint32_t optional[2];
    uint32_t key = 0;
    void *work;
    float offset;
    float delta;
    float phase;
    float window;
    int tagged;
    work = ActionResource_ChannelWork_Lookup_00BB2DAC(
        context_view->channel_source_014 + 0x0c);
    if (work != 0)
        key = *(uint32_t *)((uint8_t *)work + 0x38);
    FrameEndShp_DescriptorSelect_004223FC(
        selected, context_view->descriptor_owner_018, 0, key);
    FrameEndShp_OptionalInitialize_003B84C8(optional, selected);
    if (!FrameEndShp_OptionalHasValue_003B84E8(optional)) {
        context_view->state_000 = 1;
        FrameEndShp_OptionalClear_003B5A78(optional);
        return;
    }
    offset = (float)FrameEndShp_OptionalTruncate_00C86B18(optional);
    delta = FrameEndShp_DescriptorDelta_00C865A4(selected);
    phase = FrameEnd_WrapPhase_00923724(
        FrameEndShp_DescriptorPhase_00C865E0(selected),
        1.0f / 1024.0f);
    window = FrameEnd_WrapPhase_00923724(
        FrameEndShp_DescriptorPhase_00C865E0(selected) - delta,
        1.0f / 1024.0f);
    tagged = FrameEndShp_OptionalIsTagged_00C86B30(optional);
    if (!tagged && delta != 0.0f) {
        if ((delta >= 0.0f && window <= threshold) ||
            (delta < 0.0f && threshold <= window)) {
            FrameEndShp_OptionalClear_003B5A78(optional);
            return;
        }
    }
    context_view->state_000 = (uint8_t)FrameEnd_ThresholdInWindow_00923788(
        threshold, window, phase);
    if (context_view->state_000 == 0 &&
        FrameEndShp_OptionalHasValue_003B84E8(optional) &&
        FrameEndShp_OptionalIsTagged_00C86B30(optional)) {
        if (delta < 0.0f)
            offset = -offset;
        context_view->state_000 = (uint8_t)FrameEnd_ThresholdInWindow_00923788(
            threshold, window + offset, phase + offset);
    }
    FrameEndShp_OptionalClear_003B5A78(optional);
}
__attribute__((noinline)) void AnimeCommand_Channel_WorkCallback_00C89C14(void *command, void *context)
{
    struct ActionExecutionContextView *context_view =
        (struct ActionExecutionContextView *)context;
    uint32_t selected[3];
    uint32_t optional[2];
    uint32_t key = 0;
    void *work;
    float threshold;
    (void)command;
    if (context_view->descriptor_owner_018 == 0)
        return;
    work = ActionResource_ChannelWork_Lookup_00BB2DAC(
        context_view->channel_source_014 + 0x0c);
    if (work != 0)
        key = *(uint32_t *)((uint8_t *)work + 0x34);
    AnimeCommand_Channel_SelectLane34_00448D74(
        selected, context_view->descriptor_owner_018, 0, key);
    AnimeCommand_Channel_Lane34OptionalInit_004C5CDC(optional, selected);
    if (!AnimeCommand_Channel_Lane34OptionalHasValue_004C5D1C(optional) ||
        AnimeCommand_Channel_Lane34OptionalIsTagged_00C86B7C(optional)) {
        AnimeCommand_Channel_Lane34OptionalClear_004C55E4(optional);
        return;
    }
    threshold = AnimeCommand_Channel_Lane34DescriptorFrame_00C86638(selected)
            >= 0.0f
        ? (float)AnimeCommand_Channel_Lane34OptionalTruncate_00C86B64(optional)
        : 0.0f;
    AnimeCommand_Channel_CompleteCallback_00BB42C0(context, threshold);
    AnimeCommand_Channel_Lane34OptionalClear_004C55E4(optional);
}
__attribute__((noinline)) void AnimeCommand_Channel_CompleteCallback_00BB42C0(
    void *context, float threshold)
{
    struct ActionExecutionContextView *context_view =
        (struct ActionExecutionContextView *)context;
    uint32_t selected[3];
    uint32_t optional[2];
    uint32_t key = 0;
    void *work;
    float offset;
    float delta;
    float phase;
    float window;
    int tagged;
    work = ActionResource_ChannelWork_Lookup_00BB2DAC(
        context_view->channel_source_014 + 0x0c);
    if (work != 0)
        key = *(uint32_t *)((uint8_t *)work + 0x34);
    AnimeCommand_Channel_SelectLane34_00448D74(
        selected, context_view->descriptor_owner_018, 0, key);
    AnimeCommand_Channel_Lane34OptionalInit_004C5CDC(optional, selected);
    if (!AnimeCommand_Channel_Lane34OptionalHasValue_004C5D1C(optional)) {
        context_view->state_000 = 1;
        AnimeCommand_Channel_Lane34OptionalClear_004C55E4(optional);
        return;
    }
    offset = (float)AnimeCommand_Channel_Lane34OptionalTruncate_00C86B64(optional);
    delta = AnimeCommand_Channel_Lane34DescriptorDelta_00C86604(selected);
    phase = FrameEnd_WrapPhase_00923724(
        AnimeCommand_Channel_Lane34DescriptorPhase_00C86650(selected),
        1.0f / 1024.0f);
    window = FrameEnd_WrapPhase_00923724(
        AnimeCommand_Channel_Lane34DescriptorPhase_00C86650(selected) - delta,
        1.0f / 1024.0f);
    tagged = AnimeCommand_Channel_Lane34OptionalIsTagged_00C86B7C(optional);
    if (!tagged && delta != 0.0f) {
        if ((delta >= 0.0f && window <= threshold) ||
            (delta < 0.0f && threshold <= window)) {
            AnimeCommand_Channel_Lane34OptionalClear_004C55E4(optional);
            return;
        }
    }
    context_view->state_000 = (uint8_t)FrameEnd_ThresholdInWindow_00923788(
        threshold, window, phase);
    if (context_view->state_000 == 0 &&
        AnimeCommand_Channel_Lane34OptionalHasValue_004C5D1C(optional) &&
        AnimeCommand_Channel_Lane34OptionalIsTagged_00C86B7C(optional)) {
        if (delta < 0.0f)
            offset = -offset;
        context_view->state_000 = (uint8_t)FrameEnd_ThresholdInWindow_00923788(
            threshold, window + offset, phase + offset);
    }
    AnimeCommand_Channel_Lane34OptionalClear_004C55E4(optional);
}
__attribute__((noinline)) void AnimeCommand_Channel_WorkCallback_00C8A38C(void *command, void *context)
{
    struct ActionExecutionContextView *context_view =
        (struct ActionExecutionContextView *)context;
    uint32_t selected[3];
    uint32_t optional[2];
    uint32_t key = 0;
    void *work;
    float threshold;
    (void)command;
    if (context_view->descriptor_owner_018 == 0)
        return;
    work = ActionResource_ChannelWork_Lookup_00BB2DAC(
        context_view->channel_source_014 + 0x0c);
    if (work != 0)
        key = *(uint32_t *)((uint8_t *)work + 0x2c);
    AnimeCommand_Channel_SelectLane2C_00448E08(
        selected, context_view->descriptor_owner_018, 0, key);
    AnimeCommand_Channel_Lane2COptionalInit_005C3D3C(optional, selected);
    if (!AnimeCommand_Channel_Lane2COptionalHasValue_005C3D5C(optional) ||
        AnimeCommand_Channel_Lane2COptionalIsTagged_00C86C14(optional)) {
        AnimeCommand_Channel_Lane2COptionalClear_005C3C84(optional);
        return;
    }
    threshold = AnimeCommand_Channel_Lane2CDescriptorFrame_00C866F8(selected)
            >= 0.0f
        ? (float)AnimeCommand_Channel_Lane2COptionalTruncate_00C86BFC(optional)
        : 0.0f;
    AnimeCommand_Channel_CompleteCallback_00BB45F8(context, threshold);
    AnimeCommand_Channel_Lane2COptionalClear_005C3C84(optional);
}
__attribute__((noinline)) void AnimeCommand_Channel_CompleteCallback_00BB45F8(
    void *context, float threshold)
{
    struct ActionExecutionContextView *context_view =
        (struct ActionExecutionContextView *)context;
    uint32_t selected[3];
    uint32_t optional[2];
    uint32_t key = 0;
    void *work;
    float offset;
    float delta;
    float phase;
    float window;
    int tagged;
    work = ActionResource_ChannelWork_Lookup_00BB2DAC(
        context_view->channel_source_014 + 0x0c);
    if (work != 0)
        key = *(uint32_t *)((uint8_t *)work + 0x2c);
    AnimeCommand_Channel_SelectLane2C_00448E08(
        selected, context_view->descriptor_owner_018, 0, key);
    AnimeCommand_Channel_Lane2COptionalInit_005C3D3C(optional, selected);
    if (!AnimeCommand_Channel_Lane2COptionalHasValue_005C3D5C(optional)) {
        context_view->state_000 = 1;
        AnimeCommand_Channel_Lane2COptionalClear_005C3C84(optional);
        return;
    }
    offset = (float)AnimeCommand_Channel_Lane2COptionalTruncate_00C86BFC(optional);
    delta = AnimeCommand_Channel_Lane2CDescriptorDelta_00C866D4(selected);
    phase = FrameEnd_WrapPhase_00923724(
        AnimeCommand_Channel_Lane2CDescriptorPhase_00C86710(selected),
        1.0f / 1024.0f);
    window = FrameEnd_WrapPhase_00923724(
        AnimeCommand_Channel_Lane2CDescriptorPhase_00C86710(selected) - delta,
        1.0f / 1024.0f);
    tagged = AnimeCommand_Channel_Lane2COptionalIsTagged_00C86C14(optional);
    if (!tagged && delta != 0.0f) {
        if ((delta >= 0.0f && window <= threshold) ||
            (delta < 0.0f && threshold <= window)) {
            AnimeCommand_Channel_Lane2COptionalClear_005C3C84(optional);
            return;
        }
    }
    context_view->state_000 = (uint8_t)FrameEnd_ThresholdInWindow_00923788(
        threshold, window, phase);
    if (context_view->state_000 == 0 &&
        AnimeCommand_Channel_Lane2COptionalHasValue_005C3D5C(optional) &&
        AnimeCommand_Channel_Lane2COptionalIsTagged_00C86C14(optional)) {
        if (delta < 0.0f)
            offset = -offset;
        context_view->state_000 = (uint8_t)FrameEnd_ThresholdInWindow_00923788(
            threshold, window + offset, phase + offset);
    }
    AnimeCommand_Channel_Lane2COptionalClear_005C3C84(optional);
}
__attribute__((noinline)) void AnimeCommand_Channel_WorkCallback_00C8A748(void *command, void *context)
{
    struct ActionExecutionContextView *context_view =
        (struct ActionExecutionContextView *)context;
    uint32_t selected[3];
    uint32_t optional[2];
    uint32_t key = 0;
    void *work;
    float threshold;
    (void)command;
    if (context_view->descriptor_owner_018 == 0)
        return;
    work = ActionResource_ChannelWork_Lookup_00BB2DAC(
        context_view->channel_source_014 + 0x0c);
    if (work != 0)
        key = *(uint32_t *)((uint8_t *)work + 0x30);
    StateSelection_FindLowerBound(
        selected, context_view->descriptor_owner_018, 0, key);
    StateHandle_ReleasePayload(optional, selected);
    if (!StateHandle_IsLive(optional) ||
        AnimeCommand_Channel_Lane30OptionalIsTagged_00C86C44(optional)) {
        StateHandle_Clear(optional);
        return;
    }
    threshold = AnimeCommand_Channel_Lane30DescriptorFrame_00C86768(selected)
            >= 0.0f
        ? (float)AnimeCommand_Channel_Lane30OptionalTruncate_00C86C2C(optional)
        : 0.0f;
    AnimeCommand_Channel_CompleteCallback_00BB4794(context, threshold);
    StateHandle_Clear(optional);
}
__attribute__((noinline)) void AnimeCommand_Channel_CompleteCallback_00BB4794(
    void *context, float threshold)
{
    struct ActionExecutionContextView *context_view =
        (struct ActionExecutionContextView *)context;
    uint32_t selected[3];
    uint32_t optional[2];
    uint32_t key = 0;
    void *work;
    float offset;
    float delta;
    float phase;
    float window;
    int tagged;
    work = ActionResource_ChannelWork_Lookup_00BB2DAC(
        context_view->channel_source_014 + 0x0c);
    if (work != 0)
        key = *(uint32_t *)((uint8_t *)work + 0x30);
    StateSelection_FindLowerBound(
        selected, context_view->descriptor_owner_018, 0, key);
    StateHandle_ReleasePayload(optional, selected);
    if (!StateHandle_IsLive(optional)) {
        context_view->state_000 = 1;
        StateHandle_Clear(optional);
        return;
    }
    offset = (float)AnimeCommand_Channel_Lane30OptionalTruncate_00C86C2C(optional);
    delta = AnimeCommand_Channel_Lane30DescriptorDelta_00C86734(selected);
    phase = FrameEnd_WrapPhase_00923724(
        AnimeCommand_Channel_Lane30DescriptorPhase_00C86780(selected),
        1.0f / 1024.0f);
    window = FrameEnd_WrapPhase_00923724(
        AnimeCommand_Channel_Lane30DescriptorPhase_00C86780(selected) - delta,
        1.0f / 1024.0f);
    tagged = AnimeCommand_Channel_Lane30OptionalIsTagged_00C86C44(optional);
    if (!tagged && delta != 0.0f) {
        if ((delta >= 0.0f && window <= threshold) ||
            (delta < 0.0f && threshold <= window)) {
            StateHandle_Clear(optional);
            return;
        }
    }
    context_view->state_000 = (uint8_t)FrameEnd_ThresholdInWindow_00923788(
        threshold, window, phase);
    if (context_view->state_000 == 0 && StateHandle_IsLive(optional) &&
        AnimeCommand_Channel_Lane30OptionalIsTagged_00C86C44(optional)) {
        if (delta < 0.0f)
            offset = -offset;
        context_view->state_000 = (uint8_t)FrameEnd_ThresholdInWindow_00923788(
            threshold, window + offset, phase + offset);
    }
    StateHandle_Clear(optional);
}
__attribute__((noinline)) void PslActorCommand_ChangeAnmShp_Execute_00C8C4AC(
    void *command, void *context)
{
    struct ActionCommandAnimationView *command_view =
        (struct ActionCommandAnimationView *)command;
    struct ActionExecutionContextView *context_view =
        (struct ActionExecutionContextView *)context;
    uint32_t name[2];
    uint32_t selected[3];
    uint32_t key = 0;
    void *work;
    if (context_view->descriptor_owner_018 == 0)
        return;
    StateParameterRecord_Init_003B530C(selected);
    selected[0] = command_view->name_010[0];
    selected[1] = command_view->name_010[1];
    name[0] = selected[0];
    name[1] = selected[1];
    work = ActionResource_ChannelWork_Lookup_00BB2DAC(
        context_view->channel_source_014 + 0x0c);
    if (work != 0)
        key = *(uint32_t *)((uint8_t *)work + 0x38);
    FrameEndShp_DescriptorSelect_004223FC(
        selected, context_view->descriptor_owner_018, 0, key);
    PslShp_ChangeAnimation_003B5514(
        selected, name, command_view->mode_040);
    PslShp_ResourceApply_003B55FC(
        selected, command_view->frame_03c);
}
__attribute__((noinline)) void AnimeCommand_Channel_ChangeAnmCallback_00C8C96C(
    void *command, void *context)
{
    struct ActionCommandAnimationView *command_view =
        (struct ActionCommandAnimationView *)command;
    struct ActionExecutionContextView *context_view =
        (struct ActionExecutionContextView *)context;
    uint32_t name[2];
    uint32_t selected[3];
    uint32_t key = 0;
    void *work;
    if (context_view->descriptor_owner_018 == 0)
        return;
    StateParameterRecord_Init_003B530C(selected);
    selected[0] = command_view->name_010[0];
    selected[1] = command_view->name_010[1];
    name[0] = selected[0];
    name[1] = selected[1];
    work = ActionResource_ChannelWork_Lookup_00BB2DAC(
        context_view->channel_source_014 + 0x0c);
    if (work != 0)
        key = *(uint32_t *)((uint8_t *)work + 0x34);
    AnimeCommand_Channel_SelectLane34_00448D74(
        selected, context_view->descriptor_owner_018, 0, key);
    AnimeCommand_Channel_Lane34ChangeAnimation_003B56B0(
        selected, name, command_view->mode_040);
    AnimeCommand_Channel_Lane34ResourceApply_004C54D4(
        selected, command_view->frame_03c);
}
__attribute__((noinline)) void AnimeCommand_Channel_ChangeAnmCallback_00C8D2EC(
    void *command, void *context)
{
    struct ActionCommandAnimationView *command_view =
        (struct ActionCommandAnimationView *)command;
    struct ActionExecutionContextView *context_view =
        (struct ActionExecutionContextView *)context;
    uint32_t name[2];
    uint32_t selected[3];
    uint32_t key = 0;
    void *work;
    if (context_view->descriptor_owner_018 == 0)
        return;
    StateParameterRecord_Init_003B530C(selected);
    selected[0] = command_view->name_010[0];
    selected[1] = command_view->name_010[1];
    name[0] = selected[0];
    name[1] = selected[1];
    work = ActionResource_ChannelWork_Lookup_00BB2DAC(
        context_view->channel_source_014 + 0x0c);
    if (work != 0)
        key = *(uint32_t *)((uint8_t *)work + 0x2c);
    AnimeCommand_Channel_SelectLane2C_00448E08(
        selected, context_view->descriptor_owner_018, 0, key);
    AnimeCommand_Channel_Lane2CChangeAnimation_00BB143C(
        selected, name, command_view->mode_040);
    AnimeCommand_Channel_Lane2CResourceApply_005C3C68(
        selected, command_view->frame_03c);
}
__attribute__((noinline)) void AnimeCommand_Channel_ChangeAnmCallback_00C8D7AC(
    void *command, void *context)
{
    struct ActionCommandAnimationView *command_view =
        (struct ActionCommandAnimationView *)command;
    struct ActionExecutionContextView *context_view =
        (struct ActionExecutionContextView *)context;
    uint32_t name[2];
    uint32_t selected[3];
    uint32_t key = 0;
    void *work;
    if (context_view->descriptor_owner_018 == 0)
        return;
    StateParameterRecord_Init_003B530C(selected);
    selected[0] = command_view->name_010[0];
    selected[1] = command_view->name_010[1];
    name[0] = selected[0];
    name[1] = selected[1];
    work = ActionResource_ChannelWork_Lookup_00BB2DAC(
        context_view->channel_source_014 + 0x0c);
    if (work != 0)
        key = *(uint32_t *)((uint8_t *)work + 0x30);
    StateSelection_FindLowerBound(
        selected, context_view->descriptor_owner_018, 0, key);
    AnimeCommand_Channel_Lane30ChangeAnimation_003B5830(
        selected, name, command_view->mode_040);
    StatePayload_Release(selected, command_view->frame_03c);
}
__attribute__((noinline)) void PslShp_ResourceApply_003B55FC(void *resource, float frame)
{
    void *payload = *(void **)((uint8_t *)resource + 0x04);
    if (payload != 0)
        (*(void (**)(void *, float))(*(uint32_t **)payload + 0x0b))(
            payload, frame);
}
__attribute__((noinline)) void AnimeCommand_Channel_Lane34ResourceApply_004C54D4(
    void *resource, float frame)
{
    void *payload = *(void **)((uint8_t *)resource + 0x04);
    if (payload != 0)
        (*(void (**)(void *, float))(*(uint32_t **)payload + 0x0b))(
            payload, frame);
}
__attribute__((noinline)) void AnimeCommand_Channel_Lane2CResourceApply_005C3C68(
    void *resource, float frame)
{
    void *payload = *(void **)((uint8_t *)resource + 0x04);
    if (payload != 0)
        (*(void (**)(void *, float))(*(uint32_t **)payload + 0x0b))(
            payload, frame);
}

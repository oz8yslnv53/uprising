#include <cstdint>
#include <cmath>
extern "C" int Engine_IsAvailable_003B4FE4(void* lazy_slot);
extern "C" void* Engine_CommandObjectFactory_001898B8(void* slot,
                                                        void* class_data,
                                                        std::uint32_t size);
extern "C" void* StatusLazySingleton_0054EFA8();
static void AnimeSound_ApplyBgmCommand_005567F4(void* sound_state,
                                                 std::uint32_t id,
                                                 std::uint32_t fade,
                                                 int through);
__attribute__((noinline)) static void AnimeSound_ApplyBgmVolume_00537D8C(void* sound_state,
                                                std::uint32_t fade,
                                                int mode,
                                                float volume);
extern "C" void* Engine_LazySingletonGetter_003FD6E0();
extern "C" void* Engine_LazySingletonGetter_004EEFBC();
extern "C" void AudioChannel_Stop_0048D320(void* dispatcher,
                                            std::uint32_t handle,
                                            std::int32_t duration_ms);
extern "C" std::uint32_t EffectEvent_Dispatch_0036C330(
    void* dispatcher, std::uint32_t event_id, std::uint32_t event_type,
    void* record, std::uint32_t flags);
extern "C" void EffectEvent_QueueVolumeRecord_00566CA4(
    void* record_header, std::uint32_t handle, void* payload);
extern "C" void* Engine_AllocateTaggedBlock_0047466C(
    std::uint32_t element_size, void* type_tag, std::uint32_t count);
extern "C" void* Engine_LazyZeroSingleton_00BAE6BC();
static std::uint32_t* AnimeCommand_AllocateLinked_00AE3BBC(
    std::uint32_t size, std::uintptr_t type_tag, std::uintptr_t class_data,
    std::uint32_t count) {
    std::uint32_t* command = static_cast<std::uint32_t*>(Engine_AllocateTaggedBlock_0047466C(
        size, reinterpret_cast<void*>(type_tag), count));
    if (command == 0) {
        return 0;
    }
    for (std::uint32_t i = 0; i != size / sizeof(std::uint32_t); ++i) {
        command[i] = 0;
    }
    command[1] = reinterpret_cast<std::uintptr_t>(command);
    command[2] = reinterpret_cast<std::uintptr_t>(command + 1);
    command[3] = reinterpret_cast<std::uintptr_t>(command + 1);
    command[0] = class_data;
    return command;
}
static void AnimeCommand_RegisterParallel_00AE4AC4(
    std::uint32_t* out, std::uintptr_t state, std::uint32_t state_offset,
    std::uintptr_t lazy_slot, std::uintptr_t descriptor_slot,
    std::uintptr_t type_tag, std::uint32_t size, std::uintptr_t class_data) {
    if (((*reinterpret_cast<const std::uint32_t*>(state + state_offset) & 1u) ==
             0u) &&
        Engine_IsAvailable_003B4FE4(reinterpret_cast<void*>(lazy_slot)) != 0) {
        void* descriptor = Engine_CommandObjectFactory_001898B8(
            reinterpret_cast<void*>(descriptor_slot),
            reinterpret_cast<void*>(type_tag), size);
        *static_cast<void**>(descriptor) = reinterpret_cast<void*>(class_data);
    }
    *out = static_cast<std::uint32_t>(descriptor_slot);
}
static void* AnimeCommand_ClassDataSingleton_00AE3D48(
    std::uintptr_t outer_slot, std::uintptr_t outer_result_slot,
    std::uintptr_t inner_slot, std::uintptr_t inner_result_slot) {
    if (((*reinterpret_cast<const std::uint32_t*>(outer_slot) & 1u) == 0u) &&
        Engine_IsAvailable_003B4FE4(reinterpret_cast<void*>(outer_slot)) != 0) {
        if (((*reinterpret_cast<const std::uint32_t*>(inner_slot) & 1u) == 0u) &&
            Engine_IsAvailable_003B4FE4(reinterpret_cast<void*>(inner_slot)) !=
                0) {
            *reinterpret_cast<void**>(inner_result_slot) =
                Engine_LazyZeroSingleton_00BAE6BC();
        }
        *reinterpret_cast<void**>(outer_result_slot) =
            reinterpret_cast<void*>(inner_result_slot);
    }
    return reinterpret_cast<void*>(outer_result_slot);
}
static std::uint32_t* AnimeCommand_CopyRegistered_00AE3C2C(
    std::uint32_t size, std::uintptr_t type_tag, std::uintptr_t class_data,
    std::uintptr_t outer_slot, std::uintptr_t outer_result_slot,
    std::uintptr_t inner_slot, std::uintptr_t inner_result_slot,
    std::uint32_t count, std::uint32_t* source, std::uint32_t field_count) {
    void* sentinel = AnimeCommand_ClassDataSingleton_00AE3D48(
        outer_slot, outer_result_slot, inner_slot, inner_result_slot);
    typedef void*(*ListHeadFn)(void*);
    ListHeadFn* vtable = *reinterpret_cast<ListHeadFn**>(source);
    void* node = vtable[0](source);
    while (node != 0 && node != sentinel) {
        node = *reinterpret_cast<void**>(node);
    }
    if (node == 0) {
        return 0;
    }
    std::uint32_t* copy = static_cast<std::uint32_t*>(Engine_AllocateTaggedBlock_0047466C(
        size, reinterpret_cast<void*>(type_tag), count));
    if (copy == 0) {
        return 0;
    }
    copy[1] = reinterpret_cast<std::uintptr_t>(copy);
    copy[2] = reinterpret_cast<std::uintptr_t>(copy + 1);
    copy[3] = reinterpret_cast<std::uintptr_t>(copy + 1);
    copy[0] = class_data;
    for (std::uint32_t i = 0; i != field_count; ++i) {
        copy[4 + i] = source[4 + i];
    }
    return copy;
}
extern "C" __attribute__((noinline)) std::uint32_t* AnimeCommand_PauseTrack_Constructor_00AAE8DC(
    std::uint32_t, std::uint32_t count) {
    return AnimeCommand_AllocateLinked_00AE3BBC(
        0x14u, 0x00AAE93Cu, 0x00D05F24u, count);
}
extern "C" __attribute__((noinline)) std::uint32_t* AnimeCommand_PauseTrack_Copy_00AAE944(
    std::uint32_t, std::uint32_t count, std::uint32_t* source) {
    void* sentinel = AnimeCommand_ClassDataSingleton_00AE3D48(
        0x00D600DCu, 0x00D600E0u, 0x00D61C3Cu, 0x00D61C40u);
    typedef void*(*ListHeadFn)(void*);
    ListHeadFn* vtable = *reinterpret_cast<ListHeadFn**>(source);
    void* node = vtable[0](source);
    while (node != 0 && node != sentinel)
        node = *reinterpret_cast<void**>(node);
    if (node == 0)
        return 0;
    std::uint32_t* copy = static_cast<std::uint32_t*>(Engine_AllocateTaggedBlock_0047466C(
        0x14u, reinterpret_cast<void*>(0x00AAEA48u), count));
    if (copy == 0)
        return 0;
    copy[1] = reinterpret_cast<std::uintptr_t>(copy);
    copy[2] = reinterpret_cast<std::uintptr_t>(copy + 1);
    copy[3] = reinterpret_cast<std::uintptr_t>(copy + 1);
    copy[0] = 0x00D05F24u;
    reinterpret_cast<std::uint8_t*>(copy)[0x10] =
        reinterpret_cast<const std::uint8_t*>(source)[0x10];
    return copy;
}
extern "C" __attribute__((noinline)) void* AnimeCommand_PauseTrack_ClassDataSingleton_00AAEA50() {
    return AnimeCommand_ClassDataSingleton_00AE3D48(
        0x00D600DCu, 0x00D600E0u, 0x00D61C3Cu, 0x00D61C40u);
}
extern "C" __attribute__((noinline)) std::uint32_t* AnimeCommand_PlayBGM_Constructor_00AE3BBC(
    std::uint32_t, std::uint32_t count) {
    return AnimeCommand_AllocateLinked_00AE3BBC(
        0x1Cu, 0x00AE3C24u, 0x00D0BEA4u, count);
}
static std::uint32_t* AnimeCommand_AllocateLinked24_00AE4888(
    std::uintptr_t type_tag, std::uintptr_t class_data, std::uint32_t count) {
    std::uint32_t* command = static_cast<std::uint32_t*>(
        Engine_AllocateTaggedBlock_0047466C(
            0x18u, reinterpret_cast<void*>(type_tag), count));
    if (command == 0)
        return 0;
    command[0] = 0;
    command[1] = 0;
    command[2] = 0;
    command[3] = 0;
    command[4] = 0;
    command[5] = 0;
    command[1] = reinterpret_cast<std::uintptr_t>(command + 1);
    command[2] = reinterpret_cast<std::uintptr_t>(command + 1);
    command[1] = reinterpret_cast<std::uintptr_t>(command);
    command[3] = reinterpret_cast<std::uintptr_t>(command + 1);
    command[0] = class_data;
    return command;
}
extern "C" __attribute__((noinline)) std::uint32_t* AnimeCommand_StopBGM_Constructor_00AE4888(
    std::uint32_t, std::uint32_t count) {
    return AnimeCommand_AllocateLinked24_00AE4888(
        0x00AE48ECu, 0x00D0BFE4u, count);
}
extern "C" __attribute__((noinline)) std::uint32_t* AnimeCommand_BGMVolume_Constructor_00AE76FC(
    std::uint32_t, std::uint32_t count) {
    return AnimeCommand_AllocateLinked24_00AE4888(
        0x00AE7760u, 0x00D0C388u, count);
}
extern "C" __attribute__((noinline)) std::uint32_t* AnimeCommand_PlayVoice_Constructor_00AEA0A8(
    std::uint32_t, std::uint32_t count) {
    return AnimeCommand_AllocateLinked_00AE3BBC(
        0x14u, 0x00AEA108u, 0x00D0C680u, count);
}
extern "C" __attribute__((noinline)) void AnimeCommand_StopBGM_RegistrationFactory_00AE4AC4(
    std::uint32_t* out) {
    AnimeCommand_RegisterParallel_00AE4AC4(
        out, 0x00D3AAB8u, 0x88u, 0x00D3AB40u, 0x00D6B6F0u, 0x00C9ACACu,
        0x18u, 0x00D0BFC8u);
}
extern "C" __attribute__((noinline)) void AnimeCommand_PlayBGM_RegistrationFactory_00AE3E04(
    std::uint32_t* out) {
    AnimeCommand_RegisterParallel_00AE4AC4(
        out, 0x00D3AAB8u, 0x84u, 0x00D3AB3Cu, 0x00D6B6C4u, 0x00C9AC94u,
        0x1Cu, 0x00D0BE88u);
}
extern "C" __attribute__((noinline)) void AnimeCommand_BGMVolume_RegistrationFactory_00AE7938(
    std::uint32_t* out) {
    AnimeCommand_RegisterParallel_00AE4AC4(
        out, 0x00D3AAB8u, 0x8Cu, 0x00D3AB44u, 0x00D6B71Cu, 0x00C9ACC4u,
        0x18u, 0x00D0C36Cu);
}
extern "C" __attribute__((noinline)) void AnimeCommand_PlayVoice_RegistrationFactory_00AEA314(
    std::uint32_t* out) {
    AnimeCommand_RegisterParallel_00AE4AC4(
        out, 0x00D3AAB8u, 0x90u, 0x00D3AB48u, 0x00D6B748u, 0x00C9ACE0u,
        0x14u, 0x00D0C664u);
}
extern "C" __attribute__((noinline)) void* AnimeCommand_PlayBGM_ClassDataSingleton_00AE3D48() {
    return AnimeCommand_ClassDataSingleton_00AE3D48(
        0x00D60AACu, 0x00D60AB0u, 0x00D62524u, 0x00D62528u);
}
extern "C" __attribute__((noinline)) void* AnimeCommand_StopBGM_ClassDataSingleton_00AE4A08() {
    return AnimeCommand_ClassDataSingleton_00AE3D48(
        0x00D60ACCu, 0x00D60AD0u, 0x00D6253Cu, 0x00D62540u);
}
extern "C" __attribute__((noinline)) void* AnimeCommand_BGMVolume_ClassDataSingleton_00AE787C() {
    return AnimeCommand_ClassDataSingleton_00AE3D48(
        0x00D60B2Cu, 0x00D60B30u, 0x00D62594u, 0x00D62598u);
}
extern "C" __attribute__((noinline)) void* AnimeCommand_PlayVoice_ClassDataSingleton_00AEA21C() {
    return AnimeCommand_ClassDataSingleton_00AE3D48(
        0x00D60B7Cu, 0x00D60B80u, 0x00D625E4u, 0x00D625E8u);
}
extern "C" __attribute__((noinline)) std::uint32_t* AnimeCommand_PlayBGM_Copy_00AE3C2C(
    std::uint32_t, std::uint32_t count, std::uint32_t* source) {
    return AnimeCommand_CopyRegistered_00AE3C2C(
        0x1Cu, 0x00AE3D40u, 0x00D0BEA4u, 0x00D60AACu, 0x00D60AB0u,
        0x00D62524u, 0x00D62528u, count, source, 3);
}
extern "C" __attribute__((noinline)) std::uint32_t* AnimeCommand_StopBGM_Copy_00AE48F4(
    std::uint32_t, std::uint32_t count, std::uint32_t* source) {
    return AnimeCommand_CopyRegistered_00AE3C2C(
        0x18u, 0x00AE4A00u, 0x00D0BFE4u, 0x00D60ACCu, 0x00D60AD0u,
        0x00D6253Cu, 0x00D62540u, count, source, 2);
}
extern "C" __attribute__((noinline)) std::uint32_t* AnimeCommand_BGMVolume_Copy_00AE7768(
    std::uint32_t, std::uint32_t count, std::uint32_t* source) {
    return AnimeCommand_CopyRegistered_00AE3C2C(
        0x18u, 0x00AE7874u, 0x00D0C388u, 0x00D60B2Cu, 0x00D60B30u,
        0x00D62594u, 0x00D62598u, count, source, 2);
}
extern "C" __attribute__((noinline)) std::uint32_t* AnimeCommand_PlayVoice_Copy_00AEA110(
    std::uint32_t, std::uint32_t count, std::uint32_t* source) {
    return AnimeCommand_CopyRegistered_00AE3C2C(
        0x14u, 0x00AEA214u, 0x00D0C680u, 0x00D60B7Cu, 0x00D60B80u,
        0x00D625E4u, 0x00D625E8u, count, source, 1);
}
extern "C" __attribute__((noinline)) void* AnimeCommand_PlayBGM_Factory_00126FC8() {
    const std::uintptr_t kFactoryState = 0x00D3AAB8;
    const std::uintptr_t kLazySlot = 0x00D3AB3C;
    const std::uintptr_t kDescriptorSlot = 0x00D6B6C4;
    const std::uintptr_t kClassData = 0x00D0BE88;
    if (((*reinterpret_cast<const std::uint32_t*>(kFactoryState + 0x84) & 1u) ==
             0u) &&
        Engine_IsAvailable_003B4FE4(reinterpret_cast<void*>(kLazySlot)) != 0) {
        void* descriptor = Engine_CommandObjectFactory_001898B8(
            reinterpret_cast<void*>(kDescriptorSlot),
            reinterpret_cast<void*>(0x00C9AC94), 0x1Cu);
        *static_cast<void**>(descriptor) = reinterpret_cast<void*>(kClassData);
    }
    return *reinterpret_cast<void**>(kDescriptorSlot);
}
extern "C" __attribute__((noinline)) void* AnimeCommand_StopBGM_Factory_00127124() {
    const std::uintptr_t kFactoryState = 0x00D3AAB8;
    const std::uintptr_t kLazySlot = 0x00D3AB40;
    const std::uintptr_t kDescriptorSlot = 0x00D6B6F0;
    const std::uintptr_t kClassData = 0x00D0BFC8;
    if (((*reinterpret_cast<const std::uint32_t*>(kFactoryState + 0x88) & 1u) ==
             0u) &&
        Engine_IsAvailable_003B4FE4(reinterpret_cast<void*>(kLazySlot)) != 0) {
        void* descriptor = Engine_CommandObjectFactory_001898B8(
            reinterpret_cast<void*>(kDescriptorSlot),
            reinterpret_cast<void*>(0x00C9ACAC), 0x18u);
        *static_cast<void**>(descriptor) = reinterpret_cast<void*>(kClassData);
    }
    return *reinterpret_cast<void**>(kDescriptorSlot);
}
extern "C" __attribute__((noinline)) void* AnimeCommand_BGMVolume_Factory_00127620() {
    const std::uintptr_t kFactoryState = 0x00D3AAB8;
    const std::uintptr_t kLazySlot = 0x00D3AB44;
    const std::uintptr_t kDescriptorSlot = 0x00D6B71C;
    const std::uintptr_t kClassData = 0x00D0C36C;
    if (((*reinterpret_cast<const std::uint32_t*>(kFactoryState + 0x8c) & 1u) ==
             0u) &&
        Engine_IsAvailable_003B4FE4(reinterpret_cast<void*>(kLazySlot)) != 0) {
        void* descriptor = Engine_CommandObjectFactory_001898B8(
            reinterpret_cast<void*>(kDescriptorSlot),
            reinterpret_cast<void*>(0x00C9ACC4), 0x18u);
        *static_cast<void**>(descriptor) = reinterpret_cast<void*>(kClassData);
    }
    return *reinterpret_cast<void**>(kDescriptorSlot);
}
extern "C" __attribute__((noinline)) void* AnimeCommand_PlayVoice_Factory_00127AA8() {
    const std::uintptr_t kFactoryState = 0x00D3AAB8;
    const std::uintptr_t kLazySlot = 0x00D3AB48;
    const std::uintptr_t kDescriptorSlot = 0x00D6B748;
    const std::uintptr_t kClassData = 0x00D0C664;
    if (((*reinterpret_cast<const std::uint32_t*>(kFactoryState + 0x90) & 1u) ==
             0u) &&
        Engine_IsAvailable_003B4FE4(reinterpret_cast<void*>(kLazySlot)) != 0) {
        void* descriptor = Engine_CommandObjectFactory_001898B8(
            reinterpret_cast<void*>(kDescriptorSlot),
            reinterpret_cast<void*>(0x00C9ACE0), 0x14u);
        *static_cast<void**>(descriptor) = reinterpret_cast<void*>(kClassData);
    }
    return *reinterpret_cast<void**>(kDescriptorSlot);
}
extern "C" __attribute__((noinline)) void* AnimeCommand_PlaySE_Factory_0012672C() {
    const std::uintptr_t kDescriptorSlot = 0x00D6B538;
    if (((*reinterpret_cast<const std::uint32_t*>(0x00D3AAB8 + 0x60) & 1u) ==
             0u) &&
        Engine_IsAvailable_003B4FE4(reinterpret_cast<void*>(0x00D3AB18)) != 0) {
        void* descriptor = Engine_CommandObjectFactory_001898B8(
            reinterpret_cast<void*>(kDescriptorSlot),
            reinterpret_cast<void*>(0x00C9AB78), 0x50u);
        *static_cast<void**>(descriptor) = reinterpret_cast<void*>(0x00D0BAAC);
    }
    return *reinterpret_cast<void**>(kDescriptorSlot);
}
extern "C" __attribute__((noinline)) void* AnimeCommand_StopSE_Factory_00126814() {
    const std::uintptr_t kDescriptorSlot = 0x00D6B4B4;
    if (((*reinterpret_cast<const std::uint32_t*>(0x00D3AAB8 + 0x54) & 1u) ==
             0u) &&
        Engine_IsAvailable_003B4FE4(reinterpret_cast<void*>(0x00D3AB0C)) != 0) {
        void* descriptor = Engine_CommandObjectFactory_001898B8(
            reinterpret_cast<void*>(kDescriptorSlot),
            reinterpret_cast<void*>(0x00C9AB48), 0x3Cu);
        *static_cast<void**>(descriptor) = reinterpret_cast<void*>(0x00D0BB44);
    }
    return *reinterpret_cast<void**>(kDescriptorSlot);
}
extern "C" __attribute__((noinline)) void* AnimeCommand_PlaySECommon_Factory_0011EA90() {
    const std::uintptr_t kDescriptorSlot = 0x00D6B774;
    if (((*reinterpret_cast<const std::uint32_t*>(0x00D3AAB8 + 0x94) & 1u) ==
             0u) &&
        Engine_IsAvailable_003B4FE4(reinterpret_cast<void*>(0x00D3AB4C)) != 0) {
        void* descriptor = Engine_CommandObjectFactory_001898B8(
            reinterpret_cast<void*>(kDescriptorSlot),
            reinterpret_cast<void*>(0x00C9ACFC), 0x14u);
        *static_cast<void**>(descriptor) = reinterpret_cast<void*>(0x00D0713C);
    }
    return *reinterpret_cast<void**>(kDescriptorSlot);
}
extern "C" __attribute__((noinline)) void* AnimeCommand_PauseTrack_Factory_0011C978() {
    const std::uintptr_t kDescriptorSlot = 0x00D6A568;
    if (((*reinterpret_cast<const std::uint32_t*>(0x00D3A9A4 + 0xa4) & 1u) ==
             0u) &&
        Engine_IsAvailable_003B4FE4(reinterpret_cast<void*>(0x00D3A9A4)) != 0) {
        void* descriptor = Engine_CommandObjectFactory_001898B8(
            reinterpret_cast<void*>(kDescriptorSlot),
            reinterpret_cast<void*>(0x00C9A738), 0x14u);
        *static_cast<void**>(descriptor) = reinterpret_cast<void*>(0x00D05F08);
    }
    return *reinterpret_cast<void**>(kDescriptorSlot);
}
extern "C" void* ResourceTree_KeyGetter_00481C7C();
extern "C" void* OrderedTree_LowerBoundByPointer_004C5D3C(
    void* tree, void* key);
extern "C" __attribute__((noinline)) void AnimeCommand_PauseTrack_Execute_00AAEAD4(
    void* command, void* context) {
    std::uint8_t* context_bytes = static_cast<std::uint8_t*>(context);
    std::uint8_t* resource = *reinterpret_cast<std::uint8_t**>(context_bytes + 0x04);
    std::uint8_t* node = static_cast<std::uint8_t*>(
        OrderedTree_LowerBoundByPointer_004C5D3C(
            resource + 0x1a4, ResourceTree_KeyGetter_00481C7C()));
    std::uint8_t* payload = node == 0
                        ? static_cast<std::uint8_t*>(0)
                        : *reinterpret_cast<std::uint8_t**>(node);
    std::uint8_t* sentinel = *reinterpret_cast<std::uint8_t**>(resource + 0x1a8);
    if (payload != sentinel) {
        payload[0x1d1] = *reinterpret_cast<const std::uint8_t*>(
            static_cast<const std::uint8_t*>(command) + 0x10);
    }
}
extern "C" void ParameterDescriptor_BuildFlagged_00BACD90(
    std::uint32_t* descriptor, const void* name, void* target);
extern "C" __attribute__((noinline)) void AnimeCommand_PauseTrack_ParameterRegistrar_0072D2F0(
    void* parameter_block, void* registrar) {
    std::uint32_t descriptor[6] = {};
    ParameterDescriptor_BuildFlagged_00BACD90(
        descriptor, reinterpret_cast<const void*>(0x0072D328),
        static_cast<std::uint8_t*>(parameter_block) + 0x10);
    typedef void(*RegisterFn)(void*, const void*);
    RegisterFn* vtable = *reinterpret_cast<RegisterFn**>(registrar);
    vtable[2](registrar, descriptor);
}
extern "C" void ParameterDescriptor_BuildString_00BACBB4(
    std::uint32_t* descriptor, const void* name, void* target);
extern "C" __attribute__((noinline)) void AnimeCommand_NameOfSE_ParameterRegistrar_0073D240(
    void* parameter_block, void* registrar) {
    std::uint32_t descriptor[6] = {};
    ParameterDescriptor_BuildString_00BACBB4(
        descriptor, reinterpret_cast<const void*>(0x0073D278),
        static_cast<std::uint8_t*>(parameter_block) + 0x10);
    typedef void(*RegisterFn)(void*, const void*);
    RegisterFn* vtable = *reinterpret_cast<RegisterFn**>(registrar);
    vtable[2](registrar, descriptor);
}
extern "C" void ParameterDescriptor_BuildInteger_00BAC4E8(
    std::uint32_t* descriptor, const void* name, void* target);
extern "C" void ParameterString_Format_003FDA9C(
    void* output, std::uint32_t capacity, const void* format,
    std::uint32_t value);
extern "C" __attribute__((noinline)) void AnimeCommand_NameOfSE_ChannelRegistrarBody_00BB4940(
    void* registrar, void* target) {
    std::uint8_t formatted[32] = {};
    std::uint32_t descriptor[5] = {};
    ParameterString_Format_003FDA9C(
        formatted, 0x1fu, reinterpret_cast<const void*>(0x00BB499C), 0);
    ParameterDescriptor_BuildString_00BACBB4(descriptor, formatted, target);
    typedef void(*RegisterFn)(void*, const void*);
    RegisterFn* vtable = *reinterpret_cast<RegisterFn**>(registrar);
    vtable[2](registrar, descriptor);
}
extern "C" __attribute__((noinline)) void AnimeCommand_NameOfSE_ChannelRegistrarTail_00BB3F14(
    void* parameter_block, void* registrar) {
    AnimeCommand_NameOfSE_ChannelRegistrarBody_00BB4940(
        registrar, static_cast<std::uint8_t*>(parameter_block) + 0x10);
}
extern "C" __attribute__((noinline)) void AnimeCommand_NameOfSE_ChannelRegistrar_0073D294(
    void* parameter_block, void* registrar) {
    std::uint32_t descriptor[5] = {};
    ParameterDescriptor_BuildInteger_00BAC4E8(
        descriptor, reinterpret_cast<const void*>(0x0073D2DC),
        static_cast<std::uint8_t*>(parameter_block) + 0x3C);
    typedef void(*RegisterFn)(void*, const void*);
    RegisterFn* vtable = *reinterpret_cast<RegisterFn**>(registrar);
    vtable[2](registrar, descriptor);
    AnimeCommand_NameOfSE_ChannelRegistrarTail_00BB3F14(
        parameter_block, registrar);
}
extern "C" __attribute__((noinline)) void AnimeCommand_NameOfSEWork_RegistrationFactory_00AE6F18(
    void** output) {
    const std::uintptr_t kDescriptorSlot = 0x00D6B4E0;
    if (((*reinterpret_cast<const std::uint32_t*>(0x00D3AAB8 + 0x58) & 1u) ==
             0u) &&
        Engine_IsAvailable_003B4FE4(reinterpret_cast<void*>(0x00D3AB10)) != 0) {
        void* descriptor = Engine_CommandObjectFactory_001898B8(
            reinterpret_cast<void*>(kDescriptorSlot),
            reinterpret_cast<void*>(0x00C9AB28), 0x40u);
        *static_cast<void**>(descriptor) = reinterpret_cast<void*>(0x00D0C244);
    }
    *output = *reinterpret_cast<void**>(kDescriptorSlot);
}
extern "C" __attribute__((noinline)) void AnimeCommand_NameOfSE_RegistrationFactory_00AE6F94(
    void** output) {
    const std::uintptr_t kDescriptorSlot = 0x00D6B50C;
    if (((*reinterpret_cast<const std::uint32_t*>(0x00D3AAB8 + 0x5c) & 1u) ==
             0u) &&
        Engine_IsAvailable_003B4FE4(reinterpret_cast<void*>(0x00D3AB14)) != 0) {
        void* descriptor = Engine_CommandObjectFactory_001898B8(
            reinterpret_cast<void*>(kDescriptorSlot),
            reinterpret_cast<void*>(0x00C9AB60), 0x3cu);
        *static_cast<void**>(descriptor) = reinterpret_cast<void*>(0x00D0C228);
    }
    *output = *reinterpret_cast<void**>(kDescriptorSlot);
}
extern "C" __attribute__((noinline)) void* AnimeCommand_NameOfSE_ClassDataSingleton_00AE6B60() {
    if (((*reinterpret_cast<const std::uint32_t*>(0x00D60B0C) & 1u) == 0u) &&
        Engine_IsAvailable_003B4FE4(reinterpret_cast<void*>(0x00D60B0C)) != 0) {
        if (((*reinterpret_cast<const std::uint32_t*>(0x00D6257C) & 1u) ==
                 0u) &&
            Engine_IsAvailable_003B4FE4(
                reinterpret_cast<void*>(0x00D6257C)) != 0) {
            *reinterpret_cast<void**>(0x00D62580) =
                Engine_LazyZeroSingleton_00BAE6BC();
        }
        *reinterpret_cast<void**>(0x00D60B10) =
            reinterpret_cast<void*>(0x00D62580);
    }
    return reinterpret_cast<void*>(0x00D60B10);
}
extern "C" __attribute__((noinline)) void AnimeCommand_PauseTrack_RegistrationFactory_00AAEB30(
    void** output) {
    const std::uintptr_t kDescriptorSlot = 0x00D6A568;
    if (((*reinterpret_cast<const std::uint32_t*>(0x00D3A9A4 + 0xa4) & 1u) ==
             0u) &&
        Engine_IsAvailable_003B4FE4(reinterpret_cast<void*>(0x00D3A9A4)) != 0) {
        void* descriptor = Engine_CommandObjectFactory_001898B8(
            reinterpret_cast<void*>(kDescriptorSlot),
            reinterpret_cast<void*>(0x00C9A738), 0x14u);
        *static_cast<void**>(descriptor) = reinterpret_cast<void*>(0x00D05F08);
    }
    *output = *reinterpret_cast<void**>(kDescriptorSlot);
}
extern "C" __attribute__((noinline)) void* AnimeCommand_PlaySELabel_Factory_0011D22C() {
    const std::uintptr_t kDescriptorSlot = 0x00D6B564;
    if (((*reinterpret_cast<const std::uint32_t*>(0x00D3AAB8 + 0x64) & 1u) ==
             0u) &&
        Engine_IsAvailable_003B4FE4(reinterpret_cast<void*>(0x00D3AB1C)) != 0) {
        void* descriptor = Engine_CommandObjectFactory_001898B8(
            reinterpret_cast<void*>(kDescriptorSlot),
            reinterpret_cast<void*>(0x00C9AB90), 0x78u);
        *static_cast<void**>(descriptor) = reinterpret_cast<void*>(0x00D065E0);
    }
    return *reinterpret_cast<void**>(kDescriptorSlot);
}
extern "C" __attribute__((noinline)) void AnimeCommand_PlaySELabel_RegistrationFactory_00AB364C(
    void** output) {
    const std::uintptr_t kDescriptorSlot = 0x00D6B564;
    if (((*reinterpret_cast<const std::uint32_t*>(0x00D3AAB8 + 0x64) & 1u) ==
             0u) &&
        Engine_IsAvailable_003B4FE4(reinterpret_cast<void*>(0x00D3AB1C)) != 0) {
        void* descriptor = Engine_CommandObjectFactory_001898B8(
            reinterpret_cast<void*>(kDescriptorSlot),
            reinterpret_cast<void*>(0x00C9AB90), 0x78u);
        *static_cast<void**>(descriptor) = reinterpret_cast<void*>(0x00D065E0);
    }
    *output = *reinterpret_cast<void**>(kDescriptorSlot);
}
extern "C" __attribute__((noinline)) void* AnimeCommand_PlayMiracleSE_Factory_00120138() {
    const std::uintptr_t kDescriptorSlot = 0x00D6B5BC;
    if (((*reinterpret_cast<const std::uint32_t*>(0x00D3AAB8 + 0x6c) & 1u) ==
             0u) &&
        Engine_IsAvailable_003B4FE4(reinterpret_cast<void*>(0x00D3AB24)) != 0) {
        void* descriptor = Engine_CommandObjectFactory_001898B8(
            reinterpret_cast<void*>(kDescriptorSlot),
            reinterpret_cast<void*>(0x00C9ABC8), 0x50u);
        *static_cast<void**>(descriptor) = reinterpret_cast<void*>(0x00D07CEC);
    }
    return *reinterpret_cast<void**>(kDescriptorSlot);
}
extern "C" __attribute__((noinline)) void* AnimeCommand_PlayFootStepSE_Factory_0012102C() {
    const std::uintptr_t kDescriptorSlot = 0x00D6B66C;
    if (((*reinterpret_cast<const std::uint32_t*>(0x00D3AAB8 + 0x7c) & 1u) ==
             0u) &&
        Engine_IsAvailable_003B4FE4(reinterpret_cast<void*>(0x00D3AB34)) != 0) {
        void* descriptor = Engine_CommandObjectFactory_001898B8(
            reinterpret_cast<void*>(kDescriptorSlot),
            reinterpret_cast<void*>(0x00C9AC58), 0x3cu);
        *static_cast<void**>(descriptor) = reinterpret_cast<void*>(0x00D08558);
    }
    return *reinterpret_cast<void**>(kDescriptorSlot);
}
extern "C" __attribute__((noinline)) void* AnimeCommand_SetVehicleSEID_Factory_0012176C() {
    const std::uintptr_t kDescriptorSlot = 0x00D674C4;
    if (((*reinterpret_cast<const std::uint32_t*>(0x00D3A1A0 + 0x300) & 1u) ==
             0u) &&
        Engine_IsAvailable_003B4FE4(reinterpret_cast<void*>(0x00D3A4A0)) != 0) {
        void* descriptor = Engine_CommandObjectFactory_001898B8(
            reinterpret_cast<void*>(kDescriptorSlot),
            reinterpret_cast<void*>(0x00C99A34), 0x18u);
        *static_cast<void**>(descriptor) = reinterpret_cast<void*>(0x00D08850);
    }
    return *reinterpret_cast<void**>(kDescriptorSlot);
}
extern "C" __attribute__((noinline)) void AnimeCommand_SetVehicleSEID_RegistrationFactory_00AC5D5C(
    void** out_descriptor) {
    const std::uintptr_t kDescriptorSlot = 0x00D674C4;
    if (((*reinterpret_cast<const std::uint32_t*>(0x00D3A1A0 + 0x300) & 1u) ==
             0u) &&
        Engine_IsAvailable_003B4FE4(reinterpret_cast<void*>(0x00D3A4A0)) != 0) {
        void* descriptor = Engine_CommandObjectFactory_001898B8(
            reinterpret_cast<void*>(kDescriptorSlot),
            reinterpret_cast<void*>(0x00C99A34), 0x18u);
        *static_cast<void**>(descriptor) = reinterpret_cast<void*>(0x00D08850);
    }
    *out_descriptor = *reinterpret_cast<void**>(kDescriptorSlot);
}
extern "C" __attribute__((noinline)) void* AnimeCommand_PlayEnvironmentSE_Factory_0012468C() {
    const std::uintptr_t kDescriptorSlot = 0x00D6B5E8;
    if (((*reinterpret_cast<const std::uint32_t*>(0x00D3AAB8 + 0x70) & 1u) ==
             0u) &&
        Engine_IsAvailable_003B4FE4(reinterpret_cast<void*>(0x00D3AB28)) != 0) {
        void* descriptor = Engine_CommandObjectFactory_001898B8(
            reinterpret_cast<void*>(kDescriptorSlot),
            reinterpret_cast<void*>(0x00C9ABE8), 0x4cu);
        *static_cast<void**>(descriptor) = reinterpret_cast<void*>(0x00D0A140);
    }
    return *reinterpret_cast<void**>(kDescriptorSlot);
}
extern "C" __attribute__((noinline)) void* AnimeCommand_PlayEnvironmentSEPos_Factory_001255F4() {
    const std::uintptr_t kDescriptorSlot = 0x00D6B614;
    if (((*reinterpret_cast<const std::uint32_t*>(0x00D3AAB8 + 0x74) & 1u) ==
             0u) &&
        Engine_IsAvailable_003B4FE4(reinterpret_cast<void*>(0x00D3AB2C)) != 0) {
        void* descriptor = Engine_CommandObjectFactory_001898B8(
            reinterpret_cast<void*>(kDescriptorSlot),
            reinterpret_cast<void*>(0x00C9AC0C), 0x24u);
        *static_cast<void**>(descriptor) = reinterpret_cast<void*>(0x00D0ACDC);
    }
    return *reinterpret_cast<void**>(kDescriptorSlot);
}
extern "C" __attribute__((noinline)) void* AnimeCommand_PlayEnvironmentSELine_Factory_00125920() {
    const std::uintptr_t kDescriptorSlot = 0x00D6B640;
    if (((*reinterpret_cast<const std::uint32_t*>(0x00D3AAB8 + 0x78) & 1u) ==
             0u) &&
        Engine_IsAvailable_003B4FE4(reinterpret_cast<void*>(0x00D3AB30)) != 0) {
        void* descriptor = Engine_CommandObjectFactory_001898B8(
            reinterpret_cast<void*>(kDescriptorSlot),
            reinterpret_cast<void*>(0x00C9AC30), 0x30u);
        *static_cast<void**>(descriptor) = reinterpret_cast<void*>(0x00D0AEF0);
    }
    return *reinterpret_cast<void**>(kDescriptorSlot);
}
extern "C" __attribute__((noinline)) void* AnimeCommand_SetSoundFXReturnLevel_Factory_00125A08() {
    const std::uintptr_t kDescriptorSlot = 0x00D6B7CC;
    if (((*reinterpret_cast<const std::uint32_t*>(0x00D3AAB8 + 0x9c) & 1u) ==
             0u) &&
        Engine_IsAvailable_003B4FE4(reinterpret_cast<void*>(0x00D3AB54)) != 0) {
        void* descriptor = Engine_CommandObjectFactory_001898B8(
            reinterpret_cast<void*>(kDescriptorSlot),
            reinterpret_cast<void*>(0x00C9AD34), 0x18u);
        *static_cast<void**>(descriptor) = reinterpret_cast<void*>(0x00D0AF88);
    }
    return *reinterpret_cast<void**>(kDescriptorSlot);
}
extern "C" __attribute__((noinline)) void* AnimeCommand_NameOfSE_Factory_001274C4() {
    const std::uintptr_t kDescriptorSlot = 0x00D6B50C;
    if (((*reinterpret_cast<const std::uint32_t*>(0x00D3AAB8 + 0x5c) & 1u) ==
             0u) &&
        Engine_IsAvailable_003B4FE4(reinterpret_cast<void*>(0x00D3AB14)) != 0) {
        void* descriptor = Engine_CommandObjectFactory_001898B8(
            reinterpret_cast<void*>(kDescriptorSlot),
            reinterpret_cast<void*>(0x00C9AB60), 0x3cu);
        *static_cast<void**>(descriptor) = reinterpret_cast<void*>(0x00D0C228);
    }
    return *reinterpret_cast<void**>(kDescriptorSlot);
}
extern "C" __attribute__((noinline)) void* AnimeCommand_PlayDamageSE_Factory_0011EA1C() {
    const std::uintptr_t kDescriptorSlot = 0x00D6B7A0;
    if (((*reinterpret_cast<const std::uint32_t*>(0x00D3AAB8 + 0x98) & 1u) ==
             0u) &&
        Engine_IsAvailable_003B4FE4(reinterpret_cast<void*>(0x00D3AB50)) != 0) {
        void* descriptor = Engine_CommandObjectFactory_001898B8(
            reinterpret_cast<void*>(kDescriptorSlot),
            reinterpret_cast<void*>(0x00C9AD18), 0x48u);
        *static_cast<void**>(descriptor) = reinterpret_cast<void*>(0x00D070F0);
    }
    return *reinterpret_cast<void**>(kDescriptorSlot);
}
extern "C" __attribute__((noinline)) void* AnimeCommand_PlayHitSE_Factory_001279C0() {
    const std::uintptr_t kDescriptorSlot = 0x00D6B698;
    if (((*reinterpret_cast<const std::uint32_t*>(0x00D3AAB8 + 0x80) & 1u) ==
             0u) &&
        Engine_IsAvailable_003B4FE4(reinterpret_cast<void*>(0x00D3AB38)) != 0) {
        void* descriptor = Engine_CommandObjectFactory_001898B8(
            reinterpret_cast<void*>(kDescriptorSlot),
            reinterpret_cast<void*>(0x00C9AC78), 0x14u);
        *static_cast<void**>(descriptor) = reinterpret_cast<void*>(0x00D0C5CC);
    }
    return *reinterpret_cast<void**>(kDescriptorSlot);
}
extern "C" __attribute__((noinline)) void* AnimeCommand_PlayPitSE_Factory_00127A34() {
    const std::uintptr_t kDescriptorSlot = 0x00D6B590;
    if (((*reinterpret_cast<const std::uint32_t*>(0x00D3AAB8 + 0x68) & 1u) ==
             0u) &&
        Engine_IsAvailable_003B4FE4(reinterpret_cast<void*>(0x00D3AB20)) != 0) {
        void* descriptor = Engine_CommandObjectFactory_001898B8(
            reinterpret_cast<void*>(kDescriptorSlot),
            reinterpret_cast<void*>(0x00C9ABAC), 0x54u);
        *static_cast<void**>(descriptor) = reinterpret_cast<void*>(0x00D0C618);
    }
    return *reinterpret_cast<void**>(kDescriptorSlot);
}
extern "C" __attribute__((noinline)) void AnimeCommand_PlayBGM_Execute_00AE3DCC(void* command) {
    const std::uintptr_t kSoundStateSlot = 0x00D63578;
    void* sound_state = *reinterpret_cast<void**>(kSoundStateSlot);
    if (sound_state == 0) {
        sound_state = StatusLazySingleton_0054EFA8();
        *reinterpret_cast<void**>(kSoundStateSlot) = sound_state;
    }
    const std::uint8_t* bytes = static_cast<const std::uint8_t*>(command);
    AnimeSound_ApplyBgmCommand_005567F4(
        sound_state,
        *reinterpret_cast<const std::uint32_t*>(bytes + 0x10),
        *reinterpret_cast<const std::uint32_t*>(bytes + 0x14),
        static_cast<std::int8_t>(bytes[0x18]));
}
extern "C" __attribute__((noinline)) void AnimeCommand_StopBGM_Execute_00AE4A8C(void* command) {
    const std::uintptr_t kSoundStateSlot = 0x00D63578;
    void* sound_state = *reinterpret_cast<void**>(kSoundStateSlot);
    if (sound_state == 0) {
        sound_state = StatusLazySingleton_0054EFA8();
        *reinterpret_cast<void**>(kSoundStateSlot) = sound_state;
    }
    const std::uint8_t* bytes = static_cast<const std::uint8_t*>(command);
    AnimeSound_ApplyBgmCommand_005567F4(
        sound_state,
        *reinterpret_cast<const std::uint32_t*>(bytes + 0x14),
        *reinterpret_cast<const std::uint32_t*>(bytes + 0x10), 0);
}
extern "C" __attribute__((noinline)) void AnimeCommand_BGMVolume_Execute_00AE7900(void* command) {
    const std::uintptr_t kSoundStateSlot = 0x00D63578;
    void* sound_state = *reinterpret_cast<void**>(kSoundStateSlot);
    if (sound_state == 0) {
        sound_state = StatusLazySingleton_0054EFA8();
        *reinterpret_cast<void**>(kSoundStateSlot) = sound_state;
    }
    const std::uint8_t* bytes = static_cast<const std::uint8_t*>(command);
    AnimeSound_ApplyBgmVolume_00537D8C(
        sound_state,
        *reinterpret_cast<const std::uint32_t*>(bytes + 0x14),
        0, *reinterpret_cast<const float*>(bytes + 0x10));
}
struct SoundEventPayload {
    std::uint32_t word0;
    std::uint32_t word1;
    std::uint16_t halfword8;
    std::uint16_t untouched_halfword8;
    float scale0;
    std::uint32_t word4;
    float vector0;
    float vector1;
    float vector2;
    float vector3;
    float vector4;
    std::uint32_t transform0;
    std::uint32_t transform1;
};
typedef char kiu_sa_anime_sound_commands_1[(sizeof(SoundEventPayload) == 0x30) ? 1 : -1] __attribute__((unused));
struct FixedSoundPayload {
    std::uint32_t word0;
    std::uint32_t word1;
    std::uint16_t half2;
    float scale0;
    std::uint32_t word4;
    float scale1;
    float scale2;
    std::uint32_t word7;
    std::uint32_t word8;
};
struct BgmEventPayload {
    std::uint32_t word0;
    std::uint32_t word1;
    std::uint16_t halfword8;
    std::uint16_t reserved;
    void* channel_state;
    std::uint32_t duration_ms;
    float zero;
    float one;
};
struct VolumeEventPayload {
    std::uint32_t word0;
    std::uint32_t word1;
    std::uint16_t halfword8;
    std::uint16_t untouched_halfword8;
    float endpoint;
    std::uint32_t duration_ms;
    float one;
    float zero;
};
struct EnvironmentSoundPayload {
    std::uint32_t word0;
    std::uint32_t word1;
    std::uint16_t halfword8;
    std::uint16_t reserved;
    float scale0;
    std::uint32_t word4;
    std::uint32_t word5;
    float scale1;
    std::uint32_t commandValue0;
    std::uint32_t commandValue1;
    std::uint32_t commandValue2;
};
typedef char kiu_sa_anime_sound_commands_2[(sizeof(EnvironmentSoundPayload) == 0x28) ? 1 : -1] __attribute__((unused));
static void AnimeSound_ApplyBgmCommand_005567F4(void* sound_state,
                                                  std::uint32_t id,
                                                  std::uint32_t fade,
                                                  int through) {
    std::uint8_t* state = static_cast<std::uint8_t*>(sound_state);
    std::uint32_t* active_id = reinterpret_cast<std::uint32_t*>(state + 0x1ECBC);
    std::int32_t* active_handle = reinterpret_cast<std::int32_t*>(state + 0x1ECC0);
    if (through != 0 && *active_id == id)
        return;
    const std::int32_t duration_ms = static_cast<std::int32_t>(
        static_cast<float>(static_cast<std::int32_t>(fade)) *
        (1.0f / 60.0f) * 1000.0f);
    if (*active_handle >= 0) {
        const std::uintptr_t kDispatcherSlot = 0x00D63854;
        void* dispatcher = *reinterpret_cast<void**>(kDispatcherSlot);
        if (dispatcher == 0) {
            dispatcher = Engine_LazySingletonGetter_003FD6E0();
            *reinterpret_cast<void**>(kDispatcherSlot) = dispatcher;
        }
        AudioChannel_Stop_0048D320(dispatcher,
                                   static_cast<std::uint32_t>(*active_handle),
                                   duration_ms);
        *active_handle = -1;
    }
    if (static_cast<std::int32_t>(id) < 0 || state[0x1EDE1] != 0)
        return;
    const std::uintptr_t kDispatcherSlot = 0x00D63854;
    void* dispatcher = *reinterpret_cast<void**>(kDispatcherSlot);
    if (dispatcher == 0) {
        dispatcher = Engine_LazySingletonGetter_003FD6E0();
        *reinterpret_cast<void**>(kDispatcherSlot) = dispatcher;
    }
    std::uint8_t* gate = reinterpret_cast<std::uint8_t*>(0x00D5EE4A);
    std::uint8_t* sequence = reinterpret_cast<std::uint8_t*>(0x00D4E2F8);
    if (*gate == 0) {
        *sequence = static_cast<std::uint8_t>(*sequence + 1);
        *gate = *sequence;
    }
    BgmEventPayload payload = {0,
                            0,
                            0,
                            0,
                            *reinterpret_cast<void**>(state + 0x1ECC8),
                            static_cast<std::uint32_t>(duration_ms),
                            0.0f,
                            1.0f};
    const std::uint32_t event_id =
        (static_cast<std::uint32_t>(*gate) << 16) | 1u;
    *reinterpret_cast<float*>(state + 0x1ECC4) = 1.0f;
    *active_handle = static_cast<std::int32_t>(EffectEvent_Dispatch_0036C330(
        dispatcher, event_id, id, &payload,
        static_cast<std::uint32_t>(duration_ms)));
    *active_id = id;
}
__attribute__((noinline)) static void AnimeSound_ApplyBgmVolume_00537D8C(void* sound_state,
                                                std::uint32_t fade,
                                                int mode,
                                                float volume) {
    std::uint8_t* state = static_cast<std::uint8_t*>(sound_state);
    std::int32_t* active_handle = reinterpret_cast<std::int32_t*>(state + 0x1ECC0);
    if (*active_handle < 0)
        return;
    float* endpoint0 = reinterpret_cast<float*>(state + 0x1ECC4);
    float* endpoint1 = reinterpret_cast<float*>(state + 0x1ECC8);
    *(mode == 0 ? endpoint0 : endpoint1) = volume;
    const float endpoint = *endpoint1 < *endpoint0 ? *endpoint1 : *endpoint0;
    const std::int32_t duration_ms = static_cast<std::int32_t>(
        static_cast<float>(static_cast<std::int32_t>(fade)) *
        (1.0f / 60.0f) * 1000.0f);
    VolumeEventPayload payload = {0,
                               0,
                               0,
                               0,
                               endpoint,
                               static_cast<std::uint32_t>(duration_ms),
                               1.0f,
                               0.0f};
    const std::uintptr_t kDispatcherSlot = 0x00D63854;
    void* dispatcher = *reinterpret_cast<void**>(kDispatcherSlot);
    if (dispatcher == 0) {
        dispatcher = Engine_LazySingletonGetter_003FD6E0();
        *reinterpret_cast<void**>(kDispatcherSlot) = dispatcher;
    }
    EffectEvent_QueueVolumeRecord_00566CA4(
        static_cast<std::uint8_t*>(dispatcher) + 0x2148,
        static_cast<std::uint32_t>(*active_handle), &payload);
}
extern void EffectEvent_SoundSubtypeRouter_00BB9B80(
    void*, int, std::uint32_t, const FixedSoundPayload*, const void*, int, int,
    int);
extern std::uint32_t EffectEvent_EnvironmentSoundRouter_00BB97BC(
    void*, int, std::uint32_t, const void*, int, std::uint32_t,
    std::uint32_t, std::uint32_t);
extern std::uint32_t EffectEvent_EnvironmentSoundFallback_00BB93F8(
    void*, int, std::uint32_t, const void*, int, std::uint32_t,
    std::uint32_t, std::uint32_t);
extern void* EffectEvent_StatusResourceLookup_00498E6C(
    void*, const std::uint32_t*);
extern void EffectEvent_SoundCommandRouter_00BB9F44(
    void*, std::uint32_t, const SoundEventPayload*, const void*, int, int, int,
    int);
extern void EffectEvent_SpatialSoundCommandRouter_00BBA7E0(
    void*, std::uint32_t, const SoundEventPayload*, void*, int, int, int, int);
extern void* EffectEvent_WorkTreeLowerBound_00BB2DF4(void* tree);
extern void* StatusChannelLookup_0055C814(void*, void*);
extern void* ResolveStatusDescriptor(void*);
extern void* ResolveCachedComponent_1EC(void*);
extern void* PlayFootstepDescriptor_00A2CA98(void*);
extern std::uint32_t SoundHandleLookup_00B4F500(
    void*, int, int, const std::uint32_t*);
extern int StringEquals_00425E6C(const void*, const void*);
extern std::uint32_t ComponentType_GetGlobalDescriptor_00517CC4();
extern void* Engine_LazySingletonGetter_004C59C0();
extern std::uint32_t SoundLocatorLite_TableAt_00B10584(
    const void*, std::uint32_t, std::uint32_t);
extern std::uint32_t SoundLocatorLite_TableAt_00B105AC(
    const void*, std::uint32_t, std::uint32_t);
extern std::uint32_t SoundLocatorLite_TableAt_00B105D4(
    const void*, std::uint32_t);
extern std::uint32_t SharedResourceKey_00496BBC();
extern void* StatusHitLookup_0051B688(void*, std::uint16_t);
extern void* StatusHitDescriptor_00498F34(void*);
extern int StatusHitVariant_004990A8(void*, std::uint8_t, std::uint8_t);
extern int StatusMode_004D2B5C(void*);
extern int ObjectType_004EAF40(void*);
extern void* GlobalModeSingleton_00422CC8();
extern std::uint32_t EffectEvent_StringHash_00448668(
    const char* const* text);
extern void EffectEvent_WorkRecordFind_00BAB0A4(
    void* result, void* tree, const std::uint32_t* key,
    std::uint32_t key0, std::uint32_t key1);
extern void EffectEvent_WorkRecordRelease_004B26AC(void* record);
extern void EffectEvent_Submit_00566D70(void*, std::uint32_t, std::uint32_t,
                                         const SoundEventPayload*);
static void* LazySlot(void** slot, void* (*getter)()) {
    if (*slot == 0)
        *slot = getter();
    return *slot;
}
static std::uint16_t StatusCode(void* status, void* context) {
    const std::uint8_t* channel = static_cast<const std::uint8_t*>(
        StatusChannelLookup_0055C814(status,
                                        *reinterpret_cast<void**>(
                                            static_cast<std::uint8_t*>(context) + 4)));
    return *reinterpret_cast<const std::uint16_t*>(channel);
}
static __attribute__((always_inline)) inline SoundEventPayload MakeSoundPayload() {
    SoundEventPayload payload = {};
    payload.word0 = 0;
    payload.word1 = 0;
    payload.halfword8 = 0;
    payload.scale0 = 1.0f;
    payload.word4 = 0;
    payload.vector0 = 0.0f;
    payload.vector1 = 1.0f;
    return payload;
}
extern "C" __attribute__((noinline)) std::uint32_t SoundLocatorLite_ResolveHandles_00A22384(
    void* record, std::uint32_t* handles) {
    handles[0] = 0xffffffffu;
    handles[1] = 0xffffffffu;
    const std::uint8_t* bytes = static_cast<const std::uint8_t*>(record);
    if ((bytes[0x54] & 1u) == 0)
        return 0;
    std::uint8_t* locator = *reinterpret_cast<std::uint8_t**>(0x00D63600);
    if (locator == 0) {
        locator = static_cast<std::uint8_t*>(
            Engine_LazySingletonGetter_004C59C0());
        *reinterpret_cast<std::uint8_t**>(0x00D63600) = locator;
    }
    locator += 0x4664;
    handles[0] = SoundLocatorLite_TableAt_00B105AC(
        locator, bytes[0x39], bytes[0x3a]);
    if ((bytes[0x54] & 0x80u) == 0) {
        if (*reinterpret_cast<const std::int8_t*>(bytes + 0x3c) == 0)
            return 1;
        handles[1] = SoundLocatorLite_TableAt_00B10584(
            locator, static_cast<std::int8_t>(bytes[0x3c]), bytes[0x3a]);
        return 2;
    }
    handles[1] = SoundLocatorLite_TableAt_00B105D4(locator, bytes[0x3a]);
    return 2;
}
extern "C" __attribute__((noinline)) void ActionNode_PlayFootStepSE_00AC5088(void* command,
                                                    void* context) {
    const std::uint8_t* bytes = static_cast<const std::uint8_t*>(command);
    std::uint8_t* object = *reinterpret_cast<std::uint8_t**>(
        static_cast<std::uint8_t*>(context) + 4);
    const std::uint8_t* component = static_cast<const std::uint8_t*>(
        ResolveCachedComponent_1EC(object));
    if (component == 0 || (reinterpret_cast<const std::uint32_t*>(
                                     component + 0x94)[0] & 0x100u) != 0 ||
        (reinterpret_cast<const std::uint32_t*>(component + 0x98)[0] &
         0x1000u) == 0 ||
        StringEquals_00425E6C(reinterpret_cast<const void*>(0x00AC51D0),
                                 *reinterpret_cast<void* const*>(bytes +
                                                                  0x14)) == 0)
        return;
    std::uint8_t* descriptor = static_cast<std::uint8_t*>(
        PlayFootstepDescriptor_00A2CA98(object));
    if (descriptor == 0)
        return;
    const char* type_name = reinterpret_cast<const char*>(0x00C9AB1C);
    (void)EffectEvent_StringHash_00448668(&type_name);
    const std::uint32_t key[2] = {
        *reinterpret_cast<const std::uint32_t*>(bytes + 0x10),
        *reinterpret_cast<const std::uint32_t*>(bytes + 0x14)};
    const std::uint32_t handle = SoundHandleLookup_00B4F500(
        descriptor + 0x80, 3, 0, key);
    if (handle == 0xffffffffu)
        return;
    SoundEventPayload payload = MakeSoundPayload();
    payload.vector2 = *reinterpret_cast<const float*>(object + 0x54);
    payload.vector3 = *reinterpret_cast<const float*>(object + 0x58);
    payload.vector4 = *reinterpret_cast<const float*>(object + 0x5c);
    void* mode_state = LazySlot(reinterpret_cast<void**>(0x00D6364C),
                                 GlobalModeSingleton_00422CC8);
    const int mode = *reinterpret_cast<const std::int8_t*>(
        static_cast<const std::uint8_t*>(mode_state) + 0x1efc);
    EffectEvent_EnvironmentSoundRouter_00BB97BC(
        context, mode, handle, &payload, 0x00D3AB88, 0, 0, 0);
}
static std::uint32_t SelectPlaySound(void* status,
                                     const std::uint8_t* command) {
    const int mode = StatusMode_004D2B5C(status);
    if (mode == 0x12 || mode == 0x13 || mode == 0x14)
        return *reinterpret_cast<const std::uint32_t*>(command + 0x14);
    return *reinterpret_cast<const std::uint32_t*>(command + 0x10);
}
static void AnimeCommand_SubmitFixedSound(void* context, void* command,
                                          void* parameter, int subtype,
                                          const void* type_tag) {
    (void)command;
    const std::uint8_t* const source =
        static_cast<const std::uint8_t*>(parameter);
    FixedSoundPayload payload;
    payload.word0 = 0;
    payload.word1 = 0;
    payload.half2 = 0;
    payload.scale0 = 1.0f;
    payload.word4 = 0;
    payload.scale1 = 0.0f;
    payload.scale2 = 1.0f;
    EffectEvent_SoundSubtypeRouter_00BB9B80(
        context, subtype,
        *reinterpret_cast<const std::uint32_t*>(source + 0x10), &payload,
        type_tag, 0, 0, 0);
}
__attribute__((noinline)) static void AnimeSound_ApplyEnvironmentLine_00A4CF4C(
    void* state, const std::uint32_t* handle, const float* start,
    const float* end) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(state);
    for (std::uint32_t index = 0; index < 8; ++index) {
        std::uint8_t* slot = bytes + index * 0x44;
        if (*reinterpret_cast<std::int32_t*>(slot + 0xb8) != -1)
            continue;
        if (*handle == 0xffffffffu)
            return;
        *reinterpret_cast<std::uint32_t*>(slot + 0xb8) = *handle;
        for (std::uint32_t axis = 0; axis < 3; ++axis) {
            *reinterpret_cast<float*>(slot + 0xbc + axis * 4) = start[axis];
            *reinterpret_cast<float*>(slot + 0xc8 + axis * 4) = end[axis];
        }
        const float dx = end[0] - start[0];
        const float dy = end[1] - start[1];
        const float dz = end[2] - start[2];
        *reinterpret_cast<float*>(slot + 0xd4) = dx;
        *reinterpret_cast<float*>(slot + 0xd8) = dy;
        *reinterpret_cast<float*>(slot + 0xdc) = dz;
        *reinterpret_cast<float*>(slot + 0xe0) = -dx;
        *reinterpret_cast<float*>(slot + 0xe4) = -dy;
        *reinterpret_cast<float*>(slot + 0xe8) = -dz;
        const float length = std::sqrt(dx * dx + dy * dy + dz * dz);
        const float scale = 1.0f / length;
        *reinterpret_cast<float*>(slot + 0xec) = dx * scale;
        *reinterpret_cast<float*>(slot + 0xf0) = dy * scale;
        *reinterpret_cast<float*>(slot + 0xf4) = dz * scale;
        *reinterpret_cast<float*>(slot + 0xf8) = length;
        return;
    }
}
static void AnimeCommand_SubmitSound(void* context, const std::uint8_t* command,
                                      std::uint32_t sound) {
    SoundEventPayload payload = MakeSoundPayload();
    payload.word1 = command[0x4c];
    const std::uint8_t* target = *reinterpret_cast<const std::uint8_t* const*>(
        static_cast<const std::uint8_t*>(context) + 4);
    if (command[0x19] == 0) {
        EffectEvent_SoundCommandRouter_00BB9F44(
            context, sound, &payload, reinterpret_cast<const void*>(0x00D3AB88),
            static_cast<std::int8_t>(command[0x18]), 0,
            static_cast<std::int8_t>(command[0x48]), 0);
        return;
    }
    payload.vector2 = *reinterpret_cast<const float*>(target + 0x54);
    payload.vector3 = *reinterpret_cast<const float*>(target + 0x58);
    payload.vector4 = *reinterpret_cast<const float*>(target + 0x5c);
    payload.transform0 =
        *reinterpret_cast<const std::uint32_t*>(command + 0x1c);
    payload.transform1 =
        *reinterpret_cast<const std::uint32_t*>(command + 0x20);
    EffectEvent_SpatialSoundCommandRouter_00BBA7E0(
        context, sound, &payload, &payload.transform0,
        static_cast<std::int8_t>(command[0x18]),
        static_cast<std::int8_t>(command[0x1a]),
        static_cast<std::int8_t>(command[0x48]), 0);
}
extern "C" __attribute__((noinline)) void AnimeCommand_PlaySE_Execute_00AE2708(void* command,
                                                       void* context) {
    const std::uint8_t* bytes = static_cast<const std::uint8_t*>(command);
    void* target = *reinterpret_cast<void**>(
        static_cast<std::uint8_t*>(context) + 4);
    SoundEventPayload payload = MakeSoundPayload();
    void* descriptor = ResolveStatusDescriptor(target);
    if (descriptor != 0)
        payload.word0 = *reinterpret_cast<const std::uint32_t*>(
            static_cast<const std::uint8_t*>(descriptor) + 0x20);
    payload.word1 = bytes[0x48];
    if (bytes[0x15] == 0) {
        EffectEvent_SoundCommandRouter_00BB9F44(
            context, *reinterpret_cast<const std::uint32_t*>(bytes + 0x10),
            &payload, reinterpret_cast<const void*>(0x00D3AB88),
            static_cast<std::int8_t>(bytes[0x14]), 0,
            static_cast<std::int8_t>(bytes[0x44]),
            static_cast<std::int8_t>(bytes[0x4c]));
        return;
    }
    payload.vector2 = *reinterpret_cast<const float*>(
        static_cast<const std::uint8_t*>(target) + 0x54);
    payload.vector3 = *reinterpret_cast<const float*>(
        static_cast<const std::uint8_t*>(target) + 0x58);
    payload.vector4 = *reinterpret_cast<const float*>(
        static_cast<const std::uint8_t*>(target) + 0x5c);
    payload.transform0 = *reinterpret_cast<const std::uint32_t*>(bytes + 0x18);
    payload.transform1 = *reinterpret_cast<const std::uint32_t*>(bytes + 0x1c);
    EffectEvent_SpatialSoundCommandRouter_00BBA7E0(
        context, *reinterpret_cast<const std::uint32_t*>(bytes + 0x10),
        &payload, target, static_cast<std::int8_t>(bytes[0x14]),
        static_cast<std::int8_t>(bytes[0x16]),
        static_cast<std::int8_t>(bytes[0x44]),
        static_cast<std::int8_t>(bytes[0x4c]));
}
__attribute__((noinline)) void AnimeCommand_PlayMiracleSE_Execute_00AC02EC(void* command,
                                                  void* context) {
    const std::uint8_t* bytes = static_cast<const std::uint8_t*>(command);
    void* status = LazySlot(reinterpret_cast<void**>(0x00D63578),
                             StatusLazySingleton_0054EFA8);
    if (StatusCode(status, context) == 2)
        return;
    AnimeCommand_SubmitSound(context, bytes, SelectPlaySound(status, bytes));
}
__attribute__((noinline)) void AnimeCommand_PlayPitSE_Execute_00AE9E54(void* command, void* context) {
    const std::uint8_t* bytes = static_cast<const std::uint8_t*>(command);
    void* status = LazySlot(reinterpret_cast<void**>(0x00D63578),
                             StatusLazySingleton_0054EFA8);
    void* const context_object = *reinterpret_cast<void**>(
        static_cast<std::uint8_t*>(context) + 4);
    const bool common_path = StatusCode(status, context) == 2 ||
                             (ObjectType_004EAF40(context_object) & 0xff) == 0xb;
    std::uint32_t sound;
    if (!common_path) {
        void* global = LazySlot(reinterpret_cast<void**>(0x00D6364C),
                                 GlobalModeSingleton_00422CC8);
        const std::int8_t* mode = static_cast<const std::int8_t*>(global) + 0x1efc;
        if (*mode == 0x11 && static_cast<const std::uint8_t*>(global)[0x1efd] == 1)
            return;
        sound = *reinterpret_cast<const std::uint32_t*>(bytes + 0x10);
    } else {
        if (bytes[0x50] != 0) {
            void* global = LazySlot(reinterpret_cast<void**>(0x00D6364C),
                                     GlobalModeSingleton_00422CC8);
            const std::int8_t mode = *reinterpret_cast<const std::int8_t*>(
                static_cast<const std::uint8_t*>(global) + 0x1efc);
            if (mode == 5 || mode == 0xc)
                return;
        }
        sound = *reinterpret_cast<const std::uint32_t*>(bytes + 0x14);
    }
    AnimeCommand_SubmitSound(context, bytes, sound);
}
extern "C" __attribute__((noinline)) void AnimeCommand_StopSE_Execute_00C87BEC(void* command,
                                                       void* context) {
    const std::uint8_t* bytes = static_cast<const std::uint8_t*>(command);
    std::uint8_t* tree = *reinterpret_cast<std::uint8_t**>(
        static_cast<std::uint8_t*>(context) + 0x14);
    std::uint8_t* work = static_cast<std::uint8_t*>(
        EffectEvent_WorkTreeLowerBound_00BB2DF4(tree + 0x0c));
    if (work == 0)
        return;
    if (*reinterpret_cast<const std::uint8_t*>(
            *reinterpret_cast<void* const*>(bytes + 0x14)) == 0) {
        std::uint8_t* cursor = *reinterpret_cast<std::uint8_t**>(work + 0x28);
        std::uint8_t* sentinel = reinterpret_cast<std::uint8_t*>(work + 0x24);
        while (*reinterpret_cast<void**>(cursor) !=
               *reinterpret_cast<void**>(sentinel)) {
            EffectEvent_WorkRecordRelease_004B26AC(
                *reinterpret_cast<void**>(cursor));
            cursor = *reinterpret_cast<std::uint8_t**>(cursor + 4);
        }
        return;
    }
    const char* type_name = reinterpret_cast<const char*>(0x00C9AB1C);
    (void)EffectEvent_StringHash_00448668(&type_name);
    const std::uint32_t key0 =
        *reinterpret_cast<const std::uint32_t*>(bytes + 0x10);
    const std::uint32_t key1 =
        *reinterpret_cast<const std::uint32_t*>(bytes + 0x14);
    const std::uint32_t key[2] = {key0, key1};
    void* result[2] = {0, 0};
    EffectEvent_WorkRecordFind_00BAB0A4(result, work + 0x30, key, key0,
                                        key1);
    void* found = result[0];
    const std::uint32_t found_key =
        found == 0 ? 0 : *static_cast<std::uint32_t*>(found);
    const std::uint32_t current_key =
        *reinterpret_cast<const std::uint32_t*>(work + 0x34);
    if (found_key != current_key)
        EffectEvent_WorkRecordRelease_004B26AC(
            found == 0 ? 0 : *static_cast<void**>(found));
}
extern "C" __attribute__((noinline)) void AnimeCommand_SetSoundFXReturnLevel_00ADAB60(void* command,
                                                              float value) {
    const std::uintptr_t kStateSlot = 0x00D6368C;
    std::uint8_t* state = *reinterpret_cast<std::uint8_t**>(kStateSlot);
    if (state == 0) {
        state = static_cast<std::uint8_t*>(
            Engine_LazySingletonGetter_004EEFBC());
        *reinterpret_cast<std::uint8_t**>(kStateSlot) = state;
    }
    std::uint8_t* entries = state == 0
                        ? 0
                        : *reinterpret_cast<std::uint8_t**>(state + 0x80);
    if (entries != 0)
        entries = *reinterpret_cast<std::uint8_t**>(entries + 4);
    std::uint8_t* record = entries +
                   (*reinterpret_cast<const std::uint32_t*>(
                        static_cast<const std::uint8_t*>(command) + 0x10) *
                    0x20) +
                   0x190;
    *reinterpret_cast<std::uint8_t*>(record + 0x14) = 1;
    *reinterpret_cast<std::uint32_t*>(record + 0x00) =
        *reinterpret_cast<const std::uint32_t*>(record + 0x04);
    *reinterpret_cast<float*>(record + 0x08) =
        *reinterpret_cast<const float*>(
            static_cast<const std::uint8_t*>(command) + 0x14);
    *reinterpret_cast<std::uint8_t*>(record + 0x1c) = 1;
    *reinterpret_cast<std::uint8_t*>(record + 0x1d) = 1;
    *reinterpret_cast<float*>(record + 0x18) = -1.0f;
    *reinterpret_cast<float*>(record + 0x0c) = 0.0f;
    *reinterpret_cast<float*>(record + 0x10) = value;
}
extern "C" __attribute__((noinline)) void AnimeCommand_PlayEnvironmentSEPos_00AD8D40(void* command,
                                                             void* context) {
    const std::uint8_t* bytes = static_cast<const std::uint8_t*>(command);
    void* mode_state = LazySlot(reinterpret_cast<void**>(0x00D6364C),
                                 GlobalModeSingleton_00422CC8);
    const int mode = *reinterpret_cast<const std::int8_t*>(
        static_cast<const std::uint8_t*>(mode_state) + 0x1efc);
    EnvironmentSoundPayload payload = {0,
                                    0,
                                    0,
                                    0,
                                    1.0f,
                                    0,
                                    0,
                                    1.0f,
                                    *reinterpret_cast<const std::uint32_t*>(
                                        bytes + 0x14),
                                    *reinterpret_cast<const std::uint32_t*>(
                                        bytes + 0x18),
                                    *reinterpret_cast<const std::uint32_t*>(
                                        bytes + 0x1c)};
    EffectEvent_EnvironmentSoundRouter_00BB97BC(
        context, mode,
        *reinterpret_cast<const std::uint32_t*>(bytes + 0x10), &payload,
        static_cast<std::int8_t>(bytes[0x20]), 0x00D3AB88, 0, 0);
}
extern "C" __attribute__((noinline)) void AnimeCommand_PlayEnvironmentSE_00AD0D74(void* command,
                                                          void* context) {
    const std::uint8_t* bytes = static_cast<const std::uint8_t*>(command);
    SoundEventPayload payload = MakeSoundPayload();
    void* mode_state = LazySlot(reinterpret_cast<void**>(0x00D6364C),
                                 GlobalModeSingleton_00422CC8);
    const int mode = *reinterpret_cast<const std::int8_t*>(
        static_cast<const std::uint8_t*>(mode_state) + 0x1efc);
    const std::uint32_t sound =
        *reinterpret_cast<const std::uint32_t*>(bytes + 0x10);
    const int variant = static_cast<std::int8_t>(bytes[0x44]);
    const std::uint32_t variant_value =
        *reinterpret_cast<const std::uint32_t*>(bytes + 0x48);
    if (bytes[0x14] != 0) {
        const char* type_name = reinterpret_cast<const char*>(0x00C9AB1C);
        (void)EffectEvent_StringHash_00448668(&type_name);
        const std::uint32_t key[2] = {
            *reinterpret_cast<const std::uint32_t*>(bytes + 0x18),
            *reinterpret_cast<const std::uint32_t*>(bytes + 0x1c)};
        void* status = LazySlot(reinterpret_cast<void**>(0x00D63578),
                                 StatusLazySingleton_0054EFA8);
        const std::uint8_t* record = static_cast<const std::uint8_t*>(
            EffectEvent_StatusResourceLookup_00498E6C(
                static_cast<std::uint8_t*>(status) + 0x1e800 + 0x1ac,
                key));
        if (record == 0)
            return;
        payload.vector2 = *reinterpret_cast<const float*>(record + 8);
        payload.vector3 = *reinterpret_cast<const float*>(record + 0xc);
        payload.vector4 = *reinterpret_cast<const float*>(record + 0x10);
        EffectEvent_EnvironmentSoundRouter_00BB97BC(
            context, mode, sound, &payload, 0x00D3AB88, 0, variant,
            variant_value);
        return;
    }
    EffectEvent_EnvironmentSoundFallback_00BB93F8(
        context, mode, sound, &payload, 0x00D3AB88, 0, variant,
        variant_value);
}
extern "C" __attribute__((noinline)) void AnimeCommand_PlayHitSE_00AE999C(void* command,
                                                 void* context) {
    const std::uint8_t* bytes = static_cast<const std::uint8_t*>(command);
    std::uint8_t* object = *reinterpret_cast<std::uint8_t**>(
        static_cast<std::uint8_t*>(context) + 4);
    const std::uint32_t key = SharedResourceKey_00496BBC();
    std::uint8_t* node = *reinterpret_cast<std::uint8_t**>(object + 0x1ac);
    std::uint8_t* parent = object + 0x1a8;
    while (*reinterpret_cast<const std::uint8_t*>(node + 0x10) != 0) {
        if (*reinterpret_cast<const std::uint32_t*>(node + 0x14) < key) {
            parent = node;
            node = *reinterpret_cast<std::uint8_t**>(node + 0x0c);
        } else {
            node = *reinterpret_cast<std::uint8_t**>(node + 0x08);
        }
    }
    if (parent == object + 0x1a8 ||
        key < *reinterpret_cast<const std::uint32_t*>(parent + 0x14))
        parent = object + 0x1a8;
    std::uint8_t* record = *reinterpret_cast<std::uint8_t**>(parent);
    if (record == *reinterpret_cast<std::uint8_t**>(object + 0x1a8))
        return;
    record = *reinterpret_cast<std::uint8_t**>(parent);
    if (record == 0)
        return;
    SoundEventPayload payload = MakeSoundPayload();
    payload.vector2 = *reinterpret_cast<const float*>(record + 0x54);
    payload.vector3 = *reinterpret_cast<const float*>(record + 0x58);
    payload.vector4 = *reinterpret_cast<const float*>(record + 0x5c);
    void* status = LazySlot(reinterpret_cast<void**>(0x00D63578),
                             StatusLazySingleton_0054EFA8);
    void* hit = StatusHitLookup_0051B688(
        static_cast<std::uint8_t*>(status) + 0x1e9ac,
        *reinterpret_cast<const std::uint16_t*>(record + 0x6c));
    if (hit == 0)
        return;
    void* descriptor = StatusHitDescriptor_00498F34(hit);
    if (descriptor == 0)
        return;
    const int event_type = StatusHitVariant_004990A8(
        static_cast<std::uint8_t*>(descriptor) + 0x80, bytes[0x10],
        bytes[0x11]);
    if (event_type < 0)
        return;
    void* dispatcher = LazySlot(reinterpret_cast<void**>(0x00D63854),
                                 Engine_LazySingletonGetter_003FD6E0);
    void* mode_state = LazySlot(reinterpret_cast<void**>(0x00D6364C),
                                 GlobalModeSingleton_00422CC8);
    const std::int32_t mode = static_cast<std::int32_t>(*reinterpret_cast<
        const std::int8_t*>(static_cast<const std::uint8_t*>(mode_state) +
                            0x1efc));
    std::uint8_t* sequence_gate = reinterpret_cast<std::uint8_t*>(0x00D5EE49);
    std::uint8_t* sequence = reinterpret_cast<std::uint8_t*>(0x00D4E2F8);
    if (*sequence_gate == 0) {
        *sequence = static_cast<std::uint8_t>(*sequence + 1);
        *sequence_gate = *sequence;
    }
    const std::uint32_t event_id =
        (static_cast<std::uint32_t>(*sequence_gate) << 16) +
        static_cast<std::uint32_t>(mode);
    EffectEvent_Submit_00566D70(
        dispatcher, event_id, static_cast<std::uint32_t>(event_type), &payload);
}
extern "C" __attribute__((noinline)) void AnimeCommand_PlayDamageSE_Execute_00AB9378(
    void* command, void* context) {
    const std::uint8_t* bytes = static_cast<const std::uint8_t*>(command);
    std::uint8_t* target = *reinterpret_cast<std::uint8_t**>(
        static_cast<std::uint8_t*>(context) + 4);
    std::uint8_t* resource = *reinterpret_cast<std::uint8_t**>(target + 0x208);
    if (resource == 0) {
        const std::uint32_t key = ComponentType_GetGlobalDescriptor_00517CC4();
        std::uint8_t* node = *reinterpret_cast<std::uint8_t**>(target + 0x1ac);
        std::uint8_t* parent = target + 0x1a8;
        while (*reinterpret_cast<const std::uint8_t*>(node + 0x10) != 0) {
            if (*reinterpret_cast<const std::uint32_t*>(node + 0x14) < key) {
                parent = node;
                node = *reinterpret_cast<std::uint8_t**>(node + 0x0c);
            } else {
                node = *reinterpret_cast<std::uint8_t**>(node + 0x08);
            }
        }
        if (parent == target + 0x1a8 ||
            key < *reinterpret_cast<const std::uint32_t*>(parent + 0x14))
            parent = target + 0x1a8;
        std::uint8_t* candidate = *reinterpret_cast<std::uint8_t**>(parent);
        if (candidate != *reinterpret_cast<std::uint8_t**>(target + 0x1a8)) {
            resource = candidate;
            if (resource != 0) {
                *reinterpret_cast<std::uint8_t**>(resource + 0x34) = target;
                *reinterpret_cast<std::uint8_t**>(target + 0x208) = resource;
            }
        }
    }
    if (resource == 0 || (resource[0x54] & 0x20u) != 0 ||
        (resource[0x55] & 1u) != 0)
        return;
    std::uint32_t handles[2];
    const std::uint32_t count =
        SoundLocatorLite_ResolveHandles_00A22384(resource, handles);
    for (std::uint32_t index = 0; index < count; ++index) {
        if (handles[index] == 0xffffffffu)
            continue;
        SoundEventPayload payload = MakeSoundPayload();
        payload.word1 = bytes[0x44];
        if (bytes[0x10] == 0) {
            EffectEvent_SoundCommandRouter_00BB9F44(
                context, handles[index], &payload,
                reinterpret_cast<const void*>(0x00D3AB88), 1, 0,
                static_cast<std::int8_t>(bytes[0x40]), 0);
            continue;
        }
        payload.vector2 = *reinterpret_cast<const float*>(resource + 0x44);
        payload.vector3 = *reinterpret_cast<const float*>(resource + 0x48);
        payload.vector4 = *reinterpret_cast<const float*>(resource + 0x4c);
        std::uint32_t transform[2] = {
            *reinterpret_cast<const std::uint32_t*>(bytes + 0x14),
            *reinterpret_cast<const std::uint32_t*>(bytes + 0x18)};
        EffectEvent_SpatialSoundCommandRouter_00BBA7E0(
            context, handles[index], &payload,
            transform, 1,
            static_cast<std::int8_t>(bytes[0x11]),
            static_cast<std::int8_t>(bytes[0x40]), 0);
    }
}
extern "C" __attribute__((noinline)) void AnimeCommand_PlayEnvironmentSELine_00ADA420(void* command,
                                                              void* context) {
    const std::uint8_t* bytes = static_cast<const std::uint8_t*>(command);
    EnvironmentSoundPayload payload = {0,
                                    0,
                                    0,
                                    0,
                                    1.0f,
                                    0,
                                    0,
                                    1.0f,
                                    *reinterpret_cast<const std::uint32_t*>(
                                        bytes + 0x14),
                                    *reinterpret_cast<const std::uint32_t*>(
                                        bytes + 0x18),
                                    *reinterpret_cast<const std::uint32_t*>(
                                        bytes + 0x1c)};
    void* mode_state = LazySlot(reinterpret_cast<void**>(0x00D6364C),
                                 GlobalModeSingleton_00422CC8);
    const int mode = *reinterpret_cast<const std::int8_t*>(
        static_cast<const std::uint8_t*>(mode_state) + 0x1efc);
    const std::uint32_t handle = EffectEvent_EnvironmentSoundRouter_00BB97BC(
        context, mode,
        *reinterpret_cast<const std::uint32_t*>(bytes + 0x10), &payload,
        static_cast<std::int8_t>(bytes[0x2c]), 0x00D3AB88, 0, 0);
    const float* start = reinterpret_cast<const float*>(bytes + 0x14);
    const float* end = reinterpret_cast<const float*>(bytes + 0x20);
    void* line_state = *reinterpret_cast<void**>(0x00D6368C);
    if (line_state == 0) {
        line_state = Engine_LazySingletonGetter_004EEFBC();
        *reinterpret_cast<void**>(0x00D6368C) = line_state;
    }
    AnimeSound_ApplyEnvironmentLine_00A4CF4C(
        line_state, &handle, start, end);
}
extern "C" __attribute__((noinline)) void AnimeCommand_PlaySECommon_Thunk_00AB98F8(
    void* command, void* context) {
    AnimeCommand_SubmitFixedSound(context, command, command, 2,
                                   reinterpret_cast<const void*>(0x00D3AB88));
}
extern "C" __attribute__((noinline)) void AnimeCommand_PlayVoice_Thunk_00AEA2A0(
    void* command, void* context) {
    AnimeCommand_SubmitFixedSound(context, command, command, 0,
                                   reinterpret_cast<const void*>(0x00D3AB88));
}

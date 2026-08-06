#include <cstdint>
typedef std::uint32_t Word;
extern "C" void* ResourceTree_ResolveCurrentEntry_002A6268(void* resource);
extern "C" void FUN_0025F180(void* output, void* state, float frame_step);
extern "C" void FUN_0025EED0(void* state, float frame_step);
extern "C" void SaveUi_UpdateResourceFlags_00194CE8(void* object);
extern "C" void SaveUi_ActionTextState_00195B80(void* object);
extern "C" void SaveUi_CreateCommonText_0019403C(void* object);
extern "C" void SaveUi_LoadFontResources_001948B8(void* object);
extern "C" void* FUN_00225340(void* actor);
extern "C" void StateParameterRecord_Init_003B530C(Word* record);
extern "C" void Actor_PlayActionByHash(
    void* actor, Word channel, Word* record, Word mode, Word flags);
extern "C" void* Engine_LazyOrderedTreeSentinel_002F3368();
extern "C" void Engine_FindOrCreatePolymorphicResource_0036C090(
    void* record, Word flags, void* key);
extern "C" void ParameterString_Normalize_00352994(
    void* destination, const void* source);
extern "C" void ResourceState_CopyOrResolve_002BFD54(
    void* destination, const void* source);
extern "C" void FUN_00193EAC(void* object);
extern "C" void ResourceTree_SetTransitionMode_0025F13C(
    void* resource, Word mode);
extern "C" void ResourceTree_Activate_002A17A0(
    void* state, void* resource, Word mode);
extern "C" void* RuntimeStateSingleton_Get_002F32E8();
extern "C" void SaveUi_BindMiiDynamicResource_001EBE20(
    void* output_records, void* resource, Word selection);
extern "C" Word MenuResourceList_HasNoConflictingState_00260620(
    void* list, void* excluded_resource);
extern "C" void* StMenuBase_Factory_0022CC34();
extern "C" void ActorStateMachine_RequestStateByFactory(
    void* object, void** factory);
extern "C" void* ResourceTree_FindCurrentEntry_001ED44C(void* tree);
extern "C" void SaveUi_UpdateTextNodeState_001C16C0(void* object);
extern "C" Word once_guard_primitive(void* guard);
extern "C" void* FontTextManager_Get_003532F0();
extern "C" int FontTextManager_IsReady_002A1E94(void* manager, int command);
extern "C" void FontTextManager_PlayCommand_002EECB8(
    void* manager, Word enabled, Word duration, Word command, Word flags);
extern "C" int ResourcePathState_Discriminate_001EC0B4(
    void* record, int offset);
extern "C" int SaveUi_ResourceGate_0018C820();
extern "C" int ResourceState_GetKind_003207E8(void* state);
extern "C" void* MenuRuntime_GetShared_00225B50();
extern "C" void* GetEngineSingleton_003B6CF0();
extern "C" int MenuProfile_AvailabilityPredicate_002B6238(
    void* profile, int mode);
extern "C" unsigned ResourceEvent_PrepareAndDispatch_00302AC8(
    unsigned char* event_record, void* owner, void* key,
    unsigned action, int event_type);
extern "C" void MenuState_PublishSelectionMode_0028AB9C(
    void* state, int force);
extern "C" void SaveUi_PromoteActiveRecord_001C14A8(void* object);
extern void* g_FontTextManagerCache_00D6366C;
extern void* g_MenuProfileSingleton_00D6365C;
extern void* g_MenuRuntimeShared_00D635E0;
extern void* g_SaveUiResourceSentinel_00D63844;
extern void* g_RuntimeStateSingleton_00D635F0;
extern Word g_SaveUiSentinelGuard0_00D5FF64;
extern void* g_SaveUiSentinel0_00D5FF68;
extern Word g_SaveUiSentinelGuard1_00D627C4;
extern void* g_SaveUiSentinel1_00D627C8;
extern Word g_SaveUiSentinelGuard2_00D619C8;
extern void* g_SaveUiSentinel2_00D619CC;
namespace {
template <typename T>
T& At(void* object, Word offset) {
    return *reinterpret_cast<T*>(
        static_cast<std::uint8_t*>(object) + offset);
}
struct SaveUiTransientRecord {
    std::uint16_t flags;
    std::uint16_t padding;
    float bounds[4];
    Word state[3];
    std::uint16_t tail;
    std::uint16_t tail_padding;
};
typedef char kiu_sa_save_ui_state_machine_1[(sizeof(SaveUiTransientRecord) == 0x24) ? 1 : -1] __attribute__((unused));
}  // namespace
extern "C" __attribute__((noinline)) std::uint32_t SaveUi_AccumulateInputSnapshot_00196064(
    void* object, void* input) {
    const unsigned char state = At<std::uint8_t>(object, 0xf5);
    if (state != 0 && state != 3) {
        return 0;
    }
    const unsigned char flags = At<const std::uint8_t>(input, 0x2c);
    std::uint16_t accumulated = At<std::uint16_t>(object, 0x514);
    if ((flags & 0x01) != 0) accumulated |= 0x01;
    if ((flags & 0x02) != 0) accumulated |= 0x02;
    if ((flags & 0x20) != 0) accumulated |= 0x04;
    if ((flags & 0x04) != 0) accumulated |= 0x08;
    if ((flags & 0x08) != 0) accumulated |= 0x10;
    if ((flags & 0x10) != 0) accumulated |= 0x20;
    if ((flags & 0x21) != 0) accumulated |= 0x40;
    if ((flags & 0x40) != 0) accumulated |= 0x80;
    At<Word>(object, 0x518) = At<const Word>(input, 0x34);
    At<Word>(object, 0x51c) = At<const Word>(input, 0x38);
    At<Word>(object, 0x520) = At<const Word>(input, 0x3c);
    At<Word>(object, 0x524) = At<const Word>(input, 0x40);
    At<Word>(object, 0x528) = At<const Word>(input, 0x4c);
    At<Word>(object, 0x52c) = At<const Word>(input, 0x50);
    At<Word>(object, 0x530) = At<const Word>(input, 0x54);
    At<Word>(object, 0x534) = At<const Word>(input, 0x58);
    return 0;
}
extern "C" __attribute__((noinline)) std::uint32_t SaveUi_CapturePendingInput_00172EEC(
    void* object, void*, void* input) {
    if ((At<std::uint8_t>(object, 0xf1) & 0x80) != 0 &&
        At<Word>(input, 0x2c) != 0) {
        At<Word>(object, 0x610) = At<Word>(input, 0x2c);
        At<Word>(object, 0x614) = At<Word>(input, 0x30);
        At<Word>(object, 0x618) = At<Word>(input, 0x34);
        At<Word>(object, 0x61c) = At<Word>(input, 0x38);
        At<Word>(object, 0x620) = At<Word>(input, 0x38);
        FUN_00193EAC(object);
    }
    return 0;
}
extern "C" __attribute__((noinline)) std::uint32_t SaveUi_ApplyInputWhenReady_00172F38(
    void* object, void*, void* input) {
    if ((At<std::uint8_t>(object, 0xf1) & 0x80) != 0 &&
        (At<std::uint8_t>(input, 0x2c) & 1) != 0 &&
        At<std::uint8_t>(object, 0xf9) == 5) {
        SaveUi_AccumulateInputSnapshot_00196064(object, input);
        FUN_00193EAC(object);
    }
    return 0;
}
extern "C" __attribute__((noinline)) std::uint32_t SaveUi_AccumulateInputIfState5_00172A1C(
    void* object, void*, void* input) {
    if (At<std::uint8_t>(object, 0xf9) == 5) {
        SaveUi_AccumulateInputSnapshot_00196064(object, input);
    }
    return 0;
}
extern "C" __attribute__((noinline)) std::uint32_t SaveUi_SetResourceTransitionMode_00172A3C(
    void* object) {
    std::uint8_t* entry = static_cast<std::uint8_t*>(
        ResourceTree_ResolveCurrentEntry_002A6268(
            At<void*>(object, 0x30)));
    ResourceTree_SetTransitionMode_0025F13C(
        static_cast<std::uint8_t*>(At<void*>(entry, 0x20)) + 8, 2);
    return 0;
}
extern "C" __attribute__((noinline)) std::uint32_t SaveUi_ActivateCurrentResource_00172F84(
    void* object, void*, void*, void* frame_context) {
    std::uint8_t* entry = static_cast<std::uint8_t*>(
        ResourceTree_ResolveCurrentEntry_002A6268(
            At<void*>(object, 0x30)));
    std::uint8_t* state = static_cast<std::uint8_t*>(At<void*>(entry, 0x20)) + 8;
    const float frame_step = At<float>(frame_context, 0x0c);
    Word update_output[2];
    FUN_0025F180(update_output, state, frame_step);
    FUN_0025EED0(state, frame_step);
    std::uint8_t* secondary = static_cast<std::uint8_t*>(
        ResourceTree_ResolveCurrentEntry_002A6268(
            At<void*>(object, 0xec)));
    ResourceTree_Activate_002A17A0(
        static_cast<std::uint8_t*>(At<void*>(secondary, 0x20)) + 8,
        At<void*>(object, 0xec), 1);
    if ((At<std::uint8_t>(object, 0xf1) & 0x80) == 0) {
        if (g_RuntimeStateSingleton_00D635F0 == 0) {
            g_RuntimeStateSingleton_00D635F0 =
                RuntimeStateSingleton_Get_002F32E8();
        }
        if (At<Word>(g_RuntimeStateSingleton_00D635F0, 0xf0) != 0)
            return 0;
        SaveUi_BindMiiDynamicResource_001EBE20(
            static_cast<std::uint8_t*>(object) + 0x254,
            At<void*>(object, 0xd8), 0);
        At<std::uint8_t>(object, 0xf1) |= 0x80;
    }
    if ((At<std::uint8_t>(object, 0xf1) & 2) == 0) {
        if (MenuResourceList_HasNoConflictingState_00260620(
                static_cast<std::uint8_t*>(object) + 0x34,
                At<void*>(object, 0x30)) != 0) {
            void* factory = StMenuBase_Factory_0022CC34();
            ActorStateMachine_RequestStateByFactory(
                At<void*>(object, 0x30), &factory);
        }
        return 0;
    }
    if ((g_SaveUiSentinelGuard0_00D5FF64 & 1) == 0 &&
        once_guard_primitive(&g_SaveUiSentinelGuard0_00D5FF64) != 0) {
        if ((g_SaveUiSentinelGuard1_00D627C4 & 1) == 0 &&
            once_guard_primitive(&g_SaveUiSentinelGuard1_00D627C4) != 0) {
            if ((g_SaveUiSentinelGuard2_00D619C8 & 1) == 0 &&
                once_guard_primitive(&g_SaveUiSentinelGuard2_00D619C8) != 0) {
                g_SaveUiSentinel2_00D619CC = 0;
            }
            g_SaveUiSentinel1_00D627C8 = &g_SaveUiSentinel2_00D619CC;
        }
        g_SaveUiSentinel0_00D5FF68 = &g_SaveUiSentinel1_00D627C8;
    }
    void* list = At<void*>(At<void*>(object, 0xd8), 0x168);
    typedef void*(*FirstNode)(void*);
    void** vtable = At<void**>(list, 0);
    for (void* node = reinterpret_cast<FirstNode>(vtable[0])(list);
         node != 0; node = At<void*>(node, 0)) {
        if (node == &g_SaveUiSentinel0_00D5FF68) {
            if (list != 0)
                return 0;
            break;
        }
    }
    void* factory = StMenuBase_Factory_0022CC34();
    ActorStateMachine_RequestStateByFactory(
        At<void*>(object, 0x30), &factory);
    std::uint8_t* current = static_cast<std::uint8_t*>(
        ResourceTree_FindCurrentEntry_001ED44C(
            At<void*>(object, 0x30)));
    At<Word>(object, 0x44) = At<Word>(current, 0x44);
    ParameterString_Normalize_00352994(
        static_cast<std::uint8_t*>(object) + 0x48,
        current + 0x48);
    SaveUi_UpdateTextNodeState_001C16C0(object);
    return 0;
}
extern "C" __attribute__((noinline)) void SaveUi_UpdateStateMachine_00172A64(
    void* object, void*, void*, void* frame_context) {
    void* entry = ResourceTree_ResolveCurrentEntry_002A6268(
        At<void*>(object, 0x30));
    void* update_state =
        static_cast<std::uint8_t*>(At<void*>(entry, 0x20)) + 8;
    const float frame_step = At<float>(frame_context, 0x0c);
    Word update_output[2];
    FUN_0025F180(update_output, update_state, frame_step);
    FUN_0025EED0(update_state, frame_step);
    switch (At<std::uint8_t>(object, 0xf5)) {
    case 0:
        SaveUi_UpdateResourceFlags_00194CE8(object);
        break;
    case 1:
        SaveUi_ActionTextState_00195B80(object);
        break;
    case 2:
        SaveUi_CreateCommonText_0019403C(object);
        break;
    case 3:
        SaveUi_LoadFontResources_001948B8(object);
        SaveUi_UpdateResourceFlags_00194CE8(object);
        break;
    }
    if ((At<std::uint8_t>(object, 0xf0) & 1) != 0) {
        if (At<std::uint8_t>(object, 0xf5) == 0 &&
            At<Word>(object, 0x44) != At<Word>(object, 0x9c)) {
            std::uint8_t* action = static_cast<std::uint8_t*>(
                FUN_00225340(At<void*>(object, 0xe8)));
            Word storage[3];
            Word* record = storage;
            StateParameterRecord_Init_003B530C(record);
            record[0] = At<Word>(action, 0x120);
            record[1] = At<Word>(action, 0x124);
            Actor_PlayActionByHash(
                At<void*>(object, 0xe8), 0x14, record, 1, 1);
        }
        if (g_SaveUiResourceSentinel_00D63844 == 0) {
            g_SaveUiResourceSentinel_00D63844 =
                Engine_LazyOrderedTreeSentinel_002F3368();
        }
        Engine_FindOrCreatePolymorphicResource_0036C090(
            static_cast<std::uint8_t*>(object) + 0x70,
            0xfffffe00u, g_SaveUiResourceSentinel_00D63844);
        At<Word>(object, 0x44) = At<Word>(object, 0x9c);
        ParameterString_Normalize_00352994(
            static_cast<std::uint8_t*>(object) + 0x48,
            static_cast<std::uint8_t*>(object) + 0xa0);
        ResourceState_CopyOrResolve_002BFD54(
            static_cast<std::uint8_t*>(object) + 0x34,
            static_cast<std::uint8_t*>(object) + 0x44);
        At<std::uint8_t>(object, 0xf0) &= 0xfe;
    }
    SaveUiTransientRecord* records = reinterpret_cast<SaveUiTransientRecord*>(
        static_cast<std::uint8_t*>(object) + 0x3ac);
    for (Word i = 0; i != 17; ++i) {
        records[i].flags = 0;
        for (unsigned kiu_i8 = 0;
             kiu_i8 != sizeof(records[i].bounds) / sizeof((records[i].bounds)[0]); ++kiu_i8) {
            float& bound = (records[i].bounds)[kiu_i8]; bound = 0.0f;
        }
        for (unsigned kiu_i9 = 0;
             kiu_i9 != sizeof(records[i].state) / sizeof((records[i].state)[0]); ++kiu_i9) {
            Word& state = (records[i].state)[kiu_i9]; state = 0;
        }
        records[i].tail = 0;
    }
    for (Word offset = 0x610; offset != 0x624; offset += sizeof(Word))
        At<Word>(object, offset) = 0;
}
extern "C" __attribute__((noinline)) int SaveUi_AdvanceResourceState_001726F8(
    void* object, void* unused, void* frame_context) {
    (void)unused;
    std::uint8_t* bytes = static_cast<std::uint8_t*>(object);
    void* manager = g_FontTextManagerCache_00D6366C;
    if (At<std::uint8_t>(object, 0xf9) < 5) {
        switch (At<std::uint8_t>(object, 0xf9)) {
        case 0:
        case 1: {
            if (manager == 0) {
                manager = FontTextManager_Get_003532F0();
                g_FontTextManagerCache_00D6366C = manager;
            }
            if (FontTextManager_IsReady_002A1E94(manager, -1) == 0) {
                manager = g_FontTextManagerCache_00D6366C;
                if (manager == 0) {
                    manager = FontTextManager_Get_003532F0();
                    g_FontTextManagerCache_00D6366C = manager;
                }
                FontTextManager_PlayCommand_002EECB8(
                    manager, 1, 0,
                    At<std::uint8_t>(object, 0xf9) == 0 ? 0x1a : 0x1b, 0);
                ++At<std::uint8_t>(object, 0xf9);
            }
            break;
        }
        case 2: {
            if (manager == 0) {
                manager = FontTextManager_Get_003532F0();
                g_FontTextManagerCache_00D6366C = manager;
            }
            if (FontTextManager_IsReady_002A1E94(manager, -1) == 0) {
                bytes[0xf9] = 5;
                unsigned action = 0;
                if ((bytes[0xf1] & 0x40) == 0) {
                    void* entry = ResourceTree_ResolveCurrentEntry_002A6268(
                        At<void*>(object, 0x30));
                    int discriminator = ResourcePathState_Discriminate_001EC0B4(
                        At<void*>(entry, 0x20), 0);
                    if (discriminator == 4) {
                        void* profile = g_MenuProfileSingleton_00D6365C;
                        if (profile == 0) {
                            profile = GetEngineSingleton_003B6CF0();
                            g_MenuProfileSingleton_00D6365C = profile;
                        }
                        if (MenuProfile_AvailabilityPredicate_002B6238(
                                static_cast<std::uint8_t*>(profile) + 0x16570,
                                4) != 0)
                            action = 1;
                    }
                    entry = ResourceTree_ResolveCurrentEntry_002A6268(
                        At<void*>(object, 0x30));
                    discriminator = ResourceState_GetKind_003207E8(
                        At<void*>(entry, 0x20));
                    action = ResourceEvent_PrepareAndDispatch_00302AC8(
                        bytes + 0x34, At<void*>(object, 0x30),
                        At<void*>(object, 0x44), action, 1);
                    if (action != 0 && discriminator == 2) {
                        void* shared = g_MenuRuntimeShared_00D635E0;
                        if (shared == 0) {
                            shared = MenuRuntime_GetShared_00225B50();
                            g_MenuRuntimeShared_00D635E0 = shared;
                        }
                        MenuState_PublishSelectionMode_0028AB9C(shared, 1);
                        SaveUi_PromoteActiveRecord_001C14A8(object);
                    }
                } else {
                    bytes[0xf5] = 2;
                    bytes[0xf7] = 0;
                    void* entry = ResourceTree_ResolveCurrentEntry_002A6268(
                        At<void*>(object, 0x30));
                    At<std::uint8_t>(At<void*>(entry, 0x20), 0x59c) = 1;
                }
            }
            break;
        }
        case 3:
            if (SaveUi_ResourceGate_0018C820() == 0) {
                if (manager == 0) {
                    manager = FontTextManager_Get_003532F0();
                    g_FontTextManagerCache_00D6366C = manager;
                }
                if (FontTextManager_IsReady_002A1E94(manager, -1) == 0) {
                    FontTextManager_PlayCommand_002EECB8(
                        manager, 1, 0, 0x19, 0);
                    bytes[0xf9] = 4;
                }
            } else {
                bytes[0xf9] = 4;
            }
            break;
        case 4:
            if (manager == 0) {
                manager = FontTextManager_Get_003532F0();
                g_FontTextManagerCache_00D6366C = manager;
            }
            if (FontTextManager_IsReady_002A1E94(manager, -1) == 0) {
                FontTextManager_PlayCommand_002EECB8(
                    manager, 1, 0, 0x19, 0);
                bytes[0xf9] = 5;
                bytes[0xf5] = 1;
                bytes[0xf7] = 0;
            }
            break;
        default:
            break;
        }
    } else if ((bytes[0xf0] & 1) == 0 &&
               (bytes[0xf5] == 0 || bytes[0xf5] == 3)) {
        At<Word>(object, 0x610) = At<Word>(frame_context, 0x2c);
        At<Word>(object, 0x614) = At<Word>(frame_context, 0x30);
        At<Word>(object, 0x618) = At<Word>(frame_context, 0x34);
        At<Word>(object, 0x61c) = At<Word>(frame_context, 0x38);
        At<Word>(object, 0x620) = At<Word>(frame_context, 0x38);
    }
    return 0;
}

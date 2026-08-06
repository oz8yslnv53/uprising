#include <cstdint>
extern "C" std::uint32_t ResourceTree_CheckEntry_0022CF04(
    void*, void*);
extern "C" void* MenuRuntime_GetShared_00225B50();
extern "C" std::uint32_t FUN_0028AC18(void*);
extern "C" void* ResourceTree_ResolveCurrentEntry_002A6268(void*);
extern "C" void ResourceTree_SetTransitionMode_0025F13C(
    void*, std::uint32_t);
extern "C" void* MenuResource_FindNamedObject_00274FE8(
    void*, const char*);
extern "C" std::uint32_t FUN_00320814(void*);
extern "C" void* GetEngineSingleton_003B6CF0();
extern "C" std::uint32_t FUN_002B6238(void*, std::uint32_t);
extern "C" void FUN_002EC8E8(void*, std::uint32_t);
extern "C" void* FUN_003B6C98();
extern "C" void FUN_002B59C4(void*);
namespace actor_param {
void* MenuSelFileParam_Factory_0030444C();
}
extern "C" void* OrderedTree_FindPayloadByPointer_00326C6C(
    void*, void*);
extern "C" std::uint32_t RenderDraw_InstallSingleRecord_0025F640(
    void*, const std::int32_t*);
extern "C" void FUN_00322434(void*, std::int32_t);
extern "C" void* Engine_LazySingletonGetter_003FD6E0();
extern "C" void Resource_SetModeValue_0031EEB8(
    void*, std::int32_t, float);
extern "C" void* Engine_LazySingletonGetter_00422CC8();
extern "C" void* FUN_00353348();
extern "C" void FUN_002EEE14(void*);
extern "C" void EngineResource_ActivatePendingStates_0025E9D8(void*);
extern "C" void FUN_0025F180(void*, void*, float);
extern "C" void FUN_0025EED0(void*, float);
extern "C" void MenuSelFile_TransferAnchorDelta_0030219C(void*);
extern "C" void ResourceTransform_SyncLinkedPositions_002604C0(void*);
extern "C" std::uint32_t
MenuResourceList_HasNoConflictingState_00260620(void*, void*);
extern "C" void* StMenuBase_Factory_0022CC34();
extern "C" void ActorStateMachine_RequestStateByFactory(void*, void*);
extern "C" void* g_MenuSelectionState_00D635E0;
extern "C" void* g_MenuProfileSingleton_00D6365C;
extern "C" void* g_MenuEnvironmentSingleton_00D6364C;
extern "C" void* g_MenuSelFileSelectionDispatcher_00D63854;
extern "C" void* g_MenuSelectionRuntime_00D6367C;
extern "C" void* g_MenuResourceAdvanceSingleton_00D63588;
namespace {
template <typename T>
T& At(void* object, std::uint32_t offset) {
    return *reinterpret_cast<T*>(
        static_cast<std::uint8_t*>(object) + offset);
}
}  // namespace
extern "C" __attribute__((noinline)) void
MenuResource_AdvanceSharedState_003207AC(void* resource) {
    if ((At<std::uint8_t>(resource, 0x840) & 1) != 0)
        return;
    if (g_MenuResourceAdvanceSingleton_00D63588 == 0)
        g_MenuResourceAdvanceSingleton_00D63588 = FUN_003B6C98();
    FUN_002B59C4(At<void*>(
        g_MenuResourceAdvanceSingleton_00D63588, 0x2a0));
}
extern "C" __attribute__((noinline)) std::uint32_t MenuSelFile_DeactivateBooks_002BC794(void* object) {
    void* current = ResourceTree_ResolveCurrentEntry_002A6268(
        At<void*>(object, 0x30));
    ResourceTree_SetTransitionMode_0025F13C(
        static_cast<std::uint8_t*>(At<void*>(current, 0x20)) + 8, 2);
    void* book = MenuResource_FindNamedObject_00274FE8(
        At<void*>(object, 0xd8),
        reinterpret_cast<const char*>(0x002bc804));
    At<std::uint32_t>(book, 0xc0) &= ~4u;
    book = MenuResource_FindNamedObject_00274FE8(
        At<void*>(object, 0xdc),
        reinterpret_cast<const char*>(0x002bc80c));
    At<std::uint32_t>(book, 0xc0) &= ~4u;
    book = MenuResource_FindNamedObject_00274FE8(
        At<void*>(object, 0xe0),
        reinterpret_cast<const char*>(0x002bc814));
    At<std::uint32_t>(book, 0xc0) &= ~4u;
    return 0;
}
extern "C" __attribute__((noinline)) std::uint32_t
MenuSelFile_UpdateAnchorAndRequestBase_002BCFE4(
    void* object, void*, void*, const void* update_record) {
    MenuSelFile_TransferAnchorDelta_0030219C(object);
    void* current = ResourceTree_ResolveCurrentEntry_002A6268(
        At<void*>(object, 0x30));
    std::uint8_t* resource = static_cast<std::uint8_t*>(At<void*>(current, 0x20));
    std::uint32_t scratch[2];
    FUN_0025F180(
        scratch, resource + 8,
        At<const float>(const_cast<void*>(update_record), 0x0c));
    ResourceTransform_SyncLinkedPositions_002604C0(resource + 0x98);
    if (MenuResourceList_HasNoConflictingState_00260620(
            static_cast<std::uint8_t*>(object) + 0x60,
            At<void*>(object, 0x30)) != 0) {
        void* factory = StMenuBase_Factory_0022CC34();
        ActorStateMachine_RequestStateByFactory(
            At<void*>(object, 0x30), &factory);
    }
    return 0;
}
extern "C" __attribute__((noinline)) std::uint32_t
MenuSelFile_UpdateRenderResources_002BD058(
    void* object, void*, void*, const void* update_record) {
    if (ResourceTree_CheckEntry_0022CF04(
            static_cast<std::uint8_t*>(object) + 0x60,
            static_cast<std::uint8_t*>(object) + 0x34) != 0) {
        if (g_MenuSelectionState_00D635E0 == 0)
            g_MenuSelectionState_00D635E0 =
                MenuRuntime_GetShared_00225B50();
        if (FUN_0028AC18(g_MenuSelectionState_00D635E0) == 0) {
            if ((At<std::uint8_t>(object, 0x278) & 0x20) != 0) {
                void* entry = ResourceTree_ResolveCurrentEntry_002A6268(
                    At<void*>(object, 0x30));
                void* resource = At<void*>(entry, 0x20);
                if (FUN_00320814(resource) == 4) {
                    if (g_MenuProfileSingleton_00D6365C == 0) {
                        g_MenuProfileSingleton_00D6365C =
                            GetEngineSingleton_003B6CF0();
                    }
                    if (FUN_002B6238(
                            static_cast<std::uint8_t*>(
                                g_MenuProfileSingleton_00D6365C) +
                                0x16570,
                            4) != 0) {
                        FUN_002EC8E8(resource, 2);
                    } else {
                        MenuResource_AdvanceSharedState_003207AC(resource);
                    }
                } else {
                    MenuResource_AdvanceSharedState_003207AC(resource);
                }
            }
            if (g_MenuProfileSingleton_00D6365C == 0)
                g_MenuProfileSingleton_00D6365C =
                    GetEngineSingleton_003B6CF0();
            if (At<std::uint8_t>(object, 0xd4) < 3 &&
                (At<std::uint8_t>(object, 0x278) & 0x40) == 0) {
                std::uint8_t* const profile =
                    static_cast<std::uint8_t*>(
                        g_MenuProfileSingleton_00D6365C);
                profile[0x518] = At<std::uint8_t>(object, 0xd4);
                void* key =
                    actor_param::MenuSelFileParam_Factory_0030444C();
                void* node = OrderedTree_FindPayloadByPointer_00326C6C(
                    At<void*>(object, 0x30), &key);
                std::uint8_t* params = node == 0
                    ? 0
                    : At<std::uint8_t*>(node, 0x1c);
                for (std::uint32_t index = 0; index < 4; ++index) {
                    if (At<void*>(params, 0x228 + index * 0x2c) !=
                        At<void*>(object, 0x34)) {
                        continue;
                    }
                    At<std::uint8_t>(object, 0xd4) =
                        static_cast<std::uint8_t>(index);
                    if (index < 3) {
                        if (g_MenuProfileSingleton_00D6365C == 0) {
                            g_MenuProfileSingleton_00D6365C =
                                GetEngineSingleton_003B6CF0();
                        }
                        const std::int32_t* source =
                            reinterpret_cast<const std::int32_t*>(
                                static_cast<std::uint8_t*>(
                                    g_MenuProfileSingleton_00D6365C) +
                                0x1a0 + index * 0x18c);
                        RenderDraw_InstallSingleRecord_0025F640(
                            g_MenuProfileSingleton_00D6365C, source);
                    }
                    break;
                }
                FUN_00322434(profile, -1);
                if (g_MenuSelFileSelectionDispatcher_00D63854 == 0) {
                    g_MenuSelFileSelectionDispatcher_00D63854 =
                        Engine_LazySingletonGetter_003FD6E0();
                }
                void* const dispatcher =
                    g_MenuSelFileSelectionDispatcher_00D63854;
                Resource_SetModeValue_0031EEB8(
                    dispatcher, 0, At<float>(profile, 0x640c));
                Resource_SetModeValue_0031EEB8(
                    dispatcher, 2, At<float>(profile, 0x6414));
                Resource_SetModeValue_0031EEB8(
                    dispatcher, 1, At<float>(profile, 0x6410));
                At<std::uint8_t>(dispatcher, 0x163eb) =
                    (profile[0x32e8] & 2) >> 1;
                if (g_MenuEnvironmentSingleton_00D6364C == 0) {
                    g_MenuEnvironmentSingleton_00D6364C =
                        Engine_LazySingletonGetter_00422CC8();
                }
                At<std::uint8_t>(
                    g_MenuEnvironmentSingleton_00D6364C, 0x2b59d) =
                    profile[0x63ec];
                if (g_MenuSelectionRuntime_00D6367C == 0)
                    g_MenuSelectionRuntime_00D6367C = FUN_00353348();
                FUN_002EEE14(g_MenuSelectionRuntime_00D6367C);
            }
            void* entry = ResourceTree_ResolveCurrentEntry_002A6268(
                At<void*>(object, 0x30));
            EngineResource_ActivatePendingStates_0025E9D8(
                At<void*>(entry, 0x20));
        }
    }
    void* entry = ResourceTree_ResolveCurrentEntry_002A6268(
        At<void*>(object, 0x30));
    void* resource = At<void*>(entry, 0x20);
    std::uint32_t scratch[2];
    const float update = At<const float>(
        const_cast<void*>(update_record), 0x0c);
    FUN_0025F180(scratch, static_cast<std::uint8_t*>(resource) + 8, update);
    FUN_0025EED0(static_cast<std::uint8_t*>(resource) + 8, update);
    return 0;
}

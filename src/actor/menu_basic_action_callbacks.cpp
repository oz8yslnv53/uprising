#include <cstdint>
typedef std::uint32_t Word;
namespace actor_param {
void* MenuBasicParam_Factory_002C004C(void);
}
extern "C" void* OrderedTree_FindPayloadByPointer_00326C6C(
    void* tree, const Word* key);
extern "C" void* Engine_LazyStyleSelectionKey_00275B68();
extern "C" void* Engine_GetCommandObjectPayload_003D92BC(void* owner);
extern "C" void* OrderedTree_LowerBoundBySignedKey_00390A98(
    void* tree, std::int32_t key);
extern "C" void* ResourceTree_ResolveCurrentEntry_002A6268(void* resource);
extern "C" void StateParameterRecord_Init_003B530C(Word* record);
extern "C" void Actor_PlayActionByHash(
    void* actor, int channel, Word* record, int enabled, int flags);
extern "C" void ResourceTree_Activate_002A17A0(
    void* resource, void* owner, Word mode);
extern "C" Word StMenuAppear_Factory_00234A94();
extern "C" Word StMenuDisappear_Factory_0028AADC();
extern "C" Word StMenuNoForcus_Factory_0023B79C();
extern "C" Word StMenuForcus_Factory_0027D058();
extern "C" void* ActorStateMachine_RequestStateByFactory_0036BEF0(
    void* owner, Word* factory);
namespace {
template <typename T>
T& At(void* object, Word offset) {
    return *reinterpret_cast<T*>(
        static_cast<std::uint8_t*>(object) + offset);
}
void* ResolveMenuBasicParam(void* owner) {
    const Word key = reinterpret_cast<Word>(
        actor_param::MenuBasicParam_Factory_002C004C());
    void* entry = OrderedTree_FindPayloadByPointer_00326C6C(owner, &key);
    return entry == 0 ? 0 : At<void*>(entry, 0x1c);
}
void Dispatch(void* owner, void* parameter, Word pair_offset) {
    char* name = At<char*>(parameter, pair_offset + 4);
    if (name[0] == '\0') {
        return;
    }
    Word storage[3];
    Word* record = storage;
    StateParameterRecord_Init_003B530C(record);
    record[0] = At<Word>(parameter, pair_offset);
    record[1] = reinterpret_cast<Word>(name);
    Actor_PlayActionByHash(owner, 0x14, record, 1, 1);
}
}  // namespace
extern "C" __attribute__((noinline)) Word MenuBasic_RequestDisappearOnAnonymousMessage_002EF1C0(
    void* object, void*, void* event, void*) {
    void* owner = At<void*>(object, 0x30);
    Word factory = StMenuDisappear_Factory_0028AADC();
    void* state = ActorStateMachine_RequestStateByFactory_0036BEF0(
        owner, &factory);
    if (At<std::uint8_t>(event, 0x29) != 0) {
        At<std::uint8_t>(state, 0x0c) = 1;
    }
    return 0;
}
extern "C" __attribute__((noinline)) Word MenuBasic_RequestDisappearOnSharedEvent_002EF2F0(
    void* object, void*, void* event, void*) {
    void* owner = At<void*>(object, 0x30);
    Word factory = StMenuDisappear_Factory_0028AADC();
    void* state = ActorStateMachine_RequestStateByFactory_0036BEF0(
        owner, &factory);
    if (At<std::uint8_t>(event, 0x29) != 0) {
        At<std::uint8_t>(state, 0x0c) = 1;
    }
    return 0;
}
extern "C" __attribute__((noinline)) Word MenuBasic_DispatchAppearanceAction_002EF32C(void* object) {
    void* owner = At<void*>(object, 0x30);
    void* parameter = ResolveMenuBasicParam(owner);
    void* current = ResourceTree_ResolveCurrentEntry_002A6268(owner);
    unsigned char flags = At<std::uint8_t>(current, 0x64);
    if ((flags & 2) == 0) {
        flags &= ~std::uint8_t(1);
        Dispatch(owner, parameter, 0x18);
    } else {
        Dispatch(owner, parameter, 0x44);
        flags |= 1;
    }
    return 0;
}
extern "C" __attribute__((noinline)) Word MenuBasic_UpdateFocusSelection_002EF4EC(
    void* object, void*, void* selection, void*) {
    void* owner = At<void*>(object, 0x30);
    void* current = ResourceTree_ResolveCurrentEntry_002A6268(owner);
    const Word key = reinterpret_cast<Word>(Engine_LazyStyleSelectionKey_00275B68());
    std::uint8_t* selected = static_cast<std::uint8_t*>(
        OrderedTree_FindPayloadByPointer_00326C6C(owner, &key));
    void* payload = selected == 0 ? 0 : At<void*>(selected, 0x1c);
    unsigned char flags = At<std::uint8_t>(current, 0x64);
    if (At<Word>(payload, 0x18) == At<Word>(selection, 0x2c)) {
        flags |= 1;
    } else {
        Word factory = StMenuNoForcus_Factory_0023B79C();
        void* state = ActorStateMachine_RequestStateByFactory_0036BEF0(
            owner, &factory);
        At<std::uint8_t>(state, 0x0c) = At<std::uint8_t>(selection, 0x60);
        flags &= ~std::uint8_t(1);
    }
    return 0;
}
extern "C" __attribute__((noinline)) Word MenuBasic_DispatchForcusAction_002EF578(
    void* object, void* state) {
    void* owner = At<void*>(object, 0x30);
    void* parameter = ResolveMenuBasicParam(owner);
    Dispatch(owner, parameter,
             At<std::uint8_t>(state, 0x0c) == 0 ? 0xc8 : 0x70);
    return 0;
}
extern "C" __attribute__((noinline)) Word MenuBasic_RequestFocusActionWhenReady_002EF650(void* object) {
    void* owner = At<void*>(object, 0x30);
    void* current = ResourceTree_ResolveCurrentEntry_002A6268(owner);
    if ((At<std::uint8_t>(current, 0x64) & 1) == 0) {
        Word factory = StMenuNoForcus_Factory_0023B79C();
        ActorStateMachine_RequestStateByFactory_0036BEF0(owner, &factory);
    }
    std::uint8_t* candidate = static_cast<std::uint8_t*>(
        OrderedTree_LowerBoundBySignedKey_00390A98(
            Engine_GetCommandObjectPayload_003D92BC(owner), 0x14));
    std::uint8_t* node = At<std::uint8_t*>(candidate, 0x20);
    if (node == candidate + 0x1c) {
        return 0;
    }
    std::uint8_t* payload_node = At<std::uint8_t*>(node, 0);
    if (At<std::uint8_t*>(payload_node, 0x10) == payload_node + 0x0c) {
        return 0;
    }
    unsigned char* resource = *At<std::uint8_t**>(payload_node, 0x14);
    if (resource == 0 || resource[0x24] != 0) {
        return 0;
    }
    void* parameter = ResolveMenuBasicParam(owner);
    Dispatch(owner, parameter, 0xc8);
    return 0;
}
extern "C" __attribute__((noinline)) Word MenuBasic_RequestFocusSelection_002EF758(
    void* object, void*, void* selection, void*) {
    void* owner = At<void*>(object, 0x30);
    void* current = ResourceTree_ResolveCurrentEntry_002A6268(owner);
    const Word key = reinterpret_cast<Word>(Engine_LazyStyleSelectionKey_00275B68());
    std::uint8_t* selected = static_cast<std::uint8_t*>(
        OrderedTree_FindPayloadByPointer_00326C6C(owner, &key));
    void* payload = selected == 0 ? 0 : At<void*>(selected, 0x1c);
    unsigned char flags = At<std::uint8_t>(current, 0x64);
    if (At<Word>(payload, 0x18) != At<Word>(selection, 0x2c)) {
        flags &= ~std::uint8_t(1);
        return 0;
    }
    Word factory = StMenuForcus_Factory_0027D058();
    void* state = ActorStateMachine_RequestStateByFactory_0036BEF0(owner, &factory);
    At<std::uint8_t>(state, 0x0c) = At<std::uint8_t>(selection, 0x60);
    flags |= 1;
    return 0;
}
extern "C" __attribute__((noinline)) Word MenuBasic_DispatchNoForcusAction_002EF7E0(
    void* object, void* state) {
    void* owner = At<void*>(object, 0x30);
    void* parameter = ResolveMenuBasicParam(owner);
    Dispatch(owner, parameter,
             At<std::uint8_t>(state, 0x0c) == 0 ? 0xf4 : 0x9c);
    return 0;
}
extern "C" __attribute__((noinline)) Word MenuBasic_DispatchDisappearanceAction_002EF9D0(
    void* object, void* state) {
    void* owner = At<void*>(object, 0x30);
    void* parameter = ResolveMenuBasicParam(owner);
    Dispatch(owner, parameter,
             (At<std::uint8_t>(state, 0x0c) & 1) == 0 ? 0x120 : 0x14c);
    return 0;
}
extern "C" __attribute__((noinline)) Word MenuBasic_DisappearanceFollowup_002EFAB4(void* object) {
    void* owner = At<void*>(object, 0x30);
    void* current = ResourceTree_ResolveCurrentEntry_002A6268(owner);
    if ((At<std::uint8_t>(current, 0x64) & 4) != 0) {
        std::uint8_t* resource = static_cast<std::uint8_t*>(
            At<void*>(current, 0x20)) + 8;
        ResourceTree_Activate_002A17A0(resource, owner, 1);
    } else {
        Word factory = StMenuAppear_Factory_00234A94();
        ActorStateMachine_RequestStateByFactory_0036BEF0(owner, &factory);
    }
    return 0;
}

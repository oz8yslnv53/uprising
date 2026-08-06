#include <stdint.h>
typedef uint32_t Word;
extern "C" void StateParameterRecord_Init_003B530C(Word* record);
extern "C" void Actor_PlayActionByHash(Word actor, int channel,
                                        Word* record, int enabled, int flags);
extern "C" void* OrderedTree_LowerBoundBySignedKey_00390A98(void* tree,
                                                              int key);
extern "C" Word StMenuNoForcus_Factory_0023B79C();
extern "C" Word StMenuForcus_Factory_0027D058();
extern "C" Word StMenuAppear_Factory_00234A94();
extern "C" Word ResourceTree_KeyGetter_002A18B8();
extern "C" Word ActorParam_MenuDollParam_Factory_001F53A4();
extern "C" Word Engine_LazyCommandObjectClass_00390B08();
extern "C" Word ActionGroup_SelectActionRecord_004216A0(void* group,
                                                            Word* record);
extern "C" Word StMenuStay_Factory_0022CCBC();
extern "C" Word Engine_LazySoundResourceDescriptor_001C47C4();
extern "C" Word StMenuBase_Factory_0022CC34();
extern "C" Word Engine_LazyCommandWorkSingleton_0027C908();
extern "C" void ParameterString_Format_003FDA9C(
    void* output, Word count, const char* format, Word value);
extern "C" void* FUN_002EE080(void* state, Word owner);
extern "C" void* FUN_002D6DDC(
    void* resource, void* context, const char* name);
extern "C" void ActorStateMachine_RequestStateByFactory(Word actor,
                                                          Word* factory);
extern "C" void* Actor_ActionResource_0022529C(Word actor);
extern "C" void* ResourceTree_ResolveCurrentEntry_002A6268(Word resource);
extern "C" Word Actor_ActionKey_00246360();
extern "C" void Actor_ActionRecordForward_001B0810(void* actor,
                                                     void* action_record);
static uint8_t* select_action_payload_by_key(
    uint8_t* resource_owner, Word key) {
    uint8_t* sentinel = *reinterpret_cast<uint8_t**>(resource_owner + 0x1AC);
    uint8_t* current = sentinel;
    uint8_t* previous = resource_owner + 0x1A8;
    while (current != 0 && current[0x10] != 0) {
        uint8_t** links = reinterpret_cast<uint8_t**>(current);
        if (*reinterpret_cast<Word*>(current + 0x14) < key) {
            current = links[3];
        } else {
            uint8_t* node = current;
            current = links[2];
            previous = node;
        }
    }
    if (previous == resource_owner + 0x1A8 ||
        key < *reinterpret_cast<Word*>(previous + 0x14))
        previous = resource_owner + 0x1A8;
    if (previous == 0 ||
        *reinterpret_cast<uint8_t**>(previous) ==
            *reinterpret_cast<uint8_t**>(resource_owner + 0x1A8))
        return 0;
    return *reinterpret_cast<uint8_t**>(previous);
}
static uint8_t* select_action_payload_00183EB0(
    uint8_t* resource_owner) {
    return select_action_payload_by_key(
        resource_owner, Actor_ActionKey_00246360());
}
extern "C" __attribute__((noinline)) void Actor_UpdateFontResourceVisibility_001961A4(
    void*, Word owner) {
    if (owner == 0)
        return;
    uint8_t* entry = static_cast<uint8_t*>(
        ResourceTree_ResolveCurrentEntry_002A6268(owner));
    if (entry == 0)
        return;
    uint8_t* selected = select_action_payload_by_key(
        reinterpret_cast<uint8_t*>(owner),
        Engine_LazyCommandWorkSingleton_0027C908());
    if (selected == 0)
        return;
    const Word visible =
        (*reinterpret_cast<uint8_t*>(entry + 0x64) >> 6) & 1;
    uint8_t* link = *reinterpret_cast<uint8_t**>(selected + 0x20);
    Word index = 0;
    while (*reinterpret_cast<uint8_t**>(link) != selected + 0x1c) {
        char name[8];
        ParameterString_Format_003FDA9C(name, 7, "fnt_%02d", index);
        entry = static_cast<uint8_t*>(
            ResourceTree_ResolveCurrentEntry_002A6268(owner));
        void* context = FUN_002EE080(
            static_cast<uint8_t*>(
                *reinterpret_cast<void**>(entry + 0x20)) + 8,
            owner);
        if (context != 0) {
            uint8_t* font = static_cast<uint8_t*>(FUN_002D6DDC(
                static_cast<uint8_t*>(
                    *reinterpret_cast<void**>(entry + 0x20)) + 0x20c,
                context, name));
            if (font != 0) {
                Word flags = *reinterpret_cast<Word*>(font + 0xc0);
                flags = (flags & ~Word(2)) | (visible << 1);
            }
        }
        ++index;
        link = *reinterpret_cast<uint8_t**>(link + 4);
    }
}
extern "C" __attribute__((noinline)) int Actor_UpdateActionRecords_001833E8(void* actor_state) {
    uint8_t* actor = static_cast<uint8_t*>(actor_state);
    uint8_t* status = *reinterpret_cast<uint8_t**>(actor + 0x40);
    const uint8_t status_flags = status[0x64];
    uint8_t* resource = *reinterpret_cast<uint8_t**>(actor + 0x38);
    Word record[2];
    if ((status_flags & 0x40u) != 0) {
        const char* action_name = *reinterpret_cast<const char**>(resource + 0x17C);
        if (*action_name != '\0') {
            Word* initialized = record;
            StateParameterRecord_Init_003B530C(initialized);
            initialized[1] = *reinterpret_cast<Word*>(resource + 0x17C);
            initialized[0] = *reinterpret_cast<Word*>(resource + 0x178);
            Actor_PlayActionByHash(
                *reinterpret_cast<Word*>(actor + 0x30), 0x14, record, 1, 1);
            status[0x64] |= 1u;
        }
    } else if ((status_flags & 2u) != 0) {
        const char* action_name = *reinterpret_cast<const char**>(resource + 0x48);
        if (*action_name != '\0') {
            Word* initialized = record;
            StateParameterRecord_Init_003B530C(initialized);
            initialized[1] = *reinterpret_cast<Word*>(resource + 0x48);
            initialized[0] = *reinterpret_cast<Word*>(resource + 0x44);
            Actor_PlayActionByHash(
                *reinterpret_cast<Word*>(actor + 0x30), 0x14, record, 1, 1);
            status[0x64] |= 1u;
        }
    } else {
        status[0x64] &= static_cast<uint8_t>(~1u);
        const char* action_name = *reinterpret_cast<const char**>(resource + 0x1C);
        if (*action_name != '\0') {
            Word* initialized = record;
            StateParameterRecord_Init_003B530C(initialized);
            initialized[1] = *reinterpret_cast<Word*>(resource + 0x1C);
            initialized[0] = *reinterpret_cast<Word*>(resource + 0x18);
            Actor_PlayActionByHash(
                *reinterpret_cast<Word*>(actor + 0x30), 0x14, record, 1, 1);
        }
    }
    return 0;
}
extern "C" __attribute__((noinline)) int Actor_DispatchConditionalAction_00183680(
    void* actor_state, void* condition) {
    uint8_t* actor = static_cast<uint8_t*>(actor_state);
    uint8_t* status = *reinterpret_cast<uint8_t**>(actor + 0x40);
    const unsigned int status_mode = status[0x64] & 0x40u;
    uint8_t* resource = *reinterpret_cast<uint8_t**>(actor + 0x38);
    const bool alternate =
        *reinterpret_cast<const uint8_t*>(
            static_cast<const uint8_t*>(condition) + 0x0C) != 0;
    Word record[2];
    if (status_mode == 0) {
        const unsigned int record_offset = alternate ? 0x70u : 0xC8u;
        const unsigned int name_offset = alternate ? 0x74u : 0xCCu;
        const char* action_name = *reinterpret_cast<const char**>(
            resource + name_offset);
        if (*action_name != '\0') {
            Word* initialized = record;
            StateParameterRecord_Init_003B530C(initialized);
            initialized[1] = *reinterpret_cast<Word*>(resource + name_offset);
            initialized[0] = *reinterpret_cast<Word*>(resource + record_offset);
            Actor_PlayActionByHash(
                *reinterpret_cast<Word*>(actor + 0x30), 0x14, record, 1, 1);
        }
    }
    return 0;
}
extern "C" __attribute__((noinline)) int Actor_DispatchConditionalAction_001838E8(
    void* actor_state, void* condition) {
    uint8_t* actor = static_cast<uint8_t*>(actor_state);
    uint8_t* status = *reinterpret_cast<uint8_t**>(actor + 0x40);
    const unsigned int status_mode = status[0x64] & 0x40u;
    uint8_t* resource = *reinterpret_cast<uint8_t**>(actor + 0x38);
    const bool alternate =
        *reinterpret_cast<const uint8_t*>(
            static_cast<const uint8_t*>(condition) + 0x0C) != 0;
    if (!alternate && status_mode != 0) {
        const char* action_name = *reinterpret_cast<const char**>(resource + 0xA0);
        if (*action_name != '\0') {
            Word record[2];
            Word* initialized = record;
            StateParameterRecord_Init_003B530C(initialized);
            initialized[1] = *reinterpret_cast<Word*>(resource + 0xA0);
            initialized[0] = *reinterpret_cast<Word*>(resource + 0x9C);
            Actor_PlayActionByHash(
                *reinterpret_cast<Word*>(actor + 0x30), 0x14, record, 1, 1);
        }
    } else if (alternate && status_mode == 0) {
        const char* action_name = *reinterpret_cast<const char**>(resource + 0xF8);
        if (*action_name != '\0') {
            Word record[2];
            Word* initialized = record;
            StateParameterRecord_Init_003B530C(initialized);
            initialized[1] = *reinterpret_cast<Word*>(resource + 0xF8);
            initialized[0] = *reinterpret_cast<Word*>(resource + 0xF4);
            Actor_PlayActionByHash(
                *reinterpret_cast<Word*>(actor + 0x30), 0x14, record, 1, 1);
        }
    }
    return 0;
}
extern "C" __attribute__((noinline)) int Actor_DispatchConditionalAction_00183AB4(
    void* actor_state, void* condition) {
    uint8_t* actor = static_cast<uint8_t*>(actor_state);
    uint8_t* status = *reinterpret_cast<uint8_t**>(actor + 0x40);
    const unsigned int status_mode = status[0x64] & 0x40u;
    uint8_t* resource = *reinterpret_cast<uint8_t**>(actor + 0x38);
    const bool alternate =
        (*(static_cast<const uint8_t*>(condition) + 0x0C)) & 1u;
    Word record[2];
    if (!alternate && status_mode == 0) {
        const char* action_name = *reinterpret_cast<const char**>(resource + 0x124);
        if (*action_name != '\0') {
            Word* initialized = record;
            StateParameterRecord_Init_003B530C(initialized);
            initialized[1] = *reinterpret_cast<Word*>(resource + 0x124);
            initialized[0] = *reinterpret_cast<Word*>(resource + 0x120);
            Actor_PlayActionByHash(
                *reinterpret_cast<Word*>(actor + 0x30), 0x14, record, 1, 1);
            return 0;
        }
    } else if (alternate && status_mode == 0) {
        const char* action_name = *reinterpret_cast<const char**>(resource + 0x150);
        if (*action_name != '\0') {
            Word* initialized = record;
            StateParameterRecord_Init_003B530C(initialized);
            initialized[1] = *reinterpret_cast<Word*>(resource + 0x150);
            initialized[0] = *reinterpret_cast<Word*>(resource + 0x14C);
            Actor_PlayActionByHash(
                *reinterpret_cast<Word*>(actor + 0x30), 0x14, record, 1, 1);
            return 0;
        }
    } else {
        const char* action_name = *reinterpret_cast<const char**>(resource + 0x1D4);
        if (*action_name != '\0') {
            Word* initialized = record;
            StateParameterRecord_Init_003B530C(initialized);
            initialized[1] = *reinterpret_cast<Word*>(resource + 0x1D4);
            initialized[0] = *reinterpret_cast<Word*>(resource + 0x1D0);
            Actor_PlayActionByHash(
                *reinterpret_cast<Word*>(actor + 0x30), 0x14, record, 1, 1);
            status[0x64] |= 1u;
        }
    }
    return 0;
}
extern "C" __attribute__((noinline)) int Actor_DispatchActionAndSetState_00183E40(void* actor_state) {
    uint8_t* actor = static_cast<uint8_t*>(actor_state);
    uint8_t* resource = *reinterpret_cast<uint8_t**>(actor + 0x4C);
    uint8_t* state = *reinterpret_cast<uint8_t**>(actor + 0x48);
    const char* action_name = *reinterpret_cast<const char**>(resource + 0x48);
    if (*action_name != '\0') {
        Word record[2];
        Word* initialized = record;
        StateParameterRecord_Init_003B530C(initialized);
        initialized[1] = *reinterpret_cast<Word*>(resource + 0x48);
        initialized[0] = *reinterpret_cast<Word*>(resource + 0x44);
        Actor_PlayActionByHash(
            *reinterpret_cast<Word*>(actor + 0x30), 0x14, record, 1, 1);
    }
    state[0x28] = 1;
    return 0;
}
extern "C" __attribute__((noinline)) int Actor_QueueConditionalAction_00183760(void* actor_state) {
    uint8_t* actor = static_cast<uint8_t*>(actor_state);
    uint8_t* status = *reinterpret_cast<uint8_t**>(actor + 0x40);
    if ((status[0x64] & 1u) == 0) {
        Word factory = StMenuNoForcus_Factory_0023B79C();
        ActorStateMachine_RequestStateByFactory(
            *reinterpret_cast<Word*>(actor + 0x30), &factory);
    }
    void* candidate = OrderedTree_LowerBoundBySignedKey_00390A98(
        *reinterpret_cast<void**>(actor + 0x44), 0x14);
    uint8_t* sentinel = static_cast<uint8_t*>(candidate) + 0x1C;
    uint8_t* node = *reinterpret_cast<uint8_t**>(
        static_cast<uint8_t*>(candidate) + 0x20);
    if (node == sentinel)
        return 0;
    uint8_t* payload_node = *reinterpret_cast<uint8_t**>(node);
    if (*reinterpret_cast<uint8_t**>(payload_node + 0x10) ==
        payload_node + 0x0C)
        return 0;
    uint8_t* payload_link = *reinterpret_cast<uint8_t**>(payload_node + 0x14);
    uint8_t* payload = *reinterpret_cast<uint8_t**>(payload_link);
    if (payload == 0 || payload[0x24] != 0 ||
        (status[0x64] & 0x40u) != 0)
        return 0;
    uint8_t* resource = *reinterpret_cast<uint8_t**>(actor + 0x38);
    const char* action_name = *reinterpret_cast<const char**>(resource + 0xCC);
    if (*action_name == '\0')
        return 0;
    Word record[2];
    Word* initialized = record;
    StateParameterRecord_Init_003B530C(initialized);
    initialized[1] = *reinterpret_cast<Word*>(resource + 0xCC);
    initialized[0] = *reinterpret_cast<Word*>(resource + 0xC8);
    Actor_PlayActionByHash(
        *reinterpret_cast<Word*>(actor + 0x30), 0x14, record, 1, 1);
    return 0;
}
extern "C" __attribute__((noinline)) int Actor_QueueConditionalAction_001839C8(void* actor_state) {
    uint8_t* actor = static_cast<uint8_t*>(actor_state);
    uint8_t* status = *reinterpret_cast<uint8_t**>(actor + 0x40);
    if ((status[0x64] & 1u) != 0) {
        Word factory = StMenuForcus_Factory_0027D058();
        ActorStateMachine_RequestStateByFactory(
            *reinterpret_cast<Word*>(actor + 0x30), &factory);
    }
    void* candidate = OrderedTree_LowerBoundBySignedKey_00390A98(
        *reinterpret_cast<void**>(actor + 0x44), 0x14);
    uint8_t* sentinel = static_cast<uint8_t*>(candidate) + 0x1C;
    uint8_t* node = *reinterpret_cast<uint8_t**>(
        static_cast<uint8_t*>(candidate) + 0x20);
    if (node == sentinel)
        return 0;
    uint8_t* payload_node = *reinterpret_cast<uint8_t**>(node);
    if (*reinterpret_cast<uint8_t**>(payload_node + 0x10) ==
        payload_node + 0x0C)
        return 0;
    uint8_t* payload_link = *reinterpret_cast<uint8_t**>(payload_node + 0x14);
    uint8_t* payload = *reinterpret_cast<uint8_t**>(payload_link);
    if (payload == 0 || payload[0x24] != 0 ||
        (status[0x64] & 0x40u) != 0)
        return 0;
    uint8_t* resource = *reinterpret_cast<uint8_t**>(actor + 0x38);
    const char* action_name = *reinterpret_cast<const char**>(resource + 0xF8);
    if (*action_name == '\0')
        return 0;
    Word record[2];
    Word* initialized = record;
    StateParameterRecord_Init_003B530C(initialized);
    initialized[1] = *reinterpret_cast<Word*>(resource + 0xF8);
    initialized[0] = *reinterpret_cast<Word*>(resource + 0xF4);
    Actor_PlayActionByHash(
        *reinterpret_cast<Word*>(actor + 0x30), 0x14, record, 1, 1);
    return 0;
}
extern "C" __attribute__((noinline)) int Actor_ClearStateAndDispatchAction_001849C0(
    void* actor_state, void* resource_arg, void*, void*) {
    uint8_t* actor = static_cast<uint8_t*>(actor_state);
    uint8_t* state = *reinterpret_cast<uint8_t**>(actor + 0x44);
    uint8_t* resource = static_cast<uint8_t*>(resource_arg);
    state[0x28] = 0;
    const char* action_name = *reinterpret_cast<const char**>(resource + 0x1C);
    if (*action_name != '\0') {
        Word record[2];
        Word* initialized = record;
        StateParameterRecord_Init_003B530C(initialized);
        initialized[1] = *reinterpret_cast<Word*>(resource + 0x1C);
        initialized[0] = *reinterpret_cast<Word*>(resource + 0x18);
        Actor_PlayActionByHash(
            *reinterpret_cast<Word*>(actor + 0x30), 0x14, record, 1, 1);
    }
    return 0;
}
extern "C" __attribute__((noinline)) int
Actor_ForwardActionRecord_001850F4(void* actor_state) {
    void* action_record = *reinterpret_cast<void**>(
        reinterpret_cast<uint8_t*>(actor_state) + 0x48);
    Actor_ActionRecordForward_001B0810(
        actor_state, reinterpret_cast<uint8_t*>(action_record) + 0x18);
    return 0;
}
extern "C" void Actor_ActionModeFinalize_001B0654(void* actor_state,
                                                    uint8_t mode);
extern "C" __attribute__((noinline)) int
Actor_DispatchPendingActionRecord_00184FFC(void* actor_state) {
    uint8_t* actor = static_cast<uint8_t*>(actor_state);
    uint8_t* state = *reinterpret_cast<uint8_t**>(actor + 0x44);
    uint8_t* resource = *reinterpret_cast<uint8_t**>(actor + 0x48);
    if (state[0x1c] != 0) {
        uint8_t mode = state[0x1e];
        state[0x1c] = 0;
        if (mode == 0)
            Actor_ActionRecordForward_001B0810(actor, resource + 0x44);
        else if (mode == 1)
            Actor_ActionRecordForward_001B0810(actor, resource + 0xc8);
        else if (mode == 2)
            Actor_ActionRecordForward_001B0810(actor, resource + 0x70);
        else if (mode == 3)
            Actor_ActionRecordForward_001B0810(actor, resource + 0x14c);
        else if (mode == 4)
            Actor_ActionRecordForward_001B0810(actor, resource + 0x178);
        else if (mode == 5)
            Actor_ActionRecordForward_001B0810(actor, resource + 0x1a4);
        Actor_ActionModeFinalize_001B0654(actor, mode);
    }
    return 0;
}
extern "C" __attribute__((noinline)) int
Actor_RequestMenuBaseWhenReady_00185110(void* actor_state, void*, void*, void*) {
    uint8_t* actor = static_cast<uint8_t*>(actor_state);
    uint8_t* candidate = static_cast<uint8_t*>(
        OrderedTree_LowerBoundBySignedKey_00390A98(
            *reinterpret_cast<void**>(actor + 0x50), 0x14));
    uint8_t* sentinel = candidate + 0x1c;
    uint8_t* node = *reinterpret_cast<uint8_t**>(candidate + 0x20);
    if (node != sentinel) {
        uint8_t* payload_node = *reinterpret_cast<uint8_t**>(node);
        if (*reinterpret_cast<void**>(payload_node + 0x10) !=
                payload_node + 0x0c) {
            uint8_t* payload_link = *reinterpret_cast<uint8_t**>(
                payload_node + 0x14);
            uint8_t* payload = *reinterpret_cast<uint8_t**>(payload_link);
            if (payload != 0 && payload[0x24] == 0) {
                Actor_ActionRecordForward_001B0810(
                    actor, *reinterpret_cast<uint8_t**>(actor + 0x48) + 0x44);
                Word factory = StMenuBase_Factory_0022CC34();
                ActorStateMachine_RequestStateByFactory(
                    *reinterpret_cast<Word*>(actor + 0x30), &factory);
            }
        }
    }
    return 0;
}
extern "C" __attribute__((noinline)) int
Actor_ForwardActionRecordMode2_00185198(void* actor_state) {
    uint8_t* actor = static_cast<uint8_t*>(actor_state);
    Actor_ActionRecordForward_001B0810(
        actor, *reinterpret_cast<uint8_t**>(actor + 0x48) + 0x70);
    return 0;
}
extern "C" __attribute__((noinline)) int
Actor_RequestMenuBaseWhenCommandReady_001851B4(
    void* actor_state, void*, void*, void*) {
    uint8_t* actor = static_cast<uint8_t*>(actor_state);
    uint8_t* candidate = static_cast<uint8_t*>(
        OrderedTree_LowerBoundBySignedKey_00390A98(
            *reinterpret_cast<void**>(actor + 0x50), 0x14));
    uint8_t* sentinel = candidate + 0x1c;
    uint8_t* node = *reinterpret_cast<uint8_t**>(candidate + 0x20);
    if (node != sentinel) {
        uint8_t* payload_node = *reinterpret_cast<uint8_t**>(node);
        if (*reinterpret_cast<void**>(payload_node + 0x10) !=
                payload_node + 0x0c) {
            uint8_t* payload_link = *reinterpret_cast<uint8_t**>(
                payload_node + 0x14);
            uint8_t* payload = *reinterpret_cast<uint8_t**>(payload_link);
            if (payload != 0 && payload[0x24] == 0) {
                Word factory = StMenuBase_Factory_0022CC34();
                ActorStateMachine_RequestStateByFactory(
                    *reinterpret_cast<Word*>(actor + 0x30), &factory);
            }
        }
    }
    return 0;
}
extern "C" __attribute__((noinline)) int Actor_AdvanceActionRecordState_00184A30(void* actor_state) {
    uint8_t* actor = static_cast<uint8_t*>(actor_state);
    uint8_t* state = *reinterpret_cast<uint8_t**>(actor + 0x44);
    uint8_t* resource = *reinterpret_cast<uint8_t**>(actor + 0x48);
    Word record[2];
    if (state[0x1C] != 0) {
        const char* action_name = *reinterpret_cast<const char**>(resource + 0x48);
        if (*action_name != '\0') {
            Word* initialized = record;
            StateParameterRecord_Init_003B530C(initialized);
            initialized[1] = *reinterpret_cast<Word*>(resource + 0x48);
            initialized[0] = *reinterpret_cast<Word*>(resource + 0x44);
            Actor_PlayActionByHash(
                *reinterpret_cast<Word*>(actor + 0x30), 0x14, record, 1, 1);
        }
        state[0x28] = 1;
        state[0x1C] = 0;
    } else if (state[0x1F] != 0) {
        const char* action_name = *reinterpret_cast<const char**>(resource + 0x1C);
        if (*action_name != '\0') {
            Word* initialized = record;
            StateParameterRecord_Init_003B530C(initialized);
            initialized[1] = *reinterpret_cast<Word*>(resource + 0x1C);
            initialized[0] = *reinterpret_cast<Word*>(resource + 0x18);
            Actor_PlayActionByHash(
                *reinterpret_cast<Word*>(actor + 0x30), 0x14, record, 1, 1);
        }
        state[0x28] = 0;
        state[0x1F] = 0;
    } else if (state[0x1D] != 0) {
        const char* action_name = *reinterpret_cast<const char**>(resource + 0x74);
        if (*action_name != '\0') {
            Word* initialized = record;
            StateParameterRecord_Init_003B530C(initialized);
            initialized[1] = *reinterpret_cast<Word*>(resource + 0x74);
            initialized[0] = *reinterpret_cast<Word*>(resource + 0x70);
            Actor_PlayActionByHash(
                *reinterpret_cast<Word*>(actor + 0x30), 0x14, record, 1, 1);
        }
        state[0x28] = 2;
        state[0x1D] = 0;
    } else if (state[0x1E] != 0) {
        const char* action_name = *reinterpret_cast<const char**>(resource + 0xA0);
        if (*action_name != '\0') {
            Word* initialized = record;
            StateParameterRecord_Init_003B530C(initialized);
            initialized[1] = *reinterpret_cast<Word*>(resource + 0xA0);
            initialized[0] = *reinterpret_cast<Word*>(resource + 0x9C);
            Actor_PlayActionByHash(
                *reinterpret_cast<Word*>(actor + 0x30), 0x14, record, 1, 1);
        }
        state[0x28] = 3;
        state[0x1E] = 0;
    }
    return 0;
}
extern "C" __attribute__((noinline)) int Actor_DispatchResourcePhaseAction_001927A0(
    void* actor_state) {
    uint8_t* actor = static_cast<uint8_t*>(actor_state);
    const Word owner = *reinterpret_cast<Word*>(actor + 0x30);
    uint8_t* action_resource = static_cast<uint8_t*>(
        Actor_ActionResource_0022529C(owner));
    uint8_t* entry = static_cast<uint8_t*>(
        ResourceTree_ResolveCurrentEntry_002A6268(owner));
    Word record[2];
    if (*reinterpret_cast<Word*>(entry + 0x54) == 100) {
        const char* action_name = *reinterpret_cast<const char**>(
            action_resource + 0x124);
        if (*action_name != '\0') {
            Word* initialized = record;
            StateParameterRecord_Init_003B530C(initialized);
            initialized[1] = *reinterpret_cast<Word*>(action_resource + 0x124);
            initialized[0] = *reinterpret_cast<Word*>(action_resource + 0x120);
            Actor_PlayActionByHash(owner, 0x14, record, 1, 1);
        }
    } else {
        const char* action_name = *reinterpret_cast<const char**>(
            action_resource + 0x1C);
        if (*action_name != '\0') {
            Word* initialized = record;
            StateParameterRecord_Init_003B530C(initialized);
            initialized[1] = *reinterpret_cast<Word*>(action_resource + 0x1C);
            initialized[0] = *reinterpret_cast<Word*>(action_resource + 0x18);
            Actor_PlayActionByHash(owner, 0x14, record, 1, 1);
        }
    }
    return 0;
}
extern "C" __attribute__((noinline)) int Actor_DispatchResourcePhaseAction_00192974(
    void* actor_state) {
    uint8_t* actor = static_cast<uint8_t*>(actor_state);
    const Word owner = *reinterpret_cast<Word*>(actor + 0x30);
    uint8_t* action_resource = static_cast<uint8_t*>(
        Actor_ActionResource_0022529C(owner));
    uint8_t* entry = static_cast<uint8_t*>(
        ResourceTree_ResolveCurrentEntry_002A6268(owner));
    Word record[2];
    if (*reinterpret_cast<Word*>(entry + 0x54) == 100) {
        const char* action_name = *reinterpret_cast<const char**>(
            action_resource + 0xF8);
        if (*action_name != '\0') {
            Word* initialized = record;
            StateParameterRecord_Init_003B530C(initialized);
            initialized[1] = *reinterpret_cast<Word*>(action_resource + 0xF8);
            initialized[0] = *reinterpret_cast<Word*>(action_resource + 0xF4);
            Actor_PlayActionByHash(owner, 0x14, record, 1, 1);
        }
    } else {
        const char* action_name = *reinterpret_cast<const char**>(
            action_resource + 0xA0);
        if (*action_name != '\0') {
            Word* initialized = record;
            StateParameterRecord_Init_003B530C(initialized);
            initialized[1] = *reinterpret_cast<Word*>(action_resource + 0xA0);
            initialized[0] = *reinterpret_cast<Word*>(action_resource + 0x9C);
            Actor_PlayActionByHash(owner, 0x14, record, 1, 1);
        }
    }
    return 0;
}
extern "C" __attribute__((noinline)) int Actor_UpdateActionRecordState_00183EB0(void* actor_state) {
    uint8_t* actor = static_cast<uint8_t*>(actor_state);
    uint8_t* state = *reinterpret_cast<uint8_t**>(actor + 0x48);
    uint8_t* resource = *reinterpret_cast<uint8_t**>(actor + 0x4C);
    Word record[2];
    if (state[0x1D] == 0) {
        state[0x28] = 1;
        const char* action_name = *reinterpret_cast<const char**>(resource + 0xCC);
        if (*action_name != '\0') {
            uint8_t* selected = select_action_payload_00183EB0(
                *reinterpret_cast<uint8_t**>(actor + 0x30));
            *reinterpret_cast<Word*>(selected + 0x1C) =
                *reinterpret_cast<Word*>(state + 0x24);
            Word* initialized = record;
            StateParameterRecord_Init_003B530C(initialized);
            initialized[1] = *reinterpret_cast<Word*>(resource + 0xCC);
            initialized[0] = *reinterpret_cast<Word*>(resource + 0xC8);
            Actor_PlayActionByHash(
                *reinterpret_cast<Word*>(actor + 0x30), 0x14, record, 1, 1);
        }
    } else {
        const char* action_name = *reinterpret_cast<const char**>(resource + 0xA0);
        if (*action_name != '\0') {
            Word* initialized = record;
            StateParameterRecord_Init_003B530C(initialized);
            initialized[1] = *reinterpret_cast<Word*>(resource + 0xA0);
            initialized[0] = *reinterpret_cast<Word*>(resource + 0x9C);
            Actor_PlayActionByHash(
                *reinterpret_cast<Word*>(actor + 0x30), 0x14, record, 1, 1);
        }
        state[0x28] = 2;
        state[0x1D] = 0;
    }
    const int16_t remaining = *reinterpret_cast<int16_t*>(state + 0x22);
    if (remaining > 0) {
        const int16_t next = static_cast<int16_t>(remaining - 1);
        *reinterpret_cast<int16_t*>(state + 0x22) = next;
        if (next < 1)
            state[0x20] = 0;
    }
    if (state[0x20] == 0) {
        const char* action_name = *reinterpret_cast<const char**>(resource + 0x74);
        if (*action_name != '\0') {
            Word* initialized = record;
            StateParameterRecord_Init_003B530C(initialized);
            initialized[1] = *reinterpret_cast<Word*>(resource + 0x74);
            initialized[0] = *reinterpret_cast<Word*>(resource + 0x70);
            Actor_PlayActionByHash(
                *reinterpret_cast<Word*>(actor + 0x30), 0x14, record, 1, 1);
        }
        state[0x28] = 3;
        Word factory = StMenuAppear_Factory_00234A94();
        ActorStateMachine_RequestStateByFactory(
            *reinterpret_cast<Word*>(actor + 0x30), &factory);
    }
    return 0;
}
extern "C" __attribute__((noinline)) int Actor_ResolveActionRecords_0018A2AC(void* actor_state) {
    uint8_t* actor = static_cast<uint8_t*>(actor_state);
    const Word owner = *reinterpret_cast<Word*>(actor + 0x30);
    uint8_t* action_resource = static_cast<uint8_t*>(
        select_action_payload_by_key(
            reinterpret_cast<uint8_t*>(owner),
            ResourceTree_KeyGetter_002A18B8()));
    if (action_resource != 0 &&
        (action_resource[0x64] & 0x40u) != 0)
        return 0;
    action_resource = static_cast<uint8_t*>(
        select_action_payload_by_key(
            reinterpret_cast<uint8_t*>(owner),
            ActorParam_MenuDollParam_Factory_001F53A4()));
    action_resource = *reinterpret_cast<uint8_t**>(action_resource + 0x1C);
    Word record[2];
    const char* action_name = *reinterpret_cast<const char**>(action_resource + 0x128);
    if (*action_name != '\0') {
        Word* initialized = record;
        StateParameterRecord_Init_003B530C(initialized);
        initialized[1] = *reinterpret_cast<Word*>(action_resource + 0x128);
        initialized[0] = *reinterpret_cast<Word*>(action_resource + 0x124);
        Actor_PlayActionByHash(owner, 0x15, record, 1, 1);
    }
    action_name = *reinterpret_cast<const char**>(action_resource + 0xFC);
    if (*action_name != '\0') {
        Word* initialized = record;
        StateParameterRecord_Init_003B530C(initialized);
        initialized[1] = *reinterpret_cast<Word*>(action_resource + 0xFC);
        initialized[0] = *reinterpret_cast<Word*>(action_resource + 0xF8);
        Actor_PlayActionByHash(owner, 0x14, record, 1, 1);
    }
    action_name = *reinterpret_cast<const char**>(action_resource + 0x20);
    if (*action_name != '\0') {
        Word* initialized = record;
        StateParameterRecord_Init_003B530C(initialized);
        initialized[1] = *reinterpret_cast<Word*>(action_resource + 0x20);
        initialized[0] = *reinterpret_cast<Word*>(action_resource + 0x1C);
        Actor_PlayActionByHash(owner, 0x14, record, 1, 1);
    }
    Word factory = StMenuStay_Factory_0022CCBC();
    ActorStateMachine_RequestStateByFactory(owner, &factory);
    return 0;
}
extern "C" __attribute__((noinline)) int Actor_ResolveAndDispatchAction_0018A038(void* actor_state) {
    uint8_t* actor = static_cast<uint8_t*>(actor_state);
    const Word owner = *reinterpret_cast<Word*>(actor + 0x30);
    uint8_t* first_payload = select_action_payload_by_key(
        reinterpret_cast<uint8_t*>(owner),
        ActorParam_MenuDollParam_Factory_001F53A4());
    uint8_t* first_action = *reinterpret_cast<uint8_t**>(first_payload + 0x1C);
    if (**reinterpret_cast<const char**>(first_action + 0x20) == '\0')
        return 0;
    uint8_t* selected = select_action_payload_by_key(
        reinterpret_cast<uint8_t*>(owner),
        Engine_LazyCommandObjectClass_00390B08());
    Word record[2] = {
        *reinterpret_cast<Word*>(first_action + 0x1C),
        *reinterpret_cast<Word*>(first_action + 0x20)};
    const Word selected_action = ActionGroup_SelectActionRecord_004216A0(
        *reinterpret_cast<void**>(selected + 0x18), record);
    const Word linked_action = *reinterpret_cast<Word*>(selected + 0x2C);
    if (linked_action != 0) {
        if (linked_action != selected_action)
            return 0;
    } else {
        uint8_t* nested_tree = *reinterpret_cast<uint8_t**>(selected + 0x20);
        if (nested_tree == selected + 0x1C)
            return 0;
        uint8_t* nested_node = *reinterpret_cast<uint8_t**>(nested_tree);
        if (*reinterpret_cast<uint8_t**>(nested_node + 0x10) ==
            nested_node + 0x0C)
            return 0;
        uint8_t* nested_link = *reinterpret_cast<uint8_t**>(nested_node + 0x14);
        uint8_t* nested_payload = *reinterpret_cast<uint8_t**>(nested_link);
        if (nested_payload == 0 ||
            *reinterpret_cast<Word*>(nested_payload + 0x30) != selected_action)
            return 0;
    }
    uint8_t* candidate = static_cast<uint8_t*>(
        OrderedTree_LowerBoundBySignedKey_00390A98(selected, 0x14));
    void* candidate_sentinel = candidate + 0x1C;
    uint8_t* candidate_node = *reinterpret_cast<uint8_t**>(candidate + 0x20);
    if (candidate_node == candidate_sentinel)
        return 0;
    uint8_t* candidate_payload_node = *reinterpret_cast<uint8_t**>(candidate_node);
    if (*reinterpret_cast<uint8_t**>(candidate_payload_node + 0x10) ==
        candidate_payload_node + 0x0C)
        return 0;
    uint8_t* candidate_link = *reinterpret_cast<uint8_t**>(candidate_payload_node + 0x14);
    uint8_t* candidate_payload = *reinterpret_cast<uint8_t**>(candidate_link);
    if (candidate_payload == 0 || candidate_payload[0x24] != 0)
        return 0;
    Word dispatch_record[2];
    Word* initialized = dispatch_record;
    StateParameterRecord_Init_003B530C(initialized);
    initialized[1] = *reinterpret_cast<Word*>(first_action + 0x20);
    initialized[0] = *reinterpret_cast<Word*>(first_action + 0x1C);
    Actor_PlayActionByHash(owner, 0x14, dispatch_record, 1, 1);
    return 0;
}
extern "C" __attribute__((noinline)) int Actor_ResolveThreeActionRecords_0017F898(void* actor_state) {
    uint8_t* actor = static_cast<uint8_t*>(actor_state);
    const Word owner = *reinterpret_cast<Word*>(actor + 0x30);
    uint8_t* selected_payload = select_action_payload_by_key(
        reinterpret_cast<uint8_t*>(owner),
        Engine_LazySoundResourceDescriptor_001C47C4());
    uint8_t* resource = selected_payload != 0
                          ? *reinterpret_cast<uint8_t**>(
                                selected_payload + 0x1c)
                          : 0;
    Word record[2];
    const char* action_name = *reinterpret_cast<const char**>(resource + 0xA0);
    if (*action_name != '\0') {
        Word* initialized = record;
        StateParameterRecord_Init_003B530C(initialized);
        initialized[1] = *reinterpret_cast<Word*>(resource + 0xA0);
        initialized[0] = *reinterpret_cast<Word*>(resource + 0x9C);
        Actor_PlayActionByHash(owner, 0x15, record, 1, 1);
    }
    action_name = *reinterpret_cast<const char**>(resource + 0x74);
    if (*action_name != '\0') {
        Word* initialized = record;
        StateParameterRecord_Init_003B530C(initialized);
        initialized[1] = *reinterpret_cast<Word*>(resource + 0x74);
        initialized[0] = *reinterpret_cast<Word*>(resource + 0x70);
        Actor_PlayActionByHash(owner, 0x14, record, 1, 1);
    }
    action_name = *reinterpret_cast<const char**>(resource + 0x1C);
    if (*action_name != '\0') {
        Word* initialized = record;
        StateParameterRecord_Init_003B530C(initialized);
        initialized[1] = *reinterpret_cast<Word*>(resource + 0x1C);
        initialized[0] = *reinterpret_cast<Word*>(resource + 0x18);
        Actor_PlayActionByHash(owner, 0x14, record, 1, 1);
    }
    Word factory = StMenuBase_Factory_0022CC34();
    ActorStateMachine_RequestStateByFactory(owner, &factory);
    return 0;
}
extern "C" __attribute__((noinline)) int Actor_EnableFontResourceVisibility_00184164(
    void* actor_state) {
    uint8_t* actor = static_cast<uint8_t*>(actor_state);
    (*reinterpret_cast<uint8_t**>(actor + 0x48))[0x28] = 0xff;
    const Word owner = *reinterpret_cast<Word*>(actor + 0x30);
    uint8_t* selected = select_action_payload_by_key(
        reinterpret_cast<uint8_t*>(owner),
        ResourceTree_KeyGetter_002A18B8());
    selected[0x64] |= 0x40;
    Actor_UpdateFontResourceVisibility_001961A4(actor + 0x38, owner);
    return 0;
}
extern "C" __attribute__((noinline)) int Actor_ResetActionRecords_00184224(void* actor_state) {
    uint8_t* actor = static_cast<uint8_t*>(actor_state);
    uint8_t* state = *reinterpret_cast<uint8_t**>(actor + 0x48);
    if (state[0x20] == 0)
        return 0;
    uint8_t* resource = *reinterpret_cast<uint8_t**>(actor + 0x4C);
    const Word owner = *reinterpret_cast<Word*>(actor + 0x30);
    Word record[2];
    const char* action_name = *reinterpret_cast<const char**>(resource + 0xCC);
    if (*action_name != '\0') {
        *reinterpret_cast<Word*>(
            *reinterpret_cast<uint8_t**>(actor + 0x50) + 0x1C) =
            *reinterpret_cast<Word*>(state + 0x24);
        Word* initialized = record;
        StateParameterRecord_Init_003B530C(initialized);
        initialized[1] = *reinterpret_cast<Word*>(resource + 0xCC);
        initialized[0] = *reinterpret_cast<Word*>(resource + 0xC8);
        Actor_PlayActionByHash(owner, 0x14, record, 1, 1);
    }
    action_name = *reinterpret_cast<const char**>(resource + 0x1C);
    if (*action_name != '\0') {
        Word* initialized = record;
        StateParameterRecord_Init_003B530C(initialized);
        initialized[1] = *reinterpret_cast<Word*>(resource + 0x1C);
        initialized[0] = *reinterpret_cast<Word*>(resource + 0x18);
        Actor_PlayActionByHash(owner, 0x14, record, 1, 1);
    }
    state[0x28] = 0;
    Word factory = StMenuAppear_Factory_00234A94();
    ActorStateMachine_RequestStateByFactory(owner, &factory);
    uint8_t* selected = select_action_payload_by_key(
        reinterpret_cast<uint8_t*>(owner),
        ResourceTree_KeyGetter_002A18B8());
    selected[0x64] &= static_cast<uint8_t>(~0x40u);
    Actor_UpdateFontResourceVisibility_001961A4(actor + 0x38, owner);
    return 0;
}

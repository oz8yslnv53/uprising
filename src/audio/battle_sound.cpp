#include <stdint.h>
extern "C" uint32_t* Memory_FillByte_0044C190(
    uint32_t* destination, uint32_t size, uint8_t value);
extern "C" __attribute__((noinline)) int* StateSound_BuildRuntimeRecords_001CFD70(int* state) {
    uint8_t* state_bytes = reinterpret_cast<uint8_t*>(state);
    Memory_FillByte_0044C190(
        reinterpret_cast<uint32_t*>(state_bytes + 0x20), 0x10, 0xff);
    uint8_t* runtime = *reinterpret_cast<uint8_t**>(state_bytes);
    for (int index = 0; index != 4; ++index) {
        uint8_t* record = runtime + index * 0x150 + 0x1F30;
        const int type = *reinterpret_cast<const int*>(record);
        bool eligible = type == 1 || type == 2;
        if (!eligible) {
            const float product =
                *reinterpret_cast<const float*>(record + 0x10) *
                *reinterpret_cast<const float*>(record + 0x14);
            eligible = product <= 0.0f &&
                       *reinterpret_cast<const float*>(record + 0x18) > 0.0f;
        }
        if (eligible && *reinterpret_cast<const uint32_t*>(record + 0x140) == 0 &&
            record[0x138] == 0) {
            const int id = *reinterpret_cast<const int*>(record + 0x04);
            if (id != -1)
                *reinterpret_cast<int*>(state_bytes + 0x20 + index * 4) = id - 1;
        }
    }
    return reinterpret_cast<int*>(state_bytes + 0x20);
}
extern "C" __attribute__((noinline)) void StateParameter_Reset_001CF704(void* state) {
    uint8_t* bytes = static_cast<uint8_t*>(state);
    const uint8_t* const first_descriptor =
        *reinterpret_cast<const uint8_t* const*>(bytes + 0x44);
    const float first_limit = static_cast<float>(
        *reinterpret_cast<const int16_t*>(first_descriptor + 0x08));
    if (*reinterpret_cast<float*>(bytes + 0x1C) > 0.0f) {
        *reinterpret_cast<float*>(bytes + 0x14) -=
            *reinterpret_cast<float*>(bytes + 0x1C);
        ++*reinterpret_cast<int32_t*>(bytes + 0x24);
    }
    if (*reinterpret_cast<float*>(bytes + 0x14) < first_limit) {
        *reinterpret_cast<float*>(bytes + 0x14) = first_limit;
        *reinterpret_cast<int32_t*>(bytes + 0x24) = 0;
    }
    const uint8_t* const second_descriptor =
        *reinterpret_cast<const uint8_t* const*>(bytes + 0x48);
    const float second_limit = static_cast<float>(
        *reinterpret_cast<const int16_t*>(second_descriptor + 0x08));
    if (*reinterpret_cast<float*>(bytes + 0x20) > 0.0f) {
        *reinterpret_cast<float*>(bytes + 0x18) -=
            *reinterpret_cast<float*>(bytes + 0x20);
        ++*reinterpret_cast<int32_t*>(bytes + 0x28);
    }
    if (*reinterpret_cast<float*>(bytes + 0x18) < second_limit) {
        *reinterpret_cast<float*>(bytes + 0x18) = second_limit;
        *reinterpret_cast<int32_t*>(bytes + 0x28) = 0;
    }
}
__attribute__((noinline)) int BattleState_GetSoundHandle_001CFD4C(const void* state, int index) {
    const uint8_t* const runtime = *reinterpret_cast<const uint8_t* const*>(state);
    return *reinterpret_cast<const int*>(runtime + index * 0x150 + 0x1f34) - 1;
}
extern "C" int EffectResource_AllSlotsEmpty_001ECA7C(const void* table);
extern "C" int EffectResource_QueryState_0025E884(uint32_t context,
                                                    int mode,
                                                    uint32_t id);
extern "C" int EffectResource_QueryReady_0025E7FC(uint32_t context,
                                                    int mode,
                                                    uint32_t id);
extern "C" int EffectResource_QueryLoaded_0025EBCC(uint32_t context,
                                                     int mode,
                                                     uint32_t id);
extern "C" int EffectResource_ReleaseSlot_001D6A04(void* object, uint32_t slot);
__attribute__((noinline)) int BattleObject_UpdateSoundEffectState_001D762C(void* object) {
    uint8_t* bytes = static_cast<uint8_t*>(object);
    const uint32_t kStateBase = 0x59c;
    const uint32_t kStateAfterRelease = 0x58d;
    const uint32_t kStateAfterReady = 0x5a3;
    const uint32_t kStateAfterLoaded = 0x5a8;
    const uint32_t kStateAfterStart = 0x5af;
    const uint32_t state = *reinterpret_cast<const uint32_t*>(bytes + 0x3f8);
    const uint8_t* resource = *reinterpret_cast<uint8_t**>(bytes + 0x474);
    const uint32_t context = *reinterpret_cast<const uint32_t*>(resource + 0x20);
    if (state == kStateBase) {
        if (!EffectResource_QueryState_0025E884(context, 1,
                                                *reinterpret_cast<uint32_t*>(bytes + 0x404))) {
            *reinterpret_cast<uint32_t*>(bytes + 0x3f8) = kStateBase;
            return 0;
        }
    } else if (state < kStateBase) {
        if (state == 0) {
            bytes[0x3f4] = 1;
            *reinterpret_cast<uint32_t*>(bytes + 0x3f8) = kStateAfterRelease;
        } else if (state != kStateAfterRelease) {
            return 0;
        }
        if (*reinterpret_cast<int32_t*>(bytes + 0x404) != -1) {
            for (int count = 0; count != 4; ++count) {
                const uint32_t selected =
                    *reinterpret_cast<const uint32_t*>(bytes + 0x404);
                uint32_t slot = 0xffffffffu;
                if (selected == *reinterpret_cast<const uint32_t*>(bytes + 0x1a4)) {
                    slot = 0;
                } else if (selected == *reinterpret_cast<const uint32_t*>(bytes + 0x1b8)) {
                    slot = 1;
                } else if (selected == *reinterpret_cast<const uint32_t*>(bytes + 0x1cc)) {
                    slot = 2;
                } else if (selected == *reinterpret_cast<const uint32_t*>(bytes + 0x1e0)) {
                    slot = 3;
                }
                EffectResource_ReleaseSlot_001D6A04(object, slot);
            }
            if (!EffectResource_QueryState_0025E884(
                    context, 1, *reinterpret_cast<uint32_t*>(bytes + 0x404))) {
                *reinterpret_cast<uint32_t*>(bytes + 0x3f8) = kStateBase;
                return 0;
            }
        }
    } else if (state - kStateBase != 7 && state - kStateBase != 0xc) {
        return 0;
    } else if (state - kStateBase == 7) {
        if (!EffectResource_QueryReady_0025E7FC(context, 1,
                                                *reinterpret_cast<uint32_t*>(bytes + 0x400))) {
            *reinterpret_cast<uint32_t*>(bytes + 0x3f8) = kStateAfterReady;
            return 0;
        }
    }
    const uint32_t selected =
        *reinterpret_cast<const uint32_t*>(bytes + 0x400);
    const int loaded = EffectResource_QueryLoaded_0025EBCC(context, 1, selected);
    uint32_t next_state = kStateAfterLoaded;
    uint32_t result = 0;
    if (loaded != 0) {
        if (selected - 0x177u < 0x1b) {
            *reinterpret_cast<uint32_t*>(bytes + 0x1a0) = selected;
        } else if (*reinterpret_cast<int32_t*>(bytes + 0x194) == -1) {
            *reinterpret_cast<uint32_t*>(bytes + 0x194) = selected;
        } else if (*reinterpret_cast<int32_t*>(bytes + 0x198) == -1) {
            *reinterpret_cast<uint32_t*>(bytes + 0x198) = selected;
        } else if (*reinterpret_cast<int32_t*>(bytes + 0x19c) == -1) {
            *reinterpret_cast<uint32_t*>(bytes + 0x19c) = selected;
        }
        next_state = kStateAfterStart;
        result = 1;
        bytes[0x3f4] = 2;
    }
    *reinterpret_cast<uint32_t*>(bytes + 0x3f8) = next_state;
    return static_cast<int>(result);
}
extern "C" void* GetEngineSingleton_003FD6E0();
extern "C" void* GetEngineSingleton_003B6CF0();
extern "C" void SoundResource_ClampDuration_002B4CEC(void* resource,
                                                        uint32_t value);
extern "C" uint32_t EffectEvent_Dispatch(void* dispatcher,
                                                uint32_t event_id,
                                                uint32_t effect_type,
                                                void* record,
                                                uint32_t flags);
extern "C" void* AudioState_GetContainer_002A6190(uint32_t handle);
extern "C" bool StateContainer_IsUninitialized_001B4C28(const void* state);
void BattleState_SetSelectionFlag_001CF688(void* state, int value);
void BattleState_SetSoundRuntimeByte_001CFE34(void* state, int index,
                                               uint8_t value);
extern "C" void* Engine_LazyResourceSingleton_001D92C4();
extern "C" uint32_t Engine_GlobalTimeGate_001B5128();
extern "C" void StateSound_ApplyParameter_001CFA2C(
    void* state, int index, void* parameter, int active);
extern "C" uint32_t Resource_GetActiveValue_00203148(void* object);
extern "C" void BattleState_UpdateResourceTable_001EB4C0(void* root);
extern "C" uint32_t ResourceTransition_Apply_001EBC30(
    void* object, int32_t key, uint32_t value0, uint32_t value1);
extern "C" void* Engine_LazyResourceSingleton_001C47C4();
extern "C" int ParameterString_Format_002B3F78(void* output,
                                                uint32_t size,
                                                const void* format, ...);
extern "C" void ParameterRecord_SetPair_002F25B8(void* destination,
                                                    const void* format,
                                                    uint32_t value0,
                                                    uint32_t value1);
extern "C" uint32_t AudioState_GetCurrentParameter_00176234();
extern "C" void* OrderedTree_LookupUncached_00326C6C(
    uint32_t handle, const void* key);
extern "C" void* AudioState_FindEntry_00274FE8(void* container,
                                                 const char* name);
void* AudioState_GetRuntime_001ED404(uint32_t handle);
extern "C" bool StateContainer_Reset_001A6298(void* state, int mode);
extern "C" void StateMachine_SetState_001D680C(void* object, int slot, int state);
extern "C" void StateObject_Copy_00352994(void* destination, const void* source);
extern "C" void BattleObject_SetMode_001D7AC0(void* object, int mode);
extern "C" void BattleObject_BuildResourceAndSoundNames_001D6F88(
    void* object);
extern "C" void BattleObject_SetTimer_001D77E4(void* object, int slot, int frames);
extern "C" void BattleObject_ResetAction_0020AB6C(void* object,
                                                   uint32_t handle,
                                                   int arg2,
                                                   int arg3,
                                                   int flags);
void BattleObject_SetTransition_001D6954(void* object, int slot, int value,
                                          float transition_value);
extern "C" void* BattleAudio_GetMenuBattleDollKey_001D60F4();
extern "C" uint32_t OnceGuard_TestAndSet_003B4FE4(uint32_t* guard);
extern "C" void* OrderedTree_CreateSentinel_00449C68();
extern "C" int ParameterString_Equals_00425E6C(const void* left,
                                                 const void* right);
extern "C" void OrderedTree_UnlinkNode_003D40E0(
    uintptr_t node, uintptr_t replacement);
extern "C" void OrderedTree_LinkInsertedNode_0043AFF8(
    uintptr_t frame, int direction, uintptr_t node,
    uintptr_t root);
extern "C" void OrderedTree_CopySearchFrame_00445CF4(
    void* destination, const void* source);
extern "C" void Engine_BulkCopy_00425DF8(void* destination,
                                           const void* source,
                                           uint32_t size);
float BattleState_SetSoundSelectionFlag_001CF9F8(
    void* state, int index, uint8_t value);
int32_t BattleObject_SelectAndClearSoundHandle_001D6BDC(
    void* object, int mode);
extern "C" void* EffectResource_CreateOrLookup_001EBFAC(
    uint32_t context,
    uint32_t id,
    uint32_t slot,
    uint32_t mode,
    uint32_t variant);
extern "C" void* Resource_OwnerAttach_00489A54(
    void* registry, void* resource, uint32_t slot);
extern "C" void* EffectResource_GetKey_002A18B8();
extern "C" void* OrderedTree_LowerBoundByPointer_004C5D3C(
    void* tree, void* key);
extern "C" int BattleStateTable_GetSignedHalfword08_00205E08(
    void* state, int index);
extern "C" int BattleStateTable_GetSignedByte0_00205DF0(void* state,
                                                          int index);
extern "C" void ResourceParameter_RegisterPair_002EC6FC(
    void* resource, uint32_t handle, void* name, void* source,
    void* target, int mode);
extern "C" void ResourceParameter_ApplyVectorUpdate_0020A93C(
    void* object, uint32_t handle, void* name, void* vector);
extern "C" void EffectResource_Activate_002A17A0(
    void* owner_list, void* resource, int active);
extern "C" void* EffectResourceRegistry_Create_0047613C();
extern "C" void* EffectOwnerRegistry_Create_0049BF80();
extern "C" void* ResourceTree_ResolveCurrentEntry_002A6268(
    uint32_t handle);
extern "C" void ResourceTree_Activate_002A17A0(
    void* owner_list, uint32_t handle, int active);
extern "C" void Actor_PlayActionByHash_0036FCA8(
    uint32_t handle, int channel, const uint32_t* key,
    int arg3, int arg4);
__attribute__((noinline)) uint32_t BattleObject_SelectSoundCandidates_001A9B60(
    void* object, const uint32_t* input_handles) {
    uint8_t* bytes = static_cast<uint8_t*>(object);
    const uint32_t kInvalid = 0xffffffffu;
    const int32_t kHandleBitBase = static_cast<int32_t>(0xfffefe8bu);
    const float kWorstScore = 100000.0f;
    uint32_t retained_handle = kInvalid;
    uint32_t handles[4];
    struct HandlePair {
        uint32_t low;
        uint32_t high;
    };
    *reinterpret_cast<HandlePair*>(&handles[0]) =
        *reinterpret_cast<const HandlePair*>(&input_handles[0]);
    *reinterpret_cast<HandlePair*>(&handles[2]) =
        *reinterpret_cast<const HandlePair*>(&input_handles[2]);
    *reinterpret_cast<uint32_t*>(bytes + 0x464) = kInvalid;
    float active_score = kWorstScore;
    float retained_score = active_score;
    for (int index = 0; index != 4; ++index) {
        const uint32_t candidate = handles[index];
        if (candidate == kInvalid) {
            continue;
        }
        uint8_t* slot = bytes + 0x1a4 + index * 0x14;
        if (*reinterpret_cast<uint32_t*>(slot) == candidate) {
            void** engine_slot = reinterpret_cast<void**>(0x00d6365cu);
            void* engine_object = *engine_slot;
            if (engine_object == 0) {
                engine_object = GetEngineSingleton_003B6CF0();
                *engine_slot = engine_object;
            }
            uint8_t* engine = static_cast<uint8_t*>(engine_object);
            const uint32_t bit_handle = handles[index];
            const uint8_t* mask_byte =
                engine + 0x6278 + static_cast<int32_t>(bit_handle) / 8 -
                kHandleBitBase;
            const bool active = ((*mask_byte >> (bit_handle & 7u)) & 1u) != 0;
            if (active) {
                const float chosen =
                    BattleState_SetSoundSelectionFlag_001CF9F8(bytes + 0xcc, index, 1);
                if (active_score > chosen) {
                    active_score = chosen;
                    const int selected =
                        BattleState_GetSoundHandle_001CFD4C(bytes + 0xcc, index);
                    uint32_t* selection =
                        reinterpret_cast<uint32_t*>(bytes + 0x460);
                    selection[0] = static_cast<uint32_t>(selected);
                    selection[1] = static_cast<uint32_t>(index);
                }
            } else {
                const float chosen =
                    BattleState_SetSoundSelectionFlag_001CF9F8(bytes + 0xcc, index, 0);
                if (retained_score > chosen) {
                    retained_score = chosen;
                    retained_handle = handles[index];
                }
            }
        } else if (EffectResource_ReleaseSlot_001D6A04(
                       object, static_cast<uint32_t>(index)) == 0) {
            continue;
        }
        handles[index] = kInvalid;
    }
    if (bytes[0x3fe] != 0) {
        if (BattleObject_UpdateSoundEffectState_001D762C(object) != 0) {
            bytes[0x3f4] = 0;
            *reinterpret_cast<uint32_t*>(bytes + 0x3f8) = 0;
            bytes[0x3fe] = 0;
            *reinterpret_cast<uint32_t*>(bytes + 0x400) = kInvalid;
            *reinterpret_cast<uint32_t*>(bytes + 0x404) = kInvalid;
        }
        return retained_handle;
    }
    void** resource_registry = reinterpret_cast<void**>(0x00D63900);
    uint32_t fallback_index = kInvalid;
    float fallback_score = kWorstScore;
    *reinterpret_cast<uint32_t*>(bytes + 0x400) = kInvalid;
    for (int index = 0; index != 4; ++index) {
        const uint32_t candidate = handles[index];
        if (candidate == kInvalid) {
            continue;
        }
        const int32_t signed_candidate = static_cast<int32_t>(candidate);
        if (signed_candidate >= 0 &&
            (candidate == *reinterpret_cast<uint32_t*>(bytes + 0x194) ||
             candidate == *reinterpret_cast<uint32_t*>(bytes + 0x198) ||
             candidate == *reinterpret_cast<uint32_t*>(bytes + 0x19c) ||
             candidate == *reinterpret_cast<uint32_t*>(bytes + 0x1a0))) {
            void* registry = *resource_registry;
            if (registry == 0) {
                registry = EffectResourceRegistry_Create_0047613C();
                *resource_registry = registry;
            }
            if (!EffectResource_AllSlotsEmpty_001ECA7C(registry)) {
                continue;
            }
            const uint32_t handle = handles[index];
            void* context = *reinterpret_cast<void**>(bytes + 0x474);
            context = *reinterpret_cast<void**>(static_cast<uint8_t*>(context) + 0x20);
            const bool special = handle - 0x177u < 0x1b;
            void* resource = EffectResource_CreateOrLookup_001EBFAC(
                reinterpret_cast<uint32_t>(context), handle,
                static_cast<uint8_t>(index), special ? 1u : 0u,
                special ? 0u : 1u);
            uint8_t* slot = bytes + 0x1a4 + index * 0x14;
            *reinterpret_cast<void**>(slot + 0x04) = resource;
            if (*reinterpret_cast<void**>(slot + 0x04) == 0) {
                continue;
            }
            *reinterpret_cast<uint32_t*>(slot) = handle;
            void** owner_registry = reinterpret_cast<void**>(0x00D63618);
            if (*owner_registry == 0) {
                *owner_registry = EffectOwnerRegistry_Create_0049BF80();
            }
            Resource_OwnerAttach_00489A54(
                *owner_registry, *reinterpret_cast<void**>(slot + 0x04),
                static_cast<uint8_t>(index));
            uint8_t* record =
                *reinterpret_cast<uint8_t**>(slot + 0x04);
            void* key = EffectResource_GetKey_002A18B8();
            void* node = OrderedTree_LowerBoundByPointer_004C5D3C(
                record + 0x1a4, key);
            void* node_value = node == 0 ? 0 : *reinterpret_cast<void**>(node);
            void* selected_node =
                node_value == *reinterpret_cast<void**>(record + 0x1a8)
                    ? 0
                    : node_value;
            void* owner_list = *reinterpret_cast<void**>(
                static_cast<uint8_t*>(selected_node) + 0x20);
            EffectResource_Activate_002A17A0(
                static_cast<uint8_t*>(owner_list) + 8,
                *reinterpret_cast<void**>(slot + 0x04), 1);
            continue;
        }
        {
            const float chosen =
                BattleState_SetSoundSelectionFlag_001CF9F8(bytes + 0xcc, index, 0);
            if (fallback_score > chosen) {
                fallback_score = chosen;
                *reinterpret_cast<uint32_t*>(bytes + 0x400) = handles[index];
                fallback_index = static_cast<uint32_t>(index);
            }
        }
    }
    const int32_t selected =
        *reinterpret_cast<int32_t*>(bytes + 0x400);
    if (selected >= 0) {
        bytes[0x3fe] = 1;
        *reinterpret_cast<uint32_t*>(bytes + 0x404) =
            static_cast<uint32_t>(BattleObject_SelectAndClearSoundHandle_001D6BDC(
                object, static_cast<int>(fallback_index)));
    }
    return retained_handle;
}
struct SoundEventRecord {
    uint32_t word0;
    uint32_t word1;
    uint32_t word2;
    float         scalar0;
    uint32_t word4;
    uint32_t word5;
    float         scalar1;
    float         scalar2;
};
typedef char kiu_sa_battle_sound_1[(sizeof(SoundEventRecord) == 0x20) ? 1 : -1] __attribute__((unused));
void BattleUi_PlayConfiguredSound_001D7468(void* object, int category, int level) {
    uint32_t* config = *reinterpret_cast<uint32_t**>(
        reinterpret_cast<uint8_t*>(object) + 0x488);
    uint32_t effect_type;
    switch (category) {
    case 0:  effect_type = config[0x674 / 4 + level]; break;
    case 1:  effect_type = config[0x680 / 4 + level]; break;
    case 2:  effect_type = config[0x68c / 4 + level]; break;
    case 3:  effect_type = config[0x698 / 4 + level]; break;
    case 4:  effect_type = config[0x6a4 / 4 + level]; break;
    case 5:  effect_type = config[0x6b0 / 4 + level]; break;
    case 6:  effect_type = config[0x6bc / 4 + level]; break;
    case 7:  effect_type = config[0x6c8 / 4 + level]; break;
    case 8:  effect_type = config[0x6d4 / 4 + level]; break;
    case 9:  effect_type = config[0x6e0 / 4 + level]; break;
    case 10: effect_type = config[0x6ec / 4]; break;
    case 11: effect_type = config[0x6f4 / 4]; break;
    case 12: effect_type = config[0x6f8 / 4]; break;
    case 13: effect_type = config[0x6fc / 4]; break;
    case 14: effect_type = config[0x704 / 4]; break;
    case 15: effect_type = config[0x708 / 4]; break;
    case 16: effect_type = config[0x70c / 4]; break;
    case 17: effect_type = config[0x700 / 4]; break;
    case 18: effect_type = config[0x6f0 / 4]; break;
    default: return;
    }
    SoundEventRecord record = {0, 0, 0, 1.0f, 0, 0, 0.0f, 1.0f};
    void** dispatcher_slot = reinterpret_cast<void**>(0x00D63854);
    void* dispatcher = *dispatcher_slot;
    if (dispatcher == 0) {
        dispatcher = GetEngineSingleton_003FD6E0();
        *dispatcher_slot = dispatcher;
    }
    uint8_t* active_id = reinterpret_cast<uint8_t*>(0x00D5EE4A);
    uint8_t* next_id = reinterpret_cast<uint8_t*>(0x00D4E2F8);
    if (*active_id == 0) {
        *active_id = static_cast<uint8_t>(*next_id + 1);
        *next_id = *active_id;
    }
    EffectEvent_Dispatch(dispatcher,
                         (static_cast<uint32_t>(*active_id) << 16) | 2,
                         effect_type, &record, 0);
}
__attribute__((noinline)) void BattleObject_UpdateSoundProgress_001AA040(void* object,
                                                uint32_t duration,
                                                uint32_t progress,
                                                uint32_t mode) {
    uint8_t* bytes = static_cast<uint8_t*>(object);
    if (progress > 0x0098967fu) {
        progress = 0x0098967fu;
    }
    uint8_t* container = static_cast<uint8_t*>(
        AudioState_GetContainer_002A6190(
            *reinterpret_cast<uint32_t*>(bytes + 0x234)));
    ParameterRecord_SetPair_002F25B8(
        bytes + 0x390, reinterpret_cast<const void*>(0x00CA15A4), progress,
        mode);
    uint8_t* parameter_root = *reinterpret_cast<uint8_t**>(
        *reinterpret_cast<uint8_t**>(container + 0x20) + 0x04);
    *reinterpret_cast<uint8_t**>(
        *reinterpret_cast<uint8_t**>(parameter_root) + 0x10) =
        bytes + 0x390;
    ParameterRecord_SetPair_002F25B8(
        bytes + 0x3A0, reinterpret_cast<const void*>(0x00CA159C), duration,
        mode);
    uint8_t* second_chain = *reinterpret_cast<uint8_t**>(parameter_root + 4);
    second_chain = *reinterpret_cast<uint8_t**>(second_chain + 4);
    second_chain = *reinterpret_cast<uint8_t**>(second_chain + 4);
    *reinterpret_cast<uint8_t**>(
        *reinterpret_cast<uint8_t**>(second_chain) + 0x10) =
        bytes + 0x3A0;
    uint8_t* tail = *reinterpret_cast<uint8_t**>(second_chain + 4);
    uint8_t* tail_value = *reinterpret_cast<uint8_t**>(tail);
    if (mode == 0) {
        *reinterpret_cast<uint32_t*>(tail_value + 0x0C) = 0;
    } else {
        const uint32_t key = AudioState_GetCurrentParameter_00176234();
        void* record = OrderedTree_LookupUncached_00326C6C(
            *reinterpret_cast<uint32_t*>(bytes + 0x234), &key);
        uint8_t* selected = *reinterpret_cast<uint8_t**>(
            static_cast<uint8_t*>(record) + 0x1C);
        *reinterpret_cast<uint32_t*>(tail_value + 0x0C) =
            *reinterpret_cast<uint32_t*>(selected + 0x2F0);
    }
    uint8_t* final_value = *reinterpret_cast<uint8_t**>(tail + 4);
    *reinterpret_cast<uint32_t*>(final_value + 0x0C) =
        bytes[0x3B0] == 0 ? 0u : reinterpret_cast<uintptr_t>(bytes + 0x3B0);
}
__attribute__((noinline)) void BattleUi_UpdateSoundMode_001A9A0C(void* object, int mode) {
    uint8_t* bytes = static_cast<uint8_t*>(object);
    uint8_t* config = *reinterpret_cast<uint8_t**>(bytes + 0x488);
    if (mode == 0) {
        uint8_t* pending = reinterpret_cast<uint8_t*>(bytes + 0x3fd);
        if (*pending == 0) {
            return;
        }
        *pending = 0;
    }
    void* container = AudioState_GetContainer_002A6190(
        *reinterpret_cast<uint32_t*>(bytes + 0x210));
    void** pair = *reinterpret_cast<void***>(
        static_cast<uint8_t*>(container) + 0x20);
    if (mode == 0) {
        *reinterpret_cast<uint32_t*>(
            static_cast<uint8_t*>(pair[0]) + 0x0c) = 0;
        *reinterpret_cast<uint32_t*>(
            static_cast<uint8_t*>(pair[1]) + 0x0c) =
            *reinterpret_cast<uint32_t*>(config + 0x308);
    } else {
        *reinterpret_cast<uint32_t*>(
            static_cast<uint8_t*>(pair[0]) + 0x0c) =
            *reinterpret_cast<uint32_t*>(config + 0x308 + mode * 0x2c);
        *reinterpret_cast<uint32_t*>(
            static_cast<uint8_t*>(pair[1]) + 0x0c) = 0;
    }
    for (int index = 0; index != 2; ++index) {
        const char* name = reinterpret_cast<const char*>(
            index == 0 ? 0x00CA15ACu : 0x00CA15B4u);
        void* entry = AudioState_FindEntry_00274FE8(container, name);
        if (entry != 0) {
            uint32_t* flags = reinterpret_cast<uint32_t*>(
                static_cast<uint8_t*>(entry) + 0xc0);
            if (mode == 0) {
                *flags |= 0x12;
            } else {
                *flags &= ~uint32_t(0x12);
            }
        }
    }
    if (mode != 0) {
        BattleUi_PlayConfiguredSound_001D7468(object, 17, 0);
    }
    uint8_t* runtime = static_cast<uint8_t*>(
        AudioState_GetRuntime_001ED404(
            *reinterpret_cast<uint32_t*>(bytes + 0x210)));
    runtime[0x20] = 1;
    *reinterpret_cast<uint16_t*>(runtime + 0x22) =
        static_cast<uint16_t>(*reinterpret_cast<uint32_t*>(config + 0x8bc));
}
__attribute__((noinline)) void BattleState_ClearPendingTransition_001CFD2C(void* state) {
    uint8_t* bytes = static_cast<uint8_t*>(state);
    if (bytes[0x39] == 0) {
        return;
    }
    bytes[0x39] = 0;
    uint8_t* object = *reinterpret_cast<uint8_t**>(bytes);
    *reinterpret_cast<uint32_t*>(object + 0x24bc) = 0;
    object[0x24b8] = 0;
}
__attribute__((noinline)) void BattleState_SetSelectionFlag_001CF688(void* state, int value) {
    uint8_t* bytes = static_cast<uint8_t*>(state);
    uint8_t* table = *reinterpret_cast<uint8_t**>(bytes + 0x38);
    table[0x6d] = static_cast<uint8_t>(value);
}
__attribute__((noinline)) void BattleState_ResetSelection_001CF694(void* state) {
    uint8_t* bytes = static_cast<uint8_t*>(state);
    bytes[0x04] = 0;
    bytes[0x06] = 0;
    bytes[0x05] = 0;
    bytes[0x07] = 0;
    bytes[0x08] = 0;
    bytes[0x09] = 0;
    *reinterpret_cast<uint32_t*>(bytes + 0x0c) = 0xffffffff;
    bytes[0x10] = 0;
    bytes[0x11] = 0;
    *reinterpret_cast<uint32_t*>(bytes + 0x2c) = 0x3a09f874;
    uint8_t* table = *reinterpret_cast<uint8_t**>(bytes + 0x38);
    table[0x19] = 0;
}
__attribute__((noinline)) int BattleStateTable_GetSignedByte_001CF6D4(const void* state, int index) {
    if (index >= 2) {
        return 0;
    }
    const uint8_t* bytes = static_cast<const uint8_t*>(state);
    const uint8_t* const entry = *reinterpret_cast<const uint8_t* const*>(
        bytes + 0x3c + index * 4);
    return *reinterpret_cast<const int8_t*>(entry + 0x14);
}
__attribute__((noinline)) int BattleStateTable_ReadActiveIndex_001EA8AC(
    const void* table, int index) {
    const uint8_t* bytes = static_cast<const uint8_t*>(table);
    if ((*reinterpret_cast<const uint32_t*>(bytes + 0x68) & 0x20u) == 0) {
        return -1;
    }
    return *reinterpret_cast<const int32_t*>(bytes + 0x1c + index * 4);
}
__attribute__((noinline)) int BattleStateTable_GetActiveIndex_001CF6EC(const void* state, int index) {
    if (index >= 2) {
        return -1;
    }
    const uint8_t* bytes = static_cast<const uint8_t*>(state);
    return BattleStateTable_ReadActiveIndex_001EA8AC(
        *reinterpret_cast<const uint8_t* const*>(bytes + 0x38), index);
}
__attribute__((noinline)) int BattleStateTable_GetSignedHalfword_001CF800(const void* state, int index) {
    if (index >= 2) {
        return -1;
    }
    const uint8_t* bytes = static_cast<const uint8_t*>(state);
    const uint8_t* const entry = *reinterpret_cast<const uint8_t* const*>(
        bytes + 0x3c + index * 4);
    return *reinterpret_cast<const int16_t*>(entry + 0x0a);
}
__attribute__((noinline)) uint32_t BattleState_GetNestedWord10_001A6504(const void* state) {
    const uint8_t* bytes = static_cast<const uint8_t*>(state);
    const uint8_t* const nested = *reinterpret_cast<const uint8_t* const*>(bytes + 4);
    return *reinterpret_cast<const uint32_t*>(nested + 0x10);
}
__attribute__((noinline)) bool BattleState_HasFlag40_001A5D74(const void* state) {
    const uint8_t* bytes = static_cast<const uint8_t*>(state);
    const uint8_t* const table = *reinterpret_cast<const uint8_t* const*>(bytes + 0x38);
    return (*reinterpret_cast<const uint32_t*>(table + 0x68) & 0x40u) != 0;
}
__attribute__((noinline)) bool BattleState_HasFlag20_001A5D60(const void* state) {
    const uint8_t* bytes = static_cast<const uint8_t*>(state);
    const uint8_t* const table = *reinterpret_cast<const uint8_t* const*>(bytes + 0x38);
    return (*reinterpret_cast<const uint32_t*>(table + 0x68) & 0x20u) != 0;
}
extern "C" void BattleState_ApplyResourceFlag_001EA644(void* table, int mode);
__attribute__((noinline)) void BattleState_MarkReady_001A5D38(void* state) {
    uint8_t* bytes = static_cast<uint8_t*>(state);
    BattleState_ApplyResourceFlag_001EA644(
        *reinterpret_cast<void**>(bytes + 0x38), 1);
    bytes[5] = 1;
    bytes[4] = 0;
}
extern "C" void* BattleState_GetSingleton_003B6EDC();
extern "C" void BattleState_NotifyResource_003D1B1C(void* resource);
extern "C" void BattleState_ApplyResource_001D5080(void* resource,
                                                     uint32_t mode);
extern "C" void BattleState_NotifyLoaded_003ABB48(void* resource);
extern "C" void BattleState_ResetObject_00221894(void* object, int mode);
extern "C" void* FontTextManager_Get_003532F0();
extern "C" void FontTextManager_ApplyMode_001EC7A0(void* manager, int mode);
extern "C" void Resource_SetEnabled_00203168(void* resource, int enabled);
extern "C" void* Engine_SharedResourceSingleton_00422D20();
__attribute__((noinline)) void BattleState_AdvanceResourcePhase_001A6064(void* state,
                                                 uint32_t* output) {
    uint32_t* words = static_cast<uint32_t*>(state);
    uint8_t* object = reinterpret_cast<uint8_t*>(
        static_cast<uintptr_t>(words[0]));
    uint8_t* resource = reinterpret_cast<uint8_t*>(
        static_cast<uintptr_t>(words[1]));
    void** singleton_slot = reinterpret_cast<void**>(0x00d637bc);
    void* singleton = *singleton_slot;
    const uint32_t kPhaseOffset = 0x18;
    if (words[kPhaseOffset / 4] == 0) {
        return;
    }
    const uint32_t phase = words[kPhaseOffset / 4];
    if (phase == 1) {
        if (*reinterpret_cast<const uint32_t*>(object + 0x2470) == 0x100) {
            if (singleton == 0) {
                singleton = BattleState_GetSingleton_003B6EDC();
                *singleton_slot = singleton;
            }
            *reinterpret_cast<uint8_t*>(static_cast<uint8_t*>(singleton) +
                                             0x4c) = 0;
            words[5] = 3;
            words[6] = 2;
        }
    } else if (phase == 2) {
        const int32_t remaining = static_cast<int32_t>(words[5]) - 1;
        words[5] = static_cast<uint32_t>(remaining);
        if (remaining >= 0) {
            BattleState_NotifyResource_003D1B1C(object + 0x6a34);
            BattleState_ApplyResource_001D5080(resource, 0x300);
            object[0x2476] = 0;
            words[6] = 3;
        }
    } else if (phase == 3) {
        if ((resource[0x24] & 1) != 0) {
            BattleState_NotifyLoaded_003ABB48(object + 0x6a34);
            BattleState_ResetObject_00221894(object, 0);
            object[0x2474] = 0;
            void** font_slot = reinterpret_cast<void**>(0x00d6366c);
            void* font = *font_slot;
            if (font == 0) {
                font = FontTextManager_Get_003532F0();
                *font_slot = font;
            }
            static_cast<uint8_t*>(font)[0x16d] = 1;
            if (font != 0) {
                font = *font_slot;
            } else {
                font = FontTextManager_Get_003532F0();
                *font_slot = font;
            }
            FontTextManager_ApplyMode_001EC7A0(font, 1);
            words[6] = 4;
        }
    } else if (phase == 4 &&
               *reinterpret_cast<const uint32_t*>(object + 0x2470) == 0) {
        if (singleton == 0) {
            singleton = BattleState_GetSingleton_003B6EDC();
            *singleton_slot = singleton;
        }
        *reinterpret_cast<uint8_t*>(static_cast<uint8_t*>(singleton) +
                                         0x4c) = 1;
        void** shared_slot = reinterpret_cast<void**>(0x00d637ec);
        void* shared = *shared_slot;
        if (shared == 0) {
            shared = Engine_SharedResourceSingleton_00422D20();
            *shared_slot = shared;
        }
        Resource_SetEnabled_00203168(
            *reinterpret_cast<void**>(static_cast<uint8_t*>(shared) + 0x48),
            1);
        words[6] = 0;
        *output = 1;
    }
}
__attribute__((noinline)) uint8_t* ResourceTable_GetEntry_001EC938(const uint32_t* table,
                                               int index) {
    if ((table[0x1a] & 0x20u) == 0) {
        return 0;
    }
    return reinterpret_cast<uint8_t*>(
        static_cast<uintptr_t>(table[0]) + table[index + 0x0d] * 0x16u -
        0x16u);
}
__attribute__((noinline)) uint8_t* ResourceTable_GetBaseEntry_001EC914(const uint8_t* table,
                                                   int index) {
    if ((*reinterpret_cast<const uint32_t*>(table + 0x68) & 0x1au) == 0) {
        return 0;
    }
    return const_cast<uint8_t*>(table) + index * 0x16 + 0x3c;
}
extern "C" void ResourceRecord_BuildModePath_002C9140(
    void* state, void* destination, uint32_t value, int mode);
__attribute__((noinline)) uint32_t ResourceTable_AdvanceRecord_001C9220(void* state,
                                                    uint32_t value) {
    uint8_t* bytes = static_cast<uint8_t*>(state);
    int32_t* counter = reinterpret_cast<int32_t*>(bytes + 0xd910);
    const int32_t index = *counter;
    int32_t next = index + 1;
    *counter = next;
    if (next > 7) {
        *counter = 0;
    }
    uint8_t* destination = bytes + index * 0x18 + 0xd914;
    ResourceRecord_BuildModePath_002C9140(state, destination, value, 4);
    return *reinterpret_cast<uint32_t*>(destination);
}
extern "C" void ParameterString_Format_003FDA9C(void* output, int count,
                                                   const void* format,
                                                   uint32_t value);
extern "C" void ParameterString_Assign_0043A31C(void* destination,
                                                  const void* source);
extern "C" void ParameterString_Append_004EE8B4(void* destination,
                                                  const void* source);
extern "C" void ParameterString_AppendLiteral_003721DC(
    void* destination, const void* literal);
__attribute__((noinline)) uint32_t ResourceTable_BuildDollPath_001C918C(void* state,
                                                    uint32_t value) {
    uint8_t* bytes = static_cast<uint8_t*>(state);
    int32_t* counter = reinterpret_cast<int32_t*>(bytes + 0xd9d4);
    const int32_t index = *counter;
    int32_t next = index + 1;
    *counter = next;
    if (next >= 8) {
        *counter = 0;
    }
    uint32_t formatted = 0;
    ParameterString_Format_003FDA9C(&formatted, 3,
                                    reinterpret_cast<const void*>(0x001c9208),
                                    value);
    uint8_t* destination = bytes + index * 0x18 + 0xd9d8;
    *reinterpret_cast<uint8_t*>(destination + 8) = 0;
    ParameterString_Assign_0043A31C(
        destination, reinterpret_cast<const void*>(0x001c9210));
    ParameterString_Append_004EE8B4(destination, &formatted);
    ParameterString_AppendLiteral_003721DC(
        destination, reinterpret_cast<const void*>(0x001c9218));
    return *reinterpret_cast<uint32_t*>(destination);
}
extern "C" uint32_t StateResource_QueryFlags_001EA8C4(
    void* table, void* context, uint32_t key);
extern "C" void* ResourceFactory_Create_004C5938();
extern "C" void ParameterRecord_Build_00463134(void* output,
                                                 uint32_t value0,
                                                 uint32_t value1);
extern "C" void StateParameter_Reset_001CF704(void* state);
__attribute__((noinline)) void BattleState_ConfigureResourceParameters_001A5D88(void* state,
                                                        void* context) {
    uint8_t* bytes = static_cast<uint8_t*>(state);
    void* table = *reinterpret_cast<void**>(bytes + 0x38);
    void** singleton_slot = reinterpret_cast<void**>(0x00d63598);
    void* singleton = *singleton_slot;
    if (singleton == 0) {
        singleton = ResourceFactory_Create_004C5938();
        *singleton_slot = singleton;
    }
    const uint32_t path_value = ResourceTable_BuildDollPath_001C918C(singleton, 0);
    singleton = *singleton_slot;
    if (singleton == 0) {
        singleton = ResourceFactory_Create_004C5938();
        *singleton_slot = singleton;
    }
    const uint32_t record_value = ResourceTable_AdvanceRecord_001C9220(
        singleton, 0x36);
    uint32_t record[3] = {0};
    ParameterRecord_Build_00463134(record, record_value, path_value);
    const uint32_t flags = StateResource_QueryFlags_001EA8C4(
        table, context, record[0]);
    if ((flags & 1u) != 0) {
        uint8_t* entry0 = ResourceTable_GetEntry_001EC938(
            static_cast<const uint32_t*>(table), 0);
        uint8_t* entry1 = ResourceTable_GetEntry_001EC938(
            static_cast<const uint32_t*>(table), 1);
        const int16_t entry0_value =
            *reinterpret_cast<const int16_t*>(entry0 + 8);
        const int16_t entry1_value =
            *reinterpret_cast<const int16_t*>(entry1 + 8);
        bytes[4] = 1;
        bytes[6] = 0;
        *reinterpret_cast<void**>(bytes + 0x3c) =
            ResourceTable_GetEntry_001EC938(
                static_cast<const uint32_t*>(table), 0);
        *reinterpret_cast<void**>(bytes + 0x40) =
            ResourceTable_GetEntry_001EC938(
                static_cast<const uint32_t*>(table), 1);
        *reinterpret_cast<float*>(bytes + 0x14) =
            static_cast<float>(entry0_value);
        *reinterpret_cast<float*>(bytes + 0x18) =
            static_cast<float>(entry1_value);
        bytes[8] = (flags & 0x400u) != 0;
        if (bytes[8] != 0) {
            *reinterpret_cast<float*>(bytes + 0x20) =
                (*reinterpret_cast<float*>(bytes + 0x18) -
                 static_cast<float>(entry1_value)) * 0.1f;
            *reinterpret_cast<uint32_t*>(bytes + 0x24) = 0;
        }
        bytes[9] = (flags & 0x800u) != 0;
        if (bytes[9] != 0) {
            *reinterpret_cast<uint32_t*>(bytes + 0x28) = 0;
            *reinterpret_cast<float*>(bytes + 0x1c) =
                (*reinterpret_cast<float*>(bytes + 0x14) -
                 static_cast<float>(entry0_value)) * 0.1f;
        }
        const int16_t maximum = entry0_value > entry1_value ? entry0_value : entry1_value;
        *reinterpret_cast<float*>(bytes + 0x2c) = 1.0f / static_cast<float>(maximum);
        return;
    }
    if ((flags & 2u) != 0) {
        bytes[6] = 1;
        bytes[5] = 0;
        bytes[4] = 0;
        *reinterpret_cast<void**>(bytes + 0x44) =
            ResourceTable_GetBaseEntry_001EC914(
                static_cast<const uint8_t*>(table), 0);
        *reinterpret_cast<void**>(bytes + 0x48) =
            ResourceTable_GetBaseEntry_001EC914(
                static_cast<const uint8_t*>(table), 1);
        uint8_t* base0 = *reinterpret_cast<uint8_t**>(bytes + 0x44);
        uint8_t* base1 = *reinterpret_cast<uint8_t**>(bytes + 0x48);
        const int16_t base0_value =
            *reinterpret_cast<const int16_t*>(base0 + 8);
        const int16_t base1_value =
            *reinterpret_cast<const int16_t*>(base1 + 8);
        if ((flags & 0x400u) == 0) {
            bytes[8] = 0;
        } else {
            bytes[8] = 1;
            *reinterpret_cast<float*>(bytes + 0x20) =
                (*reinterpret_cast<float*>(bytes + 0x18) -
                 static_cast<float>(base1_value)) * 0.1f;
            *reinterpret_cast<uint32_t*>(bytes + 0x24) = 0;
        }
        if ((flags & 0x800u) == 0) {
            bytes[9] = 0;
        } else {
            bytes[9] = 1;
            *reinterpret_cast<uint32_t*>(bytes + 0x28) = 0;
            *reinterpret_cast<float*>(bytes + 0x1c) =
                (*reinterpret_cast<float*>(bytes + 0x14) -
                 static_cast<float>(base0_value)) * 0.1f;
        }
        StateParameter_Reset_001CF704(state);
        return;
    }
    if ((flags & 0x10u) == 0) {
        bytes[4] = 0;
        bytes[5] = 0;
        bytes[6] = 0;
        bytes[7] = 0;
        bytes[8] = 0;
        bytes[9] = 0;
        *reinterpret_cast<uint32_t*>(bytes + 0x0c) = 0xffffffffu;
        bytes[0x10] = 0;
        bytes[0x11] = 0;
        *reinterpret_cast<uint32_t*>(bytes + 0x2c) = 0x3a09f874;
        return;
    }
    const float first = *reinterpret_cast<const float*>(bytes + 0x14);
    const float second = *reinterpret_cast<const float*>(bytes + 0x18);
    bytes[8] = 0;
    bytes[9] = 0;
    StateParameter_Reset_001CF704(state);
    const int selected = static_cast<int>(first > 0.0f ? second : first);
    if (selected >= 1) {
        return;
    }
    bytes[6] = 0;
    bytes[7] = 1;
    bytes[4] = 0;
    if ((flags & 0x3000u) == 0) {
        bytes[0x10] = 1;
    } else if ((flags & 0x1000u) == 0) {
        if ((flags & 0x2000u) != 0) {
            *reinterpret_cast<uint32_t*>(bytes + 0x0c) = 1;
        }
    } else {
        *reinterpret_cast<uint32_t*>(bytes + 0x0c) = 0;
    }
}
extern "C" uint32_t ResourceTree_KeyGetter_002A18B8();
__attribute__((noinline)) void StateContainer_SetKeyedFlag_001CF818(void* state, uint8_t value) {
    uint8_t* bytes = static_cast<uint8_t*>(state);
    const uint32_t key = ResourceTree_KeyGetter_002A18B8();
    uint8_t* sentinel = bytes + 0x1a8;
    uint8_t* node = *reinterpret_cast<uint8_t**>(bytes + 0x1ac);
    uint8_t* candidate = sentinel;
    while (node[0x10] != 0) {
        if (*reinterpret_cast<const uint32_t*>(node + 0x14) < key) {
            node = *reinterpret_cast<uint8_t**>(node + 0x0c);
        } else {
            candidate = node;
            node = *reinterpret_cast<uint8_t**>(node + 0x08);
        }
    }
    if (candidate == sentinel ||
        key < *reinterpret_cast<const uint32_t*>(candidate + 0x14)) {
        candidate = sentinel;
    }
    uint8_t* payload = *reinterpret_cast<uint8_t**>(candidate);
    const uint8_t* const sentinel_payload =
        *reinterpret_cast<const uint8_t* const*>(sentinel);
    if (payload == sentinel_payload) {
        payload = 0;
    }
    if (payload != 0) {
        payload[0x64] = static_cast<uint8_t>(
            (payload[0x64] & 0xbf) | ((value ^ 1u) << 6));
    }
}
extern "C" uint32_t ResourceState_GetRecord_00205E20(void* state,
                                                            int index);
extern "C" void ResourceState_Update_0020A878(
    void* object, int index, uint32_t record, int mode,
    uint32_t value);
extern "C" uint32_t ResourceTree_KeyGetter_001E39CC();
extern "C" void ResourceState_NotifyRecord_00224B0C(void* state, int index);
__attribute__((noinline)) void* AudioState_GetRuntime_001ED404(uint32_t handle) {
    uint8_t* resource = reinterpret_cast<uint8_t*>(
        static_cast<uintptr_t>(handle));
    void* node = OrderedTree_LowerBoundByPointer_004C5D3C(
        resource + 0x1a4,
        reinterpret_cast<void*>(static_cast<uintptr_t>(
            ResourceTree_KeyGetter_001E39CC())));
    void* candidate = node == 0
                          ? 0
                          : *reinterpret_cast<void**>(node);
    const void* sentinel = *reinterpret_cast<void**>(resource + 0x1a8);
    if (candidate == sentinel) {
        return 0;
    }
    return candidate;
}
__attribute__((noinline)) void BattleObject_SetTransition_001D6954(void* object, int slot, int value,
                                          float transition_value) {
    uint8_t* bytes = static_cast<uint8_t*>(object);
    uint32_t handle = 0;
    uint32_t runtime_handle = 0;
    if (slot == 0) {
        handle = *reinterpret_cast<uint32_t*>(bytes + 0x21c);
        runtime_handle = *reinterpret_cast<uint32_t*>(bytes + 0x228);
    } else if (slot == 1) {
        handle = *reinterpret_cast<uint32_t*>(bytes + 0x220);
        runtime_handle = *reinterpret_cast<uint32_t*>(bytes + 0x22c);
    }
    uint8_t* first = static_cast<uint8_t*>(
        AudioState_GetRuntime_001ED404(handle));
    uint8_t* second = static_cast<uint8_t*>(
        AudioState_GetRuntime_001ED404(runtime_handle));
    if (value == 0) {
        uint8_t* state = bytes + 0x118;
        if (slot < 2) {
            uint8_t* entry = *reinterpret_cast<uint8_t**>(
                state + 0x3c + slot * 4);
            transition_value = static_cast<float>(
                *reinterpret_cast<int16_t*>(entry + 8));
        }
        *reinterpret_cast<float*>(first + 0x24) = transition_value;
        *reinterpret_cast<float*>(second + 0x24) = transition_value;
    } else if (value == 1) {
        first[0x20] = 1;
        second[0x20] = 1;
    } else if (value == 2) {
        first[0x1d] = 1;
        second[0x1d] = 1;
    } else if (value == 3) {
        first[0x20] = 0;
        second[0x20] = 0;
    }
}
__attribute__((noinline)) void BattleState_ApplyResourceScale_001D6CCC(void* object, float scale) {
    uint8_t* bytes = static_cast<uint8_t*>(object);
    for (int index = 0; index != 2; ++index) {
        uint8_t* selected = *reinterpret_cast<uint8_t**>(
            bytes + (index == 0 ? 0x228 : 0x22c));
        const uint32_t value = *reinterpret_cast<const uint32_t*>(
            bytes + (index == 0 ? 0x21c : 0x220));
        const uint32_t record = ResourceState_GetRecord_00205E20(bytes + 0x118, index);
        ResourceState_Update_0020A878(object, index, record, 5, value);
        const uint32_t key = ResourceTree_KeyGetter_001E39CC();
        uint8_t* sentinel = selected + 0x1a8;
        uint8_t* node = *reinterpret_cast<uint8_t**>(selected + 0x1ac);
        uint8_t* candidate = sentinel;
        while (node[0x10] != 0) {
            if (*reinterpret_cast<const uint32_t*>(node + 0x14) < key) {
                node = *reinterpret_cast<uint8_t**>(node + 0x0c);
            } else {
                candidate = node;
                node = *reinterpret_cast<uint8_t**>(node + 0x08);
            }
        }
        if (candidate == sentinel ||
            key < *reinterpret_cast<const uint32_t*>(candidate + 0x14)) {
            candidate = sentinel;
        }
        uint8_t* payload = *reinterpret_cast<uint8_t**>(candidate);
        const uint8_t* const sentinel_payload =
            *reinterpret_cast<const uint8_t* const*>(sentinel);
        if (payload == sentinel_payload) {
            payload = 0;
        }
        ResourceState_NotifyRecord_00224B0C(bytes + 0x118, index);
        *reinterpret_cast<float*>(payload + 0x24) = scale;
    }
}
__attribute__((noinline)) void BattleObject_ApplySoundConfig_001D6704(void* object) {
    uint8_t* bytes = static_cast<uint8_t*>(object);
    uint8_t* container = static_cast<uint8_t*>(
        AudioState_GetContainer_002A6190(
            *reinterpret_cast<const uint32_t*>(bytes + 0x23c)));
    uint8_t** pair = *reinterpret_cast<uint8_t***>(container + 0x20);
    uint8_t* config = *reinterpret_cast<uint8_t**>(bytes + 0x488);
    uint8_t* target0 = *reinterpret_cast<uint8_t**>(pair);
    uint8_t* target1 = *reinterpret_cast<uint8_t**>(pair + 1);
    *reinterpret_cast<uint32_t*>(target0 + 0x0c) =
        *reinterpret_cast<const uint32_t*>(config + 0x468);
    *reinterpret_cast<uint32_t*>(target1 + 0x0c) =
        *reinterpret_cast<const uint32_t*>(config + 0x43c);
    uint8_t* runtime = static_cast<uint8_t*>(AudioState_GetRuntime_001ED404(
        *reinterpret_cast<const uint32_t*>(bytes + 0x23c)));
    runtime[0x20] = 1;
}
__attribute__((noinline)) void BattleObject_BuildSoundNames_001D6750(void* object, uint32_t index) {
    if (static_cast<int32_t>(index) < 0) {
        return;
    }
    uint8_t* bytes = static_cast<uint8_t*>(object);
    uint8_t* container = static_cast<uint8_t*>(
        AudioState_GetContainer_002A6190(
            *reinterpret_cast<const uint32_t*>(bytes + 0x234)));
    uint8_t** pair = *reinterpret_cast<uint8_t***>(container + 0x20);
    uint32_t handle = *reinterpret_cast<const uint32_t*>(
        bytes + index * 0x14 + 0x1a8);
    void* key = Engine_LazyResourceSingleton_001C47C4();
    void* lookup = OrderedTree_LookupUncached_00326C6C(handle, key);
    uint8_t* resource = lookup == 0
        ? static_cast<uint8_t*>(0)
        : *reinterpret_cast<uint8_t**>(
              static_cast<uint8_t*>(lookup) + 0x1c);
    uint32_t value = *reinterpret_cast<const uint32_t*>(resource + 0xf8);
    ParameterString_Format_002B3F78(bytes + 0x3c0, 0x10,
                                     reinterpret_cast<const void*>(0xca1584),
                                     value);
    bytes[0x3c3] = 0;
    ParameterString_Format_002B3F78(bytes + 0x3d0, 0x10,
                                     reinterpret_cast<const void*>(0xca157c),
                                     reinterpret_cast<uint32_t>(bytes + 0x3c0));
    bytes[0x3c3] = 0x6e;
    *reinterpret_cast<uint8_t**>(*pair + 0x0c) = bytes + 0x3c0;
    uint8_t* nested0 = *reinterpret_cast<uint8_t**>(pair[1] + 4);
    uint8_t* nested1 = *reinterpret_cast<uint8_t**>(nested0 + 4);
    uint8_t* target_node = *reinterpret_cast<uint8_t**>(nested1 + 4);
    uint8_t* target = *reinterpret_cast<uint8_t**>(target_node);
    *reinterpret_cast<uint8_t**>(target + 0x0c) = bytes + 0x3d0;
}
__attribute__((noinline)) void BattleObject_UpdateSoundTransition_001AA128(void* object) {
    uint8_t* bytes = static_cast<uint8_t*>(object);
    if (!StateContainer_IsUninitialized_001B4C28(bytes + 0xcc)) {
        return;
    }
    int32_t* countdown = reinterpret_cast<int32_t*>(bytes + 0x454);
    if (*countdown > 0 && --*countdown == 0) {
        if (bytes[0x458] == 3) {
            BattleState_SetSelectionFlag_001CF688(bytes + 0x118, 0);
            uint8_t* runtime = static_cast<uint8_t*>(
                AudioState_GetRuntime_001ED404(
                    *reinterpret_cast<const uint32_t*>(bytes + 0x220)));
            if (*reinterpret_cast<const int8_t*>(runtime + 0x28) != -1) {
                bytes[0x459] = 5;
            }
        }
        bytes[0x458] = bytes[0x459];
        void* key = Engine_LazyResourceSingleton_001D92C4();
        uint8_t* record = static_cast<uint8_t*>(
            OrderedTree_LookupUncached_00326C6C(
                *reinterpret_cast<const uint32_t*>(bytes + 0x234), key));
        if (record != 0 &&
            record[0x1e] != bytes[0x458]) {
            record[0x1e] = bytes[0x458];
            record[0x1c] = 1;
        }
        if (bytes[0x458] == 0 &&
            *reinterpret_cast<const int32_t*>(bytes + 0x43c) >= 0) {
            *reinterpret_cast<uint32_t*>(bytes + 0x434) = 0x32;
            void** singleton_slot = reinterpret_cast<void**>(0x00D63854);
            void* singleton = *singleton_slot;
            if (singleton == 0) {
                singleton = GetEngineSingleton_003FD6E0();
                *singleton_slot = singleton;
            }
            ResourceTransition_Apply_001EBC30(
                singleton,
                *reinterpret_cast<const int32_t*>(bytes + 0x43c), 1, 600);
        }
        BattleObject_ApplySoundConfig_001D6704(object);
    }
    const int32_t index = *reinterpret_cast<const int32_t*>(bytes + 0x464);
    uint8_t* resource = *reinterpret_cast<uint8_t**>(bytes + 0x484);
    const int8_t resource_state = static_cast<int8_t>(resource[0x1e]);
    if (index < 0) {
        if (resource_state == 2 &&
            *reinterpret_cast<const int32_t*>(bytes + 0x420) != -1) {
            *reinterpret_cast<uint32_t*>(bytes + 0x420) = 0xffffffff;
            StateMachine_SetState_001D680C(object, 0, 5);
        }
        return;
    }
    if ((resource_state == 0 || resource_state == 2) &&
        *reinterpret_cast<const int32_t*>(bytes + 0x420) !=
            *reinterpret_cast<const int32_t*>(bytes + 0x460) &&
        *reinterpret_cast<const uint32_t*>(
            bytes + index * 0x14 + 0x1a8) != 0) {
        *reinterpret_cast<uint32_t*>(bytes + 0x420) =
            *reinterpret_cast<const uint32_t*>(bytes + 0x460);
        BattleObject_BuildSoundNames_001D6750(object, index);
        StateMachine_SetState_001D680C(object, 2, 0);
    }
}
__attribute__((noinline)) void BattleObject_UpdateSoundParameters_001AB708(void* object) {
    uint8_t* bytes = static_cast<uint8_t*>(object);
    StateSound_BuildRuntimeRecords_001CFD70(
        reinterpret_cast<int*>(bytes + 0xcc));
    uint8_t* config = *reinterpret_cast<uint8_t**>(bytes + 0x488);
    for (int index = 0; index != 4; ++index) {
        uint8_t* record = bytes + index * 0x14 + 0x1a8;
        if (*reinterpret_cast<const int32_t*>(config + 0x8b0) <
            *reinterpret_cast<const int32_t*>(record + 0x08)) {
            *reinterpret_cast<uint32_t*>(record + 0x08) = 0;
            record[0x0c] = 0;
            BattleState_SetSoundRuntimeByte_001CFE34(
                bytes + 0xcc, index, 0);
        }
        if (record[0x0c] != 0) {
            ++*reinterpret_cast<int32_t*>(record + 0x08);
        }
        if (*reinterpret_cast<void**>(record + 0x04) != 0) {
            StateSound_ApplyParameter_001CFA2C(
                bytes + 0xcc, index,
                *reinterpret_cast<void**>(record + 0x04), 1);
        }
        if (*reinterpret_cast<void**>(record) != 0) {
            StateSound_ApplyParameter_001CFA2C(
                bytes + 0xcc, index, *reinterpret_cast<void**>(record), 0);
        }
    }
}
__attribute__((noinline)) int BattleState_GetNestedSignedByte_001A6044(const void* state) {
    const uint8_t* bytes = static_cast<const uint8_t*>(state);
    const uint8_t* const table = *reinterpret_cast<const uint8_t* const*>(
        bytes + 0x38);
    return *reinterpret_cast<const int8_t*>(table + 0x1a);
}
__attribute__((noinline)) void BattleState_SetSoundBit_001A6BD8(void* state, uint32_t index) {
    (void)state;
    if (static_cast<int32_t>(index) < 0) {
        return;
    }
    void** singleton_slot = reinterpret_cast<void**>(0x00d6365c);
    void* singleton = *singleton_slot;
    if (singleton == 0) {
        singleton = GetEngineSingleton_003B6CF0();
        *singleton_slot = singleton;
    }
    uint8_t* bits = static_cast<uint8_t*>(singleton) + 0x6278 +
                 (index >> 3) + 0x10175;
    const uint8_t mask = static_cast<uint8_t>(1u << (index & 7));
    *bits = static_cast<uint8_t>(*bits | mask);
}
__attribute__((noinline)) void BattleState_UpdateRuntimeResource_001A6A08(void* state, float scale) {
    uint8_t* state_bytes = static_cast<uint8_t*>(state);
    uint8_t* root = *reinterpret_cast<uint8_t**>(state_bytes);
    BattleState_UpdateResourceTable_001EB4C0(root);
    void** shared_slot = reinterpret_cast<void**>(0x00d637ec);
    void* shared = *shared_slot;
    if (shared == 0) {
        shared = Engine_SharedResourceSingleton_00422D20();
        *shared_slot = shared;
    }
    uint32_t active_value = Resource_GetActiveValue_00203148(
        *reinterpret_cast<void**>(static_cast<uint8_t*>(shared) + 0x48));
    uint8_t* active = reinterpret_cast<uint8_t*>(
        static_cast<uintptr_t>(active_value));
    *reinterpret_cast<float*>(active + 0x360) = scale - 3.0f;
    uint8_t** output_slot = reinterpret_cast<uint8_t**>(0x00d49494);
    uint8_t* output = *output_slot;
    const int16_t selected = *reinterpret_cast<const int16_t*>(root + 0x10);
    uint8_t* indexed = root + selected * 0x0c;
    *reinterpret_cast<uint32_t*>(output + 0x48) =
        *reinterpret_cast<const uint32_t*>(indexed + 0x294);
    *reinterpret_cast<uint16_t*>(output + 0x4c) = 0x200;
    *reinterpret_cast<uint16_t*>(output + 0x4e) = 0x200;
    *reinterpret_cast<uint32_t*>(output + 0x50) = 2;
    *reinterpret_cast<uint32_t*>(output + 0x08) =
        *reinterpret_cast<const uint32_t*>(root + 0x148);
    *reinterpret_cast<uint32_t*>(output + 0x0c) =
        *reinterpret_cast<const uint32_t*>(root + 0x14c);
    *reinterpret_cast<uint32_t*>(output + 0x10) =
        *reinterpret_cast<const uint32_t*>(root + 0x150);
    *reinterpret_cast<uint32_t*>(output + 0x14) =
        *reinterpret_cast<const uint32_t*>(root + 0x164);
    *reinterpret_cast<uint32_t*>(output + 0x20) =
        *reinterpret_cast<const uint32_t*>(root + 0x160);
    *reinterpret_cast<float*>(output + 0x24) =
        -*reinterpret_cast<const float*>(root + 0x154);
    *reinterpret_cast<uint32_t*>(output + 0x28) =
        *reinterpret_cast<const uint32_t*>(root + 0x168);
    *reinterpret_cast<uint32_t*>(output + 0x2c) =
        *reinterpret_cast<const uint32_t*>(root + 0x16c);
    *reinterpret_cast<uint32_t*>(output + 0x30) =
        *reinterpret_cast<const uint32_t*>(root + 0x170);
    *reinterpret_cast<uint32_t*>(output + 0x34) =
        *reinterpret_cast<const uint32_t*>(root + 0x174);
    *reinterpret_cast<uint32_t*>(output + 0x38) = 0;
    *reinterpret_cast<uint32_t*>(output + 0x3c) = 0;
    *reinterpret_cast<uint32_t*>(output + 0x40) = 0;
    *reinterpret_cast<float*>(output + 0x44) = 1.0f;
    *reinterpret_cast<uint32_t*>(output + 0x18) =
        *reinterpret_cast<const uint32_t*>(root + 0x158);
    *reinterpret_cast<uint32_t*>(output + 0x1c) =
        *reinterpret_cast<const uint32_t*>(root + 0x15c);
    output[0x54] = 1;
    *reinterpret_cast<uint32_t*>(output + 0xe8) =
        *reinterpret_cast<const uint32_t*>(indexed + 0x270);
    *reinterpret_cast<uint16_t*>(output + 0xec) = 0x200;
    *reinterpret_cast<uint16_t*>(output + 0xee) = 0x200;
    *reinterpret_cast<uint32_t*>(output + 0xf0) = 2;
    *reinterpret_cast<uint32_t*>(output + 0xa8) =
        *reinterpret_cast<const uint32_t*>(root + 0x118);
    *reinterpret_cast<uint32_t*>(output + 0xac) =
        *reinterpret_cast<const uint32_t*>(root + 0x11c);
    *reinterpret_cast<uint32_t*>(output + 0xb0) =
        *reinterpret_cast<const uint32_t*>(root + 0x120);
    *reinterpret_cast<uint32_t*>(output + 0xb4) =
        *reinterpret_cast<const uint32_t*>(root + 0x134);
    *reinterpret_cast<uint32_t*>(output + 0xb8) =
        *reinterpret_cast<const uint32_t*>(root + 0x128);
    *reinterpret_cast<uint32_t*>(output + 0xbc) =
        *reinterpret_cast<const uint32_t*>(root + 0x12c);
    *reinterpret_cast<uint32_t*>(output + 0xc0) =
        *reinterpret_cast<const uint32_t*>(root + 0x130);
    *reinterpret_cast<float*>(output + 0xc4) =
        -*reinterpret_cast<const float*>(root + 0x124);
    *reinterpret_cast<uint32_t*>(output + 0xc8) =
        *reinterpret_cast<const uint32_t*>(root + 0x138);
    *reinterpret_cast<uint32_t*>(output + 0xcc) =
        *reinterpret_cast<const uint32_t*>(root + 0x13c);
    *reinterpret_cast<uint32_t*>(output + 0xd0) =
        *reinterpret_cast<const uint32_t*>(root + 0x140);
    *reinterpret_cast<uint32_t*>(output + 0xd4) =
        *reinterpret_cast<const uint32_t*>(root + 0x144);
    *reinterpret_cast<uint32_t*>(output + 0xd8) = 0;
    *reinterpret_cast<uint32_t*>(output + 0xdc) = 0;
    *reinterpret_cast<uint32_t*>(output + 0xe0) = 0;
    *reinterpret_cast<float*>(output + 0xe4) = 1.0f;
    output[0xf4] = 1;
}
__attribute__((noinline)) void BattleState_InitializeSoundRecords_001EB420(void* state) {
    uint8_t* root = *reinterpret_cast<uint8_t**>(state);
    for (int index = 0; index != 4; ++index) {
        uint8_t* record = root + index * 0x150 + 0x1fe8;
        *reinterpret_cast<uint32_t*>(record) = 0;
        *reinterpret_cast<uint32_t*>(record + 0x0c) = 0x1e;
    }
}
extern "C" __attribute__((noinline)) void StateSound_ApplyParameter_001CFA2C(
    void* state, int index, void* parameter, int active) {
    if (parameter == 0) {
        return;
    }
    uint8_t* state_bytes = static_cast<uint8_t*>(state);
    uint8_t* parameter_bytes = static_cast<uint8_t*>(parameter);
    uint8_t* root = *reinterpret_cast<uint8_t**>(state_bytes);
    uint8_t* state_record = root + 0x1f30 + index * 0x150;
    uint8_t* sentinel = parameter_bytes + 0x1a8;
    uint8_t* node = *reinterpret_cast<uint8_t**>(parameter_bytes + 0x1ac);
    uint8_t* candidate = sentinel;
    const uint32_t key = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(
        Engine_LazyResourceSingleton_001C47C4()));
    while (node[0x10] != 0) {
        if (*reinterpret_cast<const uint32_t*>(node + 0x14) < key) {
            node = *reinterpret_cast<uint8_t**>(node + 0x0c);
        } else {
            candidate = node;
            node = *reinterpret_cast<uint8_t**>(node + 0x08);
        }
    }
    if (candidate == sentinel ||
        key < *reinterpret_cast<const uint32_t*>(candidate + 0x14)) {
        candidate = sentinel;
    }
    uint8_t* selected = *reinterpret_cast<uint8_t**>(candidate);
    if (selected == *reinterpret_cast<uint8_t**>(sentinel)) {
        selected = 0;
    }
    float scale;
    if (active == 0) {
        scale = *reinterpret_cast<const float*>(state_record + 0x10) *
                *reinterpret_cast<const float*>(state_record + 0x14) *
                *reinterpret_cast<const float*>(selected + 0x14c);
    } else {
        scale = *reinterpret_cast<const float*>(state_record + 0x18);
    }
    if (scale <= 0.0f) {
        StateContainer_SetKeyedFlag_001CF818(parameter, 0);
        return;
    }
    *reinterpret_cast<float*>(parameter_bytes + 0x60) = scale;
    StateContainer_SetKeyedFlag_001CF818(parameter, 1);
    void** shared_slot = reinterpret_cast<void**>(0x00d637ec);
    void* shared = *shared_slot;
    if (shared == 0) {
        shared = Engine_SharedResourceSingleton_00422D20();
        *shared_slot = shared;
    }
    const uint32_t active_value = Resource_GetActiveValue_00203148(
        *reinterpret_cast<void**>(static_cast<uint8_t*>(shared) + 0x48));
    const bool use_alternate = Engine_GlobalTimeGate_001B5128() != 0;
    const uint32_t source_offset = use_alternate ? 0x80 : 0x50;
    uint8_t* destination = reinterpret_cast<uint8_t*>(
        static_cast<uintptr_t>(active_value)) + index * 0x90;
    for (uint32_t offset = 0; offset <= 0x2c; offset += 4) {
        *reinterpret_cast<uint32_t*>(destination + 0xa0 + offset) =
            *reinterpret_cast<const uint32_t*>(
                state_record + source_offset + offset);
    }
    *reinterpret_cast<uint32_t*>(destination + 0xd0) =
        *reinterpret_cast<const uint32_t*>(state_record + 0x50);
    for (uint32_t offset = 4; offset <= 0x2c; offset += 4) {
        *reinterpret_cast<uint32_t*>(destination + 0xd0 + offset) =
            *reinterpret_cast<const uint32_t*>(state_record + 0x50 + offset);
    }
    for (uint32_t offset = 0; offset <= 0x1c; offset += 4) {
        *reinterpret_cast<uint32_t*>(destination + 0x100 + offset) =
            *reinterpret_cast<const uint32_t*>(state_record + 0x20 + offset);
    }
    *reinterpret_cast<uint32_t*>(destination + 0x120) =
        *reinterpret_cast<const uint32_t*>(state_record + 0x40);
    *reinterpret_cast<uint32_t*>(destination + 0x124) =
        *reinterpret_cast<const uint32_t*>(state_record + 0x44);
    *reinterpret_cast<uint32_t*>(destination + 0x128) =
        *reinterpret_cast<const uint32_t*>(state_record + 0x48);
    *reinterpret_cast<uint32_t*>(destination + 0x12c) =
        *reinterpret_cast<const uint32_t*>(state_record + 0x4c);
    for (uint32_t offset = 0; offset < 0x3c; offset += 4) {
        *reinterpret_cast<uint32_t*>(
            reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(
                active_value)) + 0x2e0 + offset) =
            *reinterpret_cast<const uint32_t*>(root + 0x1bc + offset);
    }
    for (uint32_t offset = 0; offset < 0x40; offset += 4) {
        *reinterpret_cast<uint32_t*>(parameter_bytes + 0x64 + offset) =
            *reinterpret_cast<const uint32_t*>(
                reinterpret_cast<const uint8_t*>(0x00dc2538) + offset);
    }
    *reinterpret_cast<float*>(parameter_bytes + 0x74) = scale;
    *reinterpret_cast<float*>(parameter_bytes + 0x78) = scale;
    *reinterpret_cast<float*>(parameter_bytes + 0x7c) = -0.7f;
    if (active == 0) {
        const float factor = *reinterpret_cast<const float*>(state_record + 0x10) *
                             *reinterpret_cast<const float*>(state_record + 0x14);
        *reinterpret_cast<float*>(parameter_bytes + 0x74) =
            scale + *reinterpret_cast<const float*>(selected + 0x150) * factor;
        *reinterpret_cast<float*>(parameter_bytes + 0x78) =
            scale + *reinterpret_cast<const float*>(selected + 0x154) * factor;
        *reinterpret_cast<float*>(parameter_bytes + 0x7c) =
            -0.7f + *reinterpret_cast<const float*>(selected + 0x158) * factor;
    }
}
__attribute__((noinline)) int BattleState_GetSignedByte_001A6050(const void* state, uint32_t index) {
    if (index >= 2) {
        return 0;
    }
    const uint8_t* bytes = static_cast<const uint8_t*>(state);
    return *reinterpret_cast<const int8_t*>(bytes + 8 + index);
}
__attribute__((noinline)) uint32_t BattleState_GetResourceWord2560_001A6348(const void* state) {
    const uint8_t* bytes = static_cast<const uint8_t*>(state);
    const uint8_t* const resource = *reinterpret_cast<const uint8_t* const*>(bytes);
    return *reinterpret_cast<const uint32_t*>(resource + 0x2560);
}
__attribute__((noinline)) uint32_t BattleState_GetIndexedWord34_001EB4AC(const void* table,
                                                     int index) {
    const uint8_t* bytes = static_cast<const uint8_t*>(table);
    return *reinterpret_cast<const uint32_t*>(bytes + index * 0x60 + 0x34);
}
extern "C" void BattleRuntime_ResetSubobject_0038F0DC(void* object);
__attribute__((noinline)) void BattleState_ResetRuntimeFields_001EB0E0(void* object) {
    uint8_t* bytes = static_cast<uint8_t*>(object);
    const uintptr_t kBase = 0x24b8u;
    const uintptr_t kWordZero = kBase | (kBase >> 8);
    *reinterpret_cast<uint8_t*>(bytes + kBase) = 1;
    *reinterpret_cast<uint32_t*>(bytes + kWordZero) = 0;
    *reinterpret_cast<uint32_t*>(bytes + 0x2560) = 2;
    *reinterpret_cast<uint8_t*>(bytes + 0x1225e) = 0;
    BattleRuntime_ResetSubobject_0038F0DC(bytes + 0x256c);
}
extern "C" void BattleState_PrepareResources_001EB238(void* object);
extern "C" void* BattleState_GetSingleton_00225BA8();
extern "C" void StateRecord_Init_001B0E14(void* record, int mode);
extern "C" void StateRecord_Finalize_00129C70(void* record);
extern "C" int ResourceService_GetDescriptor_00262E98(
    uint32_t* output, uint32_t key);
__attribute__((noinline)) uint32_t ResourceService_Hash_0029DDE4(uint32_t value) {
    if (static_cast<int32_t>(value) >= 0x20) {
        return value - 0x20;
    }
    if (static_cast<int32_t>(value) >= 0x18) {
        return value - 0x18 + 0x5109d500u;
    }
    return value + 0x6c8da500u;
}
extern "C" int ResourceService_Register_00562F2C(
    void* destination, const uint32_t* request, const void* key,
    uint32_t* owner);
extern "C" void Platform_ReportServiceError_003D1B64();
extern "C" __attribute__((noinline)) void BattleState_PrepareResources_001EB238(void* object) {
    uint8_t* bytes = static_cast<uint8_t*>(object);
    uint32_t stack[11] = {0};
    if (ResourceService_GetDescriptor_00262E98(
            &stack[0], *reinterpret_cast<const uint32_t*>(0x00cb17c8)) < 0) {
        Platform_ReportServiceError_003D1B64();
    }
    stack[0] = 0x2800;
    stack[1] = ResourceService_Hash_0029DDE4(stack[0]) + 2;
    stack[2] = 0xffffffffu;
    stack[3] = 0x0025c478;
    stack[4] = reinterpret_cast<uintptr_t>(object);
    stack[6] = 4;
    stack[7] = 0x00261b04;
    stack[8] = 0x00261b20;
    stack[9] = 0x00261b14;
    if (ResourceService_Register_00562F2C(
            bytes + 4, &stack[6], reinterpret_cast<const void*>(stack[3]),
            &stack[4]) < 0) {
        Platform_ReportServiceError_003D1B64();
    }
    if (ResourceService_GetDescriptor_00262E98(
            &stack[0], *reinterpret_cast<const uint32_t*>(0x00cb17c8)) < 0) {
        Platform_ReportServiceError_003D1B64();
    }
    stack[0] = 0x2800;
    stack[1] = ResourceService_Hash_0029DDE4(stack[0]) + 0xb;
    stack[2] = 0xfffffffeu;
    stack[3] = reinterpret_cast<uintptr_t>(object);
    stack[4] = 4;
    stack[5] = 0x00261b04;
    stack[6] = 0x00261b20;
    stack[7] = 0x00261b14;
    if (ResourceService_Register_00562F2C(
            bytes + 0x2564, &stack[4], reinterpret_cast<const void*>(0x0025b878),
            &stack[3]) < 0) {
        Platform_ReportServiceError_003D1B64();
    }
}
extern "C" __attribute__((noinline)) void BattleState_RegisterResource_001D4FB8(
    void* destination, void*, uint32_t value0, uint32_t value1) {
    uint8_t* bytes = static_cast<uint8_t*>(destination);
    *reinterpret_cast<uint32_t*>(bytes + 0x08) =
        value1 + 0x5dc00;
    *reinterpret_cast<uint32_t*>(bytes + 0x00) = value0;
    *reinterpret_cast<uint32_t*>(bytes + 0x04) = value1;
    StateRecord_Init_001B0E14(bytes + 0x1c, 0);
    StateRecord_Finalize_00129C70(bytes + 0x1c);
    uint32_t request[8];
    const uint32_t descriptor_key =
        *reinterpret_cast<const uint32_t*>(0x00ca7bc0);
    if (ResourceService_GetDescriptor_00262E98(&request[0], descriptor_key) < 0) {
        Platform_ReportServiceError_003D1B64();
    }
    request[1] = ResourceService_Hash_0029DDE4(request[0]) - 4;
    request[2] = 0xffffffffu;
    request[3] = reinterpret_cast<uintptr_t>(destination);
    request[4] = 4;
    request[5] = 0x00225078;
    request[6] = 0x00225094;
    request[7] = 0x00225088;
    uint32_t owner = reinterpret_cast<uintptr_t>(destination);
    if (ResourceService_Register_00562F2C(
            bytes + 0x14, request, reinterpret_cast<const void*>(0x0020a740),
            &owner) < 0) {
        Platform_ReportServiceError_003D1B64();
    }
}
extern "C" __attribute__((noinline)) bool StateContainer_Reset_001A6298(void* state, int mode) {
    uint32_t* words = static_cast<uint32_t*>(state);
    const bool was_uninitialized =
        *reinterpret_cast<const uint8_t*>(static_cast<const uint8_t*>(state) +
                                               0x39) == 0;
    if (mode != 0) {
        BattleState_PrepareResources_001EB238(
            reinterpret_cast<void*>(static_cast<uintptr_t>(words[0])));
        if (words[1] != 0) {
            const uint8_t* resource = reinterpret_cast<const uint8_t*>(static_cast<uintptr_t>(words[0]));
            const uint32_t value1 = BattleState_GetIndexedWord34_001EB4AC(resource, 1);
            const uint32_t value0 = BattleState_GetIndexedWord34_001EB4AC(resource, 0);
            void** singleton_slot = reinterpret_cast<void**>(0x00D63684);
            void* singleton = *singleton_slot;
            if (singleton == 0) {
                singleton = BattleState_GetSingleton_00225BA8();
                *singleton_slot = singleton;
            }
            BattleState_RegisterResource_001D4FB8(
                reinterpret_cast<void*>(static_cast<uintptr_t>(words[1])),
                static_cast<uint8_t*>(singleton) + 0x460, value0, value1);
        }
    }
    if (was_uninitialized) {
        BattleState_ResetRuntimeFields_001EB0E0(
            reinterpret_cast<void*>(static_cast<uintptr_t>(words[0])));
        *reinterpret_cast<uint8_t*>(static_cast<uint8_t*>(state) + 0x39) = 1;
    }
    return was_uninitialized;
}
__attribute__((noinline)) bool BattleStateTable_AllowsTransitionSound_001EA874(const void* state,
                                                       int index) {
    static const uint32_t kMasks[] = {0x2008u, 0x1008u};
    const uint8_t* bytes = static_cast<const uint8_t*>(state);
    const uint8_t* const table = *reinterpret_cast<const uint8_t* const*>(
        bytes + 0x38);
    const uint32_t flags =
        *reinterpret_cast<const uint32_t*>(table + 0x68);
    return (kMasks[index] & ~flags) == 0;
}
__attribute__((noinline)) float BattleState_SetSoundSelectionFlag_001CF9F8(void* state,
                                                  int index,
                                                  uint8_t value) {
    uint8_t* bytes = static_cast<uint8_t*>(state);
    uint8_t* runtime = *reinterpret_cast<uint8_t**>(bytes);
    uint8_t* entry = runtime + 0x1F30 + index * 0x150;
    entry[0x105] = value;
    return *reinterpret_cast<const float*>(entry + 0x13c);
}
__attribute__((noinline)) int32_t BattleObject_SelectAndClearSoundHandle_001D6BDC(
    uint8_t* object, int mode) {
    if (mode == 3) {
        const int32_t value = *reinterpret_cast<int32_t*>(object + 0x1A0);
        if (value != -1) {
            *reinterpret_cast<int32_t*>(object + 0x1A0) = -1;
        }
        return value;
    }
    const int32_t first = *reinterpret_cast<int32_t*>(object + 0x194);
    if (first == -1 ||
        *reinterpret_cast<int32_t*>(object + 0x198) == -1 ||
        *reinterpret_cast<int32_t*>(object + 0x19C) == -1) {
        return -1;
    }
    int32_t returned = -1;
    const int32_t* active = *reinterpret_cast<const int32_t**>(object + 0x408);
    for (int slot = 0; slot < 3; ++slot) {
        int32_t* slot_value = reinterpret_cast<int32_t*>(object + 0x194 +
                                                            slot * 4);
        const int32_t value = *slot_value;
        bool retained = false;
        if (active != 0) {
            retained = active[0] == value || active[1] == value ||
                       active[2] == value;
        }
        if (!retained) {
            returned = value;
            *slot_value = -1;
        }
    }
    *reinterpret_cast<int32_t*>(object + 0x19C) = -1;
    return returned;
}
__attribute__((noinline)) void BattleState_SetSoundRuntimeByte_001CFE34(void* state,
                                               int index,
                                               uint8_t value) {
    uint8_t* bytes = static_cast<uint8_t*>(state);
    uint8_t* runtime = *reinterpret_cast<uint8_t**>(bytes);
    if (runtime != 0) {
        *reinterpret_cast<uint8_t*>(runtime + 0x1F30 + index * 0x150 +
                                         0x104) = value;
    }
}
__attribute__((noinline)) uint32_t BattleState_UpdateSoundUsage_001A6224(
    void* state, uint32_t duration, int entry_offset) {
    (void)state;
    void** singleton_slot = reinterpret_cast<void**>(0x00D6365C);
    void* singleton = *singleton_slot;
    if (singleton == 0) {
        singleton = GetEngineSingleton_003B6CF0();
        *singleton_slot = singleton;
    }
    uint8_t* resource_table = static_cast<uint8_t*>(singleton) + 0x6278;
    SoundResource_ClampDuration_002B4CEC(resource_table, duration);
    singleton = *singleton_slot;
    if (singleton == 0) {
        singleton = GetEngineSingleton_003B6CF0();
        *singleton_slot = singleton;
    }
    uint8_t* entry = static_cast<uint8_t*>(singleton) + 0x6278 +
                  entry_offset;
    uint32_t usage = static_cast<uint32_t>(entry[0x46C]) + 1;
    if (usage > 100) {
        usage = 100;
    }
    entry[0x46C] = static_cast<uint8_t>(usage);
    return 1;
}
__attribute__((noinline)) void BattleState_StoreHitLevel_001EAF5C(void* entry, int level) {
    uint8_t* bytes = static_cast<uint8_t*>(entry);
    *reinterpret_cast<uint32_t*>(bytes + 0x148) = 0x44870000;
    *reinterpret_cast<float*>(bytes + 0x14c) = 0.25f + static_cast<float>(level) * 0.2f;
}
__attribute__((noinline)) int BattleState_GetRuntimeBase_001A6338(const int* state) {
    return *state + 0x1f30;
}
__attribute__((noinline)) int BattleUi_ApplyModeAndSound_001A97E8(void* object, int mode,
                                        float transition_value) {
    uint8_t* bytes = static_cast<uint8_t*>(object);
    if (*reinterpret_cast<int8_t*>(bytes + 0x190) == mode) {
        return 0;
    }
    *reinterpret_cast<int8_t*>(bytes + 0x190) =
        static_cast<int8_t>(mode);
    if (mode == -1) {
        BattleUi_PlayConfiguredSound_001D7468(object, 10, 0);
        BattleState_ClearPendingTransition_001CFD2C(bytes + 0xcc);
    } else if (mode == 1) {
        StateContainer_Reset_001A6298(bytes + 0xcc, 0);
        StateMachine_SetState_001D680C(object, 0, 5);
    } else if (mode == 2) {
        uint8_t* state = *reinterpret_cast<uint8_t**>(bytes + 0x47c);
        if ((state[0x1c] & 0x80) != 0) {
            state[0x1c] = static_cast<uint8_t>((state[0x1c] & ~0x08) | 0x04);
        }
        StateContainer_SetKeyedFlag_001CF818(
            reinterpret_cast<void*>(static_cast<uintptr_t>(
                *reinterpret_cast<uint32_t*>(bytes + 0x20c))),
            1);
        uint8_t* config = *reinterpret_cast<uint8_t**>(bytes + 0x488);
        *reinterpret_cast<uint32_t*>(bytes + 0x164) =
            *reinterpret_cast<uint32_t*>(config + 0x18);
        StateObject_Copy_00352994(bytes + 0x168, config + 0x1c);
        BattleObject_SetMode_001D7AC0(object, 0);
        BattleObject_BuildResourceAndSoundNames_001D6F88(object);
        BattleObject_SetTimer_001D77E4(object, 1, 0x3c);
        StateMachine_SetState_001D680C(object, 5, 0);
        BattleState_SetSelectionFlag_001CF688(bytes + 0x118, 0);
        uint8_t* runtime = static_cast<uint8_t*>(AudioState_GetRuntime_001ED404(
            *reinterpret_cast<uint32_t*>(bytes + 0x23c)));
        runtime[0x20] = 0;
    } else if (mode == 5) {
        uint8_t* state = *reinterpret_cast<uint8_t**>(bytes + 0x47c);
        if ((state[0x1c] & 0x80) == 0) {
            state[0x1c] |= 0x0c;
        }
        uint8_t* config = *reinterpret_cast<uint8_t**>(bytes + 0x488);
        *reinterpret_cast<uint32_t*>(bytes + 0x164) =
            *reinterpret_cast<uint32_t*>(config + 0x70);
        StateObject_Copy_00352994(bytes + 0x168, config + 0x74);
        BattleObject_SetMode_001D7AC0(object, 1);
        BattleState_ResetSelection_001CF694(bytes + 0x118);
        *reinterpret_cast<uint32_t*>(bytes + 0x3e0) = 0;
        *reinterpret_cast<uint8_t*>(bytes + 0x208) &= ~uint8_t(0x06);
        BattleObject_ResetAction_0020AB6C(
            object, *reinterpret_cast<uint32_t*>(bytes + 0x21c), -1, -1, 1);
        BattleObject_ResetAction_0020AB6C(
            object, *reinterpret_cast<uint32_t*>(bytes + 0x220), -1, -1, 1);
        BattleObject_SetTransition_001D6954(object, 0, 3, transition_value);
        BattleObject_SetTransition_001D6954(object, 1, 3, transition_value);
        uint8_t* runtime = static_cast<uint8_t*>(AudioState_GetRuntime_001ED404(
            *reinterpret_cast<uint32_t*>(bytes + 0x238)));
        if (runtime[0x1f] == 0) {
            runtime[0x1f] = 1;
        }
        BattleState_SetSelectionFlag_001CF688(bytes + 0x118, 0);
    }
    return 1;
}
extern "C" void* Engine_LazySingletonGetter_00498828();
extern "C" void* Engine_LazyResourceSingleton_001C47C4();
extern "C" void StateParameterRecord_Init_003B530C(uint32_t* record);
extern "C" void ParameterString_Normalize_00352994(void* destination,
                                                     const void* source);
extern "C" uint32_t ParameterString_Hash_002F2808(void* record);
extern "C" void ParameterString_Assign_0043A31C(void* destination,
                                                 const void* source);
extern "C" void Transform_ResolveEffectiveMatrix_004C39D8(
    float* output, void* source, void* selected_record);
extern "C" void Engine_StatusEventIdEncode(uint32_t* output,
                                             int key,
                                             void* payload,
                                             int mode,
                                             int variant);
extern "C" void* Engine_SharedResourceSingleton_00422D20();
extern "C" void* Resource_GetIndexedEntry_00464200(void* table, int index);
extern "C" void* Engine_SharedObjectSingleton_004C5BA4();
extern "C" void StatusEvent_DispatchByEncodedKey_001EBC8C(
    void* object, uint32_t* encoded, void* resource);
static void BattleSound_ActivateHandle(uint32_t handle, int active) {
    uint8_t* entry = static_cast<uint8_t*>(
        ResourceTree_ResolveCurrentEntry_002A6268(handle));
    uint8_t* owner_list = static_cast<uint8_t*>(
        *reinterpret_cast<void**>(entry + 0x20));
    ResourceTree_Activate_002A17A0(owner_list + 0x8, handle, active);
}
static void BattleSound_PlayAction(uint8_t* bytes,
                                   uint32_t resource_handle,
                                   uint32_t action_handle) {
    uint32_t key[2] = {0};
    StateParameterRecord_Init_003B530C(key);
    uint8_t* action = *reinterpret_cast<uint8_t**>(
        bytes + action_handle);
    key[0] = *reinterpret_cast<uint32_t*>(action + 0xc8);
    key[1] = *reinterpret_cast<uint32_t*>(action + 0xcc);
    Actor_PlayActionByHash_0036FCA8(resource_handle, 0x14, key, 1, 1);
}
extern "C" void* OrderedTree_LookupActive_00473C9C(
    void* tree, const uint32_t* key);
static void* BattleIndexed_ResolveDescriptor(uint8_t* entry) {
    void** cache = reinterpret_cast<void**>(entry + 0x1e4);
    if (*cache == 0) {
        void* node = OrderedTree_LowerBoundByPointer_004C5D3C(
            entry + 0x1a4, Engine_LazySingletonGetter_00498828());
        void* payload = node == 0 ? 0
                                        : *reinterpret_cast<void**>(node);
        void* sentinel = *reinterpret_cast<void**>(entry + 0x1a8);
        if (payload == sentinel) {
            payload = 0;
        }
        if (payload != 0) {
            *reinterpret_cast<void**>(static_cast<uint8_t*>(payload) + 0x1c) =
                entry;
            *cache = payload;
        }
    }
    return *cache;
}
__attribute__((noinline)) void BattleUi_PlayIndexedSound_001AA578(void* object, int mode) {
    uint8_t* bytes = static_cast<uint8_t*>(object);
    uint8_t* state = bytes + 0x118;
    const int status_key =
        BattleStateTable_GetSignedHalfword_001CF800(state, mode);
    const int level = BattleStateTable_GetSignedByte_001CF6D4(state, mode);
    const int source_index = BattleStateTable_GetActiveIndex_001CF6EC(state, mode);
    const int selected_index =
        BattleStateTable_GetActiveIndex_001CF6EC(state, mode == 0);
    uint8_t* state_slot = bytes + selected_index * 0x14;
    const uint32_t resource_handle =
        *reinterpret_cast<uint32_t*>(state_slot + 0x1a8);
    void* resource_node = OrderedTree_LookupUncached_00326C6C(
        resource_handle, Engine_LazyResourceSingleton_001C47C4());
    uint8_t* resource = resource_node == 0
                         ? 0
                         : *reinterpret_cast<uint8_t**>(
                               static_cast<uint8_t*>(resource_node) + 0x1c);
    uint8_t* runtime = reinterpret_cast<uint8_t*>(
        BattleState_GetRuntimeBase_001A6338(
            reinterpret_cast<const int*>(bytes + 0xcc)));
    uint8_t* runtime_entry = runtime + selected_index * 0x180;
    const float* matrix = reinterpret_cast<const float*>(runtime_entry + 0x20);
    const float a = matrix[0];
    const float b = matrix[1];
    const float c = matrix[2];
    const float d = matrix[4];
    const float e = matrix[5];
    const float f = matrix[6];
    const float g = matrix[8];
    const float h = matrix[9];
    const float i = matrix[10];
    const float determinant = a * e * i + b * f * g + c * d * h -
                              c * e * g - a * f * h - b * d * i;
    float inverse[9];
    if (determinant == 0.0f) {
        const float* fallback = reinterpret_cast<const float*>(0x00DC2588);
        for (int index = 0; index != 9; ++index) {
            inverse[index] = fallback[index];
        }
    } else {
        const float reciprocal = 1.0f / determinant;
        inverse[0] = (e * i - f * h) * reciprocal;
        inverse[1] = (c * h - b * i) * reciprocal;
        inverse[2] = (b * f - c * e) * reciprocal;
        inverse[3] = (f * g - d * i) * reciprocal;
        inverse[4] = (a * i - c * g) * reciprocal;
        inverse[5] = (c * d - a * f) * reciprocal;
        inverse[6] = (d * h - e * g) * reciprocal;
        inverse[7] = (b * g - a * h) * reciprocal;
        inverse[8] = (a * e - b * d) * reciprocal;
    }
    float payload[12] = {
        inverse[0], inverse[1], inverse[2], 0.0f,
        inverse[3], inverse[4], inverse[5], 0.0f,
        inverse[6], inverse[7], inverse[8], 0.0f,
    };
    const float resource_scale = *reinterpret_cast<float*>(resource + 0x16c);
    const float* resource_position = reinterpret_cast<const float*>(resource + 0x15c);
    payload[3] = resource_position[0] + inverse[2] * resource_scale;
    payload[7] = resource_position[1] + inverse[5] * resource_scale;
    payload[11] = resource_position[2] + inverse[8] * resource_scale;
    void* descriptor = BattleIndexed_ResolveDescriptor(
        *reinterpret_cast<uint8_t**>(state_slot + 0x1a8));
    void* source = *reinterpret_cast<void**>(
        static_cast<uint8_t*>(descriptor) + 0x24);
    uint32_t parameter_key[11] = {0};
    StateParameterRecord_Init_003B530C(parameter_key);
    parameter_key[0] = *reinterpret_cast<uint32_t*>(resource + 0xc8);
    parameter_key[1] = *reinterpret_cast<uint32_t*>(resource + 0xcc);
    void* selected_record = OrderedTree_LookupActive_00473C9C(
        source, parameter_key);
    if (selected_record == 0) {
        uint8_t empty_source[0x20] = {0};
        uint8_t top_n_string[0x20] = {0};
        uint32_t temporary_key[11] = {0};
        ParameterString_Normalize_00352994(top_n_string, empty_source);
        ParameterString_Assign_0043A31C(
            top_n_string, reinterpret_cast<const void*>(0x001AA9B8));
        StateParameterRecord_Init_003B530C(temporary_key);
        temporary_key[0] = ParameterString_Hash_002F2808(top_n_string);
        temporary_key[1] = *reinterpret_cast<uintptr_t*>(top_n_string);
        selected_record = OrderedTree_LookupActive_00473C9C(
            source, temporary_key);
        if (selected_record != 0) {
            float transform[12] = {0};
            Transform_ResolveEffectiveMatrix_004C39D8(
                transform, source, selected_record);
            payload[7] += transform[7];
            payload[11] += transform[11];
        }
    }
    const float scale = *reinterpret_cast<float*>(resource + 0x168) * 0.4f;
    for (int index = 0; index != 12; ++index) {
        if ((index & 3) != 3) {
            payload[index] *= scale;
        }
    }
    uint32_t encoded = 0;
    const int variant = *reinterpret_cast<int*>(
        bytes + source_index * 0x14 + 0x1a8);
    Engine_StatusEventIdEncode(&encoded, status_key, payload, 0, variant);
    void** resource_slot = reinterpret_cast<void**>(0x00D637EC);
    if (*resource_slot == 0) {
        *resource_slot = Engine_SharedResourceSingleton_00422D20();
    }
    void* status_resource = Resource_GetIndexedEntry_00464200(
        *reinterpret_cast<void**>(static_cast<uint8_t*>(*resource_slot) +
                                  0x44),
        selected_index);
    void** object_slot = reinterpret_cast<void**>(0x00D6385C);
    if (*object_slot == 0) {
        *object_slot = Engine_SharedObjectSingleton_004C5BA4();
    }
    StatusEvent_DispatchByEncodedKey_001EBC8C(
        *object_slot, &encoded, status_resource);
    const int category = status_key % 10 & 0xff;
    BattleUi_PlayConfiguredSound_001D7468(object, category, level);
    uint8_t* hit_entry = runtime + selected_index * 0x150;
    BattleState_StoreHitLevel_001EAF5C(hit_entry, level);
}
__attribute__((noinline)) void StateAudioParameter_Init_001CFE94(uint8_t* payload) {
    *reinterpret_cast<uint32_t*>(payload) = 0;
    *reinterpret_cast<float*>(payload + 4) = 0.0f;
    payload[8] = 0;
    payload[9] = 0;
    payload[10] = 0;
    payload[11] = 0;
    payload[12] = 0;
}
// Retail passes the scalar in s0; the other fields are byte-sized flags.
__attribute__((noinline)) void StateAudioParameter_SetConfig_001CFE60(
    uint8_t* payload, uint8_t flag0, uint8_t flag1,
    uint8_t flag2, uint8_t flag3, uint32_t packed,
    uint8_t tail, float scalar) {
    *reinterpret_cast<float*>(payload + 4) = scalar;
    payload[8] = flag0;
    payload[9] = flag1;
    payload[10] = flag2;
    payload[11] = flag3;
    *reinterpret_cast<uint32_t*>(payload) = packed;
    payload[12] = tail;
}
__attribute__((noinline)) void StateAudioParameter_Commit_001D7C08(
    uint8_t* descriptor, const uint8_t* payload, float scalar) {
    descriptor[0] = 0x49;
    *reinterpret_cast<const uint8_t**>(descriptor + 8) = payload;
    *reinterpret_cast<uint32_t*>(descriptor + 0x10) =
        *reinterpret_cast<const uint32_t*>(payload + 4);
    uint8_t flags = descriptor[0x18];
    flags = payload[9] == 0 ? static_cast<uint8_t>(flags & ~1u)
                            : static_cast<uint8_t>(flags | 1u);
    flags = static_cast<uint8_t>((flags & ~2u) | ((payload[0xc] & 1u) << 1));
    descriptor[0x18] = flags;
    *reinterpret_cast<float*>(descriptor + 0xc) = 0.0f;
    *reinterpret_cast<float*>(descriptor + 0x14) = scalar;
}
__attribute__((noinline)) void BattleObject_BuildTransitionResourcePayload_001AB62C(
    void* object, int mode) {
    uint8_t* bytes = static_cast<uint8_t*>(object);
    const int active = BattleStateTable_GetActiveIndex_001CF6EC(
        bytes + 0x118, mode);
    uint8_t* config = *reinterpret_cast<uint8_t**>(bytes + 0x488);
    const float config_scalar = *reinterpret_cast<float*>(config + 0x824);
    uint8_t* state_entry = *reinterpret_cast<uint8_t**>(
        bytes + active * 0x14 + 0x1a8);
    void* key = BattleAudio_GetMenuBattleDollKey_001D60F4();
    void* node = OrderedTree_LowerBoundByPointer_004C5D3C(
        state_entry + 0x1a4, key);
    void* payload_owner = node == 0
                              ? 0
                              : *reinterpret_cast<void**>(node);
    void* sentinel = *reinterpret_cast<void**>(state_entry + 0x1a8);
    if (payload_owner == sentinel) {
        payload_owner = 0;
    } else if (payload_owner != 0) {
        payload_owner = *reinterpret_cast<void**>(node);
    }
    uint8_t parameter[13] = {0};
    StateAudioParameter_Init_001CFE94(parameter);
    const uint32_t word = *reinterpret_cast<uint32_t*>(config + 0x81e);
    const uint32_t packed = (word >> 24) | ((word >> 8) & 0xff00u) |
                                 ((word << 8) & 0xff0000u) | (word << 24) |
                                 0xffu;
    StateAudioParameter_SetConfig_001CFE60(
        parameter, config[0x821], 0, config[0x822], config[0x823], packed, 0,
        config_scalar);
    Engine_BulkCopy_00425DF8(
        static_cast<uint8_t*>(payload_owner) + 0x14c, parameter, 13);
    StateAudioParameter_Commit_001D7C08(
        static_cast<uint8_t*>(payload_owner) + 0xbc,
        static_cast<uint8_t*>(payload_owner) + 0x14c,
        1.0f);
}
__attribute__((noinline)) void BattleObject_BuildResourceAndSoundNames_001D6F88(
    void* object) {
    uint8_t* bytes = static_cast<uint8_t*>(object);
    uint8_t* config = *reinterpret_cast<uint8_t**>(bytes + 0x488);
    uint8_t index_text[0x20] = {0};
    uint8_t dynamic_name[0x20] = {0};
    uint8_t parameter_name[0x20] = {0};
    uint8_t target_name[0x20];
    uint8_t parameter_index_text[0x20] = {0};
    uint8_t vector[0x10] = {0};
    const void* kDecimal = reinterpret_cast<const void*>(0x00CA1588);
    const void* kStringIndex = reinterpret_cast<const void*>(0x00CA1594);
    const void* kNamedIndex = reinterpret_cast<const void*>(0x001D7464);
    const void* kDynamic00 = reinterpret_cast<const void*>(0x001D736C);
    const void* kMat0 = reinterpret_cast<const void*>(0x001D7394);
    const void* kDynamic10 = reinterpret_cast<const void*>(0x001D739C);
    const void* kStringIndexInline =
        reinterpret_cast<const void*>(0x001D738C);
    for (int index = 0; index != 2; ++index) {
        const uint32_t handle = *reinterpret_cast<uint32_t*>(
            bytes + (index == 0 ? 0x21c : 0x220));
        void* node = OrderedTree_LowerBoundByPointer_004C5D3C(
            reinterpret_cast<void*>(static_cast<uintptr_t>(handle) +
                                    0x1a8),
            EffectResource_GetKey_002A18B8());
        uint8_t* record = node == 0 ? 0
                                       : *reinterpret_cast<uint8_t**>(node);
        uint8_t* sentinel = *reinterpret_cast<uint8_t**>(
            static_cast<uint8_t*>(reinterpret_cast<void*>(
                static_cast<uintptr_t>(handle))) +
            0x1a8);
        if (record == sentinel)
            record = 0;
        const int state_value = BattleStateTable_GetSignedHalfword08_00205E08(
            bytes + 0x118, index);
        if (ParameterString_Format_002B3F78(
                index_text, sizeof(index_text), kDecimal, 0) == 1) {
            ParameterString_Format_002B3F78(
                dynamic_name, sizeof(dynamic_name), kNamedIndex, kDynamic00,
                0, 0);
        } else {
            ParameterString_Format_002B3F78(
                dynamic_name, sizeof(dynamic_name), kStringIndex, kDynamic00,
                0);
        }
        ParameterString_Format_002B3F78(
            parameter_name, sizeof(parameter_name), kStringIndexInline,
            *reinterpret_cast<uint32_t*>(config + 0x7c4), index);
        if (state_value != -1) {
            if (ParameterString_Format_002B3F78(
                    index_text, sizeof(index_text), kDecimal,
                    state_value) == 1) {
                ParameterString_Format_002B3F78(
                    target_name, sizeof(target_name), kNamedIndex,
                    kDynamic00, 0, state_value);
            } else {
                ParameterString_Format_002B3F78(
                    target_name, sizeof(target_name), kStringIndex,
                    kDynamic00, state_value);
            }
        }
        ResourceParameter_RegisterPair_002EC6FC(
            *reinterpret_cast<void**>(record + 0x20), handle,
            dynamic_name, parameter_name, target_name, 1);
        const int vector_index = state_value;
        const uint8_t* vector_source = config +
            (vector_index == 0 ? 0x828 :
             vector_index == 1 ? 0x834 :
             vector_index == 2 ? 0x840 :
             vector_index == 3 ? 0x84c :
             vector_index == 4 ? 0x858 :
             vector_index == 5 ? 0x864 :
             vector_index == 6 ? 0x870 :
             vector_index == 7 ? 0x87c :
             vector_index == 8 ? 0x888 :
             vector_index == 9 ? 0x894 : 0x8a0);
        for (int component = 0; component != 3; ++component)
            *reinterpret_cast<uint32_t*>(vector + component * 4) =
                *reinterpret_cast<const uint32_t*>(vector_source +
                                                        component * 4);
        *reinterpret_cast<float*>(vector + 0x0c) = 1.0f;
        ParameterString_Format_002B3F78(
            parameter_name, sizeof(parameter_name), kStringIndexInline, kMat0,
            *reinterpret_cast<uint32_t*>(config + 0x7f0), index);
        ResourceParameter_ApplyVectorUpdate_0020A93C(
            object, handle, parameter_name, vector);
        const int parameter_index =
            BattleStateTable_GetSignedByte0_00205DF0(bytes + 0x118, index);
        if (ParameterString_Format_002B3F78(
                parameter_index_text, sizeof(parameter_index_text), kDecimal,
                0) == 1) {
            ParameterString_Format_002B3F78(
                dynamic_name, sizeof(dynamic_name), kNamedIndex, kDynamic10,
                0, 0);
        } else {
            ParameterString_Format_002B3F78(
                dynamic_name, sizeof(dynamic_name), kStringIndex, kDynamic10,
                0);
        }
        if (parameter_index != -1) {
            if (ParameterString_Format_002B3F78(
                    parameter_index_text, sizeof(parameter_index_text),
                    kDecimal, parameter_index) == 1) {
                ParameterString_Format_002B3F78(
                    target_name, sizeof(target_name), kNamedIndex, kDynamic10,
                    0, parameter_index);
            } else {
                ParameterString_Format_002B3F78(
                    target_name, sizeof(target_name), kStringIndex, kDynamic10,
                    parameter_index);
            }
        }
        ParameterString_Format_002B3F78(
            parameter_name, sizeof(parameter_name), kStringIndexInline,
            *reinterpret_cast<uint32_t*>(config + 0x7f0), index);
        ResourceParameter_RegisterPair_002EC6FC(
            *reinterpret_cast<void**>(record + 0x20), handle,
            dynamic_name, parameter_name, target_name, 1);
        BattleObject_ResetAction_0020AB6C(object, handle, index, state_value,
                                           0);
    }
    BattleState_ApplyResourceScale_001D6CCC(object, 1.0f);
    BattleObject_SetTransition_001D6954(object, 0, 1, 1.0f);
    BattleObject_SetTransition_001D6954(object, 1, 1, 1.0f);
    BattleObject_SetTransition_001D6954(object, 0, 0, 1.0f);
    BattleObject_SetTransition_001D6954(object, 1, 0, 1.0f);
}
static void PitSound_RegisterActionPairs_00192A70(
    uint32_t handle, const void* first_name,
    const void* first_source, const void* first_target,
    const void* second_name, const void* second_source,
    const void* second_target, const void* third_name,
    const void* third_source, const void* third_target,
    const void* fourth_name, const void* fourth_source,
    const void* fourth_target) {
    uint8_t* entry = static_cast<uint8_t*>(
        ResourceTree_ResolveCurrentEntry_002A6268(handle));
    void* owner = *reinterpret_cast<void**>(entry + 0x20);
    ResourceParameter_RegisterPair_002EC6FC(
        owner, handle, const_cast<void*>(first_name),
        const_cast<void*>(first_source), const_cast<void*>(first_target), 1);
    ResourceParameter_RegisterPair_002EC6FC(
        owner, handle, const_cast<void*>(second_name),
        const_cast<void*>(second_source), const_cast<void*>(second_target), 1);
    ResourceParameter_RegisterPair_002EC6FC(
        owner, handle, const_cast<void*>(third_name),
        const_cast<void*>(third_source), const_cast<void*>(third_target), 1);
    ResourceParameter_RegisterPair_002EC6FC(
        owner, handle, const_cast<void*>(fourth_name),
        const_cast<void*>(fourth_source), const_cast<void*>(fourth_target), 1);
}
__attribute__((noinline)) void* PitSound_ConfigureResourcesAndActions_00192A70(void* object) {
    uint8_t* bytes = static_cast<uint8_t*>(object);
    uint8_t* actor = *reinterpret_cast<uint8_t**>(bytes + 0x34);
    const int state = *reinterpret_cast<int16_t*>(bytes + 0x120);
    const void* const kDynamic00 = reinterpret_cast<const void*>(0x00192DC0);
    const void* const kDynamic01 = reinterpret_cast<const void*>(0x00192DD8);
    const void* const kDynamic02 = reinterpret_cast<const void*>(0x00192DF0);
    const void* const kDynamic03 = reinterpret_cast<const void*>(0x00192DFC);
    const void* const kDynamic00Source =
        reinterpret_cast<const void*>(0x00192DBC);
    const void* const kPitHead = reinterpret_cast<const void*>(0x00192DCC);
    const void* const kPitEye = reinterpret_cast<const void*>(0x00192DE4);
    const void* const kDynamic00Target =
        reinterpret_cast<const void*>(0x00192E08);
    const void* const kPitHeadTarget =
        reinterpret_cast<const void*>(0x00192E10);
    const void* const kPitEyeTarget =
        reinterpret_cast<const void*>(0x00192E1C);
    if (state == 2) {
        const uint32_t handle = *reinterpret_cast<uint32_t*>(bytes + 0xf0);
        BattleSound_ActivateHandle(handle, 0);
        uint8_t* resource = reinterpret_cast<uint8_t*>(
            static_cast<uintptr_t>(handle));
        *reinterpret_cast<uint32_t*>(resource + 0x74) =
            *reinterpret_cast<uint32_t*>(actor + 0x1d0);
        *reinterpret_cast<uint32_t*>(resource + 0x78) =
            *reinterpret_cast<uint32_t*>(actor + 0x1d4);
        *reinterpret_cast<uint32_t*>(resource + 0x7c) =
            *reinterpret_cast<uint32_t*>(actor + 0x1d8);
        *reinterpret_cast<uint32_t*>(resource + 0x60) =
            *reinterpret_cast<uint32_t*>(actor + 0x1dc);
        PitSound_RegisterActionPairs_00192A70(
            handle, kDynamic00, kDynamic00Source, kDynamic00Target,
            kDynamic01, kPitHead, kPitHeadTarget, kDynamic02, kPitEye,
            kPitEyeTarget, kDynamic03, kPitEye, kPitEyeTarget);
        const uint32_t secondary = *reinterpret_cast<uint32_t*>(bytes + 0xf4);
        BattleSound_ActivateHandle(secondary, 1);
        BattleSound_PlayAction(bytes, handle, 0x108);
        return reinterpret_cast<void*>(static_cast<uintptr_t>(handle));
    }
    const uint32_t primary = *reinterpret_cast<uint32_t*>(bytes + 0xf4);
    if (state != 800) {
        BattleSound_ActivateHandle(primary, 1);
        const uint32_t handle = *reinterpret_cast<uint32_t*>(bytes + 0xf0);
        BattleSound_ActivateHandle(handle, 0);
        uint8_t* resource = reinterpret_cast<uint8_t*>(
            static_cast<uintptr_t>(handle));
        for (int i = 0; i != 4; ++i)
            *reinterpret_cast<uint32_t*>(resource + (i == 3 ? 0x60 :
                0x74 + i * 4)) =
                *reinterpret_cast<uint32_t*>(actor + 0x1d0 + i * 4);
        PitSound_RegisterActionPairs_00192A70(
            handle, kDynamic00, kDynamic00Source, kDynamic00Source,
            kDynamic01, kPitHead, kPitHead, kDynamic02, kPitEye, kPitEye,
            kDynamic03, kPitEye, kPitEye);
        BattleSound_PlayAction(bytes, handle, 0x108);
        return reinterpret_cast<void*>(static_cast<uintptr_t>(handle));
    }
    const uint32_t handle = primary;
    BattleSound_ActivateHandle(handle, 0);
    uint8_t* resource = reinterpret_cast<uint8_t*>(
        static_cast<uintptr_t>(handle));
    for (int i = 0; i != 4; ++i)
        *reinterpret_cast<uint32_t*>(resource + (i == 3 ? 0x60 :
            0x74 + i * 4)) =
            *reinterpret_cast<uint32_t*>(actor + 0x1e0 + i * 4);
    BattleSound_ActivateHandle(*reinterpret_cast<uint32_t*>(bytes + 0xf0), 1);
    BattleSound_PlayAction(bytes, handle, 0x10c);
    return reinterpret_cast<void*>(static_cast<uintptr_t>(handle));
}
static uint32_t MenuArBattleDoll_Hash_001D60F4(const char* text) {
    uint32_t hash = 0;
    for (const char* p = text; *p != '\0'; ++p) {
        const int32_t signed_byte = static_cast<int32_t>(
            static_cast<int8_t>(*p));
        hash ^= static_cast<uint32_t>(
            signed_byte + static_cast<int32_t>(hash * 0x40u) +
            static_cast<int32_t>(hash >> 2) +
            static_cast<int32_t>(0x9E3779B9u));
    }
    return hash;
}
__attribute__((noinline)) void* BattleAudio_GetMenuBattleDollKey_001D60F4() {
    uint32_t* guard = reinterpret_cast<uint32_t*>(0x00D47598);
    void** cached = reinterpret_cast<void**>(0x00D751FC);
    if ((*guard & 1u) != 0 || OnceGuard_TestAndSet_003B4FE4(guard) == 0)
        return *cached;
    const unsigned int kNodeAddress = 0x00D75200u;
    uint8_t* node = reinterpret_cast<uint8_t*>(kNodeAddress);
    uint32_t* record = reinterpret_cast<uint32_t*>(node + 0x14);
    const char* kName = reinterpret_cast<const char*>(0x001D6454);
    StateParameterRecord_Init_003B530C(record);
    record[0] = MenuArBattleDoll_Hash_001D60F4(kName);
    record[1] = reinterpret_cast<uintptr_t>(kName);
    *reinterpret_cast<uint32_t*>(node + 0x00) =
        reinterpret_cast<uintptr_t>(node);
    *reinterpret_cast<uint32_t*>(node + 0x04) =
        reinterpret_cast<uintptr_t>(node);
    *reinterpret_cast<uint32_t*>(node + 0x08) =
        reinterpret_cast<uintptr_t>(node);
    *reinterpret_cast<uint32_t*>(node + 0x0c) =
        reinterpret_cast<uintptr_t>(node);
    node[0x10] = 0;
    node[0x1d] = 0;
    node[0x20] = 0;
    record[3] = reinterpret_cast<uintptr_t>(kName);
    record[4] = 0x160;
    *reinterpret_cast<uint32_t*>(node + 0x00) =
        static_cast<uint32_t>(kNodeAddress - 4u);
    uint8_t** tree_slot = reinterpret_cast<uint8_t**>(0x00D63864);
    uint8_t* tree = *tree_slot;
    if (tree == 0) {
        tree = static_cast<uint8_t*>(
            OrderedTree_CreateSentinel_00449C68());
        *tree_slot = tree;
    }
    uint8_t* root = *reinterpret_cast<uint8_t**>(tree + 0x08);
    uint8_t* lower_bound = tree + 0x04;
    uint8_t* candidate = root;
    const uint32_t hash = record[0];
    while (candidate != 0 && candidate[0x10] != 0) {
        const uint32_t candidate_hash =
            *reinterpret_cast<uint32_t*>(candidate + 0x14);
        if (candidate_hash < hash) {
            candidate = *reinterpret_cast<uint8_t**>(candidate + 0x0c);
        } else {
            lower_bound = candidate;
            candidate = *reinterpret_cast<uint8_t**>(candidate + 0x08);
        }
    }
    uint8_t* successor = lower_bound;
    bool equal_name = false;
    const bool new_name_is_empty = kName[0] == '\0';
    while (successor != 0 && successor[0x10] != 0) {
        uint8_t* payload = *reinterpret_cast<uint8_t**>(successor);
        if (new_name_is_empty)
            equal_name =
                *reinterpret_cast<uint32_t*>(payload + 0x18) == hash;
        else
            equal_name = ParameterString_Equals_00425E6C(
                *reinterpret_cast<const char* const*>(payload + 0x1c),
                kName) == 0;
        if (equal_name) {
            *reinterpret_cast<uint8_t*>(payload + 0x20) = 0;
            break;
        }
        uint8_t* next = *reinterpret_cast<uint8_t**>(successor + 0x0c);
        if (next != 0 && next[0x10] != 0) {
            do {
                successor = next;
                next = *reinterpret_cast<uint8_t**>(successor + 0x08);
            } while (next != 0 && next[0x10] != 0);
            successor = next;
        } else {
            uint8_t* child = successor;
            uint8_t* parent = *reinterpret_cast<uint8_t**>(child + 0x04);
            while (parent != 0 && parent[0x10] != 0 &&
                   *reinterpret_cast<uint8_t**>(parent + 0x0c) == child) {
                child = parent;
                parent = *reinterpret_cast<uint8_t**>(child + 0x04);
            }
            successor = parent;
        }
    }
    if (!equal_name) {
        if (node[0x10] != 0) {
            uint8_t* replacement = *reinterpret_cast<uint8_t**>(node + 0x04);
            while (replacement != 0 && replacement[0x10] != 0) {
                replacement =
                    *reinterpret_cast<uint8_t**>(replacement + 0x04);
            }
            OrderedTree_UnlinkNode_003D40E0(
                reinterpret_cast<uintptr_t>(node),
                reinterpret_cast<uintptr_t>(replacement));
        }
        struct OrderedTreeSearchFrame {
            uint32_t pointer;
            uint8_t direction;
        } frame, next;
        uint8_t* parent = tree + 0x04;
        uint8_t* current = *reinterpret_cast<uint8_t**>(parent);
        frame.pointer = reinterpret_cast<uintptr_t>(parent);
        frame.direction = 1;
        while (current != 0 && current[0x10] != 0) {
            next.pointer = reinterpret_cast<uintptr_t>(current);
            if (hash < *reinterpret_cast<uint32_t*>(current + 0x14)) {
                next.direction = 1;
                OrderedTree_CopySearchFrame_00445CF4(&frame, &next);
                current = *reinterpret_cast<uint8_t**>(current + 0x08);
            } else {
                next.direction = 0;
                OrderedTree_CopySearchFrame_00445CF4(&frame, &next);
                current = *reinterpret_cast<uint8_t**>(current + 0x0c);
            }
        }
        OrderedTree_LinkInsertedNode_0043AFF8(
            frame.pointer, frame.direction,
            reinterpret_cast<uintptr_t>(node),
            reinterpret_cast<uintptr_t>(tree + 0x04));
    }
    *reinterpret_cast<const char**>(node + 0x20) = kName;
    node[0x1d] = 1;
    *reinterpret_cast<uint32_t*>(node - 4) = 0x00D0E39C;
    return *cached;
}

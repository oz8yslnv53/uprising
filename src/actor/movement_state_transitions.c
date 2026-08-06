#include <stdint.h>
extern void *FUN_003d92bc(void *state_machine);
extern void *OrderedTree_LowerBoundBySignedKey_00390A98(void *tree, int key);
extern int FUN_003714cc(void *entry);
extern void StateParameterRecord_Init_003B530C(uint32_t *record);
extern void *ActionGroup_SelectActionRecord_004216A0(void *group,
                                                       void *record);
extern int FUN_0051cbbc(void *action_tree);
extern void FUN_004e980c(void *owner, void *state_fields,
                         void *phase_state, void *frame_context, ...);
extern void FUN_004e5a5c(void *owner, int mode, int argument);
extern int FUN_004e6968(void *owner);
extern void Actor_PlayActionByHash(uint32_t actor, int channel,
                                   uint32_t *record, int enabled, int flags);
extern void FUN_004d0140(void *state_subobject, uint32_t actor);
extern void FUN_004e5950(float *out_vector, void *owner);
extern void StatusOwner_EventDispatch(uint32_t owner, int event);
extern void FUN_004bf390(void *owner, void *state, void *param3,
                         void *param4);
extern void Player_UpdateMoveOrientation(void *owner, void *state_fields,
                                         void *frame_context, int mode);
extern void FUN_005186e0(uint32_t actor, void *state_fields,
                         void *flags_owner);
extern void FUN_005328fc(void *state_subobject, uint32_t actor);
extern void FUN_004fd5ac(void *state_subobject);
extern void *FUN_004ef844(void *state);
extern int FUN_003b4fe4(void *once_guard);
extern void *Engine_LazyCallbackTableGetter_004EE830(void);
extern void *FUN_005109d0(void *actor, void *key);
extern void FUN_00517138(void *owner, void *state, float delta_time);
extern int Player_ConsumeDashEvent(void *player, void *context, void *input,
                                   int mode, void *optional_timer);
extern int StatusResource_ResolveAndCreate_004D2D0C(
    void *owner_context, void *descriptor, void *unused, void *link);
extern int StatusGate_AllThreeFlags_0051B664(void *flags);
extern void *Engine_LazySingletonGetter_0054EFA8(void);
extern void *MovementState_DeferredFactory_004C33CC(void);
extern void ActorThreat_BuildRelativeDirection_004EC31C(
    float *output, void *object, void *component_owner, unsigned full_normalize);
extern int FUN_004fcc90(void *flags_owner);
extern void *StWalk_Factory_004E9DF8(void);
extern void *ActorStateMachine_RequestStateByFactory(
    void *machine, void *factory_slot);
static const uint8_t *const kMovementThresholdRecord =
    (const uint8_t *)(uintptr_t)0x00d47f58u;
static uint32_t *const kMovementCounter =
    (uint32_t *)(uintptr_t)0x00d6365cu;
static const uint32_t kMovementCounterCap = 0x3b9ac9ffu;
static const float kMovementVectorScale = 0.3f;
static const float kMovementWalkThreshold = 25.0f;
static const uint8_t *const kMovementWalkVector =
    (const uint8_t *)(uintptr_t)0x00dc249cu;
static const float *const kMovementDirectionQuatA =
    (const float *)(uintptr_t)0x00dc2538u;
static const float *const kMovementDirectionQuatB =
    (const float *)(uintptr_t)0x00dc2558u;
static const float kMovementDirectionPoleThreshold = 0.99999f;
static const float *const kMovementFinalStateValueKey =
    (const float *)(uintptr_t)0x004bf020u;
static uint32_t *const kMovementCallbackOnceGuard =
    (uint32_t *)(uintptr_t)0x00d639b0u;
static void **const kMovementCallbackTableSlot =
    (void **)(uintptr_t)0x00d639b4u;
static uint32_t *const kMovementCallbackPriority =
    (uint32_t *)(uintptr_t)0x00d6c9b8u;
typedef void *(*MovementCallbackListBegin)(void *list);
__attribute__((noinline)) uint32_t MovementState_RefreshCallbackGate_004BE31C(
    uint8_t *owner, void *param2, void *param3, void *param4)
{
    uint8_t *flags;
    uint8_t *descriptor;
    void *node;
    void *table;
    void *sentinel = (void *)kMovementCallbackTableSlot;
    FUN_004bf390(owner, param2, param3, param4);
    flags = *(uint8_t **)(owner + 0x38);
    if ((*(uint32_t *)(flags + 0x98) & 0x100u) == 0u) {
        *(uint32_t *)(flags + 0x94) &= ~0x400u;
        *(uint32_t *)(flags + 0x94) &= ~0x8000u;
    }
    descriptor = *(uint8_t **)(*(uint8_t **)(owner + 0x30) + 0x16c);
    if (*(float *)(owner + 0xcc) < 0.0f) {
        if (descriptor != 0 && *(uint32_t *)(descriptor + 0x8) ==
            *kMovementCallbackPriority) {
            if ((*kMovementCallbackOnceGuard & 1u) == 0u &&
                FUN_003b4fe4(kMovementCallbackOnceGuard) != 0) {
                table = Engine_LazyCallbackTableGetter_004EE830();
                *kMovementCallbackTableSlot = table;
            }
            node = (*(MovementCallbackListBegin *)(*(uintptr_t *)descriptor))
                (descriptor);
            while (node != 0) {
                if (node == sentinel) {
                    if (*(uint8_t *)(descriptor + 0x74) == 0u)
                        return 0;
                    break;
                }
                node = *(void **)node;
            }
        }
        *(float *)(owner + 0xcc) = 0.0f;
    }
    return 0;
}
__attribute__((noinline)) uint32_t MovementState_UpdateWalkTransition_004BEA48(
    uint8_t *owner, uint8_t *state, void *unused, uint8_t *frame_context)
{
    void *actor = *(void **)(owner + 0x30);
    void *entry = OrderedTree_LowerBoundBySignedKey_00390A98(
        FUN_003d92bc(actor), 1);
    void *component;
    void *factory;
    uint8_t *walk;
    float delta_time = *(float *)(frame_context + 0x0c);
    (void)unused;
    if (*(float *)(state + 0x38) <= 0.0f) {
        component = FUN_005109d0(actor, (void *)(uintptr_t)0x004bebc4u);
        if (component != 0) {
            *(float *)(state + 0x34) +=
                *(float *)((uint8_t *)component + 0x8c) * delta_time;
            if (*(float *)(state + 0x34) > kMovementWalkThreshold)
                *(float *)(state + 0x34) = kMovementWalkThreshold;
        }
    } else {
        *(float *)(state + 0x38) -= delta_time;
    }
    *(uint32_t *)(owner + 0x54) = *(const uint32_t *)(kMovementWalkVector + 0);
    *(uint32_t *)(owner + 0x58) = *(const uint32_t *)(kMovementWalkVector + 4);
    *(uint32_t *)(owner + 0x5c) = *(const uint32_t *)(kMovementWalkVector + 8);
    if (owner[0x107] == 0u)
        FUN_00517138(owner, state, delta_time);
    if (FUN_003714cc(entry) != 0 &&
        (*(uint32_t *)(*(uint8_t **)(owner + 0x38) + 0x98) & 0x100u) == 0u) {
        factory = StWalk_Factory_004E9DF8();
        walk = ActorStateMachine_RequestStateByFactory(actor, &factory);
        walk[0x9c] |= 4u;
        if (state[0x3c] == 0u) {
            *(uint32_t *)(owner + 0x60) = *(uint32_t *)(owner + 0x54);
            *(uint32_t *)(owner + 0x64) = *(uint32_t *)(owner + 0x58);
            *(uint32_t *)(owner + 0x68) = *(uint32_t *)(owner + 0x5c);
        }
        *(uint32_t *)(owner + 0x54) = *(const uint32_t *)(kMovementWalkVector + 0);
        *(uint32_t *)(owner + 0x58) = *(const uint32_t *)(kMovementWalkVector + 4);
        *(uint32_t *)(owner + 0x5c) = *(const uint32_t *)(kMovementWalkVector + 8);
        walk[0xe4] |= 0x10u;
    }
    return 0;
}
__attribute__((noinline)) uint32_t MovementState_DashAndDirectionUpdate_004BEC7C(
    uint8_t *owner, uint8_t *state, uint8_t *phase_state,
    uint8_t *frame_context)
{
    uint8_t phase;
    uint8_t *phase_object;
    uint8_t *flags = *(uint8_t **)(owner + 0x38);
    void *actor = *(void **)(owner + 0x30);
    phase = phase_state[0x2c];
    if (phase < 2u)
        phase = 1u;
    phase_state[0x2c] = phase;
    phase_object = *(uint8_t **)(phase_state + 0x30);
    if (phase_object[0x12] != 0u) {
        Player_ConsumeDashEvent(owner, state + 0x0c, phase_state, 1, 0);
        if (*(float *)(state + 0xb4) <
            *(float *)(*(uint8_t **)(uintptr_t)0x00d47f58u + 0x44))
            state[0xb8] |= 4u;
    }
    if (phase_object[0x11] != 0u) {
        if ((*(uint32_t *)(flags + 0x98) & 0x100u) == 0u)
            *(uint32_t *)(flags + 0x94) &= ~0x8000u;
        void **cache = (void **)(uintptr_t)0x00d63578u;
        if (*cache == 0)
            *cache = Engine_LazySingletonGetter_0054EFA8();
        if (StatusResource_ResolveAndCreate_004D2D0C(
                *cache, actor, phase_state, frame_context) == 0) {
            if ((*(uint32_t *)(flags + 0x98) & 0x100u) == 0u)
                *(uint32_t *)(flags + 0x94) &= ~0x8000u;
            if (owner[0x10b] != 0u ||
                (StatusGate_AllThreeFlags_0051B664(flags) != 0 &&
                 (*(uint32_t *)(flags + 0x98) & 0x00400040u) == 0u)) {
                void *factory = MovementState_DeferredFactory_004C33CC();
                uint8_t *next = ActorStateMachine_RequestStateByFactory(
                    actor, &factory);
                uint8_t *params = *(uint8_t **)(owner + 0x34);
                uint32_t record[3];
                StateParameterRecord_Init_003B530C(record);
                record[0] = *(uint32_t *)(params + 0x8d8);
                record[1] = *(uint32_t *)(params + 0x8dc);
                *(uint32_t *)(next + 0x0c) = record[0];
                *(uint32_t *)(next + 0x10) = record[1];
                next[0x54] = (uint8_t)((next[0x54] & ~1u) | 8u);
                {
                    float direction[3];
                    float x;
                    float y;
                    float z;
                    float q0;
                    float q1;
                    float q2;
                    float q3;
                    ActorThreat_BuildRelativeDirection_004EC31C(
                        direction, actor, flags, 0u);
                    x = direction[0];
                    y = direction[1];
                    z = direction[2];
                    if ((z < 0.0f ? -z : z) >
                        kMovementDirectionPoleThreshold) {
                        const float *pole = z <= 0.0f
                            ? kMovementDirectionQuatB
                            : kMovementDirectionQuatA;
                        q0 = pole[0];
                        q1 = pole[1];
                        q2 = pole[2];
                        q3 = pole[3];
                    } else {
                        float scale = 1.0f /
                            __builtin_sqrtf(2.0f + z * 2.0f);
                        q0 = -(y * scale);
                        q1 = x * scale;
                        q2 = 0.0f;
                        q3 = (2.0f + z * 2.0f) * 0.5f * scale;
                    }
                    *(float *)(actor + 0x64) = q0;
                    *(float *)(actor + 0x68) = q1;
                    *(float *)(actor + 0x6c) = q2;
                    *(float *)(actor + 0x70) = q3;
                    *(uint32_t *)(owner + 0x54) =
                        *(const uint32_t *)(kMovementWalkVector + 0);
                    *(uint32_t *)(owner + 0x58) =
                        *(const uint32_t *)(kMovementWalkVector + 4);
                    *(uint32_t *)(owner + 0x5c) =
                        *(const uint32_t *)(kMovementWalkVector + 8);
                    *(uint32_t *)(owner + 0x48) =
                        *(const uint32_t *)(kMovementWalkVector + 0);
                    *(uint32_t *)(owner + 0x4c) =
                        *(const uint32_t *)(kMovementWalkVector + 4);
                    *(uint32_t *)(owner + 0x50) =
                        *(const uint32_t *)(kMovementWalkVector + 8);
                }
            }
        }
    }
    phase = phase_state[0x2c];
    if (phase < 2u)
        phase = 1u;
    phase_state[0x2c] = phase;
    if (phase_state[0x2d] != 0u) {
        float x;
        float y;
        float z;
        float length_squared;
        FUN_004e980c(owner, state + 0x0c, phase_state, frame_context);
        if ((state[0xb8] & 1u) == 0u) {
            x = *(float *)(owner + 0x48);
            y = *(float *)(owner + 0x4c);
            z = *(float *)(owner + 0x50);
            length_squared = x * x + y * y + z * z;
            if (length_squared <= 0.0f) {
                const uint8_t *orientation = *(const uint8_t **)(owner + 0x30);
                float q0 = *(const float *)(orientation + 0x64);
                float q1 = *(const float *)(orientation + 0x68);
                float q2 = *(const float *)(orientation + 0x6c);
                float q3 = *(const float *)(orientation + 0x70);
                *(float *)(state + 0x30) = 2.0f * (q0 * q2 + q1 * q3);
                *(float *)(state + 0x34) = 2.0f * (q1 * q2 - q0 * q3);
                *(float *)(state + 0x38) =
                    (q2 * q2 + q3 * q3) - (q0 * q0 + q1 * q1);
            } else {
                float scale = 1.0f / __builtin_sqrtf(length_squared);
                *(float *)(state + 0x30) = x * scale;
                *(float *)(state + 0x34) = y * scale;
                *(float *)(state + 0x38) = z * scale;
            }
        }
    }
    {
        void *component = FUN_005109d0(
            actor, (void *)(uintptr_t)kMovementFinalStateValueKey);
        if (component != 0)
            *(uint32_t *)(state + 0x24) =
                *(uint32_t *)((uint8_t *)component + 0x74);
    }
    return 0;
}
static int MovementState_ActionMatches(void *tree, uint32_t *key)
{
    void *selected;
    if (*(uint32_t *)((uint8_t *)tree + 0x2c) == 0u)
        return FUN_0051cbbc(tree) != 0;
    selected = ActionGroup_SelectActionRecord_004216A0(
        *(void **)((uint8_t *)tree + 0x18), key);
    return *(void **)((uint8_t *)tree + 0x2c) != 0 &&
           *(void **)((uint8_t *)tree + 0x2c) == selected;
}
static void MovementState_CopyWalkParams(uint8_t *walk, uint8_t *params)
{
    uint32_t record[3];
    StateParameterRecord_Init_003B530C(record);
    record[0] = *(uint32_t *)(params + 0x6c);
    record[1] = *(uint32_t *)(params + 0x70);
    *(uint32_t *)(walk + 0xfc) = record[0];
    *(uint32_t *)(walk + 0x100) = record[1];
}
__attribute__((noinline)) uint32_t MovementState_UpdateActionAndTransition_004BE4BC(
    uint8_t *owner, uint8_t *state, void *unused, uint8_t *frame_context)
{
    void *actor = *(void **)(owner + 0x30);
    uint8_t *flags = *(uint8_t **)(owner + 0x38);
    uint8_t *params = *(uint8_t **)(owner + 0x34);
    void *tree;
    uint32_t key[3];
    void *factory;
    uint8_t *walk;
    void *record;
    (void)unused;
    tree = OrderedTree_LowerBoundBySignedKey_00390A98(
        FUN_003d92bc(actor), 1);
    if ((*(uint32_t *)(flags + 0x98) & 0x8000u) != 0u &&
        (*(uint32_t *)(flags + 0x94) & 0x400u) == 0u &&
        (*(uint32_t *)(flags + 0x98) & 0x100u) != 0u)
        return 0;
    Player_UpdateMoveOrientation(owner, state + 0x10, frame_context, 0);
    if ((*(uint32_t *)(flags + 0x98) & 0x100u) == 0u) {
        if (*(float *)(state + 0x28) == 0.0f)
            *(uint32_t *)(flags + 0x94) |= 0x400u;
        else
            *(uint32_t *)(flags + 0x94) &= ~0x400u;
    }
    StateParameterRecord_Init_003B530C(key);
    key[0] = *(uint32_t *)(params + 0x574);
    key[1] = *(uint32_t *)(params + 0x578);
    if (MovementState_ActionMatches(tree, key)) {
        if ((*(uint32_t *)(flags + 0x94) & 0x400u) != 0u) {
            FUN_004fd5ac(state + 0x70);
            Actor_PlayActionByHash((uint32_t)actor, 1,
                                   key, 1, 1);
        } else {
            if (*(float *)(state + 0x28) < 25.0f &&
                (*(uint32_t *)(flags + 0x98) & 0x100u) != 0u)
                *(float *)(state + 0x28) = 25.0f;
            FUN_005186e0((uint32_t)actor, state + 0x10, flags);
            FUN_005328fc(state + 0x70, (uint32_t)actor);
        }
    }
    StateParameterRecord_Init_003B530C(key);
    key[0] = *(uint32_t *)(params + 0x590);
    key[1] = *(uint32_t *)(params + 0x594);
    if (MovementState_ActionMatches(tree, key) &&
        *(float *)(state + 0xb4) <= 0.0f) {
        record = FUN_004ef844(state);
        if (record != 0)
            *(float *)((uint8_t *)record + 0x20) = 0.0f;
        *(uint32_t *)(owner + 0xcc) = *(uint32_t *)(owner + 0xd0);
        if ((*(uint32_t *)(flags + 0x98) & 0x100u) == 0u) {
            factory = StWalk_Factory_004E9DF8();
            walk = ActorStateMachine_RequestStateByFactory(actor, &factory);
            MovementState_CopyWalkParams(walk, params);
        }
    }
    if (owner[0x108] != 0u) {
        factory = StWalk_Factory_004E9DF8();
        walk = ActorStateMachine_RequestStateByFactory(actor, &factory);
        MovementState_CopyWalkParams(walk, params);
        *(uint32_t *)(owner + 0xcc) = *(uint32_t *)(owner + 0xd0);
    }
    StateParameterRecord_Init_003B530C(key);
    key[0] = *(uint32_t *)(params + 0x590);
    key[1] = *(uint32_t *)(params + 0x594);
    if (MovementState_ActionMatches(tree, key) &&
        *(float *)(state + 0xb4) > 0.0f)
        *(float *)(state + 0xb4) -= *(float *)(frame_context + 0x0c);
    return 0;
}
__attribute__((noinline)) uint32_t MovementState_DispatchEventAndUpdate_004BE858(
    uint8_t *owner, uint8_t *state, void *param3, void *param4)
{
    if (state[0x3c] != 0u)
        StatusOwner_EventDispatch(*(uint32_t *)(owner + 0x30), 1);
    FUN_004bf390(owner, state, param3, param4);
    return 0;
}
__attribute__((noinline)) uint32_t MovementState_EnterAction_004BE444(uint8_t *owner, uint8_t *state)
{
    uint32_t action_record[3];
    uint8_t *params = *(uint8_t **)(owner + 0x34);
    uint32_t actor = *(uint32_t *)(owner + 0x30);
    StateParameterRecord_Init_003B530C(action_record);
    action_record[0] = *(uint32_t *)(params + 0x574);
    action_record[1] = *(uint32_t *)(params + 0x578);
    Actor_PlayActionByHash(actor, 1, action_record, 0, 1);
    *(uint32_t *)(state + 0xb4) = *(uint32_t *)(params + 0xab8);
    FUN_004d0140(state + 0x70, actor);
    return 0;
}
__attribute__((noinline)) uint32_t MovementState_SampleDirection_004BEBD0(
    uint8_t *owner, uint8_t *state, uint8_t *phase_state)
{
    uint8_t phase = phase_state[0x2c];
    float sampled[3];
    if (phase < 2u)
        phase = 1u;
    phase_state[0x2c] = phase;
    if (phase_state[0x2d] != 0u) {
        if (state[0x54] == 2u && owner[0x10a] == 0u) {
            FUN_004e5950(sampled, owner);
            *(float *)(state + 0x74) = sampled[0];
            *(float *)(state + 0x78) = sampled[1];
            *(float *)(state + 0x7c) = sampled[2];
        }
        *(float *)(state + 0x74) *= kMovementVectorScale;
        *(float *)(state + 0x78) *= kMovementVectorScale;
        *(float *)(state + 0x7c) *= kMovementVectorScale;
    }
    return 0;
}
__attribute__((noinline)) uint32_t MovementState_PhaseThresholdCallback_004BE030(
    void *owner, uint8_t *state, uint8_t *phase_state)
{
    uint8_t phase;
    if (*(float *)(state + 0x44) <=
        *(const float *)(kMovementThresholdRecord + 0x58)) {
        phase = phase_state[0x2c];
        if (phase < 2u)
            phase = 1u;
        phase_state[0x2c] = phase;
        if (*(uint8_t *)(*(void **)(phase_state + 0x30) + 0x11) != 0)
            FUN_004e5a5c(owner, 1, 0);
    }
    return 0;
}
__attribute__((noinline)) uint32_t MovementState_StartActionAndAdvanceCounter_004BE08C(
    uint8_t *owner, uint8_t *state)
{
    uint32_t counter;
    FUN_004e6968(owner);
    Actor_PlayActionByHash(*(uint32_t *)(owner + 0x30), 1,
                           (uint32_t *)(state + 0x28), 1, 1);
    if ((*(uint32_t *)(*(uint8_t **)(owner + 0x38) + 0x98) & 0x100u) == 0u &&
        FUN_004fcc90(*(void **)(owner + 0x38)) == 0) {
        counter = *kMovementCounter;
        if (counter == 0u)
            counter = 0u;
        counter++;
        if (counter == 0u || counter > kMovementCounterCap)
            counter = kMovementCounterCap;
        *kMovementCounter = counter;
    }
    return 0;
}
__attribute__((noinline)) uint32_t MovementState_UpdateActionDirection_004BE1A4(
    uint8_t *owner, uint8_t *state, uint8_t *phase_state, void *frame_context)
{
    uint8_t phase;
    void *action_tree;
    uint32_t action_key[2];
    void *selected;
    int action_matches;
    phase = phase_state[0x2c];
    if (phase < 2u)
        phase = 1u;
    phase_state[0x2c] = phase;
    if (phase_state[0x2d] == 0u)
        return 0;
    action_tree = FUN_003d92bc(*(void **)(owner + 0x30));
    action_tree = OrderedTree_LowerBoundBySignedKey_00390A98(action_tree, 1);
    StateParameterRecord_Init_003B530C(action_key);
    action_key[0] = *(uint32_t *)(*(uint8_t **)(owner + 0x34) + 0x574);
    action_key[1] = *(uint32_t *)(*(uint8_t **)(owner + 0x34) + 0x578);
    if (*(uint32_t *)((uint8_t *)action_tree + 0x2c) == 0u) {
        action_matches = FUN_0051cbbc(action_tree) != 0;
    } else {
        selected = ActionGroup_SelectActionRecord_004216A0(
            *(void **)((uint8_t *)action_tree + 0x18), action_key);
        action_matches = *(void **)((uint8_t *)action_tree + 0x2c) != 0 &&
                         *(void **)((uint8_t *)action_tree + 0x2c) == selected;
    }
    FUN_004e980c(owner, state + 0x10, phase_state, frame_context, 1);
    if (action_matches)
        return 0;
    if (*(float *)(state + 0xb4) > 0.0f) {
        const uint8_t *orientation = *(const uint8_t **)(owner + 0x30);
        float q0 = *(const float *)(orientation + 0x64);
        float q1 = *(const float *)(orientation + 0x68);
        float q2 = *(const float *)(orientation + 0x6c);
        float q3 = *(const float *)(orientation + 0x70);
        *(float *)(state + 0x34) = 2.0f * (q0 * q2 + q1 * q3);
        *(float *)(state + 0x38) = 2.0f * (q1 * q2 - q0 * q3);
        *(float *)(state + 0x3c) =
            (q2 * q2 + q3 * q3) - (q0 * q0 + q1 * q1);
        *(float *)(state + 0x28) = 0.0f;
    }
    return 0;
}
__attribute__((noinline)) uint32_t MovementState_UpdateTimerAndReturnToWalk_004BE128(
    uint8_t *actor, uint8_t *state, void *unused, const uint8_t *frame_context)
{
    void *entry;
    void *factory;
    uint8_t *walk;
    (void)unused;
    *(float *)(state + 0x44) += *(const float *)(frame_context + 0x0c);
    entry = FUN_003d92bc(*(void **)(actor + 0x30));
    entry = OrderedTree_LowerBoundBySignedKey_00390A98(entry, 1);
    if (FUN_003714cc(entry) == 0 ||
        (*(uint32_t *)(*(uint8_t **)(actor + 0x38) + 0x98) & 0x100u) != 0)
        return 0;
    factory = StWalk_Factory_004E9DF8();
    walk = ActorStateMachine_RequestStateByFactory(
        *(void **)(actor + 0x30), &factory);
    walk[0xe4] |= 0x10u;
    return 0;
}

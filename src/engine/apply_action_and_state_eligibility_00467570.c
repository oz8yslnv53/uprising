#include <stdint.h>
extern void FUN_0049149C(void);
extern void Engine_ClearActorState_004C1110(void *actor, int value);
extern void Actor_PlayActionByHash(uint32_t actor, int channel,
                                   const void *record, int flags, int mode);
extern int ActorState_SpecialEligibilityPredicate(void *actor);
extern uint8_t *Engine_FindActorState_004EE634(void *actor);
__attribute__((noinline)) uint32_t
Engine_ApplyActionAndStateEligibility_00467570(void *object,
                                                uint8_t *action_record)
{
    uint8_t *actor = *(uint8_t **)((uint8_t *)object + 0x30u);
    FUN_0049149C();
    Engine_ClearActorState_004C1110(actor, 1);
    Actor_PlayActionByHash((uint32_t)(uintptr_t)actor, 1,
                           action_record + 0x3cu, 1, 1);
    if (ActorState_SpecialEligibilityPredicate(actor) == 0) {
        uint8_t *state = Engine_FindActorState_004EE634(actor);
        if (state != 0)
            state[0x21u] = 0u;
    }
    return 0u;
}

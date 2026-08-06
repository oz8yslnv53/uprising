#include <stdint.h>
extern void Engine_RefreshActorState_004E187C(void *object, void *record);
extern void Engine_ClearActorState_004C1110(void *actor, int value);
extern int ActorState_SpecialEligibilityPredicate(void *actor);
extern uint8_t *Engine_FindActorState_004EE634(void *actor);
__attribute__((noinline)) uint32_t
Engine_ResetActorStateEligibility_00467524(void *object)
{
    uint8_t *actor = *(uint8_t **)((uint8_t *)object + 0x30u);
    Engine_RefreshActorState_004E187C(object, actor + 0x64u);
    Engine_ClearActorState_004C1110(actor, 0);
    if (ActorState_SpecialEligibilityPredicate(actor) == 0) {
        uint8_t *state = Engine_FindActorState_004EE634(actor);
        if (state != 0)
            state[0x21u] = 1u;
    }
    return 0u;
}

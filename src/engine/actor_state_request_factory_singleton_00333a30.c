#include <stdint.h>
extern void *ActorStateFactory_GetSingleton_004E9D70(void);
extern void *ActorStateMachine_RequestStateByFactory(void *machine,
                                                      void *factory_slot);
__attribute__((noinline)) int ActorState_RequestFactorySingleton_00333A30(void *object)
{
    void *machine = *(void **)((uint8_t *)object + 0x30);
    void *factory = ActorStateFactory_GetSingleton_004E9D70();
    ActorStateMachine_RequestStateByFactory(machine, &factory);
    return 0;
}

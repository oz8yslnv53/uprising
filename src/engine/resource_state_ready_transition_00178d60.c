#include <stdint.h>
extern void FUN_002253E4(void *machine);
extern uint32_t CommandObject_IsReady_001F51B0(void *command);
extern void *StMenuBase_Factory_0022CC34(void);
extern void ActorStateMachine_RequestStateByFactory(void *machine,
                                                    void *factory_slot);
int FUN_00178D60(void *object, void *unused2, void *unused3, void *unused4)
{
    void *machine;
    void *factory;
    uint8_t *bytes = (uint8_t *)object;
    (void)unused2;
    (void)unused3;
    (void)unused4;
    FUN_002253E4(*(void **)(bytes + 0x30));
    if (CommandObject_IsReady_001F51B0(*(void **)(bytes + 0xec)) != 0) {
        machine = *(void **)(bytes + 0x30);
        factory = StMenuBase_Factory_0022CC34();
        ActorStateMachine_RequestStateByFactory(machine, &factory);
    }
    return 0;
}

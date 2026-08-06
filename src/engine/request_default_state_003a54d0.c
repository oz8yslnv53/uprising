#include <stdint.h>
int Engine_StateRequestGate_003CCA34(void);
uint32_t Engine_DefaultStateFactory_003A4984(void);
void ActorStateMachine_RequestStateByFactory(void *machine,
                                              void *factory_slot);
__attribute__((noinline)) uint32_t Engine_RequestDefaultState_003A54D0(uint8_t *object,
                                             uint32_t unused2,
                                             uint32_t unused3,
                                             uint32_t argument4)
{
    uint32_t factory;
    void *machine;
    (void)unused2;
    (void)unused3;
    if (Engine_StateRequestGate_003CCA34() == 0) {
        machine = *(void **)(object + 0x30);
        factory = Engine_DefaultStateFactory_003A4984();
        ActorStateMachine_RequestStateByFactory(machine, &factory);
        *(uint32_t *)(object + 0x48) = (uint32_t)-1;
    }
    (void)argument4;
    return 0;
}

#include <stdint.h>
extern void *StMenuDisappear_Factory_0028AADC(void);
extern void ActorStateMachine_RequestStateByFactory(void *machine,
                                                     void *factory_slot);
int Menu_RequestDisappearState_001CFEC4(void *object)
{
    void *machine = *(void **)((uint8_t *)object + 0x30);
    void *factory = StMenuDisappear_Factory_0028AADC();
    ActorStateMachine_RequestStateByFactory(machine, &factory);
    return 0;
}

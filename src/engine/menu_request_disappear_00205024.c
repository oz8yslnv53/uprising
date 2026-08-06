#include <stdint.h>
extern uint32_t StMenuDisappear_Factory_0028AADC(void);
extern void ActorStateMachine_RequestStateByFactory(void *state_machine,
                                                     void *factory);
int Menu_RequestDisappear_00205024(void *record, uint32_t unused2,
                                   uint32_t unused3, void *unused4)
    __attribute__((noinline));
__attribute__((noinline)) int Menu_RequestDisappear_00205024(void *record, uint32_t unused2,
                                   uint32_t unused3, void *unused4)
{
    void *state_machine = *(void **)((uint8_t *)record + 0x30);
    uint32_t factory;
    (void)unused2;
    (void)unused3;
    (void)unused4;
    factory = StMenuDisappear_Factory_0028AADC();
    ActorStateMachine_RequestStateByFactory(state_machine, &factory);
    return 0;
}

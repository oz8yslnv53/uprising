#include <stdint.h>
extern void *StMenuDisappear_Factory_0028AADC(void);
extern void *ActorStateMachine_RequestStateByFactory(void *machine,
                                                       void *factory_slot);
int Menu_RequestDisappearState_001D128C(
    void *object, uint32_t unused_1, void *selection, void *unused_3)
{
    uint8_t *bytes = (uint8_t *)object;
    void *machine = *(void **)(bytes + 0x30);
    void *factory = StMenuDisappear_Factory_0028AADC();
    void *state;
    (void)unused_1;
    (void)unused_3;
    state = ActorStateMachine_RequestStateByFactory(machine, &factory);
    if (*(uint8_t *)((uint8_t *)selection + 0x29) != 0)
        *(uint8_t *)((uint8_t *)state + 0x0c) = 1;
    return 0;
}

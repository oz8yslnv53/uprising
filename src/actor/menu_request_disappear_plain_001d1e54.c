#include <stdint.h>
extern void *StMenuDisappear_Factory_0028AADC(void);
extern void *ActorStateMachine_RequestStateByFactory(void *machine,
                                                       void *factory_slot);
int Menu_RequestDisappearPlain_001D1E54(
    void *object, uint32_t unused_1, uint32_t unused_2, void *unused_3)
{
    uint8_t *bytes = (uint8_t *)object;
    void *machine = *(void **)(bytes + 0x30);
    void *factory = StMenuDisappear_Factory_0028AADC();
    (void)unused_1;
    (void)unused_2;
    (void)unused_3;
    ActorStateMachine_RequestStateByFactory(machine, &factory);
    return 0;
}

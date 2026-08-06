#include <stdint.h>
extern void *StMenuStay_Factory_0022CCBC(void);
extern void ActorStateMachine_RequestStateByFactory(void *machine,
                                                     void *factory_slot);
int Menu_RequestStayState_001D0520(
    void *object, uint32_t unused_1, uint32_t unused_2, void *unused_3)
{
    void *machine = *(void **)((uint8_t *)object + 0x30);
    void *factory = StMenuStay_Factory_0022CCBC();
    (void)unused_1;
    (void)unused_2;
    (void)unused_3;
    ActorStateMachine_RequestStateByFactory(machine, &factory);
    return 0;
}

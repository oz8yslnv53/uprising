#include <stdint.h>
extern void *StMenuDisappear_Factory_0028AADC(void);
extern void *ActorStateMachine_RequestStateByFactory(void *machine,
                                                      void *factory_slot);
__attribute__((noinline)) int Menu_RequestDisappear_00202CCC(
    void *object, void *unused1, void *unused2, void *unused3)
{
    void *machine = *(void **)((uint8_t *)object + 0x30u);
    void *factory = StMenuDisappear_Factory_0028AADC();
    (void)unused1;
    (void)unused2;
    (void)unused3;
    ActorStateMachine_RequestStateByFactory(machine, &factory);
    return 0;
}

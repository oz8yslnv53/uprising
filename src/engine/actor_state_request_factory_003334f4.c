#include <stdint.h>
extern void *Engine_LazyFactoryDescriptor_004BFB7C(void);
extern void *ActorStateMachine_RequestStateByFactory(void *machine,
                                                     void *factory_slot);
__attribute__((noinline)) int ActorState_RequestFactory_003334F4(void *context, void *unused1,
                                       void *unused2, void *unused3)
{
    void *machine = *(void **)((uint8_t *)context + 0x30u);
    void *factory = Engine_LazyFactoryDescriptor_004BFB7C();
    (void)unused1;
    (void)unused2;
    (void)unused3;
    ActorStateMachine_RequestStateByFactory(machine, &factory);
    return 0;
}

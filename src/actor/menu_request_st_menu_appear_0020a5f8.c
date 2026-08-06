#include <stdint.h>
extern void *StMenuAppear_Factory_00234A94(void);
extern void ActorStateMachine_RequestStateByFactory(void *machine,
                                                    void *factory);
__attribute__((noinline)) int Menu_RequestStMenuAppear_0020A5F8(void *object)
{
    void *machine = *(void **)((uint8_t *)object + 0x30u);
    void *factory = StMenuAppear_Factory_00234A94();
    ActorStateMachine_RequestStateByFactory(machine, &factory);
    return 0;
}
extern void *StMenuForcus_Factory_0027D058(void);
__attribute__((noinline)) int Menu_RequestStMenuForcus_001825FC(
    void *object, void *unused1, void *unused2, void *unused3)
{
    void *machine = *(void **)((uint8_t *)object + 0x30u);
    void *factory = StMenuForcus_Factory_0027D058();
    (void)unused1;
    (void)unused2;
    (void)unused3;
    ActorStateMachine_RequestStateByFactory(machine, &factory);
    return 0;
}
__attribute__((noinline)) int Menu_RequestStMenuAppear_001A506C(
    void *object, void *unused1, void *unused2, void *unused3)
{
    void *machine = *(void **)((uint8_t *)object + 0x30u);
    void *factory = StMenuAppear_Factory_00234A94();
    (void)unused1;
    (void)unused2;
    (void)unused3;
    ActorStateMachine_RequestStateByFactory(machine, &factory);
    return 0;
}
__attribute__((noinline)) int Menu_RequestStMenuAppear_0017F7BC(
    void *object, void *unused1, void *unused2, void *unused3)
{
    void *machine = *(void **)((uint8_t *)object + 0x30u);
    void *factory = StMenuAppear_Factory_00234A94();
    (void)unused1;
    (void)unused2;
    (void)unused3;
    ActorStateMachine_RequestStateByFactory(machine, &factory);
    return 0;
}

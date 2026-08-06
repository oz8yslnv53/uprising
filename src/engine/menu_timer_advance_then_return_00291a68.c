#include <stdint.h>
extern void *StMenuBase_Factory_0022CC34(void);
extern void *ActorStateMachine_RequestStateByFactory(void *machine,
                                                      void *factory_slot);
__attribute__((noinline)) int FUN_00291A68(
    void *object, void *unused1, void *unused2, void *delta_record)
{
    uint8_t *bytes = (uint8_t *)object;
    uint8_t *record = bytes + 0x400u;
    float *timer = (float *)(record + 0x100u);
    union {
        float f;
        int32_t i;
    } next;
    void *factory;
    next.f = *timer + *(float *)((uint8_t *)delta_record + 0x0cu);
    *timer = next.f;
    (void)unused1;
    (void)unused2;
    if (next.i > 0x3f000000) {
        void *machine = *(void **)(bytes + 0x30u);
        factory = StMenuBase_Factory_0022CC34();
        ActorStateMachine_RequestStateByFactory(machine, &factory);
    }
    return 0;
}

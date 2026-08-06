#include <stdint.h>
extern void *StMenuBase_Factory_0022CC34(void);
extern void *ActorStateMachine_RequestStateByFactory_0036BEF0(
    void *machine, void *factory_slot);
extern void FUN_002095B8(void *state);
int FUN_0017AB88(void *object, void *unused2, void *unused3,
                 void *step_record)
{
    union {
        float value;
        uint32_t bits;
    } timer;
    void *factory;
    uint8_t *bytes = (uint8_t *)object;
    (void)unused2;
    (void)unused3;
    timer.value = *(float *)(bytes + 0x2bbc) +
                  *(float *)((uint8_t *)step_record + 0x0c);
    *(float *)(bytes + 0x2bbc) = timer.value;
    if (timer.bits > 0x3f000000u) {
        void *machine = *(void **)(bytes + 0x30);
        factory = StMenuBase_Factory_0022CC34();
        ActorStateMachine_RequestStateByFactory_0036BEF0(
            machine, &factory);
    }
    FUN_002095B8(bytes + 0x5c);
    return 0;
}

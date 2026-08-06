#include <stdint.h>
extern void FUN_001A9614(void *object);
extern void ActorStateConditionPreUpdate(void *record, void *target,
                                          void *frame_context);
int ActorStateCondition_PreUpdateDispatch_0017F86C(
    void *object, void *unused1, void *unused2, void *frame_context)
{
    void *machine;
    (void)unused1;
    (void)unused2;
    FUN_001A9614(object);
    machine = *(void **)((uint8_t *)object + 0x30);
    ActorStateConditionPreUpdate((uint8_t *)object + 0xb8, machine,
                                 frame_context);
    return 0;
}

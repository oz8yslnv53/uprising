#include <stdint.h>
extern void Engine_ApplyRecordUpdate_00490890(void *owner, void *record,
                                               float value);
extern int ActorState_SpecialEligibilityPredicate(void *actor);
__attribute__((noinline)) uint32_t
Engine_ApplyRecordUpdateAndEligibilityFlag_004675D8(
    void *object, uint8_t *output, uint8_t *record, uint8_t *value_record)
{
    uint8_t *actor = *(uint8_t **)((uint8_t *)object + 0x30u);
    Engine_ApplyRecordUpdate_00490890(object, record,
                                      *(float *)(value_record + 0x14u));
    if (record[0x29u] == 4u &&
        ActorState_SpecialEligibilityPredicate(actor) != 0)
        output[0x64u] = 3u;
    return 0u;
}

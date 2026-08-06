#include <stdint.h>
extern uint32_t Engine_RecordPoolFind_004B47C4(void *pool, uint32_t key);
extern void Engine_IntrusiveRecordLink_0048ED3C(void *list, void *record,
                                                 uint32_t key);
__attribute__((noinline)) uint32_t Engine_FindAndLinkRecord_0045F798(
    void *object, void *record, uint32_t key)
{
    uint8_t *base = (uint8_t *)object;
    void *pool = *(void **)(base + 0x48u);
    if (pool == 0)
        return 0u;
    uint32_t found = Engine_RecordPoolFind_004B47C4(pool, key);
    if (found == 0u)
        return 0u;
    Engine_IntrusiveRecordLink_0048ED3C((uint8_t *)pool + 8u,
                                       (uint8_t *)record + 0xcu, found);
    return 1u;
}

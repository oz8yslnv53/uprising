#include <stdint.h>
typedef uint32_t (*EntryBeginFn)(void *object);
typedef void (*EntryUpdateFn)(void *object, void *argument);
extern uint32_t Engine_AdvanceBoundedCursor_0013062C(
    void *cursor, uint32_t base, uint32_t amount);
uint32_t ResourceEntry_Refresh_001305E0(void *object, void *argument)
{
    void **entry_vtable = *(void ***)object;
    uint32_t begin = ((EntryBeginFn)entry_vtable[3])(object);
    uint8_t *provider = *(uint8_t **)((uint8_t *)object + 0x68);
    uint8_t *dispatch = *(uint8_t **)(provider + 0x190);
    void **dispatch_vtable = *(void ***)dispatch;
    ((EntryUpdateFn)dispatch_vtable[6])(dispatch, argument);
    return Engine_AdvanceBoundedCursor_0013062C(
        (uint8_t *)object + 0x50, begin, 0);
}

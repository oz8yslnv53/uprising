#include <stdint.h>
typedef void (*Notify)(void *object);
typedef void (*Release)(void *object, void *record);
__attribute__((noinline)) int FUN_00b90428(void *object, void *unused, Notify notify)
{
    (void)unused;
    if (object == 0)
        return -2;
    if (*(void **)((uint8_t *)object + 0x1c) == 0 ||
        *(Release *)((uint8_t *)object + 0x24) == 0)
        return -2;
    if (*(uint32_t *)((uint8_t *)*(void **)((uint8_t *)object + 0x1c) + 0x34) != 0)
        notify(*(void **)((uint8_t *)object + 0x28));
    (*(Release *)((uint8_t *)object + 0x24))(
        *(void **)((uint8_t *)object + 0x28),
        *(void **)((uint8_t *)object + 0x1c));
    *(void **)((uint8_t *)object + 0x1c) = 0;
    return 0;
}

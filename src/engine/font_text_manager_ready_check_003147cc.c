#include <stdint.h>
extern void *DAT_00D6366C;
extern void *FontTextManager_Get_003532F0(void);
extern int FUN_002EEC20(void *manager, int selector);
extern int FUN_002A1E94(void *manager, int selector);
__attribute__((noinline)) int FUN_003147CC(void)
{
    void **slot = &DAT_00D6366C;
    void *manager = *slot;
    if (manager == (void *)0) {
        manager = FontTextManager_Get_003532F0();
        *slot = manager;
    }
    if (FUN_002EEC20(manager, -1) != 0)
        return 1;
    manager = *slot;
    if (manager == (void *)0) {
        manager = FontTextManager_Get_003532F0();
        *slot = manager;
    }
    if (FUN_002A1E94(manager, -1) != 0)
        return 1;
    return 0;
}

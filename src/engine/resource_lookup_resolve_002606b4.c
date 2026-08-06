#include <stdint.h>
extern int FUN_002A3D58(uint32_t table, void * key, int32_t * result, int mode);
extern int FUN_002A3DB0(void);
extern int FUN_002A3DD4(int entry);
extern int FUN_002A3D84(int entry);
__attribute__((noinline)) int ResourceLookup_Core_002606C0(
    uint32_t table, void * key, int32_t * result, int mode)
{
    int entry = FUN_002A3D58(*(uint32_t *)((uint8_t *)table + 0x3c),
                             key, result, mode);
    int kind = 0;
    if (entry != 0) {
        kind = FUN_002A3DB0();
        if (kind == 0) {
            kind = FUN_002A3DD4(entry);
            result[0] = *(int32_t *)(kind + 8);
            result[1] = *(int32_t *)(kind + 4) + 8;
        } else if (kind == 1) {
            result[2] = FUN_002A3D84(entry);
        } else if (kind == 2) {
            return 0;
        }
        kind = 1;
    }
    return kind;
}
__attribute__((noinline)) int ResourceLookup_Resolve_002606B4(
    void * object, void * key, int32_t * result)
{
    return ResourceLookup_Core_002606C0(
        *(uint32_t *)((uint8_t *)object + 4), key, result, 0);
}

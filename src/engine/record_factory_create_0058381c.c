#include <stdint.h>
extern void *FUN_005B0A14(void);
__attribute__((noinline)) void *Engine_RecordFactoryCreate_0058381C(void) {
    uint8_t *record = (uint8_t *)FUN_005B0A14();
    *(uint32_t *)(record + 0x20) = 0x2710u;
    *(uint32_t *)record = 0x00cf1c5cu;
    return record;
}

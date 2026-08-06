#include <stdint.h>
extern uint32_t CtrSvc_ThreadProcessSelector_00107D04(
    uint32_t *record, uint32_t key);
__attribute__((noinline)) uint32_t Engine_GlobalRecordPublish_00101BC0(uint32_t value)
{
    volatile uint32_t *global = (volatile uint32_t *)(uintptr_t)0x00d4d5e0u;
    uint32_t local = value;
    global[4] = value;
    CtrSvc_ThreadProcessSelector_00107D04(&local, 0x030205c8u);
    return 0;
}

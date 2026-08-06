#include <stdint.h>
extern void *ResourceLock_Get_00166C50(void);
extern uint8_t *ResourceRecord_Allocate_009064BC(void);
extern void *ResourceState_GetCallbackContext_001B3DFC(void);
extern uint8_t *ResourceRecord_Create_00220154(void *context,
                                                uint32_t arg1,
                                                uint32_t arg2,
                                                uint32_t arg3,
                                                uint8_t *record);
extern void ResourceRecord_Initialize_00908A3C(uint8_t *record,
                                               uint32_t arg3,
                                               uint32_t arg4);
extern void ResourceLock_Release_001B3F04(void *lock, uint8_t *record);
__attribute__((noinline)) uint8_t *
ResourceRecord_CreateAndAttach_009084A8(uint32_t arg1, uint32_t arg2,
                                         uint32_t arg3, uint32_t arg4)
{
    uint8_t *record;
    void *context;
    uint8_t *created;
    void *lock;
    (void)ResourceLock_Get_00166C50();
    record = ResourceRecord_Allocate_009064BC();
    if (record == 0)
        return 0;
    record[0xc7] = 1;
    context = ResourceState_GetCallbackContext_001B3DFC();
    created = ResourceRecord_Create_00220154(context, arg1, arg2,
                                              (uint32_t)0x001B3E7CU,
                                              record);
    if (created == 0) {
        lock = ResourceLock_Get_00166C50();
        ResourceLock_Release_001B3F04(lock, record);
        return 0;
    }
    *(uint8_t **)(record + 0x134U) = created;
    ResourceRecord_Initialize_00908A3C(record, arg3, arg4);
    return record;
}

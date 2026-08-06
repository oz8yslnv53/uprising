#include <stdint.h>
extern void ResourceHandle_Release_0090E054(uint32_t *record);
typedef void (*ResourceRecordCallback)(
    uint32_t, uint32_t, void *, uint32_t);
__attribute__((noinline)) void ResourceRecord_Destroy_0090FEB4(
    uint8_t *record)
{
    ResourceRecordCallback callback;
    if (*(uint32_t *)(record + 0x50U) == 0)
        return;
    callback = *(ResourceRecordCallback *)(record + 0x24U);
    if (callback != 0)
        callback(0, 0, *(void **)(record + 0x20U), 0);
    ResourceHandle_Release_0090E054(
        (uint32_t *)(record + 0x4cU));
}

#include <stdint.h>
extern void *ResourceFactory_001F5A30(void);
extern int OrderedTree_FindPayloadByPointer_00326C6C(void *, void *);
__attribute__((noinline)) int ResourceState_PublishReadyFlag_001C8F00(
    void *owner_pointer, uint32_t unused_second, uint32_t unused_third,
    void *unused_fourth)
{
    uint8_t *owner = (uint8_t *)owner_pointer;
    void *machine = *(void **)(owner + 0x30);
    void *key_record = ResourceFactory_001F5A30();
    int match = OrderedTree_FindPayloadByPointer_00326C6C(
        machine, &key_record);
    int record = match != 0 ? *(int *)(match + 0x1C) : 0;
    (void)unused_second;
    (void)unused_third;
    (void)unused_fourth;
    if (*(uint8_t *)(record + 0xD6) != 0)
        owner[0x74] = 1;
    return 0;
}

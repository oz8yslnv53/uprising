#include <stdint.h>
extern void *FUN_00275B68(void);
extern void *OrderedTree_FindPayloadByPointer_00326C6C(
    void *tree, void *key_record);
extern void *ResourceTree_ResolveCurrentEntry_002A6268(void *owner);
extern void FUN_00205E44(void *object, void *entry, void *selection);
int Menu_ApplyMatchingResource_001CFEEC(
    void *object, uint32_t unused_1, void *selection, void *unused_3)
{
    uint8_t *bytes = (uint8_t *)object;
    void *machine = *(void **)(bytes + 0x30);
    void *key = FUN_00275B68();
    void *payload = OrderedTree_FindPayloadByPointer_00326C6C(machine, &key);
    uint8_t *record = payload == 0 ? 0 :
        *(uint8_t **)((uint8_t *)payload + 0x1c);
    (void)unused_1;
    (void)unused_3;
    if (*(uint32_t *)((uint8_t *)selection + 0x2c) ==
        *(uint32_t *)(record + 0x18)) {
        void *entry = ResourceTree_ResolveCurrentEntry_002A6268(machine);
        FUN_00205E44(object, entry, selection);
    }
    return 0;
}

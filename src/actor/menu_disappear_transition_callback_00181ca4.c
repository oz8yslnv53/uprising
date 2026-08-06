#include <stdint.h>
extern void FUN_001AC1EC(void *object, void *record);
extern void *StMenuDisappear_Factory_0028AADC(void);
extern void *ActorStateMachine_RequestStateByFactory_0036BEF0(
    void *machine, void *factory_slot);
extern void *OrderedTree_LowerBoundBySignedKey_00390A98(void *tree,
                                                        int key);
extern void *StMenuBase_Factory_0022CC34(void);
extern void *StMenuAppear_Factory_00234A94(void);
extern void *MenuWork_Factory_002A18B8(void);
int MenuDisappear_TransitionCallback_00181CA4(
    void *object, void *unused1, void *unused2, void *unused3)
{
    uint8_t *bytes = (uint8_t *)object;
    uint8_t *resource = *(uint8_t **)(bytes + 0x34);
    uint8_t *state = *(uint8_t **)(bytes + 0x38);
    void *factory;
    (void)unused1;
    (void)unused2;
    (void)unused3;
    if ((resource[0x1c] & 0x0a) == 0x0a) {
        FUN_001AC1EC(object, state + 0x14c);
        resource[0x1c] &= (uint8_t)~2u;
        factory = StMenuDisappear_Factory_0028AADC();
        ActorStateMachine_RequestStateByFactory_0036BEF0(
            *(void **)(bytes + 0x30), &factory);
        bytes[0x54] |= 1u;
        return 0;
    }
    {
        uint8_t *node = (uint8_t *)OrderedTree_LowerBoundBySignedKey_00390A98(
            *(void **)(bytes + 0x3c), 0x14);
        uint8_t *list = *(uint8_t **)(node + 0x20);
        int should_update = 0;
        if (list != node + 0x1c) {
                uint8_t *entry = *(uint8_t **)list;
            if (*(uint8_t **)(entry + 0x10) != entry + 0x0c) {
                uint8_t *payload = *(uint8_t **)(entry + 0x14);
                payload = *(uint8_t **)payload;
                if (payload != 0 && payload[0x24] == 0) {
                    should_update = 1;
                }
            }
        }
        if (should_update != 0) {
            if ((bytes[0x54] & 2u) != 0) {
                FUN_001AC1EC(object, state + 0xf4);
            } else {
                FUN_001AC1EC(object, state + 0x44);
            }
        }
    }
    if ((resource[0x1c] & 8u) != 0) {
        factory = StMenuDisappear_Factory_0028AADC();
        ActorStateMachine_RequestStateByFactory_0036BEF0(
            *(void **)(bytes + 0x30), &factory);
    }
    return 0;
}
__attribute__((noinline)) int FUN_00181DE0(void *object)
{
    FUN_001AC1EC(object, *(uint8_t **)((uint8_t *)object + 0x38) + 0x18);
    return 0;
}
__attribute__((noinline)) int FUN_00181DFC(
    void *object, void *unused1, void *unused2, void *unused3)
{
    uint8_t *bytes = (uint8_t *)object;
    uint8_t *node;
    uint8_t *list;
    uint8_t *entry;
    uint8_t *payload;
    void *factory;
    (void)unused1;
    (void)unused2;
    (void)unused3;
    node = (uint8_t *)OrderedTree_LowerBoundBySignedKey_00390A98(
        *(void **)(bytes + 0x3c), 0x14);
    list = *(uint8_t **)(node + 0x20);
    if (list == node + 0x1c) {
        return 0;
    }
    entry = *(uint8_t **)list;
    if (*(uint8_t **)(entry + 0x10) == entry + 0x0c) {
        return 0;
    }
    payload = *(uint8_t **)(entry + 0x14);
    payload = *(uint8_t **)payload;
    if (payload == 0 || payload[0x24] != 0) {
        return 0;
    }
    if (((*(uint8_t **)(bytes + 0x34))[0x1c] & 8u) != 0) {
        factory = StMenuDisappear_Factory_0028AADC();
        ActorStateMachine_RequestStateByFactory_0036BEF0(
            *(void **)(bytes + 0x30), &factory);
        return 0;
    }
    if ((bytes[0x54] & 2u) != 0) {
        FUN_001AC1EC(object, *(uint8_t **)(bytes + 0x38) + 0xf4);
    } else {
        FUN_001AC1EC(object, *(uint8_t **)(bytes + 0x38) + 0x44);
    }
    factory = StMenuBase_Factory_0022CC34();
    ActorStateMachine_RequestStateByFactory_0036BEF0(
        *(void **)(bytes + 0x30), &factory);
    return 0;
}
__attribute__((noinline)) int FUN_00181F00(void *object)
{
    uint8_t *bytes = (uint8_t *)object;
    if ((bytes[0x54] & 1u) != 0) {
        bytes[0x54] &= (uint8_t)~1u;
    } else {
        FUN_001AC1EC(object, *(uint8_t **)(bytes + 0x38) + 0x70);
    }
    return 0;
}
__attribute__((noinline)) int FUN_00181F3C(
    void *object, void *unused1, void *unused2, void *unused3)
{
    uint8_t *bytes = (uint8_t *)object;
    uint8_t *node;
    uint8_t *list;
    uint8_t *entry;
    uint8_t *payload;
    void *factory;
    (void)unused1;
    (void)unused2;
    (void)unused3;
    node = (uint8_t *)OrderedTree_LowerBoundBySignedKey_00390A98(
        *(void **)(bytes + 0x3c), 0x14);
    list = *(uint8_t **)(node + 0x20);
    if (list == node + 0x1c) {
        return 0;
    }
    entry = *(uint8_t **)list;
    if (*(uint8_t **)(entry + 0x10) == entry + 0x0c) {
        return 0;
    }
    payload = *(uint8_t **)(entry + 0x14);
    payload = *(uint8_t **)payload;
    if (payload == 0 || payload[0x24] != 0) {
        return 0;
    }
    if (((*(uint8_t **)(bytes + 0x34))[0x1c] & 8u) == 0) {
        factory = StMenuAppear_Factory_00234A94();
        ActorStateMachine_RequestStateByFactory_0036BEF0(
            *(void **)(bytes + 0x30), &factory);
        return 0;
    }
    FUN_001AC1EC(object, *(uint8_t **)(bytes + 0x38) + 0x1a4);
    {
        uint8_t *node = *(uint8_t **)(*(uint8_t **)(bytes + 0x30) + 0x1ac);
        void *key = MenuWork_Factory_002A18B8();
        while (node[0x10] != 0) {
            if (*(void **)(node + 0x14) < key) {
                node = *(uint8_t **)(node + 0x0c);
            } else {
                node = *(uint8_t **)(node + 0x08);
            }
        }
    }
    return 0;
}

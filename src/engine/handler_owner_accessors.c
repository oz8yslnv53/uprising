#include <stddef.h>
#include <stdint.h>
extern void *EngineLazySingletonGetter_0054EFA8(void);
extern void *StatusDescriptor_OwnerGet(void *engine, void *object);
extern uint32_t Engine_LazySingletonGetter_00498828(void);
extern void *ComponentType_GetGlobalDescriptor(void);
extern int Engine_StatusVariantModeByte(void);
extern void *ComponentInstance_ResolveByTypeIndex_0058F9B8(uint32_t type_index);
__attribute__((noinline)) void *EngineContextGet_006ea1a4(void)
{
    static void **const context_slot = (void **)(uintptr_t)0x006ea1c4u;
    void *context = *context_slot;
    if (context == NULL) {
        context = EngineLazySingletonGetter_0054EFA8();
        *context_slot = context;
    }
    return context;
}
__attribute__((noinline)) void *ItemHandlerOwner_GetField0x3C_00B60214(void *handler)
{
    uint8_t *owner = *(uint8_t **)((uint8_t *)handler + 8);
    return *(void **)(owner + 0x3c);
}
__attribute__((noinline)) uint32_t PackedState_Get2BitField_00B67158(
    void *owner, uint32_t selector)
{
    if (selector != 0u && selector < 7u)
        return (*(uint32_t *)((uint8_t *)owner + 0x94u) >>
                (selector * 2u - 2u)) & 3u;
    return 0u;
}
__attribute__((noinline)) void *ItemHandlerOwner_GetField0x40_00A33F54(void *handler)
{
    uint8_t *owner = *(uint8_t **)((uint8_t *)handler + 8);
    return *(void **)(owner + 0x40);
}
__attribute__((noinline)) void *ItemHandlerOwner_GetField0x44_00A33F64(void *handler)
{
    uint8_t *owner = *(uint8_t **)((uint8_t *)handler + 8);
    return *(void **)(owner + 0x44);
}
__attribute__((noinline)) void *OwnerFromGenerationHandle_00611D5C(uint32_t handle)
{
    static void **const engine_slot = (void **)(uintptr_t)0x00611dc8u;
    static uint32_t *const table_generation_slot =
        (uint32_t *)(uintptr_t)0x00611dc0u;
    static uint8_t **const table_base_slot =
        (uint8_t **)(uintptr_t)0x00611dc4u;
    uint8_t *row;
    void *entry;
    void *engine;
    if (*table_generation_slot != (handle >> 9))
        return NULL;
    row = *table_base_slot + (handle & 0x1ffu) * 8u;
    entry = *(void **)row;
    if (*(uint32_t *)(row + 4) != (handle >> 9) || entry == NULL)
        return NULL;
    engine = *engine_slot;
    if (engine == NULL) {
        engine = EngineLazySingletonGetter_0054EFA8();
        *engine_slot = engine;
    }
    return StatusDescriptor_OwnerGet(engine, entry);
}
__attribute__((noinline)) uint32_t ActorNotify_TransitionBit_0042F61C(void *record)
{
    uint32_t byte_value = *((uint8_t *)record + 0x34);
    return ((byte_value << 0x1a) | (byte_value << 0x1b)) >> 0x1f;
}
int32_t StateMachineVariant_LookupCachedValue_00552008(void *machine);
uint8_t VariantModeFlag_GetByIndex_00551F88(uint32_t index);
__attribute__((noinline)) int32_t ActorStateMachine_LookupCachedVariantValue_00552000(void *owner)
{
    return StateMachineVariant_LookupCachedValue_00552008(
        *(void **)((uint8_t *)owner + 0x30));
}
__attribute__((noinline)) uint32_t ComponentTypeIndex_Lookup_00548C04(void *record)
{
    uint8_t *bytes = (uint8_t *)record;
    uint8_t *cached = *(uint8_t **)(bytes + 0x1e8);
    if (cached == NULL) {
        uint32_t key = (uint32_t)(uintptr_t)ComponentType_GetGlobalDescriptor();
        uint8_t *sentinel = bytes + 0x1a8;
        uint8_t *node = *(uint8_t **)(bytes + 0x1ac);
        uint8_t *best = sentinel;
        while (*(node + 0x10) != 0) {
            uint32_t node_key = *(uint32_t *)(node + 0x14);
            if (node_key < key) {
                node = *(uint8_t **)(node + 0xc);
            } else {
                best = node;
                node = *(uint8_t **)(node + 8);
            }
        }
        if (best == sentinel || *(uint32_t *)(best + 0x14) <= key)
            best = sentinel;
        if (*(void **)best != *(void **)sentinel) {
            cached = *(uint8_t **)best;
            if (cached == NULL)
                return 0;
            *(void **)(cached + 0x1c) = record;
            *(uint8_t **)(bytes + 0x1e8) = cached;
        }
    }
    if (cached != NULL) {
        uint32_t packed = *(uint32_t *)(cached + 0x20);
        if ((packed >> 0x1c) == 1)
            return ((packed >> 0x10) + 1) & 0xffu;
    }
    return 0;
}
__attribute__((noinline)) void *ComponentInstance_Resolve_005B0E00(void *record)
{
    uint32_t type_index = ComponentTypeIndex_Lookup_00548C04(record);
    if (type_index == 0)
        return NULL;
    return ComponentInstance_ResolveByTypeIndex_0058F9B8(type_index);
}
__attribute__((noinline)) uint32_t MaskLow22Bits_00541B90(const uint32_t *value)
{
    return *value & 0x3fffffu;
}
__attribute__((noinline)) uint32_t ComponentRecord_GetMaskedField0x20_004EDBE0(void *record)
{
    uint32_t value = *(uint32_t *)((uint8_t *)record + 0x20);
    return MaskLow22Bits_00541B90(&value);
}
__attribute__((noinline)) int32_t StateMachineVariant_LookupCachedValue_00552008(void *machine)
{
    uint8_t *bytes = (uint8_t *)machine;
    uint8_t *record = *(uint8_t **)(bytes + 0x1e4);
    if (record != NULL) {
        if (record[0x2c] == 5)
            return *(int16_t *)(record + 0x20);
        return -1;
    }
    {
        uint32_t key = Engine_LazySingletonGetter_00498828();
        uint8_t *sentinel = bytes + 0x1a8;
        uint8_t *node = *(uint8_t **)(bytes + 0x1ac);
        uint8_t *best = sentinel;
        while (*(node + 0x10) != 0) {
            uint32_t node_key = *(uint32_t *)(node + 0x14);
            if (node_key < key) {
                node = *(uint8_t **)(node + 0xc);
            } else {
                best = node;
                node = *(uint8_t **)(node + 8);
            }
        }
        if (best == sentinel || *(uint32_t *)(best + 0x14) > key)
            best = sentinel;
        if (*(void **)best != *(void **)sentinel) {
            record = *(uint8_t **)best;
            if (record != NULL) {
                *(void **)(record + 0x1c) = machine;
                *(void **)(bytes + 0x1e4) = record;
            }
        }
    }
    if (record != NULL && record[0x2c] == 5)
        return *(int16_t *)(record + 0x20);
    return -1;
}
__attribute__((noinline)) uint8_t VariantModeFlag_Get_00551F74(void *owner)
{
    void *machine = *(void **)((uint8_t *)owner + 0x30);
    return VariantModeFlag_GetByIndex_00551F88(
        (uint32_t)StateMachineVariant_LookupCachedValue_00552008(machine));
}
__attribute__((noinline)) uint8_t ItemHandlerOwner_GetVariantModeFlag_00A9D4C8(void *handler)
{
    void *owner = *(void **)((uint8_t *)handler + 8);
    return VariantModeFlag_Get_00551F74(owner);
}
__attribute__((noinline)) uint8_t VariantModeFlag_GetByIndex_00551F88(uint32_t index)
{
    if (index < 0xaeu) {
        static void **const table_base_slot = (void **)(uintptr_t)0x00551ffcu;
        uint8_t *table_base = *table_base_slot;
        if (table_base == NULL) {
            table_base = EngineLazySingletonGetter_0054EFA8();
            *table_base_slot = table_base;
        }
        {
            uint8_t *record = table_base + 0x230c + index * 0x34u;
            return (Engine_StatusVariantModeByte() == 0) ? record[0x2d] : record[0x2c];
        }
    }
    return 0;
}
__attribute__((noinline)) uint32_t OwnerVariantFlagInSet1345_005934E8(void *owner)
{
    void *machine = *(void **)((uint8_t *)owner + 0x30);
    uint32_t index = (uint32_t)StateMachineVariant_LookupCachedValue_00552008(machine);
    uint8_t flag = VariantModeFlag_GetByIndex_00551F88(index);
    return flag == 1 || flag == 3 || flag == 4 || flag == 5;
}
__attribute__((noinline)) uint32_t OwnerVariantFlagInSet345_00B5FE78(void *owner)
{
    void *machine = *(void **)((uint8_t *)owner + 0x30);
    uint32_t index = (uint32_t)StateMachineVariant_LookupCachedValue_00552008(machine);
    uint8_t flag = VariantModeFlag_GetByIndex_00551F88(index);
    return flag == 3 || flag == 4 || flag == 5;
}
__attribute__((noinline)) uint32_t OwnerVariantFlagInSet12345_00B5FEA8(void *owner)
{
    void *machine = *(void **)((uint8_t *)owner + 0x30);
    uint32_t index = (uint32_t)StateMachineVariant_LookupCachedValue_00552008(machine);
    uint8_t flag = VariantModeFlag_GetByIndex_00551F88(index);
    return flag == 1 || flag == 2 || flag == 3 || flag == 4 || flag == 5;
}
__attribute__((noinline)) int32_t OwnerField0x3C_GetByte0x20E_00B60224(void *owner)
{
    uint8_t *field = *(uint8_t **)((uint8_t *)owner + 0x3c);
    return (int32_t)(int8_t)field[0x20e];
}
__attribute__((noinline)) uint32_t PackHandleId_00A2B654(uint32_t index)
{
    return ((index - 1u) << 16) | 0x10000000u;
}
extern void *ResourceStatus_LookupByHandle(void *registry, uint32_t handle);
__attribute__((noinline))
void *ResourceStatus_LookupHandleValid_00611748(uint32_t handle)
{
    static void **const registry_slot = (void **)(uintptr_t)0x00611774u;
    void *registry = *registry_slot;
    if (registry == NULL) {
        registry = EngineLazySingletonGetter_0054EFA8();
        *registry_slot = registry;
    }
    return ResourceStatus_LookupByHandle(registry, handle);
}

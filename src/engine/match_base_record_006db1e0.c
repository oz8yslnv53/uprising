#include <stdint.h>
extern int *MatchBase_RecordEnsure_009DA99C(int context);
extern void Feature_RecordInitialize_009D3724(
    uint8_t *parent, const char *name);
extern uint8_t *FUN_009C3954(uint8_t *parent);
extern uint8_t *FUN_005D2704(uint8_t *record);
extern uint8_t *FUN_009D7164(uint8_t *record, uint32_t value);
extern void FUN_00BD4CA0(uint32_t *record, uint32_t value);
extern uint8_t *FUN_00BD8C80(uint8_t *record, uint32_t size, uint32_t align);
extern void *MemoryFillEnd_003FDCAC(void *destination, uint32_t size);
__attribute__((noinline)) int *MatchBase_RecordEnsure_009DA99C(int context)
{
    uint8_t *parent = (uint8_t *)(uintptr_t)context;
    uint8_t *state;
    uint8_t *r4;
    uint8_t *r5;
    uint8_t *record;
    uint8_t *global_pair = (uint8_t *)(uintptr_t)0x00D4A668u;
    Feature_RecordInitialize_009D3724(parent, "MatchBase");
    state = FUN_009C3954(parent + 0x70u);
    state = FUN_005D2704(state + 0x1ecu);
    state = FUN_009D7164(state + 0x34u, 0);
    r5 = state - 0x290u;
    r4 = r5 + 4u;
    *(uint32_t *)(state + 0x08u) = 0x00D22A8Cu;
    *(uint32_t *)(state + 0x0cu) = 0;
    *(uint32_t *)(state + 0x10u) = 0;
    *(uint32_t *)(state + 0x14u) = 0;
    *(uint32_t *)(state + 0x18u) = 0x00D228F0u;
    *(uint32_t *)(r4 + 0x00u) = 0x00D20B54u;
    *(uint32_t *)(r4 + 0x04u) = 0;
    *(uint32_t *)(r5 + 0x0cu) = 0;
    *(uint32_t *)(r5 + 0x10u) = 0;
    *(uint32_t *)(r5 + 0x14u) = 0;
    FUN_00BD4CA0((uint32_t *)r4, 0);
    *(uint32_t *)(r5 + 0x1cu) = 0x10u;
    *(uint32_t *)(r5 + 0x20u) = 0x100u;
    *(uint8_t *)(r5 + 0x18u) = 1;
    state = FUN_00BD8C80(r4 + 0x20u, 0x10u, 0x100u);
    state = FUN_00BD8C80(state + 0x24u, 0x10u, 0x100u);
    record = state - 0x2f0u;
    *(uint32_t *)(state + 0x24u) = 0;
    MemoryFillEnd_003FDCAC(state + 0x28u, 0x88u);
    *(uint32_t *)(state + 0xb0u) = 0;
    *(uint32_t *)(state + 0xb4u) = 0;
    *(uint32_t *)(state + 0xb8u) = 0;
    *(uint32_t *)(state + 0xbcu) = 0;
    *(uint32_t *)(state + 0xc0u) = 0;
    *(uint16_t *)(state + 0xc4u) = 0;
    *(uint8_t *)(record + 0x10u) = 9;
    if (record + 0x68u != global_pair) {
        *(uint32_t *)(record + 0x6cu) = *(uint32_t *)(global_pair + 4u);
        *(uint32_t *)(record + 0x68u) = *(uint32_t *)(global_pair + 0u);
    }
    *(uint8_t *)(record + 0x250u) = 0;
    *(uint8_t *)(record + 0x251u) = 0;
    *(uint8_t *)(record + 0x252u) = 0;
    *(uint32_t *)(record + 0x254u) = 0;
    *(uint32_t *)(record + 0x284u) = 0;
    *(uint32_t *)(record + 0x288u) = 0;
    *(uint8_t *)(record + 0x28cu) = 0;
    return (int *)record;
}
__attribute__((noinline)) int *MatchBase_RecordEnsureSetWord_006DB1E0(int context)
{
    int *record = MatchBase_RecordEnsure_009DA99C(context);
    record[0] = 0x00CEDC00;
    return record;
}

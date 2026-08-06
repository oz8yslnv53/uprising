__attribute__((noinline)) void Engine_SetField190One_00884ACC(unsigned int *record)
{
    *(unsigned char *)((char *)record + 0x190) = 1;
}
__attribute__((noinline)) void Engine_ClearField164_00889F0C(unsigned int *record)
{
    *(unsigned char *)((char *)record + 0x164) = 0;
}
__attribute__((noinline)) void *Engine_GlobalField30Get_0088E884(void)
{
    void *base = *(void **)0x00DB98B8;
    return *(void **)((char *)base + 0x30);
}
__attribute__((noinline)) void Engine_InitializePairD11FAC_0088135C(unsigned int *target)
{
    target[0] = 0x00D11FACu;
    target[1] = 0;
}

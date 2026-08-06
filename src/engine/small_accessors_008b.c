__attribute__((noinline)) void Engine_DecrementFieldC_008B0738(unsigned int *record)
{
    --record[3];
}
__attribute__((noinline)) int Engine_GlobalSignedByteGetDBB32C_008B6A28(void)
{
    return *(signed char *)0x00DBB32C;
}
__attribute__((noinline)) void Engine_SetGlobalD4D0D8Field10_008B6CB4(unsigned int value)
{
    *(unsigned int *)0x00D4D0E8 = value;
}
__attribute__((noinline)) int Engine_GlobalSignedByteGetD4D0DA_008B6E58(void)
{
    return *(signed char *)0x00D4D0DA;
}
struct Engine_TwoWords_008BADAC {
    unsigned int first;
    unsigned int second;
};
__attribute__((noinline)) void Engine_CopyTwoWords_008BADAC(unsigned int *destination,
                                  const unsigned int *source)
{
    *(struct Engine_TwoWords_008BADAC *)destination =
        *(const struct Engine_TwoWords_008BADAC *)source;
}

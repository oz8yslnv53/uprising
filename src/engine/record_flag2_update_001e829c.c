extern void Engine_RecordFlag2UpdateCommon_0021FC14(
    void *record, unsigned char flags);
__attribute__((noinline)) void Engine_RecordFlag2UpdateCommon_0021FC14(
    void *record, unsigned char flags)
{
    unsigned char *linked = (unsigned char *)record;
    linked[0x0f] = flags;
    *(unsigned short *)(linked + 0x6c) |= 4;
}
void Engine_RecordFlag2Update_001E829C(void *object, int enabled)
{
    unsigned flags;
    unsigned char *record = (unsigned char *)object;
    flags = record[7];
    if (enabled != 0)
        flags |= 2u;
    else
        flags &= ~2u;
    record[7] = flags;
    Engine_RecordFlag2UpdateCommon_0021FC14(
        *(void **)(record + 0x68), (unsigned char)flags);
}
void Engine_RecordFlag1Update_0021FBF4(void *object, int enabled)
{
    unsigned flags;
    unsigned char *record = (unsigned char *)object;
    flags = record[7];
    if (enabled != 0)
        flags |= 1u;
    else
        flags &= ~1u;
    record[7] = flags;
    {
        unsigned char *linked = *(unsigned char **)(record + 0x68);
        linked[0x0f] = (unsigned char)flags;
        *(unsigned short *)(linked + 0x6c) |= 4;
    }
}

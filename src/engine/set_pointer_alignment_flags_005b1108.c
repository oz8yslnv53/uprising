__attribute__((noinline)) void Engine_SetPointerAlignmentFlags_005B1108(unsigned int *record,
                                               int clearFlags)
{
    unsigned int value = record[5];
    if (clearFlags != 0)
        value &= ~0x0Fu;
    else
        value |= 0x0Fu;
    record[5] = value;
}

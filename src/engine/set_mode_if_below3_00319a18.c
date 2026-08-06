__attribute__((noinline)) void Engine_SetModeIfBelow3_00319A18(unsigned int *record, unsigned int mode)
{
    if (mode < 3u)
        record[1] = mode;
}

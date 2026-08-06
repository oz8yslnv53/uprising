__attribute__((noinline)) void Engine_ClearByteAndWord_006FDC1C(unsigned char *record)
{
    record[0] = 0;
    *(int *)(record + 4) = 0;
}

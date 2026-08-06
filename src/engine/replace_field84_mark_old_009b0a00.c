__attribute__((noinline)) void Engine_ReplaceField84MarkOld_009B0A00(void *object, void *replacement)
{
    unsigned char *old = *(unsigned char **)((unsigned char *)object + 0x84);
    if (old != 0)
        old[0x12] = 1;
    *(void **)((unsigned char *)object + 0x84) = replacement;
}

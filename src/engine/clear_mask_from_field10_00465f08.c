__attribute__((noinline)) void Engine_ClearMaskFromField10_00465F08(void *object, void *other)
{
    unsigned int *field = (unsigned int *)((unsigned char *)object + 0x10);
    *field &= ~*(unsigned int *)((unsigned char *)other + 0x0c);
}

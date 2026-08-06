__attribute__((noinline)) unsigned int Engine_GlobalByteGet1FF81066_008C3BF0(void)
{
    return *(unsigned char *)0x1FF81066;
}
__attribute__((noinline)) void *Engine_Identity_008C5978(void *value)
{
    return value;
}
__attribute__((noinline)) void Engine_ClearFields6And8_008C5B58(void *record)
{
    *(unsigned short *)((char *)record + 0x6) = 0;
    *(unsigned int *)((char *)record + 0x8) = 0;
}

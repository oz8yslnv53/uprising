__attribute__((noinline)) void Engine_BoundedAppendWordAt50_00590A90(unsigned int *record,
                                            unsigned int value)
{
    unsigned int count = *(unsigned int *)((char *)record + 0x4c);
    if (count < 0xf) {
        *(unsigned int *)((char *)record + 0x4c) = count + 1;
        *(unsigned int *)((char *)record + 0x50 + count * 4) = value;
    }
}

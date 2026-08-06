__attribute__((noinline)) void Engine_RecordStorePair84_001E9D48(void *object,
                                       unsigned int first,
                                       unsigned int second)
{
    unsigned int *pair = (unsigned int *)((unsigned char *)object + 0x84);
    pair[0] = first;
    pair[1] = second;
}

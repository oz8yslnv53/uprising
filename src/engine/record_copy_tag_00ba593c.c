__attribute__((noinline)) void Engine_RecordCopyTag_00BA593C(void *destination, const unsigned int *source,
                                    unsigned char mode)
{
    *(unsigned char *)((unsigned char *)destination + 4) = 4u;
    *(unsigned char *)((unsigned char *)destination + 6) = mode;
    *(unsigned int *)destination = *source;
}

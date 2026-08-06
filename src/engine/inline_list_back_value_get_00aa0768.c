__attribute__((noinline)) unsigned int Engine_InlineListBackValueGet_00AA0768(const void *object)
{
    const unsigned int *head = *(const unsigned int **)((const unsigned char *)object + 0x18);
    const unsigned int *sentinel = (const unsigned int *)((const unsigned char *)object + 0x14);
    if (head == sentinel)
        return 0u;
    return **(const unsigned int **)((const unsigned char *)object + 0x1c);
}

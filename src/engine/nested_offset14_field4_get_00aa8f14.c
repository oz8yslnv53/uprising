__attribute__((noinline)) unsigned int Engine_NestedOffset14Field4Get_00AA8F14(const void *object)
{
    const unsigned char *nested =
        *(const unsigned char * const *)((const unsigned char *)object + 0x14);
    return *(const unsigned int *)(nested + 4);
}

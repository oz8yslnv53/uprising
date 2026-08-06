__attribute__((noinline)) unsigned short Engine_IndexedHalfwordLookupNullable_004357A8(
    void *object, int table_index, int element_index)
{
    unsigned char *entry = *(unsigned char **)((unsigned char *)object + table_index * 12 + 4);
    unsigned char *value = entry + element_index * 2;
    if (value == 0)
        return 0;
    return *(unsigned short *)value;
}

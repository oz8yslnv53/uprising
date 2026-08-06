typedef struct IndexedCopy64BytesBlock {
    float values[16];
} IndexedCopy64BytesBlock;
__attribute__((noinline)) void Indexed_Copy64Bytes_00349DF0(void *base, unsigned int index,
                                  const IndexedCopy64BytesBlock *source)
{
    IndexedCopy64BytesBlock *destination =
        (IndexedCopy64BytesBlock *)((unsigned char *)base + index * 0x40);
    *destination = *source;
}

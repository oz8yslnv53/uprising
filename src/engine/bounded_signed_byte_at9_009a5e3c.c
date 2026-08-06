__attribute__((noinline)) int Engine_BoundedSignedByteAt9_009A5E3C(const unsigned char *object,
                                         unsigned int index)
{
    if (index >= 0x10u)
        return -1;
    return (int)(*(const signed char *)(object + index + 9));
}
__attribute__((noinline)) int FUN_009A24E4(unsigned char *object,
                                           const unsigned char *entry)
{
    signed char limit;
    unsigned char index;
    int value;
    object[0x19] = 0xff;
    limit = *(const signed char *)(entry + 0x1c);
    if (limit < 0)
        return 1;
    index = entry[0x1d];
    value = Engine_BoundedSignedByteAt9_009A5E3C(object, (unsigned int)index);
    if (value < (int)limit) {
        object[0x19] = index;
        return 1;
    }
    return 0;
}

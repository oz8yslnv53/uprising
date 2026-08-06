__attribute__((noinline)) unsigned int Engine_Field31B8Bit4Get_00A5880C(const void *object)
{
    const unsigned int *base = (const unsigned int *)((const unsigned char *)object + 0x3000);
    return (base[0x1b8 / 4] & 0x10u) >> 4;
}

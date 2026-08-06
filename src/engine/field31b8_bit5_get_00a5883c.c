__attribute__((noinline)) unsigned int Engine_Field31B8Bit5Get_00A5883C(const void *object)
{
    const unsigned int *base = (const unsigned int *)((const unsigned char *)object + 0x3000);
    return (base[0x1b8 / 4] & 0x20u) >> 5;
}

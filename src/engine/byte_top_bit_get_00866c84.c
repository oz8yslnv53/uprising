__attribute__((noinline)) unsigned int Engine_ByteTopBitGet_00866C84(const unsigned char *object)
{
    return (*object & 0x80u) >> 7;
}

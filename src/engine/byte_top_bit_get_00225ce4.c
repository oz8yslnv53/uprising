__attribute__((noinline)) unsigned int Engine_ByteTopBitGet_00225CE4(const unsigned char * value)
{
    return (*value & 0x80) >> 7;
}

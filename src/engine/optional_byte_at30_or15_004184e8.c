__attribute__((noinline)) unsigned int Engine_OptionalByteAt30Or15_004184E8(void * object)
{
    unsigned char value = 0xf;
    if (object != 0)
        value = *(unsigned char *)((char *)object + 0x30);
    return value;
}

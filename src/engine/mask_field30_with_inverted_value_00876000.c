__attribute__((noinline)) void Engine_MaskField30WithInvertedValue_00876000(void *object, unsigned short value)
{
    unsigned short *field = (unsigned short *)((unsigned char *)object + 0x30);
    *field = (unsigned short)((value ^ 0xffff) & *field);
}

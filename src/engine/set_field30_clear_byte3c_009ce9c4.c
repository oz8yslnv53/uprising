__attribute__((noinline)) void Engine_SetField30ClearByte3C_009CE9C4(unsigned int *object,
                                           unsigned int value)
{
    *(unsigned int *)((unsigned char *)object + 0x30) = value;
    *((unsigned char *)object + 0x3c) = 0;
}

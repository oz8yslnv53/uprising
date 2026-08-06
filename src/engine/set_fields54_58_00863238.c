__attribute__((noinline)) void Engine_SetFields54And58_00863238(unsigned char *object,
                                      const unsigned int *value,
                                      unsigned int tag)
{
    *(unsigned int *)(object + 0x58) = tag;
    *(unsigned int *)(object + 0x54) = *value;
}

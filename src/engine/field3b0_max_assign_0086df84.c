__attribute__((noinline)) void Engine_Field3B0MaxAssign_0086DF84(unsigned int *object,
                                        unsigned int value)
{
    unsigned int current = object[0x3b0 / 4];
    if (current >= value)
        value = current;
    object[0x3b0 / 4] = value;
}

__attribute__((noinline)) void Engine_SetField0Bit4_009F676C(unsigned int *object, int enabled)
{
    if (enabled != 0)
        *object |= 0x10u;
    else
        *object &= ~0x10u;
}

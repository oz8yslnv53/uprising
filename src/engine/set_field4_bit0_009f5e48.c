__attribute__((noinline)) void Engine_SetField4Bit0_009F5E48(unsigned int *object, int enabled)
{
    if (enabled != 0)
        * (object + 1) |= 1u;
    else
        * (object + 1) &= ~1u;
}

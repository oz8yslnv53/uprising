__attribute__((noinline)) void Engine_SetFlagBit12_00A0EE5C(unsigned int *flags, int enabled)
{
    if (enabled != 0)
        *flags |= 0x1000u;
    else
        *flags &= ~0x1000u;
}

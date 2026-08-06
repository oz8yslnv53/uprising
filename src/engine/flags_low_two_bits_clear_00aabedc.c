__attribute__((noinline)) unsigned int Engine_FlagsLowTwoBitsSet_00AABEDC(const unsigned int *flags)
{
    return ((~*flags & 3u) == 0u) ? 1u : 0u;
}

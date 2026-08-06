__attribute__((noinline)) unsigned int Engine_TripleByteGate_00B1E6D4(const void *state)
{
    const unsigned char *bytes = (const unsigned char *)state;
    if (bytes[0xc5] == 1u)
        return 0u;
    if (bytes[0xfc] != 3u)
        return 0u;
    return bytes[0xec] == 3u ? 1u : 0u;
}

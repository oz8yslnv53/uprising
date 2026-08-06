__attribute__((noinline)) void Engine_FillWordFromByte_005D2A78(unsigned int *destination,
                                      unsigned int value)
{
    unsigned int repeated = value & 0xff;
    repeated |= repeated << 8;
    repeated |= repeated << 16;
    *destination = repeated;
}

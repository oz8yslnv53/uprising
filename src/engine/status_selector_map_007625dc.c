__attribute__((noinline)) int Engine_StatusSelectorMap_007625DC(unsigned int unused, unsigned int selector)
{
    (void)unused;
    if (selector == 0x0b || selector == 0x0d)
        return 15;
    return -1;
}

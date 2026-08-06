__attribute__((noinline)) void Engine_IndexedField30Store_00878E68(unsigned char *object,
                                          unsigned int index,
                                          unsigned int value)
{
    unsigned int *entries = *(unsigned int **)(object + 0x30);
    entries[index] = value;
}

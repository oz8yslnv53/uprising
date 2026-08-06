__attribute__((noinline)) void *Engine_SetIndexedByteAndReturnSlot_00990C18(void *owner,
                                                  int index,
                                                  unsigned char value)
{
    char *slot = *(char **)((char *)owner + 0xec) + index * 0x28;
    slot[0x8] = value;
    return slot;
}
__attribute__((noinline)) void Engine_NoOp_0099EC08(void)
{
}

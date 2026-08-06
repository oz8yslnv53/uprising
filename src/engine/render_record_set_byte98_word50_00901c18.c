__attribute__((noinline)) void RenderRecord_SetByte98AndWord50_00901C18(int record,
                                               unsigned char byteValue,
                                               int wordValue)
{
    *(int *)(record + 0x50) = wordValue;
    *(unsigned char *)(record + 0x98) = byteValue;
}

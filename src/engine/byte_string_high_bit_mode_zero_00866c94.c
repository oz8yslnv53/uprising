unsigned int ByteString_HighBitWhenModeZero_00866C94(
    const unsigned char *text, int mode)
{
    if (mode == 0)
        return (text[0] & 0x80) >> 7;
    return 0;
}

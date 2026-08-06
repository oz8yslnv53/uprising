void Record_SetFlagByte50Shifted_0083DA40(unsigned char *record,
                                           unsigned char value)
{
    record[0x50] = value | (record[0x50] << 1);
}

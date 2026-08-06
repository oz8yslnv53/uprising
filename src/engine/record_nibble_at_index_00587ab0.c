__attribute__((noinline)) unsigned short Engine_RecordNibbleAtIndex_00587AB0(void *record,
                                                    unsigned int index)
{
    unsigned short value = *(unsigned short *)((char *)record + 0x84);
    unsigned int shift = (index & 0x3f) << 2;
    unsigned short nibble = (unsigned short)((value >> shift) & 0xf);
    return nibble == 0xf ? 0 : nibble;
}

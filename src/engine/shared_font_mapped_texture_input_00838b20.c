extern unsigned char *DAT_00838B34;
unsigned char *SharedFont_GetMappedTextureInput_00838B20(void)
{
    unsigned char *base = DAT_00838B34;
    if (base != 0)
        base += 0x80;
    return base;
}

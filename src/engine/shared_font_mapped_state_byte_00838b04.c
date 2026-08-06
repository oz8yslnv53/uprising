extern unsigned int *DAT_00838B1C;
unsigned int SharedFont_GetMappedStateByte_00838B04(void)
{
    if (DAT_00838B1C == 0)
        return 0;
    return DAT_00838B1C[1] & 0xff;
}

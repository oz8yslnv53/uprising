extern unsigned int *DAT_00838B50;
unsigned int SharedFont_GetMappedState_00838B38(void)
{
    if (DAT_00838B50 == 0)
        return 3;
    return DAT_00838B50[0];
}

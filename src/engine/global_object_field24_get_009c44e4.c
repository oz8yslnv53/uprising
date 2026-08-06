extern void *Engine_GlobalObjectGet_005AFE40(void);
__attribute__((noinline)) void *Engine_GlobalObjectField24Get_009C44E4(void)
{
    void *object = Engine_GlobalObjectGet_005AFE40();
    if (object != 0)
        return *(void **)((unsigned char *)object + 0x24u);
    return 0;
}

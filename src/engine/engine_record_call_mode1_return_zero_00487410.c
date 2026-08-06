extern void Engine_RecordCall_004C1110(void *record, int mode);
__attribute__((noinline)) int Engine_RecordCallMode1ReturnZero_00487410(void *object)
{
    Engine_RecordCall_004C1110(*(void **)((unsigned char *)object + 0x30), 1);
    return 0;
}

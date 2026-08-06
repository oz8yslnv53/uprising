extern unsigned int Engine_SelectionQuery_0090D8FC(void *selection);
__attribute__((noinline)) int Engine_RecordField20Truth_00AA4D10(void *record)
{
    return Engine_SelectionQuery_0090D8FC(*(void **)((unsigned char *)record + 0x20)) != 0;
}

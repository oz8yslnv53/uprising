extern void *StatusResource_RecordGet_00540878(void);
__attribute__((noinline)) void StatusResource_SetByte38IfPresent_004133B8(void *unused,
                                                unsigned char value)
{
    void *record;
    (void)unused;
    record = StatusResource_RecordGet_00540878();
    if (record != 0)
        *(unsigned char *)((char *)record + 0x38) = value;
}

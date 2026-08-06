extern int HID_FrameResourcePrepare_003D1B18(void *resource);
extern void Engine_BulkCopy_00425DF8(void *destination, const void *source,
                                     unsigned int size);
extern void StateResource_NotifyLoaded_003ABB48(void *resource);
__attribute__((noinline)) void HID_CopyCurrentFrame(void *state, void *output)
{
    unsigned char *bytes = (unsigned char *)state;
    HID_FrameResourcePrepare_003D1B18(bytes + 0x384);
    Engine_BulkCopy_00425DF8(output, bytes + 0x104, 0x25c);
    StateResource_NotifyLoaded_003ABB48(bytes + 0x384);
}

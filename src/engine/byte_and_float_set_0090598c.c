__attribute__((noinline)) void Engine_ByteAndFloatSet_0090598C(void * object,
                                     unsigned char byte_value,
                                     float float_value)
{
    *(float *)((char *)object + 0x9c) = float_value;
    *(unsigned char *)((char *)object + 0x95) = byte_value;
}

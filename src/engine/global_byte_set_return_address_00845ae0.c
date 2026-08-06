extern unsigned char DAT_00D4D040;
__attribute__((noinline)) unsigned char * Engine_GlobalByteSetReturnAddress_00845AE0(void * unused,
                                                            unsigned char value)
{
    (void)unused;
    DAT_00D4D040 = value;
    return &DAT_00D4D040;
}

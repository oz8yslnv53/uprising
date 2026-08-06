extern void ParameterRegistrar_Init_001EB95C(void *context,
                                              unsigned int value1,
                                              unsigned int value2,
                                              unsigned char mode);
extern void ParameterRecord_Apply_0063D5C4(void *owner, void *context);
extern void *ParameterRegistrar_Finalize_001EB9BC(void *context);
__attribute__((noinline)) int ParameterRecord_Register_00C00898(void *owner, unsigned int value1,
                                      unsigned int value2, unsigned char mode)
{
    unsigned char context[16];
    ParameterRegistrar_Init_001EB95C(context, value1, value2, mode);
    ParameterRecord_Apply_0063D5C4(*(void **)((unsigned char *)owner + 4), context);
    ParameterRegistrar_Finalize_001EB9BC(context);
    return 1;
}

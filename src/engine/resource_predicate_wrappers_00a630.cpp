extern "C" bool StatusResource_IsKind5Or6_0054ABE0(unsigned char *object);
extern "C" bool StatusResource_IsKind4_0054ABF8(unsigned char *object);
extern "C" __attribute__((noinline)) int Engine_ResourceByteOrOne_00A63050(void *record)
{
    unsigned char *bytes = (unsigned char *)record;
    if (*(int *)(bytes + 0xb4) == 0)
        return 1;
    return *(signed char *)(bytes + 0xb8);
}
extern "C" __attribute__((noinline)) bool Engine_ResourceKind5Or6_00A63064(void *record)
{
    unsigned char *object = *(unsigned char **)((char *)record + 0xb4);
    if (object == 0)
        return false;
    return StatusResource_IsKind5Or6_0054ABE0(object);
}
extern "C" __attribute__((noinline)) bool Engine_ResourceKind4_00A630B4(void *record)
{
    unsigned char *object = *(unsigned char **)((char *)record + 0xb4);
    if (object == 0)
        return false;
    return StatusResource_IsKind4_0054ABF8(object);
}

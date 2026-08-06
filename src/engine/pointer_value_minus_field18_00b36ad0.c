__attribute__((noinline)) int Engine_PointerValueMinusField18_00B36AD0(const int *object, const int *value)
{
    const int field = *(const int *)((const unsigned char *)object + 0x18);
    const int value_copy = *value;
    return value_copy - field;
}

typedef struct Engine_NestedRecord_00B4F1F0 {
    unsigned char padding[0x10c];
    void *value;
} Engine_NestedRecord_00B4F1F0;
__attribute__((noinline)) unsigned int Engine_NestedOffset10CField8Get_00B4F1F0(const void *object)
{
    const Engine_NestedRecord_00B4F1F0 *nested = *(const Engine_NestedRecord_00B4F1F0 * const *)
        ((const unsigned char *)object + 8);
    return *(const unsigned int *)((const unsigned char *)nested->value + 8);
}

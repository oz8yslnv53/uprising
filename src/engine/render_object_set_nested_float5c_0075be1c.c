__attribute__((noinline)) void RenderObject_SetNestedFloat5CIfPresent_0075BE1C(void *object, float value)
{
    int nested = *(int *)((char *)object + 0x9C);
    if (nested != 0)
        *(float *)(nested + 0x5C) = value;
}

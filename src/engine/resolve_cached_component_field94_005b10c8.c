extern void *ResolveCachedComponent_1EC(void *object);
__attribute__((noinline)) unsigned int Engine_ResolveCachedComponentField94_005B10C8(void *object)
{
    void *component = ResolveCachedComponent_1EC(object);
    return *(unsigned int *)((char *)component + 0x94);
}

extern void *ResolveRelatedComponent(void *object);
__attribute__((noinline)) unsigned int Engine_RelatedComponentField1DCGet_0043FF40(void *object)
{
    void *component = ResolveRelatedComponent(object);
    if (component != 0)
        return *(unsigned int *)((unsigned char *)component + 0x1dc);
    return 0;
}

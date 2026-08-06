#include <stdint.h>
extern void *ResourceTree_ResolveCurrentEntry_002A6268(void *owner);
extern void *FUN_002EE0C8(void *tree, void *owner);
extern int ParameterString_Equals_00425E6C(void *left, void *right);
void *ResourceTree_FindNamedEntry_001F5144(void *owner, void *name)
{
    unsigned char *entry;
    unsigned char *record;
    unsigned char *node;
    if (owner == 0 || name == 0)
        return 0;
    entry = (unsigned char *)ResourceTree_ResolveCurrentEntry_002A6268(owner);
    record = (unsigned char *)FUN_002EE0C8(
        (void *)(*(uintptr_t *)(entry + 0x20) + 8),
        owner);
    node = *(unsigned char **)(*(void **)(record + 0x40) + 0x104);
    while (node != 0) {
        if (ParameterString_Equals_00425E6C(*(void **)node, name) == 0)
            return node;
        node = *(unsigned char **)(node + 0x10C);
    }
    return 0;
}

#include <stdint.h>
extern void ParameterString_Hash_00593D58(uint32_t *key, const char *text);
extern int ParameterRecord_Find_005C076C(uint32_t *key);
__attribute__((noinline)) int ParameterObject_HashLookup_00B66020(void *object)
{
    uint32_t key[2];
    const char *name = *(const char **)((uint8_t *)object + 0x94u) + 0x2cu;
    ParameterString_Hash_00593D58(key, name);
    return ParameterRecord_Find_005C076C(key);
}

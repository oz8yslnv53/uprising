extern unsigned int Engine_FieldPredicate_005CEE90(unsigned int value);
__attribute__((noinline)) unsigned int Object_Field168PredicateNot_00A62F88(void *object)
{
    unsigned int value = *(unsigned int *)((unsigned char *)object + 0x168);
    return Engine_FieldPredicate_005CEE90(value) ^ 1;
}

extern unsigned int Engine_RangeLengthAt8_00B3AA40(unsigned int *range);
__attribute__((noinline)) int Engine_RangeLengthWithinBounds_00B3A580(void *record)
{
    unsigned int length = Engine_RangeLengthAt8_00B3AA40(
        (unsigned int *)((unsigned char *)record + 0x0c));
    if (length < *(unsigned int *)((unsigned char *)record + 0x20))
        return 0;
    length = Engine_RangeLengthAt8_00B3AA40(
        (unsigned int *)((unsigned char *)record + 0x0c));
    return length <= *(unsigned int *)((unsigned char *)record + 0x24);
}

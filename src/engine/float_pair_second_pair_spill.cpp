extern "C" __attribute__((noinline)) void FloatPairAndSecondPair_Spill_005BF2CC(
    float* output, float first_value, float first_reserved,
    float second_value, float second_reserved)
{
    output[0] = first_value;
    output[1] = first_reserved;
    output[7] = second_value;
    output[8] = second_reserved;
}

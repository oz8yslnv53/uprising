#include <stdint.h>
__attribute__((noinline)) void FloatTriple_InterpolateMiddle_0053CEFC(uint8_t *triple, float ratio)
{
    float start = *(float *)(triple + 0);
    float end = *(float *)(triple + 8);
    *(float *)(triple + 4) = start + (end - start) * ratio;
}

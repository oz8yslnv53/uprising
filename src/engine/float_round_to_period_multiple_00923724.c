#include <stdint.h>
extern float Engine_Modf_00395854(float value, float *integral);
__attribute__((noinline)) float FloatRoundToPeriodMultiple_00923724(
    float value, float period) {
    float quotient = value / period;
    float integral;
    float fraction = Engine_Modf_00395854(quotient, &integral);
    if (fraction < -0.5f) {
        integral -= 1.0f;
    } else if (fraction >= 0.5f) {
        integral += 1.0f;
    }
    return integral * period;
}

#include <cstdlib>
// Retail 009E6B3C: decimal digit count for a signed integer, capped at ten.
extern "C" __attribute__((noinline)) int RenderTarget_DigitCount_009E6B3C(int value) {
    value = std::abs(value);
    int digits = 1;
    int place = 10;
    while (place <= value && digits <= 10) {
        ++digits;
        place *= 10;
    }
    return digits;
}

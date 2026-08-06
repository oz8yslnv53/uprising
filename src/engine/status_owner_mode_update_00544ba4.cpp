#include <cstdint>
#include <stdint.h>
__attribute__((noinline)) void StatusOwner_UpdateMode_00544BA4(uint8_t *owner, uint32_t mode) {
    const int32_t previous = static_cast<int8_t>(owner[0xb5]);
    if (((previous | static_cast<int32_t>(mode)) & (mode - 1u)) == 0) {
        owner[0xb4] = static_cast<uint8_t>(mode);
    }
}

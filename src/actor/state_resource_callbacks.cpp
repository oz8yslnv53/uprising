// Retail 0x00395C14, 0x00395C24, and 0x00395C30.
#include <cstdint>
extern "C" __attribute__((noinline)) void StateResource_CopyValueIfPresent_00395C14(
    const std::uint32_t* value, std::uint32_t* destination) {
    if (destination != 0) {
        *destination = *value;
    }
}
typedef void(*StateResourceCallback_00395C24)(std::uint32_t);
extern "C" __attribute__((noinline)) void StateResource_DispatchIndirect_00395C24(
    StateResourceCallback_00395C24 target, const std::uint32_t* argument) {
    target(*argument);
}
extern "C" __attribute__((noinline)) void StateResource_Return_00395C30() {
}

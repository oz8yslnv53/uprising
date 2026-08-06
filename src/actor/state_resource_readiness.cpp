// Retail 0x0033B550. Shared state-resource readiness query.
#include <cstdint>
extern "C" int StateResource_IsLoaded_0036BA18(void* state);
extern "C" std::uint32_t StateResource_Probe_003959B8(
    void* request, std::uint32_t key, void* resource);
extern std::uint32_t DAT_0036BE60;
extern "C" __attribute__((noinline)) int StateResource_Allocate_0036BE2C(void* resource) {
    if (*reinterpret_cast<std::uint32_t*>(
            reinterpret_cast<std::uint8_t*>(resource) + 0x20) == 0 ||
        (StateResource_Probe_003959B8(
            reinterpret_cast<std::uint8_t*>(resource) + 0xC4,
            DAT_0036BE60, resource) & 0xFFu) != 0) {
        return 0;
    }
    return 1;
}
extern "C" __attribute__((noinline)) bool StateResource_IsReady_0033B550(std::uint32_t* manager) {
    if (reinterpret_cast<std::uint8_t*>(manager)[0x15] == 0) {
        return false;
    }
    return StateResource_IsLoaded_0036BA18(
               reinterpret_cast<void*>(*manager)) != 0;
}

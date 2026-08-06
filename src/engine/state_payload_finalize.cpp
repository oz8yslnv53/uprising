#include <cstdint>
extern "C" __attribute__((noinline)) void StatePayload_Finalize(void *payload, float value)
{
    std::uint8_t* handle = static_cast<std::uint8_t*>(payload);
    std::uint8_t* state = *reinterpret_cast<std::uint8_t**>(handle + 0x04);
    if (state != 0)
        *reinterpret_cast<float *>(state + 0x3c) = value;
}

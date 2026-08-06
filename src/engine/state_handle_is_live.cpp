#include <cstdint>
extern "C" __attribute__((noinline)) bool StateHandle_IsLive(const std::uint32_t handle[2])
{
    return handle[1] != 0u;
}

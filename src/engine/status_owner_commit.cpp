// KIU jp_rev1 status-owner commit leaf at 0x00580424.
#include <cstdint>
extern "C" int Engine_StatusModeIsType5();
extern "C" __attribute__((noinline)) void
Engine_StatusOwnerCommitIfNotType5(void* owner, std::uint32_t value) {
    if (Engine_StatusModeIsType5() == 0)
        *reinterpret_cast<std::uint32_t*>(
            static_cast<std::uint8_t*>(owner) + 0x2CC) = value;
}

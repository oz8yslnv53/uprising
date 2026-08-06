#include <stdint.h>
extern uint32_t Engine_GuardedStringPayloadGet_0050D9D8(const uint8_t *object);
void Engine_GuardedStringPayloadSetByte49_00592650(void *object, uint8_t value) {
    uint8_t *state = *(uint8_t **)((uint8_t *)object + 0x80u);
    if (state != 0) {
        uint8_t *payload = (uint8_t *)(uintptr_t)
            Engine_GuardedStringPayloadGet_0050D9D8(*(const uint8_t **)(state + 0x14u));
        payload[0x49u] = value;
    }
}

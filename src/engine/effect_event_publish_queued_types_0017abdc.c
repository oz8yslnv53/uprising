#include <stdint.h>
extern void EffectEvent_PublishResourceType_002B427C(void *resource_context,
                                                      uint32_t effect_type);
int FUN_0017ABDC(void *object)
{
    uint8_t *bytes = (uint8_t *)object;
    int32_t *count = (int32_t *)(bytes + 0x2bd4);
    int32_t i = 0;
    while (i < *count) {
        EffectEvent_PublishResourceType_002B427C(
            *(void **)(bytes + 0x30),
            *(uint32_t *)(bytes + 0x2bd8 + i * 4));
        ++i;
    }
    *count = 0;
    return 0;
}

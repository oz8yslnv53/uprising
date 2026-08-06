#include <stdint.h>
typedef struct ResourceVector4 {
    float value[4];
} ResourceVector4;
__attribute__((noinline)) void ResourceVector_Copy_002A2F70(uint8_t *object,
                                  const ResourceVector4 *source) {
    ResourceVector4 *destination = (ResourceVector4 *)(object + 0x10);
    *destination = *source;
}

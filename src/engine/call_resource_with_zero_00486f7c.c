#include <stdint.h>
extern void Engine_ResourceAction_004EADCC(void *resource, uint32_t mode);
__attribute__((noinline)) uint32_t Engine_CallResourceWithZero_00486F7C(void *object) {
    Engine_ResourceAction_004EADCC(*(void **)((uint8_t *)object + 0x30u), 0u);
    return 0;
}

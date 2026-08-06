#include <stdint.h>
typedef void *(*GlobalCallback_005F82CC)(uint32_t argument);
__attribute__((noinline)) void *Engine_GlobalCallbackDispatch_005F82CC(uint32_t argument)
{
    GlobalCallback_005F82CC callback =
        *(GlobalCallback_005F82CC *)((uintptr_t)0x00d4e370);
    return callback(argument);
}

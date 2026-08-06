#include <stdint.h>
extern int StateResource_Notify_003D1B1C(void *resource);
extern void StateResource_NotifyLoaded_003ABB48(void *resource);
extern void FUN_001E796C(void *event, int value);
__attribute__((noinline)) int RingQueue_Pop_001BA034(uint32_t *queue, uint32_t *output) {
    void *resource = queue + 5;
    StateResource_Notify_003D1B1C(resource);
    if (queue[10] == 0) {
        StateResource_NotifyLoaded_003ABB48(resource);
        return 0;
    }
    *output = ((uint32_t *)(uintptr_t)queue[0])[queue[9]];
    queue[9] = (queue[9] + 1u) % queue[8];
    queue[10] -= 1u;
    if (queue[12] != 0)
        FUN_001E796C(queue + 3, 1);
    StateResource_NotifyLoaded_003ABB48(resource);
    return 1;
}

#include <stdint.h>
extern void *Engine_LazySingletonGetter_00520634(void);
typedef void (*ServiceNotify)(void *service, void *state);
__attribute__((noinline)) uint32_t FlaggedService_Dispatch_00704528(void *state) {
    static volatile void **const service_slot =
        (volatile void **)0x00d63528u;
    uint8_t *bytes = (uint8_t *)state;
    if (bytes[0x10e8] == 1u) {
        void *service = (void *)*service_slot;
        if (service == 0) {
            service = Engine_LazySingletonGetter_00520634();
            *service_slot = service;
        }
        {
            void *interface_object = *(void **)service;
            void **vtable = *(void ***)interface_object;
            ((ServiceNotify)vtable[3])(interface_object, state);
        }
        bytes[0x10e8] = 0;
    }
    return 0;
}

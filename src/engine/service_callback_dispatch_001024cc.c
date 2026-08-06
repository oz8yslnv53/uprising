#include <stdint.h>
#include "engine_common_views.h"
typedef void (*ServiceCallback)(uint32_t argument);
__attribute__((noinline)) void Engine_ServiceCallbackDispatch_001024CC(void)
{
    volatile struct EngineGlobalRecordD4D4C8View *state =
        (volatile struct EngineGlobalRecordD4D4C8View *)(uintptr_t)0x00D4D4C8u;
    ServiceCallback first = (ServiceCallback)state->callback_040;
    if (first != 0)
        first(state->callback_argument_080);
    ServiceCallback second = (ServiceCallback)state->callback_044;
    if (second != 0)
        second(state->callback_argument_084);
}

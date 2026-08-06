#include <stdint.h>
extern uint32_t ResourceStream_Load_0090E0E4(
    uint32_t *output, uint32_t source, uint32_t descriptor,
    uint32_t flags, uint32_t stream_size, int distributed);
uint32_t ResourceRecord_CreateVfpForwarder_0090E034(
    uint32_t *output, uint32_t source, uint32_t descriptor,
    uint32_t flags, uint32_t stream_size, int distributed)
{
    return ResourceStream_Load_0090E0E4(
        output, source, descriptor, flags, stream_size, distributed);
}

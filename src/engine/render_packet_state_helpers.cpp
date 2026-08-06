#include <stdint.h>
static uint8_t *const g_render_context = (uint8_t *)0x00DBC490u;
extern "C" __attribute__((noinline)) void RenderCommand_ClearPacketFlag_00152978(int index) {
    uint8_t *packet = *(uint8_t **)(g_render_context + 0x9c);
    if (packet == (uint8_t *)0)
        return;
    if (index == -1)
        *(uint8_t *)(packet + 0x3c) = 0;
    else {
        uint8_t *records = *(uint8_t **)(packet + 0x18);
        records[index * 0x1c - 0x1b] = 0;
    }
}
extern "C" __attribute__((noinline)) void RenderCommand_SetPacketMode_00153880(uint32_t mode) {
    uint8_t *packet = *(uint8_t **)(g_render_context + 0x9c);
    if (packet != (uint8_t *)0)
        *(uint32_t *)(packet + 0x38) = mode;
}
extern "C" __attribute__((noinline)) void RenderCommand_SetResolutionMode_00153898(uint32_t mode) {
    uint32_t *context = (uint32_t *)g_render_context;
    if (context[0x164 / 4] == mode)
        return;
    if (mode == 0x700u || mode == 0x702u)
        context[2] = 400;
    else if (mode == 0x701u)
        context[2] = 800;
    else
        return;
    context[0x164 / 4] = mode;
}

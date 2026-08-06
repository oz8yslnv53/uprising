#include <stdint.h>
extern void ResourceState_Initialize_0043118C(void *context, void *record);
extern uint8_t ResourceState_Refresh_0045E2CC(void *context, uint32_t mode,
                                               float phase);
__attribute__((noinline)) int ResourceState_InitializeThenRefresh_00430E8C(void *context,
                                                  uint8_t *record,
                                                  void *unused,
                                                  uint8_t *phase_record) {
    (void)unused;
    ResourceState_Initialize_0043118C(context, record + 0xCu);
    if (record[0x11u] == 0u)
        record[0x11u] = ResourceState_Refresh_0045E2CC(
            context, 0u, *(float *)(phase_record + 0xCu));
    return 0;
}

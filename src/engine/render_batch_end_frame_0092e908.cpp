// KIU jp_rev1 0x0092E908.  Generic render-command end-frame cleanup.
#include <cstdint>
extern "C" void RenderCommand_QueryState_001B4F50(std::uint32_t,
                                                    std::uint32_t*);
extern "C" void RenderCommand_AdvanceAllocation_00153868(std::uint32_t);
extern "C" void RenderResource_ResetPool_00B87C90(void*, std::uint32_t);
extern "C" void RenderResource_ClearSlotDirty_00B8850C(std::uint32_t);
extern "C" __attribute__((noinline)) void
RenderBatch_EndFrame_0092E908(void*  ) {
    std::uint32_t record;
    RenderCommand_QueryState_001B4F50(0x208, &record);
    if ((record & 8u) != 0) {
        std::uint32_t* words = reinterpret_cast<std::uint32_t*>(record);
        words[0] = 0;
        words[1] = 0;
        RenderCommand_AdvanceAllocation_00153868(8);
    }
    RenderResource_ResetPool_00B87C90(reinterpret_cast<void*>(0x00008892u), 0);
    RenderResource_ResetPool_00B87C90(reinterpret_cast<void*>(0x00008893u), 0);
    for (std::uint32_t slot = 0; slot != 12; ++slot)
        RenderResource_ClearSlotDirty_00B8850C(slot);
}

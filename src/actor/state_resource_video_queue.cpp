#include <cstdint>
extern "C" std::uint32_t StateResource_WaitForBackend_004DF2AC(
    void* backend);
extern "C" std::uint32_t StateResource_CountCompletedY2RJobs_00511CB4(
    void* backend);
extern "C" void VideoCodec_RecordClose_0034C1D0(std::uint32_t index);
extern "C" void Thread_SleepNanoseconds_003F34A4(
    std::uint64_t nanoseconds);
extern "C" int Platform_ServiceCommand_00353A4C(
    void* output, void* input, std::uint32_t input_size,
    std::uint32_t output_size, std::uint32_t command,
    std::uint32_t flags);
extern "C" void Platform_ReportServiceError_003D1B64(void);
extern "C" std::uint32_t Y2R_QueuedConversionWorker_005441C0(void* backend);
extern "C" std::uint32_t DAT_004DF370;
namespace {
std::uint32_t stream_step(std::uint8_t* resource, std::int32_t stream_index) {
    const std::uintptr_t state_address =
        reinterpret_cast<std::uintptr_t>(resource) +
        static_cast<std::uint32_t>(stream_index) * 0x28 + 0x16c;
    if (state_address == 0)
        return 0;
    const std::uint32_t mode =
        *reinterpret_cast<const std::uint32_t*>(state_address + 8);
    return mode < 2 ? 2 : 1;
}
}  // namespace
extern "C" __attribute__((noinline)) std::uint32_t StateResource_WaitForBackend_004DF2AC(
    void* backend) {
    std::uint8_t output[4] = {};
    const std::uint32_t command = 0x01312D00u;
    std::uint32_t input = DAT_004DF370;
    for (;;) {
        if (Y2R_QueuedConversionWorker_005441C0(backend) != 0)
            return 1;
        const int result = Platform_ServiceCommand_00353A4C(
            output, &input, 1, 0, command, 0);
        if (result < 0)
            Platform_ReportServiceError_003D1B64();
    }
}
extern "C" __attribute__((noinline)) void VideoBufferRecord_SelectUnusedIndex_003D36A8(void* record) {
    std::int8_t* bytes = static_cast<std::int8_t*>(record);
    const std::int8_t next = static_cast<std::int8_t>((bytes[0x1A] + 1) % 2);
    bytes[0x1A] = next;
    if (bytes[0x18] != next && bytes[0x19] != next)
        return;
    bytes[0x1A] = static_cast<std::int8_t>((next + 1) % 2);
}
extern "C" __attribute__((noinline)) void FUN_00511A78(void* resource) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(resource);
    for (;;) {
        if (bytes[0xec] == 1)
            return;
        std::int32_t lane;
        if (*reinterpret_cast<std::int32_t*>(bytes + 0x1c4) >= 0)
            lane = 0;
        else if (*reinterpret_cast<std::int32_t*>(bytes + 0x1c8) >= 0)
            lane = 1;
        else
            continue;
        const std::int32_t stream_index = *reinterpret_cast<std::int32_t*>(
            bytes + 0x1c4 + lane * 4);
        const std::uint32_t step = stream_step(bytes, stream_index);
        const std::int32_t available =
            *reinterpret_cast<std::int32_t*>(bytes + 0x1cc + lane * 4) -
            *reinterpret_cast<std::int32_t*>(bytes + 0x1d4 + lane * 4);
        if (available < static_cast<std::int32_t>(step)) {
            Thread_SleepNanoseconds_003F34A4(500000);
            continue;
        }
        const std::int32_t consumed = *reinterpret_cast<std::int32_t*>(
            bytes + 0x1d4 + lane * 4);
        const std::int32_t ring_index = consumed % 16;
        const std::uint64_t timestamp = *reinterpret_cast<std::uint64_t*>(
            bytes + 0x228 + lane * 0x80 + ring_index * 8);
        *reinterpret_cast<std::uint64_t*>(bytes + 0x338) =
            *reinterpret_cast<std::uint64_t*>(bytes + 0x330) + timestamp;
        return;
    }
}
extern "C" __attribute__((noinline)) bool StateResource_AdvanceStreamsIfReady_003D36F4(
    void* resource) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(resource);
    for (std::uint32_t lane = 0; lane < 2; ++lane) {
        const std::int32_t stream_index = *reinterpret_cast<std::int32_t*>(
            bytes + 0x1c4 + lane * 4);
        if (stream_index < 0)
            continue;
        void* stream = *reinterpret_cast<void**>(
            bytes + 0x164 + stream_index * 4);
        std::int32_t available;
        void** vtable = *static_cast<void***>(stream);
        reinterpret_cast<void (*)(void*, std::int32_t*)>(vtable[4])(
            stream, &available);
        if (available <
            static_cast<std::int32_t>(stream_step(bytes, stream_index) * 2))
            return false;
    }
    for (std::uint32_t lane = 0; lane < 2; ++lane) {
        const std::int32_t stream_index = *reinterpret_cast<std::int32_t*>(
            bytes + 0x1c4 + lane * 4);
        if (stream_index < 0)
            continue;
        void* stream = *reinterpret_cast<void**>(
            bytes + 0x164 + stream_index * 4);
        void** vtable = *static_cast<void***>(stream);
        void (*const advance)(void*) = reinterpret_cast<void (*)(void*)>(vtable[7]);
        const std::uint32_t step = stream_step(bytes, stream_index);
        for (std::uint32_t i = 0; i < step; ++i)
            advance(stream);
    }
    const std::uint64_t position =
        *reinterpret_cast<std::uint64_t*>(bytes + 0x220);
    *reinterpret_cast<std::uint64_t*>(bytes + 0x340) = 0;
    for (std::uint32_t lane = 0; lane < 2; ++lane) {
        const std::int32_t stream_index = *reinterpret_cast<std::int32_t*>(
            bytes + 0x1c4 + lane * 4);
        if (stream_index < 0)
            continue;
        if (*reinterpret_cast<std::uint64_t*>(bytes + 0x340) == 0) {
            const std::int32_t consumed = *reinterpret_cast<std::int32_t*>(
                bytes + 0x1d4 + lane * 4);
            const std::int32_t ring_index = consumed % 16;
            *reinterpret_cast<std::uint64_t*>(bytes + 0x340) =
                *reinterpret_cast<std::uint64_t*>(
                    bytes + 0x228 + lane * 0x80 + ring_index * 8);
        }
        const std::uint32_t step = stream_step(bytes, stream_index);
        *reinterpret_cast<std::uint32_t*>(
            bytes + 0x1d4 + lane * 4) += step;
        if (*reinterpret_cast<std::uint64_t*>(bytes + 0x220) == position)
            *reinterpret_cast<std::uint64_t*>(bytes + 0x220) += step;
    }
    ++*reinterpret_cast<std::uint64_t*>(bytes + 0x218);
    FUN_00511A78(resource);
    return true;
}
extern "C" __attribute__((noinline)) bool StateResource_DrainY2RQueue_003D38C8(void* resource) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(resource);
    const bool complete = StateResource_WaitForBackend_004DF2AC(bytes + 4) != 0;
    if (!complete)
        bytes[0xEC] = 7;
    return complete;
}
extern "C" __attribute__((noinline)) bool StateResource_AreQueuedY2RJobsComplete_003D38F0(
    void* resource) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(resource);
    const std::uint32_t queued =
        *reinterpret_cast<std::uint32_t*>(bytes + 0xAC);
    const std::uint32_t consumed =
        *reinterpret_cast<std::uint32_t*>(bytes + 0xB0);
    if (queued == consumed)
        return false;
    return StateResource_CountCompletedY2RJobs_00511CB4(bytes + 4) >=
        queued - consumed;
}
extern "C" __attribute__((noinline)) void StateResource_ClosePendingCodecRecord_003D3FD4(void* slot) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(slot);
    const std::uint32_t index =
        *reinterpret_cast<std::uint32_t*>(bytes + 4);
    if (index != UINT32_MAX && bytes[0x18] == 0) {
        VideoCodec_RecordClose_0034C1D0(index);
        bytes[0x18] = 1;
        bytes[0x19] = 0;
    }
}
extern "C" __attribute__((noinline)) bool StateResource_HasPendingY2RWork_003D8220(void* resource) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(resource);
    return *reinterpret_cast<std::uint32_t*>(bytes + 0xAC) !=
        *reinterpret_cast<std::uint32_t*>(bytes + 0xB0);
}

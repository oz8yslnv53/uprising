#include <cstddef>
#include <cstdint>
extern "C" void* FUN_003DC5D0(void* destination, std::uint32_t size) throw();
namespace {
struct PacketView {
    std::uint32_t allocator_key;
    std::uint8_t* backing;
    std::uint32_t byte_size;
    std::uint32_t opaque_0c;
    std::uint32_t opaque_10;
    std::uint32_t opaque_14;
    std::uint8_t* records;
    std::uint32_t record_count;
    std::uint32_t record_cursor;
    std::uint32_t opaque_24;
    std::uint32_t opaque_28;
    std::uint32_t mode;
    std::uint32_t opaque_30;
    std::uint32_t opaque_34;
    std::uint8_t opaque_38[5];
    std::uint8_t flag_3d;
};
typedef char kiu_sa_render_command_packet_backing_1[(offsetof(PacketView, backing) == 0x04) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_render_command_packet_backing_2[(offsetof(PacketView, byte_size) == 0x08) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_render_command_packet_backing_3[(offsetof(PacketView, records) == 0x18) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_render_command_packet_backing_4[(offsetof(PacketView, record_count) == 0x1c) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_render_command_packet_backing_5[(offsetof(PacketView, mode) == 0x2c) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_render_command_packet_backing_6[(offsetof(PacketView, flag_3d) == 0x3d) ? 1 : -1] __attribute__((unused));
typedef void*(*Allocate)(std::uint32_t, std::uint32_t, std::uint32_t,
                           std::uint32_t);
typedef void(*Release)(std::uint32_t, std::uint32_t, std::uint32_t);
PacketView* SelectedPacket() {
    std::uint8_t* context = reinterpret_cast<std::uint8_t*>(0x00dbc490u);
    return *reinterpret_cast<PacketView**>(context + 0x9c);
}
}  // namespace
extern "C" __attribute__((noinline)) void FUN_00224E24(std::uint32_t byte_size,
                              std::uint32_t record_count) {
    PacketView* packet = SelectedPacket();
    if (packet == 0)
        return;
    std::uintptr_t* callbacks = reinterpret_cast<std::uintptr_t*>(0x00d4d45cu);
    if (packet->backing != 0 && callbacks[1] != 0) {
        reinterpret_cast<Release>(callbacks[1])(
            0x10000, 0x105, packet->allocator_key);
    }
    packet->opaque_0c = 0;
    packet->byte_size = byte_size;
    packet->record_count = record_count;
    packet->record_cursor = 0;
    packet->opaque_10 = 0;
    packet->opaque_28 = 0;
    packet->opaque_24 = 0;
    packet->opaque_34 = 0;
    packet->opaque_30 = 0;
    Allocate allocate = reinterpret_cast<Allocate>(callbacks[0]);
    packet->backing =
        allocate == 0
            ? 0
            : static_cast<std::uint8_t*>(allocate(
                  0x10000, 0x105, packet->allocator_key,
                  byte_size + record_count * 0x1c));
    packet->records = packet->backing + byte_size;
    FUN_003DC5D0(packet->records, record_count * 0x1c);
    *reinterpret_cast<std::uint8_t**>(0x00d4d134u) = packet->backing;
    *reinterpret_cast<std::uint8_t**>(0x00d4d138u) =
        packet->backing + byte_size;
}
// Retail 0x0026189C. Updates the selected packet's small mode fields.
extern "C" __attribute__((noinline)) void FUN_0026189C(std::uint32_t selector,
                              std::uint32_t value) {
    PacketView* packet = SelectedPacket();
    if (packet == 0)
        return;
    if (selector == 0x200)
        packet->mode = value;
    else if (selector == 0x20f)
        packet->flag_3d = value != 0;
}

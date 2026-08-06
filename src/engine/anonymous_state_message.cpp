#include <cstddef>
#include <cstdint>
extern "C" void* Engine_AllocateTaggedBlock(std::uint32_t element_size,
                                              const void* type_tag,
                                              std::uint32_t count);
extern "C" int FUN_003B4FE4(void* guard);
extern "C" void* Engine_LazyStrideRegistry_003B6D84();
extern "C" void OrderedTree_UnlinkNode_003D40E0(void* node,
                                                 void* replacement);
extern "C" void* Engine_AllocateResource_003B5A8C(
    void* descriptor, void* initializer, std::uint32_t count);
extern "C" std::uint32_t g_AnonymousMessageKeyGuard_00D63488;
extern "C" std::uint32_t g_AnonymousMessageKey_00D6348C;
extern "C" std::uint32_t g_MessageKeyCounter_00D63520;
extern "C" void* g_MessageStrideRegistry_00D63714;
extern "C" std::uint32_t g_AnonymousMessageType_00C9B80C;
extern "C" void* g_AnonymousMessageBaseVtable_00D1DA84[];
extern "C" void* g_AnonymousMessageCopyBaseVtable_00D1EA30[];
extern "C" void* g_AnonymousMessageVtable_00CFCA90[];
extern "C" std::uint32_t g_MessageCloneOuterGuard_00D63B70;
extern "C" void* g_MessageCloneSentinel_00D63B74;
extern "C" std::uint32_t g_MessageCloneLinkGuard_00D627E4;
extern "C" void* g_MessageCloneLink_00D627E8;
extern "C" std::uint32_t g_MessageCloneRootGuard_00D619C8;
extern "C" void* g_MessageCloneRoot_00D619CC;
namespace {
struct MessageLinks {
    void* owner;
    MessageLinks* next;
    MessageLinks* previous;
};
struct AnonymousStateMessage {
    void** vtable;
    std::uint32_t key;
    MessageLinks first_links;
    MessageLinks second_links;
    std::uint32_t type;
    std::uint32_t flags;
    std::uint8_t option;
    std::uint8_t variant;
    std::uint8_t padding[2];
};
typedef char kiu_sa_anonymous_state_message_1[(sizeof(AnonymousStateMessage) == 0x2c) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_anonymous_state_message_2[(offsetof(AnonymousStateMessage, first_links) == 0x08) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_anonymous_state_message_3[(offsetof(AnonymousStateMessage, second_links) == 0x14) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_anonymous_state_message_4[(offsetof(AnonymousStateMessage, type) == 0x20) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_anonymous_state_message_5[(offsetof(AnonymousStateMessage, option) == 0x28) ? 1 : -1] __attribute__((unused));
const std::uint32_t kAllocationTag = 0;
void InitializeLinks(AnonymousStateMessage* message) {
    message->first_links.owner = message;
    message->first_links.next = &message->first_links;
    message->first_links.previous = &message->first_links;
    message->second_links.owner = message;
    message->second_links.next = &message->second_links;
    message->second_links.previous = &message->second_links;
}
void EnsureCloneSentinel() {
    if ((g_MessageCloneOuterGuard_00D63B70 & 1) == 0 &&
        FUN_003B4FE4(&g_MessageCloneOuterGuard_00D63B70) != 0) {
        if ((g_MessageCloneLinkGuard_00D627E4 & 1) == 0 &&
            FUN_003B4FE4(&g_MessageCloneLinkGuard_00D627E4) != 0) {
            if ((g_MessageCloneRootGuard_00D619C8 & 1) == 0 &&
                FUN_003B4FE4(&g_MessageCloneRootGuard_00D619C8) != 0) {
                g_MessageCloneRoot_00D619CC = 0;
            }
            g_MessageCloneLink_00D627E8 = &g_MessageCloneRoot_00D619CC;
        }
        g_MessageCloneSentinel_00D63B74 = &g_MessageCloneLink_00D627E8;
    }
}
bool IsCloneSourceRegistered(AnonymousStateMessage* source) {
    typedef void*(*GetRegistryNode)(AnonymousStateMessage*);
    GetRegistryNode get_node = reinterpret_cast<GetRegistryNode>(source->vtable[0]);
    void* node = get_node(source);
    while (node != 0 && node != &g_MessageCloneSentinel_00D63B74) {
        node = *static_cast<void**>(node);
    }
    return node != 0;
}
}  // namespace
extern "C" __attribute__((noinline)) void* AnonymousStateMessage_GetUpdateResult_009230AC(
    void* message) {
    (void)message;
    return 0;
}
extern "C" __attribute__((noinline)) void AnonymousStateMessage_MarkConsumed_0092322C(
    AnonymousStateMessage* message) {
    message->option = 1;
}
extern "C" __attribute__((noinline)) void* AnonymousStateMessage_Destroy_00A4B528(void* object) {
    std::uint8_t* node = static_cast<std::uint8_t*>(object) + 4;
    std::uint8_t* replacement = node;
    if (node[0x10] != 0) {
        while (replacement[0x10] != 0) {
            replacement = *reinterpret_cast<std::uint8_t**>(replacement + 4);
        }
        OrderedTree_UnlinkNode_003D40E0(node, replacement);
    }
    return object;
}
extern "C" __attribute__((noinline)) AnonymousStateMessage* AnonymousStateMessage_Construct_00B67718(
    void* unused, std::uint32_t count) {
    (void)unused;
    AnonymousStateMessage* message = static_cast<AnonymousStateMessage*>(
        Engine_AllocateTaggedBlock(sizeof(AnonymousStateMessage),
                                   &kAllocationTag, count));
    if (message == 0) {
        return 0;
    }
    message->vtable = g_AnonymousMessageBaseVtable_00D1DA84;
    if ((g_AnonymousMessageKeyGuard_00D63488 & 1) == 0 &&
        FUN_003B4FE4(&g_AnonymousMessageKeyGuard_00D63488) != 0) {
        g_AnonymousMessageKey_00D6348C = g_MessageKeyCounter_00D63520++;
    }
    message->key = g_AnonymousMessageKey_00D6348C;
    if (g_MessageStrideRegistry_00D63714 == 0) {
        g_MessageStrideRegistry_00D63714 = Engine_LazyStrideRegistry_003B6D84();
    }
    InitializeLinks(message);
    message->type = g_AnonymousMessageType_00C9B80C;
    message->flags = 0xfffffffe;
    message->option = 0;
    message->vtable = g_AnonymousMessageVtable_00CFCA90;
    message->variant = 0;
    return message;
}
extern "C" __attribute__((noinline)) AnonymousStateMessage* AnonymousStateMessage_Clone_00B67828(
    void* unused, std::uint32_t count, AnonymousStateMessage* source) {
    (void)unused;
    EnsureCloneSentinel();
    if (!IsCloneSourceRegistered(source)) {
        return 0;
    }
    AnonymousStateMessage* copy = static_cast<AnonymousStateMessage*>(
        Engine_AllocateTaggedBlock(sizeof(AnonymousStateMessage),
                                   &kAllocationTag, count));
    if (copy == 0) {
        return 0;
    }
    copy->key = source->key;
    InitializeLinks(copy);
    copy->type = source->type;
    copy->vtable = g_AnonymousMessageCopyBaseVtable_00D1EA30;
    copy->flags = source->flags;
    copy->option = source->option & 1;
    copy->vtable = g_AnonymousMessageVtable_00CFCA90;
    copy->variant = source->variant;
    return copy;
}
extern "C" __attribute__((noinline)) void*
AnonymousStateMessage_GetCloneRegistryNode_00B679C0() {
    EnsureCloneSentinel();
    return &g_MessageCloneSentinel_00D63B74;
}
extern "C" __attribute__((noinline)) void*
AnonymousStateMessage_GetCloneFactory_00A4B4A0() {
    std::uint32_t guard =
        *reinterpret_cast<std::uint32_t*>(0x00d3b080u);
    if ((guard & 1u) == 0 && FUN_003B4FE4(&guard) != 0) {
        void* initializer = reinterpret_cast<void*>(0x00c9be90u);
        std::uint8_t* body = static_cast<std::uint8_t*>(
            Engine_AllocateResource_003B5A8C(
                reinterpret_cast<void*>(0x00d6d278u),
                &initializer, 1));
        *reinterpret_cast<void**>(body - 4) =
            reinterpret_cast<void*>(0x00d23ab8u);
        *reinterpret_cast<void**>(body + 0x20) = initializer;
        *reinterpret_cast<std::uint32_t*>(body + 0x24) = 0x2c;
    }
    return reinterpret_cast<void*>(0x00d6d274u);
}
extern "C" __attribute__((noinline)) void
AnonymousStateMessage_AssignCloneFactory_00B67A80(
    void** output, void*) {
    *output = AnonymousStateMessage_GetCloneFactory_00A4B4A0();
}

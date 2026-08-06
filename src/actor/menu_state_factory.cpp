#include <cstdint>
#include "engine_common_views.h"
extern "C" int OnceGuard_TestAndSet_003B4FE4(std::uint32_t* lazy_slot);
extern "C" void* Engine_AllocateResource_003B5A8C(
    void* descriptor, void* initializer, std::uint32_t count);
extern "C" void* Engine_AllocateTaggedBlock(
    std::uint32_t element_size, void* type_tag, std::uint32_t count);
extern "C" void* Engine_LazyStrideRegistry_003B6D84();
extern "C" void* ResourceTree_ResolveCurrentEntry_002A6268(void* owner);
extern "C" void* Engine_GetCommandObjectPayload_003D92BC(void* owner);
extern "C" void* OrderedTree_LowerBoundBySignedKey_00390A98(
    void* tree, std::int32_t key);
extern "C" void* ActorStateMachine_RequestStateByFactory_0036BEF0(
    void* machine, void* factory_slot);
struct StMenuAppearStateRecordView {
    std::uint32_t implementation_00;
    std::uint32_t opaque_04;
    std::uint32_t opaque_08;
};
typedef char kiu_sa_menu_state_factory_2[(sizeof(StMenuAppearStateRecordView) == 0x0c) ? 1 : -1] __attribute__((unused));
struct StMenuDisappearStateRecordView {
    std::uint32_t implementation_00;
    std::uint32_t opaque_04;
    std::uint32_t opaque_08;
    std::uint8_t initial_flag_0c;
    std::uint8_t padding_0d_0f[3];
};
typedef char kiu_sa_menu_state_factory_3[(sizeof(StMenuDisappearStateRecordView) == 0x10) ? 1 : -1] __attribute__((unused));
struct StMenuForcusStateRecordView {
    std::uint32_t implementation_00;
    std::uint32_t opaque_04;
    std::uint32_t opaque_08;
    std::uint8_t initial_flag_0c;
    std::uint8_t padding_0d_0f[3];
};
typedef char kiu_sa_menu_state_factory_4[(sizeof(StMenuForcusStateRecordView) == 0x10) ? 1 : -1] __attribute__((unused));
namespace {
template <typename T>
T& At(std::uintptr_t address) {
    return *reinterpret_cast<T*>(address);
}
bool BeginOnce(std::uintptr_t address) {
    std::uint32_t* guard = reinterpret_cast<std::uint32_t*>(address);
    return (*guard & 1u) == 0 && OnceGuard_TestAndSet_003B4FE4(guard) != 0;
}
}  // namespace
extern "C" __attribute__((noinline)) StateFactoryRecordView* StMenuDisappear_Factory_0028AADC(void) {
    std::uint32_t* guard = reinterpret_cast<std::uint32_t*>(0x00D457D0u);
    if ((*guard & 1u) == 0 && OnceGuard_TestAndSet_003B4FE4(guard) != 0) {
        std::uint32_t initializer = 0x00CA090Cu;
        void* resource = Engine_AllocateResource_003B5A8C(
            reinterpret_cast<void*>(0x00D72C0Cu), &initializer, 1);
        StateFactoryRecordView* record = reinterpret_cast<StateFactoryRecordView*>(
            static_cast<std::uint8_t*>(resource) - 4);
        record->factory_vtable_00 = reinterpret_cast<void*>(0x00D0D3FCu);
        record->name_024 = reinterpret_cast<const char*>(initializer);
        record->state_size_028 = 0x10u;
    }
    return reinterpret_cast<StateFactoryRecordView*>(0x00D72C08u);
}
extern "C" __attribute__((noinline)) StateFactoryRecordView* StMenuLoadWait_Factory_00284E48(void) {
    std::uint32_t* guard = reinterpret_cast<std::uint32_t*>(0x00D457D8u);
    if ((*guard & 1u) == 0 && OnceGuard_TestAndSet_003B4FE4(guard) != 0) {
        std::uint32_t initializer = 0x00CA0934u;
        void* resource = Engine_AllocateResource_003B5A8C(
            reinterpret_cast<void*>(0x00D72C64u), &initializer, 1);
        StateFactoryRecordView* record = reinterpret_cast<StateFactoryRecordView*>(
            static_cast<std::uint8_t*>(resource) - 4);
        record->factory_vtable_00 = reinterpret_cast<void*>(0x00D0CCB4u);
        record->name_024 = reinterpret_cast<const char*>(initializer);
        record->state_size_028 = 0x0cu;
    }
    return reinterpret_cast<StateFactoryRecordView*>(0x00D72C60u);
}
extern "C" __attribute__((noinline)) StateFactoryRecordView* StMenuForcus_Factory_0027D058(void) {
    std::uint32_t* guard = reinterpret_cast<std::uint32_t*>(0x00D457D4u);
    if ((*guard & 1u) == 0 && OnceGuard_TestAndSet_003B4FE4(guard) != 0) {
        std::uint32_t initializer = 0x00CA0920u;
        void* resource = Engine_AllocateResource_003B5A8C(
            reinterpret_cast<void*>(0x00D72C38u), &initializer, 1);
        StateFactoryRecordView* record = reinterpret_cast<StateFactoryRecordView*>(
            static_cast<std::uint8_t*>(resource) - 4);
        record->factory_vtable_00 = reinterpret_cast<void*>(0x00D057DCu);
        record->name_024 = reinterpret_cast<const char*>(initializer);
        record->state_size_028 = 0x10u;
    }
    return reinterpret_cast<StateFactoryRecordView*>(0x00D72C34u);
}
extern "C" __attribute__((noinline)) StateFactoryRecordView* StMenuBase_Factory_0022CC34(void) {
    std::uint32_t* guard = reinterpret_cast<std::uint32_t*>(0x00D457CCu);
    if ((*guard & 1u) == 0 && OnceGuard_TestAndSet_003B4FE4(guard) != 0) {
        std::uint32_t initializer = 0x00CA08FCu;
        void* resource = Engine_AllocateResource_003B5A8C(
            reinterpret_cast<void*>(0x00D72BE0u), &initializer, 1);
        StateFactoryRecordView* record = reinterpret_cast<StateFactoryRecordView*>(
            static_cast<std::uint8_t*>(resource) - 4);
        record->factory_vtable_00 = reinterpret_cast<void*>(0x00CFD174u);
        record->name_024 = reinterpret_cast<const char*>(initializer);
        record->state_size_028 = 0x0cu;
    }
    return reinterpret_cast<StateFactoryRecordView*>(0x00D72BDCu);
}
extern "C" __attribute__((noinline)) StateFactoryRecordView* StMenuStay_Factory_0022CCBC(void) {
    std::uint32_t* guard = reinterpret_cast<std::uint32_t*>(0x00D457E0u);
    if ((*guard & 1u) == 0 && OnceGuard_TestAndSet_003B4FE4(guard) != 0) {
        std::uint32_t initializer = 0x00CA095Cu;
        void* resource = Engine_AllocateResource_003B5A8C(
            reinterpret_cast<void*>(0x00D72CBCu), &initializer, 1);
        StateFactoryRecordView* record = reinterpret_cast<StateFactoryRecordView*>(
            static_cast<std::uint8_t*>(resource) - 4);
        record->factory_vtable_00 = reinterpret_cast<void*>(0x00CFD190u);
        record->name_024 = reinterpret_cast<const char*>(initializer);
        record->state_size_028 = 0x0cu;
    }
    return reinterpret_cast<StateFactoryRecordView*>(0x00D72CB8u);
}
extern "C" __attribute__((noinline)) StateFactoryRecordView* StMenuNoForcus_Factory_0023B79C(void) {
    std::uint32_t* guard = reinterpret_cast<std::uint32_t*>(0x00D457DCu);
    if ((*guard & 1u) == 0 && OnceGuard_TestAndSet_003B4FE4(guard) != 0) {
        std::uint32_t initializer = 0x00CA0948u;
        void* resource = Engine_AllocateResource_003B5A8C(
            reinterpret_cast<void*>(0x00D72C90u), &initializer, 1);
        StateFactoryRecordView* record = reinterpret_cast<StateFactoryRecordView*>(
            static_cast<std::uint8_t*>(resource) - 4);
        record->factory_vtable_00 = reinterpret_cast<void*>(0x00D0CCD0u);
        record->name_024 = reinterpret_cast<const char*>(initializer);
        record->state_size_028 = 0x10u;
    }
    return reinterpret_cast<StateFactoryRecordView*>(0x00D72C8Cu);
}
extern "C" __attribute__((noinline)) StateFactoryRecordView* StMenuAppear_Factory_00234A94(void) {
    std::uint32_t* guard = reinterpret_cast<std::uint32_t*>(0x00D457C8u);
    if ((*guard & 1u) == 0 && OnceGuard_TestAndSet_003B4FE4(guard) != 0) {
        std::uint32_t initializer = 0x00CA08E8u;
        void* resource = Engine_AllocateResource_003B5A8C(
            reinterpret_cast<void*>(0x00D72BB4u), &initializer, 1);
        StateFactoryRecordView* record = reinterpret_cast<StateFactoryRecordView*>(
            static_cast<std::uint8_t*>(resource) - 4);
        record->factory_vtable_00 = reinterpret_cast<void*>(0x00D057C0u);
        record->name_024 = reinterpret_cast<const char*>(initializer);
        record->state_size_028 = 0x0cu;
    }
    return reinterpret_cast<StateFactoryRecordView*>(0x00D72BB0u);
}
extern "C" __attribute__((noinline)) std::uint32_t MenuState_RequestAppearOrStay_002B692C(
    void* owner, void*, void*, void*) {
    std::uint8_t* entry = static_cast<std::uint8_t*>(ResourceTree_ResolveCurrentEntry_002A6268(
        *reinterpret_cast<void**>(static_cast<std::uint8_t*>(owner) + 0x30)));
    void* factory = (entry[0x64] & 4u) != 0
        ? static_cast<void*>(StMenuStay_Factory_0022CCBC())
        : static_cast<void*>(StMenuAppear_Factory_00234A94());
    ActorStateMachine_RequestStateByFactory_0036BEF0(
        *reinterpret_cast<void**>(static_cast<std::uint8_t*>(owner) + 0x30),
        &factory);
    return 0;
}
extern "C" __attribute__((noinline)) std::uint32_t MenuState_RequestForcusOrNoForcus_002EF424(
    void* owner, void*, void*, void*) {
    std::uint8_t* owner_bytes = static_cast<std::uint8_t*>(owner);
    std::uint8_t* candidate = static_cast<std::uint8_t*>(OrderedTree_LowerBoundBySignedKey_00390A98(
        Engine_GetCommandObjectPayload_003D92BC(
            *reinterpret_cast<void**>(owner_bytes + 0x30)), 0x14));
    std::uint8_t* sentinel = candidate + 0x1c;
    std::uint8_t* node = *reinterpret_cast<std::uint8_t**>(candidate + 0x20);
    bool resource_ready = node != sentinel;
    if (resource_ready) {
        std::uint8_t* payload_node = *reinterpret_cast<std::uint8_t**>(node);
        resource_ready = *reinterpret_cast<std::uint8_t**>(payload_node + 0x10) !=
                         payload_node + 0x0c;
        if (resource_ready) {
            std::uint8_t* payload_link = *reinterpret_cast<std::uint8_t**>(payload_node + 0x14);
            std::uint8_t* payload = *reinterpret_cast<std::uint8_t**>(payload_link);
            resource_ready = payload != 0 && payload[0x24] == 0;
        }
    }
    if (!resource_ready && owner_bytes[0x34] == 0)
        return 0;
    std::uint8_t* entry = static_cast<std::uint8_t*>(ResourceTree_ResolveCurrentEntry_002A6268(
        *reinterpret_cast<void**>(owner_bytes + 0x30)));
    void* factory = (entry[0x64] & 2u) != 0
        ? static_cast<void*>(StMenuForcus_Factory_0027D058())
        : static_cast<void*>(StMenuNoForcus_Factory_0023B79C());
    std::uint8_t* state = static_cast<std::uint8_t*>(ActorStateMachine_RequestStateByFactory_0036BEF0(
        *reinterpret_cast<void**>(owner_bytes + 0x30), &factory));
    state[0x0c] = 0;
    return 0;
}
extern "C" __attribute__((noinline)) std::uint32_t MenuState_RequestForcusOrNoForcus_002EF1FC(
    void* owner, void*, void*, void*) {
    std::uint8_t* owner_bytes = static_cast<std::uint8_t*>(owner);
    std::uint8_t* entry = static_cast<std::uint8_t*>(ResourceTree_ResolveCurrentEntry_002A6268(
        *reinterpret_cast<void**>(owner_bytes + 0x30)));
    void* factory = (entry[0x64] & 2u) != 0
        ? static_cast<void*>(StMenuForcus_Factory_0027D058())
        : static_cast<void*>(StMenuNoForcus_Factory_0023B79C());
    std::uint8_t* state = static_cast<std::uint8_t*>(ActorStateMachine_RequestStateByFactory_0036BEF0(
        *reinterpret_cast<void**>(owner_bytes + 0x30), &factory));
    state[0x0c] = 0;
    return 0;
}
extern "C" __attribute__((noinline)) std::uint32_t MenuState_RequestForcusOrNoForcus_001832DC(
    void* owner, void*, void*, void*) {
    std::uint8_t* machine = *reinterpret_cast<std::uint8_t**>(
        static_cast<std::uint8_t*>(owner) + 0x30);
    std::uint8_t* entry = *reinterpret_cast<std::uint8_t**>(machine + 0x10);
    void* factory = (entry[0x64] & 2u) != 0
        ? static_cast<void*>(StMenuForcus_Factory_0027D058())
        : static_cast<void*>(StMenuNoForcus_Factory_0023B79C());
    std::uint8_t* state = static_cast<std::uint8_t*>(
        ActorStateMachine_RequestStateByFactory_0036BEF0(machine, &factory));
    state[0x0c] = 0;
    return 0;
}
extern "C" __attribute__((noinline)) std::uint32_t MenuState_RequestDisappear_001833AC(
    void* owner, void*, void* callback_record, void*) {
    std::uint8_t* machine = *reinterpret_cast<std::uint8_t**>(
        static_cast<std::uint8_t*>(owner) + 0x30);
    void* factory = StMenuDisappear_Factory_0028AADC();
    std::uint8_t* state = static_cast<std::uint8_t*>(
        ActorStateMachine_RequestStateByFactory_0036BEF0(machine, &factory));
    if (*reinterpret_cast<std::uint8_t*>(
            static_cast<std::uint8_t*>(callback_record) + 0x29) != 0)
        state[0x0c] = 1;
    return 0;
}
extern "C" __attribute__((noinline)) std::uint32_t MenuState_RequestForcusOrNoForcus_00183530(
    void* owner, void*, void*, void*) {
    std::uint8_t* owner_bytes = static_cast<std::uint8_t*>(owner);
    std::uint8_t* candidate = static_cast<std::uint8_t*>(
        OrderedTree_LowerBoundBySignedKey_00390A98(
            *reinterpret_cast<void**>(owner_bytes + 0x44), 0x14));
    std::uint8_t* sentinel = candidate + 0x1c;
    std::uint8_t* node = *reinterpret_cast<std::uint8_t**>(candidate + 0x20);
    bool resource_ready = node != sentinel;
    if (resource_ready) {
        std::uint8_t* payload_node = *reinterpret_cast<std::uint8_t**>(node);
        resource_ready = *reinterpret_cast<std::uint8_t**>(payload_node + 0x10) !=
                         payload_node + 0x0c;
        if (resource_ready) {
            std::uint8_t* payload_link = *reinterpret_cast<std::uint8_t**>(
                payload_node + 0x14);
            std::uint8_t* payload = *reinterpret_cast<std::uint8_t**>(payload_link);
            resource_ready = payload != 0 && payload[0x24] == 0;
        }
    }
    if (!resource_ready && (owner_bytes[0x34] & 1u) == 0)
        return 0;
    std::uint8_t* machine = *reinterpret_cast<std::uint8_t**>(
        owner_bytes + 0x30);
    std::uint8_t* entry = *reinterpret_cast<std::uint8_t**>(owner_bytes + 0x40);
    void* factory = (entry[0x64] & 2u) != 0
        ? static_cast<void*>(StMenuForcus_Factory_0027D058())
        : static_cast<void*>(StMenuNoForcus_Factory_0023B79C());
    std::uint8_t* state = static_cast<std::uint8_t*>(
        ActorStateMachine_RequestStateByFactory_0036BEF0(machine, &factory));
    state[0x0c] = 0;
    return 0;
}
extern "C" __attribute__((noinline)) std::uint32_t MenuState_UpdateForcusFlag_001835F0(
    void* owner, void*, void* callback_record, void*) {
    std::uint8_t* owner_bytes = static_cast<std::uint8_t*>(owner);
    std::uint8_t* entry = *reinterpret_cast<std::uint8_t**>(owner_bytes + 0x40);
    std::uint8_t* context = *reinterpret_cast<std::uint8_t**>(owner_bytes + 0x3c);
    std::uint8_t flag = static_cast<std::uint8_t>(entry[0x64] & 0xfeu);
    if (*reinterpret_cast<std::uint32_t*>(context + 0x18) ==
        *reinterpret_cast<std::uint32_t*>(
            static_cast<std::uint8_t*>(callback_record) + 0x2c)) {
        entry[0x64] = static_cast<std::uint8_t>(flag | 1u);
    } else {
        entry[0x64] = flag;
        void* factory = StMenuNoForcus_Factory_0023B79C();
        ActorStateMachine_RequestStateByFactory_0036BEF0(
            *reinterpret_cast<void**>(owner_bytes + 0x30), &factory);
    }
    return 0;
}
extern "C" __attribute__((noinline)) std::uint32_t MenuState_RequestDisappear_00183644(
    void* owner, void*, void* callback_record, void*) {
    std::uint8_t* machine = *reinterpret_cast<std::uint8_t**>(
        static_cast<std::uint8_t*>(owner) + 0x30);
    void* factory = StMenuDisappear_Factory_0028AADC();
    std::uint8_t* state = static_cast<std::uint8_t*>(
        ActorStateMachine_RequestStateByFactory_0036BEF0(machine, &factory));
    if (*reinterpret_cast<std::uint8_t*>(
            static_cast<std::uint8_t*>(callback_record) + 0x29) != 0)
        state[0x0c] = 1;
    return 0;
}
extern "C" __attribute__((noinline)) std::uint32_t MenuState_UpdateForcusFlagAndRequest_0018384C(
    void* owner, void*, void* callback_record, void*) {
    std::uint8_t* owner_bytes = static_cast<std::uint8_t*>(owner);
    if (*reinterpret_cast<std::uint32_t*>(
            *reinterpret_cast<std::uint8_t**>(owner_bytes + 0x3c) + 0x18) ==
        *reinterpret_cast<std::uint32_t*>(
            static_cast<std::uint8_t*>(callback_record) + 0x2c)) {
        void* factory = StMenuForcus_Factory_0027D058();
        ActorStateMachine_RequestStateByFactory_0036BEF0(
            *reinterpret_cast<void**>(owner_bytes + 0x30), &factory);
        std::uint8_t* entry = *reinterpret_cast<std::uint8_t**>(owner_bytes + 0x40);
        entry[0x64] = static_cast<std::uint8_t>(entry[0x64] | 1u);
    } else {
        std::uint8_t* entry = *reinterpret_cast<std::uint8_t**>(owner_bytes + 0x40);
        entry[0x64] = static_cast<std::uint8_t>(entry[0x64] & 0xfeu);
    }
    return 0;
}
extern "C" __attribute__((noinline)) std::uint32_t MenuState_RequestDisappear_001838AC(
    void* owner, void*, void* callback_record, void*) {
    std::uint8_t* machine = *reinterpret_cast<std::uint8_t**>(
        static_cast<std::uint8_t*>(owner) + 0x30);
    void* factory = StMenuDisappear_Factory_0028AADC();
    std::uint8_t* state = static_cast<std::uint8_t*>(
        ActorStateMachine_RequestStateByFactory_0036BEF0(machine, &factory));
    if (*reinterpret_cast<std::uint8_t*>(
            static_cast<std::uint8_t*>(callback_record) + 0x29) != 0)
        state[0x0c] = 1;
    return 0;
}
extern "C" __attribute__((noinline)) std::uint32_t MenuState_RequestBaseOrDisappear_001840AC(
    void* owner, void*, void*, void*) {
    std::uint8_t* owner_bytes = static_cast<std::uint8_t*>(owner);
    std::uint8_t* mode_record = *reinterpret_cast<std::uint8_t**>(
        owner_bytes + 0x48);
    std::uint8_t* candidate = static_cast<std::uint8_t*>(
        OrderedTree_LowerBoundBySignedKey_00390A98(
            *reinterpret_cast<void**>(owner_bytes + 0x54), 0x14));
    std::uint8_t* sentinel = candidate + 0x1c;
    std::uint8_t* node = *reinterpret_cast<std::uint8_t**>(candidate + 0x20);
    bool resource_ready = node != sentinel;
    if (resource_ready) {
        std::uint8_t* payload_node = *reinterpret_cast<std::uint8_t**>(node);
        resource_ready = *reinterpret_cast<std::uint8_t**>(payload_node + 0x10) !=
                         payload_node + 0x0c;
        if (resource_ready) {
            std::uint8_t* payload_link = *reinterpret_cast<std::uint8_t**>(
                payload_node + 0x14);
            std::uint8_t* payload = *reinterpret_cast<std::uint8_t**>(payload_link);
            resource_ready = payload != 0 && payload[0x24] == 0;
        }
    }
    if (!resource_ready)
        return 0;
    void* machine = *reinterpret_cast<void**>(owner_bytes + 0x30);
    if (mode_record[0x28] == 0) {
        void* factory = StMenuBase_Factory_0022CC34();
        ActorStateMachine_RequestStateByFactory_0036BEF0(machine, &factory);
    } else if (mode_record[0x28] == 3) {
        void* factory = StMenuDisappear_Factory_0028AADC();
        ActorStateMachine_RequestStateByFactory_0036BEF0(machine, &factory);
    }
    return 0;
}
extern "C" __attribute__((noinline)) void* StMenuAppear_Construct_00AA29E4(
    void*, std::uint32_t count) {
    StMenuAppearStateRecordView* record = static_cast<StMenuAppearStateRecordView*>(Engine_AllocateTaggedBlock(
        0x0c, reinterpret_cast<void*>(0x00AA2A88u), count));
    if (record == 0)
        return 0;
    record->implementation_00 = 0x00D1DA84u;
    if (BeginOnce(0x00D62CD8u)) {
        std::uint32_t next_id = At<std::uint32_t>(0x00D6351Cu);
        At<std::uint32_t>(0x00D62CDCu) = next_id++;
    }
    record->opaque_04 = At<std::uint32_t>(0x00D62CDCu);
    void* registry = At<void*>(0x00D63714u);
    if (registry == 0)
        registry = Engine_LazyStrideRegistry_003B6D84();
    record->opaque_08 = At<std::uint32_t>(0x00C9B924u);
    record->implementation_00 = 0x00CEE52Cu;
    return record;
}
extern "C" __attribute__((noinline)) void* StMenuAppear_Clone_00AA2AA8(
    void*, std::uint32_t count, void* source) {
    if (BeginOnce(0x00D5FF64u)) {
        if (BeginOnce(0x00D627C4u)) {
            if (BeginOnce(0x00D619C8u))
                At<std::uint32_t>(0x00D619CCu) = 0;
            At<void*>(0x00D627C8u) = reinterpret_cast<void*>(0x00D619CCu);
        }
        At<void*>(0x00D5FF68u) = reinterpret_cast<void*>(0x00D627C8u);
    }
    typedef void*(*FirstLink)(void*);
    void** vtable = *reinterpret_cast<void***>(source);
    void* link = reinterpret_cast<FirstLink>(vtable[0])(source);
    const void* sentinel = reinterpret_cast<void*>(0x00D5FF68u);
    while (link != 0 && link != sentinel)
        link = *reinterpret_cast<void**>(link);
    if (link == 0)
        return 0;
    StMenuAppearStateRecordView* clone = static_cast<StMenuAppearStateRecordView*>(Engine_AllocateTaggedBlock(
        0x0c, reinterpret_cast<void*>(0x00AA2BE0u), count));
    if (clone == 0)
        return 0;
    StMenuAppearStateRecordView* source_record = static_cast<StMenuAppearStateRecordView*>(source);
    clone->opaque_04 = source_record->opaque_04;
    clone->opaque_08 = source_record->opaque_08;
    clone->implementation_00 = 0x00CEE52Cu;
    return clone;
}
extern "C" __attribute__((noinline)) void* StMenuDisappear_Construct_00B0066C(
    void*, std::uint32_t count) {
    StMenuDisappearStateRecordView* record = static_cast<StMenuDisappearStateRecordView*>(
        Engine_AllocateTaggedBlock(0x10, reinterpret_cast<void*>(0x00B00718u), count));
    if (record == 0)
        return 0;
    record->implementation_00 = 0x00D1DA84u;
    if (BeginOnce(0x00D62F44u)) {
        std::uint32_t next_id = At<std::uint32_t>(0x00D63540u);
        At<std::uint32_t>(0x00D62F40u) = next_id++;
    }
    record->opaque_04 = At<std::uint32_t>(0x00D62F40u);
    void* registry = At<void*>(0x00D63714u);
    if (registry == 0)
        registry = Engine_LazyStrideRegistry_003B6D84();
    record->opaque_08 = At<std::uint32_t>(0x00C9B92Cu);
    record->implementation_00 = 0x00CF26F0u;
    record->initial_flag_0c = 0;
    return record;
}
extern "C" __attribute__((noinline)) void* StMenuDisappear_Clone_00B00738(
    void*, std::uint32_t count, void* source) {
    if (BeginOnce(0x00D60EDCu)) {
        if (BeginOnce(0x00D627C4u)) {
            if (BeginOnce(0x00D619C8u))
                At<std::uint32_t>(0x00D619CCu) = 0;
            At<void*>(0x00D627C8u) = reinterpret_cast<void*>(0x00D619CCu);
        }
        At<void*>(0x00D60EE0u) = reinterpret_cast<void*>(0x00D627C8u);
    }
    typedef void*(*FirstLink)(void*);
    void** vtable = *reinterpret_cast<void***>(source);
    void* link = reinterpret_cast<FirstLink>(vtable[0])(source);
    const void* sentinel = reinterpret_cast<void*>(0x00D60EE0u);
    while (link != 0 && link != sentinel)
        link = *reinterpret_cast<void**>(link);
    if (link == 0)
        return 0;
    StMenuDisappearStateRecordView* clone = static_cast<StMenuDisappearStateRecordView*>(
        Engine_AllocateTaggedBlock(0x10, reinterpret_cast<void*>(0x00B0087Cu), count));
    if (clone == 0)
        return 0;
    StMenuDisappearStateRecordView* source_record = static_cast<StMenuDisappearStateRecordView*>(source);
    clone->opaque_04 = source_record->opaque_04;
    clone->opaque_08 = source_record->opaque_08;
    clone->implementation_00 = 0x00CF26F0u;
    clone->initial_flag_0c = source_record->initial_flag_0c & 1u;
    return clone;
}
extern "C" __attribute__((noinline)) void* StMenuForcus_Construct(
    void*, std::uint32_t count) {
    StMenuForcusStateRecordView* record = static_cast<StMenuForcusStateRecordView*>(
        Engine_AllocateTaggedBlock(0x10, reinterpret_cast<void*>(0x00AA2DE8u), count));
    if (record == 0)
        return 0;
    record->implementation_00 = 0x00D1DA84u;
    if (BeginOnce(0x00D62CE4u)) {
        std::uint32_t next_id = At<std::uint32_t>(0x00D6351Cu);
        At<std::uint32_t>(0x00D62CE0u) = next_id++;
    }
    record->opaque_04 = At<std::uint32_t>(0x00D62CE0u);
    void* registry = At<void*>(0x00D63714u);
    if (registry == 0)
        registry = Engine_LazyStrideRegistry_003B6D84();
    record->opaque_08 = At<std::uint32_t>(0x00C9B930u);
    record->implementation_00 = 0x00CEE550u;
    record->initial_flag_0c = 1;
    return record;
}
extern "C" __attribute__((noinline)) void* StMenuForcus_Clone(
    void*, std::uint32_t count, void* source) {
    if (BeginOnce(0x00D5FF6Cu)) {
        if (BeginOnce(0x00D5EF4Cu)) {
            if (BeginOnce(0x00D627C4u)) {
                if (BeginOnce(0x00D619C8u))
                    At<std::uint32_t>(0x00D619CCu) = 0;
                At<void*>(0x00D627C8u) = reinterpret_cast<void*>(0x00D619CCu);
            }
            At<void*>(0x00D5EF50u) = reinterpret_cast<void*>(0x00D627C8u);
        }
        At<void*>(0x00D5FF70u) = reinterpret_cast<void*>(0x00D5EF50u);
    }
    typedef void*(*FirstLink)(void*);
    void** vtable = *reinterpret_cast<void***>(source);
    void* link = reinterpret_cast<FirstLink>(vtable[0])(source);
    const void* sentinel = reinterpret_cast<void*>(0x00D5FF70u);
    while (link != 0 && link != sentinel)
        link = *reinterpret_cast<void**>(link);
    if (link == 0)
        return 0;
    StMenuForcusStateRecordView* clone = static_cast<StMenuForcusStateRecordView*>(
        Engine_AllocateTaggedBlock(0x10, reinterpret_cast<void*>(0x00AA2F84u), count));
    if (clone == 0)
        return 0;
    StMenuForcusStateRecordView* source_record = static_cast<StMenuForcusStateRecordView*>(source);
    clone->opaque_04 = source_record->opaque_04;
    clone->opaque_08 = source_record->opaque_08;
    clone->implementation_00 = 0x00CEE550u;
    clone->initial_flag_0c = source_record->initial_flag_0c;
    return clone;
}

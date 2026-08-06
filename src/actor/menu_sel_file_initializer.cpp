#include <cstdint>
extern "C" void* Object_GetAllocatorContext_0042167C(void* object);
extern "C" void* Engine_AllocateTaggedBlock_0047466C(
    std::uint32_t size, const void* type_tag, void* allocator_context);
namespace actor_param {
void* MenuSelFileParam_Factory_0030444C();
}
extern "C" void* OrderedTree_FindPayloadByPointer_00326C6C(
    void* tree, void* key_record);
extern "C" void* MenuResource_RecordLookup_002BF024(void* record);
extern "C" void* MenuResource_Key_002C00D4();
extern "C" void* ResourceTree_ResolveCurrentEntry_002A6268(void* resource);
extern "C" void* ResourceTree_FindActiveLink_002EE080(
    void* links, void* resource);
extern "C" void* MenuResource_FindNamedRecord_002D6DDC(
    void* records, void* key, const char* name);
extern "C" void* BufferDescriptor_Create_002EA2EC(
    void* descriptor, void* allocator);
extern "C" void BufferField_Reset_00260C9C(std::uint32_t value, void* field);
extern "C" void BufferField_Reset_00260ED4(std::uint32_t value, void* field);
extern "C" void BufferResource_Bind_001ECCEC(void* resource, void* field);
extern "C" void BufferResource_SetField_00260A90(void* resource, void* field);
extern "C" void BufferResource_SetFormat_00261284(
    void* resource, std::uintptr_t format, void* width, void* height);
extern "C" void BufferResource_SetName_00260BD8(
    void* resource, std::uintptr_t name, void* owner, void* field);
extern "C" void BufferResource_Notify_0034C650(float value, void* record);
extern "C" void BufferResource_Notify_0031EBC8(void* resource);
extern void* g_BufferResourceType_002D8AD8;
extern void* g_BufferResourceField_002D8ADC;
extern std::uintptr_t g_BufferFormat_002D8AE0;
extern std::uintptr_t g_BufferFormat_002D8AE4;
extern std::uint8_t g_ResourceReadyTable_002DC23C[];
extern void* g_MenuSelFileDefaultVector_0030218C;
extern std::uint32_t g_MenuSelFileDefaultValue_00302190;
extern float g_DegreesToRadians_00302194;
extern const char* g_MenuSelFileFinalKey_00302198;
extern float g_MenuSelFileAnchorDefault_00DC249C[3];
extern std::uint8_t g_MenuSelFileLinkTypeTag_00302030;
extern void* g_MenuProfileStateSingletonSlot_002E38D4;
extern std::uint32_t g_MenuProfileStateFieldDefault_002E38D8;
extern std::uint32_t g_MenuProfileStateTableStride_002E3BA4;
extern "C" void FUN_003DC5D0(void* destination, std::uint32_t size);
extern "C" void MemoryRecordArray_Initialize_00106494(void* object);
extern "C" void ResourceRecord_ResetState_00107978(void* object);
extern "C" void* Engine_LazySingletonGetter_003FD6E0();
extern "C" void* Engine_ForEachStrideCallback_00421EA4(
    void* base, void* callback, std::uint32_t stride, std::uint32_t count);
const std::uint32_t k_MenuProfileResourceLimit_002B5598 = 0x3b9ac9ff;
const std::uintptr_t k_MenuProfileResourceTable_002B55A4 = 0x00cfc354;
extern "C" void MenuProfileResource_ApplyRecord_002B55A8(
    void* object, std::uint32_t group, std::uint16_t selector,
    void* source, std::int32_t count);
extern "C" void MenuProfileRecord_Clear_002B6498(void* record);
extern "C" void MenuProfileRecord_ClearCallback_001FC788(void* record);
extern "C" std::uint32_t MenuProfileResource_UpdateIndex_0026F324(
    void* object, void* record);
extern "C" void MenuProfileResource_UpdateMode_0022CA08(
    void* object, std::uint32_t mode);
extern "C" void MenuProfileResource_SetFlag_00210514(
    void* object, std::uint32_t index, std::uint32_t slot,
    std::uint32_t value);
extern "C" std::uint32_t MenuProfileResource_FindIndex_0016715C(void* record);
extern "C" std::uint16_t MenuProfileResource_SelectIndex_0018A5F4(
    void* record, void* indices, std::uint32_t count, void* range,
    std::uint32_t use_range);
extern "C" void MenuProfileResource_SetBit_001AD414(
    void* object, std::uint32_t index, std::uint32_t value);
extern "C" void MenuProfileResource_AdvanceRandom_001DAA54(void* object);
extern "C" void ParameterString_Normalize_00352994(void* destination, void* source);
extern "C" void* MenuResource_Resolve_002A6190(void* resource);
extern "C" void* MenuResource_FindNamedObject_00274FE8(void* resource, const char* name);
extern "C" void* ResourceTree_KeyGetter_002A18B8();
extern "C" void* MemoryFillEnd_003FDCAC(
    void* destination, std::uint32_t size);
extern "C" void Utf16_CopyBounded_00275034(void* destination, void* source,
                                             void* record, std::uint32_t size);
extern "C" void* BattleState_GetSingleton_00225BA8();
extern "C" void* FUN_001BA790();
extern "C" void* GetEngineSingleton_003B6CF0();
extern "C" void* FUN_002a69f4();
extern "C" void* FUN_002F32E8();
extern "C" void FUN_0028D9D4(void* object, void* resource);
extern "C" int FUN_002630A4(void* result, std::uint32_t mode, void* record,
                              std::uint32_t value);
extern "C" int FUN_002A7224(void* key, void* result);
extern "C" int FUN_00225C3C(void* result, std::uint32_t mode, std::uint16_t value);
extern "C" void Engine_BulkCopy_00425DF8(void* source, void* destination,
                                           std::uint32_t size);
extern "C" void* Engine_LazyCommandWorkSingleton_0027C908();
extern "C" void FUN_003B5918(void* resource, void* command, void* result);
extern "C" std::uint32_t FUN_00275B68();
extern "C" void* Engine_LazyCommandResourceSingleton_0028F138();
extern "C" void FUN_00337DE0(void* object);
extern "C" void* Engine_LazySingletonGetter_00422CC8();
extern "C" void FUN_002A15B4(void* resource, void* owner);
extern "C" void FUN_0025EE70(void* entry);
extern "C" void ResourceTree_SetEntryActive_0025EE3C(void* entry, std::uint8_t active);
extern "C" void* StMenuAppear_Factory_00234A94();
extern "C" void ActorStateMachine_RequestStateByFactory(void* resource, void* factory);
extern "C" void MenuProfileState_Initialize_002E33D4(void* object);
extern "C" void MenuSelFile_InitializeSelectionData_00302038(void* object);
extern "C" void MenuSelFile_TransferAnchorDelta_0030219C(void* object);
extern "C" void* MenuSelFile_InsertResourceLink_00301F80(
    void* owner, void* resource, void* source);
extern "C" bool BufferDescriptor_Initialize_002D8AE8(
    void* destination, void* owner, std::uint32_t rows, std::uint32_t columns,
    std::uint32_t mode);
extern "C" bool BufferDescriptor_Publish_002D89C8(void* descriptor);
extern "C" void Resource_SetModeValue_0031EEB8(void* resource, std::int32_t mode,
                                                float value);
extern "C" void* g_MenuWorkSingleton_00D63570;
extern "C" void* g_MenuSelectionState_00D635E0;
extern "C" void* g_MenuProfileSingleton_00D6365C;
extern "C" void* g_MenuSelFileResourceList_00D636CC;
extern "C" void* g_MenuRuntimeSingleton_00D6384C;
namespace {
template <typename T>
T& At(void* object, std::uint32_t offset);
void* ResourceTreeFind(void* resource, void* key) {
    std::uint8_t* tree = static_cast<std::uint8_t*>(resource) + 0x1a8;
    std::uint8_t* node = At<std::uint8_t*>(resource, 0x1ac);
    const std::uintptr_t needle = reinterpret_cast<std::uintptr_t>(key);
    while (At<std::uint8_t>(node, 0x10) != 0) {
        if (At<std::uintptr_t>(node, 0x14) < needle) {
            node = At<std::uint8_t*>(node, 0x0c);
            tree = node;
        } else {
            node = At<std::uint8_t*>(node, 0x08);
        }
    }
    if (tree == static_cast<std::uint8_t*>(resource) + 0x1a8 ||
        needle < At<std::uintptr_t>(tree, 0x14))
        tree = static_cast<std::uint8_t*>(resource) + 0x1a8;
    if (tree == 0 || At<void*>(tree, 0) == 0)
        return 0;
    return At<void*>(tree, 0);
}
void InitMenuRecord(void* object, std::uint32_t offset) {
    std::uint8_t* record = static_cast<std::uint8_t*>(object) + offset;
    At<std::uint16_t>(record, 0) = 0;
    At<std::uint32_t>(record, 4) = 0;
    At<std::uint32_t>(record, 8) = 0;
    At<std::uint32_t>(record, 0xc) = 0;
    At<std::uint32_t>(record, 0x10) = 0;
    At<std::uint32_t>(record, 0x14) = 0;
    At<std::uint32_t>(record, 0x18) = 0;
    At<std::uint32_t>(record, 0x1c) = 0;
    At<std::uint32_t>(record, 0x20) = 0;
}
}  // namespace
namespace {
template <typename T>
T& At(void* object, std::uint32_t offset) {
    return *reinterpret_cast<T*>(static_cast<std::uint8_t*>(object) + offset);
}
void MenuSelFile_BindResource(void* object, void* resource,
                              std::uint32_t offset, const char* name) {
    MenuSelFile_InsertResourceLink_00301F80(object, resource,
                                             At<void*>(object, offset));
    void* record = MenuResource_FindNamedObject_00274FE8(
        At<void*>(object, offset), name);
    At<std::uint32_t>(record, 0xc0) |= 4;
}
void* Allocate(void* allocator, std::uint32_t size, bool aligned) {
    typedef void*(*AllocateFn)(void*, std::uint32_t, ...);
    std::uint8_t* vtable = static_cast<std::uint8_t*>(At<void*>(allocator, 0));
    AllocateFn allocate = reinterpret_cast<AllocateFn>(At<void*>(vtable, 0x08));
    return aligned ? allocate(allocator, size, 0x80) : allocate(allocator, size);
}
}  // namespace
extern "C" __attribute__((noinline)) void MenuProfileRecord_Clear_002B6498(void* record) {
    std::uint8_t*const bytes = static_cast<std::uint8_t*>(record);
    std::uint32_t i;
    *reinterpret_cast<std::uint32_t*>(bytes + 0x04) = 0;
    for (i = 0; i < 6; ++i) {
        std::uint8_t*const slot = bytes + i * 2;
        *reinterpret_cast<std::uint16_t*>(slot + 0x14) = 0;
    }
    for (i = 0; i < 6; ++i) {
        std::uint8_t*const slot = bytes + i * 2;
        *reinterpret_cast<std::uint16_t*>(slot + 0x08) = 0;
    }
}
extern "C" __attribute__((noinline)) void MenuProfileRecord_ClearCallback_001FC788(void* record) {
    At<std::uint32_t>(record, 0x00) = 0;
    At<std::uint8_t>(record, 0x04) = 0xff;
    At<std::uint16_t>(record, 0x04) &= 0x00ff;
}
extern "C" void MenuProfileResource_ApplyRecord_002B55A8(
    void* object, std::uint32_t group, std::uint16_t selector,
    void* source, std::int32_t count) {
    std::uint8_t* group_base = static_cast<std::uint8_t*>(object) + group * 0x128;
    std::uint8_t* destination = group_base + 0x8ed8;
    for (std::int32_t i = 0; i < 0x24; ++i) {
        std::uint8_t* record = destination + i * 8;
        At<std::uint8_t>(record, 0x08) = 0xff;
        At<std::uint16_t>(record, 0x08) &= 0x00ff;
    }
    At<std::uint8_t>(group_base, 0x8ffc) = 0;
    std::uint8_t* packed = static_cast<std::uint8_t*>(object) + 0x8a34 + group * 0x128;
    At<std::uint16_t>(packed, 0x5ca) = static_cast<std::uint16_t>(
        (At<std::uint16_t>(packed, 0x5ca) & 0xfc00) | 0x400 | (selector & 0x3ff));
    At<std::uint8_t>(group_base, 0x8ffc) = static_cast<std::uint8_t>(count);
    for (std::int32_t i = 0; i < count; ++i) {
        std::uint8_t* source_record = static_cast<std::uint8_t*>(source) + i * 8;
        std::uint8_t* record = packed + 0x4a4 + i * 8;
        const std::uint16_t value = At<std::uint16_t>(source_record, 0x04);
        At<std::uint8_t>(record, 0x08) = static_cast<std::uint8_t>(value);
        At<std::uint16_t>(record, 0x08) = static_cast<std::uint16_t>(
            (value & 0x3f00) | (At<std::uint16_t>(record, 0x08) & 0xc0ff));
        At<std::uint16_t>(record, 0x08) = static_cast<std::uint16_t>(
            (value & 0xc000) | (value & 0x3f00) |
            (At<std::uint16_t>(record, 0x08) & 0x00ff));
    }
}
extern "C" __attribute__((noinline)) void MenuProfileResource_Initialize_002B4FDC(void* object) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(object);
    std::uint8_t stack[0x570];
    std::uint8_t* first = stack;
    std::uint8_t* second = stack + 8;
    std::uint8_t* resource_context = stack + 0x400;
    MenuProfileRecord_Clear_002B6498(first);
    MenuProfileResource_UpdateIndex_0026F324(object, first);
    MenuProfileResource_UpdateMode_0022CA08(object, 4);
    MenuProfileResource_UpdateMode_0022CA08(object, 0x95);
    std::uint32_t count = At<std::uint32_t>(object, 0x101b8) + 1;
    if (count == 0 || k_MenuProfileResourceLimit_002B5598 < count)
        count = k_MenuProfileResourceLimit_002B5598;
    At<std::uint32_t>(object, 0x101b8) = count;
    At<std::uint32_t>(object, 0x101cc) = 0;
    At<std::uint32_t>(object, 0x101c8) = 0;
    MenuProfileResource_SetFlag_00210514(object, 0, 0, 1);
    Engine_ForEachStrideCallback_00421EA4(
        first, reinterpret_cast<void*>(MenuProfileRecord_ClearCallback_001FC788), 8, 1);
    At<std::uint8_t>(first, 0x04) = 0x95;
    At<std::uint16_t>(first, 0x04) &= 0x00ff;
    std::uint8_t* first_group = bytes + 0x8a38;
    for (std::uint32_t i = 0; i < 0x24; ++i) {
        At<std::uint8_t>(first_group + i * 8, 0x08) = 0xff;
        At<std::uint16_t>(first_group + i * 8, 0x08) &= 0x00ff;
    }
    bytes[0x8b5c] = 0;
    At<std::uint8_t>(second, 0x04) = static_cast<std::uint8_t>(
        At<std::uint16_t>(first, 0x04));
    At<std::uint16_t>(second, 0x04) = static_cast<std::uint16_t>(
        (At<std::uint16_t>(first, 0x04) & 0x3f00) |
        (At<std::uint16_t>(second, 0x04) & 0xc0ff));
    At<std::uint16_t>(second, 0x04) = static_cast<std::uint16_t>(
        (At<std::uint16_t>(first, 0x04) & 0xc000) |
        (At<std::uint16_t>(first, 0x04) & 0x3f00) |
        (At<std::uint16_t>(second, 0x04) & 0x00ff));
    Engine_ForEachStrideCallback_00421EA4(
        second, reinterpret_cast<void*>(MenuProfileRecord_ClearCallback_001FC788), 8, 1);
    At<std::uint8_t>(second, 0x04) = 0x95;
    At<std::uint16_t>(second, 0x04) &= 0x00ff;
    At<std::uint32_t>(first, 0x00) = 1;
    MenuProfileResource_ApplyRecord_002B55A8(
        object, 0, 0, second, static_cast<std::int32_t>(At<std::uint32_t>(first, 0)));
    At<std::uint32_t>(object, 0x102f4) &= 0xffffff83;
    static const std::uint32_t kiu_items1[] = {0x29u, 0x2au, 0x2bu, 0x2du, 0x2eu,
                                      0x32u};
    for (unsigned kiu_j1 = 0;
         kiu_j1 != sizeof(kiu_items1) / sizeof(kiu_items1[0]); ++kiu_j1) {
        const std::uint32_t index = kiu_items1[kiu_j1]; MenuProfileResource_SetFlag_00210514(object, index, 1, 1);
    }
    At<std::uint32_t>(second, 0x00) =
        static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(
            k_MenuProfileResourceTable_002B55A4));
    At<std::uint32_t>(first, 0x00) = 0;
    At<std::uint16_t>(first, 0x04) = 1;
    At<std::uint8_t>(resource_context, 0x14) = 5;
    const std::uint32_t index = MenuProfileResource_FindIndex_0016715C(second);
    if (index != 0) {
        const std::uint32_t selected =
            MenuProfileResource_SelectIndex_0018A5F4(
                second, resource_context + 0x148, 1, resource_context + 0x160, 0);
        At<std::uint8_t>(bytes, 0x46c + selected) = 1;
        At<std::uint8_t>(bytes, 0x608 + (selected >> 3)) |=
            static_cast<std::uint8_t>(1u << (selected & 7));
    }
    for (std::uint32_t index = 0; index < 0x6c; ++index)
        At<std::uint8_t>(bytes, 0x3ae + (index >> 3)) &=
            static_cast<std::uint8_t>(~(1u << (index & 7)));
    static const std::uint32_t kiu_items2[] = {
             0x08u, 0x14u, 0x20u, 0x2cu, 0x38u, 0x44u, 0x50u, 0x5cu,
             0x68u, 0x09u, 0x2du, 0x39u, 0x45u, 0x5du, 0x0bu, 0x16u,
             0x17u, 0x23u, 0x2fu, 0x3bu, 0x46u, 0x47u, 0x52u, 0x53u,
             0x5fu, 0x6au, 0x6bu, 0x5eu, 0x22u, 0x3au, 0x0au, 0x2eu,
             0x4bu, 0x5bu};
    for (unsigned kiu_j2 = 0;
         kiu_j2 != sizeof(kiu_items2) / sizeof(kiu_items2[0]); ++kiu_j2) {
        const std::uint32_t index = kiu_items2[kiu_j2]; MenuProfileResource_SetBit_001AD414(object, index, 0);
    }
    MenuProfileResource_AdvanceRandom_001DAA54(object);
}
extern "C" __attribute__((noinline)) std::uint32_t MenuSelFile_Initialize_002BD348(void* object, float scale) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(object);
    for (std::uint32_t offset = 0x3a0; offset <= 0x5e0; offset += 0x24)
        InitMenuRecord(object, offset);
    At<std::uint32_t>(object, 0x614) = 0;
    At<std::uint8_t>(object, 0x278) &= 0xfe;
    void** work_slot = &g_MenuWorkSingleton_00D63570;
    if (*work_slot == 0)
        *work_slot = FUN_001BA790();
    At<std::uint8_t>(*work_slot, 0x80) &= 0xdf;
    void** battle_slot = &g_MenuSelectionState_00D635E0;
    if (*battle_slot == 0)
        *battle_slot = BattleState_GetSingleton_00225BA8();
    At<std::uint8_t>(*battle_slot, 0x80) = 0xff;
    void** engine_slot = &g_MenuProfileSingleton_00D6365C;
    if (*engine_slot == 0)
        *engine_slot = GetEngineSingleton_003B6CF0();
    void* profile_state = static_cast<std::uint8_t*>(*engine_slot) + 0x6278;
    At<std::uint8_t>(object, 0xd4) = At<std::uint8_t>(*engine_slot, 0x518);
    MenuProfileState_Initialize_002E33D4(profile_state);
    MenuProfileResource_Initialize_002B4FDC(profile_state);
    for (std::uint32_t index = 0; index < 0x200; ++index) {
        std::uint8_t* bit = static_cast<std::uint8_t*>(profile_state) - 0x10175 + (index >> 3);
        *bit &= static_cast<std::uint8_t>(~(1u << (index & 7)));
    }
    void* parameter_key = actor_param::MenuSelFileParam_Factory_0030444C();
    void* parameter_node = OrderedTree_FindPayloadByPointer_00326C6C(
        At<void*>(object, 0x30), &parameter_key);
    void* parameter = parameter_node == 0
        ? 0 : At<void*>(parameter_node, 0x1c);
    const std::uint8_t profile = At<std::uint8_t>(object, 0xd4);
    std::uint8_t* profile_entry = static_cast<std::uint8_t*>(parameter) + profile * 0x2c;
    At<void*>(object, 0x34) = At<void*>(profile_entry, 0x228);
    ParameterString_Normalize_00352994(static_cast<std::uint8_t*>(object) + 0x38,
                                        profile_entry + 0x22c);
    MenuSelFile_InitializeSelectionData_00302038(object);
    void** resource_list_slot = &g_MenuSelFileResourceList_00D636CC;
    if (*resource_list_slot == 0)
        *resource_list_slot = FUN_002a69f4();
    std::uint8_t* resource_sentinel = static_cast<std::uint8_t*>(*resource_list_slot);
    std::uint8_t* resource_list = static_cast<std::uint8_t*>(
        At<void*>(resource_sentinel, 0x04));
    for (;;) {
        void* current = At<void*>(resource_list, 0);
        if (current == At<void*>(resource_sentinel, 0)) {
            void* command = Engine_LazyCommandWorkSingleton_0027C908();
            FUN_003B5918(At<void*>(object, 0xd8), &command, &command);
            void* resource = MenuResource_Resolve_002A6190(At<void*>(object, 0xd8));
            MenuSelFile_BindResource(object, resource, 0xd8,
                                     reinterpret_cast<const char*>(0x002be1ec));
            MenuSelFile_BindResource(object, resource, 0xdc,
                                     reinterpret_cast<const char*>(0x002be1f4));
            MenuSelFile_BindResource(object, resource, 0xe0,
                                     reinterpret_cast<const char*>(0x002be1fc));
            for (std::uint32_t i = 0; i < 6; ++i)
                MenuSelFile_InsertResourceLink_00301F80(object, resource,
                                                         At<void*>(object, 0xe4));
            for (std::uint32_t i = 0; i < 3; ++i) {
                void* source = At<void*>(object, 0xd8 + i * 4);
                void* selected = ResourceTreeFind(source, ResourceTree_KeyGetter_002A18B8());
                std::uint8_t* record = static_cast<std::uint8_t*>(selected) + 0x20;
                void* destination = bytes + 0xf8 + i * 0x40;
                MemoryFillEnd_003FDCAC(destination, 0x40);
                At<void*>(At<void*>(record, 0), 0x10) = destination;
            }
            void* battle = *battle_slot;
            FUN_0028D9D4(battle, bytes + 0x460);
            for (std::uint32_t i = 0; i < 3; ++i) {
                void* descriptor = bytes + 0x28c + i * 0x20;
                BufferDescriptor_Initialize_002D8AE8(descriptor,
                    static_cast<std::uint8_t*>(battle) + 0x460, 0x80, 0x80, 0);
                BufferDescriptor_Publish_002D89C8(descriptor);
            }
            break;
        }
        resource_list = static_cast<std::uint8_t*>(
            At<void*>(resource_list, 0x04));
    }
    for (std::uint32_t i = 0; i < 6; ++i) {
        void* link = At<void*>(object, 0x25c + i * 4);
        At<std::uint8_t>(link, 0x15) = i == 4;
        At<void*>(link, 0xc) = reinterpret_cast<void*>(0x002be75c + i * 0xc);
    }
    FUN_00337DE0(object);
    void* resource = At<void*>(object, 0xf4);
    void* selected = ResourceTreeFind(resource, ResourceTree_KeyGetter_002A18B8());
    At<void*>(object, 0x274) = selected;
    if (resource != 0)
        At<float>(resource, 0x7c) += scale;
    for (std::uint32_t i = 0; i < 0x10; ++i) {
        void* entry = static_cast<std::uint8_t*>(selected) + 0x1c;
        void* record = At<void*>(entry, 0);
        if (record == 0)
            break;
        void* named = MenuResource_FindNamedObject_00274FE8(
            At<void*>(object, 0xe4), static_cast<const char*>(At<void*>(record, 4)));
        At<std::uint32_t>(named, 0xc0) =
            (At<std::uint32_t>(named, 0xc0) & 0xffffffed) | 0x12;
        entry = At<void*>(entry, 4);
        selected = entry;
    }
    void** singleton_slot = &g_MenuRuntimeSingleton_00D6384C;
    if (*singleton_slot == 0)
        *singleton_slot = Engine_LazySingletonGetter_00422CC8();
    At<std::uint32_t>(*singleton_slot, 0x3f20) = 0;
    void* current_entry = ResourceTree_ResolveCurrentEntry_002A6268(
        At<void*>(object, 0xe4));
    if (current_entry != 0)
        FUN_002A15B4(At<void*>(current_entry, 0x20), At<void*>(object, 0xe4));
    current_entry = ResourceTree_ResolveCurrentEntry_002A6268(At<void*>(object, 0x30));
    if (current_entry != 0) {
        void* entry = static_cast<std::uint8_t*>(At<void*>(current_entry, 0x20)) + 8;
        FUN_0025EE70(entry);
        ResourceTree_SetEntryActive_0025EE3C(entry, 1);
    }
    void* resource_manager = Engine_LazySingletonGetter_003FD6E0();
    Resource_SetModeValue_0031EEB8(resource_manager, 0, 0.5f);
    Resource_SetModeValue_0031EEB8(resource_manager, 2, 0.5f);
    Resource_SetModeValue_0031EEB8(resource_manager, 1, 0.5f);
    ActorStateMachine_RequestStateByFactory(At<void*>(object, 0x30),
                                            StMenuAppear_Factory_00234A94());
    return 0;
}
extern "C" __attribute__((noinline)) bool BufferDescriptor_Initialize_002D8AE8(
    void* destination, void* owner, std::uint32_t rows, std::uint32_t columns,
    std::uint32_t mode) {
    const std::uint32_t size = 0x80 + rows * columns * 4;
    void* allocator = At<void*>(owner, 0x40);
    void* storage = 0;
    std::uint32_t descriptorStorage = mode;
    if (mode == 0) {
        storage = Allocate(allocator, size, false);
        descriptorStorage = static_cast<std::uint32_t>(
            (reinterpret_cast<std::uintptr_t>(storage) + 0x7f) & ~std::uintptr_t(0x7f));
        At<void*>(destination, 0x08) = storage;
    }
    std::uint8_t descriptor[0x1c] = {};
    At<std::uint32_t>(descriptor, 0x00) = columns;
    At<std::uint32_t>(descriptor, 0x04) = rows;
    At<std::uint32_t>(descriptor, 0x08) = 1;
    At<std::uint32_t>(descriptor, 0x10) = descriptorStorage;
    descriptor[0x19] = descriptorStorage == 0;
    void* resource = BufferDescriptor_Create_002EA2EC(descriptor, allocator);
    At<void*>(destination, 0x04) = resource;
    if (resource == 0)
        return false;
    At<void*>(destination, 0x0c) = Allocate(allocator, size, true);
    At<void*>(destination, 0x00) = owner;
    At<std::uint8_t>(destination, 0x1c) = 1;
    return true;
}
extern "C" __attribute__((noinline)) bool BufferDescriptor_Publish_002D89C8(void* descriptor) {
    if (At<void*>(descriptor, 0x04) == 0)
        return false;
    BufferField_Reset_00260C9C(1, static_cast<std::uint8_t*>(descriptor) + 0x10);
    BufferField_Reset_00260ED4(1, static_cast<std::uint8_t*>(descriptor) + 0x14);
    BufferField_Reset_00260ED4(1, static_cast<std::uint8_t*>(descriptor) + 0x18);
    BufferResource_Bind_001ECCEC(
        g_BufferResourceType_002D8AD8, At<void*>(descriptor, 0x10));
    void* resource = At<void*>(descriptor, 0x04);
    std::uint8_t* parent = static_cast<std::uint8_t*>(resource) + 0x38;
    const std::uint32_t parentOffset = At<std::uint32_t>(parent, 0x00);
    std::uint8_t* parentRecord = parentOffset == 0 ? 0 : parent + parentOffset;
    void* record = At<void*>(parentRecord, 0x18);
    if (record == 0) {
        std::uint8_t* child = parentRecord + 0x0c;
        const std::uint32_t childOffset = At<std::uint32_t>(child, 0);
        record = childOffset == 0 ? 0 : child + childOffset;
    }
    BufferResource_Notify_0031EBC8(record);
    BufferResource_SetField_00260A90(
        g_BufferResourceField_002D8ADC, At<void*>(descriptor, 0x14));
    BufferResource_SetFormat_00261284(
        g_BufferResourceField_002D8ADC, g_BufferFormat_002D8AE0,
        At<void*>(resource, 0x1c), At<void*>(resource, 0x18));
    BufferResource_SetName_00260BD8(
        g_BufferResourceType_002D8AD8,
        reinterpret_cast<std::uintptr_t>(g_BufferResourceField_002D8ADC) -
            0x61,
        g_BufferResourceField_002D8ADC, At<void*>(descriptor, 0x14));
    BufferResource_Notify_0031EBC8(
        reinterpret_cast<void*>((At<std::uintptr_t>(descriptor, 0x0c) + 0x7f) &
                                ~std::uintptr_t(0x7f)));
    BufferResource_SetField_00260A90(
        g_BufferResourceField_002D8ADC, At<void*>(descriptor, 0x18));
    BufferResource_SetFormat_00261284(
        g_BufferResourceField_002D8ADC, g_BufferFormat_002D8AE4,
        At<void*>(resource, 0x1c), At<void*>(resource, 0x18));
    BufferResource_SetName_00260BD8(
        g_BufferResourceType_002D8AD8, 0x8d00,
        g_BufferResourceField_002D8ADC, At<void*>(descriptor, 0x18));
    return true;
}
extern "C" __attribute__((noinline)) bool Resource_IsReady_002DC214(void* resource) {
    return g_ResourceReadyTable_002DC23C[reinterpret_cast<std::uintptr_t>(resource)] != 0 &&
           At<std::uint32_t>(resource, 0xf0) < 6;
}
extern "C" __attribute__((noinline)) void Resource_SetModeValue_0031EEB8(
    void* resource, std::int32_t mode, float value) {
    At<float>(resource, 0x208 + mode * 4) = value;
    std::uint8_t* cursor = static_cast<std::uint8_t*>(At<void*>(resource, 0x218));
    void* sentinel = At<void*>(resource, 0x214);
    for (; At<void*>(cursor, 0x00) != sentinel;
         cursor = static_cast<std::uint8_t*>(At<void*>(cursor, 0x04))) {
        std::uint8_t* record = static_cast<std::uint8_t*>(At<void*>(cursor, 0x00));
        if (static_cast<std::int8_t>(At<std::uint8_t>(record, 0x16)) == mode)
            BufferResource_Notify_0034C650(value, record);
    }
}
extern "C" __attribute__((noinline)) void* MenuSelFile_InsertResourceLink_00301F80(
    void*, void* resource, void* source) {
    void* allocator = Object_GetAllocatorContext_0042167C(source);
    std::uint8_t* link = static_cast<std::uint8_t*>(Engine_AllocateTaggedBlock_0047466C(
        0x28, &g_MenuSelFileLinkTypeTag_00302030, allocator));
    if (link != 0) {
        At<void*>(link, 0x00) = link;
        At<void*>(link, 0x04) = link;
        At<void*>(link, 0x08) = link;
        At<std::uint32_t>(link, 0x0c) = 0;
        At<std::uint32_t>(link, 0x10) = 0;
        At<std::uint8_t>(link, 0x14) = 0;
        At<std::uint8_t>(link, 0x15) = 0;
        At<std::uint32_t>(link, 0x18) = g_MenuSelFileDefaultValue_00302190;
        At<std::uint32_t>(link, 0x1c) = g_MenuSelFileDefaultValue_00302190;
        At<std::uint8_t>(link, 0x20) = 0xff;
        At<std::uint8_t>(link, 0x21) = 0xff;
        At<std::uint8_t>(link, 0x22) = 0xff;
        At<std::uint8_t>(link, 0x23) = 0xff;
        At<std::uint8_t>(link, 0x24) &= 0xf0;
    }
    At<std::uint8_t>(link, 0x20) = 0xff;
    At<std::uint8_t>(link, 0x22) = 0xff;
    At<std::uint8_t>(link, 0x21) = 0xff;
    At<std::uint8_t>(link, 0x14) = 0;
    At<std::uint8_t>(link, 0x15) = 0;
    std::uint8_t* sentinel = static_cast<std::uint8_t*>(At<void*>(resource, 0x20));
    if (sentinel != link) {
        std::uint8_t* previous = static_cast<std::uint8_t*>(At<void*>(link, 0x04));
        std::uint8_t* next = static_cast<std::uint8_t*>(At<void*>(link, 0x08));
        At<void*>(next, 0x04) = previous;
        At<void*>(previous, 0x08) = next;
        previous = static_cast<std::uint8_t*>(At<void*>(sentinel, 0x08));
        At<void*>(previous, 0x04) = link;
        At<void*>(link, 0x04) = sentinel;
        At<void*>(link, 0x08) = previous;
        At<void*>(sentinel, 0x08) = link;
    }
    return link;
}
extern "C" __attribute__((noinline)) void MenuSelFile_InitializeSelectionData_00302038(void* object) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(object);
    const std::uint32_t* defaults = static_cast<const std::uint32_t*>(
        g_MenuSelFileDefaultVector_0030218C);
    At<std::uint32_t>(object, 0x280) = defaults[0];
    At<std::uint32_t>(object, 0x284) = defaults[1];
    At<std::uint32_t>(object, 0x288) = defaults[2];
    void* key = actor_param::MenuSelFileParam_Factory_0030444C();
    void* node = OrderedTree_FindPayloadByPointer_00326C6C(
        At<void*>(object, 0x30), &key);
    void* parameter = node == 0 ? 0 : At<void*>(node, 0x1c);
    void* resource = MenuResource_RecordLookup_002BF024(
        static_cast<std::uint8_t*>(parameter) + 0x120);
    if (resource == 0)
        return;
    key = MenuResource_Key_002C00D4();
    node = OrderedTree_FindPayloadByPointer_00326C6C(resource, &key);
    void* selected = node == 0 ? 0 : At<void*>(node, 0x1c);
    void* current = ResourceTree_ResolveCurrentEntry_002A6268(resource);
    void* active = ResourceTree_FindActiveLink_002EE080(
        static_cast<std::uint8_t*>(At<void*>(current, 0x20)) + 8, resource);
    key = MenuResource_Key_002C00D4();
    node = OrderedTree_FindPayloadByPointer_00326C6C(resource, &key);
    void* records = node == 0 ? 0 : At<void*>(node, 0x1c);
    std::uint8_t* cursor = static_cast<std::uint8_t*>(At<void*>(records, 0x1c));
    void* target = MenuResource_FindNamedRecord_002D6DDC(
        static_cast<std::uint8_t*>(At<void*>(current, 0x20)) + 0x20c,
        active, At<const char*>(At<void*>(cursor, 0x00), 0x04));
    if (target != 0) {
        At<std::uint32_t>(target, 0xc0) |= 0x10;
        At<float>(target, 0x1c) = 0.0f;
        for (; At<void*>(cursor, 0x00) != At<void*>(selected, 0x18);
             cursor = static_cast<std::uint8_t*>(At<void*>(cursor, 0x04))) {
            std::uint8_t* record = static_cast<std::uint8_t*>(At<void*>(cursor, 0x00));
            if (At<void*>(record, 0x2c) == At<void*>(object, 0x34)) {
                At<float>(target, 0x1c) =
                    At<float>(record, 0x68) * g_DegreesToRadians_00302194;
                break;
            }
        }
    }
    void* final = MenuResource_FindNamedRecord_002D6DDC(
        static_cast<std::uint8_t*>(At<void*>(current, 0x20)) + 0x20c,
        active, g_MenuSelFileFinalKey_00302198);
    if (final != 0) {
        At<std::uint32_t>(bytes, 0x280) = At<std::uint32_t>(final, 0x08);
        At<std::uint32_t>(bytes, 0x284) = At<std::uint32_t>(final, 0x0c);
        At<std::uint32_t>(bytes, 0x288) = At<std::uint32_t>(final, 0x10);
    }
}
extern "C" __attribute__((noinline)) void MenuSelFile_TransferAnchorDelta_0030219C(void* object) {
    void* key = actor_param::MenuSelFileParam_Factory_0030444C();
    void* node = OrderedTree_FindPayloadByPointer_00326C6C(
        At<void*>(object, 0x30), &key);
    void* parameter = node == 0 ? 0 : At<void*>(node, 0x1c);
    void* resource = MenuResource_RecordLookup_002BF024(
        static_cast<std::uint8_t*>(parameter) + 0x120);
    if (resource == 0)
        return;
    key = MenuResource_Key_002C00D4();
    OrderedTree_FindPayloadByPointer_00326C6C(resource, &key);
    void* current = ResourceTree_ResolveCurrentEntry_002A6268(resource);
    void* active = ResourceTree_FindActiveLink_002EE080(
        static_cast<std::uint8_t*>(At<void*>(current, 0x20)) + 8, resource);
    float delta[3] = {
        g_MenuSelFileAnchorDefault_00DC249C[0],
        g_MenuSelFileAnchorDefault_00DC249C[1],
        g_MenuSelFileAnchorDefault_00DC249C[2],
    };
    void* anchor = MenuResource_FindNamedRecord_002D6DDC(
        static_cast<std::uint8_t*>(At<void*>(current, 0x20)) + 0x20c,
        active, reinterpret_cast<const char*>(0x003022e8));
    if (anchor != 0) {
        delta[0] = At<float>(anchor, 0x08) - At<float>(object, 0x280);
        delta[1] = At<float>(anchor, 0x0c) - At<float>(object, 0x284);
        delta[2] = At<float>(anchor, 0x10) - At<float>(object, 0x288);
        At<float>(object, 0x280) = At<float>(anchor, 0x08);
        At<float>(object, 0x284) = At<float>(anchor, 0x0c);
        At<float>(object, 0x288) = At<float>(anchor, 0x10);
    }
    key = MenuResource_Key_002C00D4();
    node = OrderedTree_FindPayloadByPointer_00326C6C(resource, &key);
    void* records = node == 0 ? 0 : At<void*>(node, 0x1c);
    std::uint8_t* first = static_cast<std::uint8_t*>(At<void*>(records, 0x1c));
    std::uint8_t* record = static_cast<std::uint8_t*>(At<void*>(first, 0));
    void* target = MenuResource_FindNamedRecord_002D6DDC(
        static_cast<std::uint8_t*>(At<void*>(current, 0x20)) + 0x20c,
        active, At<const char*>(record, 4));
    if (target != 0) {
        At<float>(target, 0x08) += delta[0];
        At<float>(target, 0x0c) += delta[1];
        At<float>(target, 0x10) += delta[2];
    }
}
extern "C" __attribute__((noinline)) void MenuProfileState_Initialize_002E33D4(void* object) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(object);
    const std::uint8_t zero = 0;
    // Three 5x5 profile-state tables are cleared, then counted by state kind.
    void* profile_table = bytes + 8;
    for (std::uint32_t profile = 0; profile < 3; ++profile) {
        FUN_003DC5D0(
            static_cast<std::uint8_t*>(profile_table) + profile * 0x78 + 4,
            0x78);
        for (std::uint32_t kind = 0; kind < 5; ++kind) {
            bytes[0x175 + profile * 5 + kind] = zero;
            if (bytes[0x175 + profile * 5 + kind] == 1 ||
                bytes[0x175 + profile * 5 + kind] == 2 ||
                bytes[0x175 + profile * 5 + kind] == 4 ||
                bytes[0x175 + profile * 5 + kind] == 6)
                ++bytes[0x184 + profile];
        }
        bytes[0x17f + profile] = zero;
    }
    bytes[0x16c] = zero;
    bytes[0x16d] = 1;
    bytes[0x184] = zero;
    for (std::uint32_t kind = 0; kind < 5; ++kind) {
        if (bytes[0x175 + kind] == 1 || bytes[0x175 + kind] == 2 ||
            bytes[0x175 + kind] == 4 || bytes[0x175 + kind] == 6)
            ++bytes[0x184];
    }
    const float profile_default = 0.8f;
    At<float>(bytes, 0x194) = profile_default;
    At<float>(bytes, 0x198) = profile_default;
    At<float>(bytes, 0x19c) = profile_default;
    for (std::uint32_t group = 0; group < 4; ++group) {
        std::uint8_t* records = bytes + 0x8a34 + group * 0x128 + 0x234;
        for (std::uint32_t record = 0; record < 0x24; ++record)
            records[record * 8 + 0x0c] &= 0x00ff;
        records[0x124] = zero;
    }
    for (std::uint32_t group = 0; group < 0x11; ++group) {
        std::uint8_t* records = bytes + 0x8a34 + group * 0x128 + 0x4a4;
        for (std::uint32_t record = 0; record < 0x24; ++record)
            records[record * 8 + 0x0c] &= 0x00ff;
        records[0x124] = zero;
        At<std::uint16_t>(records + 0x100, 0x26) &= 0xf800;
    }
    MemoryRecordArray_Initialize_00106494(bytes + 0xa284);
    std::uint8_t* profile = bytes + 0xffe0;
    At<float>(profile, 0x04) = 0.0f;
    At<float>(profile, 0x08) = 0.0f;
    At<float>(profile, 0x0c) = 0.0f;
    profile[0x18] |= 2;
    At<std::uint32_t>(profile, 0x10) = 0;
    profile[0x18] = static_cast<std::uint8_t>((profile[0x18] & ~1u) | 2);
    At<std::uint32_t>(profile, 0x14) = 0;
    profile[0x18] &= static_cast<std::uint8_t>(~6u);
    ResourceRecord_ResetState_00107978(bytes + 0xfeb8);
    std::uint8_t* substate = bytes + 0x1001c;
    substate[0x04] = 1;
    substate[0x08] = zero;
    substate[0x0c] = zero;
    substate[0x10] = zero;
    substate[0x14] = zero;
    substate[0x18] = zero;
    At<float>(substate, 0x1c) = 0.0f;
    for (std::uint32_t bit = 0; bit < 0x80; ++bit)
        bytes[0x10000 + 0x3fc + (bit >> 3)] &=
            static_cast<std::uint8_t>(~(1u << (bit & 7)));
    bytes[0x10000 + 0x3fc + 0x14] &= 0;
    At<float>(bytes + 0x10000, 0x14) = 0.0f;
    At<float>(bytes + 0x10000, 0x18) = 0.0f;
    bytes[0x10000 + 0x164] = zero;
    bytes[0x10000 + 0x165] = zero;
    At<std::uint32_t>(bytes, 0x1e8) = 0;
    At<std::uint32_t>(bytes, 0x1ec) = 0;
    At<std::uint32_t>(bytes, 0x1f0) = 0;
    At<std::uint32_t>(bytes, 0x1f4) = 0;
    bytes[0x10000 + 0x173] = static_cast<std::uint8_t>(
        (bytes[0x10000 + 0x173] & ~1u) | 2);
    if (g_MenuProfileStateSingletonSlot_002E38D4 == 0)
        g_MenuProfileStateSingletonSlot_002E38D4 =
            Engine_LazySingletonGetter_003FD6E0();
    std::uint8_t* singleton = static_cast<std::uint8_t*>(
        g_MenuProfileStateSingletonSlot_002E38D4);
    singleton[0x32e8] = (bytes[0x10000 + 0x173] & 2) >> 1;
    At<std::uint32_t>(bytes + 0x10000, 0x170) =
        (At<std::uint32_t>(bytes + 0x10000, 0x170) & 0xfffff3ff) | 0x800;
    bytes[0x10000 + 0x173] &= static_cast<std::uint8_t>(~0x0c);
    At<std::uint32_t>(bytes + 0x10000, 0x170) =
        (At<std::uint32_t>(bytes + 0x10000, 0x170) & 0xffe00fff) | 0x11000;
    At<std::uint32_t>(bytes + 0x10000, 0x16c) &= 0xfffff000;
    bytes[0x10000 + 0x174] &= static_cast<std::uint8_t>(~0x80);
    At<std::uint32_t>(bytes + 0x10000, 0x16c) &= 0xffff8fff;
    At<std::uint32_t>(bytes + 0x10000, 0x170) &= 0xfffffc00;
    bytes[0x10000 + 0x173] = static_cast<std::uint8_t>(
        (bytes[0x10000 + 0x173] & 0x1f) | 0x50);
    bytes[0x10000 + 0x174] |= 1;
    At<std::uint32_t>(bytes + 0x10000, 0x170) &= 0xff1fffff;
    bytes[0x10000 + 0x174] &= static_cast<std::uint8_t>(0xc1);
    At<float>(bytes + 0x10000, 0x150) = 0.0f;
    At<float>(bytes + 0x10000, 0x154) = 0.0f;
    At<float>(bytes + 0x10000, 0x160) = 0.0f;
    At<float>(bytes + 0x10000, 0x158) = 0.0f;
    At<float>(bytes + 0x10000, 0x15c) = 0.0f;
    At<std::uint32_t>(bytes + 0x10000, 0x60) = 0;
    bytes[0x10000 + 0x174] |= 0x40;
    At<std::uint16_t>(bytes, 0x3ac) = 0;
    At<std::uint32_t>(bytes + 0x10000, 0x64) = 0;
    At<std::uint32_t>(bytes + 0x10168, 0x00) =
        g_MenuProfileStateFieldDefault_002E38D8;
    At<std::uint32_t>(bytes + 0x10168, 0x04) &= 0xfe007fff;
    for (std::uint32_t i = 0; i < 0x32; ++i) {
        bytes[0x63c + i * 2] = zero;
        bytes[0x63d + i * 2] = zero;
    }
    for (std::uint32_t i = 0; i < 0x6c; ++i) {
        At<std::uint32_t>(bytes, 0x1fc + i * 4) = 0;
        bytes[0x3ae + (i >> 3)] &=
            static_cast<std::uint8_t>(~(1u << (i & 7)));
    }
    for (std::uint32_t i = 0; i < 100; ++i) {
        const std::uint32_t bit0 = i * 2;
        bytes[0x413 + (bit0 >> 3)] &=
            static_cast<std::uint8_t>(~(1u << (bit0 & 7)));
        const std::uint32_t bit1 = bit0 + 1;
        bytes[0x413 + (bit1 >> 3)] &=
            static_cast<std::uint8_t>(~(1u << (bit1 & 7)));
    }
    for (std::uint32_t i = 0; i < 0x19c; ++i) {
        bytes[0x46c + i] = zero;
        const std::uint8_t mask = static_cast<std::uint8_t>(1u << (i & 7));
        bytes[0x608 + (i >> 3)] =
            static_cast<std::uint8_t>((bytes[0x608 + (i >> 3)] & ~mask) | mask);
    }
    for (std::uint32_t i = 0; i < 1000; ++i) {
        std::uint8_t* entry = bytes + 0x670 + i * 0x20;
        At<std::uint32_t>(entry, 0x04) = 0;
        for (std::uint32_t j = 0; j < 6; ++j) {
            At<std::uint16_t>(entry, 0x22 + j * 2) = 0;
            At<std::uint16_t>(entry, 0x16 + j * 2) = 0;
        }
    }
    for (std::uint32_t i = 0; i < 0xd1; ++i)
        At<std::uint32_t>(bytes, 0x8374 + i * 8) &= 0x80000000;
    for (std::uint32_t i = 0; i < 0x19; ++i) {
        At<std::uint32_t>(bytes, 0x10068 + i * 4) = 0;
        bytes[0x100d0 + i] = zero;
        At<float>(bytes + 0x10000 + i * 4, 0xec) = 0.0f;
        At<std::uint32_t>(bytes + g_MenuProfileStateTableStride_002E3BA4 + i * 8,
                          0) = 0;
    }
    for (std::uint32_t i = 0; i < 0x1e; ++i) {
        bytes[0x89f8 + i] = zero;
        bytes[0x89f9 + i] = zero;
    }
    bytes[0x3bc] &= static_cast<std::uint8_t>(~1u);
    for (std::uint32_t bit = 1; bit < 0xe9; bit += 2) {
        bytes[0x3bc + (bit >> 3)] &=
            static_cast<std::uint8_t>(~(1u << (bit & 7)));
        bytes[0x3bc + ((bit + 1) >> 3)] &=
            static_cast<std::uint8_t>(~(1u << ((bit + 1) & 7)));
    }
    for (std::uint32_t bit = 0; bit < 0x200; bit += 2) {
        bytes[0x42c + (bit >> 3)] &=
            static_cast<std::uint8_t>(~(1u << (bit & 7)));
        const std::uint32_t next = bit + 1;
        bytes[0x42c + (next >> 3)] &=
            static_cast<std::uint8_t>(~(1u << (next & 7)));
    }
    for (std::uint32_t i = 0; i < 0x39; ++i)
        bytes[0x3da + i] = zero;
    At<std::uint32_t>(bytes + 0x10000, 0x40) = 0;
    bytes[0x10000 + 0x45] = zero;
    bytes[0x10000 + 0x44] = zero;
    At<std::uint32_t>(bytes + 0x10000, 0x4c) = 0;
    bytes[0x10000 + 0x51] = zero;
    bytes[0x10000 + 0x50] = zero;
    At<std::uint32_t>(bytes + 0x10000, 0x58) = 0;
    bytes[0x10000 + 0x5d] = zero;
    bytes[0x10000 + 0x5c] = zero;
}

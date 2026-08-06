#include <cstdint>
extern "C" __attribute__((noinline)) void FontTextResource_Clear_0072ACAC(void* resource) {
    *static_cast<void**>(resource) = 0;
}
extern "C" __attribute__((noinline)) void FontTextManager_SetMode_00575438(
    void* manager, std::uint32_t mode) {
    std::uint8_t* owner = *reinterpret_cast<std::uint8_t**>(
        static_cast<std::uint8_t*>(manager) + 0x64);
    if (owner != 0)
        *reinterpret_cast<std::uint32_t*>(owner + 0x2e4) = mode;
}
extern "C" __attribute__((noinline)) std::uint32_t FontText_BindResourceDescriptor_005AF934(
    void* text, std::uint32_t slot, const void* descriptor) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(text);
    if (slot >= *reinterpret_cast<std::uint32_t*>(bytes + 8))
        return 0;
    std::uint32_t* indices = *reinterpret_cast<std::uint32_t**>(bytes + 0x0c);
    std::uint32_t* descriptors = *reinterpret_cast<std::uint32_t**>(bytes + 0x10);
    if (indices == 0 || descriptors == 0)
        return 0;
    const std::uint32_t* source = static_cast<const std::uint32_t*>(descriptor);
    std::uint32_t* destination = descriptors + slot * 3;
    destination[0] = source[0];
    destination[1] = source[1];
    destination[2] = source[2];
    indices[slot] = slot + 0xf0;
    return 1;
}
extern "C" __attribute__((noinline)) std::uint32_t
FontText_BindResourceDescriptor_Slot20_005AF928(
    void* text, const void* descriptor) {
    return FontText_BindResourceDescriptor_005AF934(text, 0x14, descriptor);
}
extern "C" void* ResourceDescriptor_GetEntry_005AF908(
    void* text, std::uint32_t slot);
extern "C" void ResourceDescriptor_SetLayerFlags_005AF8E0(
    void* descriptor, std::uint32_t first, std::uint32_t second);
extern "C" __attribute__((noinline)) void FontText_BindOverlayResourceBody_0057FAE8(
    void* text_object, std::uint32_t slot, const void* descriptor) {
    if (slot >= 2)
        return;
    std::uint8_t* text = static_cast<std::uint8_t*>(text_object);
    if (FontText_BindResourceDescriptor_005AF934(
            text, slot + 4, descriptor) == 0)
        return;
    *reinterpret_cast<std::uint32_t*>(text + 0x2a0) |= 1u << slot;
    if (slot == 1) {
        void* entry = ResourceDescriptor_GetEntry_005AF908(text, 5);
        if (entry != 0)
            ResourceDescriptor_SetLayerFlags_005AF8E0(entry, 3, 3);
    }
}
extern "C" __attribute__((noinline)) void FontTextManager_BindOverlayResource_00575450(
    void* manager, std::uint32_t slot, const void* descriptor) {
    std::uint8_t* owner = *reinterpret_cast<std::uint8_t**>(
        static_cast<std::uint8_t*>(manager) + 0x64);
    if (owner == 0)
        return;
    FontText_BindOverlayResourceBody_0057FAE8(owner + 0x4c, slot, descriptor);
}
extern "C" void FUN_0057F8D4(
    void* state, std::uint32_t metric_mode, std::uint32_t counter_mode);
extern "C" void* Engine_LazySingletonGetter_00422CC8();
extern "C" void* GetEngineSingleton_003B6CF0();
extern "C" float FUN_0054BFB8(int count, float step);
extern "C" std::uint32_t FUN_005B8DD8(void* resource, std::uint32_t channel);
extern "C" __attribute__((noinline)) int FontText_ResolveMetricResource_005A7840(
    void* resource) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(resource);
    static void** const mode_cache = reinterpret_cast<void**>(0x00d6364cu);
    static void** const engine_cache = reinterpret_cast<void**>(0x00d6365cu);
    std::uint8_t* mode_owner = static_cast<std::uint8_t*>(*mode_cache);
    std::uint8_t* engine = static_cast<std::uint8_t*>(*engine_cache);
    if (mode_owner == 0) {
        mode_owner = static_cast<std::uint8_t*>(
            Engine_LazySingletonGetter_00422CC8());
        *mode_cache = mode_owner;
    }
    if (engine == 0) {
        engine = static_cast<std::uint8_t*>(GetEngineSingleton_003B6CF0());
        *engine_cache = engine;
    }
    const int mode = static_cast<int>(static_cast<signed char>(
        mode_owner[0x3f04]));
    const int mode_plus_one = mode + 1;
    const int special = static_cast<int>(static_cast<signed char>(
        mode_owner[0x3f05]));
    const int engine_bit = (engine[0x6691] >> 1) & 1;
    float weights[11];
    int i;
    if ((mode_plus_one == 0x12 || mode_plus_one == 0x16) && special == 0) {
        for (i = 0; i < 11; ++i)
            weights[i] = 0.0f;
        weights[4] = 1.0f;
    } else {
        const int mode_class =
            (engine_bit == 0 && mode_plus_one >= 0 && mode_plus_one <= 3);
        const int mode_group_b =
            mode <= 9 || (mode >= 0x12 && mode <= 0x17);
        const int mode_group_c =
            (mode >= 10 && mode <= 13) || mode == 0x14 || mode == 0x17;
        const int mode_group_d =
            (mode >= 14 && mode <= 16) || mode == 0x14 || mode == 0x17;
        const int mode_group_e = (mode == 0x11 || mode == 0x13);
        const int mode_group_not_e = !mode_group_e;
        const int mode_group_f = (mode == 7);
        weights[0] = mode_class ? 5.0f : 0.5f;
        weights[1] = 1.0f;
        weights[2] = mode <= 0x1b ? 1.0f : 0.0f;
        weights[3] = mode_group_b ? 1.0f : 0.0f;
        weights[4] = mode_group_b ? 0.7f : weights[2];
        weights[5] = mode_group_b ? 1.0f : 0.0f;
        weights[6] = mode_group_c ? 2.0f : 0.0f;
        weights[7] = mode_group_d ? 2.0f : 0.0f;
        weights[8] = mode_group_not_e ? 2.0f : 0.0f;
        weights[9] = mode_group_e ? 5.0f : 0.0f;
        weights[10] = mode_group_f ? 5.0f : 0.0f;
    }
    float cumulative = 0.0f;
    float candidates[22];
    int candidate_count = 0;
    const int current = *reinterpret_cast<int*>(bytes + 0x18);
    const int resource_count = *reinterpret_cast<int*>(bytes + 0x100);
    for (i = 0; i < 11; ++i) {
        float weight = weights[i];
        std::uint8_t* record = bytes + i * 0x14;
        if (weight > cumulative &&
            (i != current || *reinterpret_cast<int*>(record + 0x20) != 1)) {
            int lag = resource_count - *reinterpret_cast<int*>(record + 0x28);
            if (lag > 0) {
                if (lag > 8)
                    lag = 8;
                weight *= FUN_0054BFB8(lag, 0.1f);
            }
            cumulative += (1.0f +
                static_cast<float>(*reinterpret_cast<int*>(record + 0x20) -
                                   *reinterpret_cast<int*>(record + 0x24)) *
                0.1f) * weight;
            candidates[candidate_count * 2] = cumulative;
            candidates[candidate_count * 2 + 1] = static_cast<float>(i);
            ++candidate_count;
        }
    }
    int selected = 1;
    if (candidate_count > 0) {
        std::uint32_t x = *reinterpret_cast<std::uint32_t*>(bytes + 4);
        const std::uint32_t y = *reinterpret_cast<std::uint32_t*>(bytes + 8);
        const std::uint32_t z = *reinterpret_cast<std::uint32_t*>(bytes + 12);
        const std::uint32_t w = *reinterpret_cast<std::uint32_t*>(bytes + 16);
        x = x ^ (x << 11);
        x = x ^ (x >> 8) ^ w ^ (w >> 19);
        *reinterpret_cast<std::uint32_t*>(bytes + 16) = x;
        *reinterpret_cast<std::uint32_t*>(bytes + 12) = w;
        *reinterpret_cast<std::uint32_t*>(bytes + 8) = z;
        *reinterpret_cast<std::uint32_t*>(bytes + 4) = y;
        const float threshold = static_cast<float>(x >> 8) *
            0.00000011920928955078125f * cumulative;
        for (i = 0; i < candidate_count; ++i) {
            if (threshold <= candidates[i * 2]) {
                selected = static_cast<int>(candidates[i * 2 + 1]);
                break;
            }
        }
    }
    const std::uint32_t result = FUN_005B8DD8(
        resource, static_cast<std::uint32_t>(selected));
    *reinterpret_cast<int*>(bytes + 0x14) = result;
    *reinterpret_cast<int*>(bytes + 0x18) = selected;
    return static_cast<int>(result);
}
extern "C" int FUN_005A8AE8(
    void* state, int* metrics, int entry, std::uint32_t colour, float scale,
    float width_limit, float height_limit);
extern "C" void FontText_PrepareSingleGlyphBatch_005A8C28(void* state);
extern "C" void FontText_SetLayoutState_005A899C(
    void* state, std::uint32_t mode, std::uint32_t enabled);
extern "C" void* Engine_LazySingletonGetter_0054EFA8();
extern "C" void* Engine_LazySingletonGetter_00422CC8();
extern "C" std::uint32_t Engine_GetGlobalFlags_004A9690();
extern "C" std::uint32_t Engine_SingletonField88_Get_005A5B34();
extern "C" void FUN_005BF53C(void* state);
// Semantic reconstruction, JP Rev 1: 0x0057F8D4.
extern "C" __attribute__((noinline)) void FUN_0057F8D4(
    void* state, std::uint32_t metric_mode, std::uint32_t counter_mode) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(state);
    std::uint32_t* flags = reinterpret_cast<std::uint32_t*>(bytes + 0x270);
    *flags |= 0x82000000u;
    FontText_SetLayoutState_005A899C(state, 5, 1);
    if (metric_mode != 0) {
        void* const resource = *reinterpret_cast<void**>(bytes + 0x394);
        if (resource != 0) {
            const int entry = FontText_ResolveMetricResource_005A7840(resource);
            if (entry >= 0) {
                int* const metrics = reinterpret_cast<int*>(bytes + 0x3ac);
                if (FUN_005A8AE8(
                        state, metrics, entry, 0xffffffffu, 0.5f, 200.0f,
                        240.0f) != 0) {
                    const float metric_width =
                        *reinterpret_cast<float*>(bytes + 0x3b8);
                    const float metric_height =
                        *reinterpret_cast<float*>(bytes + 0x3bc);
                    const float source_width =
                        *reinterpret_cast<float*>(bytes + 0x3c0);
                    const float source_height =
                        *reinterpret_cast<float*>(bytes + 0x3c4);
                    *reinterpret_cast<float*>(bytes + 0x3c0) =
                        static_cast<float>(static_cast<int>(
                            source_width + 200.0f - metric_width * 0.5f +
                            0.5f));
                    *reinterpret_cast<float*>(bytes + 0x3c4) =
                        static_cast<float>(static_cast<int>(
                            source_height + 240.0f - 29.5f -
                            metric_height * 0.5f + 0.5f));
                    FontText_PrepareSingleGlyphBatch_005A8C28(state);
                    *flags |= 0x04000000u;
                }
            }
        }
    }
    if (counter_mode != 0 &&
        *reinterpret_cast<std::int32_t*>(bytes + 0x390) >= 0) {
        std::uint8_t* timing = *reinterpret_cast<std::uint8_t**>(0x00d63578u);
        if (timing == 0) {
            timing = static_cast<std::uint8_t*>(
                Engine_LazySingletonGetter_0054EFA8());
            *reinterpret_cast<std::uint8_t**>(0x00d63578u) = timing;
        }
        const std::uint32_t global_flags = Engine_GetGlobalFlags_004A9690();
        std::uint8_t* environment = *reinterpret_cast<std::uint8_t**>(0x00d6364cu);
        if (environment == 0) {
            environment = static_cast<std::uint8_t*>(
                Engine_LazySingletonGetter_00422CC8());
            *reinterpret_cast<std::uint8_t**>(0x00d6364cu) = environment;
        }
        if ((global_flags & 0x200u) != 0) {
            const std::uint32_t scaled =
                *reinterpret_cast<std::uint32_t*>(environment + 0x4030) * 100u;
            *reinterpret_cast<std::uint32_t*>(bytes + 0x39c) =
                static_cast<std::uint32_t>(
                    (static_cast<std::uint64_t>(scaled) * 0x88888889u) >> 36);
            *reinterpret_cast<std::uint32_t*>(bytes + 0x3a0) =
                *reinterpret_cast<std::uint32_t*>(environment + 0x4334);
            *reinterpret_cast<std::uint32_t*>(bytes + 0x3a4) =
                *reinterpret_cast<std::uint32_t*>(environment + 0x4020);
            *reinterpret_cast<std::uint32_t*>(bytes + 0x3a8) = 0;
            *flags |= 0x10000000u;
        } else {
            *reinterpret_cast<std::uint32_t*>(bytes + 0x39c) =
                static_cast<std::uint32_t>(environment[0x3f38]);
            *reinterpret_cast<std::uint32_t*>(bytes + 0x3a0) =
                *reinterpret_cast<std::uint32_t*>(timing + 0xa6c);
            *reinterpret_cast<std::uint32_t*>(bytes + 0x3a4) =
                Engine_SingletonField88_Get_005A5B34();
            *reinterpret_cast<std::uint32_t*>(bytes + 0x3a8) =
                *reinterpret_cast<std::uint32_t*>(timing + 0xa68);
            *flags &= ~0x10000000u;
        }
        FUN_005BF53C(state);
        *flags |= 0x08000000u;
    }
    *reinterpret_cast<float*>(bytes + 0x29c) = 0.0f;
}
extern "C" __attribute__((noinline)) void FontTextManager_ActivateOverlayChild_00575468(void* manager) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(manager);
    bytes[0x16c] = static_cast<std::uint8_t>(
        (bytes[0x16c] & ~0x18u) | 4u);
    std::uint8_t* owner = *reinterpret_cast<std::uint8_t**>(bytes + 0x64);
    if (owner != 0) {
        FUN_0057F8D4(owner + 0x4c, 0, 0);
        owner[0x31] = 1;
    }
}
extern "C" void* FontTextManager_Get_003532F0();
extern void* g_FontTextManagerCache_00D6366C;
extern "C" __attribute__((noinline)) void* ResourceDescriptorTable_Get_00576244(
    void* table, std::uint32_t key) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(table);
    std::uint8_t* descriptors = *reinterpret_cast<std::uint8_t**>(bytes + 0x10);
    if (descriptors != 0 &&
        key < *reinterpret_cast<std::uint32_t*>(bytes + 8))
        return descriptors + key * 12;
    return reinterpret_cast<void*>(0x00cb1928u);
}
extern "C" __attribute__((noinline)) std::uint32_t ResourceDescriptorTable_Has_00576268(
    void* table, std::uint32_t key) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(table);
    if (key >= *reinterpret_cast<std::uint32_t*>(bytes + 8))
        return 0;
    std::uint32_t* indices = *reinterpret_cast<std::uint32_t**>(bytes + 0x0c);
    void* descriptors = *reinterpret_cast<void**>(bytes + 0x10);
    return indices != 0 && descriptors != 0 &&
           indices[key] != 0;
}
extern "C" __attribute__((noinline)) void TextureDescriptor_SetModes_0092F7D4(
    std::uint32_t* descriptor, std::uint32_t first, std::uint32_t second) {
    if (first >= 2)
        first = 1;
    if (second >= 6)
        second = 1;
    descriptor[0] = (descriptor[0] & ~0xf0u) |
                    ((first & 1) << 4) | ((second & 7) << 5);
}
extern "C" std::uint32_t Platform_MapResourceAddress_003AC86C(
    std::uint32_t address);
extern "C" __attribute__((noinline)) std::uint32_t TextureDescriptor_EncodeFromResource_0092E974(
    std::uint32_t* descriptor, void* resource) {
    if (resource == 0 ||
        *reinterpret_cast<std::uint32_t*>(
            static_cast<std::uint8_t*>(resource) + 0x2c) == 0) {
        descriptor[0] = 0x30;
        descriptor[1] = 0;
        descriptor[2] = 0;
        return 0;
    }
    std::uint8_t* bytes = static_cast<std::uint8_t*>(resource);
    const std::uint32_t width = *reinterpret_cast<std::uint32_t*>(bytes + 0x18);
    const std::uint32_t height = *reinterpret_cast<std::uint32_t*>(bytes + 0x1c);
    const std::uint32_t format = *reinterpret_cast<std::uint32_t*>(bytes + 0x34);
    std::uint8_t* relative = bytes + 0x38;
    const std::uint32_t offset = *reinterpret_cast<std::uint32_t*>(relative);
    std::uint8_t* source = offset == 0 ? 0 : relative + offset;
    std::uint32_t address = *reinterpret_cast<std::uint32_t*>(source + 0x18);
    if (address == 0) {
        relative = source + 0x0c;
        const std::uint32_t nested_offset =
            *reinterpret_cast<std::uint32_t*>(relative);
        address = nested_offset == 0
                      ? 0
                      : static_cast<std::uint32_t>(
                            reinterpret_cast<std::uintptr_t>(
                                relative + nested_offset));
    }
    descriptor[0] = (format & 0x0f) | 0x30;
    descriptor[1] = Platform_MapResourceAddress_003AC86C(address) >> 3;
    descriptor[2] = (width & 0x7ff) | ((height & 0x7ff) << 16);
    return *reinterpret_cast<std::uint32_t*>(bytes + 0x2c);
}
extern "C" __attribute__((noinline)) void ResourceDescriptorTable_CopyWithModes_0060DE8C(
    void* table, std::uint32_t source_slot, std::uint32_t destination_slot,
    std::uint32_t first_mode, std::uint32_t second_mode) {
    if (ResourceDescriptorTable_Has_00576268(table, source_slot) == 0)
        return;
    const std::uint32_t* source = static_cast<const std::uint32_t*>(
        ResourceDescriptorTable_Get_00576244(table, source_slot));
    std::uint32_t descriptor[3] = {source[0], source[1], source[2]};
    TextureDescriptor_SetModes_0092F7D4(
        descriptor, first_mode, second_mode);
    FontText_BindResourceDescriptor_005AF934(
        table, destination_slot, descriptor);
}
extern "C" __attribute__((noinline)) void FontTextManager_SetupOverlayResources_0054A1E8(void* owner) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(owner);
    if ((*reinterpret_cast<std::uint32_t*>(bytes + 0xc0) &
         0x30000000u) == 0)
        return;
    void* table = *reinterpret_cast<void**>(bytes + 0x140);
    if (table == 0)
        return;
    void* manager = g_FontTextManagerCache_00D6366C;
    if (manager == 0) {
        manager = FontTextManager_Get_003532F0();
        g_FontTextManagerCache_00D6366C = manager;
    }
    const std::uint32_t mode =
        (*reinterpret_cast<std::uint32_t*>(bytes + 0xc0) &
         0x10000000u) != 0 ? 1u : 2u;
    FontTextManager_SetMode_00575438(manager, mode);
    for (std::uint32_t slot = 0; slot != 2; ++slot) {
        const std::uint32_t key = 0xc5 + slot;
        if (ResourceDescriptorTable_Has_00576268(table, key) != 0) {
            FontTextManager_BindOverlayResource_00575450(
                manager, slot,
                ResourceDescriptorTable_Get_00576244(table, key));
        }
    }
    FontTextManager_ActivateOverlayChild_00575468(manager);
    *reinterpret_cast<std::uint32_t*>(bytes + 0xc0) &= 0xcfffffffu;
}
extern "C" void FontEffectEvent_Notify_0075D298(int event_type);
extern "C" std::uint32_t ResourceWrapper_FirstField_00425F64(
    const void* wrapper_or_handle);
extern "C" int ResourceTable_FindOffset_00425F6C(
    void* wrapper, const char* name);
extern "C" std::uint32_t ResourceTable_EntryLength_0049CB04(
    const void* table, int entry);
extern "C" void ParameterString_Assign_0043A31C(
    void* string, const char* text);
extern "C" void FUN_004C5484(void* string, const char* text);
extern "C" void ParameterString_AppendLiteral_003721DC(
    void* string, const char* text);
extern "C" const void* ResourceTable_GetEntry_00579AD0(
    const void* table, int entry);
extern "C" int Utf16_CountUnits_005509C0(const std::int16_t* text);
extern "C" int ParameterString_SplitByDelimiter_0029F780(
    void* cursor, void* output, int delimiter);
extern "C" int ByteString_FindChar_00262F94(
    char* text, int character);
extern "C" std::uint32_t ResourceWrapper_FirstField_00425F64(
    const void* wrapper_or_handle);
extern "C" void* Engine_CopyBytes_0044C108(
    void* destination, const void* source, std::uint32_t size);
extern "C" unsigned char* FUN_005B4B38(
    const void* packed_resource, float* bounds, int begin, int count);
extern "C" void Engine_BulkCopy_00425DF8(
    void* destination, const void* source, std::uint32_t size);
extern "C" void FontResource_ApplyPackedText_005CF240(
    void* resource, std::uint32_t begin, std::uint32_t end);
extern "C" void FontText_ResetBatchState_005C7888(void* batch);
extern "C" void FontResource_SelectTextBuffer_005BF1C4(void* batch);
extern "C" void FontResource_ApplyTextRecord_005CB100(
    void* batch, std::uint32_t begin, std::uint32_t end);
extern "C" void* FontText_BatchIdentity_005C78A4(void* batch);
extern "C" void* Engine_RendererSingleton_Get_005C3CE4();
extern "C" void FontText_CompileGlyphBatch_005BFA8C(
    void* renderer, void* batch);
extern "C" void FontRecord_ClearTransientFlag_005D5520(void* record);
extern "C" std::uint32_t FUN_005CAD18(
    void* resource, float* record_bounds, std::uint32_t* cursor, int count);
extern "C" __attribute__((noinline)) void FontRecord_ClearTransientFlag_005D5520(void* record) {
    static_cast<std::uint8_t*>(record)[0x12] = 0;
}
extern "C" __attribute__((noinline)) char* FontResource_BuildTexturePath_00717CE8(void* owner) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(owner);
    std::uint32_t cursor = *reinterpret_cast<std::uint32_t*>(bytes + 0xb2d8);
    std::uint8_t* entry = bytes + 0xb2dc + cursor * 0x18;
    cursor = cursor + 1 < 8 ? cursor + 1 : 0;
    entry[8] = 0;
    ParameterString_Assign_0043A31C(entry, "bin/");
    FUN_004C5484(entry, "fnt");
    ParameterString_AppendLiteral_003721DC(entry, ".bin");
    return *reinterpret_cast<char**>(entry);
}
extern "C" void FUN_005D5230(
    void* resource, void* glyph_record, float horizontal_position);
extern "C" float Float_ForceIntConversion_0049A8B0(float value);
extern "C" void FontText_UpdatePendingResource_0051DBA0(
    std::uint32_t tag, std::uint32_t key);
extern "C" void FontText_PendingValueUpdate_0051E934(
    std::uint32_t mode, std::uint32_t* value);
extern "C" void FUN_005D7FE4(std::uint32_t left, std::uint32_t top,
                               std::uint32_t height, std::uint32_t glyph,
                               std::uint32_t texture_handle,
                               std::uint32_t texture_state);
extern "C" void FontGlyph_AdvanceTail_005DA3E4(void);
extern "C" void FUN_005D9C78(void);
extern "C" void FUN_005D9BBC(void);
extern "C" void FUN_005D9D08(std::uint32_t size, std::uint32_t mode,
                              std::uint32_t value, std::uint32_t state);
static void FontCommandRing_Append_005D8278(
    std::uint8_t* context, std::uint32_t value, std::uint32_t header) {
    std::uint32_t** const end_slot =
        reinterpret_cast<std::uint32_t**>(0x00d4d138u);
    std::uint32_t** const cursor_slot =
        reinterpret_cast<std::uint32_t**>(0x00d4d134u);
    std::uint32_t* const cursor = *cursor_slot;
    if (cursor < *end_slot) {
        cursor[0] = value;
        cursor[1] = header;
        *cursor_slot = cursor + 2;
    }
    (void)context;
}
extern "C" __attribute__((noinline)) void FUN_005D8278(
    std::uint32_t mode, std::uint32_t value, std::uint32_t size) {
    std::uint8_t* const context = *reinterpret_cast<std::uint8_t**>(
        0x00d4e4e4u);
    if (context == 0 || size == 0)
        return;
    if (mode != 6u && mode != 4u && mode != 5u && mode != 0x6010u)
        return;
    if (mode == 0x6010u)
        *reinterpret_cast<std::uint32_t*>(context) |= 0x80000u;
    {
        const std::uint32_t old_mode =
            *reinterpret_cast<std::uint32_t*>(context + 0x10);
        *reinterpret_cast<std::uint32_t*>(context + 0x10) = mode;
        context[0x18] = 1;
        *reinterpret_cast<std::uint32_t*>(context + 0x14) = old_mode;
        context[0x19] = 1;
    }
    FUN_005D9C78();
    if (mode == 6u) {
        FontCommandRing_Append_005D8278(context, 0x200u, 0x0002025eu);
        FontCommandRing_Append_005D8278(context, 1u, 0x000f025fu);
    }
    {
        const std::uint32_t mask =
            *reinterpret_cast<std::uint32_t*>(context + 0x670) & 7u;
        if (mask != 0)
            FontCommandRing_Append_005D8278(context, mask, 0x00010080u);
    }
    if (*reinterpret_cast<std::uint8_t*>(context + 0x71c) == 0)
        FUN_005D9D08(size, 2u, value, 0u);
    FontCommandRing_Append_005D8278(context, 1u, 0x00010253u);
    FontCommandRing_Append_005D8278(context, size, 0x000f0228u);
    FontCommandRing_Append_005D8278(context, value, 0x000f022au);
    FontCommandRing_Append_005D8278(context, 0u, 0x00010245u);
    FontCommandRing_Append_005D8278(context, 1u, 0x000f022eu);
    FontCommandRing_Append_005D8278(context, 1u, 0x00010245u);
    FontCommandRing_Append_005D8278(context, 1u, 0x000f0231u);
    FontCommandRing_Append_005D8278(context, 0u, 0x0008025eu);
    FontCommandRing_Append_005D8278(context, 0u, 0x0008025eu);
    FontCommandRing_Append_005D8278(context, 0u, 0x00010253u);
    FontCommandRing_Append_005D8278(context, 1u, 0x000f0111u);
    FontCommandRing_Append_005D8278(context, 0x7fff0000u, 0x000c02bau);
    if (mode == 0x6010u)
        FontCommandRing_Append_005D8278(context, 0x7fff0000u, 0x000c028au);
    *reinterpret_cast<std::uint8_t*>(context + 0x18) = 0;
    *reinterpret_cast<std::uint8_t*>(context + 0x19) = 0;
    if (*reinterpret_cast<std::uint32_t*>(context + 4) != 0)
        *reinterpret_cast<std::uint32_t*>(context + 4) = 0;
}
extern "C" int FontResource_ControlFallback_00BA8A6C(
    void* context, float* bounds, std::uint32_t opcode, void* cursor);
extern "C" void FontResource_DestroyTemporary_00BA898C(void* resource);
extern "C" float Libm_Floorf_0049A940(float value);
// Reconstructed control-table lookup, JP Rev 1: 0x005F8014.
extern "C" __attribute__((noinline)) int FontResource_LookupControlBytes_005F8014(
    void* const* wrapper_handle, int entry, std::uint8_t* output) {
    std::uint8_t* wrapper = static_cast<std::uint8_t*>(*wrapper_handle);
    const int section = *reinterpret_cast<const int*>(wrapper + 0x14);
    if (section == -1) return -5;
    std::uint8_t* sections = *reinterpret_cast<std::uint8_t**>(wrapper + 0x0c);
    std::uint8_t* payload = *reinterpret_cast<std::uint8_t**>(
        sections + static_cast<std::uint32_t>(section) * 0x10);
    const std::uint32_t count = *reinterpret_cast<const std::uint32_t*>(payload);
    if (entry >= static_cast<int>(count)) return -1;
    const std::uint8_t* selected = payload + (static_cast<std::uint32_t>(entry) + 1) * 4;
    output[0] = selected[0];
    output[1] = selected[1];
    output[2] = selected[2];
    output[3] = selected[3];
    return 0;
}
// Reconstructed named-text lookup, JP Rev 1: 0x002F432C.
extern "C" __attribute__((noinline)) const std::int16_t* ResourceText_FindNamedUtf16_002F432C(
    void* const* wrapper_handle, const char* name) {
    std::uint8_t* wrapper = static_cast<std::uint8_t*>(*wrapper_handle);
    const int offset = ResourceTable_FindOffset_00425F6C(wrapper, name);
    if (offset < 0) return 0;
    const int section = *reinterpret_cast<const int*>(wrapper + 0x14);
    if (section == -1) return 0;
    std::uint8_t* sections = *reinterpret_cast<std::uint8_t**>(wrapper + 0x0c);
    std::uint8_t* payload = *reinterpret_cast<std::uint8_t**>(
        sections + static_cast<std::uint32_t>(section) * 0x10);
    const std::uint32_t count = *reinterpret_cast<const std::uint32_t*>(payload);
    if (offset >= static_cast<int>(count)) return 0;
    const std::uint8_t* entry = payload +
        (static_cast<std::uint32_t>(offset) + 1) * 4;
    return reinterpret_cast<const std::int16_t*>(entry);
}
extern "C" __attribute__((noinline)) std::int16_t* ResourceText_ResolveLocalized_002A1454(
    void* state, std::uint32_t* length, const char* name, int direct,
    const std::int16_t* direct_text) {
    if (direct != 0) {
        *length = static_cast<std::uint32_t>(
            Utf16_CountUnits_005509C0(direct_text));
        return const_cast<std::int16_t*>(direct_text);
    }
    if (name == 0) return 0;
    std::uint8_t* bytes = static_cast<std::uint8_t*>(state);
    void** wrapper_handle = reinterpret_cast<void**>(bytes + 0x6a8);
    if (ByteString_FindChar_00262F94(const_cast<char*>(name), '+') == 0) {
        const std::int16_t* text = ResourceText_FindNamedUtf16_002F432C(
            wrapper_handle, name);
        if (text == 0) return 0;
        const std::uint32_t entry = ResourceWrapper_FirstField_00425F64(wrapper_handle);
        const std::uint32_t encoded = ResourceTable_EntryLength_0049CB04(
            wrapper_handle, static_cast<int>(entry));
        *length = encoded >> 1;
        return const_cast<std::int16_t*>(text);
    }
    struct ParameterStringObject {
        char* data;
        int limit;
    } input = {const_cast<char*>(name), -1},
      output = {0, 0x100};
    char scratch[0x100] = {};
    output.data = scratch;
    while (*length < 0x80u &&
           ParameterString_SplitByDelimiter_0029F780(
               &input, &output, '+') != 0) {
        const std::int16_t* text = ResourceText_FindNamedUtf16_002F432C(
            wrapper_handle, output.data);
        if (text == 0) return 0;
        const std::uint32_t entry = ResourceWrapper_FirstField_00425F64(wrapper_handle);
        const std::uint32_t encoded = ResourceTable_EntryLength_0049CB04(
            wrapper_handle, static_cast<int>(entry));
        const std::uint32_t units = encoded >> 1;
        Engine_CopyBytes_0044C108(
            bytes + 0x72e + *length * 2, text, units * 2);
        *length += units;
    }
    return reinterpret_cast<std::int16_t*>(bytes + 0x72e);
}
// Semantic/byte-match reconstruction, JP Rev 1: 0x005C37B4.
extern "C" __attribute__((noinline)) void FUN_005C37B4(
    void* resource, float* bounds, int begin, int count) {
    std::uint32_t cursor = static_cast<std::uint32_t>(begin);
    const float zero = 0.0f;
    bounds[0] = zero;
    bounds[2] = zero;
    bounds[1] = zero;
    bounds[3] = zero;
    *reinterpret_cast<float*>(static_cast<std::uint8_t*>(resource) + 0x2c) = zero;
    *reinterpret_cast<float*>(static_cast<std::uint8_t*>(resource) + 0x30) = zero;
    const int end = begin + count * 2;
    int remaining = count;
    do {
        float record[4];
        record[0] = zero;
        record[1] = zero;
        record[2] = zero;
        record[3] = zero;
        FUN_005CAD18(
            resource, record, &cursor, remaining);
        if (record[0] < bounds[0]) bounds[0] = record[0];
        if (record[1] < bounds[1]) bounds[1] = record[1];
        if (bounds[2] < record[2]) bounds[2] = record[2];
        if (bounds[3] < record[3]) bounds[3] = record[3];
        remaining = (end - static_cast<int>(cursor)) >> 1;
    } while (remaining > 0);
}
// Reconstructed wrapper, JP Rev 1: 0x005B4B38.
extern "C" __attribute__((noinline)) unsigned char* FUN_005B4B38(
    const void* packed_resource, float* bounds, int begin, int count) {
    static unsigned char workspace[104];
    Engine_BulkCopy_00425DF8(workspace, packed_resource, 100);
    FUN_005C37B4(
        workspace, bounds, begin, count);
    return workspace;
}
// Reconstructed wrapper, JP Rev 1: 0x005D6420.
extern "C" __attribute__((noinline)) float
FontResource_MeasureAlignmentBounds_005D6420(
    void* resource, std::uint32_t begin, std::uint32_t count) {
    std::uint8_t workspace[0x90];
    Engine_BulkCopy_00425DF8(workspace, resource, 100);
    float* bounds = reinterpret_cast<float*>(workspace + 0x68);
    bounds[0] = 0.0f;
    bounds[1] = 0.0f;
    bounds[2] = 0.0f;
    bounds[3] = 0.0f;
    FUN_005CAD18(
        workspace, bounds, &begin, static_cast<int>(count));
    return bounds[2] - bounds[0];
}
// Reconstructed adapter body, JP Rev 1: 0x005CB104.
extern "C" __attribute__((noinline)) unsigned char* FontResource_ApplyTextRecord_005CB104(
    void* resource, std::uint32_t begin, std::uint32_t end) {
    static std::uint8_t workspace[0x90];
    Engine_BulkCopy_00425DF8(workspace, resource, 100);
    FontResource_ApplyPackedText_005CF240(workspace, begin, end);
    std::uint8_t* live = static_cast<std::uint8_t*>(resource);
    *reinterpret_cast<std::uint32_t*>(live + 0x2c) =
        *reinterpret_cast<std::uint32_t*>(workspace + 0x2c);
    *reinterpret_cast<std::uint32_t*>(live + 0x30) =
        *reinterpret_cast<std::uint32_t*>(workspace + 0x30);
    return workspace;
}
// Reconstructed selector helper, JP Rev 1: 0x005CA9C0.
extern "C" __attribute__((noinline)) void FUN_005CA9C0(
    std::uint32_t* result, void* resource) {
    std::uint32_t first = 0;
    std::uint32_t second = 0;
    std::uint8_t* object = static_cast<std::uint8_t*>(resource);
    std::uint32_t* vtable = *reinterpret_cast<std::uint32_t**>(object);
    int (*selector)(void*) = reinterpret_cast<int (*)(void*)>(vtable[0x48 / 4]);
    if (selector(resource) == 1) {
        const std::uint8_t* shared = reinterpret_cast<const std::uint8_t*>(0x00CB3840);
        first = *reinterpret_cast<const std::uint32_t*>(shared + 0x18);
        second = *reinterpret_cast<const std::uint32_t*>(shared + 0x1c);
    }
    result[0] = 0;
    result[1] = first;
    result[2] = second;
}
// Reconstructed adapter, JP Rev 1: 0x005D6184.
extern "C" __attribute__((noinline)) float
FontResource_GetVerticalAdvance_005D6184(void* resource) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(resource);
    std::uint8_t* nested = *reinterpret_cast<std::uint8_t**>(bytes + 0x3c);
    std::uint32_t* vtable = *reinterpret_cast<std::uint32_t**>(nested);
    int (*advance)(void*) = reinterpret_cast<int (*)(void*)>(vtable[0x10 / 4]);
    const int units = advance(nested);
    const float scale = *reinterpret_cast<float*>(bytes + 0x28);
    return static_cast<float>(units) * scale;
}
// Reconstructed glyph application, JP Rev 1: 0x005D24A0.
extern "C" __attribute__((noinline)) float FontResource_EmitGlyphAndAdvance_005D24A0(
    void* resource, std::uint32_t codepoint) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(resource);
    std::uint8_t record[0x1c];
    FontRecord_ClearTransientFlag_005D5520(record);
    void* atlas = *reinterpret_cast<void**>(bytes + 0x3c);
    std::uintptr_t* vtable = *reinterpret_cast<std::uintptr_t**>(atlas);
    void (*lookup)(void*, void*, std::uint32_t) = reinterpret_cast<void (*)(void*, void*, std::uint32_t)>(
        vtable[0x40 / sizeof(std::uintptr_t)]);
    lookup(atlas, record, codepoint);
    const float scale = *reinterpret_cast<float*>(bytes + 0x24);
    const float cursor = *reinterpret_cast<float*>(bytes + 0x2c);
    const std::int8_t left = static_cast<std::int8_t>(record[4]);
    const std::int8_t width = static_cast<std::int8_t>(record[6]);
    float advance;
    float position;
    if (bytes[0x48] == 0) {
        advance = static_cast<float>(width) * scale;
        position = cursor + static_cast<float>(left) * scale;
    } else {
        advance = *reinterpret_cast<float*>(bytes + 0x38);
        position = cursor +
            (advance - static_cast<float>(width) * scale) * 0.5f +
            static_cast<float>(left) * scale;
    }
    FUN_005D5230(resource, record, position);
    *reinterpret_cast<float*>(bytes + 0x2c) = cursor + advance;
    return advance;
}
extern "C" __attribute__((noinline)) void FUN_005D5230(
    void* resource, void* glyph_record, float horizontal_position) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(resource);
    std::uint8_t* glyph = static_cast<std::uint8_t*>(glyph_record);
    std::uint8_t* queue = *reinterpret_cast<std::uint8_t**>(bytes + 0x44);
    if (queue == 0) {
        const std::uint8_t width = glyph[5];
        const std::uint8_t height = glyph[7];
        const std::uint16_t sheet_width =
            *reinterpret_cast<const std::uint16_t*>(glyph + 8);
        const std::uint16_t sheet_height =
            *reinterpret_cast<const std::uint16_t*>(glyph + 10);
        const std::uint16_t left =
            *reinterpret_cast<const std::uint16_t*>(glyph + 12);
        const std::uint16_t top =
            *reinterpret_cast<const std::uint16_t*>(glyph + 14);
        const float scale_x = *reinterpret_cast<const float*>(bytes + 0x24);
        const float scale_y = *reinterpret_cast<const float*>(bytes + 0x28);
        const float baseline = *reinterpret_cast<const float*>(bytes + 0x30);
        const float glyph_x = horizontal_position +
            static_cast<float>(width) * scale_x;
        const float glyph_y = baseline -
            static_cast<float>(height) * scale_y;
        const float uv_left = static_cast<float>(left) /
            static_cast<float>(sheet_width);
        const float uv_top = static_cast<float>(sheet_height - top) /
            static_cast<float>(sheet_height);
        const float uv_right = static_cast<float>(left + width) /
            static_cast<float>(sheet_width);
        const float uv_bottom = static_cast<float>(sheet_height - top - height) /
            static_cast<float>(sheet_height);
        std::uint8_t* output =
            *reinterpret_cast<std::uint8_t**>(bytes + 0x40) + 8;
        bool emit = true;
        *reinterpret_cast<float*>(output + 0x00) = glyph_x;
        *reinterpret_cast<float*>(output + 0x04) = baseline;
        *reinterpret_cast<float*>(output + 0x14) = horizontal_position;
        *reinterpret_cast<float*>(output + 0x18) = baseline;
        *reinterpret_cast<float*>(output + 0x28) = horizontal_position;
        *reinterpret_cast<float*>(output + 0x2c) = glyph_y;
        *reinterpret_cast<float*>(output + 0x3c) = glyph_x;
        *reinterpret_cast<float*>(output + 0x40) = glyph_y;
        *reinterpret_cast<float*>(output + 0x0c) = uv_left;
        *reinterpret_cast<float*>(output + 0x10) = uv_top;
        *reinterpret_cast<float*>(output + 0x20) = uv_right;
        *reinterpret_cast<float*>(output + 0x24) = uv_bottom;
        *reinterpret_cast<float*>(output + 0x34) = uv_right;
        *reinterpret_cast<float*>(output + 0x38) = uv_bottom;
        *reinterpret_cast<float*>(output + 0x48) = uv_left;
        *reinterpret_cast<float*>(output + 0x4c) = uv_top;
        *reinterpret_cast<float*>(output + 0x08) =
            *reinterpret_cast<const float*>(bytes + 0x08);
        *reinterpret_cast<float*>(output + 0x1c) =
            *reinterpret_cast<const float*>(bytes + 0x0c);
        *reinterpret_cast<float*>(output + 0x30) =
            *reinterpret_cast<const float*>(bytes + 0x10);
        *reinterpret_cast<float*>(output + 0x44) =
            *reinterpret_cast<const float*>(bytes + 0x14);
        {
            std::uint32_t pending = 0;
            std::uint8_t* record =
                *reinterpret_cast<std::uint8_t**>(glyph + 0x14);
            if (record == 0) {
                std::uint8_t* batch =
                    *reinterpret_cast<std::uint8_t**>(bytes + 0x40);
                const std::uint32_t previous =
                    *reinterpret_cast<const std::uint32_t*>(batch + 4);
                const std::uint32_t current =
                    *reinterpret_cast<const std::uint32_t*>(glyph);
                *reinterpret_cast<std::uint32_t*>(batch + 0xdc) = current;
                FontText_UpdatePendingResource_0051DBA0(0x00000de1u, previous);
                emit = previous != current;
            } else {
                pending = *reinterpret_cast<std::uint32_t*>(record);
                if (pending == 0) {
                    FontText_PendingValueUpdate_0051E934(1u, &pending);
                    *reinterpret_cast<std::uint32_t*>(record) = pending;
                    FontText_UpdatePendingResource_0051DBA0(0x00000de1u, pending);
                } else if (glyph[0x12] == 0) {
                    FontText_UpdatePendingResource_0051DBA0(0x00000de1u, 0);
                    emit = false;
                } else {
                    FontText_UpdatePendingResource_0051DBA0(0x00000de1u, 0);
                }
            }
        }
        if (emit) {
            std::uint8_t* owner =
                *reinterpret_cast<std::uint8_t**>(bytes + 0x3c);
            std::uint8_t* vtable =
                *reinterpret_cast<std::uint8_t**>(owner);
            typedef std::uint32_t (*FontVirtualCall)(void*);
            const std::uint32_t texture_state =
                reinterpret_cast<FontVirtualCall>(vtable + 0x60)(owner);
            const std::uint32_t texture_handle =
                reinterpret_cast<FontVirtualCall>(vtable + 0x5c)(owner);
            FUN_005D7FE4(*reinterpret_cast<const std::uint16_t*>(glyph + 8),
                         *reinterpret_cast<const std::uint16_t*>(glyph + 10),
                         *reinterpret_cast<const std::uint16_t*>(glyph + 0x10),
                         *reinterpret_cast<const std::uint32_t*>(glyph),
                         texture_handle, texture_state);
        }
        {
            std::uint8_t* batch =
                *reinterpret_cast<std::uint8_t**>(bytes + 0x40);
            if (*reinterpret_cast<const float*>(batch + 0xe0) !=
                *reinterpret_cast<const float*>(bytes + 0x34))
                FontGlyph_AdvanceTail_005DA3E4();
        }
        FUN_005D8278(6u, 0u, 4u);
        return;
    }
    const std::uint32_t capacity =
        *reinterpret_cast<const std::uint32_t*>(queue);
    std::uint16_t* count = reinterpret_cast<std::uint16_t*>(queue + 4);
    if (*count >= capacity) return;
    const std::uint8_t width = glyph[5];
    const std::uint8_t height = glyph[7];
    const std::uint16_t sheet_width =
        *reinterpret_cast<const std::uint16_t*>(glyph + 8);
    const std::uint16_t sheet_height =
        *reinterpret_cast<const std::uint16_t*>(glyph + 10);
    const std::uint16_t left =
        *reinterpret_cast<const std::uint16_t*>(glyph + 12);
    const std::uint16_t top =
        *reinterpret_cast<const std::uint16_t*>(glyph + 14);
    std::uint8_t* record = queue + 0x20 + static_cast<std::uint32_t>(*count) * 0x2c;
    ++*count;
    const float scale_x = *reinterpret_cast<const float*>(bytes + 0x24);
    const float scale_y = *reinterpret_cast<const float*>(bytes + 0x28);
    float* output = reinterpret_cast<float*>(record);
    output[0] = static_cast<float>(width) * scale_x;
    output[1] = static_cast<float>(-static_cast<int>(height)) * scale_y;
    output[2] = horizontal_position;
    output[3] = *reinterpret_cast<const float*>(bytes + 0x30);
    reinterpret_cast<std::uint32_t*>(record)[4] =
        *reinterpret_cast<const std::uint32_t*>(bytes + 0x18);
    reinterpret_cast<std::uint32_t*>(record)[5] =
        *reinterpret_cast<const std::uint32_t*>(bytes + 0x1c);
    output[6] = static_cast<float>(left) / static_cast<float>(sheet_width);
    output[7] = static_cast<float>(
                    static_cast<int>(sheet_height) - static_cast<int>(top)) /
                static_cast<float>(sheet_height);
    output[8] =
        static_cast<float>(static_cast<std::uint32_t>(left) + width) /
        static_cast<float>(sheet_width);
    output[9] = static_cast<float>(
                    static_cast<int>(sheet_height) -
                    (static_cast<int>(top) + height)) /
                static_cast<float>(sheet_height);
    reinterpret_cast<std::uint32_t*>(record)[10] =
        *reinterpret_cast<const std::uint32_t*>(glyph + 0x14);
}
// Reconstructed cursor alignment, JP Rev 1: 0x005D2F38.
extern "C" __attribute__((noinline)) float FontResource_ApplyCursorAlignment_005D2F38(
    void* resource, float* origin, float* extent, std::uint32_t begin,
    std::uint32_t count) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(resource);
    const std::uint32_t flags =
        *reinterpret_cast<const std::uint32_t*>(bytes + 0x5c);
    float width = 0.0f;
    float height = 0.0f;
    const std::uint32_t active_alignment = flags & 0x333u;
    if (active_alignment != 0 && active_alignment != 0x300u) {
        std::uint8_t workspace[104];
        float bounds[4] = {};
        Engine_BulkCopy_00425DF8(workspace, resource, 100);
        FUN_005C37B4(
            workspace, bounds, static_cast<int>(begin),
            static_cast<int>(count));
        width = bounds[0] + bounds[2];
        height = bounds[1] + bounds[3];
    }
    switch (flags & 0x30u) {
    case 0x10:
        *origin -= Float_ForceIntConversion_0049A8B0(width * 0.5f);
        break;
    case 0x20:
        *origin -= width;
        break;
    }
    switch (flags & 0x300u) {
    case 0x100:
        *extent -= Float_ForceIntConversion_0049A8B0(height * 0.5f);
        break;
    case 0x200:
        *extent -= height;
        break;
    }
    const std::uint32_t low_mode = flags & 3u;
    const float measured_width =
        (low_mode == 1u || low_mode == 2u)
            ? FontResource_MeasureAlignmentBounds_005D6420(
                  resource, begin, count)
            : 0.0f;
    switch (low_mode) {
    case 1:
        *reinterpret_cast<float*>(bytes + 0x2c) =
            *origin +
            (Float_ForceIntConversion_0049A8B0(width * 0.5f) -
             Float_ForceIntConversion_0049A8B0(measured_width * 0.5f));
        break;
    case 2:
        *reinterpret_cast<float*>(bytes + 0x2c) =
            *origin + (width - measured_width);
        break;
    default:
        *reinterpret_cast<float*>(bytes + 0x2c) = *origin;
        break;
    }
    *reinterpret_cast<float*>(bytes + 0x30) =
        (flags & 0x300u) == 0x300u
            ? *extent
            : *extent + FontResource_GetVerticalAdvance_005D6184(resource);
    return width;
}
// Reconstructed buffer-view helper, JP Rev 1: 0x005BF1C4.
extern "C" __attribute__((noinline)) void FontResource_SelectTextBuffer_005BF1C4(void* resource) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(resource);
    const std::uint8_t state = bytes[0x20];
    std::uint32_t* table = reinterpret_cast<std::uint32_t*>(bytes + 0x18);
    std::uint32_t* view = reinterpret_cast<std::uint32_t*>(bytes);
    view[0x0c / 4] = table[0];
    view[0x08 / 4] = table[state == 1 ? 1 : 0];
    view[0x10 / 4] = table[state == 2 ? 2 : 0];
    view[0x14 / 4] = table[state != 0 ? 3 : 0];
}
// Reconstructed batch reset, JP Rev 1: 0x005C7888.
extern "C" __attribute__((noinline)) void FontText_ResetBatchState_005C7888(void* batch) {
    std::uint8_t* nested = *reinterpret_cast<std::uint8_t**>(
        static_cast<std::uint8_t*>(batch) + 0x44);
    *reinterpret_cast<std::uint16_t*>(nested + 0x04) = 0;
    nested[0x08] = 0;
}
// Reconstructed identity helper, JP Rev 1: 0x005C78A4.
extern "C" __attribute__((noinline)) void* FontText_BatchIdentity_005C78A4(void* batch) {
    return batch;
}
// Reconstructed wrapper, JP Rev 1: 0x00C00514.
extern "C" __attribute__((noinline)) float
FontResource_MeasurePackedText_00C00514(
    void* resource, int begin, int count) {
    std::uint8_t workspace[0x90];
    Engine_BulkCopy_00425DF8(workspace, resource, 100);
    float* bounds = reinterpret_cast<float*>(workspace + 0x68);
    bounds[0] = 0.0f;
    bounds[1] = 0.0f;
    bounds[2] = 0.0f;
    bounds[3] = 0.0f;
    FUN_005C37B4(
        workspace, bounds, begin, count);
    return bounds[2] - bounds[0];
}
// Reconstructed wrapper, JP Rev 1: 0x00C00580.
extern "C" __attribute__((noinline)) float
FontResource_MeasurePackedHeight_00C00580(
    void* resource, int begin, int count) {
    std::uint8_t workspace[0x90];
    Engine_BulkCopy_00425DF8(workspace, resource, 100);
    float* bounds = reinterpret_cast<float*>(workspace + 0x68);
    bounds[0] = 0.0f;
    bounds[1] = 0.0f;
    bounds[2] = 0.0f;
    bounds[3] = 0.0f;
    FUN_005C37B4(
        workspace, bounds, begin, count);
    return bounds[3] - bounds[1];
}
// Reconstructed scaled line-height query, JP Rev 1: 0x00B45D20.
extern "C" __attribute__((noinline)) float FontResource_GetLineHeight_00B45D20(void* resource) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(resource);
    void* font = *reinterpret_cast<void**>(bytes + 0x3c);
    std::uintptr_t* vtable = *reinterpret_cast<std::uintptr_t**>(font);
    int (*query)(void*) = reinterpret_cast<int (*)(void*)>(
        vtable[0x0c / sizeof(std::uintptr_t)]);
    return static_cast<float>(query(font)) *
           *reinterpret_cast<const float*>(bytes + 0x28);
}
extern "C" __attribute__((noinline)) float FontResource_GetHorizontalMetric_00B45CF4(void* resource) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(resource);
    void* font = *reinterpret_cast<void**>(bytes + 0x3c);
    std::uintptr_t* vtable = *reinterpret_cast<std::uintptr_t**>(font);
    int (*query)(void*) = reinterpret_cast<int (*)(void*)>(
        vtable[0x08 / sizeof(std::uintptr_t)]);
    return static_cast<float>(query(font)) *
           *reinterpret_cast<const float*>(bytes + 0x24);
}
extern "C" __attribute__((noinline)) float FontResource_GetRubyVerticalMetric_00B45D4C(void* resource) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(resource);
    void* font = *reinterpret_cast<void**>(bytes + 0x3c);
    std::uintptr_t* vtable = *reinterpret_cast<std::uintptr_t**>(font);
    int (*query)(void*) = reinterpret_cast<int (*)(void*)>(
        vtable[0x14 / sizeof(std::uintptr_t)]);
    return static_cast<float>(query(font)) *
           *reinterpret_cast<const float*>(bytes + 0x28);
}
// Reconstructed codepoint-to-glyph mapper, JP Rev 1: 0x00B45E2C.
extern "C" __attribute__((noinline)) std::uint32_t FontFace_MapCodepoint_00B45E2C(
    void* face, std::uint32_t codepoint) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(face);
    if (*reinterpret_cast<std::uint16_t*>(bytes + 0x14) == codepoint) {
        return *reinterpret_cast<std::uint16_t*>(bytes + 0x16);
    }
    *reinterpret_cast<std::uint16_t*>(bytes + 0x14) =
        static_cast<std::uint16_t>(codepoint);
    std::uint32_t glyph = 0xffff;
    std::uint8_t* info = *reinterpret_cast<std::uint8_t**>(bytes + 8);
    for (std::uint8_t* map = *reinterpret_cast<std::uint8_t**>(info + 0x10);
         map != 0;
         map = *reinterpret_cast<std::uint8_t**>(map + 8)) {
        const std::uint16_t first =
            *reinterpret_cast<const std::uint16_t*>(map);
        const std::uint16_t last =
            *reinterpret_cast<const std::uint16_t*>(map + 2);
        if (codepoint < first || codepoint > last) continue;
        const std::uint16_t kind =
            *reinterpret_cast<const std::uint16_t*>(map + 4);
        if (kind == 0) {
            glyph = *reinterpret_cast<const std::uint16_t*>(map + 0x0c) +
                    codepoint - first;
        } else if (kind == 1) {
            glyph = *reinterpret_cast<const std::uint16_t*>(
                map + 0x0c + (codepoint - first) * 2);
        } else if (kind == 2) {
            const std::uint16_t count =
                *reinterpret_cast<const std::uint16_t*>(map + 0x0c);
            const std::uint16_t* low = reinterpret_cast<const std::uint16_t*>(map + 0x0e);
            const std::uint16_t* high = low + (count - 1) * 2;
            while (low <= high) {
                const std::uint16_t* middle = low + ((high - low) / 4) * 2;
                if (middle[0] < codepoint) {
                    low = middle + 2;
                } else if (middle[0] > codepoint) {
                    high = middle - 2;
                } else {
                    glyph = middle[1];
                    break;
                }
            }
        }
        break;
    }
    *reinterpret_cast<std::uint16_t*>(bytes + 0x16) =
        static_cast<std::uint16_t>(glyph);
    return glyph;
}
// Reconstructed glyph-record filler, JP Rev 1: 0x00B45F90.
extern "C" __attribute__((noinline)) void FontFace_FillGlyphRecordByIndex_00B45F90(
    void* face, void* output, std::uint32_t glyph) {
    std::uint8_t* face_bytes = static_cast<std::uint8_t*>(face);
    std::uint8_t* out = static_cast<std::uint8_t*>(output);
    std::uint8_t* info = *reinterpret_cast<std::uint8_t**>(face_bytes + 8);
    std::uint8_t* sheet = *reinterpret_cast<std::uint8_t**>(info + 8);
    const std::uint32_t columns =
        *reinterpret_cast<const std::uint16_t*>(sheet + 0x0c);
    const std::uint32_t rows =
        *reinterpret_cast<const std::uint16_t*>(sheet + 0x0e);
    const std::uint32_t cells_per_sheet = columns * rows;
    const std::uint32_t sheet_index = glyph / cells_per_sheet;
    const std::uint32_t cell = glyph % cells_per_sheet;
    *reinterpret_cast<void**>(out) =
        *reinterpret_cast<std::uint8_t**>(sheet + 0x14) +
        *reinterpret_cast<const std::uint32_t*>(sheet + 4) * sheet_index;
    const std::uint8_t* width = info + 4;
    for (std::uint8_t* range = *reinterpret_cast<std::uint8_t**>(info + 0x0c);
         range != 0;
         range = *reinterpret_cast<std::uint8_t**>(range + 4)) {
        const std::uint16_t first =
            *reinterpret_cast<const std::uint16_t*>(range);
        const std::uint16_t last =
            *reinterpret_cast<const std::uint16_t*>(range + 2);
        if (glyph >= first && glyph <= last) {
            width = range + 8 + (glyph - first) * 3;
            break;
        }
    }
    *reinterpret_cast<std::uint16_t*>(out + 4) =
        *reinterpret_cast<const std::uint16_t*>(width);
    out[6] = width[2];
    void* sheet_record = *reinterpret_cast<void**>(face_bytes + 0x0c);
    if (sheet_record != 0) {
        sheet_record = static_cast<std::uint8_t*>(sheet_record) +
                       sheet_index * 0x14;
    }
    *reinterpret_cast<void**>(out + 0x14) = sheet_record;
    const std::uint32_t row = cell / columns;
    const std::uint32_t column = cell % columns;
    out[7] = sheet[1];
    *reinterpret_cast<std::uint16_t*>(out + 8) =
        *reinterpret_cast<const std::uint16_t*>(sheet + 0x10);
    *reinterpret_cast<std::uint16_t*>(out + 0x0a) =
        *reinterpret_cast<const std::uint16_t*>(sheet + 0x12);
    *reinterpret_cast<std::uint16_t*>(out + 0x0c) =
        static_cast<std::uint16_t>((sheet[0] + 1) * column + 1);
    *reinterpret_cast<std::uint16_t*>(out + 0x0e) =
        static_cast<std::uint16_t>((sheet[1] + 1) * row + 1);
    *reinterpret_cast<std::uint16_t*>(out + 0x10) =
        *reinterpret_cast<const std::uint16_t*>(sheet + 0x0a);
}
// Reconstructed mapped glyph-record callback, JP Rev 1: 0x00B45F58.
extern "C" __attribute__((noinline)) void FontFace_FillGlyphRecord_00B45F58(
    void* face, void* output, std::uint32_t codepoint) {
    std::uint32_t glyph = FontFace_MapCodepoint_00B45E2C(face, codepoint);
    if (glyph == 0xffff) {
        std::uint8_t* info = *reinterpret_cast<std::uint8_t**>(
            static_cast<std::uint8_t*>(face) + 8);
        glyph = *reinterpret_cast<const std::uint16_t*>(info + 2);
    }
    FontFace_FillGlyphRecordByIndex_00B45F90(face, output, glyph);
}
struct FontLayoutPackedCursor {
    std::uint32_t position;
    std::uintptr_t decoder;
    std::uintptr_t descriptor;
};
static std::uint32_t FontLayout_DecodePacked(FontLayoutPackedCursor& cursor) {
    std::uint8_t* receiver = reinterpret_cast<std::uint8_t*>(&cursor) +
                     (cursor.descriptor >> 1);
    std::uintptr_t target = cursor.decoder;
    if ((cursor.descriptor & 1u) != 0) {
        std::uintptr_t* table = *reinterpret_cast<std::uintptr_t**>(receiver);
        target = table[cursor.decoder / sizeof(std::uintptr_t)];
    }
    return reinterpret_cast<std::uint32_t (*)(void*)>(target)(receiver);
}
static void FontLayout_MergeBounds(float* bounds, float left, float top,
                                   float right, float bottom) {
    if (right - left < 0.0f) {
        left = right;
    }
    if (bottom - top < 0.0f) {
        top = bottom;
    }
    if (right - bounds[0] < 0.0f) bounds[2] = bounds[0];
    else bounds[2] = right;
    if (left - bounds[0] < 0.0f) bounds[0] = left;
    if (bottom - bounds[1] < 0.0f) bounds[3] = bounds[1];
    else bounds[3] = bottom;
    if (top - bounds[1] < 0.0f) bounds[1] = top;
    }
extern "C" __attribute__((noinline)) std::uint32_t FUN_005CAD18(
    void* resource, float* record_bounds, std::uint32_t* cursor, int count) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(resource);
    const std::uint32_t start = *cursor;
    const std::uint32_t limit = start + static_cast<std::uint32_t>(count * 2);
    record_bounds[0] = 0.0f;
    record_bounds[1] = 0.0f;
    record_bounds[2] = 0.0f;
    record_bounds[3] = 0.0f;
    FontLayoutPackedCursor packed = {};
    FUN_005CA9C0(reinterpret_cast<std::uint32_t*>(&packed),
                 *reinterpret_cast<void**>(bytes + 0x3c));
    packed.position = start;
    {
        int metric = 0;
        void* face = *reinterpret_cast<void**>(bytes + 0x3c);
        if (face != 0) {
            std::uintptr_t* table = *reinterpret_cast<std::uintptr_t**>(face);
            typedef int (*Metric)(void*);
            Metric get_metric = reinterpret_cast<Metric>(
                table[0x24 / sizeof(std::uintptr_t)]);
            metric = get_metric(face);
        }
        const float baseline = *reinterpret_cast<float*>(bytes + 0x54);
        const float delta = static_cast<float>(metric) *
                            *reinterpret_cast<float*>(bytes + 0x28);
        record_bounds[1] = delta < 0.0f ? delta : 0.0f;
        record_bounds[3] = delta > 0.0f ? delta : 0.0f;
        (void)baseline;
    }
    const bool has_threshold =
        *reinterpret_cast<const std::uint32_t*>(bytes + 0x4c) < 0x7f7fffffu;
    bool alternate = false;
    bool retry_seen = false;
    std::uint32_t threshold_origin = 0;
    bool pending_newline = false;
    for (;;) {
        std::uint32_t value;
        if (pending_newline) {
            value = 10u;
            pending_newline = false;
        } else {
            value = FontLayout_DecodePacked(packed);
        }
        *cursor = packed.position;
        if (*cursor > limit)
            return retry_seen ? 1u : 0u;
        if (value < 0x20u) {
            const std::uint32_t saved_position = *cursor;
            struct CursorState {
                void* resource;
                std::uint32_t cursor;
                float x;
                float y;
                std::uint32_t alternate;
            } state;
            if (has_threshold && value != 10u && threshold_origin != 0u) {
                std::uint8_t copied_resource[100];
                float geometry[4] = {0.0f, 0.0f, 0.0f, 0.0f};
                CursorState geometry_state;
                Engine_BulkCopy_00425DF8(copied_resource, resource, 100);
                geometry_state.resource = copied_resource;
                geometry_state.cursor = saved_position;
                geometry_state.x = *reinterpret_cast<float*>(bytes + 0x2c);
                geometry_state.y = *reinterpret_cast<float*>(bytes + 0x30);
                geometry_state.alternate = alternate ? 1u : 0u;
                void* controls = *reinterpret_cast<void**>(bytes + 0x60);
                std::uintptr_t* table =
                    *reinterpret_cast<std::uintptr_t**>(controls);
                typedef void (*Geometry)(void*, float*, std::uint32_t,
                                         CursorState*);
                Geometry geometry_callback = reinterpret_cast<Geometry>(
                    table[0x0c / sizeof(std::uintptr_t)]);
                geometry_callback(controls, geometry, value,
                                  &geometry_state);
                if (geometry[2] - geometry[0] > 0.0f &&
                    *reinterpret_cast<float*>(copied_resource + 0x2c) -
                        *reinterpret_cast<float*>(bytes + 0x2c) >
                        *reinterpret_cast<float*>(bytes + 0x4c)) {
                    retry_seen = true;
                    value = 10u;
                    packed.position = threshold_origin;
                    *cursor = threshold_origin;
                }
            }
            state.resource = resource;
            state.cursor = *cursor;
            state.x = *reinterpret_cast<float*>(bytes + 0x2c);
            state.y = *reinterpret_cast<float*>(bytes + 0x30);
            state.alternate = alternate ? 1u : 0u;
            *reinterpret_cast<float*>(bytes + 0x2c) = 0.0f;
            void* controls = *reinterpret_cast<void**>(bytes + 0x60);
            std::uintptr_t* table =
                *reinterpret_cast<std::uintptr_t**>(controls);
            typedef int (*ApplyControl)(void*, std::uint32_t, CursorState*);
            ApplyControl apply = reinterpret_cast<ApplyControl>(
                table[0x08 / sizeof(std::uintptr_t)]);
            const int result = apply(controls, value, &state);
            *cursor = state.cursor;
            packed.position = *cursor;
            {
                float geometry[4] = {0.0f, 0.0f, 0.0f, 0.0f};
                typedef void (*Geometry)(void*, float*, std::uint32_t,
                                         CursorState*);
                Geometry geometry_callback = reinterpret_cast<Geometry>(
                    table[0x0c / sizeof(std::uintptr_t)]);
                geometry_callback(controls, geometry, value, &state);
                FontLayout_MergeBounds(record_bounds, geometry[0], geometry[1],
                                       geometry[2], geometry[3]);
            }
            if (result == 4) {
                *cursor += static_cast<std::uint32_t>(count * 2);
                return 0u;
            }
            if (result == 3)
                return retry_seen ? 1u : 0u;
            if (result == 1) {
                alternate = false;
                if (has_threshold)
                    threshold_origin = *cursor;
            } else if (result == 2) {
                alternate = true;
            }
            if (has_threshold)
                threshold_origin = *cursor;
            continue;
        }
        float advance = alternate ?
            *reinterpret_cast<float*>(bytes + 0x50) : 0.0f;
        if (bytes[0x48] == 0) {
            void* face = *reinterpret_cast<void**>(bytes + 0x3c);
            std::uintptr_t* table = *reinterpret_cast<std::uintptr_t**>(face);
            typedef int (*Metric)(void*, std::uint32_t);
            Metric get_metric = reinterpret_cast<Metric>(
                table[0x38 / sizeof(std::uintptr_t)]);
            advance += static_cast<float>(get_metric(face, value)) *
                       *reinterpret_cast<float*>(bytes + 0x24);
        } else {
            advance += *reinterpret_cast<float*>(bytes + 0x38);
        }
        if (alternate)
            *reinterpret_cast<float*>(bytes + 0x2c) +=
                *reinterpret_cast<float*>(bytes + 0x50);
        if (has_threshold && threshold_origin != 0u &&
            advance > *reinterpret_cast<const float*>(bytes + 0x4c)) {
            retry_seen = true;
            packed.position = threshold_origin;
            pending_newline = true;
            continue;
        }
        if (record_bounds[0] > advance)
            record_bounds[0] = advance;
        if (record_bounds[2] < advance)
            record_bounds[2] = advance;
        packed.position = *cursor;
    }
}
extern "C" __attribute__((noinline)) void FontResource_ApplyPackedText_005CF240(
    void* resource, std::uint32_t begin, std::uint32_t count) {
    struct CursorState {
        void* resource;
        std::uint32_t cursor;
        float aligned_x;
        float aligned_y;
        std::uint32_t alternate;
    };
    struct Bounds {
        float left;
        float top;
        float right;
        float bottom;
    };
    std::uint8_t* bytes = static_cast<std::uint8_t*>(resource);
    const float original_x = *reinterpret_cast<float*>(bytes + 0x2c);
    const float original_y = *reinterpret_cast<float*>(bytes + 0x30);
    float aligned_x = original_x;
    float aligned_y = original_y;
    float alignment_width = FontResource_ApplyCursorAlignment_005D2F38(
        resource, &aligned_x, &aligned_y, begin, count);
    const float vertical_restore =
        original_y - *reinterpret_cast<float*>(bytes + 0x30);
    const bool has_threshold =
        *reinterpret_cast<const std::uint32_t*>(bytes + 0x4c) < 0x7f7fffffu;
    FontLayoutPackedCursor cursor = {};
    FUN_005CA9C0(reinterpret_cast<std::uint32_t*>(&cursor),
                 *reinterpret_cast<void**>(bytes + 0x3c));
    cursor.position = begin;
    bool alternate = false;
    std::uint32_t retry_origin = begin;
    std::uint32_t threshold_origin = begin;
    std::uint32_t codepoint = FontLayout_DecodePacked(cursor);
    while ((cursor.position - begin) / 2 <= count) {
        if (codepoint < 0x20) {
            const std::uint32_t saved_position = cursor.position;
            if (has_threshold && codepoint != 10 &&
                threshold_origin != retry_origin) {
                std::uint8_t copied_resource[100];
                Bounds geometry = {};
                CursorState geometry_cursor = {
                    resource, cursor.position, aligned_x, aligned_y,
                    alternate ? 0u : 1u,
                };
                Engine_BulkCopy_00425DF8(copied_resource, resource, 100);
                void* controls = *reinterpret_cast<void**>(bytes + 0x60);
                std::uintptr_t* geometry_vtable = *reinterpret_cast<std::uintptr_t**>(controls);
                void (*geometry_callback)(
                    void*, Bounds*, std::uint32_t, CursorState*) = reinterpret_cast<void (*)(
                    void*, Bounds*, std::uint32_t, CursorState*)>(
                    geometry_vtable[0x0c / sizeof(std::uintptr_t)]);
                geometry_cursor.resource = copied_resource;
                geometry_callback(controls, &geometry, codepoint,
                                  &geometry_cursor);
                if (geometry.right - geometry.left > 0.0f &&
                    *reinterpret_cast<float*>(copied_resource + 0x2c) -
                            aligned_x >
                        *reinterpret_cast<const float*>(bytes + 0x4c)) {
                    codepoint = 10;
                    cursor.position = threshold_origin;
                    continue;
                }
            }
            void* controls = *reinterpret_cast<void**>(bytes + 0x60);
            std::uintptr_t* vtable = *reinterpret_cast<std::uintptr_t**>(controls);
            int (*apply)(
                void*, std::uint32_t, CursorState*) = reinterpret_cast<int (*)(
                void*, std::uint32_t, CursorState*)>(
                vtable[0x08 / sizeof(std::uintptr_t)]);
            CursorState state = {
                resource,
                cursor.position,
                aligned_x,
                aligned_y,
                alternate ? 1u : 0u,
            };
            const int result = apply(controls, codepoint, &state);
            cursor.position = state.cursor;
            if (result == 4) break;
            if (result == 3) {
                const std::uint32_t mode =
                    *reinterpret_cast<const std::uint32_t*>(bytes + 0x5c) & 3u;
                if (mode == 1 || mode == 2) {
                    std::uint8_t copied_resource[100];
                    Bounds bounds = {};
                    std::uint32_t measurement_cursor = saved_position;
                    Engine_BulkCopy_00425DF8(copied_resource, resource, 100);
                    FUN_005CAD18(
                        copied_resource, reinterpret_cast<float*>(&bounds),
                        &measurement_cursor,
                        static_cast<int>(count -
                            (saved_position - begin) / 2));
                    const float width = bounds.right - bounds.left;
                    if (mode == 1) {
                        *reinterpret_cast<float*>(bytes + 0x2c) =
                            original_x +
                            (Float_ForceIntConversion_0049A8B0(
                                 alignment_width * 0.5f) -
                             Float_ForceIntConversion_0049A8B0(width * 0.5f));
                    } else {
                        *reinterpret_cast<float*>(bytes + 0x2c) =
                            original_x + alignment_width - width;
                    }
                } else {
                    const float extent =
                        *reinterpret_cast<float*>(bytes + 0x2c) - aligned_x;
                    *reinterpret_cast<float*>(bytes + 0x2c) = aligned_x;
                    if (alignment_width < extent) alignment_width = extent;
                }
                if (has_threshold) threshold_origin = cursor.position;
                alternate = false;
            } else if (result == 1) {
                alternate = false;
            } else if (result == 2) {
                alternate = true;
            }
            retry_origin = cursor.position;
            codepoint = FontLayout_DecodePacked(cursor);
            continue;
        }
        float advance = alternate
            ? *reinterpret_cast<const float*>(bytes + 0x50) : 0.0f;
        if (bytes[0x48] == 0) {
            void* face = *reinterpret_cast<void**>(bytes + 0x3c);
            std::uintptr_t* vtable = *reinterpret_cast<std::uintptr_t**>(face);
            int (*metric)(void*, std::uint32_t) = reinterpret_cast<int (*)(void*, std::uint32_t)>(
                vtable[0x38 / sizeof(std::uintptr_t)]);
            advance += static_cast<float>(metric(face, codepoint)) *
                       *reinterpret_cast<const float*>(bytes + 0x24);
        } else {
            advance += *reinterpret_cast<const float*>(bytes + 0x38);
        }
        if (has_threshold && threshold_origin != retry_origin &&
            advance >
                *reinterpret_cast<const float*>(bytes + 0x4c)) {
            codepoint = 10;
            cursor.position = threshold_origin;
            continue;
        }
        if (alternate)
            *reinterpret_cast<float*>(bytes + 0x2c) +=
                *reinterpret_cast<const float*>(bytes + 0x50);
        const float saved_y = *reinterpret_cast<float*>(bytes + 0x30);
        void* face = *reinterpret_cast<void**>(bytes + 0x3c);
        std::uintptr_t* vtable = *reinterpret_cast<std::uintptr_t**>(face);
        int (*vertical_metric)(void*) = reinterpret_cast<int (*)(void*)>(
            vtable[0x4c / sizeof(std::uintptr_t)]);
        *reinterpret_cast<float*>(bytes + 0x30) =
            saved_y - static_cast<float>(vertical_metric(face)) *
                          *reinterpret_cast<const float*>(bytes + 0x28);
        FontResource_EmitGlyphAndAdvance_005D24A0(resource, codepoint);
        *reinterpret_cast<float*>(bytes + 0x30) = saved_y;
        alternate = true;
        if (has_threshold) threshold_origin = cursor.position;
        retry_origin = cursor.position;
        codepoint = FontLayout_DecodePacked(cursor);
    }
    const std::uint32_t vertical_mode =
        *reinterpret_cast<const std::uint32_t*>(bytes + 0x5c) & 0x300u;
    if (vertical_mode == 0x100u || vertical_mode == 0x200u) {
        *reinterpret_cast<float*>(bytes + 0x30) = original_y;
    } else {
        *reinterpret_cast<float*>(bytes + 0x30) += vertical_restore;
    }
}
// Reconstructed ruby-control measurement, JP Rev 1: 0x0091818C.
extern "C" __attribute__((noinline)) int FontResource_MeasureRubyControl_0091818C(
    void* context, float* bounds, std::uint32_t opcode, void* cursor_state) {
    std::uint8_t* cursor = static_cast<std::uint8_t*>(cursor_state);
    std::uint8_t* control = *reinterpret_cast<std::uint8_t**>(cursor + 4);
    if (opcode != 0x0e ||
        *reinterpret_cast<const std::uint16_t*>(control) != 0 ||
        *reinterpret_cast<const std::uint16_t*>(control + 2) != 0) {
        return FontResource_ControlFallback_00BA8A6C(
            context, bounds, opcode, cursor_state);
    }
    const std::uint16_t payload_bytes =
        *reinterpret_cast<const std::uint16_t*>(control + 4);
    const std::uint16_t base_bytes =
        *reinterpret_cast<const std::uint16_t*>(control + 6);
    const std::uint16_t ruby_bytes =
        *reinterpret_cast<const std::uint16_t*>(control + 8);
    std::uint8_t* resource = *reinterpret_cast<std::uint8_t**>(cursor);
    std::uint8_t* base_text = control + 10 + ruby_bytes;
    std::uint8_t ruby_resource[100];
    Engine_BulkCopy_00425DF8(ruby_resource, resource, 100);
    *reinterpret_cast<void**>(ruby_resource + 0x3c) =
        *reinterpret_cast<void**>(static_cast<std::uint8_t*>(context) + 0x0c);
    *reinterpret_cast<float*>(ruby_resource + 0x24) = 1.0f;
    *reinterpret_cast<float*>(ruby_resource + 0x28) = 1.0f;
    *reinterpret_cast<float*>(ruby_resource + 0x54) = -2.0f;
    *reinterpret_cast<std::uint32_t*>(ruby_resource + 0x5c) = 0x300;
    float* threshold = reinterpret_cast<float*>(resource + 0x4c);
    const float saved_threshold = *threshold;
    *threshold = 0x1.fffffep127f;
    const float base_width = FontResource_MeasurePackedText_00C00514(
        resource, static_cast<int>(reinterpret_cast<std::uintptr_t>(base_text)),
        base_bytes >> 1);
    const std::uint32_t flags =
        *reinterpret_cast<const std::uint32_t*>(cursor + 0x10);
    const float spacing =
        (flags & 1u) == 0
            ? *reinterpret_cast<const float*>(resource + 0x50)
            : 0.0f;
    *threshold = saved_threshold;
    const float horizontal_extent = base_width + spacing;
    *reinterpret_cast<float*>(resource + 0x2c) += horizontal_extent;
    bounds[2] = bounds[0] + horizontal_extent;
    const float base_height = FontResource_GetLineHeight_00B45D20(resource);
    const float ruby_height =
        FontResource_GetLineHeight_00B45D20(ruby_resource);
    bounds[3] = bounds[1] + base_height + ruby_height - 2.0f;
    const float ruby_shift =
        FontResource_GetLineHeight_00B45D20(ruby_resource) - 2.0f;
    bounds[1] -= ruby_shift;
    bounds[3] -= ruby_shift;
    *reinterpret_cast<std::uint8_t**>(cursor + 4) =
        control + payload_bytes + 6 + base_bytes;
    FontResource_DestroyTemporary_00BA898C(ruby_resource);
    return 2;
}
// Reconstructed generic bounds/control callback, JP Rev 1: 0x00BA8A6C.
extern "C" __attribute__((noinline)) int FontResource_ControlFallback_00BA8A6C(
    void*  , float* bounds, std::uint32_t opcode,
    void* cursor_state) {
    std::uint8_t* cursor = static_cast<std::uint8_t*>(cursor_state);
    std::uint8_t* resource = static_cast<std::uint8_t*>(
        *reinterpret_cast<void**>(cursor));
    if (opcode == 9) {
        bounds[0] = *reinterpret_cast<float*>(resource + 0x2c);
        const int count = *reinterpret_cast<int*>(resource + 0x58);
        if (count > 0) {
            const float metric = resource[0x48]
                ? *reinterpret_cast<float*>(resource + 0x38)
                : FontResource_GetHorizontalMetric_00B45CF4(resource);
            const float cell = static_cast<float>(count) * metric;
            const float origin = *reinterpret_cast<float*>(cursor + 8);
            const int line = static_cast<int>(
                (*reinterpret_cast<float*>(resource + 0x2c) - origin) / cell) + 1;
            *reinterpret_cast<float*>(resource + 0x2c) = origin + cell * line;
        }
        bounds[2] = *reinterpret_cast<float*>(resource + 0x2c);
        bounds[1] = *reinterpret_cast<float*>(resource + 0x30);
        bounds[3] = bounds[1] + FontResource_GetLineHeight_00B45D20(resource);
        FontLayout_MergeBounds(bounds, bounds[0], bounds[1], bounds[2], bounds[3]);
        return 1;
    }
    if (opcode != 10)
        return 0;
    std::uint8_t* first = *reinterpret_cast<std::uint8_t**>(cursor + 4);
    std::uint8_t* scan = first;
    while (*reinterpret_cast<const std::uint16_t*>(scan) != 0 &&
           *reinterpret_cast<const std::uint16_t*>(scan) != 10) {
        const std::uint16_t tag = *reinterpret_cast<const std::uint16_t*>(scan);
        if (tag == 0x0e)
            scan += *reinterpret_cast<const std::uint16_t*>(scan + 6) + 8;
        else
            scan += tag == 0x0f ? 6 : 2;
    }
    const int count = static_cast<int>(scan - first) / 2;
    bounds[2] = *reinterpret_cast<float*>(resource + 0x2c);
    bounds[1] = *reinterpret_cast<float*>(resource + 0x30);
    const float height = FontResource_MeasurePackedHeight_00C00580(
        resource, static_cast<int>(reinterpret_cast<std::uintptr_t>(first)), count);
    *reinterpret_cast<float*>(resource + 0x2c) =
        *reinterpret_cast<const float*>(cursor + 8);
    *reinterpret_cast<float*>(resource + 0x30) += height;
    bounds[0] = *reinterpret_cast<float*>(resource + 0x2c);
    bounds[3] = *reinterpret_cast<float*>(resource + 0x30) +
        FontResource_GetLineHeight_00B45D20(resource);
    FontLayout_MergeBounds(bounds, bounds[0], bounds[1], bounds[2], bounds[3]);
    return 3;
}
extern "C" int FontResource_ControlWorker_009178A0(
    void* context, std::uint32_t opcode, void* cursor_state);
extern "C" __attribute__((noinline)) int FontResource_ApplyRubyControl_00917F10(
    void* context, std::uint32_t opcode, void* cursor_state) {
    std::uint8_t* cursor = static_cast<std::uint8_t*>(cursor_state);
    std::uint8_t* control = *reinterpret_cast<std::uint8_t**>(cursor + 4);
    const bool ruby = opcode == 0x0e &&
        *reinterpret_cast<const std::uint16_t*>(control) == 0 &&
        *reinterpret_cast<const std::uint16_t*>(control + 2) == 0;
    if (!ruby)
        return FontResource_ControlWorker_009178A0(
            context, opcode, cursor_state);
    if (!ruby) {
        if (opcode == 0x0a) {
            std::uint8_t* first = control;
            std::uint8_t* scan = first;
            while (*reinterpret_cast<const std::uint16_t*>(scan) != 0 &&
                   *reinterpret_cast<const std::uint16_t*>(scan) != 10) {
                const std::uint16_t tag = *reinterpret_cast<const std::uint16_t*>(scan);
                if (tag == 0x0e)
                    scan += *reinterpret_cast<const std::uint16_t*>(scan + 6) + 8;
                else
                    scan += tag == 0x0f ? 6 : 2;
            }
            const int count = static_cast<int>(scan - first);
            const float height = FontResource_MeasurePackedHeight_00C00580(
                *reinterpret_cast<void**>(cursor),
                static_cast<int>(reinterpret_cast<std::uintptr_t>(first)), count);
            std::uint8_t* resource = static_cast<std::uint8_t*>(
                *reinterpret_cast<void**>(cursor));
            *reinterpret_cast<float*>(resource + 0x2c) =
                *reinterpret_cast<const float*>(static_cast<std::uint8_t*>(cursor) + 8);
            *reinterpret_cast<float*>(resource + 0x30) += height;
            return 3;
        }
        if (opcode == 0x0f) {
            *reinterpret_cast<std::uint8_t**>(cursor + 4) += 4;
            return 0;
        }
        if (opcode == 9) {
            std::uint8_t* resource = static_cast<std::uint8_t*>(
                *reinterpret_cast<void**>(cursor));
            const int count = *reinterpret_cast<int*>(resource + 0x58);
            if (count > 0) {
                const float metric = resource[0x48]
                    ? *reinterpret_cast<float*>(resource + 0x38)
                    : FontResource_GetHorizontalMetric_00B45CF4(resource);
                const float cell = metric * static_cast<float>(
                    *reinterpret_cast<const float*>(static_cast<std::uint8_t*>(cursor) + 8));
                const float base = *reinterpret_cast<float*>(resource + 0x2c);
                const float origin = *reinterpret_cast<float*>(static_cast<std::uint8_t*>(cursor) + 8);
                const int line = static_cast<int>((base - origin) / cell) + 1;
                *reinterpret_cast<float*>(resource + 0x2c) = origin + cell * line;
            }
            return 1;
        }
        if (opcode != 0x0e)
            return 0;
        std::uint8_t* resource = static_cast<std::uint8_t*>(
            *reinterpret_cast<void**>(cursor));
        const std::uint16_t group = *reinterpret_cast<const std::uint16_t*>(control);
        const std::uint16_t subtype = *reinterpret_cast<const std::uint16_t*>(control + 2);
        if (group == 0) {
            if (subtype == 2) {
                const float scale = static_cast<float>(
                    *reinterpret_cast<const std::uint16_t*>(control + 6)) *
                    0.01f;
                *reinterpret_cast<float*>(resource + 0x24) = scale;
                *reinterpret_cast<float*>(resource + 0x28) = scale;
            } else if (subtype == 3) {
                const std::uint16_t payload = *reinterpret_cast<const std::uint16_t*>(control + 4);
                if (payload == 4) {
                    *reinterpret_cast<std::uint32_t*>(resource + 0x18) =
                        *reinterpret_cast<const std::uint32_t*>(control + 6);
                    FontResource_SelectTextBuffer_005BF1C4(resource);
                } else if (payload == 2) {
                    const std::int16_t index = *reinterpret_cast<const std::int16_t*>(control + 6);
                    *reinterpret_cast<std::uint32_t*>(resource + 0x18) =
                        index == -1 ? 0xffffffffu : static_cast<std::uint32_t>(index);
                    if (index == -1 || *reinterpret_cast<void**>(static_cast<std::uint8_t*>(context) + 4)) {
                        if (index != -1)
                            FontResource_LookupControlBytes_005F8014(
                                reinterpret_cast<void* const*>(static_cast<std::uint8_t*>(context) + 4),
                                index, control + 0x20);
                        FontResource_SelectTextBuffer_005BF1C4(resource);
                    }
                }
            }
        } else if (group == 1 && subtype == 0) {
            std::uint8_t* end = control + *reinterpret_cast<const std::uint16_t*>(control + 4) + 6;
            std::uint8_t* scan = end;
            while (*reinterpret_cast<const std::uint16_t*>(scan) != 0x0f) {
                ++scan;
            }
            const int count = static_cast<int>(scan - end);
            std::uint8_t workspace[100];
            Engine_BulkCopy_00425DF8(workspace, *reinterpret_cast<void**>(cursor), 100);
            const float old_y = *reinterpret_cast<float*>(workspace + 0x30);
            FontResource_ApplyTextRecord_005CB104(
                workspace, static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(end)), count);
            *reinterpret_cast<float*>(workspace + 0x30) = old_y +
                FontResource_GetVerticalAdvance_005D6184(workspace);
            FontResource_ApplyTextRecord_005CB104(
                workspace, static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(end)), count);
            float bounds[4] = {};
            FUN_005B4B38(workspace, bounds,
                static_cast<int>(reinterpret_cast<std::uintptr_t>(end)), count);
            *reinterpret_cast<float*>(resource + 0x2c) += bounds[3] + 1.0f;
            *reinterpret_cast<std::uint8_t**>(cursor + 4) =
                end + count * 2;
            FontResource_DestroyTemporary_00BA898C(workspace);
            return 0;
        } else if (group == 1 && subtype == 1 &&
                   *reinterpret_cast<const float*>(static_cast<std::uint8_t*>(context) + 8) <
                   *reinterpret_cast<const float*>(control + 6)) {
            return 4;
        }
        *reinterpret_cast<std::uint8_t**>(cursor + 4) =
            control + *reinterpret_cast<const std::uint16_t*>(control + 4) + 6;
        return 0;
    }
    std::uint8_t* resource = *reinterpret_cast<std::uint8_t**>(cursor);
    float* threshold = reinterpret_cast<float*>(resource + 0x4c);
    const float saved_threshold = *threshold;
    *threshold = 0x1.fffffep127f;
    if ((*reinterpret_cast<const std::uint32_t*>(cursor + 0x10) & 1u) == 0) {
        *reinterpret_cast<float*>(resource + 0x2c) +=
            *reinterpret_cast<const float*>(resource + 0x50);
    }
    const std::uint16_t payload_bytes =
        *reinterpret_cast<const std::uint16_t*>(control + 4);
    const std::uint16_t base_bytes =
        *reinterpret_cast<const std::uint16_t*>(control + 6);
    const std::uint16_t ruby_bytes =
        *reinterpret_cast<const std::uint16_t*>(control + 8);
    const int base_count = base_bytes >> 1;
    const int ruby_count = ruby_bytes >> 1;
    std::uint8_t* ruby_text = control + 10;
    std::uint8_t* base_text = ruby_text + ruby_bytes;
    const float original_x = *reinterpret_cast<const float*>(resource + 0x2c);
    const float original_y = *reinterpret_cast<const float*>(resource + 0x30);
    const std::uint32_t saved_flags =
        *reinterpret_cast<const std::uint32_t*>(resource + 0x5c);
    std::uint8_t ruby_resource[100];
    Engine_BulkCopy_00425DF8(ruby_resource, resource, 100);
    *reinterpret_cast<void**>(ruby_resource + 0x3c) =
        *reinterpret_cast<void**>(static_cast<std::uint8_t*>(context) + 0x0c);
    *reinterpret_cast<float*>(ruby_resource + 0x24) = 1.0f;
    *reinterpret_cast<float*>(ruby_resource + 0x28) = 1.0f;
    *reinterpret_cast<float*>(ruby_resource + 0x54) = -2.0f;
    *reinterpret_cast<std::uint32_t*>(ruby_resource + 0x5c) = 0x300;
    const float base_width = FontResource_MeasurePackedText_00C00514(
        resource, static_cast<int>(reinterpret_cast<std::uintptr_t>(base_text)),
        base_count);
    const float ruby_width = FontResource_MeasurePackedText_00C00514(
        ruby_resource,
        static_cast<int>(reinterpret_cast<std::uintptr_t>(ruby_text)),
        ruby_count);
    const float difference = base_width - ruby_width;
    float ruby_x = original_x;
    if (difference > 0.0f) {
        const int gaps = ruby_count - 1;
        const float metric_difference =
            FontResource_GetHorizontalMetric_00B45CF4(resource) -
            FontResource_GetHorizontalMetric_00B45CF4(ruby_resource);
        float spacing = 0.0f;
        if (gaps != 0) {
            spacing = Libm_Floorf_0049A940(
                (difference - (metric_difference > 0.0f
                                   ? metric_difference
                                   : 0.0f)) /
                static_cast<float>(gaps));
            if (spacing < 0.0f) spacing = 0.0f;
        }
        ruby_x += Libm_Floorf_0049A940(
            (difference - spacing * static_cast<float>(gaps)) * 0.5f);
        *reinterpret_cast<float*>(ruby_resource + 0x50) = spacing;
    } else if (difference < 0.0f) {
        ruby_x += difference * 0.5f;
    }
    const float ruby_y =
        original_y -
        (FontResource_GetVerticalAdvance_005D6184(resource) +
         FontResource_GetRubyVerticalMetric_00B45D4C(ruby_resource) - 2.0f);
    if (*reinterpret_cast<const std::uint8_t*>(
            static_cast<std::uint8_t*>(context) + 0x10) != 0) {
        *reinterpret_cast<float*>(ruby_resource + 0x2c) =
            Libm_Floorf_0049A940(ruby_x + 0.5f);
        *reinterpret_cast<float*>(ruby_resource + 0x30) =
            Libm_Floorf_0049A940(ruby_y + 0.5f);
        FontResource_ApplyTextRecord_005CB104(
            ruby_resource,
            static_cast<std::uint32_t>(
                reinterpret_cast<std::uintptr_t>(ruby_text)),
            static_cast<std::uint32_t>(ruby_count));
    }
    *reinterpret_cast<std::uint32_t*>(resource + 0x5c) = 0x300;
    FontResource_ApplyTextRecord_005CB104(
        resource,
        static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(base_text)),
        static_cast<std::uint32_t>(base_count));
    *reinterpret_cast<std::uint32_t*>(resource + 0x5c) = saved_flags;
    *reinterpret_cast<std::uint8_t**>(cursor + 4) =
        control + payload_bytes + 6 + base_bytes;
    *threshold = saved_threshold;
    FontResource_DestroyTemporary_00BA898C(ruby_resource);
    return 2;
}
extern "C" void UiLayoutEnvironment_Query_00A31248(void* out_result,
                                                      std::uint32_t mode_mask);
extern "C" void* Engine_LazySingletonGetter_0049BED0();
void FontText_UpdateGlyphAnimation_0072C060(void* resource, float dt);
extern "C" int FontText_StateQuery_005C2A58();
extern "C" int FontText_StateQuery_005C2AC0(void* singleton);
extern "C" int FontText_StateQuery_005C2AA4(void* singleton);
extern "C" int FontText_StatusQuery_005BCDFC();
extern "C" std::uint32_t FontText_StatusQuery_005BCDE4();
extern "C" void* Engine_GlobalTimingState_Get_0054EF64();
void FontText_UpdateEffectTransition_007236F0(void* state);
extern "C" int FontText_EffectTransitionReady_002F1140();
extern "C" std::uint32_t FontText_EffectTransitionMode_00A61A04(void* environment);
extern "C" void FUN_0072AE84(void* resource);
extern "C" int FontTextResource_IsActive_00AABEDC(void* resource);
extern "C" __attribute__((noinline)) int FontTextResource_IsReady_00AABEF4(void* resource) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(resource);
    return ((*reinterpret_cast<std::uint32_t*>(bytes) & 3) == 3 &&
            *reinterpret_cast<void**>(bytes + 0x28) != 0)
               ? 1
               : 0;
}
extern "C" int FUN_005A8AE8(
    void* state, int* metrics, int entry, std::uint32_t colour, float scale,
    float width_limit, float height_limit);
extern "C" void FUN_005C52AC(
    void* resource, std::uint32_t channel, std::uint32_t value);
extern "C" void Engine_StridedInsertionSort_004C626C(
    void* base, std::uint32_t count, std::uint32_t stride, void* comparator);
// Semantic reconstruction, JP Rev 1: 0x005C52AC.
extern "C" __attribute__((noinline)) void FUN_005C52AC(
    void* resource, std::uint32_t channel, std::uint32_t previous) {
    if (channel >= 11) return;
    std::uint8_t* bytes = static_cast<std::uint8_t*>(resource);
    std::uint8_t* record = bytes + channel * 0x14;
    std::uint32_t* random_state = reinterpret_cast<std::uint32_t*>(bytes + 4);
    std::uint8_t* derived = *reinterpret_cast<std::uint8_t**>(bytes + 0xfc);
    const std::uint32_t count = *reinterpret_cast<std::uint32_t*>(record + 0x20);
    std::uint16_t* source = *reinterpret_cast<std::uint16_t**>(record + 0x2c);
    if (derived == 0 || source == 0 || count == 0) return;
    const std::int32_t base_index = *reinterpret_cast<std::int32_t*>(record + 0x1c);
    for (std::uint32_t i = 0; i < count; ++i) {
        std::uint32_t value = random_state[0];
        random_state[0] = random_state[1];
        random_state[1] = random_state[2];
        random_state[2] = random_state[3];
        value ^= value << 11;
        value ^= value >> 8;
        value ^= random_state[3] ^ (random_state[3] >> 19);
        random_state[3] = value;
        std::uint32_t* item = reinterpret_cast<std::uint32_t*>(derived + i * 8);
        *reinterpret_cast<float*>(item) =
            static_cast<float>(value >> 8) * 0x1.000002p-24f;
        item[1] = static_cast<std::uint32_t>(base_index + i);
    }
    Engine_StridedInsertionSort_004C626C(
        derived, count, 8, reinterpret_cast<void*>(0x005cb654));
    for (std::uint32_t i = 0; i < count; ++i)
        source[i] = static_cast<std::uint16_t>(
            reinterpret_cast<std::uint32_t*>(derived + i * 8)[1]);
    if (count > 1 && source[0] == previous) {
        const std::uint16_t next = source[1];
        source[1] = source[0];
        source[0] = next;
    }
    *reinterpret_cast<std::int32_t*>(record + 0x24) = 0;
}
// Semantic reconstruction, JP Rev 1: 0x005B8DD8.
extern "C" __attribute__((noinline)) std::uint32_t FUN_005B8DD8(
    void* resource, std::uint32_t channel) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(resource);
    if (channel >= 11) return 0xffffffffu;
    std::uint8_t* record = bytes + channel * 0x14;
    std::uint8_t* fields = record + 0x1c;
    const std::int32_t count = *reinterpret_cast<std::int32_t*>(record + 0x20);
    const std::uint16_t* data =
        *reinterpret_cast<const std::uint16_t**>(fields + 0x10);
    if (count <= 0 || data == 0) return 0xffffffffu;
    const std::int32_t cursor =
        *reinterpret_cast<std::int32_t*>(fields + 0x08);
    const std::uint16_t* sample = data + cursor;
    *reinterpret_cast<std::int32_t*>(fields + 0x08) = cursor + 1;
    const std::uint32_t value = static_cast<std::uint32_t>(*sample);
    if (count <= cursor + 1) {
        FUN_005C52AC(resource, channel, value);
        std::int32_t* completion =
            reinterpret_cast<std::int32_t*>(bytes + 0x28);
        ++*completion;
        std::int32_t* total = reinterpret_cast<std::int32_t*>(bytes + 0x100);
        if (*total > *completion) *completion = *total;
        *total = *completion;
        std::int32_t minimum = *completion;
        for (std::uint32_t i = 1; i < 11; ++i) {
            std::int32_t* candidate =
                reinterpret_cast<std::int32_t*>(bytes + i * 0x14u + 0x28u);
            if (*candidate < minimum) minimum = *candidate;
        }
        if (minimum > 0) {
            for (std::uint32_t i = 0; i < 11; ++i) {
                std::int32_t* candidate =
                    reinterpret_cast<std::int32_t*>(bytes + i * 0x14u + 0x28u);
                *candidate -= minimum;
            }
            *total -= minimum;
        }
    }
    return value;
}
// Semantic reconstruction, JP Rev 1: 0x005A8AE8.
extern "C" __attribute__((noinline)) int FUN_005A8AE8(
    void* state, int* metrics, int entry, std::uint32_t colour,
    float scale, float width_limit, float height_limit) {
    if (metrics == 0 || entry < 0) return 0;
    std::uint8_t* bytes = static_cast<std::uint8_t*>(state);
    const std::uint32_t encoded_length =
        ResourceTable_EntryLength_0049CB04(bytes + 0x26c, entry);
    const std::uint32_t unit_count = encoded_length >> 1;
    if (unit_count == 0) return 0;
    const void* entry_bytes =
        ResourceTable_GetEntry_00579AD0(bytes + 0x26c, entry);
    if (entry_bytes == 0) return 0;
    *reinterpret_cast<float*>(bytes + 0x160) = 0.0f;
    *reinterpret_cast<float*>(bytes + 0x164) = 0.0f;
    *reinterpret_cast<float*>(bytes + 0x158) = scale;
    *reinterpret_cast<float*>(bytes + 0x15c) = scale;
    float bounds[4] = {0.0f, 0.0f, 0.0f, 0.0f};
    FUN_005B4B38(
        bytes + 0x134, bounds, entry, static_cast<int>(unit_count));
    float width = bounds[2] - bounds[0];
    float height = bounds[3] - bounds[1];
    float scaled_width = scale;
    float scaled_height = scale;
    if (width_limit < width && width != 0.0f) {
        const float ratio = width_limit / width;
        scaled_width *= ratio;
        width *= ratio;
    }
    if (height_limit > 0.0f && height_limit < height && height != 0.0f) {
        const float ratio = height_limit / height;
        scaled_height *= ratio;
        height *= ratio;
    }
    metrics[0] = entry;
    metrics[1] = reinterpret_cast<std::uintptr_t>(entry_bytes);
    metrics[2] = static_cast<int>(unit_count);
    *reinterpret_cast<float*>(metrics + 3) = width;
    *reinterpret_cast<float*>(metrics + 4) = height;
    *reinterpret_cast<float*>(metrics + 5) = -bounds[1];
    *reinterpret_cast<float*>(metrics + 6) = -bounds[0];
    *reinterpret_cast<float*>(metrics + 7) = scaled_width;
    *reinterpret_cast<float*>(metrics + 8) = scaled_height;
    metrics[9] = static_cast<int>(colour);
    return 1;
}
// Semantic reconstruction, JP Rev 1: 0x005A8C28.
extern "C" __attribute__((noinline)) void FontText_PrepareSingleGlyphBatch_005A8C28(void* state) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(state);
    std::uint8_t* batch = bytes + 0x19c;
    FontText_ResetBatchState_005C7888(batch);
    *reinterpret_cast<std::uint32_t*>(bytes + 0x1c8) =
        *reinterpret_cast<std::uint32_t*>(bytes + 0x3c0);
    *reinterpret_cast<std::uint32_t*>(bytes + 0x1cc) =
        *reinterpret_cast<std::uint32_t*>(bytes + 0x3c4);
    *reinterpret_cast<std::uint32_t*>(bytes + 0x1c0) =
        *reinterpret_cast<std::uint32_t*>(bytes + 0x3c8);
    *reinterpret_cast<std::uint32_t*>(bytes + 0x1c4) =
        *reinterpret_cast<std::uint32_t*>(bytes + 0x3cc);
    const std::uint32_t colour =
        *reinterpret_cast<std::uint32_t*>(bytes + 0x3d0);
    *reinterpret_cast<std::uint32_t*>(bytes + 0x1b4) =
        (colour << 24) | ((colour >> 8) & 0xffu) << 16 |
        ((colour >> 16) & 0xffu) << 8 | (colour >> 24);
    FontResource_SelectTextBuffer_005BF1C4(batch);
    FontResource_ApplyTextRecord_005CB100(
        batch,
        *reinterpret_cast<std::uint32_t*>(bytes + 0x3b0),
        *reinterpret_cast<std::uint32_t*>(bytes + 0x3b4));
    FontText_BatchIdentity_005C78A4(batch);
    void** cached = reinterpret_cast<void**>(0x00d6372c);
    if (*cached == 0) *cached = Engine_RendererSingleton_Get_005C3CE4();
    FontText_CompileGlyphBatch_005BFA8C(*cached, batch);
}
// Semantic/byte-match reconstruction, JP Rev 1: 0x00722358.
__attribute__((noinline)) int FontText_StartLayoutUpdate_00722358(void* state) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(state);
    std::uint32_t* flags = reinterpret_cast<std::uint32_t*>(bytes + 0x270);
    if (((*reinterpret_cast<const std::uint32_t*>(bytes + 0x2c0) & 1u) == 0) ||
        ((*flags & 0x1000u) != 0)) {
        return 0;
    }
    bytes[0x27c] = 0;
    *reinterpret_cast<float*>(bytes + 0x280) = 0.0f;
    *reinterpret_cast<float*>(bytes + 0x284) = 0.0f;
    *flags = (*flags & 0xffcffdffu) | 0x80001500u;
    FontEffectEvent_Notify_0075D298(0xc);
    return 1;
}
// Semantic/byte-match reconstruction, JP Rev 1: 0x00722420.
__attribute__((noinline)) int FontText_QueueGlyphMetrics_00722420(void* state) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(state);
    const int entry = static_cast<int>(ResourceWrapper_FirstField_00425F64(
        bytes + 0x26c));
    if (entry < 0) return 0;
    int* metrics = reinterpret_cast<int*>(bytes + 0x2c8);
    if (FUN_005A8AE8(
            state, metrics, entry, 0x3c281effu, 0.65f, 268.0f, -1.0f) == 0) {
        return 0;
    }
    const float rounded_x = 160.0f -
                            *reinterpret_cast<float*>(metrics + 3) * 0.5f +
                            0.5f;
    const float rounded_y = 120.0f -
                            *reinterpret_cast<float*>(metrics + 4) * 0.5f +
                            0.5f;
    *reinterpret_cast<float*>(metrics + 5) =
        static_cast<float>(static_cast<int>(rounded_x));
    *reinterpret_cast<float*>(metrics + 6) =
        static_cast<float>(static_cast<int>(rounded_y));
    std::uint32_t* pending = reinterpret_cast<std::uint32_t*>(bytes + 0x2c0);
    pending[0] = (pending[0] & ~0xeu) | 1u;
    pending[1] &= ~0xfu;
    *reinterpret_cast<std::uint32_t*>(bytes + 0x28c) = 0;
    *reinterpret_cast<std::uint32_t*>(bytes + 0x270) &= ~0x2000u;
    return 1;
}
// Partial semantic/byte-match reconstruction, JP Rev 1: 0x007232A8.
__attribute__((noinline)) int FontText_LayoutTwoGlyphs_007232A8(void* state,
                                      int first_source,
                                      int second_source,
                                      std::uint32_t mode) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(state);
    if (mode > 1) mode = 0;
    *reinterpret_cast<std::uint32_t*>(bytes + 0x28c) = 0;
    *reinterpret_cast<std::uint32_t*>(bytes + 0x2c0) &= ~0xeu;
    *reinterpret_cast<std::uint32_t*>(bytes + 0x2c4) &= ~0xeu;
    for (int index = 0; index < 2; ++index) {
        const int source = index == 0 ? first_source : second_source;
        if (source == 0) return 0;
        const int entry = static_cast<int>(ResourceWrapper_FirstField_00425F64(
            bytes + 0x26c));
        if (entry < 0) return 0;
        int* metrics = reinterpret_cast<int*>(bytes + 0x2f0 + index * 0x28);
        const std::uint32_t colour = mode == static_cast<std::uint32_t>(index)
                                         ? 0x190f0fffu
                                         : 0xc7a786ffu;
        if (FUN_005A8AE8(
                state, metrics, entry, colour, 0.65f, 111.0f, -1.0f) == 0) {
            return 0;
        }
        const float x = 36.0f + static_cast<float>(index) * 137.0f;
        const float rounded_x = x + 119.0f * 0.5f -
                                *reinterpret_cast<float*>(metrics + 3) * 0.5f +
                                0.5f;
        const float rounded_y = 171.0f -
                                *reinterpret_cast<float*>(metrics + 4) * 0.5f +
                                0.5f;
        *reinterpret_cast<float*>(metrics + 5) =
            static_cast<float>(static_cast<int>(rounded_x));
        *reinterpret_cast<float*>(metrics + 6) =
            static_cast<float>(static_cast<int>(rounded_y));
        std::int16_t* bounds = reinterpret_cast<std::int16_t*>(bytes + 0x2a8 + index * 8);
        bounds[0] = static_cast<std::int16_t>(x);
        bounds[1] = static_cast<std::int16_t>(x + 119.0f);
        bounds[2] = 0x9a;
        bounds[3] = 0xbc;
    }
    if ((*reinterpret_cast<const std::uint32_t*>(bytes + 0x2c0) & 1u) != 0) {
        const float x = 85.0f -
                        *reinterpret_cast<const float*>(bytes + 0x2d8) * 0.5f;
        *reinterpret_cast<std::uint32_t*>(bytes + 0x2c4) &= ~1u;
        *reinterpret_cast<float*>(bytes + 0x2e0) =
            static_cast<float>(static_cast<int>(x + 0.5f));
    }
    *reinterpret_cast<std::uint32_t*>(bytes + 0x28c) = 2;
    *reinterpret_cast<std::uint32_t*>(bytes + 0x2c0) |= 6;
    *reinterpret_cast<std::uint32_t*>(bytes + 0x290) = 1;
    *reinterpret_cast<std::uint32_t*>(bytes + 0x294) = mode;
    return 1;
}
// Partial semantic/byte-match reconstruction, JP Rev 1: 0x00723498.
__attribute__((noinline)) int FontText_LayoutGlyphRun_00723498(void* state,
                                     int first_source,
                                     int second_source,
                                     int third_source,
                                     std::uint32_t mode) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(state);
    if (mode > 1) mode = 0;
    *reinterpret_cast<std::uint32_t*>(bytes + 0x28c) = 0;
    *reinterpret_cast<std::uint32_t*>(bytes + 0x2c0) &= ~0xeu;
    *reinterpret_cast<std::uint32_t*>(bytes + 0x2c4) &= ~0xeu;
    const int sources[3] = {first_source, second_source, third_source};
    for (int index = 0; index < 3; ++index) {
        if (sources[index] == 0) return 0;
        const int entry = static_cast<int>(ResourceWrapper_FirstField_00425F64(
            bytes + 0x26c));
        if (entry < 0) return 0;
        int* metrics = reinterpret_cast<int*>(bytes + 0x2f0 + index * 0x28);
        const std::uint32_t colour = mode == static_cast<std::uint32_t>(index)
                                         ? 0x190f0fffu
                                         : 0x3f000000u;
        const float width_limit = index < 2 ? 54.0f : 191.0f;
        if (FUN_005A8AE8(
                state, metrics, entry, colour, 0.65f, width_limit, -1.0f) == 0) {
            return 0;
        }
        const float placement_x = 36.0f +
                                  static_cast<float>(index & 1) * 137.0f;
        const float placement_y = 132.0f +
                                  static_cast<float>(index / 2) * 46.0f;
        const float atlas_x = index < 2 ? 119.0f : 256.0f;
        const float rounded_x = placement_x + atlas_x * 0.5f -
                                *reinterpret_cast<float*>(metrics + 3) * 0.5f +
                                0.5f;
        const float rounded_y = placement_y + 34.0f * 0.5f -
                                *reinterpret_cast<float*>(metrics + 4) * 0.5f +
                                0.5f;
        *reinterpret_cast<float*>(metrics + 5) =
            static_cast<float>(static_cast<int>(rounded_x));
        *reinterpret_cast<float*>(metrics + 6) =
            static_cast<float>(static_cast<int>(rounded_y));
        std::int16_t* bounds = reinterpret_cast<std::int16_t*>(bytes + 0x2a8 + index * 8);
        bounds[0] = static_cast<std::int16_t>(placement_x);
        bounds[1] = static_cast<std::int16_t>(placement_x + atlas_x);
        bounds[2] = static_cast<std::int16_t>(placement_y);
        bounds[3] = static_cast<std::int16_t>(placement_y + 34.0f);
    }
    if ((*reinterpret_cast<const std::uint32_t*>(bytes + 0x2c0) & 1u) != 0) {
        const float x = 84.0f -
                        *reinterpret_cast<const float*>(bytes + 0x2d8) * 0.5f;
        *reinterpret_cast<std::uint32_t*>(bytes + 0x2c4) &= ~1u;
        *reinterpret_cast<float*>(bytes + 0x2e0) =
            static_cast<float>(static_cast<int>(x + 0.5f));
    }
    *reinterpret_cast<std::uint32_t*>(bytes + 0x28c) = 3;
    *reinterpret_cast<std::uint32_t*>(bytes + 0x2c0) |= 0xeu;
    *reinterpret_cast<std::uint32_t*>(bytes + 0x290) = 2;
    *reinterpret_cast<std::uint32_t*>(bytes + 0x294) = mode;
    return 1;
}
struct UiLayoutEnvironmentResult {
    std::int32_t x;
    std::int32_t y;
    std::uint8_t x_active;
    std::uint8_t y_active;
    std::uint8_t mode;
    std::uint8_t reserved;
    float extent;
};
// Partial semantic/byte-match reconstruction, JP Rev 1: 0x00722530.
__attribute__((noinline)) void FUN_00722530(void* state) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(state);
    std::uint32_t* flags = reinterpret_cast<std::uint32_t*>(bytes + 0x270);
    std::uint32_t* count = reinterpret_cast<std::uint32_t*>(bytes + 0x28c);
    std::int32_t* selection = reinterpret_cast<std::int32_t*>(bytes + 0x294);
    std::uint32_t* enabled = reinterpret_cast<std::uint32_t*>(bytes + 0x290);
    UiLayoutEnvironmentResult environment = {};
    UiLayoutEnvironment_Query_00A31248(&environment, 1);
    if ((*flags & 0x100000u) != 0 &&
        *reinterpret_cast<const float*>(bytes + 0x284) >= 0.4f &&
        (environment.y_active != 0 ||
         environment.mode == 4 || environment.mode == 5 ||
         environment.mode == 6 || environment.mode == 8 ||
         environment.mode == 9 || environment.mode == 10 ||
         environment.mode == 11)) {
        bytes[0x27c] = 1;
        *flags &= ~0x100000u;
    }
    if ((*flags & 0x200000u) == 0) return;
    const std::int32_t previous_selection = *selection;
    std::int32_t effect_slot = -1;
    if (environment.mode != 0xff && *count != 0 &&
        environment.x >= 0 && environment.y >= 0) {
        const std::int16_t* bounds = reinterpret_cast<const std::int16_t*>(bytes + 0x2a8);
        for (std::uint32_t index = 0; index < *count; ++index) {
            const std::int16_t* rectangle = bounds + index * 4;
            if (environment.x < rectangle[0] || environment.x > rectangle[1] ||
                environment.y < rectangle[2] || environment.y > rectangle[3]) {
                continue;
            }
            *selection = static_cast<std::int32_t>(index);
            *reinterpret_cast<float*>(bytes + 0x288) = 0.0f;
            bytes[0x27c] = static_cast<std::uint8_t>(index + 2);
            *flags = ((*flags | (1u << (index + 16))) & ~0x200000u) | 0x80000u;
            effect_slot = static_cast<std::int32_t>(index);
            break;
        }
    }
    if (environment.mode != 0xff && (*flags & 0x200000u) != 0) {
        switch (environment.mode) {
        case 0:
            if (*count >= 1 && *selection < 0) *selection = 0;
            break;
        case 1:
            if (*count < 1 || *selection < 0) {
                if (*count >= 1) *selection = 0;
            } else if (*count >= 2 && *selection < 2) {
                *selection = *selection == 0 ? 1 : 0;
            }
            break;
        case 2:
        case 3:
            if (*count >= 1 && *selection < 0) {
                *selection = 0;
            } else if (*count >= 3 && *selection < 2) {
                *selection = 2;
            }
            break;
        case 4:
        case 6:
        case 8:
        case 9:
        case 10:
        case 11:
            if (*selection >= 0 && *selection < static_cast<std::int32_t>(*count)) {
                *reinterpret_cast<float*>(bytes + 0x288) = 0.0f;
                bytes[0x27c] = static_cast<std::uint8_t>(*selection + 2);
                *flags = (*flags & ~0x200000u) | 0x80000u;
                effect_slot = *selection;
            }
            break;
        case 5: {
            const std::uint32_t valid_mask =
                (*count >= 32 ? 0xffffffffu : (1u << *count) - 1u) & *enabled;
            if (valid_mask != 0) {
                std::uint32_t next = 0;
                while ((valid_mask & (1u << next)) == 0) ++next;
                *selection = static_cast<std::int32_t>(next);
                *reinterpret_cast<float*>(bytes + 0x288) = 0.0f;
                bytes[0x27c] = static_cast<std::uint8_t>(next + 2);
                *flags = (*flags & ~0x200000u) | 0x80000u;
                effect_slot = *selection;
            }
            break;
        }
        default:
            break;
        }
    }
    if (effect_slot >= 0) {
        FontEffectEvent_Notify_0075D298(
            (*enabled & (1u << effect_slot)) != 0 ? 4 : 3);
    }
    if (*selection == previous_selection) return;
    *reinterpret_cast<std::uint32_t*>(bytes + 0x2c4) &= ~0xeu;
    std::uint8_t* metrics = bytes + 0x2f0;
    for (std::uint32_t index = 0; index < *count; ++index) {
        const std::uint32_t colour = index == static_cast<std::uint32_t>(*selection)
                                         ? 0x190f0fffu
                                         : 0xc7a786ffu;
        *reinterpret_cast<std::uint32_t*>(metrics + index * 0x28 + 0x24) = colour;
    }
    if (effect_slot < 0) FontEffectEvent_Notify_0075D298(1);
}
// Partial semantic/byte-match reconstruction, JP Rev 1: 0x007245A4.
__attribute__((noinline)) void FontText_UpdateOverlayState_007245A4(void* state) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(state);
    std::uint32_t* flags = reinterpret_cast<std::uint32_t*>(bytes + 0x270);
    std::uint32_t updated_flags = *flags;
    if ((updated_flags & 1u) == 0) return;
    if ((updated_flags & 0x300000u) != 0) {
        FUN_00722530(state);
        updated_flags = *flags;
    }
    if ((*reinterpret_cast<const std::uint32_t*>(bytes + 0x274) & 2u) != 0) {
        static void* singleton_cache;
        void* singleton = singleton_cache;
        if (singleton == 0) {
            singleton = Engine_LazySingletonGetter_0049BED0();
            singleton_cache = singleton;
        }
        int value = FontText_StateQuery_005C2A58();
        if (value != 0) {
            value = 0;
        } else if (FontText_StateQuery_005C2AC0(singleton) != 0) {
            value = -1;
        } else {
            value = FontText_StateQuery_005C2AA4(singleton);
            if (value < 0) value = 0;
            if (value > 3) value = 3;
            ++value;
        }
        *reinterpret_cast<std::int32_t*>(bytes + 0x374) = value;
    }
    if ((*reinterpret_cast<const std::uint32_t*>(bytes + 0x274) & 4u) != 0) {
        const int first = FontText_StatusQuery_005BCDFC();
        const std::uint32_t second = FontText_StatusQuery_005BCDE4();
        std::uint32_t value;
        if (first == 1) {
            value = 0xffffffffu;
        } else if (second <= 2) {
            value = 0;
        } else if (second >= 5) {
            value = 3;
        } else {
            value = second == 4 ? 2u : 1u;
        }
        *reinterpret_cast<std::uint32_t*>(bytes + 0x378) = value;
    }
    updated_flags = *flags;
    if ((updated_flags & 0x1000000u) != 0) {
        FontText_UpdateEffectTransition_007236F0(state);
    }
    static void* status_cache;
    void* status = status_cache;
    if (status == 0) {
        status = Engine_GlobalTimingState_Get_0054EF64();
        status_cache = status;
    }
    const float dt = *reinterpret_cast<const float*>(
                         static_cast<const std::uint8_t*>(status) + 0xc) /
                     60.0f;
    const std::uint32_t layout_flags =
        *reinterpret_cast<const std::uint32_t*>(bytes + 0x274);
    if (layout_flags & 8u) {
        float fade = *reinterpret_cast<float*>(bytes + 0x2a4) + 12.0f * dt;
        if (fade < 0.0f) fade = 0.0f;
        if (fade > 1.0f) fade = 1.0f;
        *reinterpret_cast<float*>(bytes + 0x2a4) = fade;
    } else if ((updated_flags & 0x10u) != 0) {
        float fade = *reinterpret_cast<float*>(bytes + 0x2a4) - 3.0f * dt;
        if (fade < 0.0f) fade = 0.0f;
        if (fade > 1.0f) fade = 1.0f;
        *reinterpret_cast<float*>(bytes + 0x2a4) = fade;
        if (fade <= 0.0f) *flags &= ~0x10u;
        updated_flags = *flags;
    }
    void* resource = *reinterpret_cast<void**>(bytes + 0x398);
    if (resource == 0 || FontTextResource_IsActive_00AABEDC(resource) == 0) {
        updated_flags &= ~8u;
    } else {
        FontText_UpdateGlyphAnimation_0072C060(resource, dt);
        if (FontTextResource_IsReady_00AABEF4(resource) != 0) {
            updated_flags |= 8u;
        } else {
            updated_flags &= ~8u;
        }
    }
    *flags = updated_flags;
    if ((updated_flags & 0x2000000u) != 0 &&
        *reinterpret_cast<const std::int32_t*>(bytes + 0x298) > 0) {
        *reinterpret_cast<float*>(bytes + 0x29c) += dt;
    }
    const std::uint32_t effect_mask = 0x70f00u;
    if ((updated_flags & effect_mask) != 0) {
        if ((updated_flags & 0x100u) != 0) {
            float progress = *reinterpret_cast<float*>(bytes + 0x280) +
                             dt * 6.6666665f;
            *reinterpret_cast<float*>(bytes + 0x280) = progress;
            if (progress >= 1.0f) {
                *reinterpret_cast<float*>(bytes + 0x280) = 1.0f;
                updated_flags = (updated_flags & ~0x100u);
                if (*reinterpret_cast<const std::uint32_t*>(bytes + 0x28c) != 0) {
                    updated_flags = (updated_flags & ~0x70000u) | 0x200000u;
                } else if ((updated_flags & 0x2000u) != 0) {
                    updated_flags = (updated_flags & ~0x2000u) | 0x100000u;
                }
                *flags = updated_flags;
            }
        } else if ((updated_flags & 0x200u) != 0) {
            float progress = *reinterpret_cast<float*>(bytes + 0x280) -
                             dt * 6.6666665f;
            *reinterpret_cast<float*>(bytes + 0x280) = progress;
            if (progress <= 0.0f) {
                *reinterpret_cast<float*>(bytes + 0x280) = 0.0f;
                updated_flags = (updated_flags & ~0x1600u) | 0x80000000u;
                *flags = updated_flags;
            }
        }
        if ((updated_flags & 0x400u) != 0) {
            *reinterpret_cast<float*>(bytes + 0x284) += dt;
        }
        if ((updated_flags & 0x800u) != 0) {
            std::int32_t* phase = reinterpret_cast<std::int32_t*>(bytes + 0x278);
            *phase += static_cast<std::int32_t>(dt * 960.0f);
            if (*phase > 0x40000000) *phase -= 0x40000000;
        }
        if ((updated_flags & 0x70000u) != 0) {
            *reinterpret_cast<float*>(bytes + 0x288) += dt;
        }
    }
    updated_flags = *flags;
    if ((updated_flags & 0x80000000u) == 0) return;
    const bool progress_high =
        *reinterpret_cast<const float*>(bytes + 0x280) > 0.001f;
    bool render_active = progress_high ||
                         (updated_flags & 0x6000000u) != 0 ||
                         ((*reinterpret_cast<const std::uint32_t*>(bytes + 0x274) &
                           0x1f7u) != 0);
    const bool render_ready = progress_high ||
                              (updated_flags & 0x8000000u) != 0;
    if (render_active) {
        updated_flags |= 2u;
    } else {
        updated_flags &= ~2u;
    }
    if (render_ready) {
        updated_flags |= 4u;
    } else {
        updated_flags &= ~4u;
    }
    *flags = updated_flags & ~0x80000000u;
}
// Partial semantic/byte-match reconstruction, JP Rev 1: 0x007236F0.
__attribute__((noinline)) void FontText_UpdateEffectTransition_007236F0(void* state) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(state);
    std::uint32_t* flags = reinterpret_cast<std::uint32_t*>(bytes + 0x270);
    static void* environment_cache;
    void* environment = environment_cache;
    if (environment == 0) {
        environment = Engine_LazySingletonGetter_0049BED0();
        environment_cache = environment;
    }
    bool advancing = false;
    bool update_secondary = false;
    int transition_id = 0;
    std::uint32_t transition_mode = 0;
    if (*reinterpret_cast<const std::uint8_t*>(
            static_cast<const std::uint8_t*>(environment) + 0xb0) != 0) {
        transition_id = FontText_EffectTransitionReady_002F1140();
        transition_mode = FontText_EffectTransitionMode_00A61A04(environment);
        if (transition_id != 0 && (*flags & 0x800000u) != 0) {
            advancing = true;
            update_secondary = transition_mode <= 10;
        }
    }
    if (transition_id != 0) {
        *reinterpret_cast<std::int32_t*>(bytes + 0x37c) = transition_id;
        *reinterpret_cast<std::uint32_t*>(bytes + 0x380) = transition_mode;
    }
    static void* status_cache;
    void* status = status_cache;
    if (status == 0) {
        status = Engine_GlobalTimingState_Get_0054EF64();
        status_cache = status;
    }
    const float dt = *reinterpret_cast<const float*>(
                         static_cast<const std::uint8_t*>(status) + 0xc) /
                     60.0f;
    const float step = dt * 6.0f * 1.6666666f;
    float transition = *reinterpret_cast<float*>(bytes + 0x384);
    if (advancing) {
        transition += step;
        if (transition > 1.0f) transition = 1.0f;
    } else {
        transition -= step;
        if (transition <= 0.0f) {
            transition = 0.0f;
            if ((*flags & 0x800000u) == 0) *flags &= ~0x1000000u;
        }
    }
    *reinterpret_cast<float*>(bytes + 0x384) = transition;
    float secondary = *reinterpret_cast<float*>(bytes + 0x388);
    if (update_secondary) {
        secondary += step;
        (void)Libm_Floorf_0049A940(transition);
        secondary = 0.0f;
    } else {
        secondary = 0.0f;
    }
    *reinterpret_cast<float*>(bytes + 0x388) = secondary;
}
// Semantic/byte-match reconstruction, JP Rev 1: 0x00723838.
__attribute__((noinline)) void FontText_ApplyRenderState_00723838(void* state, std::uint32_t enabled) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(state);
    std::uint32_t* flags = reinterpret_cast<std::uint32_t*>(bytes + 0x270);
    const std::uint32_t current = (*flags & 0x800000u) >> 23;
    if (enabled == current) return;
    std::uint32_t updated = *flags ^ 0x800000u;
    *flags = updated;
    if (enabled == 0 || (updated & 0x1000000u) != 0) return;
    *reinterpret_cast<std::uint32_t*>(bytes + 0x37c) = 0;
    *reinterpret_cast<std::uint32_t*>(bytes + 0x380) = 0;
    *flags = updated | 0x1000000u;
    *reinterpret_cast<float*>(bytes + 0x384) = 0.0f;
    *reinterpret_cast<float*>(bytes + 0x388) = 0.0f;
}
__attribute__((noinline)) static void FontText_UpdateGlyphRecords_0072B168(void* resource, float dt) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(resource);
    std::uint32_t* active_count = reinterpret_cast<std::uint32_t*>(bytes + 0x28);
    const std::uint32_t* group_masks = reinterpret_cast<const std::uint32_t*>(bytes + 0x2c);
    for (std::uint32_t group = 0; group < 2 && *active_count != 0; ++group) {
        std::uint32_t mask = group_masks[group];
        std::uint8_t* records = bytes + 0x34 + group * 0x500;
        for (std::uint32_t slot = 0; mask != 0 && *active_count != 0;
             ++slot, mask >>= 1) {
            if ((mask & 1u) == 0) continue;
            std::uint8_t* record = records + slot * 0x28;
            float progress = *reinterpret_cast<float*>(record + 0x04) +
                             *reinterpret_cast<const float*>(record + 0x08) * dt;
            if (progress < 1.0f) {
                *reinterpret_cast<float*>(record + 0x04) = progress;
                if ((*reinterpret_cast<const std::uint16_t*>(record + 0x02) & 1u) != 0) {
                    *reinterpret_cast<float*>(record + 0x10) +=
                        *reinterpret_cast<const float*>(record + 0x1c) * dt;
                    *reinterpret_cast<float*>(record + 0x14) +=
                        *reinterpret_cast<const float*>(record + 0x20) * dt;
                    float angle = *reinterpret_cast<float*>(record + 0x18) *
                                  0.1591549367f;
                    const float normalized = Libm_Floorf_0049A940(angle);
                    *reinterpret_cast<float*>(record + 0x18) =
                        (angle - normalized) * 6.2831855f;
                }
                continue;
            }
            const std::uint32_t bit = 1u << (slot & 31u);
            std::uint32_t* first_bitmap = reinterpret_cast<std::uint32_t*>(
                bytes + 0xa34 + group * 4);
            if ((*first_bitmap & bit) != 0) {
                *first_bitmap &= ~bit;
                --*active_count;
            }
            for (std::uint32_t bitmap = 1; bitmap < 5; ++bitmap) {
                std::uint32_t* word = reinterpret_cast<std::uint32_t*>(
                    bytes + 0xa34 + bitmap * 8 + group * 4);
                *word &= ~bit;
            }
        }
    }
}
__attribute__((noinline)) void FontText_UpdateGlyphAnimation_0072C060(void* resource, float dt) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(resource);
    if ((*reinterpret_cast<const std::uint32_t*>(bytes) & 2u) == 0 ||
        dt <= 0.0f) {
        return;
    }
    ++*reinterpret_cast<std::uint32_t*>(bytes + 0x14);
    FUN_0072AE84(resource);
    FontText_UpdateGlyphRecords_0072B168(resource, dt);
}
extern "C" void SinCosAngleUnits(float angle_units, float* out_sin,
                                    float* out_cos);
extern "C" void* RenderBatch_WriteQuadTexcoords_0092EB64(
    void* batch, float u0, float v0, float u1, float v1);
extern "C" std::uint32_t RenderBatch_FinalizePrimitive_0092F26C(
    void* batch, std::uint32_t command_index);
namespace {
template <typename T>
T& AnimatedField(void* object, std::uint32_t offset) {
    return *reinterpret_cast<T*>(static_cast<std::uint8_t*>(object) + offset);
}
static std::uint32_t AnimatedByte(float value) {
    return static_cast<std::uint32_t>(value) & 0xffu;
}
static std::uint32_t AnimatedColor(float red, float green, float blue,
                                   float alpha) {
    return AnimatedByte(red) | (AnimatedByte(green) << 8) |
           (AnimatedByte(blue) << 16) | (AnimatedByte(alpha) << 24);
}
struct AnimatedQuad {
    float half_width;
    float half_height;
    float u0;
    float v0;
    float u1;
    float v1;
    std::uint32_t color;
};
static AnimatedQuad MakeAnimatedQuad(std::uint32_t mode, float progress,
                                     float record_size) {
    const float half_size = record_size * 0.5f;
    AnimatedQuad quad = {half_size, half_size, 0.0f, 1.0f, 0.0f, 0.0f,
                         0xffffffffu};
    const float early = progress * 4.0f;
    const float late = (progress - 0.25f) * 1.33333337f;
    switch (mode) {
    case 0:
        if (progress < 0.25f) {
            quad.color = AnimatedColor(255.0f - early * 255.0f,
                25.0f + early * 230.0f, 255.0f - early * 64.0f,
                early * 255.0f);
        } else {
            quad.color = AnimatedColor(late * 191.0f,
                191.0f - late * 191.0f, 255.0f,
                255.0f - late * 230.0f);
        }
        quad.u1 = 0.25f + progress * 0.75f;
        quad.v1 = -1.0f;
        quad.half_width *= quad.u1;
        quad.half_height = quad.half_width;
        break;
    case 1:
        if (progress < 0.25f) {
            quad.color = AnimatedColor(255.0f - early * 255.0f,
                255.0f - early * 64.0f, early * 255.0f, 255.0f);
        } else {
            quad.color = AnimatedColor(late * 191.0f,
                191.0f - late * 191.0f, 255.0f, 255.0f);
        }
        quad.v0 = 1.0f - progress * 0.8f;
        quad.u1 = 1.0f;
        quad.half_width *= quad.v0;
        break;
    case 2: {
        std::uint32_t color;
        if (progress < 0.25f) {
            color = AnimatedColor(25.0f - early * 25.0f,
                51.0f - early * 26.0f, early * 51.0f, 0.0f);
        } else {
            color = AnimatedColor(25.0f - late * 25.0f,
                51.0f + late * 0.1f, late * 25.0f, 0.0f);
        }
        const float alpha = progress < 0.1f
            ? (0.1f + progress * 0.1f)
            : (-0.866666675f + (progress - 0.1f) * 7.0f);
        quad.color = color | (AnimatedByte(alpha * 255.0f) << 24);
        quad.u1 = 2.0f;
        quad.v1 = -1.0f;
        quad.half_width *= progress * (1.0f + progress);
        quad.half_height = quad.half_width;
        break;
    }
    case 3:
        if (progress < 0.25f) {
            quad.color = (AnimatedByte(153.0f + early * 0.8f) << 8) |
                         (AnimatedByte(255.0f - early * 255.0f) << 16);
        } else {
            quad.color = AnimatedColor(late * 255.0f,
                255.0f + late * 102.0f, late * 51.0f, 255.0f);
        }
        quad.v0 = 1.0f - progress * 0.8f;
        quad.u1 = 1.0f;
        quad.half_width *= quad.v0;
        break;
    case 4:
        quad.u1 = 2.0f;
        if (progress < 0.1f) {
            quad.half_width *= 0.5f - progress * 102.0f;
            // s3 remains the literal loaded by the less-than arm at 0072BC7C.
            quad.v1 = -102.0f;
        } else {
            quad.half_width *= 1.1f - progress;
            quad.v1 = record_size;
        }
        quad.half_height = quad.half_width;
        break;
    }
    return quad;
}
static void WriteAnimatedQuad(void* batch, const std::uint8_t* record,
                              const std::uint8_t* resource,
                              const AnimatedQuad& quad) {
    const std::uint16_t flags = *reinterpret_cast<const std::uint16_t*>(
        record + 2);
    const float* center = (flags & 2u) != 0
        ? reinterpret_cast<const float*>(resource + 0x20)
        : reinterpret_cast<const float*>(record + 0x10);
    std::uint8_t* vertex = AnimatedField<std::uint8_t*>(batch, 0x38);
    if ((flags & 1u) == 0) {
        const float left = center[0] - quad.half_width;
        const float top = center[1] - quad.half_height;
        const float right = left + quad.half_width * 2.0f;
        const float bottom = top + quad.half_height * 2.0f;
        const float xy[] = {left, top, right, top, left, bottom, right, bottom};
        for (std::uint32_t i = 0; i != 4; ++i) {
            *reinterpret_cast<float*>(vertex + i * 0x18) = xy[i * 2];
            *reinterpret_cast<float*>(vertex + i * 0x18 + 4) = xy[i * 2 + 1];
            *reinterpret_cast<float*>(vertex + i * 0x18 + 8) = 0.0f;
        }
    } else {
        float sine;
        float cosine;
        SinCosAngleUnits(*reinterpret_cast<const float*>(record + 0x18) * 5.0f,
                         &sine, &cosine);
        const float x_cos = cosine * quad.half_width;
        const float x_sin = sine * quad.half_width;
        const float y_cos = cosine * quad.half_height;
        const float y_sin = sine * quad.half_height;
        const float xy[] = {
            center[0] - x_cos + y_sin, center[1] - x_sin - y_cos,
            center[0] + x_cos + y_sin, center[1] + x_sin - y_cos,
            center[0] - x_cos - y_sin, center[1] - x_sin + y_cos,
            center[0] + x_cos - y_sin, center[1] + x_sin + y_cos,
        };
        for (std::uint32_t i = 0; i != 4; ++i) {
            *reinterpret_cast<float*>(vertex + i * 0x18) = xy[i * 2];
            *reinterpret_cast<float*>(vertex + i * 0x18 + 4) = xy[i * 2 + 1];
            *reinterpret_cast<float*>(vertex + i * 0x18 + 8) = 0.0f;
        }
    }
    RenderBatch_WriteQuadTexcoords_0092EB64(
        batch, quad.u0, quad.v0, quad.u1, quad.v1);
    for (std::uint32_t i = 0; i != 4; ++i)
        *reinterpret_cast<std::uint32_t*>(vertex + i * 0x18 + 0x0c) = quad.color;
    AnimatedField<std::uint8_t*>(batch, 0x38) = vertex + 0x60;
    ++AnimatedField<std::uint32_t>(batch, 0x3c);
}
static void FinalizeAnimatedMode(void* batch, const void* resource,
                                 std::uint32_t mode) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(batch);
    std::uint32_t* flags = reinterpret_cast<std::uint32_t*>(bytes + 0x50);
    *flags |= 0x100u;
    switch (mode) {
    case 0:
        *reinterpret_cast<std::uint32_t*>(bytes + 0xf8) = 0;
        *reinterpret_cast<std::uint32_t*>(bytes + 0xf4) =
            *reinterpret_cast<const std::uint32_t*>(
                static_cast<const std::uint8_t*>(resource) + 0x1c);
        *reinterpret_cast<std::uint32_t*>(bytes + 0xec) = 0x12;
        *reinterpret_cast<std::uint32_t*>(bytes + 0xf0) = 2;
        *reinterpret_cast<std::uint32_t*>(bytes + 0xe0) = 0x00ffffffu;
        *reinterpret_cast<std::uint32_t*>(bytes + 0xe4) = 0x00ffffffu;
        *flags |= 0x1b30u;
        break;
    case 1:
        *reinterpret_cast<std::uint32_t*>(bytes + 0xf8) = 7;
        *reinterpret_cast<std::uint32_t*>(bytes + 0xf4) =
            *reinterpret_cast<const std::uint32_t*>(
                static_cast<const std::uint8_t*>(resource) + 0x1c) + 2;
        *reinterpret_cast<std::uint32_t*>(bytes + 0xec) = 10;
        *reinterpret_cast<std::uint32_t*>(bytes + 0xf0) = 10;
        *reinterpret_cast<std::uint32_t*>(bytes + 0xe0) = 0x33ffffffu;
        *flags |= 0x1b10u;
        break;
    case 2:
        *reinterpret_cast<std::uint32_t*>(bytes + 0xf8) = 0;
        *reinterpret_cast<std::uint32_t*>(bytes + 0xf4) =
            *reinterpret_cast<const std::uint32_t*>(
                static_cast<const std::uint8_t*>(resource) + 0x1c);
        *reinterpret_cast<std::uint32_t*>(bytes + 0xec) = 0x12;
        *reinterpret_cast<std::uint32_t*>(bytes + 0xf0) = 2;
        *reinterpret_cast<std::uint32_t*>(bytes + 0xe0) = 0xccffffffu;
        *reinterpret_cast<std::uint32_t*>(bytes + 0xe4) = 0xccffffffu;
        *flags |= 0x1b30u;
        break;
    case 3:
        *reinterpret_cast<std::uint32_t*>(bytes + 0xf8) = 7;
        *reinterpret_cast<std::uint32_t*>(bytes + 0xf4) =
            *reinterpret_cast<const std::uint32_t*>(
                static_cast<const std::uint8_t*>(resource) + 0x1c) + 2;
        *reinterpret_cast<std::uint32_t*>(bytes + 0xec) = 11;
        *reinterpret_cast<std::uint32_t*>(bytes + 0xf0) = 10;
        *reinterpret_cast<std::uint32_t*>(bytes + 0xe0) = 0x33990000u;
        *flags |= 0x1b10u;
        break;
    default:
        *reinterpret_cast<std::uint32_t*>(bytes + 0xf8) = 7;
        *reinterpret_cast<std::uint32_t*>(bytes + 0xf4) =
            *reinterpret_cast<const std::uint32_t*>(
                static_cast<const std::uint8_t*>(resource) + 0x1c) + 1;
        *reinterpret_cast<std::uint32_t*>(bytes + 0xec) = 11;
        *reinterpret_cast<std::uint32_t*>(bytes + 0xf0) = 10;
        *reinterpret_cast<std::uint32_t*>(bytes + 0xe0) = 0x7fffbf00u;
        *flags |= 0x1b10u;
        break;
    }
    RenderBatch_FinalizePrimitive_0092F26C(batch, 0);
}
}  // namespace
extern "C" __attribute__((noinline)) void FontText_RenderAnimatedResource_0072B750(void* resource,
                                                           void* text) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(resource);
    std::int32_t remaining = *reinterpret_cast<const std::int32_t*>(bytes + 0x28);
    for (std::uint32_t mode = 0; mode != 5 && remaining > 0; ++mode) {
        std::uint32_t emitted = 0;
        for (std::uint32_t group = 0; group != 2 && remaining > 0; ++group) {
            std::uint32_t mask =
                *reinterpret_cast<const std::uint32_t*>(bytes + 0x2c + group * 4) &
                *reinterpret_cast<const std::uint32_t*>(bytes + 0xa34 + mode * 8 +
                                                         group * 4);
            std::uint8_t* records = bytes + 0x34 + group * 0x500;
            for (std::uint32_t slot = 0; mask != 0 && remaining > 0;
                 ++slot, mask >>= 1) {
                if ((mask & 1u) == 0) continue;
                const std::uint8_t* record = records + slot * 0x28;
                const AnimatedQuad quad = MakeAnimatedQuad(
                    mode, *reinterpret_cast<const float*>(record + 4),
                    *reinterpret_cast<const float*>(record + 0xc));
                WriteAnimatedQuad(text, record, bytes, quad);
                --remaining;
                ++emitted;
            }
        }
        if (emitted != 0) FinalizeAnimatedMode(text, resource, mode);
    }
}
// Semantic/byte-match reconstruction, JP Rev 1: 0x00722520.
__attribute__((noinline)) void FontText_MarkLayoutMode_00722520(void* state) {
    std::uint32_t* flags = reinterpret_cast<std::uint32_t*>(
        static_cast<std::uint8_t*>(state) + 0x270);
    *flags |= 0x2000u;
}
// Semantic/byte-match reconstruction, JP Rev 1: 0x007228AC.
__attribute__((noinline)) std::uint32_t FontText_IsLayoutModeActive_007228AC(const void* state) {
    const std::uint32_t* flags = reinterpret_cast<const std::uint32_t*>(
        static_cast<const std::uint8_t*>(state) + 0x270);
    return (*flags >> 12) & 1u;
}
// Semantic/byte-match reconstruction, JP Rev 1: 0x007236E0.
__attribute__((noinline)) void FontText_ClearLayoutFlags_007236E0(void* state) {
    std::uint32_t* flags = reinterpret_cast<std::uint32_t*>(
        static_cast<std::uint8_t*>(state) + 0x274);
    *flags &= ~0x1c0u;
}

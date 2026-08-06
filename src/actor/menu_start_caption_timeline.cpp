#include <cstdint>
extern "C" void* DAT_00323DA4;
extern "C" void StateParameterRecord_Init_003B530C(
    std::uint32_t* record);
extern "C" void Actor_PlayActionByHash(
    void* actor, int channel, std::uint32_t* record, int mode, int flags);
extern "C" void MenuStartActor_UpdateSecondary_00323074(void* object);
extern "C" void ParameterString_Format_002F2598(
    void* output, const std::uint16_t* format, ...);
extern "C" int ParameterString_Format_002B3F78(
    void* output, std::uint32_t size, const char* format, ...);
extern "C" void* GetEngineSingleton_003B6CF0();
extern "C" void MenuStart_RegisterEntryCountParameter_00370C70(
    void* object, std::uint32_t count);
extern "C" __attribute__((noinline)) std::int32_t
MenuEntryCount_SelectThresholdBand_002A1E00(
    void* engine, std::int32_t count);
extern "C" std::uint32_t ResourceTree_KeyGetter_002A18B8();
extern "C" void ResourceParameter_RegisterPair_002EC6FC(
    void* resource, std::uint32_t handle, const void* name,
    const void* source, const void* target, std::int32_t mode);
extern void* g_CachedEngineSingleton_00D6365C;
namespace {
template <typename T>
T& At(void* object, std::uint32_t offset) {
    return *reinterpret_cast<T*>(
        static_cast<std::uint8_t*>(object) + offset);
}
struct CaptionNode {
    std::uint8_t* value;
    CaptionNode* next;
};
struct ResourceNode {
    void* payload;
    std::uint32_t reserved;
    ResourceNode* left;
    ResourceNode* right;
    std::uint8_t active;
    std::uint8_t padding[3];
    std::uint32_t key;
};
std::uint8_t* CaptionAt(void* object, std::uint32_t index) {
    std::uint8_t* resource = At<std::uint8_t*>(object, 0x34);
    if (resource == 0) {
        return 0;
    }
    CaptionNode* node = At<CaptionNode*>(resource, 0x14c);
    std::uint8_t* sentinel = At<std::uint8_t*>(resource, 0x148);
    for (std::uint32_t current = 0; node->value != sentinel;
         ++current, node = node->next) {
        if (current == index) {
            return node->value;
        }
    }
    return 0;
}
}  // namespace
extern "C" __attribute__((noinline)) std::int64_t
MenuTimeline_GetFrame_00350580(void* clock) {
    if (At<std::uint8_t>(clock, 0x15) == 0) {
        return 0;
    }
    return At<std::int64_t>(At<void*>(clock, 0), 0x218);
}
extern "C" __attribute__((noinline)) void MenuStartCaptionTimeline_SelectNext_00350014(void* object) {
    std::uint32_t position = At<std::uint32_t>(object, 0x90);
    At<std::uint8_t*>(object, 0x80) = CaptionAt(object, position);
    if (At<std::uint8_t*>(object, 0x80) == 0) {
        At<std::uint8_t>(object, 0x89) = 1;
    }
    ++position;
    At<std::uint8_t*>(object, 0x84) = CaptionAt(object, position);
    At<std::uint8_t>(object, 0x8a) = 0;
    At<std::uint8_t>(object, 0x88) = 0;
}
extern "C" __attribute__((noinline)) void MenuStartCaptionTimeline_Update_00323C10(void* object) {
    const std::int64_t frame = MenuTimeline_GetFrame_00350580(DAT_00323DA4);
    const std::int64_t previous = At<std::int64_t>(object, 0x98);
    if (frame < previous) {
        At<std::uint8_t>(DAT_00323DA4, 0x17) = 1;
        At<std::uint8_t>(object, 0x89) = 0;
        At<void*>(At<void*>(object, 0xa4), 0x0c) = 0;
        At<std::uint32_t>(object, 0x90) = 0;
        MenuStartCaptionTimeline_SelectNext_00350014(object);
    }
    std::uint8_t* current = At<std::uint8_t*>(object, 0x80);
    if (frame >= 0 && current != 0) {
        const std::uint32_t lane = At<std::uint32_t>(object, 0x8c);
        if (At<std::uint8_t>(object, 0x89) == 0 &&
            At<std::uint8_t>(object, 0x88) == 0) {
            const std::int32_t start = At<std::int32_t>(current, 0x10 + lane * 4);
            if (frame > start) {
                void* actor = At<void*>(object, 0xa0);
                char* action_name = At<char*>(current, 0x24);
                if (actor != 0 && action_name[0] != '\0' &&
                    At<std::uint8_t>(object, 0x8a) == 0) {
                    std::uint32_t storage[3];
                    StateParameterRecord_Init_003B530C(storage);
                    std::uint32_t* const record = storage;
                    record[0] = At<std::uint32_t>(current, 0x20);
                    record[1] =
                        reinterpret_cast<std::uint32_t>(action_name);
                    Actor_PlayActionByHash(actor, 0x14, record, 1, 1);
                    At<std::uint8_t>(object, 0x8a) = 1;
                }
                std::uint8_t* output = At<std::uint8_t*>(object, 0xa4);
                char* text_label = At<char*>(current, 0x50);
                if (output != 0 && text_label[0] != '\0') {
                    At<char*>(output, 0x0c) = text_label;
                }
                At<std::uint8_t>(object, 0x88) = 1;
            }
        } else {
            const std::int32_t end = At<std::int32_t>(current, 0x18 + lane * 4);
            if (end < 0 || frame < end) {
                std::uint8_t* next = At<std::uint8_t*>(object, 0x84);
                if (next != 0) {
                    const std::int32_t next_start =
                        At<std::int32_t>(next, 0x10 + lane * 4);
                    if (frame >= next_start) {
                        MenuStartCaptionTimeline_SelectNext_00350014(object);
                    }
                }
            } else {
                At<void*>(At<void*>(object, 0xa4), 0x0c) = 0;
                MenuStartCaptionTimeline_SelectNext_00350014(object);
            }
        }
    }
    At<std::int64_t>(object, 0x98) = frame;
}
extern "C" __attribute__((noinline)) std::uint32_t MenuStartActor_Update_002EFB44(void* object) {
    MenuStartCaptionTimeline_Update_00323C10(object);
    MenuStartActor_UpdateSecondary_00323074(object);
    return 0;
}
extern "C" __attribute__((noinline)) void MenuStart_UpdateDynamicSelectionVisibility_00370A64(
    void* object, std::int32_t selection) {
        std::uint8_t* first = static_cast<std::uint8_t*>(At<void*>(object, 0x124));
        std::uint32_t first_flags = At<std::uint32_t>(first, 0xc0);
    if (selection < 0) {
        first_flags &= ~std::uint32_t(2);
        first_flags |= 0x2000;
        At<std::uint32_t>(first, 0xc0) = first_flags;
        std::uint8_t* second = static_cast<std::uint8_t*>(At<void*>(object, 0x128));
        std::uint32_t second_flags = At<std::uint32_t>(second, 0xc0);
        second_flags &= ~std::uint32_t(2);
        second_flags |= 0x2000;
        At<std::uint32_t>(second, 0xc0) = second_flags;
        std::uint8_t* third = static_cast<std::uint8_t*>(At<void*>(object, 0x12c));
        std::uint32_t third_flags = At<std::uint32_t>(third, 0xc0);
        third_flags &= ~std::uint32_t(2);
        third_flags |= 0x2000;
        At<std::uint32_t>(third, 0xc0) = third_flags;
        return;
    }
    if (At<std::int32_t>(object, 0xc8) == 0) {
        first_flags &= ~std::uint32_t(2);
    } else {
        first_flags |= 2;
    }
    first_flags |= 0x2000;
    At<std::uint32_t>(first, 0xc0) = first_flags;
    At<std::uint32_t>(first, 0xc0) = first_flags;
    std::uint8_t* second = static_cast<std::uint8_t*>(At<void*>(object, 0x128));
    std::uint32_t second_flags = At<std::uint32_t>(second, 0xc0);
    if (At<std::int32_t>(object, 0xc8) == 1) {
        second_flags &= ~std::uint32_t(2);
    } else {
        second_flags |= 2;
    }
    second_flags |= 0x2000;
    At<std::uint32_t>(second, 0xc0) = second_flags;
    std::uint8_t* third = static_cast<std::uint8_t*>(At<void*>(object, 0x12c));
    std::uint32_t third_flags = At<std::uint32_t>(third, 0xc0);
    if (At<std::int32_t>(object, 0xc8) == 2) {
        third_flags &= ~std::uint32_t(2);
    } else {
        third_flags |= 2;
    }
    third_flags |= 0x2000;
    At<std::uint32_t>(third, 0xc0) = third_flags;
}
extern "C" __attribute__((noinline)) void MenuStart_UpdateEntryCountPresentation_00370B68(
    void* object, std::int32_t count) {
    if (count < 0) {
        count = 0;
    }
    std::int32_t level = 2;
    std::uint8_t* first = static_cast<std::uint8_t*>(At<void*>(object, 0x130));
    std::uint32_t first_flags = At<std::uint32_t>(first, 0xc0);
    if (count == 0) {
        level = -1;
        first_flags |= 2;
    } else {
        if (count < 10) {
            level = 0;
        } else if (count < 20) {
            level = 1;
        }
        first_flags &= ~std::uint32_t(2);
    }
    first_flags |= 0x2000;
    std::uint8_t* second = static_cast<std::uint8_t*>(At<void*>(object, 0x134));
    std::uint32_t second_flags = At<std::uint32_t>(second, 0xc0);
    second_flags = level < 1 ? second_flags | 2 : second_flags & ~2u;
    second_flags |= 0x2000;
    At<std::uint32_t>(second, 0xc0) = second_flags;
    std::uint8_t* third = static_cast<std::uint8_t*>(At<void*>(object, 0x138));
    std::uint32_t third_flags = At<std::uint32_t>(third, 0xc0);
    third_flags = level < 2 ? third_flags | 2 : third_flags & ~2u;
    third_flags |= 0x2000;
    At<std::uint32_t>(third, 0xc0) = third_flags;
    std::uint8_t* text = static_cast<std::uint8_t*>(object) + 0xdc;
    // u"..." is a C++11 UTF-16 literal; spell the code units out for C++03.
    static const std::uint16_t kPercentD[] = {'%', 'd', 0};
    ParameterString_Format_002F2598(text, kPercentD, count);
    std::uint8_t* output = static_cast<std::uint8_t*>(At<void*>(object, 0x13c));
    output[0x24] |= 8;
    At<void*>(output, 0x0c) = 0;
    At<void*>(output, 0x10) = text;
    output[0x24] = (output[0x24] & ~std::uint8_t(1)) | 2;
}
extern "C" __attribute__((noinline)) void ResourceRecord_Finalize_003500C0(void* object) {
    std::uint8_t* resource = At<std::uint8_t*>(object, 0x34);
    const std::uint32_t previous = At<std::uint32_t>(object, 0xb0);
    if (g_CachedEngineSingleton_00D6365C == 0) {
        g_CachedEngineSingleton_00D6365C = GetEngineSingleton_003B6CF0();
    }
    std::uint8_t* engine = static_cast<std::uint8_t*>(
        g_CachedEngineSingleton_00D6365C);
    std::uint32_t count = 0;
    for (std::uint32_t index = 0; index < 99; ++index) {
        if (engine[0x730 + index * 0xec] != 0) {
            ++count;
        }
    }
    count &= 0xff;
    At<std::uint32_t>(object, 0xb0) = count;
    void* first_actor = At<void*>(object, 0x11c);
    void* second_actor = At<void*>(object, 0x120);
    if (At<std::int32_t>(object, 0xc4) < 0 || first_actor == 0 ||
        second_actor == 0 || previous >= count) {
        return;
    }
    if (previous < 1) {
        std::uint32_t storage[3];
        StateParameterRecord_Init_003B530C(storage);
        std::uint32_t* const record = storage;
        record[0] = At<std::uint32_t>(resource, 0x154);
        record[1] = At<std::uint32_t>(resource, 0x158);
        Actor_PlayActionByHash(first_actor, 0x14, record, 1, 1);
        StateParameterRecord_Init_003B530C(storage);
        record[0] = At<std::uint32_t>(resource, 0x154);
        record[1] = At<std::uint32_t>(resource, 0x158);
        Actor_PlayActionByHash(second_actor, 0x14, record, 1, 1);
    }
    MenuStart_RegisterEntryCountParameter_00370C70(object, count);
    MenuStart_UpdateEntryCountPresentation_00370B68(object, count);
}
extern "C" __attribute__((noinline)) void MenuStart_RegisterEntryCountParameter_00370C70(
    void* object, std::uint32_t count) {
    if (g_CachedEngineSingleton_00D6365C == 0) {
        g_CachedEngineSingleton_00D6365C = GetEngineSingleton_003B6CF0();
    }
    const std::int32_t band = MenuEntryCount_SelectThresholdBand_002A1E00(
        g_CachedEngineSingleton_00D6365C, count);
    char target[0x80];
    ParameterString_Format_002B3F78(
        target, sizeof(target), "StDynamic_000%02d", band + 1);
    std::uint8_t* actor = At<std::uint8_t*>(object, 0x120);
    const std::uint32_t key = ResourceTree_KeyGetter_002A18B8();
    ResourceNode* sentinel = reinterpret_cast<ResourceNode*>(actor + 0x1a8);
    ResourceNode* node = At<ResourceNode*>(actor, 0x1ac);
    ResourceNode* selected = sentinel;
    while (node->active != 0) {
        if (node->key < key) {
            node = node->right;
        } else {
            selected = node;
            node = node->left;
        }
    }
    if (selected == sentinel || selected->key <= key) {
        selected = sentinel;
    }
    void* payload = selected == 0 ? 0 : selected->payload;
    if (selected == 0 || payload == sentinel->payload) {
        payload = 0;
    }
    ResourceParameter_RegisterPair_002EC6FC(
        At<void*>(payload, 0x20), reinterpret_cast<std::uint32_t>(actor),
        "Dynamic_00", "StDynamic000000", target, 1);
}
extern "C" __attribute__((noinline)) std::int32_t
MenuEntryCount_SelectThresholdBand_002A1E00(
    void* engine, std::int32_t count) {
    (void)engine;
    static const std::int32_t thresholds[9] = {
        0, 2, 4, 5, 12, 19, 29, 39, 50,
    };
    for (std::int32_t index = 0; index < 9; ++index) {
        if (count <= thresholds[index]) {
            return index;
        }
    }
    return 8;
}

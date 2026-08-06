#include <cstddef>
#include <stdint.h>
#include <cmath>
#if defined(__CC_ARM)
#define KIU_FORCE_INLINE __forceinline
#else
#define KIU_FORCE_INLINE inline __attribute__((always_inline))
#endif
extern "C" uint32_t gAnimationChannelSentinel_00CB0350;
extern "C" const float gAnimationTrigTable_00CAF18C[][4];
extern "C" float AnimationController_EvaluateListScale_00B498B4(void* list);
extern "C" float AnimationCurve_Evaluate_005642F8(
    const void* curve, float frame);
extern "C" uint32_t Color_QuantizeFloat4ToRGBA_002F1AD8(
    const float* color);
extern "C" void RelativeParameterRecord_ResolvePair_002A3CF0(
    void* output, void* const* source);
extern "C" void RelativePointerRecord_Assign_003AC8F4(
    void* destination, void* source);
extern "C" void SinCosAngleUnits(
    float angle_units, float* sine, float* cosine);
extern "C" void TransformRecord_NormalizeFlags_008E63F4(void* record);
extern "C" void TransformRecord_UpdateIdentityRotationFlag_008E62F0(
    void* record);
extern "C" void TransformRecord_UpdateZeroTranslationFlag_008E6428(
    void* record);
extern "C" void TransformRecord_BuildEulerAffine_008E65BC(
    void* record, const float* rotation, const float* translation);
extern "C" void FUN_00B3F898(
    void* animation, void* destination, void* element, void* sample,
    int mode, float frame);
extern "C" void FUN_0044C05C(
    void* destination, const void* data);
extern "C" uint32_t ByteString_Length_00425CAC(const char* text);
extern "C" void* ParameterString_FindNode_00498FBC(
    const void* root, const char* text, uint32_t length);
extern "C" int AnimationChrInner_MaterializeRecords_008ED190(
    void* inner, void* target_buffer, void* source_records);
extern "C" bool once_guard_primitive(uint32_t* guard);
extern "C" uint32_t gIdentityMatrixGuard_00D618C4;
extern "C" uint32_t gIdentityTransformGuard_00D618D0;
extern "C" uint8_t gIdentityMatrix_00E125F4[];
extern "C" uint8_t gIdentityTransform_00E1267C[];
extern "C" void* TransformRecord_GetIdentity_008E6938();
extern "C" void Skeleton_ComposeChildTransform_00B3E4A4(
    int mode, void* output, float* output_scale, void* child,
    void* parent_world, void* parent_local);
extern "C" void Skeleton_ComposeChildTransformAlternate_00B3E820(
    int mode, void* output, float* output_scale, void* child,
    void* parent_world, void* parent_local);
extern "C" void Skeleton_ComposeChildTransformMode2_00B3E30C(
    int mode, void* output, float* output_scale, void* child,
    void* parent_world, void* parent_local);
namespace {
struct SkeletalAnimationInner {
    void** vtable;
    uint8_t unknown_04[4];
    uint8_t* resource;
    uint8_t unknown_0c[8];
    uint32_t* channel_map;
    uint8_t unknown_18[0x3c];
    void* apply_source;
    uint8_t apply_pending;
    uint8_t unknown_59[0x0b];
    uint8_t* target_base;
    void* previous_target_base;
};
struct TransformRecord {
    float affine[12];
    float scale[3];
    uint32_t flags;
};
struct Matrix3x4 {
    float values[12];
};
struct TransformModifierRecord {
    uint32_t flags;
    uint32_t channel_index;
    uint32_t target_index;
    float scale[3];
    Matrix3x4 transform;
};
struct IndexArray {
    void* allocator;
    uint32_t* begin;
    uint32_t* end;
    uint32_t capacity_flags;
};
struct AnimationChrController {
    void** vtable;
    uint8_t unknown_04[0x58];
    SkeletalAnimationInner* inner;
    uint32_t animation_key;
    uint8_t unknown_64[4];
    float frame;
    int slot_index;
    uint8_t* slot_owner;
};
struct AnimationChrSlotOwner {
    void** vtable;
    uint8_t unknown_04[0x44];
    uint32_t* active_mask_begin;
    uint32_t* active_mask_end;
    uint8_t unknown_50[4];
    int slot_count;
};
typedef char AssertSkeletalResource[
    offsetof(SkeletalAnimationInner, resource) == 0x08 ? 1 : -1];
typedef char AssertSkeletalChannelMap[
    offsetof(SkeletalAnimationInner, channel_map) == 0x14 ? 1 : -1];
typedef char AssertSkeletalApplySource[
    offsetof(SkeletalAnimationInner, apply_source) == 0x54 ? 1 : -1];
typedef char AssertSkeletalApplyPending[
    offsetof(SkeletalAnimationInner, apply_pending) == 0x58 ? 1 : -1];
typedef char AssertSkeletalTargetBase[
    offsetof(SkeletalAnimationInner, target_base) == 0x64 ? 1 : -1];
typedef char AssertSkeletalPreviousTargetBase[
    offsetof(SkeletalAnimationInner, previous_target_base) == 0x68 ? 1 : -1];
typedef char AssertTransformFlags[
    offsetof(TransformRecord, flags) == 0x3c ? 1 : -1];
typedef char AssertTransformModifierSize[
    sizeof(TransformModifierRecord) == 0x48 ? 1 : -1];
typedef char AssertChrControllerInner[
    offsetof(AnimationChrController, inner) == 0x5c ? 1 : -1];
typedef char AssertChrControllerSlotIndex[
    offsetof(AnimationChrController, slot_index) == 0x6c ? 1 : -1];
typedef char AssertChrControllerSlotOwner[
    offsetof(AnimationChrController, slot_owner) == 0x70 ? 1 : -1];
typedef char AssertChrSlotOwnerMaskBegin[
    offsetof(AnimationChrSlotOwner, active_mask_begin) == 0x48 ? 1 : -1];
typedef char AssertChrSlotOwnerSlotCount[
    offsetof(AnimationChrSlotOwner, slot_count) == 0x54 ? 1 : -1];
extern "C" __attribute__((noinline)) void Matrix3x4_Copy_0044C0A0(
    void* destination, const void* source) {
    if (destination == source)
        return;
    {
        const float* input = static_cast<const float*>(source);
        const float a0 = input[0];
        const float a1 = input[1];
        const float a2 = input[2];
        const float a3 = input[3];
        const float a4 = input[4];
        const float a5 = input[5];
        const float a6 = input[6];
        const float a7 = input[7];
        const float a8 = input[8];
        const float a9 = input[9];
        const float a10 = input[10];
        const float a11 = input[11];
        float* output = static_cast<float*>(destination);
        output[0] = a0;
        output[1] = a1;
        output[2] = a2;
        output[3] = a3;
        output[4] = a4;
        output[5] = a5;
        output[6] = a6;
        output[7] = a7;
        output[8] = a8;
        output[9] = a9;
        output[10] = a10;
        output[11] = a11;
    }
}
extern "C" __attribute__((noinline)) void
Matrix3x4_ApplyColumnScale_00550948(
    void* destination, const void* source, const float* scale) {
    const float* input = static_cast<const float*>(source);
    const float a0 = input[0];
    const float a1 = input[1];
    const float a2 = input[2];
    const float a3 = input[3];
    const float a4 = input[4];
    const float a5 = input[5];
    const float a6 = input[6];
    const float a7 = input[7];
    const float a8 = input[8];
    const float a9 = input[9];
    const float a10 = input[10];
    const float a11 = input[11];
    const float sx = scale[0];
    const float sy = scale[1];
    const float sz = scale[2];
    Matrix3x4& output = *static_cast<Matrix3x4*>(destination);
    output.values[0] = a0 * sx;
    output.values[1] = a1 * sy;
    output.values[2] = a2 * sz;
    output.values[3] = a3;
    output.values[4] = a4 * sx;
    output.values[5] = a5 * sy;
    output.values[6] = a6 * sz;
    output.values[7] = a7;
    output.values[8] = a8 * sx;
    output.values[9] = a9 * sy;
    output.values[10] = a10 * sz;
    output.values[11] = a11;
}
extern "C" __attribute__((noinline)) void
Matrix3x3_TransformVector_005E140C(
    float* destination, const float* matrix, const float* vector) {
    const float x = vector[0];
    const float y = vector[1];
    const float z = vector[2];
    float row0 = matrix[0] * x;
    float row1 = matrix[3] * x;
    float row2 = matrix[6] * x;
    row0 += matrix[1] * y;
    row1 += matrix[4] * y;
    row2 += matrix[7] * y;
    row0 += matrix[2] * z;
    row1 += matrix[5] * z;
    row2 += matrix[8] * z;
    destination[0] = row0;
    destination[1] = row1;
    destination[2] = row2;
}
extern "C" __attribute__((noinline)) void
Matrix3x4_AddTransformedTranslation_005E1558(
    void* destination, const void* source, const float* translation) {
    const float* input = static_cast<const float*>(source);
    const float a0 = input[0];
    const float a1 = input[1];
    const float a2 = input[2];
    const float a3 = input[3];
    const float a4 = input[4];
    const float a5 = input[5];
    const float a6 = input[6];
    const float a7 = input[7];
    const float a8 = input[8];
    const float a9 = input[9];
    const float a10 = input[10];
    const float a11 = input[11];
    const float tx = translation[0];
    const float ty = translation[1];
    const float tz = translation[2];
    Matrix3x4 result;
    result.values[0] = a0;
    result.values[1] = a1;
    result.values[2] = a2;
    result.values[3] = a3 + a0 * tx + a1 * ty + a2 * tz;
    result.values[4] = a4;
    result.values[5] = a5;
    result.values[6] = a6;
    result.values[7] = a7 + a4 * tx + a5 * ty + a6 * tz;
    result.values[8] = a8;
    result.values[9] = a9;
    result.values[10] = a10;
    result.values[11] = a11 + a8 * tx + a9 * ty + a10 * tz;
    *static_cast<Matrix3x4*>(destination) = result;
}
struct BasisRow {
    float x;
    float y;
    float z;
};
extern "C" __attribute__((noinline)) void Matrix3x4_ExtractBasis_005E158C(
    float* destination, const void* source) {
    const volatile float* input = static_cast<const volatile float*>(source);
    const float m00 = input[0];
    const float m01 = input[1];
    const float m02 = input[2];
    const float m10 = input[4];
    const float m11 = input[5];
    const float m12 = input[6];
    const float m20 = input[8];
    const float m21 = input[9];
    const float m22 = input[10];
    const float unused03 = input[3];
    const float unused07 = input[7];
    const float unused11 = input[11];
    (void)unused03;
    (void)unused07;
    (void)unused11;
    destination[0] = m00;
    destination[1] = m01;
    destination[2] = m02;
    destination[3] = m10;
    destination[4] = m11;
    destination[5] = m12;
    destination[6] = m20;
    destination[7] = m21;
    destination[8] = m22;
}
KIU_FORCE_INLINE void sample_animation_trig(
    float angle, float& sine, float& cosine) {
    float units = angle * 40.7436637878418f;
    const bool negative = units < 0.0f;
    if (negative)
        units = -units;
    while (units >= 65536.0f)
        units -= 65536.0f;
    const uint32_t whole = static_cast<uint32_t>(units);
    const float fraction = units - static_cast<float>(whole);
    const float* sample = gAnimationTrigTable_00CAF18C[whole & 0xff];
    sine = sample[0] + fraction * sample[2];
    cosine = sample[1] + fraction * sample[3];
    if (negative)
        sine = -sine;
}
KIU_FORCE_INLINE void build_modifier_affine(
    Matrix3x4& output, const float* rotation, const float* translation) {
    float sx, cx, sy, cy, sz, cz;
    SinCosAngleUnits(rotation[0] * 40.7436637878418f, &sx, &cx);
    SinCosAngleUnits(rotation[1] * 40.7436637878418f, &sy, &cy);
    SinCosAngleUnits(rotation[2] * 40.7436637878418f, &sz, &cz);
    output.values[0] = cz * cy;
    output.values[1] = sx * cz * sy - cx * sz;
    output.values[2] = sx * sz + cx * cz * sy;
    output.values[3] = translation[0];
    output.values[4] = sz * cy;
    output.values[5] = cx * cz + sx * sz * sy;
    output.values[6] = cx * sz * sy - sx * cz;
    output.values[7] = translation[1];
    output.values[8] = -sy;
    output.values[9] = sx * cy;
    output.values[10] = cx * cy;
    output.values[11] = translation[2];
}
KIU_FORCE_INLINE void compose_affine(
    Matrix3x4& output, const Matrix3x4& left, const Matrix3x4& right) {
    for (uint32_t row = 0; row < 3; ++row) {
        const uint32_t base = row * 4;
        for (uint32_t column = 0; column < 3; ++column) {
            output.values[base + column] =
                left.values[base] * right.values[column] +
                left.values[base + 1] * right.values[4 + column] +
                left.values[base + 2] * right.values[8 + column];
        }
        output.values[base + 3] =
            left.values[base] * right.values[3] +
            left.values[base + 1] * right.values[7] +
            left.values[base + 2] * right.values[11] +
            left.values[base + 3];
    }
}
extern "C" __attribute__((noinline)) void Matrix3x4_Multiply_002A6BDC(
    void* destination, const void* left, const void* right) {
    const float* a = static_cast<const float*>(left);
    const float* b = static_cast<const float*>(right);
    const float a3 = a[3];
    const float a7 = a[7];
    const float a11 = a[11];
    const float b0 = b[0];
    const float b1 = b[1];
    const float b2 = b[2];
    const float b3 = b[3];
    const float a0 = a[0];
    const float a4 = a[4];
    float o0 = b0 * a0;
    float o1 = b1 * a0;
    float o2 = b2 * a0;
    float o3 = b3 * a0 + a3;
    const float a8 = a[8];
    float o4 = b0 * a4;
    float o5 = b1 * a4;
    float o6 = b2 * a4;
    float o7 = b3 * a4 + a7;
    float o8 = b0 * a8;
    float o9 = b1 * a8;
    float o10 = b2 * a8;
    float o11 = b3 * a8 + a11;
    const float b4 = b[4];
    const float b5 = b[5];
    const float b6 = b[6];
    const float b7 = b[7];
    const float a1 = a[1];
    o0 += b4 * a1;
    o1 += b5 * a1;
    o2 += b6 * a1;
    o3 += b7 * a1;
    const float a5 = a[5];
    o4 += b4 * a5;
    o5 += b5 * a5;
    o6 += b6 * a5;
    o7 += b7 * a5;
    const float a9 = a[9];
    o8 += b4 * a9;
    o9 += b5 * a9;
    o10 += b6 * a9;
    o11 += b7 * a9;
    const float b8 = b[8];
    const float b9 = b[9];
    const float b10 = b[10];
    const float b11 = b[11];
    const float a2 = a[2];
    o0 += b8 * a2;
    o1 += b9 * a2;
    o2 += b10 * a2;
    o3 += b11 * a2;
    const float a6 = a[6];
    o4 += b8 * a6;
    o5 += b9 * a6;
    o6 += b10 * a6;
    o7 += b11 * a6;
    const float a10 = a[10];
    o8 += b8 * a10;
    o9 += b9 * a10;
    o10 += b10 * a10;
    o11 += b11 * a10;
    float* output = static_cast<float*>(destination);
    output[0] = o0;
    output[1] = o1;
    output[2] = o2;
    output[3] = o3;
    output[4] = o4;
    output[5] = o5;
    output[6] = o6;
    output[7] = o7;
    output[8] = o8;
    output[9] = o9;
    output[10] = o10;
    output[11] = o11;
}
extern "C" __attribute__((noinline)) void
Matrix3x3_MultiplyPreserveTranslation_00BA59D4(
    void* destination, const void* left, const void* right) {
    const float* a = static_cast<const float*>(left);
    const float* b = static_cast<const float*>(right);
    const float a0 = a[0];
    const float a1 = a[1];
    const float a2 = a[2];
    const float a4 = a[4];
    const float a5 = a[5];
    const float a6 = a[6];
    const float a8 = a[8];
    const float a9 = a[9];
    const float a10 = a[10];
    const float b0 = b[0];
    const float b1 = b[1];
    const float b2 = b[2];
    const float b4 = b[4];
    const float b5 = b[5];
    const float b6 = b[6];
    const float b8 = b[8];
    const float b9 = b[9];
    const float b10 = b[10];
    float* output = static_cast<float*>(destination);
    output[0] = b0 * a0 + b4 * a1 + b8 * a2;
    output[1] = b1 * a0 + b5 * a1 + b9 * a2;
    output[2] = b2 * a0 + b6 * a1 + b10 * a2;
    output[4] = b0 * a4 + b4 * a5 + b8 * a6;
    output[5] = b1 * a4 + b5 * a5 + b9 * a6;
    output[6] = b2 * a4 + b6 * a5 + b10 * a6;
    output[8] = b0 * a8 + b4 * a9 + b8 * a10;
    output[9] = b1 * a8 + b5 * a9 + b9 * a10;
    output[10] = b2 * a8 + b6 * a9 + b10 * a10;
}
extern "C" __attribute__((noinline)) void* TransformRecord_GetIdentity_008E6938() {
    TransformRecord* record = reinterpret_cast<TransformRecord*>(
        gIdentityTransform_00E1267C);
    if ((gIdentityTransformGuard_00D618D0 & 1u) == 0 &&
        once_guard_primitive(&gIdentityTransformGuard_00D618D0)) {
        Matrix3x4* identity = reinterpret_cast<Matrix3x4*>(
            gIdentityMatrix_00E125F4);
        if ((gIdentityMatrixGuard_00D618C4 & 1u) == 0 &&
            once_guard_primitive(&gIdentityMatrixGuard_00D618C4)) {
            for (int lane = 0; lane < 12; ++lane)
                identity->values[lane] = 0.0f;
            identity->values[0] = 1.0f;
            identity->values[5] = 1.0f;
            identity->values[10] = 1.0f;
        }
        Matrix3x4_Copy_0044C0A0(record, identity);
        record->scale[0] = 1.0f;
        record->scale[1] = 1.0f;
        record->scale[2] = 1.0f;
        record->flags = 0x7e1u;
    }
    return record;
}
KIU_FORCE_INLINE float sample_transform_component(
    const uint8_t* channel, uint32_t slot,
    uint32_t inline_flag, float frame) {
    if ((*reinterpret_cast<const uint32_t*>(channel) & inline_flag) != 0)
        return *reinterpret_cast<const float*>(channel + slot);
    const uint8_t* field = channel + slot;
    const int32_t offset =
        *reinterpret_cast<const int32_t*>(field);
    return AnimationCurve_Evaluate_005642F8(
        offset == 0 ? 0 : field + offset, frame);
}
KIU_FORCE_INLINE uint32_t float_bits(float value) {
    union {
        float as_float;
        uint32_t as_uint;
    } bits;
    bits.as_float = value;
    return bits.as_uint;
}
KIU_FORCE_INLINE uint32_t pack_animation_slope(float value) {
    const uint32_t bits = float_bits(value);
    const uint32_t sign =
        (bits & 0x80000000u) != 0 ? 0x80000u : 0;
    const uint32_t magnitude = bits & 0x7fffffffu;
    if (magnitude == 0)
        return sign;
    const int exponent = static_cast<int>(magnitude >> 23) - 0x40;
    if (exponent < 0)
        return sign;
    if (exponent > 0x7f)
        return 0x7f000u;
    return sign |
        ((magnitude & 0x007fffffu) >> 11) |
        (static_cast<uint32_t>(exponent) << 12);
}
KIU_FORCE_INLINE void dispatch_skeleton_callbacks(
    uint8_t* callbacks, void* skeleton, int bone_index) {
    void** current = *reinterpret_cast<void***>(callbacks + 8);
    void** end = *reinterpret_cast<void***>(callbacks + 0x0c);
    while (current != end) {
        void* callback = *current++;
        void** vtable = *reinterpret_cast<void***>(callback);
        reinterpret_cast<void (*)(void*, void*, int)>(vtable[0])(
            callback, skeleton, bone_index);
    }
}
KIU_FORCE_INLINE void stabilize_skeleton_scale(float* scale) {
    const float epsilon = 0x1.0c6f7cp-20f;
    if (scale[0] * scale[0] + scale[1] * scale[1] +
            scale[2] * scale[2] >= epsilon)
        return;
    for (int component = 0; component < 3; ++component)
        scale[component] = scale[component] >= 0.0f ? epsilon : -epsilon;
}
KIU_FORCE_INLINE void update_skeleton_scale_flags(TransformRecord* record) {
    uint32_t flags = record->flags & ~0x7e0u;
    record->flags = flags;
    if ((flags & 8u) != 0)
        return;
    if (record->scale[0] == record->scale[1] &&
        record->scale[0] == record->scale[2]) {
        flags |= 0x400u;
        record->flags = flags;
        if (float_bits(record->scale[0]) == 0x3f800000u)
            record->flags = flags | 0x200u;
    }
}
extern "C" __attribute__((noinline)) void AnimationTransform_SampleScale_005AF458(
    float* scale, void* const* channel_pointer, float frame) {
    const uint8_t* channel =
        static_cast<const uint8_t*>(*channel_pointer);
    const uint32_t flags =
        *reinterpret_cast<const uint32_t*>(channel);
    for (uint32_t component = 0; component < 3; ++component) {
        float value = (flags & (0x00010000u << component)) != 0
            ? 1.0f
            : sample_transform_component(
                  channel, 0x0c + component * 4,
                  0x00000040u << component, frame);
        if ((float_bits(value) & 0x7fffffffu) < 0x3727c5acu)
            value = 0.00001f;
        scale[component] = value;
    }
}
KIU_FORCE_INLINE uint8_t* resolve_relative(uint8_t* field) {
    if (field == 0)
        return 0;
    const int32_t offset =
        *reinterpret_cast<const int32_t*>(field);
    return offset == 0 ? 0 : field + offset;
}
KIU_FORCE_INLINE void resize_index_array(IndexArray* array, int requested) {
    const int size = static_cast<int>(array->end - array->begin);
    if (requested < size) {
        if (requested < 0)
            requested = 0;
        array->end = array->begin + requested;
        return;
    }
    int new_size = requested;
    const uint32_t capacity = array->capacity_flags & 0x3fffffffu;
    if (static_cast<int>(capacity) < requested) {
        if (array->allocator == 0 ||
            (array->capacity_flags & 0xc0000000u) != 0x40000000u) {
            new_size = static_cast<int>(capacity);
        } else {
            void** vtable = *reinterpret_cast<void***>(array->allocator);
            void* (*allocate)(void*, uint32_t, uint32_t) =
                reinterpret_cast<void* (*)(void*, uint32_t,
                                            uint32_t)>(vtable[2]);
            void (*deallocate)(void*, void*) =
                reinterpret_cast<void (*)(void*, void*)>(vtable[3]);
            uint32_t* replacement = static_cast<uint32_t*>(
                allocate(array->allocator, requested * 4u, 4));
            const int old_size = size;
            for (int index = 0; index < old_size; ++index) {
                if (replacement != 0)
                    replacement[index] = array->begin[index];
            }
            if (array->begin != 0)
                deallocate(array->allocator, array->begin);
            array->begin = replacement;
            array->end = replacement + old_size;
            array->capacity_flags =
                (array->capacity_flags & 0xc0000000u) |
                static_cast<uint32_t>(requested);
        }
    }
    array->end = array->begin + new_size;
}
KIU_FORCE_INLINE void reset_target_channel_cache(
    uint8_t* target, uint32_t type) {
    switch (type) {
    case 1:
        *reinterpret_cast<uint32_t*>(target + 0x2b4) = 0;
        break;
    case 2:
        *reinterpret_cast<uint32_t*>(target + 0x2b0) = 0;
        *reinterpret_cast<uint32_t*>(target + 0x2ac) = 0;
        break;
    case 3:
        *reinterpret_cast<uint32_t*>(target + 0x2b0) = 0;
        break;
    case 4:
        *reinterpret_cast<uint32_t*>(target + 0x2d0) = 0;
        break;
    case 5:
        *reinterpret_cast<uint32_t*>(target + 0x2a8) = 0;
        break;
    default:
        break;
    }
}
KIU_FORCE_INLINE int animation_channel_count(
    const uint8_t* target_work) {
    uint8_t* descriptor =
        *reinterpret_cast<uint8_t* const*>(target_work + 8);
    return *reinterpret_cast<const int*>(descriptor + 0x10);
}
KIU_FORCE_INLINE void update_transform_derived_flags(
    const uint8_t* animation, TransformRecord* transform) {
    transform->flags &= ~0x40000000u;
    if (animation[0x5b] != 0)
        transform->flags |= 8u;
    else
        transform->flags &= ~8u;
    if (animation[0x5c] != 0)
        transform->flags |= 0x10u;
    else
        transform->flags &= ~0x10u;
    if (animation[0x5d] != 0)
        transform->flags |= 4u;
    else
        transform->flags &= ~4u;
    if ((transform->flags & 8u) == 0) {
        transform->flags &= ~0x600u;
        if (transform->scale[0] == transform->scale[1] &&
            transform->scale[0] == transform->scale[2]) {
            transform->flags |= 0x400u;
            if (float_bits(transform->scale[0]) == 0x3f800000u)
                transform->flags |= 0x200u;
        }
    }
    TransformRecord_UpdateIdentityRotationFlag_008E62F0(transform);
    TransformRecord_UpdateZeroTranslationFlag_008E6428(transform);
    TransformRecord_NormalizeFlags_008E63F4(transform);
}
}  // namespace
extern "C" __attribute__((noinline)) void TransformRecord_RebuildEulerKeepTranslation_008E5E90(
    void* record, float x, float y, float z) {
    TransformRecord* transform = static_cast<TransformRecord*>(record);
    const float tx = transform->affine[3];
    const float ty = transform->affine[7];
    const float tz = transform->affine[11];
    float sx, cx, sy, cy, sz, cz;
    sample_animation_trig(x, sx, cx);
    sample_animation_trig(y, sy, cy);
    sample_animation_trig(z, sz, cz);
    transform->affine[0] = cz * cy;
    transform->affine[1] = sx * cz * sy - cx * sz;
    transform->affine[2] = sx * sz + cx * cz * sy;
    transform->affine[4] = sz * cy;
    transform->affine[5] = cx * cz + sx * sz * sy;
    transform->affine[6] = cx * sz * sy - sx * cz;
    transform->affine[8] = -sy;
    transform->affine[9] = sx * cy;
    transform->affine[10] = cx * cy;
    transform->affine[3] = tx;
    transform->affine[7] = ty;
    transform->affine[11] = tz;
    transform->flags |= 0x800u;
}
extern "C" __attribute__((noinline)) void
TransformRecord_NormalizeFlags_008E63F4(void* record) {
    TransformRecord* transform = static_cast<TransformRecord*>(record);
    uint32_t flags = transform->flags & ~0x60u;
    if ((flags & 0x180u) == 0) {
        flags |= 0x40u;
        if ((flags & 0x200u) == 0)
            flags |= 0x20u;
    }
    transform->flags = flags;
}
extern "C" __attribute__((noinline)) void
TransformRecord_UpdateIdentityRotationFlag_008E62F0(
    void* record) {
    TransformRecord* transform = static_cast<TransformRecord*>(record);
    if ((transform->flags & 0x10u) != 0)
        return;
    if (float_bits(transform->affine[0]) == 0x3f800000u &&
        float_bits(transform->affine[5]) == 0x3f800000u)
        transform->flags |= 0x80u;
    else
        transform->flags &= ~0x80u;
}
extern "C" __attribute__((noinline)) void
TransformRecord_UpdateZeroTranslationFlag_008E6428(
    void* record) {
    TransformRecord* transform = static_cast<TransformRecord*>(record);
    if ((transform->flags & 4u) != 0)
        return;
    if (transform->affine[3] == 0.0f &&
        transform->affine[7] == 0.0f &&
        transform->affine[11] == 0.0f)
        transform->flags |= 0x100u;
    else
        transform->flags &= ~0x100u;
}
extern "C" __attribute__((noinline)) void TransformRecord_UpdateAllDerivedFlags_008E5D7C(
    void* record) {
    TransformRecord* transform = static_cast<TransformRecord*>(record);
    uint32_t flags = transform->flags;
    if ((flags & 8u) == 0) {
        flags &= ~0x600u;
        transform->flags = flags;
        if (transform->scale[0] == transform->scale[1] &&
            transform->scale[0] == transform->scale[2]) {
            flags |= 0x400u;
            transform->flags = flags;
            if (float_bits(transform->scale[0]) == 0x3f800000u) {
                flags |= 0x200u;
                transform->flags = flags;
            }
        }
    }
    if ((flags & 0x10u) == 0) {
        if (float_bits(transform->affine[0]) == 0x3f800000u &&
            float_bits(transform->affine[5]) == 0x3f800000u)
            flags |= 0x80u;
        else
            flags &= ~0x80u;
        transform->flags = flags;
    }
    if ((flags & 4u) == 0) {
        if (transform->affine[3] == 0.0f &&
            transform->affine[7] == 0.0f &&
            transform->affine[11] == 0.0f)
            flags |= 0x100u;
        else
            flags &= ~0x100u;
        transform->flags = flags;
    }
    flags &= ~0x60u;
    transform->flags = flags;
    if ((flags & 0x180u) == 0) {
        flags |= 0x40u;
        transform->flags = flags;
        if ((flags & 0x200u) == 0)
            transform->flags = flags | 0x20u;
    }
}
extern "C" __attribute__((noinline)) void TransformRecord_UpdateDerivedFlags_008E6328(
    void* animation_pointer, void* record) {
    const uint8_t* animation =
        static_cast<const uint8_t*>(animation_pointer);
    TransformRecord* transform = static_cast<TransformRecord*>(record);
    update_transform_derived_flags(animation, transform);
}
extern "C" __attribute__((noinline)) void TransformRecord_BuildEulerAffine_008E65BC(
    void* record, const float* rotation, const float* translation) {
    TransformRecord* transform = static_cast<TransformRecord*>(record);
    float sa, ca, sb, cb, sc, cc;
    sample_animation_trig(rotation[0], sa, ca);
    sample_animation_trig(rotation[1], sb, cb);
    sample_animation_trig(rotation[2], sc, cc);
    transform->affine[0] = cc * cb;
    transform->affine[1] = sa * cc * sb - ca * sc;
    transform->affine[2] = sa * sc + ca * cc * sb;
    transform->affine[4] = sc * cb;
    transform->affine[5] = ca * cc + sa * sc * sb;
    transform->affine[6] = ca * sc * sb - sa * cc;
    transform->affine[8] = -sb;
    transform->affine[9] = sa * cb;
    transform->affine[10] = ca * cb;
    transform->affine[3] = translation[0];
    transform->affine[7] = translation[1];
    transform->affine[11] = translation[2];
    transform->flags |= 0x800u;
}
extern "C" __attribute__((noinline)) void TransformRecord_AssignScaleEulerTranslation_008E60C0(
    void* record, const float* values) {
    TransformRecord* transform = static_cast<TransformRecord*>(record);
    transform->scale[0] = values[0];
    transform->scale[1] = values[1];
    transform->scale[2] = values[2];
    float x = values[3] * 40.7436637878418f;
    float y = values[4] * 40.7436637878418f;
    float z = values[5] * 40.7436637878418f;
    const bool negative_x = x < 0.0f;
    const bool negative_y = y < 0.0f;
    const bool negative_z = z < 0.0f;
    if (negative_x)
        x = -x;
    if (negative_y)
        y = -y;
    if (negative_z)
        z = -z;
    while (x >= 65536.0f)
        x -= 65536.0f;
    while (y >= 65536.0f)
        y -= 65536.0f;
    while (z >= 65536.0f)
        z -= 65536.0f;
    const uint32_t whole_x = static_cast<uint32_t>(x);
    const uint32_t whole_y = static_cast<uint32_t>(y);
    const uint32_t whole_z = static_cast<uint32_t>(z);
    const float* sample_x = gAnimationTrigTable_00CAF18C[whole_x & 0xff];
    const float* sample_y = gAnimationTrigTable_00CAF18C[whole_y & 0xff];
    const float* sample_z = gAnimationTrigTable_00CAF18C[whole_z & 0xff];
    float sx = sample_x[0] +
        (x - static_cast<float>(whole_x)) * sample_x[2];
    const float cx = sample_x[1] +
        (x - static_cast<float>(whole_x)) * sample_x[3];
    float sy = sample_y[0] +
        (y - static_cast<float>(whole_y)) * sample_y[2];
    const float cy = sample_y[1] +
        (y - static_cast<float>(whole_y)) * sample_y[3];
    float sz = sample_z[0] +
        (z - static_cast<float>(whole_z)) * sample_z[2];
    const float cz = sample_z[1] +
        (z - static_cast<float>(whole_z)) * sample_z[3];
    if (negative_x)
        sx = -sx;
    if (negative_y)
        sy = -sy;
    if (negative_z)
        sz = -sz;
    transform->affine[0] = cz * cy;
    transform->affine[1] = sx * cz * sy - cx * sz;
    transform->affine[2] = sx * sz + cx * cz * sy;
    transform->affine[4] = sz * cy;
    transform->affine[5] = cx * cz + sx * sz * sy;
    transform->affine[6] = cx * sz * sy - sx * cz;
    transform->affine[8] = -sy;
    transform->affine[9] = sx * cy;
    transform->affine[10] = cx * cy;
    transform->affine[3] = values[6];
    transform->affine[7] = values[7];
    transform->affine[11] = values[8];
    transform->flags |= 0x800u;
}
extern "C" __attribute__((noinline)) void AnimationChannel_ApplyKind15_00B45AA0(
    void* const* channel_pointer, void* destination_pointer,
    const float* source) {
    const uint8_t* channel =
        static_cast<const uint8_t*>(*channel_pointer);
    uint8_t* destination =
        static_cast<uint8_t*>(destination_pointer);
    const uint32_t mode =
        *reinterpret_cast<const uint32_t*>(channel + 0x14);
    if (mode == 0 || mode == 1) {
        float* output = reinterpret_cast<float*>(
            destination + (mode == 0 ? 0xb8 : 0xc8));
        output[0] = source[0];
        output[1] = source[1];
        output[2] = source[2];
        output[3] = source[3];
    } else if (mode == 2) {
        const float inverse_length = 1.0f / std::sqrt(
            source[0] * source[0] +
            source[1] * source[1] +
            source[2] * source[2]);
        float* output =
            reinterpret_cast<float*>(destination + 0xd8);
        output[0] = source[0] * inverse_length;
        output[1] = source[1] * inverse_length;
        output[2] = source[2] * inverse_length;
    } else if (mode == 3) {
        *reinterpret_cast<float*>(destination + 0xe4) = source[0];
    }
}
extern "C" __attribute__((noinline)) void AnimationChannel_ApplyKind14_00B45570(
    void* const* channel_pointer, void* destination_pointer,
    const float* source) {
    const uint8_t* channel =
        static_cast<const uint8_t*>(*channel_pointer);
    uint8_t* destination =
        static_cast<uint8_t*>(destination_pointer);
    const uint32_t mode =
        *reinterpret_cast<const uint32_t*>(channel + 0x14);
    float* output;
    switch (mode) {
    case 0:
        output = reinterpret_cast<float*>(destination + 0xbc);
        break;
    case 1:
        output = reinterpret_cast<float*>(destination + 0xcc);
        break;
    case 2: {
        const float inverse_length = 1.0f / std::sqrt(
            source[0] * source[0] +
            source[1] * source[1] +
            source[2] * source[2]);
        output = reinterpret_cast<float*>(destination + 0xdc);
        output[0] = source[0] * inverse_length;
        output[1] = source[1] * inverse_length;
        output[2] = source[2] * inverse_length;
        return;
    }
    case 3:
        *reinterpret_cast<float*>(destination + 0xe8) = source[0];
        return;
    case 4:
        *reinterpret_cast<float*>(destination + 0xec) = source[0];
        return;
    case 5:
        *reinterpret_cast<float*>(destination + 0xf0) = source[0];
        return;
    case 6:
        *reinterpret_cast<float*>(destination + 0xf8) = source[0];
        return;
    case 7:
        *reinterpret_cast<float*>(destination + 0xfc) = source[0];
        return;
    default:
        return;
    }
    output[0] = source[0];
    output[1] = source[1];
    output[2] = source[2];
    output[3] = source[3];
}
extern "C" __attribute__((noinline)) void AnimationChannel_ApplyKind11_00B45B2C(
    void* const* channel_pointer, void* destination_pointer,
    const float* source) {
    const uint8_t* channel =
        static_cast<const uint8_t*>(*channel_pointer);
    uint8_t* destination =
        static_cast<uint8_t*>(destination_pointer);
    const uint32_t mode =
        *reinterpret_cast<const uint32_t*>(channel + 0x14);
    const uint32_t record_kind =
        *reinterpret_cast<const uint32_t*>(destination);
    if (record_kind == 0x20000000u) {
        const uint32_t value =
            *reinterpret_cast<const uint32_t*>(source);
        if (mode == 0)
            *reinterpret_cast<uint32_t*>(destination + 0x04) = value;
        else if (mode == 1)
            *reinterpret_cast<uint32_t*>(destination + 0x08) = value;
        else if (mode == 2)
            *reinterpret_cast<uint32_t*>(destination + 0x10) = value;
        else if (mode == 3)
            *reinterpret_cast<uint32_t*>(destination + 0x0c) = value;
        return;
    }
    if (record_kind != 0x40000000u)
        return;
    const float first = source[0];
    switch (mode) {
    case 0:
        *reinterpret_cast<float*>(destination + 0x04) = first;
        break;
    case 1:
        *reinterpret_cast<float*>(destination + 0x08) = first;
        break;
    case 3:
        *reinterpret_cast<float*>(destination + 0x0c) = first;
        break;
    case 4:
        *reinterpret_cast<float*>(destination + 0x10) = first;
        break;
    case 5: {
        const float second = source[1];
        *reinterpret_cast<float*>(destination + 0x14) = first;
        *reinterpret_cast<float*>(destination + 0x18) = second;
        break;
    }
    default:
        break;
    }
}
extern "C" __attribute__((noinline)) void AnimationChannel_ApplyKind1_00B458DC(
    void* const* channel_pointer, void* destination_pointer,
    const float* source) {
    const uint8_t* channel =
        static_cast<const uint8_t*>(*channel_pointer);
    const uint32_t mode =
        *reinterpret_cast<const uint32_t*>(channel + 0x14);
    uint8_t* destination =
        static_cast<uint8_t*>(destination_pointer);
#define KIU_APPLY_COLOR_SLOT(slot)                                           \
    case slot: {                                                             \
        const uint32_t* input =                                         \
            reinterpret_cast<const uint32_t*>(source);                  \
        uint32_t* output = reinterpret_cast<uint32_t*>(            \
            destination + (slot) * 0x10);                                    \
        const uint32_t word0 = input[0];                                \
        const uint32_t word1 = input[1];                                \
        const uint32_t word2 = input[2];                                \
        output[3] = input[3];                                                \
        output[0] = word0;                                                   \
        output[1] = word1;                                                   \
        output[2] = word2;                                                   \
        *reinterpret_cast<uint32_t*>(                                   \
            destination + 0xb0 + (slot) * 4) =                              \
            Color_QuantizeFloat4ToRGBA_002F1AD8(                             \
                reinterpret_cast<const float*>(output));                     \
        return;                                                              \
    }
    switch (mode) {
        KIU_APPLY_COLOR_SLOT(0)
        KIU_APPLY_COLOR_SLOT(1)
        KIU_APPLY_COLOR_SLOT(2)
        KIU_APPLY_COLOR_SLOT(3)
        KIU_APPLY_COLOR_SLOT(4)
        KIU_APPLY_COLOR_SLOT(5)
        KIU_APPLY_COLOR_SLOT(6)
        KIU_APPLY_COLOR_SLOT(7)
        KIU_APPLY_COLOR_SLOT(8)
        KIU_APPLY_COLOR_SLOT(9)
        KIU_APPLY_COLOR_SLOT(10)
    default:
        return;
    }
#undef KIU_APPLY_COLOR_SLOT
}
extern "C" __attribute__((noinline)) void AnimationChannel_ApplyKind13_00B45640(
    void* const* channel_pointer, void* destination_pointer,
    const float* source) {
    const uint8_t* channel =
        static_cast<const uint8_t*>(*channel_pointer);
    uint8_t* destination =
        static_cast<uint8_t*>(destination_pointer);
    const uint32_t mode =
        *reinterpret_cast<const uint32_t*>(channel + 0x14);
#define KIU_APPLY_KIND13_COLOR(slot)                                        \
    case slot: {                                                            \
        const float x = source[0];                                          \
        const float y = source[1];                                          \
        const float z = source[2];                                          \
        const float w = source[3];                                          \
        float* output = reinterpret_cast<float*>(                           \
            destination + 0xbc + (slot) * 0x10);                            \
        output[0] = x;                                                      \
        output[1] = y;                                                      \
        output[2] = z;                                                      \
        output[3] = w;                                                      \
        *reinterpret_cast<uint32_t*>(                                  \
            destination + 0xfc + (slot) * 4) =                              \
            Color_QuantizeFloat4ToRGBA_002F1AD8(output);                    \
        return;                                                             \
    }
    switch (mode) {
        KIU_APPLY_KIND13_COLOR(0)
        KIU_APPLY_KIND13_COLOR(1)
        KIU_APPLY_KIND13_COLOR(2)
        KIU_APPLY_KIND13_COLOR(3)
    case 4: {
        const float x = source[0];
        const float y = source[1];
        const float z = source[2];
        const float inverse_length =
            1.0f / std::sqrt(x * x + y * y + z * z);
        *reinterpret_cast<float*>(destination + 0x10c) =
            x * inverse_length;
        *reinterpret_cast<float*>(destination + 0x110) =
            y * inverse_length;
        *reinterpret_cast<float*>(destination + 0x114) =
            z * inverse_length;
        return;
    }
    case 5: {
        const float value = source[0];
        *reinterpret_cast<float*>(destination + 0x120) = value;
        float delta =
            *reinterpret_cast<float*>(destination + 0x124) - value;
        if ((float_bits(delta) & 0x7fffffffu) < 0x3c23d70au)
            delta = 0.01f;
        *reinterpret_cast<uint32_t*>(destination + 0x128) =
            pack_animation_slope(1.0f / delta);
        *reinterpret_cast<uint32_t*>(destination + 0x12c) =
            pack_animation_slope(-value / delta);
        return;
    }
    case 6: {
        const float value = source[0];
        *reinterpret_cast<float*>(destination + 0x124) = value;
        const float start =
            *reinterpret_cast<float*>(destination + 0x120);
        float delta = value - start;
        if ((float_bits(delta) & 0x7fffffffu) < 0x3c23d70au)
            delta = 0.01f;
        *reinterpret_cast<uint32_t*>(destination + 0x128) =
            pack_animation_slope(1.0f / delta);
        *reinterpret_cast<uint32_t*>(destination + 0x12c) =
            pack_animation_slope(-start / delta);
        return;
    }
    default:
        return;
    }
#undef KIU_APPLY_KIND13_COLOR
}
extern "C" __attribute__((noinline)) int AnimationChannel_ApplyKind5_00B45C1C(
    void* const* channel_pointer, void* destination_pointer,
    const float* source) {
    const uint8_t* channel =
        static_cast<const uint8_t*>(*channel_pointer);
    uint8_t* destination =
        static_cast<uint8_t*>(destination_pointer);
    const uint32_t mode =
        *reinterpret_cast<const uint32_t*>(channel + 0x14);
    if (mode == 0) {
        float* output = reinterpret_cast<float*>(destination + 0x10);
        if (output[0] != source[0] || output[1] != source[1]) {
            output[0] = source[0];
            output[1] = source[1];
            destination[0x24] = 1;
        }
    } else if (mode == 1) {
        float* output = reinterpret_cast<float*>(destination + 0x18);
        if (*output != source[0]) {
            *output = source[0];
            destination[0x24] = 1;
        }
    } else if (mode == 2) {
        float* output = reinterpret_cast<float*>(destination + 0x1c);
        if (output[0] != source[0] || output[1] != source[1]) {
            output[0] = source[0];
            output[1] = source[1];
            destination[0x24] = 1;
        }
    }
    destination[0x24] = 1;
    return 1;
}
extern "C" __attribute__((noinline)) void AnimationChannel_ApplyByKind_00B451B8(
    void* const* channel_pointer, void* destination_pointer,
    const float* source) {
    void* channel_value = *channel_pointer;
    void* const* channel = &channel_value;
    const uint8_t* descriptor =
        static_cast<const uint8_t*>(channel_value);
    uint8_t* destination =
        static_cast<uint8_t*>(destination_pointer);
    const uint32_t kind =
        *reinterpret_cast<const uint32_t*>(descriptor + 0x10);
    const uint32_t subtype =
        *reinterpret_cast<const uint32_t*>(descriptor + 0x14);
    switch (kind) {
    case 0: {
        TransformRecord_AssignScaleEulerTranslation_008E60C0(
            destination, source);
        uint32_t& flags =
            *reinterpret_cast<uint32_t*>(destination + 0x3c);
        if ((flags & 8u) == 0) {
            flags &= ~0x600u;
            const float* scale =
                reinterpret_cast<const float*>(destination + 0x30);
            if (scale[0] == scale[1] && scale[0] == scale[2]) {
                flags |= 0x400u;
                if (float_bits(scale[0]) == 0x3f800000u)
                    flags |= 0x200u;
            }
        }
        TransformRecord_UpdateIdentityRotationFlag_008E62F0(destination);
        TransformRecord_UpdateZeroTranslationFlag_008E6428(destination);
        TransformRecord_NormalizeFlags_008E63F4(destination);
        return;
    }
    case 1:
        AnimationChannel_ApplyKind1_00B458DC(
            channel, destination, source);
        return;
    case 2: {
        if (subtype != 0)
            return;
        uint8_t* record = resolve_relative(destination + 0x0c);
        float* output = reinterpret_cast<float*>(record + 0x0c);
        const float x = source[0];
        const float y = source[1];
        const float z = source[2];
        const float w = source[3];
        output[0] = x;
        output[1] = y;
        output[2] = z;
        output[3] = w;
        const uint32_t packed =
            Color_QuantizeFloat4ToRGBA_002F1AD8(output);
        struct {
            uint32_t value;
            void* view;
        } pair;
        void* record_pointer = record;
        RelativeParameterRecord_ResolvePair_002A3CF0(
            &pair, &record_pointer);
        *reinterpret_cast<uint32_t*>(
            static_cast<uint8_t*>(pair.view) + 8) = packed;
        return;
    }
    case 3: {
        if (subtype != 0)
            return;
        uint8_t* source_record = resolve_relative(
            const_cast<uint8_t*>(
                reinterpret_cast<const uint8_t*>(source)));
        void* resolved = resolve_relative(source_record + 0x1c);
        void* destination_record = destination;
        RelativePointerRecord_Assign_003AC8F4(
            &destination_record, resolved);
        return;
    }
    case 4: {
        if (subtype != 0)
            return;
        const uint32_t* input =
            reinterpret_cast<const uint32_t*>(source);
        uint32_t* output =
            reinterpret_cast<uint32_t*>(destination + 4);
        const uint32_t x = input[0];
        const uint32_t y = input[1];
        const uint32_t z = input[2];
        const uint32_t w = input[3];
        output[0] = x;
        output[1] = y;
        output[2] = z;
        output[3] = w;
        *reinterpret_cast<uint32_t*>(destination + 0x24) =
            Color_QuantizeFloat4ToRGBA_002F1AD8(
                reinterpret_cast<const float*>(output));
        return;
    }
    case 5:
        AnimationChannel_ApplyKind5_00B45C1C(
            channel, destination, source);
        return;
    case 6:
        if (subtype == 0)
            destination[0x30] =
                *reinterpret_cast<const uint8_t*>(source);
        else if (subtype == 1)
            destination[0x1f6] =
                *reinterpret_cast<const uint8_t*>(source);
        return;
    case 7:
        destination[0x24] =
            *reinterpret_cast<const uint8_t*>(source);
        return;
    case 8:
        destination[0x04] =
            *reinterpret_cast<const uint8_t*>(source);
        return;
    case 9:
        if (subtype == 0) {
            TransformRecord_AssignScaleEulerTranslation_008E60C0(
                destination + 0x4c, source);
            *reinterpret_cast<uint32_t*>(destination + 0x88) |=
                0x800u;
        }
        return;
    case 10: {
        const uint32_t record_kind =
            *reinterpret_cast<const uint32_t*>(destination);
        uint8_t* output = 0;
        if (record_kind == 0x80000000u) {
            if (subtype == 1) {
                *reinterpret_cast<uint32_t*>(destination + 0x14) =
                    *reinterpret_cast<const uint32_t*>(source);
                return;
            }
            if (subtype == 0)
                output = destination + 0x08;
        } else if (record_kind == 0x20000000u) {
            if (subtype == 3)
                output = destination + 0x08;
        } else if (record_kind == 0x40000000u) {
            if (subtype == 0)
                output = destination + 0x08;
            else if (subtype == 2)
                output = destination + 0x14;
        }
        if (output != 0) {
            const uint32_t* input =
                reinterpret_cast<const uint32_t*>(source);
            uint32_t* words =
                reinterpret_cast<uint32_t*>(output);
            const uint32_t x = input[0];
            const uint32_t y = input[1];
            const uint32_t z = input[2];
            words[0] = x;
            words[1] = y;
            words[2] = z;
        }
        return;
    }
    case 11:
        AnimationChannel_ApplyKind11_00B45B2C(
            channel, destination, source);
        return;
    case 12:
        if (subtype == 0)
            destination[0xb4] =
                static_cast<uint8_t>(
                    *reinterpret_cast<const int8_t*>(source));
        return;
    case 13:
        AnimationChannel_ApplyKind13_00B45640(
            channel, destination, source);
        return;
    case 14:
        AnimationChannel_ApplyKind14_00B45570(
            channel, destination, source);
        return;
    case 15:
        AnimationChannel_ApplyKind15_00B45AA0(
            channel, destination, source);
        return;
    case 16: {
        if (subtype != 0)
            return;
        const float x = source[0];
        const float y = source[1];
        const float z = source[2];
        const float w = source[3];
        float* output = reinterpret_cast<float*>(destination + 0xb8);
        output[0] = x;
        output[1] = y;
        output[2] = z;
        output[3] = w;
        *reinterpret_cast<uint32_t*>(destination + 0xc8) =
            Color_QuantizeFloat4ToRGBA_002F1AD8(output);
        return;
    }
    case 17: {
        if (subtype != 0)
            return;
        const uint32_t* input =
            reinterpret_cast<const uint32_t*>(source);
        uint32_t* output =
            reinterpret_cast<uint32_t*>(destination + 0xb4);
        const uint32_t x = input[0];
        const uint32_t y = input[1];
        const uint32_t z = input[2];
        const uint32_t w = input[3];
        output[0] = x;
        output[1] = y;
        output[2] = z;
        output[3] = w;
        return;
    }
    default:
        return;
    }
}
extern "C" __attribute__((noinline)) void AnimationTransform_Evaluate_00B3F2E0(
    void* animation_pointer, void* destination_pointer,
    void* channel_pointer, void* defaults_pointer, int mode, float frame) {
    uint8_t* animation = static_cast<uint8_t*>(animation_pointer);
    TransformRecord* destination =
        static_cast<TransformRecord*>(destination_pointer);
    const uint8_t* channel =
        static_cast<const uint8_t*>(channel_pointer);
    const float* defaults = static_cast<const float*>(defaults_pointer);
    const uint32_t flags =
        *reinterpret_cast<const uint32_t*>(channel);
    static const uint32_t default_flags[3][3] = {
        {0x00010000, 0x00020000, 0x00040000},
        {0x00080000, 0x00100000, 0x00200000},
        {0x00800000, 0x01000000, 0x02000000},
    };
    static const uint32_t inline_flags[3][3] = {
        {0x00000040, 0x00000080, 0x00000100},
        {0x00000200, 0x00000400, 0x00000800},
        {0x00002000, 0x00004000, 0x00008000},
    };
    static const uint32_t slots[3][3] = {
        {0x0c, 0x10, 0x14},
        {0x18, 0x1c, 0x20},
        {0x28, 0x2c, 0x30},
    };
    if (mode != 0) {
        float values[3][3];
        for (uint32_t group = 0; group < 3; ++group) {
            for (uint32_t component = 0; component < 3; ++component) {
                const uint32_t index = group * 3 + component;
                values[group][component] =
                    animation[0x5b + group] != 0 ||
                        (flags & default_flags[group][component]) != 0
                    ? defaults[index]
                    : sample_transform_component(
                          channel, slots[group][component],
                          inline_flags[group][component], frame);
            }
        }
        destination->scale[0] = values[0][0];
        destination->scale[1] = values[0][1];
        destination->scale[2] = values[0][2];
        TransformRecord_BuildEulerAffine_008E65BC(
            destination, values[1], values[2]);
    } else {
        if (animation[0x5b] == 0) {
            for (uint32_t component = 0; component < 3; ++component) {
                if ((flags & default_flags[0][component]) == 0) {
                    destination->scale[component] = sample_transform_component(
                        channel, slots[0][component],
                        inline_flags[0][component], frame);
                }
            }
        }
        const uint32_t all_rotation_defaults = 0x00380000;
        if (animation[0x5c] == 0 &&
            (flags & all_rotation_defaults) != all_rotation_defaults) {
            float rotation[3];
            for (uint32_t component = 0; component < 3; ++component) {
                rotation[component] =
                    (flags & default_flags[1][component]) != 0
                    ? defaults[3 + component]
                    : sample_transform_component(
                          channel, slots[1][component],
                          inline_flags[1][component], frame);
            }
            TransformRecord_RebuildEulerKeepTranslation_008E5E90(
                destination, rotation[0], rotation[1], rotation[2]);
        }
        if (animation[0x5d] == 0) {
            for (uint32_t component = 0; component < 3; ++component) {
                if ((flags & default_flags[2][component]) == 0) {
                    destination->affine[3 + component * 4] =
                        sample_transform_component(
                            channel, slots[2][component],
                            inline_flags[2][component], frame);
                }
            }
        }
        destination->flags |= 0x800u;
    }
    destination->flags &= ~0x40000000u;
    static const uint32_t preservation_flags[3] = {8, 0x10, 4};
    for (uint32_t group = 0; group < 3; ++group) {
        if (animation[0x5b + group] != 0)
            destination->flags |= preservation_flags[group];
        else
            destination->flags &= ~preservation_flags[group];
    }
    if ((flags & 0x00380000) != 0x00380000)
        destination->flags &= ~0x80u;
    if ((flags & 0x03800000) != 0x03800000)
        destination->flags &= ~0x100u;
    if ((flags & 0x00070000) != 0x00070000)
        destination->flags &= ~0x200u;
    TransformRecord_NormalizeFlags_008E63F4(destination);
}
__attribute__((noinline)) void* animation_channel_apply_shared(
    void* animation_pointer, void* destination_pointer,
    uint32_t channel_index, int mode) {
    uint8_t* animation = static_cast<uint8_t*>(animation_pointer);
    TransformRecord* destination =
        static_cast<TransformRecord*>(destination_pointer);
    void** vtable = *reinterpret_cast<void***>(animation);
    int (*has_channel)(void*, uint32_t) =
        reinterpret_cast<int (*)(void*, uint32_t)>(vtable[7]);
    if (has_channel(animation, channel_index) == 0)
        return 0;
    const float frame = *reinterpret_cast<const float*>(animation + 0x38);
    const uint8_t* const* samples =
        *reinterpret_cast<const uint8_t* const**>(
            *reinterpret_cast<uint8_t**>(animation + 8) + 0x54);
    const uint8_t* sample_record = samples[channel_index];
    if (*reinterpret_cast<void**>(animation + 0x54) == 0) {
        destination->scale[0] =
            *reinterpret_cast<const float*>(sample_record + 0x00);
        destination->scale[1] =
            *reinterpret_cast<const float*>(sample_record + 0x04);
        destination->scale[2] =
            *reinterpret_cast<const float*>(sample_record + 0x08);
        TransformRecord_BuildEulerAffine_008E65BC(
            destination,
            reinterpret_cast<const float*>(sample_record + 0x0c),
            reinterpret_cast<const float*>(sample_record + 0x18));
        TransformRecord_UpdateDerivedFlags_008E6328(animation, destination);
        return destination;
    }
    const uint8_t* table_field =
        static_cast<const uint8_t*>(
            *reinterpret_cast<void**>(animation + 0x54)) + 0x1c;
    const int32_t table_offset =
        *reinterpret_cast<const int32_t*>(table_field);
    const uint8_t* table =
        table_offset == 0 ? 0 : table_field + table_offset;
    const uint32_t mapped_channel =
        (*reinterpret_cast<const uint32_t* const*>(animation + 0x14))[
            channel_index];
    const uint8_t* element_field =
        table + mapped_channel * 0x10 + 0x28;
    const int32_t element_offset =
        *reinterpret_cast<const int32_t*>(element_field);
    const uint8_t* element =
        element_offset == 0 ? 0 : element_field + element_offset;
    const uint32_t primitive_type =
        *reinterpret_cast<const uint32_t*>(element + 8);
    if (primitive_type == 5) {
        AnimationTransform_Evaluate_00B3F2E0(
            animation, destination, const_cast<uint8_t*>(element),
            const_cast<uint8_t*>(sample_record), mode, frame);
    } else if (primitive_type == 8) {
        FUN_00B3F898(
            animation, destination, const_cast<uint8_t*>(element),
            const_cast<uint8_t*>(sample_record), mode, frame);
    } else if (primitive_type == 9) {
        const uint8_t* data_field = element + 0x0c;
        const int32_t data_offset =
            *reinterpret_cast<const int32_t*>(data_field);
        const void* data = data_offset == 0 ? 0 : data_field + data_offset;
        FUN_0044C05C(destination, data);
    }
    return destination;
}
extern "C" __attribute__((noinline)) void* AnimationChannel_ApplyMode0_00B3F19C(
    void* animation, void* destination, uint32_t channel_index) {
    return animation_channel_apply_shared(
        animation, destination, channel_index, 0);
}
extern "C" __attribute__((noinline)) void* AnimationChannel_ApplyMode1_00B3FB60(
    void* animation, void* destination, uint32_t channel_index) {
    return animation_channel_apply_shared(
        animation, destination, channel_index, 1);
}
extern "C" __attribute__((noinline)) void AnimationTransform_SampleRotationTranslation_009252CC(
    float* rotation, float* translation, void* const* channel_pointer,
    float frame) {
    const uint8_t* channel =
        static_cast<const uint8_t*>(*channel_pointer);
    const uint32_t flags =
        *reinterpret_cast<const uint32_t*>(channel);
    for (uint32_t component = 0; component < 3; ++component) {
        rotation[component] =
            (flags & (0x00080000u << component)) != 0
            ? 0.0f
            : sample_transform_component(
                  channel, 0x18 + component * 4,
                  0x00000200u << component, frame);
        translation[component] =
            (flags & (0x00800000u << component)) != 0
            ? 0.0f
            : sample_transform_component(
                  channel, 0x28 + component * 4,
                  0x00002000u << component, frame);
    }
}
extern "C" __attribute__((noinline)) void AnimationTransformModifier_ApplyRecords_00924E44(
    void* context_pointer, void*) {
    uint8_t* context = static_cast<uint8_t*>(context_pointer);
    uint8_t* resource =
        *reinterpret_cast<uint8_t**>(context + 0x6c);
    const float frame = *reinterpret_cast<const float*>(context + 0x74);
    if (resource == 0 || frame == 0.0f)
        return;
    uint8_t* owner =
        *reinterpret_cast<uint8_t**>(context + 0x78);
    TransformModifierRecord* records =
        *reinterpret_cast<TransformModifierRecord**>(context + 0x80);
    const int count = *reinterpret_cast<const int*>(context + 0x7c);
    if (records == 0 || owner == 0 || count <= 0)
        return;
    uint8_t* descriptor =
        *reinterpret_cast<uint8_t**>(resource + 0x24);
    for (int index = 0; index < count; ++index) {
        TransformModifierRecord& modifier = records[index];
        uint8_t* table = resolve_relative(descriptor + 0x1c);
        uint8_t* channel_field = table == 0
            ? 0 : table + modifier.channel_index * 0x10 + 0x28;
        void* channel = resolve_relative(channel_field);
        TransformRecord* target =
            (*reinterpret_cast<TransformRecord***>(owner + 0x44))[
                modifier.target_index];
        if (modifier.flags == 0)
            continue;
        if ((modifier.flags & 1u) != 0) {
            float sampled_scale[3];
            AnimationTransform_SampleScale_005AF458(
                sampled_scale, &channel, frame);
            for (uint32_t component = 0; component < 3; ++component) {
                target->scale[component] *=
                    modifier.scale[component] * sampled_scale[component];
            }
            target->flags = (target->flags & ~8u) | 0x800u;
        }
        if ((modifier.flags & 6u) != 0) {
            Matrix3x4 original;
            Matrix3x4 delta;
            Matrix3x4 modified;
            Matrix3x4 composed;
            Matrix3x4 staging;
            for (uint32_t lane = 0; lane < 12; ++lane)
                original.values[lane] = target->affine[lane];
            float rotation[3];
            float translation[3];
            AnimationTransform_SampleRotationTranslation_009252CC(
                rotation, translation, &channel, frame);
            build_modifier_affine(delta, rotation, translation);
            compose_affine(modified, modifier.transform, delta);
            compose_affine(composed, original, modified);
            Matrix3x4_Copy_0044C0A0(&staging, &composed);
            Matrix3x4_Copy_0044C0A0(target, &staging);
            uint32_t clear = 0;
            if ((modifier.flags & 2u) != 0)
                clear = 0x10u;
            if ((modifier.flags & 4u) != 0)
                clear |= 4u;
            target->flags |= 0x800u;
            target->flags &= ~clear;
        }
        TransformRecord_UpdateAllDerivedFlags_008E5D7C(target);
    }
}
extern "C" __attribute__((noinline)) uint32_t AnimationChrInner_PrepareTarget_008E42B4(
    void* inner_pointer, void* target_buffer_pointer) {
    uint8_t* inner = static_cast<uint8_t*>(inner_pointer);
    uint8_t* target_buffer =
        static_cast<uint8_t*>(target_buffer_pointer);
    uint8_t* target_descriptor =
        *reinterpret_cast<uint8_t**>(target_buffer + 8);
    const int target_count =
        *reinterpret_cast<const int*>(target_descriptor + 0x10);
    resize_index_array(
        reinterpret_cast<IndexArray*>(inner + 0x10), target_count);
    uint8_t* source_descriptor =
        *reinterpret_cast<uint8_t**>(inner + 0x54);
    const int source_count =
        *reinterpret_cast<const int*>(source_descriptor + 0x18);
    resize_index_array(
        reinterpret_cast<IndexArray*>(inner + 0x20), source_count);
    uint32_t* target_to_source =
        *reinterpret_cast<uint32_t**>(inner + 0x14);
    for (int index = 0; index < target_count; ++index)
        target_to_source[index] = 0xffffffffu;
    uint32_t* source_to_target =
        *reinterpret_cast<uint32_t**>(inner + 0x24);
    int mapped_count = 0;
    for (int source_index = 0; source_index < source_count; ++source_index) {
        uint8_t* source_table =
            resolve_relative(source_descriptor + 0x1c);
        uint8_t* source_field = source_table == 0
            ? 0 : source_table + source_index * 0x10 + 0x28;
        uint8_t* source_channel = resolve_relative(source_field);
        const char* name = reinterpret_cast<const char*>(
            resolve_relative(source_channel + 4));
        uint8_t* target_table =
            resolve_relative(target_descriptor + 0x14);
        void* node = 0;
        if (target_table != 0 && name != 0) {
            node = ParameterString_FindNode_00498FBC(
                &target_table, name, ByteString_Length_00425CAC(name));
        }
        int target_index = -1;
        if (node != 0) {
            target_index = static_cast<int>(
                (static_cast<uint8_t*>(node) - target_table - 0x1c) /
                0x10);
        }
        if (target_index < 0) {
            source_to_target[source_index] = 0xffffffffu;
            continue;
        }
        ++mapped_count;
        target_to_source[target_index] =
            static_cast<uint32_t>(source_index);
        source_to_target[source_index] =
            static_cast<uint32_t>(target_index);
        target_table = resolve_relative(target_descriptor + 0x14);
        uint8_t* target_field = target_table == 0
            ? 0 : target_table + target_index * 0x10 + 0x28;
        uint8_t* target_channel = resolve_relative(target_field);
        uint8_t* target =
            *reinterpret_cast<uint8_t**>(target_channel + 0x18);
        reset_target_channel_cache(
            target,
            *reinterpret_cast<const uint32_t*>(target_channel + 0x10));
    }
    *reinterpret_cast<void**>(inner + 8) = target_buffer;
    if (source_count == mapped_count)
        return 0;
    if (mapped_count == 0)
        return 0x80000002u;
    return 1;
}
extern "C" __attribute__((noinline)) int AnimationChrInner_MaterializeRecords_008ED190(
    void* inner_pointer, void* target_work_pointer,
    void* source_records_pointer) {
    uint8_t* inner = static_cast<uint8_t*>(inner_pointer);
    uint8_t* target_work =
        static_cast<uint8_t*>(target_work_pointer);
    uint8_t* source_records =
        static_cast<uint8_t*>(source_records_pointer);
    int channel_position = 0;
    while (channel_position < animation_channel_count(target_work)) {
        const uint32_t channel =
            (*reinterpret_cast<uint32_t**>(inner + 0x14))[
                channel_position];
        if (channel != gAnimationChannelSentinel_00CB0350) {
            uint8_t* table_field = source_records + 0x1c;
            const int32_t table_offset =
                *reinterpret_cast<int32_t*>(table_field);
            uint8_t* table = table_offset == 0
                ? 0 : table_field + table_offset;
            const uint8_t* primitive_field = table == 0
                ? 0 : table + channel * 0x10 + 0x28;
            const int32_t primitive_offset = primitive_field == 0
                ? 0 : *reinterpret_cast<const int32_t*>(primitive_field);
            const uint8_t* primitive = primitive_offset == 0
                ? 0 : primitive_field + primitive_offset;
            const uint32_t type =
                *reinterpret_cast<const uint32_t*>(primitive + 8);
            if (type == 5 || type == 8) {
                const uint32_t primitive_flags =
                    *reinterpret_cast<const uint32_t*>(primitive);
                uint8_t* source =
                    (*reinterpret_cast<uint8_t***>(target_work + 0x54))[
                        channel_position];
                TransformRecord* target = reinterpret_cast<TransformRecord*>(
                    (*reinterpret_cast<void***>(target_work + 0x44))[
                        channel_position]);
                const uint32_t build_mask =
                    type == 5 ? 0x03b80000u : 0x18u;
                const uint32_t scale_mask =
                    type == 5 ? 0x00070000u : 0x20u;
                const bool built = (primitive_flags & build_mask) != 0;
                if (built) {
                    TransformRecord_BuildEulerAffine_008E65BC(
                        target,
                        reinterpret_cast<const float*>(source + 0x0c),
                        reinterpret_cast<const float*>(source + 0x18));
                }
                if ((primitive_flags & scale_mask) != 0) {
                    const float* scale =
                        reinterpret_cast<const float*>(source);
                    target->scale[0] = scale[0];
                    target->scale[1] = scale[1];
                    target->scale[2] = scale[2];
                    target->flags |= 0x800u;
                } else if (!built) {
                    ++channel_position;
                    continue;
                }
                update_transform_derived_flags(inner, target);
                uint8_t* current =
                    *reinterpret_cast<uint8_t**>(inner + 0x64);
                if (current != *reinterpret_cast<void**>(inner + 0x68)) {
                    *reinterpret_cast<TransformRecord*>(
                        current + channel * sizeof(TransformRecord)) = *target;
                }
            }
        }
        ++channel_position;
    }
    return animation_channel_count(target_work);
}
extern "C" __attribute__((noinline)) void AnimationChrInner_Apply_008ED104(void* inner) {
    SkeletalAnimationInner* animation =
        static_cast<SkeletalAnimationInner*>(inner);
    if (animation->target_base == animation->previous_target_base ||
        animation->apply_pending == 0)
        return;
    if (animation->apply_source != 0) {
        void (*apply)(void*, void*, int) =
            reinterpret_cast<void (*)(void*, void*, int)>(
            animation->vtable[6]);
        uint8_t* header = *reinterpret_cast<uint8_t**>(
            animation->resource + 8);
        const int count = *reinterpret_cast<int*>(header + 0x10);
        for (int channel = 0; channel < count; ++channel) {
            const uint32_t target = animation->channel_map[channel];
            if (target != gAnimationChannelSentinel_00CB0350)
                apply(animation, animation->target_base + target * 0x40,
                      channel);
        }
    }
    animation->apply_pending = 0;
}
extern "C" __attribute__((noinline)) uint32_t AnimationChrInner_Update_008ED414(
    void* inner, void* target_buffer) {
    const uint32_t result =
        AnimationChrInner_PrepareTarget_008E42B4(inner, target_buffer);
    if ((result & 0x80000000u) != 0)
        return result;
    SkeletalAnimationInner* animation =
        static_cast<SkeletalAnimationInner*>(inner);
    AnimationChrInner_MaterializeRecords_008ED190(
        animation, target_buffer, animation->apply_source);
    animation->resource = static_cast<uint8_t*>(target_buffer);
    return result;
}
extern "C" __attribute__((noinline)) void AnimationChrSlotOwner_RebuildActiveMask_008EEFEC(
    void* owner_pointer) {
    AnimationChrSlotOwner* owner = static_cast<AnimationChrSlotOwner*>(owner_pointer);
    for (uint32_t* word = owner->active_mask_begin;
         word != owner->active_mask_end; ++word)
        *word = 0;
    int (*const slot_is_active)(void*, int) = reinterpret_cast<int (*)(void*, int)>(
        owner->vtable[7]);
    for (int slot = 0; slot < owner->slot_count; ++slot) {
        if (slot_is_active(owner, slot) != 0)
            owner->active_mask_begin[static_cast<unsigned>(slot) >> 5] |=
                1u << (slot & 31);
    }
}
extern "C" __attribute__((noinline)) void AnimationChrController_Clear_0091E128(
    void* controller_pointer) {
    AnimationChrController* controller = static_cast<AnimationChrController*>(controller_pointer);
    if (controller->slot_owner != 0 && controller->slot_index >= 0) {
        void** slots = *reinterpret_cast<void***>(controller->slot_owner + 0x14);
        slots[controller->slot_index] = 0;
        AnimationChrSlotOwner_RebuildActiveMask_008EEFEC(controller->slot_owner);
        controller->slot_index = -1;
        controller->slot_owner = 0;
    }
    SkeletalAnimationInner* animation = controller->inner;
    if (animation != 0) {
        void (*const destroy)(void*) = reinterpret_cast<void (*)(void*)>(
            animation->vtable[0]);
        destroy(animation);
        void* release_owner = *reinterpret_cast<void**>(
            reinterpret_cast<uint8_t*>(animation) + 4);
        void** release_vtable = *reinterpret_cast<void***>(release_owner);
        void (*const release)(void*, void*) = reinterpret_cast<void (*)(void*, void*)>(
            release_vtable[3]);
        release(release_owner, animation);
    }
    controller->inner = 0;
    *reinterpret_cast<uint8_t*>(
        static_cast<uint8_t*>(controller_pointer) + 0x58) = 0;
    controller->animation_key = 0;
    controller->frame = 0.0f;
}
extern "C" __attribute__((noinline)) void AnimationChrController_Update_00BAFB90(
    void* controller, float delta) {
    uint8_t* bytes = static_cast<uint8_t*>(controller);
    void** vtable = *reinterpret_cast<void***>(controller);
    void (*update)(void*, float) =
        reinterpret_cast<void (*)(void*, float)>(vtable[13]);
    update(controller, delta);
    SkeletalAnimationInner* animation =
        *reinterpret_cast<SkeletalAnimationInner**>(bytes + 0x5c);
    if (animation == 0)
        return;
    const float endpoint =
        AnimationController_EvaluateListScale_00B498B4(bytes + 0x2c) * delta *
        60.0f;
    *reinterpret_cast<float*>(reinterpret_cast<uint8_t*>(animation) + 0x40) =
        endpoint;
    if (endpoint == 0.0f) {
        animation->apply_pending = 1;
        void (*apply)(void*) = reinterpret_cast<void (*)(void*)>(
            animation->vtable[8]);
        apply(animation);
    }
}
extern "C" __attribute__((noinline)) void Skeleton_ComposeChildTransform_00B3E4A4(
    int, void* output_pointer, float* output_scale, void* child_pointer,
    void* parent_world_pointer, void* parent_local_pointer) {
    TransformRecord* child = static_cast<TransformRecord*>(child_pointer);
    TransformRecord* parent_world =
        static_cast<TransformRecord*>(parent_world_pointer);
    TransformRecord* parent_local =
        static_cast<TransformRecord*>(parent_local_pointer);
    if ((parent_local->flags & 0x200u) != 0)
        Matrix3x4_Copy_0044C0A0(output_pointer, parent_world);
    else
        Matrix3x4_ApplyColumnScale_00550948(
            output_pointer, parent_world, parent_local->scale);
    if ((child->flags & 0x60u) == 0) {
        const float translation[3] = {
            child->affine[3], child->affine[7], child->affine[11]};
        Matrix3x4_AddTransformedTranslation_005E1558(
            output_pointer, output_pointer, translation);
        if ((child->flags & 0x80u) == 0)
            Matrix3x3_MultiplyPreserveTranslation_00BA59D4(
                output_pointer, output_pointer, child);
    }
    output_scale[0] = child->scale[0];
    output_scale[1] = child->scale[1];
    output_scale[2] = child->scale[2];
    if ((parent_world->flags & 0x200u) == 0) {
        output_scale[0] *= parent_world->scale[0];
        output_scale[1] *= parent_world->scale[1];
        output_scale[2] *= parent_world->scale[2];
    }
}
extern "C" __attribute__((noinline)) void Skeleton_ComposeChildTransformAlternate_00B3E820(
    int, void* output_pointer, float* output_scale, void* child_pointer,
    void* parent_world_pointer, void* parent_local_pointer) {
    TransformRecord* child = static_cast<TransformRecord*>(child_pointer);
    TransformRecord* parent_world =
        static_cast<TransformRecord*>(parent_world_pointer);
    TransformRecord* parent_local =
        static_cast<TransformRecord*>(parent_local_pointer);
    Matrix3x4_Copy_0044C0A0(output_pointer, parent_world);
    if ((child->flags & 0x60u) == 0) {
        const float translation[3] = {
            child->affine[3], child->affine[7], child->affine[11]};
        if ((parent_local->flags & 0x200u) != 0) {
            Matrix3x4_AddTransformedTranslation_005E1558(
                output_pointer, output_pointer, translation);
        } else {
            float basis[9];
            float transformed[3];
            Matrix3x4_ExtractBasis_005E158C(basis, output_pointer);
            basis[0] *= parent_local->scale[0];
            basis[3] *= parent_local->scale[0];
            basis[6] *= parent_local->scale[0];
            basis[1] *= parent_local->scale[1];
            basis[4] *= parent_local->scale[1];
            basis[7] *= parent_local->scale[1];
            basis[2] *= parent_local->scale[2];
            basis[5] *= parent_local->scale[2];
            basis[8] *= parent_local->scale[2];
            Matrix3x3_TransformVector_005E140C(
                transformed, basis, translation);
            static_cast<TransformRecord*>(output_pointer)->affine[3] +=
                transformed[0];
            static_cast<TransformRecord*>(output_pointer)->affine[7] +=
                transformed[1];
            static_cast<TransformRecord*>(output_pointer)->affine[11] +=
                transformed[2];
        }
        if ((child->flags & 0x80u) == 0)
            Matrix3x3_MultiplyPreserveTranslation_00BA59D4(
                output_pointer, output_pointer, child);
    }
    output_scale[0] = child->scale[0];
    output_scale[1] = child->scale[1];
    output_scale[2] = child->scale[2];
    if ((parent_world->flags & 0x200u) == 0) {
        output_scale[0] *= parent_world->scale[0];
        output_scale[1] *= parent_world->scale[1];
        output_scale[2] *= parent_world->scale[2];
    }
}
extern "C" __attribute__((noinline)) void Skeleton_ComposeChildTransformMode2_00B3E30C(
    int, void* output_pointer, float* output_scale, void* child_pointer,
    void* parent_world_pointer, void*) {
    TransformRecord* child = static_cast<TransformRecord*>(child_pointer);
    TransformRecord* parent_world =
        static_cast<TransformRecord*>(parent_world_pointer);
    if ((child->flags & 0x60u) != 0) {
        Matrix3x4_Copy_0044C0A0(output_pointer, parent_world);
    } else {
        Matrix3x4 adjusted = *static_cast<Matrix3x4*>(child_pointer);
        if ((parent_world->flags & 0x200u) == 0) {
            adjusted.values[3] *= parent_world->scale[0];
            adjusted.values[7] *= parent_world->scale[1];
            adjusted.values[11] *= parent_world->scale[2];
        }
        if ((child->flags & 0x80u) != 0) {
            const float translation[3] = {
                adjusted.values[3], adjusted.values[7], adjusted.values[11]};
            Matrix3x4_AddTransformedTranslation_005E1558(
                output_pointer, parent_world, translation);
        } else {
            Matrix3x4_Multiply_002A6BDC(
                output_pointer, parent_world, &adjusted);
        }
    }
    output_scale[0] = child->scale[0];
    output_scale[1] = child->scale[1];
    output_scale[2] = child->scale[2];
    if ((parent_world->flags & 0x200u) == 0) {
        output_scale[0] *= parent_world->scale[0];
        output_scale[1] *= parent_world->scale[1];
        output_scale[2] *= parent_world->scale[2];
    }
}
extern "C" __attribute__((noinline)) void Skeleton_UpdateWorldTransforms_00B3C35C(
    void* owner_pointer, void* update_context_pointer) {
    uint8_t* owner = static_cast<uint8_t*>(owner_pointer);
    uint8_t* update_context =
        static_cast<uint8_t*>(update_context_pointer);
    uint8_t* skeleton =
        *reinterpret_cast<uint8_t**>(update_context + 0x22c);
    uint8_t* descriptor =
        *reinterpret_cast<uint8_t**>(skeleton + 8);
    const int compose_mode = *reinterpret_cast<int*>(owner + 0x24);
    void** vtable = *reinterpret_cast<void***>(skeleton);
    typedef void* (*GetTransformView)(void*);
    uint8_t* local_view = static_cast<uint8_t*>(
        reinterpret_cast<GetTransformView>(vtable[3])(skeleton));
    uint8_t* world_view = static_cast<uint8_t*>(
        reinterpret_cast<GetTransformView>(vtable[5])(skeleton));
    uint8_t* output_view = static_cast<uint8_t*>(
        reinterpret_cast<GetTransformView>(vtable[7])(skeleton));
    uint8_t* local_records =
        *reinterpret_cast<uint8_t**>(local_view + 4);
    uint8_t* world_records =
        *reinterpret_cast<uint8_t**>(world_view + 4);
    uint8_t* output =
        *reinterpret_cast<uint8_t**>(output_view + 4);
    uint8_t* output_end =
        *reinterpret_cast<uint8_t**>(output_view + 8);
    const uint32_t hierarchy_mode =
        *reinterpret_cast<uint32_t*>(descriptor + 0x24) & 0xffu;
    const bool use_identity_root =
        (*reinterpret_cast<uint32_t*>(descriptor + 0x28) & 1u) != 0;
    uint8_t* root = *reinterpret_cast<uint8_t**>(skeleton + 0x0c);
    uint8_t* pre_callbacks =
        *reinterpret_cast<uint8_t**>(skeleton + 0x10);
    uint8_t* post_callbacks =
        *reinterpret_cast<uint8_t**>(skeleton + 0x14);
    uint8_t* bone_table = resolve_relative(descriptor + 0x1c);
    int bone_index = 0;
    while (output != output_end) {
        dispatch_skeleton_callbacks(pre_callbacks, skeleton, bone_index);
        TransformRecord* local = reinterpret_cast<TransformRecord*>(
            local_records + bone_index * sizeof(TransformRecord));
        if ((local->flags & 1u) != 0) {
            uint8_t* bone = resolve_relative(
                bone_table + bone_index * 0x10 + 0x28);
            const int parent_index =
                *reinterpret_cast<const int*>(bone + 0x0c);
            TransformRecord* parent_local;
            TransformRecord* parent_world;
            if (parent_index == -1) {
                if (use_identity_root) {
                    parent_local = static_cast<TransformRecord*>(
                        TransformRecord_GetIdentity_008E6938());
                    parent_world = static_cast<TransformRecord*>(
                        TransformRecord_GetIdentity_008E6938());
                } else {
                    parent_local = reinterpret_cast<TransformRecord*>(
                        root + 0x4c);
                    parent_world = reinterpret_cast<TransformRecord*>(
                        root + 0xbc);
                }
            } else {
                parent_local = reinterpret_cast<TransformRecord*>(
                    local_records + parent_index * sizeof(TransformRecord));
                parent_world = reinterpret_cast<TransformRecord*>(
                    world_records + parent_index * sizeof(TransformRecord));
            }
            TransformRecord* world = reinterpret_cast<TransformRecord*>(
                world_records + bone_index * sizeof(TransformRecord));
            float world_scale[3];
            if (hierarchy_mode == 0) {
                Skeleton_ComposeChildTransform_00B3E4A4(
                    compose_mode, world, world_scale, local,
                    parent_world, parent_local);
            } else if (hierarchy_mode == 1) {
                if ((*reinterpret_cast<uint32_t*>(bone + 4) & 0x20u) == 0)
                    Skeleton_ComposeChildTransform_00B3E4A4(
                        compose_mode, world, world_scale, local,
                        parent_world, parent_local);
                else
                    Skeleton_ComposeChildTransformAlternate_00B3E820(
                        compose_mode, world, world_scale, local,
                        parent_world, parent_local);
            } else {
                Skeleton_ComposeChildTransformMode2_00B3E30C(
                    compose_mode, world, world_scale, local,
                    parent_world, parent_local);
            }
            stabilize_skeleton_scale(world_scale);
            world->scale[0] = world_scale[0];
            world->scale[1] = world_scale[1];
            world->scale[2] = world_scale[2];
            Matrix3x4_ApplyColumnScale_00550948(
                output, world,
                hierarchy_mode < 2 ? local->scale : world->scale);
            update_skeleton_scale_flags(world);
        }
        dispatch_skeleton_callbacks(post_callbacks, skeleton, bone_index);
        ++bone_index;
        output += sizeof(Matrix3x4);
    }
}
extern "C" __attribute__((noinline)) void AnimationUpdate_ResetPendingList_0091FD3C(
    void* list, void*) {
    uint8_t* base = static_cast<uint8_t*>(list);
    uint8_t* sentinel = *reinterpret_cast<uint8_t**>(base + 0x0c);
    for (uint8_t* link = *reinterpret_cast<uint8_t**>(base + 0x10);
         *reinterpret_cast<uint8_t**>(link) != sentinel;
         link = *reinterpret_cast<uint8_t**>(link + 4)) {
        uint8_t* node = *reinterpret_cast<uint8_t**>(link);
        *reinterpret_cast<uint8_t**>(node + 8) =
            *reinterpret_cast<uint8_t**>(node + 4);
    }
    int minimum = 0x7fffffff;
    for (uint8_t* link = *reinterpret_cast<uint8_t**>(base + 0x10);
         *reinterpret_cast<uint8_t**>(link) != sentinel;
         link = *reinterpret_cast<uint8_t**>(link + 4)) {
        uint8_t* node = *reinterpret_cast<uint8_t**>(link);
        const int value = *reinterpret_cast<int*>(node + 8);
        if (value >= 0 && value < minimum)
            minimum = value;
    }
    *reinterpret_cast<int*>(base + 0x28) = minimum;
}
extern "C" __attribute__((noinline)) void AnimationUpdate_DispatchPreCallbacks_0091FC0C(
    void* list, void* context) {
    uint8_t* base = static_cast<uint8_t*>(list);
    uint8_t* link = *reinterpret_cast<uint8_t**>(base + 4);
    while (link != base) {
        uint8_t* node = *reinterpret_cast<uint8_t**>(link);
        void** vtable = *reinterpret_cast<void***>(node);
        reinterpret_cast<void (*)(void*, void*)>(vtable[2])(node, context);
        link = *reinterpret_cast<uint8_t**>(link + 4);
    }
}
extern "C" __attribute__((noinline)) void AnimationUpdate_DispatchScheduledCallbacks_0091FC58(
    void* list, void* context, int frame) {
    uint8_t* base = static_cast<uint8_t*>(list);
    if (*reinterpret_cast<int*>(base + 0x28) != frame)
        return;
    uint8_t* sentinel = *reinterpret_cast<uint8_t**>(base + 0x0c);
    for (uint8_t* link = *reinterpret_cast<uint8_t**>(base + 0x10);
         *reinterpret_cast<uint8_t**>(link) != sentinel;
         link = *reinterpret_cast<uint8_t**>(link + 4)) {
        uint8_t* node = *reinterpret_cast<uint8_t**>(link);
        if (*reinterpret_cast<int*>(node + 8) == frame) {
            void** vtable = *reinterpret_cast<void***>(node);
            reinterpret_cast<void (*)(void*, void*, int)>(vtable[2])(
                node, context, frame);
        }
    }
    int next = 0x7fffffff;
    for (uint8_t* link = *reinterpret_cast<uint8_t**>(base + 0x10);
         *reinterpret_cast<uint8_t**>(link) != sentinel;
         link = *reinterpret_cast<uint8_t**>(link + 4)) {
        const int candidate = *reinterpret_cast<int*>(
            *reinterpret_cast<uint8_t**>(link) + 8);
        if (candidate > frame && candidate < next)
            next = candidate;
    }
    *reinterpret_cast<int*>(base + 0x28) = next;
}
extern "C" __attribute__((noinline)) void AnimationUpdate_DispatchPostCallbacks_0091FCF0(
    void* list, void* context) {
    uint8_t* base = static_cast<uint8_t*>(list);
    uint8_t* link = *reinterpret_cast<uint8_t**>(base + 0x1c);
    while (link != base + 0x18) {
        uint8_t* node = *reinterpret_cast<uint8_t**>(link);
        void** vtable = *reinterpret_cast<void***>(node);
        reinterpret_cast<void (*)(void*, void*)>(vtable[2])(node, context);
        link = *reinterpret_cast<uint8_t**>(link + 4);
    }
}
extern "C" __attribute__((noinline)) void AnimationUpdate_ClearRecordPending_008E1048(void* record) {
    *reinterpret_cast<uint8_t*>(static_cast<uint8_t*>(record) + 0x12c) = 0;
}
extern "C" void AnimationController_Update_008D8CC4(void* controller,
                                                       unsigned mode);
extern "C" void TemporaryRecord_ZeroInit_00916E24(
    void* record, const char* tag, uint32_t type, uint32_t size);
extern "C" uint8_t* AnimationOwner_GetResource_00499064(void* owner);
extern "C" void* Resource_GetIndexedEntry_00464200(void* resource, int index);
extern "C" int AnimationResource_Remove_0048C1C8(void* resource, void* record);
extern "C" int AnimationResource_Insert_0043A078(void* resource, void* record,
                                                  void* owner_data);
extern "C" __attribute__((noinline)) void Animation_WorldUpdate_00925CDC(
    void* owner_pointer, void*, const float* update_values) {
    uint8_t* owner = static_cast<uint8_t*>(owner_pointer);
    uint8_t* state = *reinterpret_cast<uint8_t**>(owner + 8);
    uint8_t* state_flags = *reinterpret_cast<uint8_t**>(owner + 4);
    uint8_t* record = *reinterpret_cast<uint8_t**>(state + 0x10c);
    uint8_t* callbacks = *reinterpret_cast<uint8_t**>(owner + 0x0c);
    uint8_t* update_context =
        *reinterpret_cast<uint8_t**>(state + 0x110);
    const uint8_t active =
        (state_flags[0xb4] != 0 || state_flags[0xb5] != 0) ? 1 : 0;
    state_flags[0x3d] = active;
    if (active != 0) {
    uint32_t temporary_record;
    TemporaryRecord_ZeroInit_00916E24(
        &temporary_record, "UpdateWorld", 5, 1);
    uint8_t* callback_state = 0;
    bool callbacks_ready = false;
    if (update_context != 0) {
        callback_state = *reinterpret_cast<uint8_t**>(update_context + 0x22c);
        if (callbacks != 0) {
            AnimationUpdate_ResetPendingList_0091FD3C(
                callbacks, update_context);
        }
        callbacks_ready =
            ((*reinterpret_cast<uint32_t*>(
                   *reinterpret_cast<uint8_t**>(callback_state + 8) +
                   0x28) & 1u) != 0);
    }
    const bool update_controllers =
        (owner[0x1c] & 1u) == 0 || (owner[0x1c] & 4u) != 0;
    if (*reinterpret_cast<uint8_t**>(record + 0x28) != 0 &&
        update_controllers)
        AnimationController_Update_008D8CC4(
            *reinterpret_cast<void**>(record + 0x28), 0);
    const float two = 2.0f;
    const float x = update_values[2] * two;
    const float y = update_values[1] * two;
    const float z = update_values[3] * two;
    const float w = update_values[4];
    float matrix[12];
    matrix[0] = 1.0f - x * update_values[2] - z * update_values[3];
    matrix[1] = y * update_values[2] - z * w;
    matrix[2] = y * update_values[3] + x * w;
    matrix[3] = update_values[5];
    matrix[4] = y * update_values[2] + z * w;
    matrix[5] = 1.0f - y * update_values[1] - z * update_values[3];
    matrix[6] = x * update_values[3] - y * w;
    matrix[7] = update_values[6];
    matrix[8] = y * update_values[3] - x * w;
    matrix[9] = x * update_values[3] + y * w;
    matrix[10] = 1.0f - y * update_values[1] - x * update_values[2];
    matrix[11] = update_values[7];
    const float old_frame = *reinterpret_cast<float*>(record + 0x7c);
    const float frame = *update_values;
    if (std::fabs(frame - old_frame) > 0.00001f) {
        *reinterpret_cast<float*>(record + 0x7c) = frame;
        *reinterpret_cast<float*>(record + 0x80) = frame;
        *reinterpret_cast<float*>(record + 0x84) = frame;
        uint32_t flags = *reinterpret_cast<uint32_t*>(record + 0x88);
        flags |= 0x800u;
        *reinterpret_cast<uint32_t*>(record + 0x88) = flags;
        if ((flags & 8u) == 0) {
            flags &= ~0x600u;
            *reinterpret_cast<uint32_t*>(record + 0x88) = flags;
            if (*reinterpret_cast<float*>(record + 0x7c) ==
                    *reinterpret_cast<float*>(record + 0x80) &&
                *reinterpret_cast<float*>(record + 0x7c) ==
                    *reinterpret_cast<float*>(record + 0x84)) {
                flags |= 0x400u;
                *reinterpret_cast<uint32_t*>(record + 0x88) = flags;
                if (*reinterpret_cast<uint32_t*>(record + 0x7c) ==
                    0x3f800000u)
                    *reinterpret_cast<uint32_t*>(record + 0x88) =
                        flags | 0x200u;
            }
        }
        *reinterpret_cast<float*>(record + 0xec) = frame;
        *reinterpret_cast<float*>(record + 0xf0) = frame;
        *reinterpret_cast<float*>(record + 0xf4) = frame;
        *reinterpret_cast<uint32_t*>(record + 0xf8) |= 0x800u;
    }
    Matrix3x4_Copy_0044C0A0(record + 0xbc, matrix);
    *reinterpret_cast<uint32_t*>(record + 0xf8) |= 0x800u;
    TransformRecord_UpdateAllDerivedFlags_008E5D7C(record + 0xbc);
    if (std::fabs(frame - 1.0f) > 0.00001f) {
        matrix[0] *= frame;
        matrix[1] *= frame;
        matrix[2] *= frame;
        matrix[4] *= frame;
        matrix[5] *= frame;
        matrix[6] *= frame;
        matrix[8] *= frame;
        matrix[9] *= frame;
        matrix[10] *= frame;
    }
    Matrix3x4_Copy_0044C0A0(record + 0x8c, matrix);
    AnimationUpdate_ClearRecordPending_008E1048(record);
    if (*reinterpret_cast<uint8_t**>(record + 0x28) != 0 &&
        update_controllers)
        AnimationController_Update_008D8CC4(
            *reinterpret_cast<void**>(record + 0x28), 1);
    if (callbacks != 0)
        AnimationUpdate_DispatchPreCallbacks_0091FC0C(callbacks, update_context);
    if (update_context != 0 && (!callbacks_ready || update_controllers)) {
        uint8_t* model = AnimationOwner_GetResource_00499064(owner);
        uint8_t* skeleton_owner =
            *reinterpret_cast<uint8_t**>(model + 0x94);
        Skeleton_UpdateWorldTransforms_00B3C35C(
            *reinterpret_cast<void**>(skeleton_owner + 4), update_context);
        if (callback_state != 0)
            callback_state[0x18] = 0;
    }
    if (callbacks != 0)
        AnimationUpdate_DispatchPostCallbacks_0091FCF0(callbacks, update_context);
    }
    if ((state_flags[0xb5] != 0) == (*reinterpret_cast<int*>(record + 0x0c) != 0))
        return;
    uint8_t* model = AnimationOwner_GetResource_00499064(owner);
    const int resource_index = *reinterpret_cast<int*>(owner + 0x18);
    if (state_flags[0xb5] == 0) {
        void* resource = resource_index < 0
            ? *reinterpret_cast<void**>(model + 0x98)
            : Resource_GetIndexedEntry_00464200(
                  *reinterpret_cast<void**>(model + 0x94), resource_index);
        AnimationResource_Remove_0048C1C8(resource, record);
    } else {
        void* resource = resource_index < 0
            ? *reinterpret_cast<void**>(model + 0x98)
            : Resource_GetIndexedEntry_00464200(
                  *reinterpret_cast<void**>(model + 0x94), resource_index);
        AnimationResource_Insert_0043A078(
            resource, record, *reinterpret_cast<void**>(owner + 0x10));
    }
}

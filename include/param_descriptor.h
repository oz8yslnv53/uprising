#pragma once
#include <stddef.h>
#include <stdint.h>
struct ParamDescriptor {
    const void* descriptor_type;
    const char* name;
    const void* metadata;
    void* field;
    float initial_value;
};
struct NamedParamDescriptor {
    const void* descriptor_type;
    const char* name;
    const void* metadata;
    void* field;
};
typedef char kiu_sa_param_descriptor_1[(sizeof(ParamDescriptor) == 0x14) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_param_descriptor_2[(offsetof(ParamDescriptor, name) == 0x04) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_param_descriptor_3[(offsetof(ParamDescriptor, field) == 0x0c) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_param_descriptor_4[(offsetof(ParamDescriptor, initial_value) == 0x10) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_param_descriptor_5[(sizeof(NamedParamDescriptor) == 0x10) ? 1 : -1] __attribute__((unused));
extern const void* float_param_descriptor_type;
extern const void* float_param_metadata;
extern const void* byte_param_descriptor_type;
extern const void* byte_param_metadata;
void init_float_param_descriptor(ParamDescriptor* out, const char* name, void* field);
void init_byte_param_descriptor(ParamDescriptor* out, const char* name, void* field);
typedef uint32_t Word;
struct DirectDescriptor {
    const void* metadata;
    const void* name;
    const void* type_metadata;
    void* target;
};
struct ValueDescriptor {
    const void* metadata;
    const void* name;
    const void* type_metadata;
    void* target;
    Word value;
};
struct PointerValueDescriptor {
    const void* metadata;
    const void* name;
    const void* type_metadata;
    void* target;
    const void* default_value;
};
typedef char kiu_sa_param_descriptor_6[(sizeof(DirectDescriptor) == 0x10) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_param_descriptor_7[(sizeof(ValueDescriptor) == 0x14) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_param_descriptor_8[(sizeof(PointerValueDescriptor) == 0x14) ? 1 : -1] __attribute__((unused));

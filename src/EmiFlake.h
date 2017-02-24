#ifndef BUILDING_NODE_EXTENSION
#define BUILDING_NODE_EXTENSION
#endif

#ifndef emilir_EmiFlake_h
#define emilir_EmiFlake_h

#include <node.h>
#include <node_object_wrap.h>

#include "flake.h"


class EmiFlake : public node::ObjectWrap {
    friend class EmiConnDelegate;
    friend class EmiSockDelegate;
    friend class EmiBinding;

public:
    static void Init(v8::Handle<v8::Object> exports);

    static v8::Persistent<v8::Function> generate;

private:
    emilir::flake _flake;

    // Private copy constructor and assignment operator
    inline EmiFlake(const EmiFlake& other);
    inline EmiFlake& operator=(const EmiFlake& other);

    explicit EmiFlake(const unsigned char *machineNumber,
             size_t machineNumberLength,
             size_t sequenceNumberLength,
             size_t timestampLength,
             unsigned long long timeOffset);
    virtual ~EmiFlake();

    static void ByteLength(const v8::FunctionCallbackInfo<v8::Value>& args);
    static void BitLength(const v8::FunctionCallbackInfo<v8::Value>& args);
    static void Generate(const v8::FunctionCallbackInfo<v8::Value>& args);

    static void New(const v8::FunctionCallbackInfo<v8::Value>& args);
    static v8::Persistent<v8::Function> constructor;

};

#endif

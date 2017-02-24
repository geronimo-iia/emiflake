#ifndef BUILDING_NODE_EXTENSION
#define BUILDING_NODE_EXTENSION
#endif

#include <node.h>
#include "EmiFlake.h"

using namespace v8;

void InitAll(Handle<Object> exports) {
    EmiFlake::Init(exports);
}

NODE_MODULE(emiflake, InitAll)
